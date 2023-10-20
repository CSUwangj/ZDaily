+++
updated = 2023-10-20T13:09:02+08:00
title = "2023-10-20 Daily Challenge"
path = "2023-10-20-Daily-Challenge"
date = 2023-10-20T13:09:02+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/flatten-nested-list-iterator/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 20

## Description

**Flatten Nested List Iterator**

<p>You are given a nested list of integers <code>nestedList</code>. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.</p>

<p>Implement the <code>NestedIterator</code> class:</p>

<ul>
	<li><code>NestedIterator(List&lt;NestedInteger&gt; nestedList)</code> Initializes the iterator with the nested list <code>nestedList</code>.</li>
	<li><code>int next()</code> Returns the next integer in the nested list.</li>
	<li><code>boolean hasNext()</code> Returns <code>true</code> if there are still some integers in the nested list and <code>false</code> otherwise.</li>
</ul>

<p>Your code will be tested with the following pseudocode:</p>

<pre>
initialize iterator with nestedList
res = []
while iterator.hasNext()
    append iterator.next() to the end of res
return res
</pre>

<p>If <code>res</code> matches the expected flattened list, then your code will be judged as correct.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nestedList = [[1,1],2,[1,1]]
<strong>Output:</strong> [1,1,2,1,1]
<strong>Explanation:</strong> By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nestedList = [1,[4,[6]]]
<strong>Output:</strong> [1,4,6]
<strong>Explanation:</strong> By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nestedList.length &lt;= 500</code></li>
	<li>The values of the integers in the nested list is in the range <code>[-10<sup>6</sup>, 10<sup>6</sup>]</code>.</li>
</ul>


## Solution

``` cpp
class NestedIterator {
  vector<int> integers;
  int len;
  int i;
  void solve(NestedInteger &nestedInt) {
    if(nestedInt.isInteger()) {
      integers.push_back(nestedInt.getInteger());
      return;
    }
    for(auto &l : nestedInt.getList()) {
      solve(l);
    }
  }
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for(auto &nestedInt : nestedList) solve(nestedInt);
    len = integers.size();
    i = 0;
  }

  int next() {
    return integers[i++];
  }

  bool hasNext() {
    return i != len;
  }
};

// Accepted
// 43/43 cases passed (14 ms)
// Your runtime beats 84.39 % of cpp submissions
// Your memory usage beats 56.47 % of cpp submissions (13.1 MB)
```
