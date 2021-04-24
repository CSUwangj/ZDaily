+++
title = "2020-11-21 Daily-Challenge"
path = "2020-11-21-Daily-Challenge"
date = 2020-11-21 18:49:22+08:00
updated = 2020-11-21 23:58:05+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3538/) with `cpp`.

<!-- more -->

# LeetCode Review

## Mirror Reflection

expand mirrors both axises

``` cpp
class Solution {
    int gcd(int a, int b) {
        while(b) {
            int c = a;
            a = b;
            b = c % a;
        }
        return a;
    }
public:
    int mirrorReflection(int p, int q) {
        int metY = p*q/gcd(p, q);
        int metX = metY / q * p;
        int roundX = metX / p;
        int roundY = metY / p;
        
        if((roundY & roundX & 1) == 1) return 1;
        if((roundY & 1 == 1)) return 2;
        return 0;
    }
};
```

## Alert Using Same Key-Card Three or More Times in a One Hour Period

nothing to say

``` cpp
class Solution {
    int parseTime(string &time) {
        return (time[0]-'0')*1000 + (time[1]-'0')*100 + (time[3]-'0')*10 + (time[4]-'0');
    }
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, vector<int>> m;
        int len = keyName.size();
        for(int i = 0; i < len; ++i) {
            // if(!m.count(keyName[i])) m[keyName[i]] = vector<int>();
            m[keyName[i]].push_back(parseTime(keyTime[i]));
        }
        vector<string> answer;
        for(auto &[name, times] : m) {
            sort(times.begin(), times.end());
            queue<int> q;
            for(auto time : times) {
                while(q.size() && q.front()+100 < time) q.pop();
                q.push(time);
                if(q.size() > 2) break;
            }
            if(q.size() > 2) answer.push_back(name);
        }
        return answer;
    }
};
```

## Longest Mountain in Array

``` cpp
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int len = arr.size();
        int answer = 0;
        for(int i = 1; i < len; ++i) {
            if(arr[i] > arr[i-1]) {
                int begin = i;
                while(i < len && arr[i] > arr[i-1]) i += 1;
                if(i == len || arr[i] == arr[i-1]) begin = i+1;
                while(i < len && arr[i] < arr[i-1]) i += 1;
                answer = max(answer, i-begin+1);
                i-=1;
            }
        }
        return answer;
    }
};
```

## Trapping Rain Water

dp

``` cpp
class Solution {
    vector<int> left;
    vector<int> right;
public:
    int trap(vector<int>& height) {
        int len = height.size();
        left.resize(len);
        right.resize(len);
        int maxLeft = 0;
        for(int i = 0; i < len; ++i) {
            left[i] = maxLeft;
            maxLeft = max(maxLeft, height[i]);
        }
        int maxRight = 0;
        for(int i = len-1; i >=0; --i) {
            right[i] = maxRight;
            maxRight = max(maxRight, height[i]);
        }
        int answer = 0;
        for(int i = 0; i < len; ++i) {
            answer += max(0, min(left[i], right[i]) - height[i]);
        }
        return answer;
    }
};
```

# November LeetCoding Challenge21

## Description

**Numbers At Most N Given Digit Set**

Given an array of `digits`, you can write numbers using each `digits[i]` as many times as we want. For example, if `digits = ['1','3','5']`, we may write numbers such as `'13'`, `'551'`, and `'1351315'`.

Return *the number of positive integers that can be generated* that are less than or equal to a given integer `n`.

**Example 1:**

```
Input: digits = ["1","3","5","7"], n = 100
Output: 20
Explanation: 
The 20 numbers that can be written are:
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
```

**Example 2:**

```
Input: digits = ["1","4","9"], n = 1000000000
Output: 29523
Explanation: 
We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
In total, this is 29523 integers that can be written using the digits array.
```

**Example 3:**

```
Input: digits = ["7"], n = 8
Output: 1
```

**Constraints:**

- `1 <= digits.length <= 9`
- `digits[i].length == 1`
- `digits[i]` is a digit from `'1'` to `'9'`.
- All the values in `digits` are **unique**.
- `1 <= n <= 109`

## Solution

digit dynamic programming

consider `DP[i]` means that the amount of i-digit-number we can get by using these digits, then it's obviously that `DP[i] = DP[i-1]*len(digits)`.

consider `DP2[i]` means that the amount of i-digit-number which is less or equal than the number where least significant digits stands. For example,
we have `digits` of \[1, 2, 3\], `n` of 22, then `DP2[2]` is 5(11, 12, 13, 21, 22). And we have a precomputed table `prefix` where `prefix[i]` means
that how many digits are less or equal than `i`. Then we have `DP2[i] = prefix[corresponding digit - 1]*DP[i] + (digits.find(corresponding digit) ? DP2[i-1] : 0)`.

``` cpp
class Solution {
  uint dp[12] = {0};
  uint dp2[12] = {0};
  uint prefix[10] = {0};
  vector<int> digit;
public:
  int atMostNGivenDigitSet(vector<string>& digits, int n) {
    int len = to_string(n).size();
    for(auto &d : digits) {
      digit.push_back(d[0] - '0');
    }
    sort(digit.begin(), digit.end());
    int curIndex = 0;
    for(int i = 1; i < 10; ++i) {
      if(curIndex < digit.size() && i >= digit[curIndex]) {
        prefix[i] = prefix[i-1] + 1;
        curIndex += 1;
      } else {
        prefix[i] = prefix[i-1];
      }
    }
    dp[0] = 1;
    for(int i = 1; i < len; ++i) {
      dp[i] = dp[i-1] * digit.size();
    }
    int curNum = n;
    dp2[0] = 1;
    for(int i = 1; i <= len; ++i) {
      int curDigit = curNum % 10;
      curNum /= 10;
      if(curDigit == 0) dp2[i] = 0;
      else {
        dp2[i] = prefix[curDigit-1] * dp[i-1];
        if(find(digit.begin(), digit.end(), curDigit) != digit.end()){
          dp2[i] += dp2[i-1];
        }
      }
    }
    int answer = dp2[len];
    for(int i = 1; i < len; ++i) {
      answer += dp[i];
    }
    return answer;
  }
};
```
