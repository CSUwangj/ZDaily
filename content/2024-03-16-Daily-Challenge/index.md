+++
updated = 2024-03-16T09:54:30+08:00
title = "2024-03-16 Daily Challenge"
path = "2024-03-16-Daily-Challenge"
date = 2024-03-16T09:54:30+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/contiguous-array/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 16

## Description

**Contiguous Array**

<p>Given a binary array <code>nums</code>, return <em>the maximum length of a contiguous subarray with an equal number of </em><code>0</code><em> and </em><code>1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1,0]
<strong>Output:</strong> 2
<strong>Explanation:</strong> [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
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
  int findMaxLength(vector<int>& nums) {
    int all = 0;
    int one = 0;
    int answer = 0;
    map<int, int> pos{{0, -1}};
    for(auto n : nums) {
      if(n) {
        one += 1;
      } else {
        one -= 1;
      }
      if(pos.count(one)) {
        answer = max(answer, all - pos[one]);
      } else {
        pos[one] = all;
      }
      all += 1;
    }
    return answer;
  }
};

// Accepted
// 564/564 cases passed (212 ms)
// Your runtime beats 32.57 % of cpp submissions
// Your memory usage beats 14.46 % of cpp submissions (84.3 MB)
```
