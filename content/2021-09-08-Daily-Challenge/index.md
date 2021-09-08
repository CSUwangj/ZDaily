+++
title = "2021-09-08 Daily-Challenge"
path = "2021-09-08-Daily-Challenge"
date = 2021-09-08 20:13:44+08:00
updated = 2021-09-08 21:22:40+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Strange Printer](https://leetcode.com/problems/strange-printer/description/) and leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3968/) with `cpp`.

<!-- more -->

# Strange Printer

## Description

There is a strange printer with the following two special properties:

- The printer can only print a sequence of **the same character** each time.
- At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.

Given a string `s`, return *the minimum number of turns the printer needed to print it*.

 

**Example 1:**

```
Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".
```

**Example 2:**

```
Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
```

 

**Constraints:**

- `1 <= s.length <= 100`
- `s` consists of lowercase English letters.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int dp[100][100];
class Solution {
public:
  int strangePrinter(string target) {
    string s;
    s.push_back(target.front());
    for(auto c : target) {
      if(c != s.back()) {
        s.push_back(c);
      }
    }
    int len = s.length();
    for(int l = 0; l < len; ++l) {
      for(int left = 0; left + l < len; ++left) {
        int right = left + l;
        if(!l) {
          dp[left][right] = 1;
        } else {
          dp[left][right] = dp[left][right - 1] + 1;
        }
        for(int middle = left; middle < right; middle += 1) {
          if(s[middle] == s[right]) {
            dp[left][right] = min(dp[left][right], dp[left][middle] + dp[middle + 1][right - 1]);
          }
        }
      }
    }
    return dp[0][len - 1];
  }
};

// Accepted
// 200/200 cases passed (12 ms)
// Your runtime beats 98.86 % of cpp submissions
// Your memory usage beats 66.76 % of cpp submissions (6.3 MB)
```

# September LeetCoding Challenge 8

## Description

**Shifting Letters**

You are given a string `s` of lowercase English letters and an integer array `shifts` of the same length.

Call the `shift()` of a letter, the next letter in the alphabet, (wrapping around so that `'z'` becomes `'a'`).

- For example, `shift('a') = 'b'`, `shift('t') = 'u'`, and `shift('z') = 'a'`.

Now for each `shifts[i] = x`, we want to shift the first `i + 1` letters of `s`, `x` times.

Return *the final string after all such shifts to s are applied*.

 

**Example 1:**

```
Input: s = "abc", shifts = [3,5,9]
Output: "rpl"
Explanation: We start with "abc".
After shifting the first 1 letters of s by 3, we have "dbc".
After shifting the first 2 letters of s by 5, we have "igc".
After shifting the first 3 letters of s by 9, we have "rpl", the answer.
```

**Example 2:**

```
Input: s = "aaa", shifts = [1,2,3]
Output: "gfd"
```

 

**Constraints:**

- `1 <= s.length <= 105`
- `s` consists of lowercase English letters.
- `shifts.length == s.length`
- `0 <= shifts[i] <= 10^9`

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
  string shiftingLetters(string s, vector<int>& shifts) {
    int shift = 0;
    for(int i = s.length() - 1; i >= 0; --i) {
      shift += shifts[i];
      shift %= 26;
      s[i] = (s[i] - 'a' + shift) % 26 + 'a';
    }
    return s;
  }
};

// Accepted
// 53/53 cases passed (124 ms)
// Your runtime beats 62.03 % of cpp submissions
// Your memory usage beats 20.29 % of cpp submissions (68.1 MB)
```

``` cpp
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode *newHead = nullptr;
    ListNode *prev;
    ListNode *cur = head;
    while(cur) {
      prev = cur;
      cur = cur->next;
      prev->next = newHead;
      newHead = prev;
    }
    return newHead;
  }
};

// Accepted
// 28/28 cases passed (4 ms)
// Your runtime beats 96.22 % of cpp submissions
// Your memory usage beats 97.51 % of cpp submissions (8.2 MB)
```
