+++
title = "2021-09-28 Daily-Challenge"
path = "2021-09-28-Daily-Challenge"
date = 2021-09-28 19:51:03+08:00
updated = 2021-09-28 19:57:28+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3990/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 28

## Description

**Sort Array By Parity II**

Given an array of integers `nums`, half of the integers in `nums` are **odd**, and the other half are **even**.

Sort the array so that whenever `nums[i]` is odd, `i` is **odd**, and whenever `nums[i]` is even, `i` is **even**.

Return *any answer array that satisfies this condition*.

 

**Example 1:**

```
Input: nums = [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
```

**Example 2:**

```
Input: nums = [2,3]
Output: [2,3]
```

 

**Constraints:**

- `2 <= nums.length <= 2 * 104`
- `nums.length` is even.
- Half of the integers in `nums` are even.
- `0 <= nums[i] <= 1000`

 

**Follow Up:** Could you solve it in-place?

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
  vector<int> sortArrayByParityII(vector<int>& nums) {
    int even = 0;
    int odd = 1;
    int len = nums.size();
    while(even < len) {
      while(even < len && ~nums[even] & 1) even += 2;
      while(odd < len && nums[odd] & 1) odd += 2;
      if(even >= len) break;
      swap(nums[odd], nums[even]);
      odd += 2;
      even += 2;
    }
    return nums;
  }
};

// Accepted
// 61/61 cases passed (12 ms)
// Your runtime beats 97.83 % of cpp submissions
// Your memory usage beats 30.87 % of cpp submissions (21.5 MB)
```
