+++
title = "2022-02-04 Daily-Challenge"
path = "2022-02-04-Daily-Challenge"
date = 2022-02-04 20:40:00+08:00
updated = 2022-02-04 20:46:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/contiguous-array/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 4

## Description

**Contiguous Array**

Given a binary array `nums`, return *the maximum length of a contiguous subarray with an equal number of* `0` *and* `1`.

 

**Example 1:**

```
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
```

**Example 2:**

```
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.


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
  int findMaxLength(vector<int>& nums) {
    int len = nums.size();
    int pos[2 * len + 1];
    memset(pos, -1, sizeof(pos));
    pos[len] = 0;
    
    int all = 0;
    int one = 0;
    int answer = 0;
    for(auto n : nums) {
      if(n) {
        one += 1;
      } else {
        one -= 1;
      }
      all += 1;
      if(pos[one + len] != -1) {
        answer = max(answer, all - pos[one + len]);
      } else {
        pos[one + len] = all;
      }
    }
    return answer;
  }
};

// Accepted
// 564/564 cases passed (100 ms)
// Your runtime beats 97.6 % of cpp submissions
// Your memory usage beats 99.64 % of cpp submissions (79.9 MB)
```
