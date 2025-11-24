# Chương trình lập chỉ mục từ (Indexer)

Công cụ đọc danh sách stop word và một tệp văn bản, trích xuất các từ (không phân biệt hoa/thường), bỏ qua stop word và một số danh từ riêng, rồi in bảng chỉ dẫn (index) các từ theo thứ tự chữ cái kèm danh sách số dòng xuất hiện.

## Cấu trúc thư mục
- `indexer.c`: Mã nguồn C của chương trình
- `stopw.txt`: Danh sách stop word (mỗi từ cách nhau bằng khoảng trắng/dòng mới)
- `vanban.txt`: Tệp văn bản mẫu để lập chỉ mục
- `Makefile`: Tập lệnh build (dùng với `make`)

## Yêu cầu môi trường
- Trình biên dịch C (GCC)
  - Windows: cài MinGW-w64 hoặc MSYS2 (hoặc sử dụng Git Bash)
  - macOS: Xcode Command Line Tools
  - Linux: gói `build-essential` (Debian/Ubuntu) hoặc tương đương
- Tùy chọn: `make` để dùng `Makefile`

## Biên dịch
Bạn có thể biên dịch bằng GCC trực tiếp hoặc qua `make`.

- PowerShell (Windows):
```powershell
cd D:\20251\CTD\Bai1
gcc indexer.c -o indexer
```

- Bash (Linux/macOS/Git Bash):
```bash
cd /path/to/CTD/Bai1
gcc indexer.c -o indexer
```

- Dùng `make` (nếu đã cài make):
```powershell
cd D:\20251\CTD\Bai1
make
```
Kết quả tạo ra thực thi `indexer` (hoặc `indexer.exe` trên Windows).

## Chạy chương trình
Chương trình nhận đúng 2 tham số: đường dẫn stop word và đường dẫn tệp văn bản.

- PowerShell (Windows):
```powershell
# Ví dụ trong thư mục Bai1
.\indexer stopw.txt vanban.txt
```

- Bash (Linux/macOS/Git Bash):
```bash
./indexer stopw.txt vanban.txt
```

## Định dạng đầu ra
- In tiêu đề cộng ba cột: từ (WORD), số lần xuất hiện (TIMES), danh sách số dòng (LINES).
- Mỗi dòng gồm: từ, số lần xuất hiện, danh sách số dòng (phân tách bằng dấu phẩy) mà từ xuất hiện.
- Ví dụ (minh họa):
```
INDEX TABLE
========================================
WORD            TIMES   LINES
========================================
apple           3       1,5,12
banana          2       2,5
...             ...     ...
========================================
Total unique words: 123
```

## Quy tắc xử lý (tóm tắt)
- Không phân biệt hoa/thường khi lập chỉ mục (chuyển về chữ thường).
- Bỏ qua các từ nằm trong `stopw.txt`.
- Bỏ qua các danh từ riêng bắt đầu bằng chữ hoa nếu xuất hiện giữa câu (chữ trước đó không phải dấu chấm `.`).
- Sắp xếp từ theo thứ tự chữ cái trước khi in ra.

## Giới hạn hiện tại
- Tối đa `MAX_STOP_WORDS = 100` stop word.
- Tối đa `MAX_UNIQUE_WORDS = 5000` từ duy nhất.
- Mỗi danh sách dòng tối đa `MAX_LINE_LIST_LEN = 512` ký tự.

## Dọn dẹp (clean)
- Trên hệ UNIX/Git Bash:
```bash
make clean
```
- Trên PowerShell (nếu `make clean` báo lỗi do thiếu lệnh `rm`), xóa thủ công:
```powershell
Remove-Item -Force .\indexer.exe -ErrorAction SilentlyContinue
Remove-Item -Force .\indexer -ErrorAction SilentlyContinue
```

## Lỗi thường gặp
- "The system cannot find the file specified" khi `make clean`: cài Git Bash hoặc xóa file thực thi thủ công như hướng dẫn trên.
- "Cách dùng: <program> <tệp_stop_words> <tệp_văn_bản>": bạn cần truyền đúng 2 tham số (đường dẫn `stopw.txt` và `vanban.txt`).

## Gợi ý mở rộng
- Ghi kết quả ra tệp thay vì màn hình.
- Hỗ trợ loại bỏ dấu tiếng Việt để lập chỉ mục tốt hơn.
- Tăng kích thước giới hạn hoặc chuyển sang cấu trúc dữ liệu động.
