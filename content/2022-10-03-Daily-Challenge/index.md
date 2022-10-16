+++
updated = 2022-10-03 18:14:00+08:00
title = "2022-10-03 Daily-Challenge"
path = "2022-10-03-Daily-Challenge"
date = 2022-10-03 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/minimum-time-to-make-rope-colorful/submissions/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 3

## Description

**Minimum Time to Make Rope Colorful**

Alice has `n` balloons arranged on a rope. You are given a **0-indexed** string `colors` where `colors[i]` is the color of the `ith` balloon.

Alice wants the rope to be **colorful**. She does not want **two consecutive balloons** to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it **colorful**. You are given a **0-indexed** integer array `neededTime` where `neededTime[i]` is the time (in seconds) that Bob needs to remove the `ith` balloon from the rope.

Return *the **minimum time** Bob needs to make the rope **colorful***.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/12/13/ballon1.jpg)

```
Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/12/13/balloon2.jpg)

```
Input: colors = "abc", neededTime = [1,2,3]
Output: 0
Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2021/12/13/balloon3.jpg)

```
Input: colors = "aabaa", neededTime = [1,2,3,4,1]
Output: 2
Explanation: Bob will remove the ballons at indices 0 and 4. Each ballon takes 1 second to remove.
There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.
```

 

**Constraints:**

- `n == colors.length == neededTime.length`
- `1 <= n <= 10^5`
- `1 <= neededTime[i] <= 10^4`
- `colors` contains only lowercase English letters.

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
  int minCost(string colors, vector<int>& neededTime) {
    char current = -1;
    int curSum = 0;
    int curMax = 0;
    int answer = 0;
    for(int i = 0; i < colors.length(); ++i) {
      if(colors[i] != current) {
        answer += curSum - curMax;
        current = colors[i];
        curSum = neededTime[i];
        curMax = neededTime[i];
      } else {
        curSum += neededTime[i];
        curMax = max(curMax, neededTime[i]);
      }
    }
    answer += curSum - curMax;
    return answer;
  }
};

// Accepted
// 113/113 cases passed (214 ms)
// Your runtime beats 71.93 % of cpp submissions
// Your memory usage beats 18.68 % of cpp submissions (95.8 MB)
```
