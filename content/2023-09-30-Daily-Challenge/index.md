+++
updated = 2023-09-30T08:46:28+08:00
title = "2023-09-30 Daily Challenge"
path = "2023-09-30-Daily-Challenge"
date = 2023-09-30T08:46:28+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/132-pattern/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 30

## Description

**132 Pattern**

<p>Given an array of <code>n</code> integers <code>nums</code>, a <strong>132 pattern</strong> is a subsequence of three integers <code>nums[i]</code>, <code>nums[j]</code> and <code>nums[k]</code> such that <code>i &lt; j &lt; k</code> and <code>nums[i] &lt; nums[k] &lt; nums[j]</code>.</p>

<p>Return <code>true</code><em> if there is a <strong>132 pattern</strong> in </em><code>nums</code><em>, otherwise, return </em><code>false</code><em>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no 132 pattern in the sequence.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,1,4,2]
<strong>Output:</strong> true
<strong>Explanation:</strong> There is a 132 pattern in the sequence: [1, 4, 2].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1,3,2,0]
<strong>Output:</strong> true
<strong>Explanation:</strong> There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
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
  bool find132pattern(vector<int>& nums) {
    if(nums.size() < 3) return false;
    stack<int> three;
    int two = INT_MIN;
    three.push(nums.back());
    for(int i = nums.size()-1; i >=0 ; --i) {
      if(nums[i] < two) return true;
      while(three.size() && three.top() < nums[i]) {
        two = three.top();
        three.pop();
      }
      three.push(nums[i]);
    }
    return false;
  }
};

// Accepted
// 103/103 cases passed (49 ms)
// Your runtime beats 98.35 % of cpp submissions
// Your memory usage beats 85.68 % of cpp submissions (48 MB)
```
