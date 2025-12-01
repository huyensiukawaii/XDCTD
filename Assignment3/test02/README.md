# Test Files - KPL Parser

Folder này chứa tất cả các file test và output cho KPL Parser.

## Test Files (.kpl)

### 1. test_simple.kpl
Test cơ bản với:
- Simple assignment
- Multiple variable assignment
- REPEAT-UNTIL loop

**Chạy:**
```bash
cd ..
./parser tests/test_simple.kpl
```

### 2. test_repeat.kpl
Test chi tiết cho REPEAT-UNTIL:
- Simple REPEAT-UNTIL
- REPEAT với multiple statements
- REPEAT lồng trong IF

**Chạy:**
```bash
cd ..
./parser tests/test_repeat.kpl
```

### 3. test_multiassign.kpl
Test chi tiết cho multiple assignment:
- Gán nhiều biến với số
- Gán với expressions
- Swap variables
- Array element assignment
- Mixed assignment

**Chạy:**
```bash
cd ..
./parser tests/test_multiassign.kpl
```

### 4. test.kpl
Test toàn diện:
- CONST, TYPE, VAR declarations
- FUNCTION và PROCEDURE
- All statement types
- Cả hai tính năng mở rộng

**Chạy:**
```bash
cd ..
./parser tests/test.kpl
```

### 5. test2.kpl ⭐ (Recommended)
**Test tổng hợp tất cả** - 14 test suites:
1. Basic Declarations
2. Procedure & Function
3. Simple Assignment
4. Multiple Variable Assignment (6 examples)
5. Array Assignment
6. IF-THEN-ELSE
7. WHILE-DO Loop
8. FOR-TO-DO Loop
9. REPEAT-UNTIL Loop (4 examples)
10. Complex Expressions
11. CALL Statements
12. Nested Structures
13. Comparison Operators (all 6)
14. Final Multiple Assignment Tests

**Chạy:**
```bash
cd ..
./parser tests/test2.kpl
```

## Output Files (.txt)

Output files chứa kết quả parse của các test:
- `output_simple.txt` - Output của test_simple.kpl
- `output_repeat.txt` - Output của test_repeat.kpl
- `output_multi.txt` - Output của test_multiassign.kpl

## Chạy tất cả tests

**Windows (PowerShell/CMD):**
```cmd
cd ..
for %f in (tests\*.kpl) do @echo Testing %f && parser.exe %f
```

**Linux/macOS/Git Bash:**
```bash
cd ..
for f in tests/*.kpl; do echo "Testing $f" && ./parser "$f" && echo "✓ PASSED" || echo "✗ FAILED"; done
```

## Kết quả mong đợi

Tất cả tests nên kết thúc với:
```
Program parsed!
```

## Notes

- Tất cả test files sử dụng cú pháp KPL đúng
- Array brackets: `(.` và `.)` (không phải `[` `]`)
- Not-equal operator: `!=` (không phải `<>`)
- Mỗi biến khai báo trên một dòng riêng
