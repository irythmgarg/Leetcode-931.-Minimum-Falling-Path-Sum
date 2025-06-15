# Leetcode-931.-Minimum-Falling-Path-Sum
# 🌟 Minimum Falling Path Sum - Problem Guide 🧩

## 📝 Problem Statement

Given an `n x n` matrix of integers, return the **minimum sum of a falling path** through the matrix.

A falling path starts at any element in the first row and chooses one element from each row. The next row's chosen element must be from the column directly below or diagonally left/right of the previous row's element.

### 📥 Input:

A square matrix of integers.

### 📤 Output:

An integer representing the minimum falling path sum from top to bottom.

---

## 🚀 Approaches to Solve the Problem

### 🔁 1. Pure Recursive Approach (Brute Force)

🧠 **Idea**:

* Start from every cell in the first row.
* For each cell, recursively explore all three possible moves: straight down, diagonally left, and diagonally right.
* Recurse until the last row and return the minimum path sum.

📉 **Drawbacks**:

* Extremely inefficient for large matrices.
* Recalculates the same subproblems multiple times.

⏱️ **Time Complexity**: `O(3^n)` (exponential due to multiple branching)
💾 **Space Complexity**: `O(n)` (recursion stack)

---

### 📦 2. Top-Down Approach (Memoization / DP with Recursion)

🧠 **Idea**:

* Same as recursion, but we store the result of each subproblem in a DP table.
* If we encounter the same subproblem again, we simply return the stored result instead of recalculating.

🎯 **Benefits**:

* Much faster than the pure recursive approach.
* Avoids redundant work using `memoization`.

🧮 **Steps**:

1. Create a `dp` matrix initialized with `-1`.
2. For each cell in the first row, recursively compute the minimum falling path sum.
3. Use the `dp` table to store already computed results.

⏱️ **Time Complexity**: `O(n^2)`
💾 **Space Complexity**: `O(n^2)` (for DP table) + `O(n)` (recursion stack)

---

### 📊 3. Bottom-Up Approach (Tabulation)

🧠 **Idea**:

* Use dynamic programming in an iterative manner.
* Start from the first row and build the result row by row.
* Each cell value is updated based on the minimum of three possible paths from the row above.

🎯 **Benefits**:

* Most efficient and avoids recursion.
* No stack overhead and easy to implement.

🧮 **Steps**:

1. Initialize a DP table with the same dimensions as the matrix.
2. Fill the first row as it is.
3. For each cell from the second row onward, compute its value based on the minimum of valid paths from the previous row.
4. At the last row, find the minimum value — this is the result.

⏱️ **Time Complexity**: `O(n^2)`
💾 **Space Complexity**: `O(n^2)` (can be optimized to `O(n)`)

---

## 📊 Approach Comparison

| Approach        | Time Complexity | Space Complexity   | Suitability                 |
| --------------- | --------------- | ------------------ | --------------------------- |
| Recursive       | `O(3^n)`        | `O(n)`             | ❌ Inefficient               |
| Top-Down (Memo) | `O(n^2)`        | `O(n^2)`           | ✅ Good for understanding DP |
| Bottom-Up (Tab) | `O(n^2)`        | `O(n^2)` or `O(n)` | ✅✅ Best Performance         |

---

## 🧪 Example

### 🔢 Matrix:

```
[
  [2, 1, 3],
  [6, 5, 4],
  [7, 8, 9]
]
```

### ✅ Output:

```
13
```

### 💡 Explanation:

* Path chosen: 1 → 4 → 8
* Sum: `1 + 4 + 8 = 13`

---

## 👤 Author Info

**👨‍💻 Name**: Ridham Garg
**🏫 University**: Thapar University, Patiala
**🎓 Roll Number**: 102203014

---

## 🎉 Final Thoughts

* Always go for **bottom-up tabulation** for optimal performance.
* Understand recursion and memoization to strengthen your dynamic programming skills.
* Visualize the movement in the matrix to better debug your solution.

Happy Coding! 🚀🧠🎯
