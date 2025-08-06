
# 🔺 Pascal's Triangle Variations – C++ Implementations

This project demonstrates **three variations** of computing values from **Pascal's Triangle** using **Brute Force** and **Optimal** approaches in C++.

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

---

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

### ✅ Variation 3 — Print Full Pascal's Triangle

**File**: `Variation3.cpp`

**Task**: Given a number `n`, print the full Pascal's Triangle up to the `n`th row.

#### Approach:
- Uses a helper function to generate each row using the efficient iterative formula.
- Appends each row to a 2D vector and prints the full triangle.

#### Sample Output (for `row = 5`):
```
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
```

---

## ⚙️ How to Compile & Run

Make sure you have a C++ compiler like `g++`.

### Compile:
```bash
g++ Variation1.cpp -o variation1
g++ Variation2.cpp -o variation2
g++ Variation3.cpp -o variation3
```

### Run:
```bash
./variation1
./variation2
./variation3
```

---

## ⏱️ Time & Space Complexity

| Variation      | Approach       | Time Complexity | Space Complexity |
|----------------|----------------|------------------|------------------|
| **Variation 1** | Brute Force    | O(n)              | O(1)              |
|                | Optimal        | O(r)              | O(1)              |
| **Variation 2** | Brute Force    | O(n²) (due to repeated nCr) | O(n) |
|                | Optimal        | O(n)              | O(n)              |
| **Variation 3** | Optimal Only   | O(n²) (to generate all rows) | O(n²) |

---

## 📘 Concepts Used

- **Pascal's Triangle**
- **Combinatorics (`nCr`)**
- **Factorials**
- **Iterative Dynamic Formula**
- **Vector usage in C++**

---

## 💡 Notes

- Pascal’s Triangle is 0-indexed internally.
- Optimal methods avoid factorials and are suitable for large inputs.
- To avoid overflow, use `long long` or `__int128` for very large values.

---

## 📌 Author

**Shreyansh Kumar**
