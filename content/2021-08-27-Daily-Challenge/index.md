+++
title = "2021-08-27 Daily-Challenge"
path = "2021-08-27-Daily-Challenge"
date = 2021-08-27 18:46:15+08:00
updated = 2021-08-27 19:10:54+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3920/) with `cpp`.

<!-- more -->

# Implement Stack using Queues

## Description

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (`push`, `top`, `pop`, and `empty`).

Implement the `MyStack` class:

- `void push(int x)` Pushes element x to the top of the stack.
- `int pop()` Removes the element on the top of the stack and returns it.
- `int top()` Returns the element on the top of the stack.
- `boolean empty()` Returns `true` if the stack is empty, `false` otherwise.

**Notes:**

- You must use **only** standard operations of a queue, which means that only `push to back`, `peek/pop from front`, `size` and `is empty` operations are valid.
- Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.

 

**Example 1:**

```
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
```

 

**Constraints:**

- `1 <= x <= 9`
- At most `100` calls will be made to `push`, `pop`, `top`, and `empty`.
- All the calls to `pop` and `top` are valid.

 

**Follow-up:** Can you implement the stack using only one queue?

## Solution

``` cpp
class MyStack {
  queue<int> container;
public:
  /** Initialize your data structure here. */
  MyStack() { }
  
  /** Push element x onto stack. */
  void push(int x) {
    int sz = container.size();
    container.push(x);
    while(sz--) {
      container.push(container.front());
      container.pop();
    }
  }
  
  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int val = container.front();
    container.pop();
    return val;
  }
  
  /** Get the top element. */
  int top() {
    return container.front();
  }
  
  /** Returns whether the stack is empty. */
  bool empty() {
    return container.empty();
  }
};

// Accepted
// 16/16 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 98.89 % of cpp submissions (6.7 MB)
```

# August LeetCoding Challenge 27

## Description

**Verify Preorder Serialization of a Binary Tree**

One way to serialize a binary tree is to use **preorder traversal**. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as `'#'`.

![img](https://assets.leetcode.com/uploads/2021/03/12/pre-tree.jpg)

For example, the above binary tree can be serialized to the string `"9,3,4,#,#,1,#,#,2,#,6,#,#"`, where `'#'` represents a null node.

Given a string of comma-separated values `preorder`, return `true` if it is a correct preorder traversal serialization of a binary tree.

It is **guaranteed** that each comma-separated value in the string must be either an integer or a character `'#'` representing null pointer.

You may assume that the input format is always valid.

- For example, it could never contain two consecutive commas, such as `"1,,3"`.

**Note:** You are not allowed to reconstruct the tree.

 

**Example 1:**

```
Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
```

**Example 2:**

```
Input: preorder = "1,#"
Output: false
```

**Example 3:**

```
Input: preorder = "9,#,#,1"
Output: false
```

 

**Constraints:**

- `1 <= preorder.length <= 10^4`
- `preoder` consist of integers in the range `[0, 100]` and `'#'` separated by commas `','`.


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
  bool isValidSerialization(string preorder) {
    int count = 1;
    int len = preorder.length();
    for (int i = 0; i < len; ++i) {
      if(preorder[i] == '#') {
        count -= 1;
        i += 1;
        if(count == 0 && i != len) return false;
      } else {
        while(i < len && preorder[i] != ',') {
          i += 1;
        }
        count += 1;
      }
    }
    return !count;
  }
};

// Accepted
// 151/151 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 66.91 % of cpp submissions (6.8 MB)
```
