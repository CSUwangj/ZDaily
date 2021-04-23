+++
title = "2021-04-22 Daily-Challenge"
path = "2021-04-22-Daily-Challenge"
date = 2021-04-22 18:27:20+08:00
updated = 2021-04-22 19:37:53+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Decode Ways](https://leetcode.com/problems/count-items-matching-a-rule/), [Decode Ways II](https://leetcode.com/problems/decode-ways-ii/) and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3717/) with `cpp`.

<!-- more -->

# Decode Ways

## Description

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

Given a string `s` containing only digits, return *the **number** of ways to **decode** it*.

The answer is guaranteed to fit in a **32-bit** integer.

 

**Example 1:**

```
Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
```

**Example 2:**

```
Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
```

**Example 3:**

```
Input: s = "0"
Output: 0
Explanation: There is no character that is mapped to a number starting with 0.
The only valid mappings with 0 are 'J' -> "10" and 'T' -> "20", neither of which start with 0.
Hence, there are no valid ways to decode this since all digits need to be mapped.
```

**Example 4:**

```
Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
```

 

**Constraints:**

- `1 <= s.length <= 100`
- `s` contains only digits and may contain leading zero(s).

## Solution

``` cpp
class Solution {
public:
  int numDecodings(string s) {
    if(s.front() == '0') return 0;
    int len = s.length();
    vector<int> dp(len + 1);
    dp[0] = 1;
    for(int i = 0; i < len; ++i) {
      if(s[i] != '0') {
        dp[i + 1] += dp[i];
      }
      if(i && ((s[i] < '7' && s[i - 1] == '2') || s[i - 1] == '1')) {
        dp[i + 1] += INT_MAX - dp[i - 1] < dp[i + 1] ? 0 : dp[i - 1];
      }
      if(!dp[i] && dp[i + 1])return 0;
    }
    return dp.back();
  }
};
```

# Decode Ways II

## Description

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

- <code>1 <= s.length <= 10<sup>5</sup></code>
- `s[i]` is a digit or `'*'`.

## Solution

First I wrote this

``` cpp
const int MOD = 1e9 + 7;
class Solution {
  void dealOneChar(vector<vector<int>> &dp, int index, int c, char prev) {
    if(index && c < 7 && (prev == '*' || prev == '2')) {
      dp[index + 1][c] += dp[index - 1][10]; 
      dp[index + 1][c] %= MOD;
    }
    if(index && (prev == '*' || prev == '1')) {
      dp[index + 1][c] += dp[index - 1][10];
      dp[index + 1][c] %= MOD;
    }
    if(c) {
      dp[index + 1][c] += dp[index][10];
      dp[index + 1][c] %= MOD;
    }
  }
public:
  int numDecodings(string s) {
    int len = s.length();
    vector<vector<int>> dp(len + 1, vector<int>(11));
    dp[0][10] = 1;
    for(int i = 0; i < len; ++i) {
      char prev = i ? s[i - 1] : -1;
      if(s[i] == '*') {
        for(int c = 0; c < 10; ++c) {
          dealOneChar(dp, i, c, prev);
          dp[i + 1][10] += dp[i + 1][c];
          dp[i + 1][10] %= MOD;
        }
        if(prev == '1' || prev == '*') dp[i + 1][10] -= dp[i - 1][10];
        if(prev == '2' || prev == '*') dp[i + 1][10] -= dp[i - 1][10];
        dp[i + 1][10] %= MOD;
        dp[i + 1][10] += MOD;
        dp[i + 1][10] %= MOD;
      } else {
        int c = s[i] - '0';
        dealOneChar(dp, i, c, prev);
        dp[i + 1][10] = dp[i + 1][c];
      }
      if(!dp[i][10] && !dp[i + 1][10]) return 0;
      // cout << dp[i + 1][10] << ' ';
    }
    // cout << endl;
    return dp.back().back();
  }
};


// 217 / 217 test cases passed.
// Status: Accepted
// Runtime: 408 ms
// Memory Usage: 127.1 MB
```

then I realize that I wasted 10 resources

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

// 217 / 217 test cases passed.
// Status: Accepted
// Runtime: 36 ms
// Memory Usage: 21.6 MB
```

then use some trick

``` cpp
const int MOD = 1e9 + 7;
auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
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
    }
    return dp.back();
  }
};
// Runtime: 12 ms, faster than 100.00% of C++ online submissions for Decode Ways II.
// Memory Usage: 21.7 MB, less than 33.92% of C++ online submissions for Decode Ways II.
// Next challenges:
```

# April LeetCoding challenge22

## Description

**Brick Wall**

There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The bricks have the same height but different width. You want to draw a vertical line from the **top** to the **bottom** and cross the **least** bricks.

The brick wall is represented by a list of rows. Each row is a list of integers representing the width of each brick in this row from left to right.

If your line go through the edge of a brick, then the brick is not considered as crossed. You need to find out how to draw the line to cross the least bricks and return the number of crossed bricks.

**You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.**

 

**Example:**

<pre><code>
Input: [[1,2,2,1],
        [3,1,2],
        [1,3,2],
        [2,4],
        [3,1,2],
        [1,3,1,1]]

Output: 2

Explanation: 

<img src="https://assets.leetcode.com/uploads/2018/10/12/brick_wall.png" style="width: 100%; max-width: 350px">
</code></pre>

**Note:**

1. The width sum of bricks in different rows are the same and won't exceed INT_MAX.
2. The number of bricks in each row is in range [1,10,000]. The height of wall is in range [1,10,000]. Total number of bricks of the wall won't exceed 20,000.

## Solution

``` cpp
class Solution {
public:
  int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> gaps;
    int width = accumulate(wall.front().begin(), wall.front().end(), 0);
    int answer = 0;
    for(auto &bricks : wall) {
      int sum = 0;
      for(int brick : bricks) {
        sum += brick;
        gaps[sum] += 1;
        if(sum != width) answer = max(answer, gaps[sum]);
      }
    }
    return wall.size() - answer;
  }
};
```
