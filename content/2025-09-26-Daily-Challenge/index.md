+++
updated = 2025-09-26T19:22:51+02:00
title = "2025-09-26 Daily Challenge"
path = "2025-09-26-Daily-Challenge"
date = 2025-09-26T19:22:51+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/valid-triangle-number/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 26

## Description

**Valid Triangle Number**

<p>Given an integer array <code>nums</code>, return <em>the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,2,3,4]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,2,3,4]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


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
  int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    int answer = 0;
    for(int i = 0; i < len - 2; i++) {
      for(int j = i + 1; j < len - 1; j++) {
        int l = nums[j] - nums[i];
        int h = nums[i] + nums[j];
        auto low = upper_bound(nums.begin() + j + 1, nums.end(), l);
        auto high = lower_bound(nums.begin() + j + 1, nums.end(), h);
        high -= 1;
        answer += high >= low ? high - low + 1 : 0;
      }
    }

    return answer;
  }
};

// Accepted
// 241/241 cases passed (294 ms)
// Your runtime beats 11.31 % of cpp submissions
// Your memory usage beats 8.77 % of cpp submissions (17.1 MB)
```
