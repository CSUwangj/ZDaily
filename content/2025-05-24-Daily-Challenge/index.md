+++
updated = 2025-05-25T02:00:30+08:00
title = "2025-05-24 Daily Challenge"
path = "2025-05-24-Daily-Challenge"
date = 2025-05-25T02:00:30+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/find-words-containing-character/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 24

## Description

**Find Words Containing Character**

<p>You are given a <strong>0-indexed</strong> array of strings <code>words</code> and a character <code>x</code>.</p>

<p>Return <em>an <strong>array of indices</strong> representing the words that contain the character </em><code>x</code>.</p>

<p><strong>Note</strong> that the returned array may be in <strong>any</strong> order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;leet&quot;,&quot;code&quot;], x = &quot;e&quot;
<strong>Output:</strong> [0,1]
<strong>Explanation:</strong> &quot;e&quot; occurs in both words: &quot;l<strong><u>ee</u></strong>t&quot;, and &quot;cod<u><strong>e</strong></u>&quot;. Hence, we return indices 0 and 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;abc&quot;,&quot;bcd&quot;,&quot;aaaa&quot;,&quot;cbc&quot;], x = &quot;a&quot;
<strong>Output:</strong> [0,2]
<strong>Explanation:</strong> &quot;a&quot; occurs in &quot;<strong><u>a</u></strong>bc&quot;, and &quot;<u><strong>aaaa</strong></u>&quot;. Hence, we return indices 0 and 2.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;abc&quot;,&quot;bcd&quot;,&quot;aaaa&quot;,&quot;cbc&quot;], x = &quot;z&quot;
<strong>Output:</strong> []
<strong>Explanation:</strong> &quot;z&quot; does not occur in any of the words. Hence, we return an empty array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 50</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 50</code></li>
	<li><code>x</code> is a lowercase English letter.</li>
	<li><code>words[i]</code> consists only of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> findWordsContaining(vector<string>& words, char x) {
    vector<int> answer;
    for(int i = 0; i < words.size(); ++i) {
      for(auto c : words[i]) {
        if(c != x) continue;
        answer.push_back(i);
        break;
      }
    }
    return answer;
  }
};

// Accepted
// 912/912 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 56.49 % of cpp submissions (33 MB)
```
