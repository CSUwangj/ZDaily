+++
updated = 2024-03-01T18:15:27+08:00
title = "2024-03-01 Daily Challenge"
path = "2024-03-01-Daily-Challenge"
date = 2024-03-01T18:15:27+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/maximum-odd-binary-number/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 1

## Description

**Maximum Odd Binary Number**

<p>You are given a <strong>binary</strong> string <code>s</code> that contains at least one <code>&#39;1&#39;</code>.</p>

<p>You have to <strong>rearrange</strong> the bits in such a way that the resulting binary number is the <strong>maximum odd binary number</strong> that can be created from this combination.</p>

<p>Return <em>a string representing the maximum odd binary number that can be created from the given combination.</em></p>

<p><strong>Note </strong>that the resulting string <strong>can</strong> have leading zeros.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;010&quot;
<strong>Output:</strong> &quot;001&quot;
<strong>Explanation:</strong> Because there is just one &#39;1&#39;, it must be in the last position. So the answer is &quot;001&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;0101&quot;
<strong>Output:</strong> &quot;1001&quot;
<strong>Explanation: </strong>One of the &#39;1&#39;s must be in the last position. The maximum number that can be made with the remaining digits is &quot;100&quot;. So the answer is &quot;1001&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists only of <code>&#39;0&#39;</code> and <code>&#39;1&#39;</code>.</li>
	<li><code>s</code> contains at least one <code>&#39;1&#39;</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  string maximumOddBinaryNumber(string s) {
    int ones = 0;
    for(auto c : s) {
      ones += c - '0';
    }
    string answer;
    while(ones > 1) {
      answer.push_back('1');
      ones -= 1;
    }
    while(answer.length() + 1 < s.length()) {
      answer.push_back('0');
    }
    answer.push_back('1');
    return answer;
  }
};

// Accepted
// 985/985 cases passed (4 ms)
// Your runtime beats 61.13 % of cpp submissions
// Your memory usage beats 55.89 % of cpp submissions (8.3 MB)
```
