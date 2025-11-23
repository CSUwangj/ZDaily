+++
updated = 2025-11-23T23:21:34+01:00
title = "2025-11-23 Daily Challenge"
path = "2025-11-23-Daily-Challenge"
date = 2025-11-23T23:21:34+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/greatest-sum-divisible-by-three/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 23

## Description

**Greatest Sum Divisible by Three**

<p>Given an integer array <code>nums</code>, return <em>the <strong>maximum possible sum </strong>of elements of the array such that it is divisible by three</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,6,5,1,8]
<strong>Output:</strong> 18
<strong>Explanation:</strong> Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [4]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Since 4 is not divisible by 3, do not pick any number.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4,4]
<strong>Output:</strong> 12
<strong>Explanation:</strong> Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxSumDivThree(vector<int>& nums) {
    int minOne = 0;
    int minTwo = 0;
    int sum = 0;
    for(auto num : nums) {
      if(num % 3 == 1) {
        if(minOne) {
          if(minTwo) minTwo = min(minTwo, minOne + num);
          else minTwo = minOne + num;
          minOne = min(minOne, num);
        } else {
          minOne = num;
        }
      } else if(num % 3 == 2) {
        if(minTwo) {
          if(minOne) minOne = min(minOne, minTwo + num);
          else minOne = minTwo + num;
          minTwo = min(minTwo, num);
        } else {
          minTwo = num;
        }
      }
      sum += num;
    }
    if(sum % 3 == 1) return sum - minOne;
    if(sum % 3 == 2) return sum - minTwo;
    return sum;
  }
};

// Accepted
// 43/43 cases passed (1 ms)
// Your runtime beats 89.48 % of cpp submissions
// Your memory usage beats 93.2 % of cpp submissions (28.8 MB)
```
