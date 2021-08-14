+++
title = "2021-08-14 Daily-Challenge"
path = "2021-08-14-Daily-Challenge"
date = 2021-08-14 16:31:03+08:00
updated = 2021-08-14 23:30:24+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3889/) with `cpp`.

<!-- more -->

# LeetCode Review

## Delete Leaves With a Given Value

too easy to review

## Minimum Number of Increments on Subarrays to Form a Target Array

too easy to review

## Minimum Falling Path Sum II

too easy to review

## Largest Time for Given Digits

too easy to review

## Set Matrix Zeroes

too easy to review

## Group Anagrams

too easy to review

## Array of Doubled Pairs

too easy to review

## Flip String to Monotone Increasing

too easy to review

## Add Strings

too easy to review

# August LeetCoding Challenge 14

## Description

**Remove Boxes**

You are given several `boxes` with different colors represented by different positive numbers.

You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of `k` boxes, `k >= 1`), remove them and get `k * k` points.

Return *the maximum points you can get*.

 

**Example 1:**

```
Input: boxes = [1,3,2,2,2,3,4,3,1]
Output: 23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)
```

**Example 2:**

```
Input: boxes = [1,1,1]
Output: 9
```

**Example 3:**

```
Input: boxes = [1]
Output: 1
```

 

**Constraints:**

- `1 <= boxes.length <= 100`
- `1 <= boxes[i] <= 100`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct Boxes {
  uint8_t color;
  uint8_t count;
};
const int N = 100;
uint16_t dp[N * N * N];
Boxes boxes[N];

class Solution {
  int n;
  uint16_t solve(uint8_t begin, uint8_t end, uint8_t cnt) {
    auto cache = dp + cnt * n * n + begin * n + end;
    if(*cache) return *cache;
    auto color = boxes[begin].color;
    if((end - begin) > 1 && boxes[end - 1].color == color) {
      cnt += boxes[end - 1].count;
      end -= 1;
    }
    cnt += boxes[begin].count;
    begin += 1;
    auto score = cnt * cnt;
    if(begin != end) {
      score += solve(begin, end, 0);
      for(auto mid = begin + 1; mid < end - 1; ++mid) {
        if(boxes[mid].color == color) {
          auto scoreRemove = solve(begin, mid, 0);
          auto scoreJoin = solve(mid, end, cnt);
          if(scoreRemove + scoreJoin > score) {
            score = scoreRemove + scoreJoin;
          }
        }
      }
    }
    // cout << int(begin) << ' ' << int(end) << ' ' << int(cnt) << ' ';
    // cout << score << endl;
    *cache = score;
    return score;
  }
public:
  int removeBoxes(vector<int>& boxesVec) {
    uint8_t pos = 0;
    uint8_t color = boxesVec.front();
    uint8_t count = 0;
    for(auto i : boxesVec) {
      if(i == color) {
        count += 1;
      } else {
        boxes[pos].count = count;
        boxes[pos].color = color;
        pos += 1;
        color = i;
        count = 1;
      }
    }
    boxes[pos].count = count;
    boxes[pos].color = color;
    n = pos + 1;
    if(n == 1) return boxes[0].count * boxes[0].count;
    memset(dp, 0, sizeof(uint16_t) * n * n * n);
    return solve(0, n, 0);
  }
};

// Accepted
// 62/62 cases passed (12 ms)
// Your runtime beats 96.3 % of cpp submissions
// Your memory usage beats 97.13 % of cpp submissions (9.7 MB)
```