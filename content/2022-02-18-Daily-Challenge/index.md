+++
title = "2022-02-18 Daily-Challenge"
path = "2022-02-18-Daily-Challenge"
date = 2022-02-18 19:25:00+08:00
updated = 2022-02-18 19:30:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/combination-sum/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 18

## Description

**Remove K Digits**

Given string num representing a non-negative integer `num`, and an integer `k`, return *the smallest possible integer after removing* `k` *digits from* `num`.

 

**Example 1:**

```
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
```

**Example 2:**

```
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
```

**Example 3:**

```
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
```

 

**Constraints:**

- `1 <= k <= num.length <= 10^5`
- `num` consists of only digits.
- `num` does not have any leading zeros except for the zero itself.

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
  string removeKdigits(string num, int k) {
    string monoStack;
    int pos = 0;
    int len = num.length();
    while(pos < len) {
      while(k && monoStack.size() && monoStack.back() > num[pos]) {
        monoStack.pop_back();
        k -= 1;
      }
      if(num[pos] != '0' || monoStack.size()) monoStack.push_back(num[pos]);
      pos += 1;
    }
    while(k && monoStack.size()) {
      monoStack.pop_back();
      k -= 1;
    }
    if(monoStack.size()) return monoStack;
    return "0";
  }
};

// Accepted
// 40/40 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 88 % of cpp submissions (6.9 MB)
```
