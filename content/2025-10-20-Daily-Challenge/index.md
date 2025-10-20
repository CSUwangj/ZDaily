+++
updated = 2025-10-20T16:59:20+02:00
title = "2025-10-20 Daily Challenge"
path = "2025-10-20-Daily-Challenge"
date = 2025-10-20T16:59:20+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/final-value-of-variable-after-performing-operations/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 20

## Description

**Final Value of Variable After Performing Operations**

<p>There is a programming language with only <strong>four</strong> operations and <strong>one</strong> variable <code>X</code>:</p>

<ul>
	<li><code>++X</code> and <code>X++</code> <strong>increments</strong> the value of the variable <code>X</code> by <code>1</code>.</li>
	<li><code>--X</code> and <code>X--</code> <strong>decrements</strong> the value of the variable <code>X</code> by <code>1</code>.</li>
</ul>

<p>Initially, the value of <code>X</code> is <code>0</code>.</p>

<p>Given an array of strings <code>operations</code> containing a list of operations, return <em>the <strong>final </strong>value of </em><code>X</code> <em>after performing all the operations</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> operations = [&quot;--X&quot;,&quot;X++&quot;,&quot;X++&quot;]
<strong>Output:</strong> 1
<strong>Explanation:</strong>&nbsp;The operations are performed as follows:
Initially, X = 0.
--X: X is decremented by 1, X =  0 - 1 = -1.
X++: X is incremented by 1, X = -1 + 1 =  0.
X++: X is incremented by 1, X =  0 + 1 =  1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> operations = [&quot;++X&quot;,&quot;++X&quot;,&quot;X++&quot;]
<strong>Output:</strong> 3
<strong>Explanation: </strong>The operations are performed as follows:
Initially, X = 0.
++X: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
X++: X is incremented by 1, X = 2 + 1 = 3.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> operations = [&quot;X++&quot;,&quot;++X&quot;,&quot;--X&quot;,&quot;X--&quot;]
<strong>Output:</strong> 0
<strong>Explanation:</strong>&nbsp;The operations are performed as follows:
Initially, X = 0.
X++: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
--X: X is decremented by 1, X = 2 - 1 = 1.
X--: X is decremented by 1, X = 1 - 1 = 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= operations.length &lt;= 100</code></li>
	<li><code>operations[i]</code> will be either <code>&quot;++X&quot;</code>, <code>&quot;X++&quot;</code>, <code>&quot;--X&quot;</code>, or <code>&quot;X--&quot;</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int finalValueAfterOperations(vector<string>& operations) {
    int value = 0;
    for(const auto &op : operations) {
      if(op[1] == '+') {
        value += 1;
      } else {
        value -= 1;
      }
    }
    return value;
  }
};

// Accepted
// 259/259 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 42.92 % of cpp submissions (17.7 MB)
```
