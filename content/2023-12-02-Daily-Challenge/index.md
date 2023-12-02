+++
updated = 2023-12-02T19:48:54+08:00
title = "2023-12-02 Daily Challenge"
path = "2023-12-02-Daily-Challenge"
date = 2023-12-02T19:48:54+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 2

## Description

**Find Words That Can Be Formed by Characters**

<p>You are given an array of strings <code>words</code> and a string <code>chars</code>.</p>

<p>A string is <strong>good</strong> if it can be formed by characters from chars (each character can only be used once).</p>

<p>Return <em>the sum of lengths of all good strings in words</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;cat&quot;,&quot;bt&quot;,&quot;hat&quot;,&quot;tree&quot;], chars = &quot;atach&quot;
<strong>Output:</strong> 6
<strong>Explanation:</strong> The strings that can be formed are &quot;cat&quot; and &quot;hat&quot; so the answer is 3 + 3 = 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;hello&quot;,&quot;world&quot;,&quot;leetcode&quot;], chars = &quot;welldonehoneyr&quot;
<strong>Output:</strong> 10
<strong>Explanation:</strong> The strings that can be formed are &quot;hello&quot; and &quot;world&quot; so the answer is 5 + 5 = 10.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length, chars.length &lt;= 100</code></li>
	<li><code>words[i]</code> and <code>chars</code> consist of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int countCharacters(vector<string>& words, string chars) {
    vector<int> count(26);
    for(auto c : chars) {
      count[c - 'a'] += 1;
    }
    int answer = 0;
    for(const auto &word : words) {
      vector<int> ct(count);
      if(word.length() > chars.length()) continue;
      bool ok = true;
      for(auto c : word) {
        ct[c - 'a'] -= 1;
        if(ct[c - 'a'] < 0) ok = false;
      }
      if(ok) {
        answer += word.length();
      }
    }

    return answer;
  }
};

// Accepted
// 36/36 cases passed (44 ms)
// Your runtime beats 78.41 % of cpp submissions
// Your memory usage beats 71.98 % of cpp submissions (20.5 MB)
```
