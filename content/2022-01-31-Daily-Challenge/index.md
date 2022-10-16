+++
title = "2022-01-31 Daily-Challenge"
path = "2022-01-31-Daily-Challenge"
date = 2022-01-31 13:26:00+08:00
updated = 2022-01-31 13:27:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/richest-customer-wealth/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 31

## Description

**Richest Customer Wealth**

You are given an `m x n` integer grid `accounts` where `accounts[i][j]` is the amount of money the `ith` customer has in the `jth` bank. Return *the **wealth** that the richest customer has.*

A customer's **wealth** is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum **wealth**.

 

**Example 1:**

```
Input: accounts = [[1,2,3],[3,2,1]]
Output: 6
Explanation:
1st customer has wealth = 1 + 2 + 3 = 6
2nd customer has wealth = 3 + 2 + 1 = 6
Both customers are considered the richest with a wealth of 6 each, so return 6.
```

**Example 2:**

```
Input: accounts = [[1,5],[7,3],[3,5]]
Output: 10
Explanation: 
1st customer has wealth = 6
2nd customer has wealth = 10 
3rd customer has wealth = 8
The 2nd customer is the richest with a wealth of 10.
```

**Example 3:**

```
Input: accounts = [[2,8,7],[7,1,3],[1,9,5]]
Output: 17
```

 

**Constraints:**

- `m == accounts.length`
- `n == accounts[i].length`
- `1 <= m, n <= 50`
- `1 <= accounts[i][j] <= 100`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int maximumWealth(vector<vector<int>>& accounts) {
    int answer = 0;
    for(auto &account : accounts) {
      answer = max(answer, accumulate(account.begin(), account.end(), 0));
    }
    return answer;
  }
};

// Accepted
// 34/34 cases passed (4 ms)
// Your runtime beats 90.57 % of cpp submissions
// Your memory usage beats 49.93 % of cpp submissions (7.9 MB)
```
