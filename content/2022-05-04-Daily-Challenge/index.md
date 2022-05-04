+++
updated = 2022-05-04 18:58:00+08:00
title = "2022-05-04 Daily-Challenge"
path = "2022-05-04-Daily-Challenge"
date = 2022-05-04 18:57:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/max-number-of-k-sum-pairs/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 4

## Description

**Max Number of K-Sum Pairs**

You are given an integer array `nums` and an integer `k`.

In one operation, you can pick two numbers from the array whose sum equals `k` and remove them from the array.

Return *the maximum number of operations you can perform on the array*.

 

**Example 1:**

```
Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
```

**Example 2:**

```
Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `1 <= k <= 10^9`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  unordered_map<int, int> count;
public:
  int maxOperations(vector<int>& nums, int k) {
    for(auto i : nums) count[i] += 1;
    int answer = 0;
    for(auto [num, cnt] : count) {
      if(!count.count(k-num)) continue;
      answer += min(cnt, count[k-num]);
    }
    answer /= 2;
    return answer;
  }
};

// Accepted
// 51/51 cases passed (149 ms)
// Your runtime beats 82.22 % of cpp submissions
// Your memory usage beats 31.86 % of cpp submissions (68.4 MB)
```
