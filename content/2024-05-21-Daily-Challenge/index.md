+++
updated = 2024-05-21T13:44:41+08:00
title = "2024-05-21 Daily Challenge"
path = "2024-05-21-Daily-Challenge"
date = 2024-05-21T13:44:41+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/subsets/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 21

## Description

**Subsets**

<p>Given an integer array <code>nums</code> of <strong>unique</strong> elements, return <em>all possible</em> <span data-keyword="subset"><em>subsets</em></span> <em>(the power set)</em>.</p>

<p>The solution set <strong>must not</strong> contain duplicate subsets. Return the solution in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [0]
<strong>Output:</strong> [[],[0]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10</code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
	<li>All the numbers of&nbsp;<code>nums</code> are <strong>unique</strong>.</li>
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
  vector<vector<int>> subsets(vector<int>& nums) {
    int len = nums.size();
    int sz = (1 << len);
    vector<vector<int>> answer;
    for(int i = 0; i < sz; ++i) {
      vector<int> st;
      for(int b = 0; b < len; ++b) {
        if(i & (1 << b)) st.push_back(nums[b]);
      }
      answer.emplace_back(move(st));
    }
    return answer;
  }
};

// Accepted
// 10/10 cases passed (7 ms)
// Your runtime beats 26.93 % of cpp submissions
// Your memory usage beats 85.44 % of cpp submissions (7.1 MB)
```
