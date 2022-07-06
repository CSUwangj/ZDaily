+++
updated = 2022-07-03 18:14:00+08:00
title = "2022-07-03 Daily-Challenge"
path = "2022-07-03-Daily-Challenge"
date = 2022-07-03 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/wiggle-subsequence/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 3

## Description

**Wiggle Subsequence**

A **wiggle sequence** is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one  exists) may be either positive or negative. A sequence with one element  and a sequence with two non-equal elements are trivially wiggle  sequences.

- For example, `[1, 7, 4, 9, 2, 5]` is a **wiggle sequence** because the differences `(6, -3, 5, -7, 3)` alternate between positive and negative.
- In contrast, `[1, 4, 7, 2, 5]` and `[1, 7, 4, 5, 5]` are not wiggle sequences. The first is not because its first two  differences are positive, and the second is not because its last  difference is zero.

A **subsequence** is obtained by deleting some elements  (possibly zero) from the original sequence, leaving the remaining  elements in their original order.

Given an integer array `nums`, return *the length of the longest **wiggle subsequence** of* `nums`.

 

**Example 1:**

```
Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).
```

**Example 2:**

```
Input: nums = [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length.
One is [1, 17, 10, 13, 10, 16, 8] with differences (16, -7, 3, -3, 6, -8).
```

**Example 3:**

```
Input: nums = [1,2,3,4,5,6,7,8,9]
Output: 2
```

 

**Constraints:**

- `1 <= nums.length <= 1000`
- `0 <= nums[i] <= 1000`

 

**Follow up:** Could you solve this in `O(n)` time?

## Solution

``` cpp
template <class T>
inline constexpr int sgn(const T &a) {
  return a > 0 ? 1  :
         a < 0 ? -1 :
         0;
}
class Solution {
public:
  int wiggleMaxLength(vector<int>& nums) {
    int len = nums.size();
    if(len < 2) return len;
    
    int pos = 1;
    
    // all same
    while(pos < len && nums[pos] == nums[pos - 1]) pos += 1;
    if(pos == len) return 1;
    
    int answer = 2;
    int sign = sgn(nums[pos] - nums[pos - 1]);
    pos += 1;
    while(pos < len) {
      while(pos < len && sgn(sign + sgn(nums[pos] - nums[pos - 1])) == sign) {
        pos += 1;
      }
      if(pos < len) {
        sign = -sign;
        pos += 1;
        answer += 1;
      }
    }
    
    return answer;
  }
};

// Accepted
// 26/26 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 75.45 % of cpp submissions (7 MB)
```
