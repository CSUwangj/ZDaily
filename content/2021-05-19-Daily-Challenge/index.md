+++
title = "2021-05-19 Daily-Challenge"
path = "2021-05-19-Daily-Challenge"
date = 2021-05-19 18:33:44+08:00
updated = 2021-05-19 18:44:55+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

I'm busy playing Dungeons & Fighters, so won't do pick up.

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3748/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 19

## Description

**Minimum Moves to Equal Array Elements II**

<p>Given an integer array <code>nums</code> of size <code>n</code>, return <em>the minimum number of moves required to make all array elements equal</em>.</p>

<p>In one move, you can increment or decrement an element of the array by <code>1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><code><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
Only two moves are needed (remember each move increments or decrements one element):
[<u>1</u>,2,3]  =&gt;  [2,2,<u>3</u>]  =&gt;  [2,2,2]
</pre></code>

<p><strong>Example 2:</strong></p>

<pre><code><strong>Input:</strong> nums = [1,10,2,9]
<strong>Output:</strong> 16
</pre></code>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int minMoves2(vector<int>& nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end());
    long long sum = 0;
    for(auto i : nums) sum += i;
    long long cur = 0;
    long long answer = INT_MAX;
    for(long long i = 0; i < len; ++i) {
      answer = min(answer, (nums[i] * i - cur) + (sum - cur - (len - i) * nums[i]));
      cur += nums[i];
    }
    return answer;
  }
};
```
