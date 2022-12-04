+++
updated = 2022-12-04T12:36:23+08:00
title = "2022-12-04 Daily Challenge"
path = "2022-12-04-Daily-Challenge"
date = 2022-12-04T12:36:23+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/minimum-average-difference/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 4

## Description

**Minimum Average Difference**

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> of length <code>n</code>.</p>

<p>The <strong>average difference</strong> of the index <code>i</code> is the <strong>absolute</strong> <strong>difference</strong> between the average of the <strong>first</strong> <code>i + 1</code> elements of <code>nums</code> and the average of the <strong>last</strong> <code>n - i - 1</code> elements. Both averages should be <strong>rounded down</strong> to the nearest integer.</p>

<p>Return<em> the index with the <strong>minimum average difference</strong></em>. If there are multiple such indices, return the <strong>smallest</strong> one.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>The <strong>absolute difference</strong> of two numbers is the absolute value of their difference.</li>
	<li>The <strong>average</strong> of <code>n</code> elements is the <strong>sum</strong> of the <code>n</code> elements divided (<strong>integer division</strong>) by <code>n</code>.</li>
	<li>The average of <code>0</code> elements is considered to be <code>0</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,5,3,9,5,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong>
- The average difference of index 0 is: |2 / 1 - (5 + 3 + 9 + 5 + 3) / 5| = |2 / 1 - 25 / 5| = |2 - 5| = 3.
- The average difference of index 1 is: |(2 + 5) / 2 - (3 + 9 + 5 + 3) / 4| = |7 / 2 - 20 / 4| = |3 - 5| = 2.
- The average difference of index 2 is: |(2 + 5 + 3) / 3 - (9 + 5 + 3) / 3| = |10 / 3 - 17 / 3| = |3 - 5| = 2.
- The average difference of index 3 is: |(2 + 5 + 3 + 9) / 4 - (5 + 3) / 2| = |19 / 4 - 8 / 2| = |4 - 4| = 0.
- The average difference of index 4 is: |(2 + 5 + 3 + 9 + 5) / 5 - 3 / 1| = |24 / 5 - 3 / 1| = |4 - 3| = 1.
- The average difference of index 5 is: |(2 + 5 + 3 + 9 + 5 + 3) / 6 - 0| = |27 / 6 - 0| = |4 - 0| = 4.
The average difference of index 3 is the minimum average difference so return 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [0]
<strong>Output:</strong> 0
<strong>Explanation:</strong>
The only index is 0 so return 0.
The average difference of index 0 is: |0 / 1 - 0| = |0 - 0| = 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int minimumAverageDifference(vector<int>& nums) {
    long long sum = accumulate(nums.begin(), nums.end(), 0LL);
    long long front = 0;
    long long back = sum;
    int answer = 0;
    int current = INT_MAX;
    int len = nums.size();
    for(int i = 0; i < len; ++i) {
      front += nums[i];
      back -= nums[i];
      int frontAvarage = front / (i + 1);
      int backAvarage = back ? back / (len - i - 1) : 0;
      int diff = abs(frontAvarage - backAvarage);
      if(diff < current) {
        answer = i;
        current = diff;
      }
    }
    return answer;
  }
};

// Accepted
// 78/78 cases passed (167 ms)
// Your runtime beats 72.25 % of cpp submissions
// Your memory usage beats 76.81 % of cpp submissions (78.4 MB)
```
