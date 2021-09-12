
memo: 2021/09/11
---

- one of top 3 topics in CP
  - other top: Graph & Math
- D+ level problems for CP
- Algorithm zohioh argachlal
  - olon pattern bga
  - memory pattern

## Example 1: Fibonacci

Bottom Up
- dp[0] -> dp[n]

Top Down
- recursive
- dp[n] -> dp[0]
- check on previous dp
- heap problem for python(TLE)

## Example 2: Linear DP

- Climbing Stairs (LeetCode)

Whey Linear?
- 1d array

Approach
1. State: dp[n]-d yu tawihuu
2. Transition: (time complexity?)
3. Answer

## Example 3: Knapsack DP

- table size is important
  - 2d
Idea
- use ith item
- not use ith item

How to choose j ?
- i is item
- j is? maybe first see for constraints

# Example 4: Interval DP

- dp[i][j] : string[i:j]
- O(n^2)

# Example 5: Bit DP

- olonlog subset
- O(2^n)
- dp on the set
- set is bit (bitmask)
- bitmask is previous path
- brute force: permutation factorial
- dp bit: 2^n

# Example 6: Cadane's Algorithm

- dp[i], i inclusive max


# Example 7: Longest common sub string

- dp[i], i inclusive max
