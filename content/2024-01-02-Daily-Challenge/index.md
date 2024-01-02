+++
updated = 2024-01-02T14:05:16+08:00
title = "2024-01-02 Daily Challenge"
path = "2024-01-02-Daily-Challenge"
date = 2024-01-02T14:05:16+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 2

## Description

**Convert an Array Into a 2D Array With Conditions**

<p>You are given an integer array <code>nums</code>. You need to create a 2D array from <code>nums</code> satisfying the following conditions:</p>

<ul>
	<li>The 2D array should contain <strong>only</strong> the elements of the array <code>nums</code>.</li>
	<li>Each row in the 2D array contains <strong>distinct</strong> integers.</li>
	<li>The number of rows in the 2D array should be <strong>minimal</strong>.</li>
</ul>

<p>Return <em>the resulting array</em>. If there are multiple answers, return any of them.</p>

<p><strong>Note</strong> that the 2D array can have a different number of elements on each row.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,4,1,2,3,1]
<strong>Output:</strong> [[1,3,4,2],[1,3],[1]]
<strong>Explanation:</strong> We can create a 2D array that contains the following rows:
- 1,3,4,2
- 1,3
- 1
All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
It can be shown that we cannot have less than 3 rows in a valid array.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> [[4,3,2,1]]
<strong>Explanation:</strong> All elements of the array are distinct, so we can keep all of them in the first row of the 2D array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>1 &lt;= nums[i] &lt;= nums.length</code></li>
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
  vector<vector<int>> findMatrix(vector<int>& nums) {
    map<int, int> count;
    int sz = 0;
    for(auto n : nums) {
      count[n] += 1;
      sz = max(sz, count[n]);
    }
    vector<vector<int>> answer(sz);
    for(const auto &[n, c] : count) {
      for(int i = 0; i < c; ++i) {
        answer[i].push_back(n);
      }
    }
    return answer;
  }
};

// Accepted
// 1035/1035 cases passed (29 ms)
// Your runtime beats 5.35 % of cpp submissions
// Your memory usage beats 70.96 % of cpp submissions (29.9 MB)
```
