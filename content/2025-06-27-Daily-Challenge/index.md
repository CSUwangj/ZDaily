+++
updated = 2025-06-27T23:45:00+08:00
title = "2025-06-27 Daily Challenge"
path = "2025-06-27-Daily-Challenge"
date = 2025-06-27T23:45:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/longest-subsequence-repeated-k-times/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 27

## Description

**Longest Subsequence Repeated k Times**

<p>You are given a string <code>s</code> of length <code>n</code>, and an integer <code>k</code>. You are tasked to find the <strong>longest subsequence repeated</strong> <code>k</code> times in string <code>s</code>.</p>

<p>A <strong>subsequence</strong> is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.</p>

<p>A subsequence <code>seq</code> is <strong>repeated</strong> <code>k</code> times in the string <code>s</code> if <code>seq * k</code> is a subsequence of <code>s</code>, where <code>seq * k</code> represents a string constructed by concatenating <code>seq</code> <code>k</code> times.</p>

<ul>
	<li>For example, <code>&quot;bba&quot;</code> is repeated <code>2</code> times in the string <code>&quot;bababcba&quot;</code>, because the string <code>&quot;bbabba&quot;</code>, constructed by concatenating <code>&quot;bba&quot;</code> <code>2</code> times, is a subsequence of the string <code>&quot;<strong><u>b</u></strong>a<strong><u>bab</u></strong>c<strong><u>ba</u></strong>&quot;</code>.</li>
</ul>

<p>Return <em>the <strong>longest subsequence repeated</strong> </em><code>k</code><em> times in string </em><code>s</code><em>. If multiple such subsequences are found, return the <strong>lexicographically largest</strong> one. If there is no such subsequence, return an <strong>empty</strong> string</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="example 1" src="https://assets.leetcode.com/uploads/2021/08/30/longest-subsequence-repeat-k-times.png" style="width: 457px; height: 99px;" />
<pre>
<strong>Input:</strong> s = &quot;letsleetcode&quot;, k = 2
<strong>Output:</strong> &quot;let&quot;
<strong>Explanation:</strong> There are two longest subsequences repeated 2 times: &quot;let&quot; and &quot;ete&quot;.
&quot;let&quot; is the lexicographically largest one.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;bb&quot;, k = 2
<strong>Output:</strong> &quot;b&quot;
<strong>Explanation:</strong> The longest subsequence repeated 2 times is &quot;b&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ab&quot;, k = 2
<strong>Output:</strong> &quot;&quot;
<strong>Explanation:</strong> There is no subsequence repeated 2 times. Empty string is returned.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == s.length</code></li>
	<li><code>2 &lt;= n, k &lt;= 2000</code></li>
	<li><code>2 &lt;= n &lt; k * 8</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
  bool isValid(const string &s, const string &pattern, int k) {
    if(pattern.empty()) return true;
    int lenP = pattern.length();
    int pos = 0;
    for(auto c : s) {
      if(c != pattern[pos]) continue;
      pos += 1;
      if(pos == lenP) {
        k -= 1;
        pos = 0;
      }
    }
    return k < 1;
  }
  void solve(
    const string &s,
    string &answer,
    string &current,
    vector<int> count,
    int k
  ) {
    // cout << s << ' ' << answer << ' ' << current << endl;
    if(current.length() > answer.length() || (current.length() == answer.length() && current > answer)) answer = current;
    for(int i = 0; i < 26; ++i) {
      if(!count[i]) continue;
      count[i] -= 1;
      current.push_back(i + 'a');
      if(isValid(s, current, k)) solve(s, answer, current, count, k);
      current.pop_back();
      count[i] += 1;
    }
  }
public:
  string longestSubsequenceRepeatedK(string s, int k) {
    vector<int> count(26);
    for(auto c : s) {
      count[c - 'a'] += 1;
    }
    for(auto &cnt : count) {
      cnt /= k;
    }
    string answer;
    string tmp;
    solve(s, answer, tmp, count, k);
    return answer;
  }
};

// Accepted
// 313/313 cases passed (67 ms)
// Your runtime beats 97.83 % of cpp submissions
// Your memory usage beats 55.8 % of cpp submissions (14 MB)
```
