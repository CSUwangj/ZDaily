+++
updated = 2023-08-02T16:56:02+08:00
title = "2023-08-02 Daily Challenge"
path = "2023-08-02-Daily-Challenge"
date = 2023-08-02T16:56:02+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/permutations/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 2

## Description

**Permutations**

<p>Given an array <code>nums</code> of distinct integers, return <em>all the possible permutations</em>. You can return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [0,1]
<strong>Output:</strong> [[0,1],[1,0]]
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> [[1]]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 6</code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
	<li>All the integers of <code>nums</code> are <strong>unique</strong>.</li>
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
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> answer;
    sort(nums.begin(), nums.end());
    do {
      answer.push_back(nums);
    } while(next_permutation(nums.begin(), nums.end()));
    return answer;
  }
};

// Accepted
// 26/26 cases passed (4 ms)
// Your runtime beats 70.64 % of cpp submissions
// Your memory usage beats 78.16 % of cpp submissions (7.6 MB)
```
