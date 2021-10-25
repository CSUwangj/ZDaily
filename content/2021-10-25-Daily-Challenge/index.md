+++
title = "2021-10-25 Daily-Challenge"
path = "2021-10-25-Daily-Challenge"
date = 2021-10-25 20:03:11+08:00
updated = 2021-10-25 20:22:54+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/min-stack/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 25

## Description

**Min Stack**

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the `MinStack` class:

- `MinStack()` initializes the stack object.
- `void push(int val)` pushes the element `val` onto the stack.
- `void pop()` removes the element on the top of the stack.
- `int top()` gets the top element of the stack.
- `int getMin()` retrieves the minimum element in the stack.

 

**Example 1:**

```
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= val &lt;= 2<sup>31</sup> - 1</code></li>
	<li>Methods <code>pop</code>, <code>top</code> and <code>getMin</code> operations will always be called on <strong>non-empty</strong> stacks.</li>
	<li>At most <code>3 * 10<sup>4</sup></code> calls will be made to <code>push</code>, <code>pop</code>, <code>top</code>, and <code>getMin</code>.</li>
</ul>

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class MinStack {
  vector<int> st;
  vector<int> minSt;
public:
  /** initialize your data structure here. */
  MinStack(){}
  
  void push(int val) {
    st.push_back(val);
    if(minSt.empty() || val <= minSt.back()) {
      minSt.push_back(val);
    }
  }
  
  void pop() {
    if(st.back() == minSt.back()) {
      minSt.pop_back();
    }
    st.pop_back();
  }
  
  int top() {
    return st.back();
  }
  
  int getMin() {
    return minSt.back();
  }
};

// Accepted
// 31/31 cases passed (12 ms)
// Your runtime beats 99.73 % of cpp submissions
// Your memory usage beats 33.29 % of cpp submissions (16.5 MB)
```
