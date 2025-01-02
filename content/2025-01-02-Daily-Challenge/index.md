+++
updated = 2025-01-02T19:55:08+08:00
title = "2025-01-02 Daily Challenge"
path = "2025-01-02-Daily-Challenge"
date = 2025-01-02T19:55:08+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/count-vowel-strings-in-ranges/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 2

## Description

**Count Vowel Strings in Ranges**

<p>You are given a <strong>0-indexed</strong> array of strings <code>words</code> and a 2D array of integers <code>queries</code>.</p>

<p>Each query <code>queries[i] = [l<sub>i</sub>, r<sub>i</sub>]</code> asks us to find the number of strings present in the range <code>l<sub>i</sub></code> to <code>r<sub>i</sub></code> (both <strong>inclusive</strong>) of <code>words</code> that start and end with a vowel.</p>

<p>Return <em>an array </em><code>ans</code><em> of size </em><code>queries.length</code><em>, where </em><code>ans[i]</code><em> is the answer to the </em><code>i</code><sup>th</sup><em> query</em>.</p>

<p><strong>Note</strong> that the vowel letters are <code>&#39;a&#39;</code>, <code>&#39;e&#39;</code>, <code>&#39;i&#39;</code>, <code>&#39;o&#39;</code>, and <code>&#39;u&#39;</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;aba&quot;,&quot;bcb&quot;,&quot;ece&quot;,&quot;aa&quot;,&quot;e&quot;], queries = [[0,2],[1,4],[1,1]]
<strong>Output:</strong> [2,3,0]
<strong>Explanation:</strong> The strings starting and ending with a vowel are &quot;aba&quot;, &quot;ece&quot;, &quot;aa&quot; and &quot;e&quot;.
The answer to the query [0,2] is 2 (strings &quot;aba&quot; and &quot;ece&quot;).
to query [1,4] is 3 (strings &quot;ece&quot;, &quot;aa&quot;, &quot;e&quot;).
to query [1,1] is 0.
We return [2,3,0].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;a&quot;,&quot;e&quot;,&quot;i&quot;], queries = [[0,2],[0,1],[2,2]]
<strong>Output:</strong> [3,2,1]
<strong>Explanation:</strong> Every string satisfies the conditions, so we return [3,2,1].</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= words[i].length &lt;= 40</code></li>
	<li><code>words[i]</code> consists only of lowercase English letters.</li>
	<li><code>sum(words[i].length) &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= l<sub>i</sub> &lt;= r<sub>i</sub> &lt;&nbsp;words.length</code></li>
</ul>


## Solution

``` cpp
class Solution {
  const set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
  bool isVowelString(const string &word) {
    return vowel.count(word.front()) && vowel.count(word.back());
  }
public:
  vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    vector<int> prefix(words.size() + 1);
    for(int i = 0; i < words.size(); ++i) {
      prefix[i + 1] = prefix[i] + isVowelString(words[i]);
    }
    vector<int> answer;
    answer.reserve(queries.size());
    for(auto &q : queries) {
      answer.push_back(prefix[q[1] + 1] - prefix[q[0]]);
    }

    return answer;
  }
};

// Accepted
// 93/93 cases passed (4 ms)
// Your runtime beats 81.49 % of cpp submissions
// Your memory usage beats 68.33 % of cpp submissions (69.4 MB)
```
