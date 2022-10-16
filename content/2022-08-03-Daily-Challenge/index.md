+++
updated = 2022-08-03 18:14:00+08:00
title = "2022-08-03 Daily-Challenge"
path = "2022-08-03-Daily-Challenge"
date = 2022-08-03 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/my-calendar-i/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 3

## Description

**My Calendar I**

You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a **double booking**.

A **double booking** happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers `start` and `end` that represents a booking on the half-open interval `[start, end)`, the range of real numbers `x` such that `start <= x < end`.

Implement the `MyCalendar` class:

- `MyCalendar()` Initializes the calendar object.
- `boolean book(int start, int end)` Returns `true` if the event can be added to the calendar successfully without causing a **double booking**. Otherwise, return `false` and do not add the event to the calendar.

 

**Example 1:**

```
Input
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
Output
[null, true, false, true]

Explanation
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.
```

 

**Constraints:**

- `0 <= start < end <= 10&9`
- At most `1000` calls will be made to `book`.

## Solution

``` cpp
class MyCalendar {
  set<pair<int, int>> times;
public:
  MyCalendar(){}
  
  bool book(int start, int end) {
    auto it = times.upper_bound({start, end});
    if(it != times.end() && it->second < end) return false;
    times.insert({end, start});
    return true;
  }
};

// Accepted
// 107/107 cases passed (167 ms)
// Your runtime beats 51.09 % of cpp submissions
// Your memory usage beats 31.77 % of cpp submissions (38.9 MB)
```
