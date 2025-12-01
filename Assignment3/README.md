# KPL Parser (Assignment 3)

Chương trình parser cho ngôn ngữ KPL (ngôn ngữ lập trình giáo học tương tự Pascal).

## Yêu cầu môi trường

- Trình biên dịch C (GCC)
  - Windows: MinGW-w64, MSYS2, hoặc Git Bash
  - macOS: Xcode Command Line Tools
  - Linux: gói `build-essential` (Debian/Ubuntu)
- Tùy chọn: `make` để sử dụng Makefile

## Biên dịch

### Sử dụng Make (khuyến nghị)

```bash
cd d:\20251\CTD\Assignment3
make
```

### Biên dịch thủ công với GCC

**Windows (PowerShell/CMD):**
```cmd
cd d:\20251\CTD\Assignment3
gcc -c -Wall main.c parser.c scanner.c reader.c charcode.c token.c error.c
gcc main.o parser.o scanner.o reader.o charcode.o token.o error.o -o parser.exe
```

**Linux/macOS:**
```bash
cd /path/to/Assignment3
gcc -c -Wall main.c parser.c scanner.c reader.c charcode.c token.c error.c
gcc main.o parser.o scanner.o reader.o charcode.o token.o error.o -o parser
```

## Chạy chương trình

Chương trình nhận 1 tham số: đường dẫn đến file mã nguồn KPL.

**Windows:**
```cmd
parser.exe example.kpl
```

**Linux/macOS:**
```bash
./parser example.kpl
```

## Ví dụ chương trình KPL

Tạo file `example.kpl`:

```pascal
PROGRAM Example;
CONST
  MAX = 100;
VAR
  x, y : INTEGER;
BEGIN
  x := 10;
  y := x + 5;
END.
```

Chạy parser:
```bash
parser.exe example.kpl
```

## Cấu trúc ngữ pháp KPL

KPL hỗ trợ:
- **Khai báo:** `CONST`, `TYPE`, `VAR`
- **Kiểu dữ liệu:** `INTEGER`, `CHAR`, `ARRAY`
- **Hàm và thủ tục:** `FUNCTION`, `PROCEDURE`
- **Câu lệnh:** gán (`:=`), `CALL`, `IF-THEN-ELSE`, `WHILE-DO`, `FOR-TO-DO`
- **Biểu thức:** phép toán số học (`+`, `-`, `*`, `/`)
- **Điều kiện:** phép so sánh (`=`, `<>`, `<`, `<=`, `>`, `>=`)

## Dọn dẹp (clean)

```bash
make clean
```

Hoặc thủ công:

**Windows:**
```cmd
del /Q *.o parser.exe 2>nul
```

**Linux/macOS:**
```bash
rm -f *.o parser
```

## Kết quả

Parser sẽ:
- In ra các token được phân tích
- Hiển thị thông báo parsing cho từng thành phần
- Báo lỗi cú pháp nếu có (với số dòng và cột)
- Thông báo "Program parsed!" nếu thành công
