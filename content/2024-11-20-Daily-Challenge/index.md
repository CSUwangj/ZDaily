+++
updated = 2024-11-20T08:59:57+08:00
title = "2024-11-20 Daily Challenge"
path = "2024-11-20-Daily-Challenge"
date = 2024-11-20T08:59:57+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 20

## Description

**Take K of Each Character From Left and Right**

<p>You are given a string <code>s</code> consisting of the characters <code>&#39;a&#39;</code>, <code>&#39;b&#39;</code>, and <code>&#39;c&#39;</code> and a non-negative integer <code>k</code>. Each minute, you may take either the <strong>leftmost</strong> character of <code>s</code>, or the <strong>rightmost</strong> character of <code>s</code>.</p>

<p>Return<em> the <strong>minimum</strong> number of minutes needed for you to take <strong>at least</strong> </em><code>k</code><em> of each character, or return </em><code>-1</code><em> if it is not possible to take </em><code>k</code><em> of each character.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aabaaaacaabc&quot;, k = 2
<strong>Output:</strong> 8
<strong>Explanation:</strong> 
Take three characters from the left of s. You now have two &#39;a&#39; characters, and one &#39;b&#39; character.
Take five characters from the right of s. You now have four &#39;a&#39; characters, two &#39;b&#39; characters, and two &#39;c&#39; characters.
A total of 3 + 5 = 8 minutes is needed.
It can be proven that 8 is the minimum number of minutes needed.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;a&quot;, k = 1
<strong>Output:</strong> -1
<strong>Explanation:</strong> It is not possible to take one &#39;b&#39; or &#39;c&#39; so return -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of only the letters <code>&#39;a&#39;</code>, <code>&#39;b&#39;</code>, and <code>&#39;c&#39;</code>.</li>
	<li><code>0 &lt;= k &lt;= s.length</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int takeCharacters(string s, int k) {
    int count[3] = {};
    auto check = [&](){ return count[0] >= k && count[1] >= k && count[2] >= k; };
    int left;
    for(left = 0; left < s.length() && !check(); ++left) {
      count[s[left] - 'a'] += 1;
    }
    if(!check()) return -1;
    int answer = left;
    for(int right = s.length() - 1; right >= 0; --right) {
      count[s[right] - 'a'] += 1;
      while(check() && left > 0) {
        answer = min<int>(answer, left + s.length() - right);
        count[s[left - 1] - 'a'] -= 1;
        left -= 1;
      }
      if(left == 0 && check()) {
        answer = min<int>(answer, s.length() - right);
        break;
      }
    }
    return answer;
  }
};
```
