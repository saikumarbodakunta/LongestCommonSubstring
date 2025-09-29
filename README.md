# Longest Common Substring (C++) — Student Submission

This repository contains a C++ program that computes the **Longest Common Substring (LCS)** between two input strings using a dynamic programming lookup table. The program prints the table used to compute the answer and returns one of the longest common substrings.

---

## Files
- `LongestCommonSubstring.cpp` — source code  
- `README.md` — this file  

---
   ## Example Output (sample)
```
Lookup table (rows: first string, columns: second string)

        B   A   B   A
    0   0   0   0   0
A   0   0   1   0   1
B   0   1   0   2   0
A   0   0   2   0   3
B   0   1   0   3   0

Longest Common Substring: ABA
Length: 3
```
