+++
updated = 2023-12-07T18:58:04+08:00
title = "2023-12-07 Daily Challenge"
path = "2023-12-07-Daily-Challenge"
date = 2023-12-07T18:58:04+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/largest-odd-number-in-string/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 7

## Description

**Largest Odd Number in String**

<p>You are given a string <code>num</code>, representing a large integer. Return <em>the <strong>largest-valued odd</strong> integer (as a string) that is a <strong>non-empty substring</strong> of </em><code>num</code><em>, or an empty string </em><code>&quot;&quot;</code><em> if no odd integer exists</em>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num = &quot;52&quot;
<strong>Output:</strong> &quot;5&quot;
<strong>Explanation:</strong> The only non-empty substrings are &quot;5&quot;, &quot;2&quot;, and &quot;52&quot;. &quot;5&quot; is the only odd number.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> num = &quot;4206&quot;
<strong>Output:</strong> &quot;&quot;
<strong>Explanation:</strong> There are no odd numbers in &quot;4206&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> num = &quot;35427&quot;
<strong>Output:</strong> &quot;35427&quot;
<strong>Explanation:</strong> &quot;35427&quot; is already an odd number.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 10<sup>5</sup></code></li>
	<li><code>num</code> only consists of digits and does not contain any leading zeros.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  string largestOddNumber(string num) {
    int begin = 0;
    while(begin < num.length() && !(num[begin] - '0')) {
      begin += 1;
    }
    int end = begin - 1;
    for(int i = begin; i < num.length(); ++i) {
      if((num[i] - '0') & 1) {
        end = i;
      }
    }
    return num.substr(begin, end - begin + 1);
  }
};

// Accepted
// 196/196 cases passed (32 ms)
// Your runtime beats 31.44 % of cpp submissions
// Your memory usage beats 24.39 % of cpp submissions (15.4 MB)
```
