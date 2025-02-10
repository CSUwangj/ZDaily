+++
updated = 2025-02-10T23:03:17+08:00
title = "2025-02-10 Daily Challenge"
path = "2025-02-10-Daily-Challenge"
date = 2025-02-10T23:03:17+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/clear-digits/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 10

## Description

**Clear Digits**

<p>You are given a string <code>s</code>.</p>

<p>Your task is to remove <strong>all</strong> digits by doing this operation repeatedly:</p>

<ul>
	<li>Delete the <em>first</em> digit and the <strong>closest</strong> <b>non-digit</b> character to its <em>left</em>.</li>
</ul>

<p>Return the resulting string after removing all digits.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;abc&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;abc&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>There is no digit in the string.<!-- notionvc: ff07e34f-b1d6-41fb-9f83-5d0ba3c1ecde --></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;cb34&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>First, we apply the operation on <code>s[2]</code>, and <code>s</code> becomes <code>&quot;c4&quot;</code>.</p>

<p>Then we apply the operation on <code>s[1]</code>, and <code>s</code> becomes <code>&quot;&quot;</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists only of lowercase English letters and digits.</li>
	<li>The input is generated such that it is possible to delete all digits.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  string clearDigits(string s) {
    string answer;
    for(auto c : s) {
      if(isalpha(c)) {
        answer.push_back(c);
      } else {
        if(answer.size()) answer.pop_back();
      }
    }
    return answer;
  }
};

// Accepted
// 688/688 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 87.14 % of cpp submissions (8.4 MB)
```
