+++
updated = 2022-09-20 18:14:00+08:00
title = "2022-09-20 Daily-Challenge"
path = "2022-09-20-Daily-Challenge"
date = 2022-09-20 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/maximum-length-of-repeated-subarray//) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 20

## Description

**Maximum Length of Repeated Subarray**

Given two integer arrays `nums1` and `nums2`, return *the maximum length of a subarray that appears in **both** arrays*.

 

**Example 1:**

```
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
```

**Example 2:**

```
Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
```

 

**Constraints:**

- `1 <= nums1.length, nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 100`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int dp[1001];
class Solution {
public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    // cout << "$$$$$$$$$$$$"<<endl;
    int len1 = nums1.size();
    int len2 = nums2.size();
    int answer = 0;
    memset(dp, 0, sizeof(dp[0]) * (len1 + 1));
    for(int i = len1 - 1; i >= 0; --i) {
      for(int j = 0; j < len2; ++j) {
        if(nums1[i] == nums2[j]) {
          dp[j] = dp[j + 1] + 1;
          answer = max(answer, dp[j]);
        } else {
          dp[j] = 0;
        }
        // cout << dp[j] <<  ' ';
      }
      // cout << endl;
    }
    return answer;
  }
};

// Accepted
// 57/57 cases passed (292 ms)
// Your runtime beats 85.19 % of cpp submissions
// Your memory usage beats 95.52 % of cpp submissions (11.8 MB)
```
