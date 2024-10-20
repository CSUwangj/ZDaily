+++
updated = 2024-10-20T10:36:31+08:00
title = "2024-10-20 Daily Challenge"
path = "2024-10-20-Daily-Challenge"
date = 2024-10-20T10:36:31+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/parsing-a-boolean-expression/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 20

## Description

**Parsing A Boolean Expression**

<p>A <strong>boolean expression</strong> is an expression that evaluates to either <code>true</code> or <code>false</code>. It can be in one of the following shapes:</p>

<ul>
	<li><code>&#39;t&#39;</code> that evaluates to <code>true</code>.</li>
	<li><code>&#39;f&#39;</code> that evaluates to <code>false</code>.</li>
	<li><code>&#39;!(subExpr)&#39;</code> that evaluates to <strong>the logical NOT</strong> of the inner expression <code>subExpr</code>.</li>
	<li><code>&#39;&amp;(subExpr<sub>1</sub>, subExpr<sub>2</sub>, ..., subExpr<sub>n</sub>)&#39;</code> that evaluates to <strong>the logical AND</strong> of the inner expressions <code>subExpr<sub>1</sub>, subExpr<sub>2</sub>, ..., subExpr<sub>n</sub></code> where <code>n &gt;= 1</code>.</li>
	<li><code>&#39;|(subExpr<sub>1</sub>, subExpr<sub>2</sub>, ..., subExpr<sub>n</sub>)&#39;</code> that evaluates to <strong>the logical OR</strong> of the inner expressions <code>subExpr<sub>1</sub>, subExpr<sub>2</sub>, ..., subExpr<sub>n</sub></code> where <code>n &gt;= 1</code>.</li>
</ul>

<p>Given a string <code>expression</code> that represents a <strong>boolean expression</strong>, return <em>the evaluation of that expression</em>.</p>

<p>It is <strong>guaranteed</strong> that the given expression is valid and follows the given rules.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> expression = &quot;&amp;(|(f))&quot;
<strong>Output:</strong> false
<strong>Explanation:</strong> 
First, evaluate |(f) --&gt; f. The expression is now &quot;&amp;(f)&quot;.
Then, evaluate &amp;(f) --&gt; f. The expression is now &quot;f&quot;.
Finally, return false.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> expression = &quot;|(f,f,f,t)&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> The evaluation of (false OR false OR false OR true) is true.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> expression = &quot;!(&amp;(f,t))&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> 
First, evaluate &amp;(f,t) --&gt; (false AND true) --&gt; false --&gt; f. The expression is now &quot;!(f)&quot;.
Then, evaluate !(f) --&gt; NOT false --&gt; true. We return true.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= expression.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li>expression[i] is one following characters: <code>&#39;(&#39;</code>, <code>&#39;)&#39;</code>, <code>&#39;&amp;&#39;</code>, <code>&#39;|&#39;</code>, <code>&#39;!&#39;</code>, <code>&#39;t&#39;</code>, <code>&#39;f&#39;</code>, and <code>&#39;,&#39;</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
  bool helper(const string &e, int &pos) {
    if(e[pos] == 't' || e[pos] == 'f') {
      pos += 1;
      return e[pos - 1] == 't';
    }
    if(e[pos] == '!') {
      pos += 2;
      bool result = !helper(e, pos);
      pos += 1;
      return result;
    }
    if(e[pos] == '&') {
      pos += 2;
      bool result = helper(e, pos);
      while(e[pos] == ',') {
        pos += 1;
        result &= helper(e, pos);
      }
      pos += 1;
      return result;
    }
    if(e[pos] == '|') {
      pos += 2;
      bool result = helper(e, pos);
      while(e[pos] == ',') {
        pos += 1;
        result |= helper(e, pos);
      }
      pos += 1;
      return result;
    }
    return false;
  }
public:
  bool parseBoolExpr(string expression) {
    int pos = 0;
    return helper(expression, pos);
  }
};
```
