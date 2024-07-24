+++
updated = 2024-07-25T00:22:26+08:00
title = "2024-07-24 Daily Challenge"
path = "2024-07-24-Daily-Challenge"
date = 2024-07-25T00:22:26+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/sort-the-jumbled-numbers/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 24

## Description

**Sort the Jumbled Numbers**

<p>You are given a <strong>0-indexed</strong> integer array <code>mapping</code> which represents the mapping rule of a shuffled decimal system. <code>mapping[i] = j</code> means digit <code>i</code> should be mapped to digit <code>j</code> in this system.</p>

<p>The <strong>mapped value</strong> of an integer is the new integer obtained by replacing each occurrence of digit <code>i</code> in the integer with <code>mapping[i]</code> for all <code>0 &lt;= i &lt;= 9</code>.</p>

<p>You are also given another integer array <code>nums</code>. Return <em>the array </em><code>nums</code><em> sorted in <strong>non-decreasing</strong> order based on the <strong>mapped values</strong> of its elements.</em></p>

<p><strong>Notes:</strong></p>

<ul>
	<li>Elements with the same mapped values should appear in the <strong>same relative order</strong> as in the input.</li>
	<li>The elements of <code>nums</code> should only be sorted based on their mapped values and <strong>not be replaced</strong> by them.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
<strong>Output:</strong> [338,38,991]
<strong>Explanation:</strong> 
Map the number 991 as follows:
1. mapping[9] = 6, so all occurrences of the digit 9 will become 6.
2. mapping[1] = 9, so all occurrences of the digit 1 will become 9.
Therefore, the mapped value of 991 is 669.
338 maps to 007, or 7 after removing the leading zeros.
38 maps to 07, which is also 7 after removing leading zeros.
Since 338 and 38 share the same mapped value, they should remain in the same relative order, so 338 comes before 38.
Thus, the sorted array is [338,38,991].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> mapping = [0,1,2,3,4,5,6,7,8,9], nums = [789,456,123]
<strong>Output:</strong> [123,456,789]
<strong>Explanation:</strong> 789 maps to 789, 456 maps to 456, and 123 maps to 123. Thus, the sorted array is [123,456,789].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>mapping.length == 10</code></li>
	<li><code>0 &lt;= mapping[i] &lt;= 9</code></li>
	<li>All the values of <code>mapping[i]</code> are <strong>unique</strong>.</li>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt; 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  int map(const vector<int>& mapping, int n) {
    int base = 1;
    int result = 0;
    if(!n) return mapping[0];
    while(n) {
      result += base * (mapping[n % 10]);
      base *= 10;
      n /= 10;
    }
    return result;
  }
public:
  vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    vector<pair<int, int>> afterMapping;
    afterMapping.reserve(nums.size());
    for(auto n : nums) {
      afterMapping.push_back({map(mapping, n), n});
    }
    stable_sort(afterMapping.begin(), afterMapping.end(), [=](const pair<int, int> &a, const pair<int, int> &b) {
      return a.first < b.first;
    });

    vector<int> answer(nums.size());
    for(int i = 0; i < nums.size(); ++i) {
      answer[i] = afterMapping[i].second;
    }
    return answer;
  }
};
```
