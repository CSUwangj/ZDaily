+++
updated = 2022-05-02 18:58:00+08:00
title = "2022-05-02 Daily-Challenge"
path = "2022-05-02-Daily-Challenge"
date = 2022-05-02 18:57:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/sort-array-by-parity/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 2

## Description

**Sort Array By Parity**

Given an integer array `nums`, move all the even integers at the beginning of the array followed by all the odd integers.

Return ***any array** that satisfies this condition*.

 

**Example 1:**

```
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
```

**Example 2:**

```
Input: nums = [0]
Output: [0]
```

 

**Constraints:**

- `1 <= nums.length <= 5000`
- `0 <= nums[i] <= 5000`

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
  vector<int> sortArrayByParity(vector<int>& nums) {
    int oddPos = 0;
    int evenPos = 0;
    int len = nums.size();
    while(oddPos < len) {
      if(nums[oddPos] % 2 == 0) {
        swap(nums[evenPos], nums[oddPos]);
        evenPos += 1;
      }
      oddPos += 1;
    }
    return move(nums);
  }
};

// Accepted
// 285/285 cases passed (12 ms)
// Your runtime beats 66.01 % of cpp submissions
// Your memory usage beats 95.88 % of cpp submissions (16.1 MB)
```
