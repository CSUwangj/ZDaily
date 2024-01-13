+++
updated = 2024-01-13T13:22:51+08:00
title = "2024-01-13 Daily Challenge"
path = "2024-01-13-Daily-Challenge"
date = 2024-01-13T13:22:51+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 13

## Description

**Minimum Number of Steps to Make Two Strings Anagram**

<p>You are given two strings of the same length <code>s</code> and <code>t</code>. In one step you can choose <strong>any character</strong> of <code>t</code> and replace it with <strong>another character</strong>.</p>

<p>Return <em>the minimum number of steps</em> to make <code>t</code> an anagram of <code>s</code>.</p>

<p>An <strong>Anagram</strong> of a string is a string that contains the same characters with a different (or the same) ordering.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;bab&quot;, t = &quot;aba&quot;
<strong>Output:</strong> 1
<strong>Explanation:</strong> Replace the first &#39;a&#39; in t with b, t = &quot;bba&quot; which is anagram of s.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;leetcode&quot;, t = &quot;practice&quot;
<strong>Output:</strong> 5
<strong>Explanation:</strong> Replace &#39;p&#39;, &#39;r&#39;, &#39;a&#39;, &#39;i&#39; and &#39;c&#39; from t with proper characters to make t anagram of s.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;anagram&quot;, t = &quot;mangaar&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong> &quot;anagram&quot; and &quot;mangaar&quot; are anagrams. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>s.length == t.length</code></li>
	<li><code>s</code> and <code>t</code> consist of lowercase English letters only.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int minSteps(string s, string t) {
    vector<int> countS(26);
    vector<int> countT(26);
    for(auto c : s) {
      countS[c - 'a'] += 1;
    }
    for(auto c : t) {
      countT[c - 'a'] += 1;
    }
    int answer = s.length();
    for(int i = 0; i < 26; ++i) {
      answer -= min(countS[i], countT[i]);
    }

    return answer;
  }
};

// Accepted
// 63/63 cases passed (32 ms)
// Your runtime beats 98.38 % of cpp submissions
// Your memory usage beats 19.43 % of cpp submissions (17.2 MB)
```
