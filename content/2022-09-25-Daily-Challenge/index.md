+++
updated = 2022-09-25 18:14:00+08:00
title = "2022-09-25 Daily-Challenge"
path = "2022-09-25-Daily-Challenge"
date = 2022-09-25 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/design-circular-queue/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 25

## Description

**Design Circular Queue**

Design your  implementation of the circular queue. The circular queue is a linear  data structure in which the operations are performed based on FIFO  (First In First Out) principle and the last position is connected back  to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of  the spaces in front of the queue. In a normal queue, once the queue  becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the  space to store new values.

Implementation the `MyCircularQueue` class:

- `MyCircularQueue(k)` Initializes the object with the size of the queue to be `k`.
- `int Front()` Gets the front item from the queue. If the queue is empty, return `-1`.
- `int Rear()` Gets the last item from the queue. If the queue is empty, return `-1`.
- `boolean enQueue(int value)` Inserts an element into the circular queue. Return `true` if the operation is successful.
- `boolean deQueue()` Deletes an element from the circular queue. Return `true` if the operation is successful.
- `boolean isEmpty()` Checks whether the circular queue is empty or not.
- `boolean isFull()` Checks whether the circular queue is full or not.

You must solve the problem without using the built-in queue data structure in your programming language. 

 

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

## Solution

``` cpp
class MyCircularQueue {
  vector<int> container;
  int begin;
  int size;
  int capacity;
public:
  MyCircularQueue(int k): capacity(k) {
    container.resize(k);
    begin = 0;
    size = 0;
  }
  
  bool enQueue(int value) {
    if(size == capacity) return false;
    container[(begin + size) % capacity] = value;
    size += 1;
    return true;
  }
  
  bool deQueue() {
    if(!size) return false;
    begin = (begin + 1) % capacity;
    size -= 1;
    return true;
  }
  
  int Front() {
    if(!size) return -1;
    return container[begin];
  }
  
  int Rear() {
    if(!size) return -1;
    return container[(begin + size - 1) % capacity];
  }
  
  bool isEmpty() {
    return size == 0;
  }
  
  bool isFull() {
    return size == capacity; 
  }
};

// Accepted
// 58/58 cases passed (16 ms)
// Your runtime beats 97.99 % of cpp submissions
// Your memory usage beats 40.24 % of cpp submissions (16.9 MB)
```
