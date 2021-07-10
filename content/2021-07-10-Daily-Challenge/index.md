+++
title = "2021-07-10 Daily-Challenge"
path = "2021-07-10-Daily-Challenge"
date = 2021-07-10 18:41:35+08:00
updated = 2021-07-10 19:22:23+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3809/) with `cpp`.

<!-- more -->

# LeetCode Review

## Longest Increasing Subsequence

too easy to review

## Maximum Length of Repeated Subarray

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int dp[1001];
class Solution {
public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    // cout << "$$$$$$$$$$$$"<<endl;
    int len1 = nums1.size();
    int len2 = nums2.size();
    int answer = 0;
    memset(dp, 0, sizeof(dp[0]) * (len1 + 1));
    for(int i = len1 - 1; i >= 0; --i) {
      for(int j = 0; j < len2; ++j) {
        if(nums1[i] == nums2[j]) {
          dp[j] = dp[j + 1] + 1;
          answer = max(answer, dp[j]);
        } else {
          dp[j] = 0;
        }
        // cout << dp[j] <<  ' ';
      }
      // cout << endl;
    }
    return answer;
  }
};

// Accepted
// 55/55 cases passed (128 ms)
// Your runtime beats 97.65 % of cpp submissions
// Your memory usage beats 91.98 % of cpp submissions (11.8 MB)
```

## Kth Smallest Element in a Sorted Matrix

too easy to review

## Reduce Array Size to The Half

too easy to review

## Reshape the Matrix

too easy to review

## Cinema Seat Allocation

too easy to review

## Apply Discount Every n Orders

too easy to review

## Frog Position After T Seconds

too easy to review

## Make Sum Divisible by P

too easy to review

## Number of Different Integers in a String

too easy to review

# July LeetCoding Challenge10

## Description

**Decode Ways II**

A message containing letters from `A-Z` can be **encoded** into numbers using the following mapping:

```
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
```

To **decode** an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, `"11106"` can be mapped into:

- `"AAJF"` with the grouping `(1 1 10 6)`
- `"KJF"` with the grouping `(11 10 6)`

Note that the grouping `(1 11 06)` is invalid because `"06"` cannot be mapped into `'F'` since `"6"` is different from `"06"`.

**In addition** to the mapping above, an encoded message may contain the `'*'` character, which can represent any digit from `'1'` to `'9'` (`'0'` is excluded). For example, the encoded message `"1*"` may represent any of the encoded messages `"11"`, `"12"`, `"13"`, `"14"`, `"15"`, `"16"`, `"17"`, `"18"`, or `"19"`. Decoding `"1*"` is equivalent to decoding **any** of the encoded messages it can represent.

Given a string `s` containing digits and the `'*'` character, return *the **number** of ways to **decode** it*.

Since the answer may be very large, return it **modulo** `109 + 7`.

 

**Example 1:**

```
Input: s = "*"
Output: 9
Explanation: The encoded message can represent any of the encoded messages "1", "2", "3", "4", "5", "6", "7", "8", or "9".
Each of these can be decoded to the strings "A", "B", "C", "D", "E", "F", "G", "H", and "I" respectively.
Hence, there are a total of 9 ways to decode "*".
```

**Example 2:**

```
Input: s = "1*"
Output: 18
Explanation: The encoded message can represent any of the encoded messages "11", "12", "13", "14", "15", "16", "17", "18", or "19".
Each of these encoded messages have 2 ways to be decoded (e.g. "11" can be decoded to "AA" or "K").
Hence, there are a total of 9 * 2 = 18 ways to decode "1*".
```

**Example 3:**

```
Input: s = "2*"
Output: 15
Explanation: The encoded message can represent any of the encoded messages "21", "22", "23", "24", "25", "26", "27", "28", or "29".
"21", "22", "23", "24", "25", and "26" have 2 ways of being decoded, but "27", "28", and "29" only have 1 way.
Hence, there are a total of (6 * 2) + (3 * 1) = 12 + 3 = 15 ways to decode "2*".
```

 

**Constraints:**

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is a digit or <code>&#39;*&#39;</code>.</li>
</ul>


## Solution

``` cpp
const int MOD = 1e9 + 7;
class Solution {
public:
  int numDecodings(string s) {
    int len = s.length();
    vector<long long> dp(len + 1);
    dp[0] = 1;
    for(int i = 0; i < len; ++i) {
      char prev = i ? s[i - 1] : -1;
      if(s[i] == '*') {
        dp[i + 1] = dp[i] * 9;
        if(prev == '1') dp[i + 1] += dp[i - 1] * 9;
        if(prev == '2') dp[i + 1] += dp[i - 1] * 6;
        if(prev == '*') dp[i + 1] += dp[i - 1] * 15;
      } else {
        if(s[i] < '7' && (prev == '2' || prev == '*')) dp[i + 1] += dp[i - 1];
        if(prev == '1' || prev == '*') dp[i + 1] += dp[i - 1];
        if(s[i] != '0') dp[i + 1] += dp[i];
      }
      dp[i + 1] %= MOD;
      if(!dp[i] && !dp[i + 1]) return 0;
      // cout << dp[i + 1][10] << ' ';
    }
    // cout << endl;
    return dp.back();
  }
};
```
