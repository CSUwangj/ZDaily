+++
updated = 2025-10-19T22:55:19+02:00
title = "2025-10-19 Daily Challenge"
path = "2025-10-19-Daily-Challenge"
date = 2025-10-19T22:55:19+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 19

## Description

**Lexicographically Smallest String After Applying Operations**

<p>You are given a string <code>s</code> of <strong>even length</strong> consisting of digits from <code>0</code> to <code>9</code>, and two integers <code>a</code> and <code>b</code>.</p>

<p>You can apply either of the following two operations any number of times and in any order on <code>s</code>:</p>

<ul>
	<li>Add <code>a</code> to all odd indices of <code>s</code> <strong>(0-indexed)</strong>. Digits post <code>9</code> are cycled back to <code>0</code>. For example, if <code>s = &quot;3456&quot;</code> and <code>a = 5</code>, <code>s</code> becomes <code>&quot;3951&quot;</code>.</li>
	<li>Rotate <code>s</code> to the right by <code>b</code> positions. For example, if <code>s = &quot;3456&quot;</code> and <code>b = 1</code>, <code>s</code> becomes <code>&quot;6345&quot;</code>.</li>
</ul>

<p>Return <em>the <strong>lexicographically smallest</strong> string you can obtain by applying the above operations any number of times on</em> <code>s</code>.</p>

<p>A string <code>a</code> is lexicographically smaller than a string <code>b</code> (of the same length) if in the first position where <code>a</code> and <code>b</code> differ, string <code>a</code> has a letter that appears earlier in the alphabet than the corresponding letter in <code>b</code>. For example, <code>&quot;0158&quot;</code> is lexicographically smaller than <code>&quot;0190&quot;</code> because the first position they differ is at the third letter, and <code>&#39;5&#39;</code> comes before <code>&#39;9&#39;</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;5525&quot;, a = 9, b = 2
<strong>Output:</strong> &quot;2050&quot;
<strong>Explanation:</strong> We can apply the following operations:
Start:  &quot;5525&quot;
Rotate: &quot;2555&quot;
Add:    &quot;2454&quot;
Add:    &quot;2353&quot;
Rotate: &quot;5323&quot;
Add:    &quot;5222&quot;
Add:    &quot;5121&quot;
Rotate: &quot;2151&quot;
Add:    &quot;2050&quot;​​​​​
There is no way to obtain a string that is lexicographically smaller than &quot;2050&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;74&quot;, a = 5, b = 1
<strong>Output:</strong> &quot;24&quot;
<strong>Explanation:</strong> We can apply the following operations:
Start:  &quot;74&quot;
Rotate: &quot;47&quot;
​​​​​​​Add:    &quot;42&quot;
​​​​​​​Rotate: &quot;24&quot;​​​​​​​​​​​​
There is no way to obtain a string that is lexicographically smaller than &quot;24&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;0011&quot;, a = 4, b = 2
<strong>Output:</strong> &quot;0011&quot;
<strong>Explanation:</strong> There are no sequence of operations that will give us a lexicographically smaller string than &quot;0011&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<li><code>s.length</code> is even.</li>
	<li><code>s</code> consists of digits from <code>0</code> to <code>9</code> only.</li>
	<li><code>1 &lt;= a &lt;= 9</code></li>
	<li><code>1 &lt;= b &lt;= s.length - 1</code></li>
</ul>


## Solution

``` cpp
constexpr int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}
class Solution {
private:
  void minHalf(string &s, bool odd, int a) {
    char mmin = s[odd];
    int cnt = 0;
    for(int i = 1; i < 10; ++i) {
      char test = (s[odd] - '0' + i * a) % 10 + '0';
      if(test < mmin) {
        mmin = test;
        cnt = i;
      }
    }
    // cout << s << ' ' << cnt << endl;
    if(!cnt) return;
    for(int i = odd; i < s.length(); i += 2) {
      s[i] = (s[i] - '0' + cnt * a) % 10 + '0';
    }
  }
public: 
  string findLexSmallestString(string s, int a, int b) {
    int len = s.length();
    int t = len / gcd(b, len);
    string answer = s;
    for(int i = 0; i < t; ++i) {
      rotate(s.rbegin(), s.rbegin() + b, s.rend());
      string tmp = s;
      if(b & 1) minHalf(tmp, false, a);
      minHalf(tmp, true, a);
      // cout << s << ' ' << tmp << endl;
      answer = min(answer, tmp);
    }
    return answer;
  }
};

// Accepted
// 80/80 cases passed (3 ms)
// Your runtime beats 91.41 % of cpp submissions
// Your memory usage beats 79.3 % of cpp submissions (9.7 MB)
```
