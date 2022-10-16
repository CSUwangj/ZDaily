+++
title = "2021-09-05 Daily-Challenge"
path = "2021-09-05-Daily-Challenge"
date = 2021-09-05 15:13:33+08:00
updated = 2021-09-05 15:49:52+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3964/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 5

## Description

**Orderly Queue**

You are given a string `s` and an integer `k`. You can choose one of the first `k` letters of `s` and append it at the end of the string..

Return *the lexicographically smallest string you could have after applying the mentioned step any number of moves*.

 

**Example 1:**

```
Input: s = "cba", k = 1
Output: "acb"
Explanation: 
In the first move, we move the 1st character 'c' to the end, obtaining the string "bac".
In the second move, we move the 1st character 'b' to the end, obtaining the final result "acb".
```

**Example 2:**

```
Input: s = "baaca", k = 3
Output: "aaabc"
Explanation: 
In the first move, we move the 1st character 'b' to the end, obtaining the string "aacab".
In the second move, we move the 3rd character 'c' to the end, obtaining the final result "aaabc".
```

 

**Constraints:**

- `1 <= k <= s.length <= 1000`
- `s` consist of lowercase English letters.

## Solution

I tested `"abacadaeaf", 2` and found that answer will be `"aaaaabcdef"`, so it's obviously equivalent `sort()` except `k = 1`.

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  string orderlyQueue(string s, int k) {
    if(k > 1) {
      sort(s.begin(), s.end());
      return s;
    }
    string answer = s;
    int len = s.length();
    for(int i = 1; i < len; ++i) {
      answer = min(answer, s.substr(i) + s.substr(0, i));
    }
    return answer;
  }
};

// Accepted
// 106/106 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 25.51 % of cpp submissions (10.9 MB)
```