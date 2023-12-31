+++
updated = 2023-12-31T14:23:57+08:00
title = "2023-12-31 Daily Challenge"
path = "2023-12-31-Daily-Challenge"
date = 2023-12-31T14:23:57+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/largest-substring-between-two-equal-characters/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 31

## Description

**Largest Substring Between Two Equal Characters**

<p>Given a string <code>s</code>, return <em>the length of the longest substring between two equal characters, excluding the two characters.</em> If there is no such substring return <code>-1</code>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aa&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong> The optimal substring here is an empty substring between the two <code>&#39;a&#39;s</code>.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abca&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> The optimal substring here is &quot;bc&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;cbzxy&quot;
<strong>Output:</strong> -1
<strong>Explanation:</strong> There are no characters that appear twice in s.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 300</code></li>
	<li><code>s</code> contains only lowercase English letters.</li>
</ul>


## Solution

``` cpp
int front[26];
int back[26];
class Solution {
public:
  int maxLengthBetweenEqualCharacters(string s) {
    for(int i = 0; i < 26; ++i) {
      front[i] = 1000;
      back[i] = -1000;
    }
    for(int i = 0; i < s.length(); ++i) {
      int c = s[i] - 'a';
      front[c] = min(front[c], i);
      back[c] = max(back[c], i);
    }
    int answer = -1;
    for(int i = 0; i < 26; ++i) {
      answer = max(answer, back[i] - 1 - front[i]);
    }
    return answer;
  }
};

// Accepted
// 54/54 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 97.01 % of cpp submissions (6.6 MB)
```
