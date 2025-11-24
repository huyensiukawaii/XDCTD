#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// --- Định nghĩa các hằng số ---
#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1024
#define MAX_STOP_WORDS 100
#define MAX_UNIQUE_WORDS 5000
#define MAX_LINE_LIST_LEN 512

// --- Định nghĩa cấu trúc cho một mục trong bảng chỉ dẫn ---
typedef struct {
    char word[MAX_WORD_LEN];
    char lines[MAX_LINE_LIST_LEN]; 
    int count;
} IndexEntry;

// --- Khai báo mảng toàn cục ---
IndexEntry word_index[MAX_UNIQUE_WORDS]; 
int uniqueWordCount = 0;
char stopWords[MAX_STOP_WORDS][MAX_WORD_LEN];
int stopWordCount = 0;

// --- Hàm 1: Kiểm tra xem một từ có phải là stop word không ---
int isStopWord(const char *word) {
    for (int i = 0; i < stopWordCount; i++) {
        if (strcmp(word, stopWords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// --- Hàm 2: Thêm một từ và số dòng của nó vào bảng chỉ dẫn ---
void addWordToIndex(const char *word, int lineNum) {
    char lineNumStr[10];
    sprintf(lineNumStr, "%d", lineNum);

    // 1. Tìm xem từ đã có trong chỉ mục chưa 
    for (int i = 0; i < uniqueWordCount; i++) {
        if (strcmp(word_index[i].word, word) == 0) { 
            word_index[i].count++;
            // Từ đã tồn tại, kiểm tra xem số dòng này đã được thêm chưa
            char linesCopy[MAX_LINE_LIST_LEN];
            strcpy(linesCopy, word_index[i].lines); 
            char *token = strtok(linesCopy, ",");
            
            while (token != NULL) {
                if (strcmp(token, lineNumStr) == 0) {
                    return; 
                }
                token = strtok(NULL, ",");
            }
            
            // Nếu chưa có, thêm số dòng vào cuối chuỗi 
            if (strlen(word_index[i].lines) + strlen(lineNumStr) + 2 < MAX_LINE_LIST_LEN) {
                strcat(word_index[i].lines, ",");
                strcat(word_index[i].lines, lineNumStr);
            }
            return;
        }
    }

    // 2. Nếu từ chưa có và mảng chưa đầy, thêm mục mới 
    if (uniqueWordCount < MAX_UNIQUE_WORDS) {
        strcpy(word_index[uniqueWordCount].word, word);
        strcpy(word_index[uniqueWordCount].lines, lineNumStr);
        
        word_index[uniqueWordCount].count = 1;
        uniqueWordCount++;
    } else {
      static int warned = 0;
       if (!warned) {
            fprintf(stderr, "Cảnh báo: Đã đạt số lượng từ duy nhất tối đa (%d). Một số từ có thể bị bỏ qua.\n", MAX_UNIQUE_WORDS);
            warned = 1;   
      }
    }
}

// --- Hàm 3: Hàm so sánh để dùng với qsort ---
int compareEntries(const void *a, const void *b) {
    IndexEntry *entryA = (IndexEntry *)a;
    IndexEntry *entryB = (IndexEntry *)b;
    return strcmp(entryA->word, entryB->word);
}

// --- Hàm 4: Tải danh sách stop words từ tệp ---
void loadStopWords(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Lỗi: Không thể mở tệp stopw.txt");
        exit(EXIT_FAILURE);
    }
    
    while (stopWordCount < MAX_STOP_WORDS && 
           fscanf(file, "%99s", stopWords[stopWordCount]) == 1) {
        stopWordCount++;
    }
    
    fclose(file);
}

// --- Hàm 5 (sửa): Xử lý tệp văn bản chính ---
void processTextFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        char error_msg[MAX_LINE_LEN];
        sprintf(error_msg, "Lỗi: Không thể mở tệp văn bản '%s'", filename);
        perror(error_msg);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LEN];
    int lineNum = 0;

    while (fgets(line, sizeof(line), file)) {
        lineNum++;

        char currentWord[MAX_WORD_LEN];
        int wordIndex = 0;
        int isProperNoun = 0;

        char prevNonSpaceChar = '.';

        for (int i = 0; line[i] != '\0'; i++) {
            char c = line[i];

            if (isalpha((unsigned char)c)) {

                if (wordIndex == 0) {
                    if (isupper((unsigned char)c) &&
                        prevNonSpaceChar != '.' &&
                        prevNonSpaceChar != '?' &&
                        prevNonSpaceChar != '!') {

                        char next = line[i + 1];

                        if (islower((unsigned char)next)) {
                            isProperNoun = 1;
                        } else {
                            isProperNoun = 0;
                        }
                    } else {
                        isProperNoun = 0;
                    }
                }

                if (wordIndex < MAX_WORD_LEN - 1) {
                    currentWord[wordIndex++] = tolower((unsigned char)c);
                }

            } else {

                if (wordIndex > 0) {
                    currentWord[wordIndex] = '\0';

                    if (!isProperNoun && !isStopWord(currentWord)) {
                        addWordToIndex(currentWord, lineNum);
                    }

                    wordIndex = 0;
                    isProperNoun = 0;
                }

                if (!isspace((unsigned char)c)) {
                    prevNonSpaceChar = c;
                }
            }

            if (!isspace((unsigned char)c)) {
                prevNonSpaceChar = c;
            }
        }

        if (wordIndex > 0) {
            currentWord[wordIndex] = '\0';
            if (!isProperNoun && !isStopWord(currentWord)) {
                addWordToIndex(currentWord, lineNum);
            }
        }
    }

    fclose(file);
}

// --- Hàm MAIN ---
int main(int argc, char *argv[]) {
    
    if (argc != 3) {
        fprintf(stderr, "Cách dùng: %s <tệp_stop_words> <tệp_văn_bản>\n", argv[0]);
        return EXIT_FAILURE; 
    }
    char *stopword_file = argv[1];
    char *text_file = argv[2];
    loadStopWords(stopword_file);
    processTextFile(text_file);
    qsort(word_index, uniqueWordCount, sizeof(IndexEntry), compareEntries);

    printf("INDEX TABLE\n");
    printf("========================================\n");
    printf("%-15s %-7s %s\n", "WORD", "TIMES", "LINES");
    printf("========================================\n");

    for (int i = 0; i < uniqueWordCount; i++) {
        printf("%-15s %-7d %s\n", word_index[i].word, word_index[i].count, word_index[i].lines); 
    }
    printf("========================================\n");
    printf("Total unique words: %d\n", uniqueWordCount);

    return 0;
}