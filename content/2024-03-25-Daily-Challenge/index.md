+++
updated = 2024-03-25T15:10:36+08:00
title = "2024-03-25 Daily Challenge"
path = "2024-03-25-Daily-Challenge"
date = 2024-03-25T15:10:36+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/find-all-duplicates-in-an-array/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 25

## Description

**Find All Duplicates in an Array**

<p>Given an integer array <code>nums</code> of length <code>n</code> where all the integers of <code>nums</code> are in the range <code>[1, n]</code> and each integer appears <strong>once</strong> or <strong>twice</strong>, return <em>an array of all the integers that appears <strong>twice</strong></em>.</p>

<p>You must write an algorithm that runs in&nbsp;<code>O(n)&nbsp;</code>time and uses only constant extra space.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [4,3,2,7,8,2,3,1]
<strong>Output:</strong> [2,3]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,2]
<strong>Output:</strong> [1]
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> []
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= n</code></li>
	<li>Each element in <code>nums</code> appears <strong>once</strong> or <strong>twice</strong>.</li>
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
  vector<int> findDuplicates(vector<int>& nums) {
    int len = nums.size();
    vector<int> answer;
    for(int i = 0; i < len; ++i) {
      int pos = nums[i] > 0 ? nums[i] - 1 : -1 - nums[i];
      cout << pos << endl;
      if(nums[pos] > 0) {
        nums[pos] = -nums[pos]; 
      } else {
        answer.push_back(pos + 1);
      }
    }
    return answer;
  }
};

// Accepted
// 28/28 cases passed (60 ms)
// Your runtime beats 53.68 % of cpp submissions
// Your memory usage beats 74.16 % of cpp submissions (33.5 MB)
```
