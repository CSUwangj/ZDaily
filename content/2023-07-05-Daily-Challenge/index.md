+++
updated = 2023-07-05T09:29:57+08:00
title = "2023-07-05 Daily Challenge"
path = "2023-07-05-Daily-Challenge"
date = 2023-07-05T09:29:57+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 5

## Description

**Longest Subarray of 1's After Deleting One Element**

<p>Given a binary array <code>nums</code>, you should delete one element from it.</p>

<p>Return <em>the size of the longest non-empty subarray containing only </em><code>1</code><em>&#39;s in the resulting array</em>. Return <code>0</code> if there is no such subarray.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,0,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1&#39;s.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1,1,1,0,1,1,0,1]
<strong>Output:</strong> 5
<strong>Explanation:</strong> After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1&#39;s is [1,1,1,1,1].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> You must delete one element.
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
  int longestSubarray(vector<int>& nums) {
    int start = 0;
    int count = 0;
    int answer = 0;
    for(int i = 0; i < nums.size(); ++i) {
      count += !nums[i];
      while(count > 1) {
        count -= !nums[start];
        start += 1;
      }
      answer = max(answer, i - start);
    }
    return answer;
  }
};

// Accepted
// 74/74 cases passed (53 ms)
// Your runtime beats 23.1 % of cpp submissions
// Your memory usage beats 65.98 % of cpp submissions (36.5 MB)
```
