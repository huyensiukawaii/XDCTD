# Bài 2: Scanner cho ngôn ngữ KPL (Mở Rộng)

## Cách Chạy

### 1. Biên dịch
```bash
cd Assignment2/Bai2
make clean
make
```

### 2. Chạy
```bash
./scanner test_bai2.kpl
```

### 3. Xem output
```
1-1:KW_PROGRAM
1-9:TK_IDENT(Bai2)
1-13:SB_SEMICOLON
...
7-10:SB_POW
8-10:SB_MOD
9-14:TK_STRING("Hello")
12-3:KW_REPEAT
14-3:KW_UNTIL
...
```

**Định dạng output**: `Line-Col:TokenType(value)`

### Ví dụ file test
```kpl
PROGRAM Bai2;
VAR x : INTEGER;
BEGIN
  x := 2 ** 10;    // Mũ: 2^10
  x := x % 3;      // Mod
END.
```

### Lệnh Makefile
```bash
make        # Biên dịch
make clean  # Xóa file object
```

## Các Tính Năng Mới (Bài 2)

- **STRING**: `message := "Hello";`
- **BYTES**: `VAR data : BYTES;`
- **MOD (%)**: `x % 5` (lấy phần dư)
- **POW (**)**: `2 ** 10` (mũ)
- **REPEAT...UNTIL**: 
  ```kpl
  REPEAT
    x := x - 1;
  UNTIL x = 0;
  ```
- **Comment C++**: `// Comment đến cuối dòng`
- **Comment Pascal**: `(* Comment khối *)`
