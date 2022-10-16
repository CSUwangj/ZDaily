+++
title = "2022-01-02 Daily-Challenge"
path = "2022-01-02-Daily-Challenge"
date = 2022-01-02 18:01:00+08:00
updated = 2022-01-02 18:03:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 2

## Description

**Pairs of Songs With Total Durations Divisible by 60**

You are given a list of songs where the ith song has a duration of `time[i]` seconds.

Return *the number of pairs of songs for which their total duration in seconds is divisible by* `60`. Formally, we want the number of indices `i`, `j` such that `i < j` with `(time[i] + time[j]) % 60 == 0`.

 

**Example 1:**

```
Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
```

**Example 2:**

```
Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.
```

 

**Constraints:**

- `1 <= time.length <= 6 * 10^4`
- `1 <= time[i] <= 500`

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
  int numPairsDivisibleBy60(vector<int>& time) {
    int times[60] = {};
    int answer = 0;
    for(auto t : time) {
      t %= 60;
      answer += times[(60 - t) % 60];
      times[t] += 1;
    }
    return answer;
  }
};

// Accepted
// 34/34 cases passed (16 ms)
// Your runtime beats 99.59 % of cpp submissions
// Your memory usage beats 60.38 % of cpp submissions (23.1 MB)
```
