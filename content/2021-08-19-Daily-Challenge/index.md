+++
title = "2021-08-19 Daily-Challenge"
path = "2021-08-19-Daily-Challenge"
date = 2021-08-19 17:57:56+08:00
updated = 2021-08-19 18:10:38+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Min Stack](https://leetcode.com/problems/min-stack/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3893/) with `cpp`.

<!-- more -->

# Min Stack

## Description

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the `MinStack` class:

- `MinStack()` initializes the stack object.
- `void push(val)` pushes the element `val` onto the stack.
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

 

**Constraints:**

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

# August LeetCoding Challenge 19

## Description

**Maximum Product of Splitted Binary Tree**

Given the `root` of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return *the maximum product of the sums of the two subtrees*. Since the answer may be too large, return it **modulo** `109 + 7`.

**Note** that you need to maximize the answer before taking the mod and not after taking it.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/01/21/sample_1_1699.png)

```
Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/01/21/sample_2_1699.png)

```
Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
```

**Example 3:**

```
Input: root = [2,3,9,10,7,8,6,5,4,11,1]
Output: 1025
```

**Example 4:**

```
Input: root = [1,1]
Output: 1
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[2, 5 * 10^4]`.
- `1 <= Node.val <= 10^4`


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
const int MOD = 1e9 + 7;
class Solution {
  int sum = 0;
  int cur = 0;
  void add(TreeNode *root) {
    if(!root) return;
    sum += root->val;
    add(root->left);
    add(root->right);
  }
  int solve(TreeNode *root) {
    if(!root) return 0;
    int left = solve(root->left);
    int right = solve(root->right);
    if(abs(left + right + root->val - sum / 2) < abs(cur - sum / 2)) {
      cur = left + right + root->val;
    }
    if (abs(left - sum / 2) < abs(cur - sum / 2)) {
      cur = left;
    }
    if (abs(right - sum / 2) < abs(cur - sum / 2)) {
      cur = right;
    }
    return left + right + root->val;
  }
public:
  int maxProduct(TreeNode* root) {
    add(root);
    solve(root);
    return 1LL * (sum - cur) * cur % MOD;
  }
};

// Accepted
// 54/54 cases passed (84 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 63.53 % of cpp submissions (77.5 MB)
```
