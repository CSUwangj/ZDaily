+++
updated = 2023-09-28T09:55:48+08:00
title = "2023-09-28 Daily Challenge"
path = "2023-09-28-Daily-Challenge"
date = 2023-09-28T09:55:48+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/sort-array-by-parity/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 28

## Description

**Sort Array By Parity**

<p>Given an integer array <code>nums</code>, move all the even integers at the beginning of the array followed by all the odd integers.</p>

<p>Return <em><strong>any array</strong> that satisfies this condition</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,1,2,4]
<strong>Output:</strong> [2,4,3,1]
<strong>Explanation:</strong> The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [0]
<strong>Output:</strong> [0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 5000</code></li>
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
// 285/285 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 46.32 % of cpp submissions (16.3 MB)
```
