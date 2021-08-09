+++
title = "2021-08-09 Daily-Challenge"
path = "2021-08-09-Daily-Challenge"
date = 2021-08-09 18:39:04+08:00
updated = 2021-08-09 19:16:39+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Minimum Number of Increments on Subarrays to Form a Target Array](https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3875/) with `cpp`.

<!-- more -->

# Minimum Number of Increments on Subarrays to Form a Target Array

## Description

Given an array of positive integers `target` and an array `initial` of same size with all zeros.

Return the minimum number of operations to form a `target` array from `initial` if you are allowed to do the following operation:

- Choose **any** subarray from `initial` and increment each value by one.

The answer is guaranteed to fit within the range of a 32-bit signed integer.

 

**Example 1:**

```
Input: target = [1,2,3,2,1]
Output: 3
Explanation: We need at least 3 operations to form the target array from the initial array.
[0,0,0,0,0] increment 1 from index 0 to 4 (inclusive).
[1,1,1,1,1] increment 1 from index 1 to 3 (inclusive).
[1,2,2,2,1] increment 1 at index 2.
[1,2,3,2,1] target array is formed.
```

**Example 2:**

```
Input: target = [3,1,1,2]
Output: 4
Explanation: (initial)[0,0,0,0] -> [1,1,1,1] -> [1,1,1,2] -> [2,1,1,2] -> [3,1,1,2] (target).
```

**Example 3:**

```
Input: target = [3,1,5,4,2]
Output: 7
Explanation: (initial)[0,0,0,0,0] -> [1,1,1,1,1] -> [2,1,1,1,1] -> [3,1,1,1,1] 
                                  -> [3,1,2,2,2] -> [3,1,3,3,2] -> [3,1,4,4,2] -> [3,1,5,4,2] (target).
```

**Example 4:**

```
Input: target = [1,1,1,1]
Output: 1
```

 

**Constraints:**

- `1 <= target.length <= 10^5`
- `1 <= target[i] <= 10^5`

## Solution

I spent half an hour writing intervals merge and split, then TLE

``` cpp
using pi = pair<int, int>;
class Solution {
public:
  int minNumberOperations(vector<int>& target) {
    target.resize(unique(target.begin(), target.end()) - target.begin());
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int len = target.size();
    for(int i = 0; i < len; i++) {
      pq.push({target[i], i});
    }
    vector<pi> intervals{{0, len - 1}};
    vector<pi> tmp;
    int current = 0;
    int answer = 0;
    while(pq.size() && intervals.size()) {
      auto [val, pos] = pq.top();
      pq.pop();
      if(val != current) {
        for(auto [begin, end] : intervals) {
          answer += (val - current);
        }
        current = val;
      }
      for(auto [begin, end] : intervals) {
        if(begin <= pos && end >= pos) {
          if(begin == pos) {
            tmp.push_back({begin + 1, end});
          } else if(end == pos) {
            tmp.push_back({begin, end - 1});
          } else {
            tmp.push_back({begin, pos - 1});
            tmp.push_back({pos + 1, end});
          }
        } else {
          tmp.push_back({begin, end});
        }
      }
      intervals.clear();
      for(auto [begin, end] : tmp) {
        if(begin == end) {
          answer += target[begin] - current;
        } else {
          intervals.push_back({begin, end});
        }
      }
      tmp.clear();
    }

    return answer;
  }
};

// TLE
```

then I realized...

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int minNumberOperations(vector<int>& target) {
    int prev = 0;
    int answer = 0;
    for(auto num : target) {
      if(num > prev) {
        answer += num - prev;
      }
      prev = num;
    }
    return answer;
  }
};

// Accepted
// 129/129 cases passed (68 ms)
// Your runtime beats 99.77 % of cpp submissions
// Your memory usage beats 58.96 % of cpp submissions (73.1 MB)
```

# August LeetCoding Challenge 9

## Description

**Add Strings**

Given two non-negative integers, `num1` and `num2` represented as string, return *the sum of* `num1` *and* `num2` *as a string*.

You must solve the problem without using any built-in library for handling large integers (such as `BigInteger`). You must also not convert the inputs to integers directly.

 

**Example 1:**

```
Input: num1 = "11", num2 = "123"
Output: "134"
```

**Example 2:**

```
Input: num1 = "456", num2 = "77"
Output: "533"
```

**Example 3:**

```
Input: num1 = "0", num2 = "0"
Output: "0"
```

 

**Constraints:**

- `1 <= num1.length, num2.length <= 104`
- `num1` and `num2` consist of only digits.
- `num1` and `num2` don't have any leading zeros except for the zero itself.

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
  string addStrings(string num1, string num2) {
    string answer;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int len1 = num1.length();
    int len2 = num2.length();
    int carry = 0;
    int pos;
    for(pos = 0; pos < len1 && pos < len2; ++pos) {
      int result = num1[pos] + num2[pos] - '0' * 2 + carry;
      answer.push_back(result % 10 + '0');
      carry = result / 10;
    }
    for(; pos < len1; ++pos) {
      int result = num1[pos] + carry - '0';
      answer.push_back(result % 10 + '0');
      carry = result / 10;
    }
    for(; pos < len2; ++pos) {
      int result = num2[pos] + carry - '0';
      answer.push_back(result % 10 + '0');
      carry = result / 10;
    }
    if(carry) answer.push_back('1');
    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 317/317 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 45.44 % of cpp submissions (6.8 MB)
```
