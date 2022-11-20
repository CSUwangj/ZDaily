+++
updated = 2022-11-20T15:15:34+08:00
title = "2022-11-20 Daily Challenge"
path = "2022-11-20-Daily-Challenge"
date = 2022-11-20T15:15:34+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/basic-calculator/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 20

## Description

**Basic Calculator**

<p>Given a string <code>s</code> representing a valid expression, implement a basic calculator to evaluate it, and return <em>the result of the evaluation</em>.</p>

<p><strong>Note:</strong> You are <strong>not</strong> allowed to use any built-in function which evaluates strings as mathematical expressions, such as <code>eval()</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;1 + 1&quot;
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot; 2-1 + 2 &quot;
<strong>Output:</strong> 3
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;(1+(4+5+2)-3)+(6+8)&quot;
<strong>Output:</strong> 23
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>s</code> consists of digits, <code>&#39;+&#39;</code>, <code>&#39;-&#39;</code>, <code>&#39;(&#39;</code>, <code>&#39;)&#39;</code>, and <code>&#39; &#39;</code>.</li>
	<li><code>s</code> represents a valid expression.</li>
	<li><code>&#39;+&#39;</code> is <strong>not</strong> used as a unary operation (i.e., <code>&quot;+1&quot;</code> and <code>&quot;+(2 + 3)&quot;</code> is invalid).</li>
	<li><code>&#39;-&#39;</code> could be used as a unary operation (i.e., <code>&quot;-1&quot;</code> and <code>&quot;-(2 + 3)&quot;</code> is valid).</li>
	<li>There will be no two consecutive operators in the input.</li>
	<li>Every number and running calculation will fit in a signed 32-bit integer.</li>
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
  bool shouldCompute(char current, char last) {
    if(current == '(') return false;
    if((current == '+' || current == '-') && last != '(') return true;
    if(last == '*' || last == '/') return true;
    return false;
  }
  void compute(stack<int> &n, stack<char> &op) {
    char o = op.top();
    op.pop();
    int op2 = n.top();
    n.pop();
    if(o == 'u') {
      n.push(-op2);
      return;
    }
    int op1 = n.top();
    n.pop();
    // cout << op1 << ' '<< o << " " << op2 << endl;
    switch(o){
      case '+':
        n.push(op1+op2);
        break;
      case '-':
        n.push(op1-op2);
        break;
      case '*':
        n.push(op1*op2);
        break;
      case '/':
        n.push(op1/op2);
        break;
    }
  }
public:
  int calculate(string s) {
    int curNum = 0;
    stack<int> n;
    stack<char> op;
    bool inNum = false;
    bool inCompute = false;
    bool negative = false;
    // cout << "$$$$$$$$$$$$$$$$$$$$" << endl;
    for(auto c : s) {
      if(c == ' ') continue;
      if(inNum && !isdigit(c)) {
        if(negative) curNum = -curNum;
        // cout << curNum << endl;
        n.push(curNum);
        curNum = 0;
        inNum = false;
        negative = false;
      }
      if(!inCompute && !inNum && c == '-') {
        op.push('u');
      } else if(isdigit(c)) {
        curNum *= 10;
        curNum += c - '0';
        inNum = true;
      } else if(c == ')') {
        while(op.size() && op.top() != '(') {
          compute(n, op);
        }
        op.pop();
      } else {
        while(op.size() && shouldCompute(c, op.top())) {
          compute(n, op);
        }
        op.push(c);
      }
      inCompute = c != '(';
    }
    if(inNum) n.push(curNum);
    while(op.size()) {
      compute(n, op);
    }
    return n.top();
  }
};

// Accepted
// 44/44 cases passed (26 ms)
// Your runtime beats 43.62 % of cpp submissions
// Your memory usage beats 28.22 % of cpp submissions (9.4 MB)
```
