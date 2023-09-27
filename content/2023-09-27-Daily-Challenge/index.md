+++
updated = 2023-09-27T11:48:02+08:00
title = "2023-09-27 Daily Challenge"
path = "2023-09-27-Daily-Challenge"
date = 2023-09-27T11:48:02+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/decoded-string-at-index/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 27

## Description

**Decoded String at Index**

<p>You are given an encoded string <code>s</code>. To decode the string to a tape, the encoded string is read one character at a time and the following steps are taken:</p>

<ul>
	<li>If the character read is a letter, that letter is written onto the tape.</li>
	<li>If the character read is a digit <code>d</code>, the entire current tape is repeatedly written <code>d - 1</code> more times in total.</li>
</ul>

<p>Given an integer <code>k</code>, return <em>the </em><code>k<sup>th</sup></code><em> letter (<strong>1-indexed)</strong> in the decoded string</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;leet2code3&quot;, k = 10
<strong>Output:</strong> &quot;o&quot;
<strong>Explanation:</strong> The decoded string is &quot;leetleetcodeleetleetcodeleetleetcode&quot;.
The 10<sup>th</sup> letter in the string is &quot;o&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ha22&quot;, k = 5
<strong>Output:</strong> &quot;h&quot;
<strong>Explanation:</strong> The decoded string is &quot;hahahaha&quot;.
The 5<sup>th</sup> letter is &quot;h&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;a2345678999999999999999&quot;, k = 1
<strong>Output:</strong> &quot;a&quot;
<strong>Explanation:</strong> The decoded string is &quot;a&quot; repeated 8301530446056247680 times.
The 1<sup>st</sup> letter is &quot;a&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists of lowercase English letters and digits <code>2</code> through <code>9</code>.</li>
	<li><code>s</code> starts with a letter.</li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
	<li>It is guaranteed that <code>k</code> is less than or equal to the length of the decoded string.</li>
	<li>The decoded string is guaranteed to have less than <code>2<sup>63</sup></code> letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  string decodeAtIndex(string S, int K) {
    char prevChar = S[0];
    int len = S.length();
    vector<unsigned long long> cnt(len);
    vector<char> lastChar(len);
    cnt[0] = 1, lastChar[0] = S[0];
    for(int i = 1; i < len; ++i) {
      if(isdigit(S[i])) {
        cnt[i] = cnt[i-1] * (S[i]-'0');
      } else {
        cnt[i] = cnt[i-1] + 1;
        prevChar = S[i];
      }
      lastChar[i] = prevChar;
    }
    if(K >= cnt.back()) K %= cnt.back();
    if(K == 0) return string(1, prevChar);
    while(K) {
      int pos = 0;
      while(pos < len && cnt[pos] < K) ++pos;
      if(cnt[pos] == K || K % cnt[pos-1] == 0) return string(1, lastChar[pos]);
      K %= cnt[pos-1];
    }
    return "";
  }
};

// Accepted
// 45/45 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 7.16 % of cpp submissions (6.6 MB)
```
