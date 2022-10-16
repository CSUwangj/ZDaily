+++
updated = 2022-04-25 19:58:00+08:00
title = "2022-04-25 Daily-Challenge"
path = "2022-04-25-Daily-Challenge"
date = 2022-04-25 19:57:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/peeking-iterator/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 25

## Description

**Peeking Iterator**

Design an iterator that supports the `peek` operation on an existing iterator in addition to the `hasNext` and the `next` operations.

Implement the `PeekingIterator` class:

- `PeekingIterator(Iterator<int> nums)` Initializes the object with the given integer iterator `iterator`.
- `int next()` Returns the next element in the array and moves the pointer to the next element.
- `boolean hasNext()` Returns `true` if there are still elements in the array.
- `int peek()` Returns the next element in the array **without** moving the pointer.

**Note:** Each language may have a different implementation of the constructor and `Iterator`, but they all support the `int next()` and `boolean hasNext()` functions.

 

**Example 1:**

```
Input
["PeekingIterator", "next", "peek", "next", "next", "hasNext"]
[[[1, 2, 3]], [], [], [], [], []]
Output
[null, 1, 2, 2, 3, false]

Explanation
PeekingIterator peekingIterator = new PeekingIterator([1, 2, 3]); // [1,2,3]
peekingIterator.next();    // return 1, the pointer moves to the next element [1,2,3].
peekingIterator.peek();    // return 2, the pointer does not move [1,2,3].
peekingIterator.next();    // return 2, the pointer moves to the next element [1,2,3]
peekingIterator.next();    // return 3, the pointer moves to the next element [1,2,3]
peekingIterator.hasNext(); // return False
```

 

**Constraints:**

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 1000`
- All the calls to `next` and `peek` are valid.
- At most `1000` calls will be made to `next`, `hasNext`, and `peek`.

 

**Follow up:** How would you extend your design to be generic and work with all types, not just integer?

## Solution

``` cpp
class PeekingIterator : public Iterator {
  int num;
  bool has;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
      has = Iterator::hasNext();
      if(has) num = Iterator::next();
    }
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
      return num;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
    int cur = num;
    has = Iterator::hasNext();
    if(has) num = Iterator::next();
    return cur;
	}
	
  bool hasNext() const {
    return has;
  }
};

// Accepted
// 14/14 cases passed (4 ms)
// Your runtime beats 59.03 % of cpp submissions
// Your memory usage beats 72 % of cpp submissions (7.5 MB)
```
