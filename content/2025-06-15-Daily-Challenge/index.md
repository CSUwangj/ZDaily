+++
updated = 2025-06-16T03:55:21+08:00
title = "2025-06-15 Daily Challenge"
path = "2025-06-15-Daily-Challenge"
date = 2025-06-16T03:55:21+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 15

## Description

**Max Difference You Can Get From Changing an Integer**

<p>You are given an integer <code>num</code>. You will apply the following steps to <code>num</code> <strong>two</strong> separate times:</p>

<ul>
	<li>Pick a digit <code>x (0 &lt;= x &lt;= 9)</code>.</li>
	<li>Pick another digit <code>y (0 &lt;= y &lt;= 9)</code>. Note <code>y</code> can be equal to <code>x</code>.</li>
	<li>Replace all the occurrences of <code>x</code> in the decimal representation of <code>num</code> by <code>y</code>.</li>
</ul>

<p>Let <code>a</code> and <code>b</code> be the two results from applying the operation to <code>num</code> <em>independently</em>.</p>

<p>Return <em>the max difference</em> between <code>a</code> and <code>b</code>.</p>

<p>Note that neither <code>a</code> nor <code>b</code> may have any leading zeros, and <strong>must not</strong> be 0.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num = 555
<strong>Output:</strong> 888
<strong>Explanation:</strong> The first time pick x = 5 and y = 9 and store the new integer in a.
The second time pick x = 5 and y = 1 and store the new integer in b.
We have now a = 999 and b = 111 and max difference = 888
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> num = 9
<strong>Output:</strong> 8
<strong>Explanation:</strong> The first time pick x = 9 and y = 9 and store the new integer in a.
The second time pick x = 9 and y = 1 and store the new integer in b.
We have now a = 9 and b = 1 and max difference = 8
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10<sup>8</sup></code></li>
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
