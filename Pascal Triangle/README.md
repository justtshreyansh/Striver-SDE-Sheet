
# 🔺 Pascal's Triangle Variations – C++ Implementations

This project demonstrates **two variations** of computing values from **Pascal's Triangle** using **Brute Force** and **Optimal** approaches in C++.

---

## 📁 Variations Overview

### ✅ Variation 1 — Get a Specific Element

**File**: `Variation1.cpp`

**Task**: Given a row and column number, compute the **specific element** at that position in Pascal's Triangle.

#### Approaches:
- **Brute Force**: Uses the formula:  
  \[
  \text{nCr} = \frac{n!}{r!(n-r)!}
  \]
- **Optimal Approach**: Computes `nCr` without factorials using:
  \[
  \text{nCr} = \text{nC(r-1)} \times \frac{n - r + 1}{r}
  \]

### ✅ Variation 2 — Get Entire Row

**File**: `Variation2.cpp`

**Task**: Given a row number, compute **all elements** of that row in Pascal's Triangle.

#### Approaches:
- **Brute Force**: Repeatedly calls the combination formula using `nCr`.
- **Optimal Approach**: Builds the row iteratively using previous value:
  \[
  \text{nCr} = \text{nC(r-1)} \times \frac{n - r + 1}{r}
  \]

---

## 🔍 Sample Output

### Variation 1:
```cpp
int row = 4;
int col = 3;
```
**Output:**
```
3
3
```

> The 3rd element (0-based index) in the 3rd row (0-based index) is `3`.

---

### Variation 2:
```cpp
int row = 4;
```
**Output:**
```
1 3 3 1
```

> These are the values of the 3rd row (0-based) in Pascal’s Triangle.

---

## ⚙️ How to Compile & Run

Make sure you have a C++ compiler like `g++`.

### Compile:
```bash
g++ Variation1.cpp -o variation1
g++ Variation2.cpp -o variation2
```

### Run:
```bash
./variation1
./variation2
```

---

## ⏱️ Time & Space Complexity

| Variation      | Approach       | Time Complexity | Space Complexity |
|----------------|----------------|------------------|------------------|
| **Variation 1** | Brute Force    | O(n)              | O(1)              |
|                | Optimal        | O(r)              | O(1)              |
| **Variation 2** | Brute Force    | O(n²) (due to repeated nCr) | O(n) |
|                | Optimal        | O(n)              | O(n)              |

---

## 📘 Concepts Used

- **Pascal's Triangle**
- **Combinatorics (`nCr`)**
- **Factorials**
- **Iterative Dynamic Formula**
- **Vector usage in C++**

---

## 💡 Notes

- Pascal’s Triangle is 0-indexed in both variations.
- The optimal approaches avoid heavy factorial calculations, making them more efficient and suitable for larger inputs.
- Overflow is possible for large `n`, consider using `long long` or `__int128` for safety in real applications.

---

## 📌 Author

**Shreyansh Kumar**
