+++
updated = 2025-01-12T14:37:15+08:00
title = "2025-01-12 Daily Challenge"
path = "2025-01-12-Daily-Challenge"
date = 2025-01-12T14:37:15+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 12

## Description

**Check if a Parentheses String Can Be Valid**

<p>A parentheses string is a <strong>non-empty</strong> string consisting only of <code>&#39;(&#39;</code> and <code>&#39;)&#39;</code>. It is valid if <strong>any</strong> of the following conditions is <strong>true</strong>:</p>

<ul>
	<li>It is <code>()</code>.</li>
	<li>It can be written as <code>AB</code> (<code>A</code> concatenated with <code>B</code>), where <code>A</code> and <code>B</code> are valid parentheses strings.</li>
	<li>It can be written as <code>(A)</code>, where <code>A</code> is a valid parentheses string.</li>
</ul>

<p>You are given a parentheses string <code>s</code> and a string <code>locked</code>, both of length <code>n</code>. <code>locked</code> is a binary string consisting only of <code>&#39;0&#39;</code>s and <code>&#39;1&#39;</code>s. For <strong>each</strong> index <code>i</code> of <code>locked</code>,</p>

<ul>
	<li>If <code>locked[i]</code> is <code>&#39;1&#39;</code>, you <strong>cannot</strong> change <code>s[i]</code>.</li>
	<li>But if <code>locked[i]</code> is <code>&#39;0&#39;</code>, you <strong>can</strong> change <code>s[i]</code> to either <code>&#39;(&#39;</code> or <code>&#39;)&#39;</code>.</li>
</ul>

<p>Return <code>true</code> <em>if you can make <code>s</code> a valid parentheses string</em>. Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/06/eg1.png" style="width: 311px; height: 101px;" />
<pre>
<strong>Input:</strong> s = &quot;))()))&quot;, locked = &quot;010100&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> locked[1] == &#39;1&#39; and locked[3] == &#39;1&#39;, so we cannot change s[1] or s[3].
We change s[0] and s[4] to &#39;(&#39; while leaving s[2] and s[5] unchanged to make s valid.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;()()&quot;, locked = &quot;0000&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> We do not need to make any changes because s is already valid.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;)&quot;, locked = &quot;0&quot;
<strong>Output:</strong> false
<strong>Explanation:</strong> locked permits us to change s[0]. 
Changing s[0] to either &#39;(&#39; or &#39;)&#39; will not make s valid.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == s.length == locked.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either <code>&#39;(&#39;</code> or <code>&#39;)&#39;</code>.</li>
	<li><code>locked[i]</code> is either <code>&#39;0&#39;</code> or <code>&#39;1&#39;</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool canBeValid(string s, string locked) {
    if(s.length() & 1) return false;

    stack<int> open, unlocked;
    for(int i = 0; i < s.length(); ++i) {
      if(locked[i] == '0') {
        unlocked.push(i);
      } else if (s[i] == '(') {
        open.push(i);
      } else if (s[i] == ')') {
        if(open.size()) {
          open.pop();
        } else if(unlocked.size()) {
          unlocked.pop();
        } else {
          return false;
        }
      }
    }

    while(open.size() && unlocked.size() && open.top() < unlocked.top()) {
      open.pop();
      unlocked.pop();
    }

    if(open.size()) return false;
    return true;
  }
};

// Accepted
// 258/258 cases passed (20 ms)
// Your runtime beats 25.13 % of cpp submissions
// Your memory usage beats 16.75 % of cpp submissions (34.8 MB)
```
