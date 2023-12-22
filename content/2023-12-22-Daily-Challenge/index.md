+++
updated = 2023-12-22T08:59:02+08:00
title = "2023-12-22 Daily Challenge"
path = "2023-12-22-Daily-Challenge"
date = 2023-12-22T08:59:02+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/maximum-score-after-splitting-a-string/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 22

## Description

**Maximum Score After Splitting a String**

<p>Given a&nbsp;string <code>s</code>&nbsp;of zeros and ones, <em>return the maximum score after splitting the string into two <strong>non-empty</strong> substrings</em> (i.e. <strong>left</strong> substring and <strong>right</strong> substring).</p>

<p>The score after splitting a string is the number of <strong>zeros</strong> in the <strong>left</strong> substring plus the number of <strong>ones</strong> in the <strong>right</strong> substring.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;011101&quot;
<strong>Output:</strong> 5 
<strong>Explanation:</strong> 
All possible ways of splitting s into two non-empty substrings are:
left = &quot;0&quot; and right = &quot;11101&quot;, score = 1 + 4 = 5 
left = &quot;01&quot; and right = &quot;1101&quot;, score = 1 + 3 = 4 
left = &quot;011&quot; and right = &quot;101&quot;, score = 1 + 2 = 3 
left = &quot;0111&quot; and right = &quot;01&quot;, score = 1 + 1 = 2 
left = &quot;01110&quot; and right = &quot;1&quot;, score = 2 + 1 = 3
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;00111&quot;
<strong>Output:</strong> 5
<strong>Explanation:</strong> When left = &quot;00&quot; and right = &quot;111&quot;, we get the maximum score = 2 + 3 = 5
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;1111&quot;
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 500</code></li>
	<li>The string <code>s</code> consists of characters <code>&#39;0&#39;</code> and <code>&#39;1&#39;</code> only.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxScore(string s) {
    int score = 0;
    for(auto c : s) {
      score += c - '0';
    }
    int maxScore = INT_MIN;
    for(int i = 0; i < s.length() - 1; ++i) {
      if(s[i] == '0') {
        score += 1;
      } else {
        score -= 1;
      }
      maxScore = max(score, maxScore);
    }
    return maxScore;
  }
};

// Accepted
// 104/104 cases passed (3 ms)
// Your runtime beats 50.89 % of cpp submissions
// Your memory usage beats 62.95 % of cpp submissions (6.7 MB)
```
