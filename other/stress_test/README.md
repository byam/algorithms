Problem Description

Problem

Given a sequence of non-negative integers a0,…,an−1, find the maximum pairwise product, that is, the largest integer that can be obtained by multiplying two different elements from the sequence (or, more formally, max0≤i≠j≤n−1aiaj). Different elements here mean ai and aj with i≠j (it can be the case that ai=aj).

* Input format

The first line of the input contains an integer n. The next line contains n non-negative integers a0,…,an−1 (separated by spaces).

* Constraints

    - `2 ≤ n ≤ 2 x 10^5`
    - `0 ≤ a0,…,an−1 ≤ 10^5`

* Output format

Output a single number — the maximum pairwise product.

* Sample 1

Input:
```
1
2
3
1 2 3
```
Output:
```
1
6
```
Explanation:
```
6=2×3
```

* Sample 2

Input:
```
1
2
10
7 5 14 2 8 8 10 1 2 3
```
Output:
```
1
140
```
Explanation:
```
140=14×10
```

* Sample 3

Input:
```
1
2
5
4 6 2 6 1
```
Output:
```
36
```