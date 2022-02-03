+++
title = "2022-02-03 Daily-Challenge"
path = "2022-02-03-Daily-Challenge"
date = 2022-02-03 21:40:00+08:00
updated = 2022-02-03 21:49:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/4sum-ii/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 3

## Description

**4Sum II**

Given four integer arrays `nums1`, `nums2`, `nums3`, and `nums4` all of length `n`, return the number of tuples `(i, j, k, l)` such that:

- `0 <= i, j, k, l < n`
- `nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0`

 

**Example 1:**

```
Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
```

**Example 2:**

```
Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
Output: 1
```

 

**Constraints:**

- `n == nums1.length`
- `n == nums2.length`
- `n == nums3.length`
- `n == nums4.length`
- `1 <= n <= 200`
- <code>-2<sup>28</sup> &lt;= nums1[i], nums2[i], nums3[i], nums4[i] &lt;= 2<sup>28</sup></code>

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
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    map<int, int> sum;
    for(auto n1 : nums1) {
      for(auto n2 : nums2) {
        sum[n1 + n2] += 1;
      }
    }
    int answer = 0;
    for(auto n3 : nums3) {
      for(auto n4 : nums4) {
        if(sum.count(-n3 - n4)) answer += sum[-n3 - n4];
      } 
    }
    return answer;
  }
};

// Accepted
// 132/132 cases passed (408 ms)
// Your runtime beats 27.73 % of cpp submissions
// Your memory usage beats 29.68 % of cpp submissions (24.7 MB)
```
