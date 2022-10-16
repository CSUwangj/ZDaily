+++
title = "2021-12-06 Daily-Challenge"
path = "2021-12-06-Daily-Challenge"
date = 2021-12-06 20:49:00+08:00
updated = 2021-12-06 20:50:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 6

## Description

**Minimum Cost to Move Chips to The Same Position**

We have `n` chips, where the position of the `ith` chip is `position[i]`.

We need to move all the chips to **the same position**. In one step, we can change the position of the `ith` chip from `position[i]` to:

- `position[i] + 2` or `position[i] - 2` with `cost = 0`.
- `position[i] + 1` or `position[i] - 1` with `cost = 1`.

Return *the minimum cost* needed to move all the chips to the same position.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/08/15/chips_e1.jpg)

```
Input: position = [1,2,3]
Output: 1
Explanation: First step: Move the chip at position 3 to position 1 with cost = 0.
Second step: Move the chip at position 2 to position 1 with cost = 1.
Total cost is 1.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/08/15/chip_e2.jpg)

```
Input: position = [2,2,2,3,3]
Output: 2
Explanation: We can move the two chips at position  3 to position 2. Each move has cost = 1. The total cost = 2.
```

**Example 3:**

```
Input: position = [1,1000000000]
Output: 1
```

 

**Constraints:**

- `1 <= position.length <= 100`
- `1 <= position[i] <= 10^9`

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
  int minCostToMoveChips(vector<int>& position) {
    int parity[2] = {0};
    for(auto p : position) {
      parity[p&1] += 1;
    }
    return parity[0] < parity[1] ? parity[0] : parity[1];
  }
};

// Accepted
// 51/51 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 53.85 % of cpp submissions (7.3 MB)
```
