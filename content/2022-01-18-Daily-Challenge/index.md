+++
title = "2022-01-18 Daily-Challenge"
path = "2022-01-18-Daily-Challenge"
date = 2022-01-18 18:10:00+08:00
updated = 2022-01-18 18:18:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/can-place-flowers/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 18

## Description

**Can Place Flowers**

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in **adjacent** plots.

Given an integer array `flowerbed` containing `0`'s and `1`'s, where `0` means empty and `1` means not empty, and an integer `n`, return *if* `n` new flowers can be planted in the `flowerbed` without violating the no-adjacent-flowers rule.

 

**Example 1:**

```
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
```

**Example 2:**

```
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
```

 

**Constraints:**

- `1 <= flowerbed.length <= 2 * 10^4`
- `flowerbed[i]` is `0` or `1`.
- There are no two adjacent flowers in `flowerbed`.
- `0 <= n <= flowerbed.length`

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
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    int flowers = 0;
    for(auto flowered : flowerbed) {
      if(flowered) {
        flowers += count / 2;
        count = -1;
      } else {
        count += 1;
      }
    }
    flowers += (count + 1) / 2;
    return flowers >= n;
  }
};

// Accepted
// 124/124 cases passed (24 ms)
// Your runtime beats 31.1 % of cpp submissions
// Your memory usage beats 69.55 % of cpp submissions (20.3 MB)
```
