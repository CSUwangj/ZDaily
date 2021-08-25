+++
title = "2021-08-25 Daily-Challenge"
path = "2021-08-25-Daily-Challenge"
date = 2021-08-25 18:03:23+08:00
updated = 2021-08-25 18:37:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Expressive Words](https://leetcode.com/problems/expressive-words/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3908/) with `cpp`.

<!-- more -->

# Expressive Words

## Description

Sometimes people repeat letters to represent extra feeling. For example:

- `"hello" -> "heeellooo"`
- `"hi" -> "hiiii"`

In these strings like `"heeellooo"`, we have groups of adjacent letters that are all the same: `"h"`, `"eee"`, `"ll"`, `"ooo"`.

You are given a string `s` and an array of query strings `words`. A query word is **stretchy** if it can be made to be equal to `s` by any number of applications of the following extension operation: choose a group consisting of characters `c`, and add some number of characters `c` to the group so that the size of the group is **three or more**.

- For example, starting with `"hello"`, we could do an extension on the group `"o"` to get `"hellooo"`, but we cannot get `"helloo"` since the group `"oo"` has a size less than three. Also, we could do another extension like `"ll" -> "lllll"` to get `"helllllooo"`. If `s = "helllllooo"`, then the query word `"hello"` would be **stretchy** because of these two extension operations: `query = "hello" -> "hellooo" -> "helllllooo" = s`.

Return *the number of query strings that are **stretchy***.

 

**Example 1:**

```
Input: s = "heeellooo", words = ["hello", "hi", "helo"]
Output: 1
Explanation: 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not size 3 or more.
```

**Example 2:**

```
Input: s = "zzzzzyyyyy", words = ["zzyy","zy","zyy"]
Output: 3
```

 

**Constraints:**

- `1 <= s.length, words.length <= 100`
- `1 <= words[i].length <= 100`
- `s` and `words[i]` consist of lowercase letters.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  bool expressiveWord(string &s, string&t) {
    int sLen = s.length();
    int tLen = t.length();
    int sPos = 0;
    int tPos = 0;
    while(sPos < sLen && tPos < tLen) {
      char sC = s[sPos];
      int sCnt = 0;
      while(sPos < sLen && s[sPos] == sC) {
        sCnt += 1;
        sPos += 1;
      }
      char tC = t[tPos];
      int tCnt = 0;
      while(tPos < tLen && t[tPos] == tC) {
        tCnt += 1;
        tPos += 1;
      }
      if(tC != sC || tCnt > sCnt || (tCnt == 1 && sCnt == 2)) return false;
    }
    return sPos == sLen && tPos == tLen;
  }
public:
  int expressiveWords(string s, vector<string>& words) {
    int answer = 0;
    for(auto &t : words) {
      answer += expressiveWord(s, t);
    }
    return answer;
  }
};

// Accepted
// 34/34 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 82.68 % of cpp submissions (7.6 MB)
```

# August LeetCoding Challenge 25

## Description

**Sum of Square Numbers**

Given a non-negative integer `c`, decide whether there're two integers `a` and `b` such that `a2 + b2 = c`.

 

**Example 1:**

```
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
```

**Example 2:**

```
Input: c = 3
Output: false
```

**Example 3:**

```
Input: c = 4
Output: true
```

**Example 4:**

```
Input: c = 2
Output: true
```

**Example 5:**

```
Input: c = 1
Output: true
```

 

**Constraints:**


<ul>
	<li><code>0 &lt;= c &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
constexpr auto table = []{
  array<long long, 46342> arr{0};
  for(int i = 1; i < 46341; ++i) arr[i] = i * i;
  arr[46341] = 1LL + INT_MAX;
  return arr;
}();
class Solution {
public:
  bool judgeSquareSum(int c) {
    int begin = 0;
    int end = lower_bound(table.begin(), table.end(), c) - table.begin();
    while(begin <= end) {
      long long result = table[begin] + table[end];
      if(result == c) return true;
      if(result < c) {
        begin += 1;
      } else {
        end -= 1;
      }
    }
    return false;
  }
};

// Accepted
// 124/124 cases passed (4 ms)
// Your runtime beats 54.21 % of cpp submissions
// Your memory usage beats 10.72 % of cpp submissions (6.4 MB)
```

Fermat theorem solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  bool judgeSquareSum(int c) {
    for(int i = 2; i * i <= c; ++i) {
      if(c % i == 0) {
        int count = 0;
        while(c % i == 0) {
          count += 1;
          c /= i;
        }
        if(i % 4 == 3 && (count & 1)) {
          return false;
        }
      }
    }
    return c % 4 != 3;
  }
};

// Accepted
// 124/124 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 11.27 % of cpp submissions (6 MB)
```
