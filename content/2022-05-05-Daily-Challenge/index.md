+++
updated = 2022-05-05 18:58:00+08:00
title = "2022-05-05 Daily-Challenge"
path = "2022-05-05-Daily-Challenge"
date = 2022-05-05 18:57:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/implement-stack-using-queues/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 5

## Description

**Implement Stack using Queues**

Implement a  last-in-first-out (LIFO) stack using only two queues. The implemented  stack should support all the functions of a normal stack (`push`, `top`, `pop`, and `empty`).

Implement the `MyStack` class:

- `void push(int x)` Pushes element x to the top of the stack.
- `int pop()` Removes the element on the top of the stack and returns it.
- `int top()` Returns the element on the top of the stack.
- `boolean empty()` Returns `true` if the stack is empty, `false` otherwise.

**Notes:**

- You must use **only** standard operations of a queue, which means that only `push to back`, `peek/pop from front`, `size` and `is empty` operations are valid.
- Depending on your language, the queue may not be supported  natively. You may simulate a queue using a list or deque (double-ended  queue) as long as you use only a queue's standard operations.

 

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
