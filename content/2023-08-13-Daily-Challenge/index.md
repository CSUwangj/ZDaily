+++
updated = 2023-08-13T15:22:10+08:00
title = "2023-08-13 Daily Challenge"
path = "2023-08-13-Daily-Challenge"
date = 2023-08-13T15:22:10+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 13

## Description

**Check if There is a Valid Partition For The Array**

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>. You have to partition the array into one or more <strong>contiguous</strong> subarrays.</p>

<p>We call a partition of the array <strong>valid</strong> if each of the obtained subarrays satisfies <strong>one</strong> of the following conditions:</p>

<ol>
	<li>The subarray consists of <strong>exactly</strong> <code>2</code> equal elements. For example, the subarray <code>[2,2]</code> is good.</li>
	<li>The subarray consists of <strong>exactly</strong> <code>3</code> equal elements. For example, the subarray <code>[4,4,4]</code> is good.</li>
	<li>The subarray consists of <strong>exactly</strong> <code>3</code> consecutive increasing elements, that is, the difference between adjacent elements is <code>1</code>. For example, the subarray <code>[3,4,5]</code> is good, but the subarray <code>[1,3,5]</code> is not.</li>
</ol>

<p>Return <code>true</code><em> if the array has <strong>at least</strong> one valid partition</em>. Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,4,4,5,6]
<strong>Output:</strong> true
<strong>Explanation:</strong> The array can be partitioned into the subarrays [4,4] and [4,5,6].
This partition is valid, so we return true.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,1,2]
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no valid partition for this array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
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
  bool validPartition(vector<int>& nums) {
    int len = nums.size();
    vector<bool> valid(len + 1);
    valid[0] = true;
    if(nums[0] == nums[1]) valid[2] = true;

    for(int i = 3; i <= len; ++i) {
      if(valid[i - 2] && nums[i - 2] == nums[i - 1]) {
        valid[i] = true;
      }
      if(valid[i - 3] && ((nums[i - 3] == nums[i - 2] && nums[i - 3] == nums[i - 1]) ||
                          (nums[i - 3] + 1 == nums[i - 2] && nums[i - 2] + 1 == nums[i - 1]))) {
        valid[i] = true;
      }
    }

    return valid.back();
  }
};

// Accepted
// 117/117 cases passed (65 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 92.92 % of cpp submissions (83.9 MB)
```
