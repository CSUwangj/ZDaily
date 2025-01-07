+++
updated = 2025-01-07T17:42:40+08:00
title = "2025-01-07 Daily Challenge"
path = "2025-01-07-Daily-Challenge"
date = 2025-01-07T17:42:40+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/string-matching-in-an-array/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 7

## Description

**String Matching in an Array**

<p>Given an array of string <code>words</code>, return <em>all strings in </em><code>words</code><em> that is a <strong>substring</strong> of another word</em>. You can return the answer in <strong>any order</strong>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;mass&quot;,&quot;as&quot;,&quot;hero&quot;,&quot;superhero&quot;]
<strong>Output:</strong> [&quot;as&quot;,&quot;hero&quot;]
<strong>Explanation:</strong> &quot;as&quot; is substring of &quot;mass&quot; and &quot;hero&quot; is substring of &quot;superhero&quot;.
[&quot;hero&quot;,&quot;as&quot;] is also a valid answer.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;leetcode&quot;,&quot;et&quot;,&quot;code&quot;]
<strong>Output:</strong> [&quot;et&quot;,&quot;code&quot;]
<strong>Explanation:</strong> &quot;et&quot;, &quot;code&quot; are substring of &quot;leetcode&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;blue&quot;,&quot;green&quot;,&quot;bu&quot;]
<strong>Output:</strong> []
<strong>Explanation:</strong> No string of words is substring of another string.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 30</code></li>
	<li><code>words[i]</code> contains only lowercase English letters.</li>
	<li>All the strings of <code>words</code> are <strong>unique</strong>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<string> stringMatching(vector<string>& words) {
    vector<string> answer;
    for(const auto &word : words) {
      bool found = false;
      for(const auto &source : words) {
        if(word == source) continue;
        if(source.length() > word.length() && source.find(word) != string::npos) {
          found = true;
          break;
        }
      }
      if(found) answer.push_back(word);
    }
    return answer;
  }
};

// Accepted
// 67/67 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 69.19 % of cpp submissions (11.3 MB)
```
