+++
updated = 2025-06-16T22:31:26+08:00
title = "2025-06-16 Daily Challenge"
path = "2025-06-16-Daily-Challenge"
date = 2025-06-16T22:31:26+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/maximum-difference-between-increasing-elements/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 16

## Description

**Maximum Difference Between Increasing Elements**

<p>Given a <strong>0-indexed</strong> integer array <code>nums</code> of size <code>n</code>, find the <strong>maximum difference</strong> between <code>nums[i]</code> and <code>nums[j]</code> (i.e., <code>nums[j] - nums[i]</code>), such that <code>0 &lt;= i &lt; j &lt; n</code> and <code>nums[i] &lt; nums[j]</code>.</p>

<p>Return <em>the <strong>maximum difference</strong>. </em>If no such <code>i</code> and <code>j</code> exists, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [7,<strong><u>1</u></strong>,<strong><u>5</u></strong>,4]
<strong>Output:</strong> 4
<strong>Explanation:</strong>
The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i &gt; j, so it is not valid.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [9,4,3,2]
<strong>Output:</strong> -1
<strong>Explanation:</strong>
There is no i and j such that i &lt; j and nums[i] &lt; nums[j].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [<strong><u>1</u></strong>,5,2,<strong><u>10</u></strong>]
<strong>Output:</strong> 9
<strong>Explanation:</strong>
The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxDiff(int num) {
    string n = to_string(num);
    string maxN = n;
    int len = n.length();
    int start = 0;
    while(start < len && maxN[start] == '9') start += 1;
    for(int i = start + 1; i < len; ++i) {
      if(maxN[i] == maxN[start]) maxN[i] = '9';
    }
    if(start < len) maxN[start] = '9';

    string minN = n;
    bool changed = false;
    for(int i = 0; i < len && !changed; ++i) {
      char target = minN[i];
      if(!i) {
        if(target == '1') continue;
        changed = true;
        for(int j = 0; j < len; ++j) {
          if(minN[j] == target) minN[j] = '1';
        }
      } else {
        if(target == '0' || target == minN[0]) continue;
        changed = true;
        for(int j = 0; j < len; ++j) {
          if(minN[j] == target) minN[j] = '0';
        }
      }
    }
    return stoi(maxN) - stoi(minN);
  }
};

// Accepted
// 211/211 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 66.9 % of cpp submissions (8.2 MB)
```
