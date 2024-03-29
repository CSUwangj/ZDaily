+++
updated = 2023-04-13T10:43:29+08:00
title = "2023-04-13 Daily Challenge"
path = "2023-04-13-Daily-Challenge"
date = 2023-04-13T10:43:29+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/validate-stack-sequences/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 13

## Description

**Validate Stack Sequences**

<p>Given two integer arrays <code>pushed</code> and <code>popped</code> each with distinct values, return <code>true</code><em> if this could have been the result of a sequence of push and pop operations on an initially empty stack, or </em><code>false</code><em> otherwise.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
<strong>Output:</strong> true
<strong>Explanation:</strong> We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -&gt; 4,
push(5),
pop() -&gt; 5, pop() -&gt; 3, pop() -&gt; 2, pop() -&gt; 1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
<strong>Output:</strong> false
<strong>Explanation:</strong> 1 cannot be popped before 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= pushed.length &lt;= 1000</code></li>
	<li><code>0 &lt;= pushed[i] &lt;= 1000</code></li>
	<li>All the elements of <code>pushed</code> are <strong>unique</strong>.</li>
	<li><code>popped.length == pushed.length</code></li>
	<li><code>popped</code> is a permutation of <code>pushed</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    vector<int> st;
    int pos = 0;
    int len = pushed.size();
    for(int i = 0; i < len; ++i) {
      while(pos < len && (st.empty() || st.back() != popped[i])) {
        st.push_back(pushed[pos]);
        pos += 1;
      }
      if(st.back() != popped[i]) return false;;
      st.pop_back();
    }
    return true;
  }
};

// Accepted
// 151/151 cases passed (4 ms)
// Your runtime beats 97.31 % of cpp submissions
// Your memory usage beats 59.16 % of cpp submissions (15.4 MB)
```
