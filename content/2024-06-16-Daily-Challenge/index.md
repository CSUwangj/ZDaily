+++
updated = 2024-06-16T16:18:30+08:00
title = "2024-06-16 Daily Challenge"
path = "2024-06-16-Daily-Challenge"
date = 2024-06-16T16:18:30+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/patching-array/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 16

## Description

**Patching Array**

<p>Given a sorted integer array <code>nums</code> and an integer <code>n</code>, add/patch elements to the array such that any number in the range <code>[1, n]</code> inclusive can be formed by the sum of some elements in the array.</p>

<p>Return <em>the minimum number of patches required</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3], n = 6
<strong>Output:</strong> 1
Explanation:
Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,5,10], n = 20
<strong>Output:</strong> 2
Explanation: The two patches can be [2, 4].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,2], n = 5
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> is sorted in <strong>ascending order</strong>.</li>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
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
  int minPatches(vector<int>& nums, int n) {
    int count = 0;
    int pos = 0;
    int len = nums.size();
    long long next = 1;
    while(next <= n) {
      if(pos < len && nums[pos] <= next) {
        next += nums[pos];
        pos += 1;
      } else {
        next += next;
        count += 1;
      }
    }
    return count;
  }
};

// Accepted
// 146/146 cases passed (8 ms)
// Your runtime beats 57.18 % of cpp submissions
// Your memory usage beats 48.45 % of cpp submissions (11.4 MB)
```
