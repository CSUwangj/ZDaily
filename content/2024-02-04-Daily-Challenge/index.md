+++
updated = 2024-02-04T19:17:16+08:00
title = "2024-02-04 Daily Challenge"
path = "2024-02-04-Daily-Challenge"
date = 2024-02-04T19:17:16+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/minimum-window-substring/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 4

## Description

**Minimum Window Substring**

<p>Given two strings <code>s</code> and <code>t</code> of lengths <code>m</code> and <code>n</code> respectively, return <em>the <strong>minimum window</strong></em> <span data-keyword="substring-nonempty"><strong><em>substring</em></strong></span><em> of </em><code>s</code><em> such that every character in </em><code>t</code><em> (<strong>including duplicates</strong>) is included in the window</em>. If there is no such substring, return <em>the empty string </em><code>&quot;&quot;</code>.</p>

<p>The testcases will be generated such that the answer is <strong>unique</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ADOBECODEBANC&quot;, t = &quot;ABC&quot;
<strong>Output:</strong> &quot;BANC&quot;
<strong>Explanation:</strong> The minimum window substring &quot;BANC&quot; includes &#39;A&#39;, &#39;B&#39;, and &#39;C&#39; from string t.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;a&quot;, t = &quot;a&quot;
<strong>Output:</strong> &quot;a&quot;
<strong>Explanation:</strong> The entire string s is the minimum window.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;a&quot;, t = &quot;aa&quot;
<strong>Output:</strong> &quot;&quot;
<strong>Explanation:</strong> Both &#39;a&#39;s from t must be included in the window.
Since the largest window of s only has one &#39;a&#39;, return empty string.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == s.length</code></li>
	<li><code>n == t.length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> and <code>t</code> consist of uppercase and lowercase English letters.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you find an algorithm that runs in <code>O(m + n)</code> time?</p>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int cnt[128] = {};
public:
  string minWindow(string s, string t) {
    int chars = 0;
    for(auto c : t) {
      chars += !cnt[c];
      cnt[c] += 1;
    }
    int end = 0;
    int sLen = s.length();
    while(end < sLen && chars) {
      cnt[s[end]] -= 1;
      chars -= !cnt[s[end]];
      end += 1;
    }
    if(chars) return "";
    int resultLen = INT_MAX;
    int resultBegin = 0;
    for(int begin = 0; begin < end; ++begin) {
      if(end - begin < resultLen) {
        resultLen = end - begin;
        resultBegin = begin;
      }
      cnt[s[begin]] += 1;
      while(end < sLen && cnt[s[begin]] > 0) {
        cnt[s[end]] -= 1;
        end += 1;
      }
      if(cnt[s[begin]] > 0) break;
    }
    return s.substr(resultBegin, resultLen);
  }
};

// Accepted
// 266/266 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 80.15 % of cpp submissions (7.7 MB)
```
