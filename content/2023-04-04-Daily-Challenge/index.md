+++
updated = 2023-04-04T08:03:49+08:00
title = "2023-04-04 Daily Challenge"
path = "2023-04-04-Daily-Challenge"
date = 2023-04-04T08:03:49+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/optimal-partition-of-string/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 4

## Description

**Optimal Partition of String**

<p>Given a string <code>s</code>, partition the string into one or more <strong>substrings</strong> such that the characters in each substring are <strong>unique</strong>. That is, no letter appears in a single substring more than <strong>once</strong>.</p>

<p>Return <em>the <strong>minimum</strong> number of substrings in such a partition.</em></p>

<p>Note that each character should belong to exactly one substring in a partition.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abacaba&quot;
<strong>Output:</strong> 4
<strong>Explanation:</strong>
Two possible partitions are (&quot;a&quot;,&quot;ba&quot;,&quot;cab&quot;,&quot;a&quot;) and (&quot;ab&quot;,&quot;a&quot;,&quot;ca&quot;,&quot;ba&quot;).
It can be shown that 4 is the minimum number of substrings needed.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ssssss&quot;
<strong>Output:</strong> 6
<strong>Explanation:
</strong>The only valid partition is (&quot;s&quot;,&quot;s&quot;,&quot;s&quot;,&quot;s&quot;,&quot;s&quot;,&quot;s&quot;).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of only English lowercase letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int partitionString(string s) {
    vector<int> count(26);
    int answer = 1;
    for(auto c : s) {
      if(count[c - 'a']) {
        fill(count.begin(), count.end(), 0);
        answer += 1;
      }
      count[c - 'a'] += 1;
    }
    return answer;
  }
};

// Accepted
// 59/59 cases passed (28 ms)
// Your runtime beats 83.48 % of cpp submissions
// Your memory usage beats 90.34 % of cpp submissions (10.3 MB)
```
