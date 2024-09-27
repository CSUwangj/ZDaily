+++
updated = 2024-09-27T09:00:26+08:00
title = "2024-09-27 Daily Challenge"
path = "2024-09-27-Daily-Challenge"
date = 2024-09-27T09:00:26+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/my-calendar-ii/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 27

## Description

**My Calendar II**

<p>You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a <strong>triple booking</strong>.</p>

<p>A <strong>triple booking</strong> happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).</p>

<p>The event can be represented as a pair of integers <code>start</code> and <code>end</code> that represents a booking on the half-open interval <code>[start, end)</code>, the range of real numbers <code>x</code> such that <code>start &lt;= x &lt; end</code>.</p>

<p>Implement the <code>MyCalendarTwo</code> class:</p>

<ul>
	<li><code>MyCalendarTwo()</code> Initializes the calendar object.</li>
	<li><code>boolean book(int start, int end)</code> Returns <code>true</code> if the event can be added to the calendar successfully without causing a <strong>triple booking</strong>. Otherwise, return <code>false</code> and do not add the event to the calendar.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;MyCalendarTwo&quot;, &quot;book&quot;, &quot;book&quot;, &quot;book&quot;, &quot;book&quot;, &quot;book&quot;, &quot;book&quot;]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
<strong>Output</strong>
[null, true, true, true, false, true, true]

<strong>Explanation</strong>
MyCalendarTwo myCalendarTwo = new MyCalendarTwo();
myCalendarTwo.book(10, 20); // return True, The event can be booked. 
myCalendarTwo.book(50, 60); // return True, The event can be booked. 
myCalendarTwo.book(10, 40); // return True, The event can be double booked. 
myCalendarTwo.book(5, 15);  // return False, The event cannot be booked, because it would result in a triple booking.
myCalendarTwo.book(5, 10); // return True, The event can be booked, as it does not use time 10 which is already double booked.
myCalendarTwo.book(25, 55); // return True, The event can be booked, as the time in [25, 40) will be double booked with the third event, the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= start &lt; end &lt;= 10<sup>9</sup></code></li>
	<li>At most <code>1000</code> calls will be made to <code>book</code>.</li>
</ul>


## Solution

``` cpp
class MyCalendarTwo {
  using pi = pair<int, int>;
  vector<pi> calendar;
  int findIndex(int time) {
    int low = 0;
    int high = calendar.size();
    while(low < high) {
      int mid = (low + high) / 2;
      if(calendar[mid].first < time) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
public:
  MyCalendarTwo() { }
    
  bool book(int start, int end) {
    int startIndex = findIndex(start);
    int endIndex = findIndex(end);

    for(int i = startIndex; i < endIndex; ++i) {
      if(abs(calendar[i].second) > 1) return false;
    }

    int startIntersection = 1;
    if(startIndex > 0) {
      startIntersection = calendar[startIndex - 1].second + 1;
    }

    int endIntersection = -1;
    if(endIndex < calendar.size()) {
      endIntersection = calendar[endIndex].second - 1;
    }
    if(startIntersection > 2 || -endIntersection > 2) {
      return false;
    }
    for(int i = startIndex; i < endIndex; ++i) {
      calendar[i].second += 1;
    }

    calendar.insert(calendar.begin() + startIndex, {start, startIntersection});
    calendar.insert(calendar.begin() + endIndex + 1, {end, endIntersection});

    return true;
  }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
```
