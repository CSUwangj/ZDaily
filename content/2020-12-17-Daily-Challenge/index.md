+++
title = "2020-12-17 Daily-Challenge"
path = "2020-12-17-Daily-Challenge"
date = 2020-12-17 18:00:42+08:00
updated = 2020-12-17 18:15:32+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Count Number of Teams](https://leetcode.com/problems/count-number-of-teams/) on leetcode and leetcode's [December LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3569/) with `cpp`.

<!-- more -->

# Count Number of Teams

## Description

There are `n` soldiers standing in a line. Each soldier is assigned a **unique** `rating` value.

You have to form a team of 3 soldiers amongst them under the following rules:

- Choose 3 soldiers with index (`i`, `j`, `k`) with rating (`rating[i]`, `rating[j]`, `rating[k]`).
- A team is valid if: (`rating[i] < rating[j] < rating[k]`) or (`rating[i] > rating[j] > rating[k]`) where (`0 <= i < j < k < n`).

Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

**Example 1:**

```
Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
```

**Example 2:**

```
Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.
```

**Example 3:**

```
Input: rating = [1,2,3,4]
Output: 4
```

**Constraints:**

- `n == rating.length`
- `1 <= n <= 200`
- `1 <= rating[i] <= 10^5`

## Solution

brute force

``` cpp
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int len = rating.size();
        for(int i = 0; i < len-2; ++i) {
            for(int j = i+1; j < len-1; ++j) {
                for(int k = j+1; k < len; ++k) {
                    if(rating[i] > rating[j] && rating[j] > rating[k]) ans += 1;
                    if(rating[i] < rating[j] && rating[j] < rating[k]) ans += 1;
                }
            }
        }
        return ans;
    }
};
```

# December LeetCoding Challenge17

## Description

**4Sum II**

Given four lists A, B, C, D of integer values, compute how many tuples `(i, j, k, l)` there are such that `A[i] + B[j] + C[k] + D[l]` is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

**Example:**

```
Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
```

## Solution

two-way enumeration

``` cpp
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> AB, CD;
        for(auto i : A) {
            for(auto j : B) {
                AB[i+j] += 1;
            }
        }
        for(auto i : C) {
            for(auto j : D) {
                CD[i+j] += 1;
            }
        }
        int answer = 0;
        for(auto [num, cnt] : AB) {
            answer += cnt * CD[-num];
        }
        return answer;
    }
};
```