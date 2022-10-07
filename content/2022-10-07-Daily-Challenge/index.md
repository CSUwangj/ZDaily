+++
updated = 2022-10-07 18:14:00+08:00
title = "2022-10-07 Daily-Challenge"
path = "2022-10-07-Daily-Challenge"
date = 2022-10-07 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/my-calendar-iii/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 7

## Description

**My Calendar III**

A `k`-booking happens when `k` events have some non-empty intersection (i.e., there is some time that is common to all `k` events.)

You are given some events `[start, end)`, after each given event, return an integer `k` representing the maximum `k`-booking between all the previous events.

Implement the `MyCalendarThree` class:

- `MyCalendarThree()` Initializes the object.
- `int book(int start, int end)` Returns an integer `k` representing the largest integer such that there exists a `k`-booking in the calendar.

 

**Example 1:**

```
Input
["MyCalendarThree", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
Output
[null, 1, 1, 2, 3, 3, 3]

Explanation
MyCalendarThree myCalendarThree = new MyCalendarThree();
myCalendarThree.book(10, 20); // return 1, The first event can be booked and is disjoint, so the maximum k-booking is a 1-booking.
myCalendarThree.book(50, 60); // return 1, The second event can be booked and is disjoint, so the maximum k-booking is a 1-booking.
myCalendarThree.book(10, 40); // return 2, The third event [10, 40) intersects the first event, and the maximum k-booking is a 2-booking.
myCalendarThree.book(5, 15); // return 3, The remaining events cause the maximum K-booking to be only a 3-booking.
myCalendarThree.book(5, 10); // return 3
myCalendarThree.book(25, 55); // return 3
```

 

**Constraints:**

- `0 <= start < end <= 109`
- At most `400` calls will be made to `book`.

## Solution

``` cpp
class MyCalendarThree {
  map<int, int> count;
public:
  MyCalendarThree() {  }
  
  int book(int start, int end) {
    count[start] += 1;
    count[end] -= 1;
    int answer = 0;
    int current = 0;
    for(const auto &[pos, cnt] : count) {
      current += cnt;
      answer = max(answer, current);
    }
    return answer;
  }
};

// Accepted
// 98/98 cases passed (292 ms)
// Your runtime beats 22.72 % of cpp submissions
// Your memory usage beats 94.41 % of cpp submissions (262.3 MB)
```
