+++
updated = 2023-03-30T15:49:03+08:00
title = "2023-03-30 Daily Challenge"
path = "2023-03-30-Daily-Challenge"
date = 2023-03-30T15:49:03+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/scramble-string/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 30

## Description

**Scramble String**

<p>We can scramble a string s to get a string t using the following algorithm:</p>

<ol>
	<li>If the length of the string is 1, stop.</li>
	<li>If the length of the string is &gt; 1, do the following:
	<ul>
		<li>Split the string into two non-empty substrings at a random index, i.e., if the string is <code>s</code>, divide it to <code>x</code> and <code>y</code> where <code>s = x + y</code>.</li>
		<li><strong>Randomly</strong>&nbsp;decide to swap the two substrings or to keep them in the same order. i.e., after this step, <code>s</code> may become <code>s = x + y</code> or <code>s = y + x</code>.</li>
		<li>Apply step 1 recursively on each of the two substrings <code>x</code> and <code>y</code>.</li>
	</ul>
	</li>
</ol>

<p>Given two strings <code>s1</code> and <code>s2</code> of <strong>the same length</strong>, return <code>true</code> if <code>s2</code> is a scrambled string of <code>s1</code>, otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s1 = &quot;great&quot;, s2 = &quot;rgeat&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> One possible scenario applied on s1 is:
&quot;great&quot; --&gt; &quot;gr/eat&quot; // divide at random index.
&quot;gr/eat&quot; --&gt; &quot;gr/eat&quot; // random decision is not to swap the two substrings and keep them in order.
&quot;gr/eat&quot; --&gt; &quot;g/r / e/at&quot; // apply the same algorithm recursively on both substrings. divide at random index each of them.
&quot;g/r / e/at&quot; --&gt; &quot;r/g / e/at&quot; // random decision was to swap the first substring and to keep the second substring in the same order.
&quot;r/g / e/at&quot; --&gt; &quot;r/g / e/ a/t&quot; // again apply the algorithm recursively, divide &quot;at&quot; to &quot;a/t&quot;.
&quot;r/g / e/ a/t&quot; --&gt; &quot;r/g / e/ a/t&quot; // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is &quot;rgeat&quot; which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s1 = &quot;abcde&quot;, s2 = &quot;caebd&quot;
<strong>Output:</strong> false
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s1 = &quot;a&quot;, s2 = &quot;a&quot;
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>s1.length == s2.length</code></li>
	<li><code>1 &lt;= s1.length &lt;= 30</code></li>
	<li><code>s1</code> and <code>s2</code> consist of lowercase English letters.</li>
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
  unordered_map<string, bool> result;
public:
  bool isScramble(string s1, string s2) {
    if(s1 == s2) return true;
    int len = s1.length();

    if(result.count(s1 + s2)) return result[s1 + s2];
    vector<int> a(26), b(26), c(26);

    for(int i = 1; i < len; ++i) {
      int j = len - i;
      a[s1[i - 1] - 'a'] += 1;
      b[s2[i - 1] - 'a'] += 1;
      c[s2[j] - 'a'] += 1;

      if(a == b && isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
        result[s1 + s2] = true;
        return true;
      }

      if(a == c && isScramble(s1.substr(0, i), s2.substr(j)) && isScramble(s1.substr(i), s2.substr(0, j))) {
        result[s1 + s2] = true;
        return true;
      }
    }

    result[s1 + s2] = false;
    return false;
  }
};

// Accepted
// 288/288 cases passed (3 ms)
// Your runtime beats 99.15 % of cpp submissions
// Your memory usage beats 79.89 % of cpp submissions (15.2 MB)
```
