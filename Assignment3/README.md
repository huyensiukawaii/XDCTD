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
  x : INTEGER;
  y : INTEGER;
BEGIN
  x := 10;
  y := x + 5;
END.
```

**Lưu ý:**
- Mỗi biến phải được khai báo trên một dòng riêng
- Dấu ngoặc vuông `[` `]` trong KPL được viết là `(.` và `.)`

Chạy parser:
```bash
parser.exe example.kpl
```

## Cấu trúc ngữ pháp KPL

KPL hỗ trợ:
- **Khai báo:** `CONST`, `TYPE`, `VAR`
- **Kiểu dữ liệu:** `INTEGER`, `CHAR`, `ARRAY`
- **Hàm và thủ tục:** `FUNCTION`, `PROCEDURE`
- **Câu lệnh:** gán (`:=`), `CALL`, `IF-THEN-ELSE`, `WHILE-DO`, `FOR-TO-DO`, `REPEAT-UNTIL`
- **Biểu thức:** phép toán số học (`+`, `-`, `*`, `/`)
- **Điều kiện:** phép so sánh (`=`, `<>`, `<`, `<=`, `>`, `>=`)

## Tính năng mở rộng

### 1. Vòng lặp REPEAT-UNTIL

Cú pháp:
```pascal
REPEAT
  statement1;
  statement2;
  ...
UNTIL condition
```

Ví dụ:
```pascal
PROGRAM RepeatExample;
VAR
  x : INTEGER;
BEGIN
  x := 1;
  REPEAT
    x := x + 1
  UNTIL x > 10
END.
```

### 2. Gán nhiều biến

Cú pháp:
```pascal
var1, var2, var3 := expr1, expr2, expr3
```

Ví dụ:
```pascal
PROGRAM MultiAssign;
VAR
  x : INTEGER;
  y : INTEGER;
  z : INTEGER;
BEGIN
  x, y, z := 10, 20, 30
END.
```

**Lưu ý:**
- Số lượng biến và số lượng biểu thức phải bằng nhau
- Gán nhiều biến chỉ áp dụng trong statement, không áp dụng trong khai báo VAR

## File test mẫu

Dự án bao gồm các file test sau:

### 1. `test_simple.kpl`
Test cơ bản với assignment đơn giản, multi-assignment, và REPEAT-UNTIL.

```bash
parser.exe test_simple.kpl
```

### 2. `test_repeat.kpl`
Test chi tiết cho vòng lặp REPEAT-UNTIL với nhiều trường hợp khác nhau.

```bash
parser.exe test_repeat.kpl
```

### 3. `test_multiassign.kpl`
Test chi tiết cho tính năng gán nhiều biến với các trường hợp:
- Gán giá trị số
- Gán với biểu thức
- Gán với biến
- Swap biến
- Gán phần tử mảng

```bash
parser.exe test_multiassign.kpl
```

### 4. `test.kpl`
Test toàn diện với tất cả tính năng của KPL:
- Khai báo CONST, TYPE, VAR
- Function và Procedure
- Tất cả các loại statement
- Cả hai tính năng mở rộng

```bash
parser.exe test.kpl
```

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
