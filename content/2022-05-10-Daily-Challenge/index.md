+++
updated = 2022-05-10 19:35:00+08:00
title = "2022-05-10 Daily-Challenge"
path = "2022-05-10-Daily-Challenge"
date = 2022-05-10 19:33:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/combination-sum-iii/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 10

## Description

**Combination Sum III**

Find all valid combinations of `k` numbers that sum up to `n` such that the following conditions are true:

- Only numbers `1` through `9` are used.
- Each number is used **at most once**.

Return *a list of all possible valid combinations*. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

**Example 1:**

```
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
```

**Example 2:**

```
Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
```

**Example 3:**

```
Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
```

 

**Constraints:**

- `2 <= k <= 9`
- `1 <= n <= 60`

## Solution

``` cpp
class Solution {
  void solve(
    vector<vector<int>> &answer,
    vector<int> &tmp,
    int index,
    int rest,
    int k
  ) {
    if(rest == 0 && tmp.size() == k) {
      answer.push_back(tmp);
      return;
    }
    if(tmp.size() >= k || index > 9 || index > rest) return;
    solve(answer, tmp, index + 1, rest, k);
    rest -= index;
    tmp.push_back(index);
    solve(answer, tmp, index + 1, rest, k);
    tmp.pop_back();
  }
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> answer;
    vector<int> tmp;
    solve(answer, tmp, 1, n, k);
    return vector<vector<int>>(answer.begin(), answer.end());
  }
};

// Accepted
// 18/18 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 20.91 % of cpp submissions (6.8 MB)
```
