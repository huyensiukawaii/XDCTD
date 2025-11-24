# Bài 1: Scanner cho ngôn ngữ KPL

## Cách Chạy

### 1. Biên dịch
```bash
cd Assignment2/Bai1
make
```

### 2. Chạy
```bash
./scanner test.kpl
```

### 3. Xem output
```
1-1:KW_PROGRAM
1-9:TK_IDENT(Example1)
1-17:SB_SEMICOLON
...
```

**Định dạng output**: `Line-Col:TokenType(value)`

### Ví dụ file test
```kpl
PROGRAM Example1;
BEGIN
END.
```

### Lệnh Makefile
```bash
make        # Biên dịch
make clean  # Xóa file object
```
