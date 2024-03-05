+++
updated = 2024-03-05T11:05:16+08:00
title = "2024-03-05 Daily Challenge"
path = "2024-03-05-Daily-Challenge"
date = 2024-03-05T11:05:16+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 5

## Description

**Minimum Length of String After Deleting Similar Ends**

<p>Given a string <code>s</code> consisting only of characters <code>&#39;a&#39;</code>, <code>&#39;b&#39;</code>, and <code>&#39;c&#39;</code>. You are asked to apply the following algorithm on the string any number of times:</p>

<ol>
	<li>Pick a <strong>non-empty</strong> prefix from the string <code>s</code> where all the characters in the prefix are equal.</li>
	<li>Pick a <strong>non-empty</strong> suffix from the string <code>s</code> where all the characters in this suffix are equal.</li>
	<li>The prefix and the suffix should not intersect at any index.</li>
	<li>The characters from the prefix and suffix must be the same.</li>
	<li>Delete both the prefix and the suffix.</li>
</ol>

<p>Return <em>the <strong>minimum length</strong> of </em><code>s</code> <em>after performing the above operation any number of times (possibly zero times)</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ca&quot;
<strong>Output:</strong> 2
<strong>Explanation: </strong>You can&#39;t remove any characters, so the string stays as is.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;cabaabac&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong> An optimal sequence of operations is:
- Take prefix = &quot;c&quot; and suffix = &quot;c&quot; and remove them, s = &quot;abaaba&quot;.
- Take prefix = &quot;a&quot; and suffix = &quot;a&quot; and remove them, s = &quot;baab&quot;.
- Take prefix = &quot;b&quot; and suffix = &quot;b&quot; and remove them, s = &quot;aa&quot;.
- Take prefix = &quot;a&quot; and suffix = &quot;a&quot; and remove them, s = &quot;&quot;.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aabccabba&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> An optimal sequence of operations is:
- Take prefix = &quot;aa&quot; and suffix = &quot;a&quot; and remove them, s = &quot;bccabb&quot;.
- Take prefix = &quot;b&quot; and suffix = &quot;bb&quot; and remove them, s = &quot;cca&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> only consists of characters <code>&#39;a&#39;</code>, <code>&#39;b&#39;</code>, and <code>&#39;c&#39;</code>.</li>
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
  int minimumLength(string s) {
    int len = s.length();
    int begin = 0;
    int end = len-1;
    while(begin < end && s[begin] == s[end]) {
      char c = s[begin];
      begin += 1; 
      end -= 1;
      while(begin < end && s[begin] == c) {
        begin += 1;
      }
      while(begin <= end && s[end] == c) {
        end -= 1;
      }
    }
    return end - begin + 1;
  }
};

// Accepted
// 100/100 cases passed (15 ms)
// Your runtime beats 99.31 % of cpp submissions
// Your memory usage beats 13.45 % of cpp submissions (14 MB)
```
