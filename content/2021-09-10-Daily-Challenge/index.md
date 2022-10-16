+++
title = "2021-09-10 Daily-Challenge"
path = "2021-09-10-Daily-Challenge"
date = 2021-09-10 19:04:59+08:00
updated = 2021-09-10 19:49:32+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Binary Gap](https://leetcode.com/problems/binary-gap/description/) and leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3970/) with `cpp`.

<!-- more -->

# Binary Gap

## Description

Given a positive integer `n`, find and return *the **longest distance** between any two **adjacent*** `1`*'s in the binary representation of* `n`*. If there are no two adjacent* `1`*'s, return* `0`*.*

Two `1`'s are **adjacent** if there are only `0`'s separating them (possibly no `0`'s). The **distance** between two `1`'s is the absolute difference between their bit positions. For example, the two `1`'s in `"1001"` have a distance of 3.

 

**Example 1:**

```
Input: n = 22
Output: 2
Explanation: 22 in binary is "10110".
The first adjacent pair of 1's is "10110" with a distance of 2.
The second adjacent pair of 1's is "10110" with a distance of 1.
The answer is the largest of these two distances, which is 2.
Note that "10110" is not a valid pair since there is a 1 separating the two 1's underlined.
```

**Example 2:**

```
Input: n = 5
Output: 2
Explanation: 5 in binary is "101".
```

**Example 3:**

```
Input: n = 6
Output: 1
Explanation: 6 in binary is "110".
```

**Example 4:**

```
Input: n = 8
Output: 0
Explanation: 8 in binary is "1000".
There aren't any adjacent pairs of 1's in the binary representation of 8, so we return 0.
```

**Example 5:**

```
Input: n = 1
Output: 0
```

 

**Constraints:**

- `1 <= n <= 10^9`

## Solution

``` cpp
class Solution {
public:
  int binaryGap(int n) {
    int previous = -1;
    int answer = 0;
    for(int i = 0; i < 31; ++i) {
      if(n & (1 << i)) {
        if(previous != -1) {
          answer = max(answer, i - previous);
        }
        previous = i;
      }
    }

    return answer;
  }
};

// Accepted
// 261/261 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 38.57 % of cpp submissions (6 MB)
```

# September LeetCoding Challenge 10

## Description

**Arithmetic Slices II - Subsequence**

Given an integer array `nums`, return *the number of all the **arithmetic subsequences** of* `nums`.

A sequence of numbers is called arithmetic if it consists of **at least three elements** and if the difference between any two consecutive elements is the same.

- For example, `[1, 3, 5, 7, 9]`, `[7, 7, 7, 7]`, and `[3, -1, -5, -9]` are arithmetic sequences.
- For example, `[1, 1, 2, 5, 7]` is not an arithmetic sequence.

A **subsequence** of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

- For example, `[2,5,10]` is a subsequence of `[1,2,1,**2**,4,1,**5**,**10**]`.

The test cases are generated so that the answer fits in **32-bit** integer.

 

**Example 1:**

```
Input: nums = [2,4,6,8,10]
Output: 7
Explanation: All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
```

**Example 2:**

```
Input: nums = [7,7,7,7,7]
Output: 16
Explanation: Any subsequence of this array is arithmetic.
```

 

**Constraints:**

<ul>
	<li><code>1&nbsp; &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

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
  int numberOfArithmeticSlices(vector<int>& nums) {
    using ll = long long;
    int len = nums.size();
    int answer = 0;
    map<int, vector<int>> indices;
    for(int i = 0; i < len; ++i) {
      indices[nums[i]].push_back(i);
    }
    vector<vector<int>> dp(len, vector<int>(len));
    for(int i = 1; i < len; ++i) {
      for(int j = 0; j < i; ++j) {
        ll k = 2LL * nums[j] - nums[i];
        if(k > INT_MAX || k < INT_MIN) continue;
        if(indices.count(k)) {
          for(auto index : indices[k]) {
            if(index >= j) break;
            dp[j][i] += dp[index][j] + 1;
          }
        }
        answer += dp[j][i];
      }
    }

    return answer;
  }
};

// Accepted
// 101/101 cases passed (192 ms)
// Your runtime beats 94.46 % of cpp submissions
// Your memory usage beats 95.73 % of cpp submissions (29.8 MB)
```
