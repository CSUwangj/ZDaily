+++
title = "2022-02-28 Daily-Challenge"
path = "2022-02-28-Daily-Challenge"
date = 2022-02-28 18:16:00+08:00
updated = 2022-02-28 18:21:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/summary-ranges/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 28

## Description

**Summary Ranges**

You are given a **sorted unique** integer array `nums`.

Return *the **smallest sorted** list of ranges that **cover all the numbers in the array exactly***. That is, each element of `nums` is covered by exactly one of the ranges, and there is no integer `x` such that `x` is in one of the ranges but not in `nums`.

Each range `[a,b]` in the list should be output as:

- `"a->b"` if `a != b`
- `"a"` if `a == b`

 

**Example 1:**

```
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
```

**Example 2:**

```
Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
```

 

**Constraints:**

<ul>
	<li><code>0 &lt;= nums.length &lt;= 20</code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li>All the values of <code>nums</code> are <strong>unique</strong>.</li>
	<li><code>nums</code> is sorted in ascending order.</li>
</ul>

## Solution

``` cpp
class Solution {
  string toRange(int begin, int end) {
    if(begin == end) return to_string(begin);
    return to_string(begin) + "->" + to_string(end);
  }
public:
  vector<string> summaryRanges(vector<int>& nums) {
    if(nums.empty()) return {};
    vector<string> answer;
    int begin = nums.front();
    int end = nums.front();
    for(auto n : nums) {
      if(n > min(end, INT_MAX - 1) + 1) {
        answer.push_back(toRange(begin, end));
        begin = end = n;
      } else {
        end = n;
      }
    }
    answer.push_back(toRange(begin, end));
    return answer;
  }
};

// Accepted
// 28/28 cases passed (5 ms)
// Your runtime beats 13.39 % of cpp submissions
// Your memory usage beats 62.02 % of cpp submissions (6.8 MB)
```
