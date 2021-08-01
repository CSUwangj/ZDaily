+++
title = "2021-03-18 Daily-Challenge"
path = "2021-03-18-Daily-Challenge"
date = 2021-03-18 16:27:53+08:00
updated = 2021-03-18 18:42:34+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Maximum Score from Performing Multiplication Operations](https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3676/) with `cpp`.

<!-- more -->

# Maximum Score from Performing Multiplication Operations

## Description

You are given two integer arrays `nums` and `multipliers` of size `n` and `m` respectively, where `n >= m`. The arrays are **1-indexed**.

You begin with a score of `0`. You want to perform **exactly** `m` operations. On the `ith` operation **(1-indexed)**, you will:

- Choose one integer `x` from **either the start or the end** of the array `nums`.
- Add `multipliers[i] * x` to your score.
- Remove `x` from the array `nums`.

Return *the **maximum** score after performing* `m` *operations.*

 

**Example 1:**

```
Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.
```

**Example 2:**

```
Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
Output: 102
Explanation: An optimal solution is as follows:
- Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
- Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
- Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
- Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
- Choose from the end, [-2,7], adding 7 * 6 = 42 to the score. 
The total score is 50 + 15 - 9 + 4 + 42 = 102.
```

 

**Constraints:**

- `n == nums.length`
- `m == multipliers.length`
- `1 <= m <= 10^3`
- `m <= n <= 10^5`
- `-1000 <= nums[i], multipliers[i] <= 1000`

## Solution

interval dynamic programming

I first write this

``` cpp
class Solution {
  // dp[i][j] means max score for m-th multipliers with front j elements
public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int m = multipliers.size();
    int len = nums.size();
    vector<vector<int>> dp(m + 1, vector<int>(m + 1));
    for(int i = 1; i <= m; ++i) {
      for(int j = 0; j <= i; ++j) {
        dp[i][j] = INT_MIN;
        if(j) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + nums[j - 1] * multipliers[i - 1]);
        if(j < i) dp[i][j] = max(dp[i][j], dp[i - 1][j] + nums[len - (i - j)] * multipliers[i - 1]);
        // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
      }
    }
    
    int answer = INT_MIN;
    for(int i = 0; i <= m; ++i) answer = max(answer, dp[m][i]);
    return answer;
  }
};

// Runtime: 528 ms, faster than 16.67% of C++ online submissions for Maximum Score from Performing Multiplication Operations.
// Memory Usage: 173.1 MB, less than 33.33% of C++ online submissions for Maximum Score from Performing Multiplication Operations.
```

then change `vector<vector<int>>` to `unordered_map<unordered_map<int, int>>`, but it `Time Limit Exceeded`, then I change it to raw array. ah ha!

``` cpp
class Solution {
  // dp[i][j] means max score for m-th multipliers with front j elements
public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int m = multipliers.size();
    int len = nums.size();
    int dp[1001][1001] = {0};
    for(int i = 1; i <= m; ++i) {
      for(int j = 0; j <= i; ++j) {
        dp[i][j] = INT_MIN;
        if(j) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + nums[j - 1] * multipliers[i - 1]);
        if(j < i) dp[i][j] = max(dp[i][j], dp[i - 1][j] + nums[len - (i - j)] * multipliers[i - 1]);
        // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
      }
    }
    
    int answer = INT_MIN;
    for(int i = 0; i <= m; ++i) answer = max(answer, dp[m][i]);
    return answer;
  }
};

// Runtime: 248 ms, faster than 100.00% of C++ online submissions for Maximum Score from Performing Multiplication Operations.
// Memory Usage: 87.2 MB, less than 100.00% of C++ online submissions for Maximum Score from Performing Multiplication Operations.
```

# March LeetCoding Challenge 18

## Description

**Wiggle Subsequence**

Given an integer array `nums`, return *the length of the longest **wiggle sequence***.

A **wiggle sequence** is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

- For example, `[1, 7, 4, 9, 2, 5]` is a **wiggle sequence** because the differences `(6, -3, 5, -7, 3)` are alternately positive and negative.
- In contrast, `[1, 4, 7, 2, 5]` and `[1, 7, 4, 5, 5]` are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

A **subsequence** is obtained by deleting some elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

 

**Example 1:**

```
Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence.
```

**Example 2:**

```
Input: nums = [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
```

**Example 3:**

```
Input: nums = [1,2,3,4,5,6,7,8,9]
Output: 2
```

 

**Constraints:**

- `1 <= nums.length <= 1000`
- `0 <= nums[i] <= 1000`

 

**Follow up:** Could you solve this in `O(n)` time?

## Solution

it's a simple problem, but example mislead me.

``` cpp
template <class T>
inline constexpr int sgn(const T &a) {
  return a > 0 ? 1  :
         a < 0 ? -1 :
         0;
}
class Solution {
public:
  int wiggleMaxLength(vector<int>& nums) {
    int len = nums.size();
    if(len < 2) return len;
    
    int pos = 1;
    
    // all same
    while(pos < len && nums[pos] == nums[pos - 1]) pos += 1;
    if(pos == len) return 1;
    
    int answer = 2;
    int sign = sgn(nums[pos] - nums[pos - 1]);
    pos += 1;
    while(pos < len) {
      while(pos < len && sgn(sign + sgn(nums[pos] - nums[pos - 1])) == sign) {
        pos += 1;
      }
      if(pos < len) {
        sign = -sign;
        pos += 1;
        answer += 1;
      }
    }
    
    return answer;
  }
};

// 26 / 26 test cases passed.
// Status: Accepted
// Runtime: 0 ms
// Memory Usage: 7 MB
```
