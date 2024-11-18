+++
updated = 2024-11-18T08:17:31+08:00
title = "2024-11-18 Daily Challenge"
path = "2024-11-18-Daily-Challenge"
date = 2024-11-18T08:17:31+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/defuse-the-bomb/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 18

## Description

**Defuse the Bomb**

<p>You have a bomb to defuse, and your time is running out! Your informer will provide you with a <strong>circular</strong> array <code>code</code>&nbsp;of length of <code>n</code>&nbsp;and a key <code>k</code>.</p>

<p>To decrypt the code, you must replace every number. All the numbers are replaced <strong>simultaneously</strong>.</p>

<ul>
	<li>If <code>k &gt; 0</code>, replace the <code>i<sup>th</sup></code> number with the sum of the <strong>next</strong> <code>k</code> numbers.</li>
	<li>If <code>k &lt; 0</code>, replace the <code>i<sup>th</sup></code> number with the sum of the <strong>previous</strong> <code>k</code> numbers.</li>
	<li>If <code>k == 0</code>, replace the <code>i<sup>th</sup></code> number with <code>0</code>.</li>
</ul>

<p>As <code>code</code> is circular, the next element of <code>code[n-1]</code> is <code>code[0]</code>, and the previous element of <code>code[0]</code> is <code>code[n-1]</code>.</p>

<p>Given the <strong>circular</strong> array <code>code</code> and an integer key <code>k</code>, return <em>the decrypted code to defuse the bomb</em>!</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> code = [5,7,1,4], k = 3
<strong>Output:</strong> [12,10,16,13]
<strong>Explanation:</strong> Each number is replaced by the sum of the next 3 numbers. The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> code = [1,2,3,4], k = 0
<strong>Output:</strong> [0,0,0,0]
<strong>Explanation:</strong> When k is zero, the numbers are replaced by 0. 
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> code = [2,4,9,3], k = -2
<strong>Output:</strong> [12,5,6,13]
<strong>Explanation:</strong> The decrypted code is [3+9, 2+3, 4+2, 9+4]. Notice that the numbers wrap around again. If k is negative, the sum is of the <strong>previous</strong> numbers.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == code.length</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 100</code></li>
	<li><code>1 &lt;= code[i] &lt;= 100</code></li>
	<li><code>-(n - 1) &lt;= k &lt;= n - 1</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> decrypt(vector<int>& code, int k) {
    int len = code.size();
    vector<int> prefix(len);
    for(int i = 0; i < len; ++i) {
      prefix[i] = code[i];
      if(i) prefix[i] += prefix[i - 1];
    }
    vector<int> answer(len);
    if(!k) return answer;
    for(int i = 0; i < len; ++i) {
      int result = 0;
      if(k < 0) {
        if(i + k <= 0) {
          answer[i] = prefix[len - 1] - prefix[i + k + len - 1]  + prefix[i] - code[i];
        } else {
          answer[i] = prefix[i - 1] - prefix[i + k - 1];
        }
      } else {
        if(i + k >= len) {
          answer[i] = prefix[len - 1] - prefix[i] + prefix[i + k - len];
        } else {
          answer[i] = prefix[i + k] - prefix[i];
        }
      }
    }
    return answer;
  }
};
```
