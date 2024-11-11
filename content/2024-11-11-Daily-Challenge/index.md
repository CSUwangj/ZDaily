+++
updated = 2024-11-11T13:18:18+08:00
title = "2024-11-11 Daily Challenge"
path = "2024-11-11-Daily-Challenge"
date = 2024-11-11T13:18:18+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/prime-subtraction-operation/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 11

## Description

**Prime Subtraction Operation**

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> of length <code>n</code>.</p>

<p>You can perform the following operation as many times as you want:</p>

<ul>
	<li>Pick an index <code>i</code> that you haven&rsquo;t picked before, and pick a prime <code>p</code> <strong>strictly less than</strong> <code>nums[i]</code>, then subtract <code>p</code> from <code>nums[i]</code>.</li>
</ul>

<p>Return <em>true if you can make <code>nums</code> a strictly increasing array using the above operation and false otherwise.</em></p>

<p>A <strong>strictly increasing array</strong> is an array whose each element is strictly greater than its preceding element.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,9,6,10]
<strong>Output:</strong> true
<strong>Explanation:</strong> In the first operation: Pick i = 0 and p = 3, and then subtract 3 from nums[0], so that nums becomes [1,9,6,10].
In the second operation: i = 1, p = 7, subtract 7 from nums[1], so nums becomes equal to [1,2,6,10].
After the second operation, nums is sorted in strictly increasing order, so the answer is true.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [6,8,11,12]
<strong>Output:</strong> true
<strong>Explanation: </strong>Initially nums is sorted in strictly increasing order, so we don&#39;t need to make any operations.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [5,8,3]
<strong>Output:</strong> false
<strong>Explanation:</strong> It can be proven that there is no way to perform operations to make nums sorted in strictly increasing order, so the answer is false.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code><font face="monospace">nums.length == n</font></code></li>
</ul>


## Solution

``` cpp
const vector<int> primes = {
  2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
  101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
  211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
  307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
  401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499,
  503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599,
  601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691,
  701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797,
  809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887,
  907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997
};
class Solution {
public:
  bool primeSubOperation(vector<int>& nums) {
    int prev = 0;
    for(auto &n : nums) {
      if(n <= prev) return false;
      int diff = n - prev;
      if(diff > 2) {
        auto it = lower_bound(primes.begin(), primes.end(), diff);
        --it;
        n -= *it;
      }
      prev = n;
    }
    return true;
  }
};
```
