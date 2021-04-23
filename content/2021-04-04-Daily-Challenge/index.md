+++
title = "2021-04-04 Daily-Challenge"
path = "2021-04-04-Daily-Challenge"
date = 2021-04-04 07:17:02+08:00
updated = 2021-04-04 21:45:14+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/featured/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3696/) with `cpp`.

<!-- more -->

# LeetCode Review

## Longest Valid Parentheses

``` cpp
template<typename T>
class reversion_wrapper {
private:
  T& iterable;
public:
  explicit reversion_wrapper(T& iterable): iterable{iterable} {}
  auto begin() const { return std::rbegin(iterable); }
  auto end() const { return std::rend(iterable); }
};

class Solution {
public:
  int longestValidParentheses(string s) {
    int left = 0;
    int right = 0;
    int answer = 0;
    for(auto c : s) {
      if(c == '(') {
        left += 1;
      } else {
        right += 1;
        if(left == right) {
          answer = max(answer, left << 1);
        } else if (left < right) {
          left = 0;
          right = 0;
        }
      }
    }
    left = 0;
    right = 0;
    for(auto c : reversion_wrapper(s)) {
      if(c == ')') {
        right += 1;
      } else {
        left += 1;
        if(left == right) {
          answer = max(answer, left << 1);
        } else if(left > right) {
          left = 0;
          right = 0;
        }
      }
    }
    return answer;
  }
};
```

# April LeetCoding Challenge4

## Description

**Design Circular Queue**

## Description

Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implementation the `MyCircularQueue` class:

- `MyCircularQueue(k)` Initializes the object with the size of the queue to be `k`.
- `int Front()` Gets the front item from the queue. If the queue is empty, return `-1`.
- `int Rear()` Gets the last item from the queue. If the queue is empty, return `-1`.
- `boolean enQueue(int value)` Inserts an element into the circular queue. Return `true` if the operation is successful.
- `boolean deQueue()` Deletes an element from the circular queue. Return `true` if the operation is successful.
- `boolean isEmpty()` Checks whether the circular queue is empty or not.
- `boolean isFull()` Checks whether the circular queue is full or not.

 

**Example 1:**

```
Input
["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 3, true, true, true, 4]

Explanation
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4
```

 

**Constraints:**

- `1 <= k <= 1000`
- `0 <= value <= 1000`
- At most `3000` calls will be made to `enQueue`, `deQueue`, `Front`, `Rear`, `isEmpty`, and `isFull`.

 

**Follow up:** Could you solve the problem without using the built-in queue? 

## Solution

``` cpp
class MyCircularQueue {
  int *buffer;
  int begin;
  int capacity;
  int size;
public:
  MyCircularQueue(int k): capacity(k), size(0), begin(0) {
    buffer = new int[capacity];
  }
  
  ~MyCircularQueue() {
    delete[] buffer;
  }

  bool enQueue(int value) {
    if(isFull()) return false;
    buffer[(begin + size) % capacity] = value;
    size += 1;
    return true;
  }

  bool deQueue() {
    if(!size) return false;
    begin += 1;
    begin %= capacity;
    size -= 1;
    return true;
  }

  int Front() {
    if(!size) return -1;
    return buffer[begin];
  }

  int Rear() {
    if(!size) return -1;
    return buffer[(begin + size - 1) % capacity];
  }

  bool isEmpty() {
    return !size;
  }

  bool isFull() {
    return size == capacity;
  }
};
```
