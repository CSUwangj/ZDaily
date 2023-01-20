+++
updated = 2023-01-20T11:50:43+08:00
title = "2023-01-20 Daily Challenge"
path = "2023-01-20-Daily-Challenge"
date = 2023-01-20T11:50:43+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/non-decreasing-subsequences/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 20

## Description

**Non-decreasing Subsequences**

<p>Given an integer array <code>nums</code>, return <em>all the different possible non-decreasing subsequences of the given array with at least two elements</em>. You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,6,7,7]
<strong>Output:</strong> [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,4,3,2,1]
<strong>Output:</strong> [[4,4]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 15</code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
</ul>


## Solution

``` cpp
constexpr int pop_count(int x) {
  const int m1  = 0X55555555;
  const int m2  = 0X33333333;
  const int m4  = 0X0F0F0F0F;
  const int m8  = 0X00FF00FF;
  const int m16 = 0X0000FFFF;
  x = (x &  m1) + ((x >>  1) &  m1);
  x = (x &  m2) + ((x >>  2) &  m2);
  x = (x &  m4) + ((x >>  4) &  m4);
  x = (x &  m8) + ((x >>  8) &  m8);
  x = (x & m16) + ((x >> 16) & m16);
  return x;
}
class Solution {
  vector<int> getSubsequence(int mask, const vector<int> &array) {
    vector<int> result;
    for(int i = 0; i < array.size(); ++i) {
      if((1 << i) & mask) {
        result.push_back(array[i]);
      }
    }
    return result;
  }
  bool validSubsequence(int mask, const vector<int> &array) {
    int last = -101;
    for(int i = 0; i < array.size(); ++i) {
      if(!((1 << i) & mask)) continue;
      if(array[i] < last) return false;
      last = array[i];
    }
    return true;
  }
public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    int bits = nums.size();
    int maxMask = 1 << bits;

    vector<vector<int>> answer;
    for(int i = 1; i < maxMask; ++i) {
      if(pop_count(i) < 2) continue;
      if(!validSubsequence(i, nums)) continue;
      answer.emplace_back(getSubsequence(i, nums));
    }

    sort(answer.begin(), answer.end());
    answer.resize(unique(answer.begin(), answer.end()) - answer.begin());
    return answer;
  }
};

// Accepted
// 58/58 cases passed (162 ms)
// Your runtime beats 24.96 % of cpp submissions
// Your memory usage beats 33.17 % of cpp submissions (31.1 MB)
```
