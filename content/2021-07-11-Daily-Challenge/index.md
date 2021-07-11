+++
title = "2021-07-11 Daily-Challenge"
path = "2021-07-11-Daily-Challenge"
date = 2021-07-11 22:38:37+08:00
updated = 2021-07-11 23:21:35+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3810/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge11

## Description

**Find Median from Data Stream**

The **median** is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

- For example, for `arr = [2,3,4]`, the median is `3`.
- For example, for `arr = [2,3]`, the median is `(2 + 3) / 2 = 2.5`.

Implement the MedianFinder class:

- `MedianFinder()` initializes the `MedianFinder` object.
- `void addNum(int num)` adds the integer `num` from the data stream to the data structure.
- `double findMedian()` returns the median of all elements so far. Answers within `10-5` of the actual answer will be accepted.

 

**Example 1:**

```
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
```

 

**Constraints:**

<ul>
	<li><code>-10<sup>5</sup> &lt;= num &lt;= 10<sup>5</sup></code></li>
	<li>There will be at least one element in the data structure before calling <code>findMedian</code>.</li>
	<li>At most <code>5 * 10<sup>4</sup></code> calls will be made to <code>addNum</code> and <code>findMedian</code>.</li>
</ul>

 

**Follow up:**

- If all integer numbers from the stream are in the range `[0, 100]`, how would you optimize your solution?
- If `99%` of all integer numbers from the stream are in the range `[0, 100]`, how would you optimize your solution?

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class MedianFinder {
  priority_queue<int> greaterQ;
  priority_queue<int, vector<int>, greater<int>> lessQ;
public:
  /** initialize your data structure here. */
  MedianFinder() { }
  
  void addNum(int num) {
    if(greaterQ.size() && greaterQ.top() <= num) {
      lessQ.push(num);
    } else {
      if(greaterQ.size()) {
        lessQ.push(greaterQ.top());
        greaterQ.pop();
      }
      greaterQ.push(num);
    }
    if(lessQ.size() > greaterQ.size()) {
      greaterQ.push(lessQ.top());
      lessQ.pop();
    }
  }
  
  double findMedian() {
    if(greaterQ.size() > lessQ.size()) {
      return greaterQ.top();
    } else {
      return (greaterQ.top() + lessQ.top()) / 2.0;
    }
  }
};

// Accepted
// 18/18 cases passed (180 ms)
// Your runtime beats 15.97 % of cpp submissions
// Your memory usage beats 20.18 % of cpp submissions (47.1 MB)
```

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
#define lowbit(x) (x & (-x))
const int SIZE = 200002;
int BITS[SIZE];
void add(int x) {
  while(x < SIZE) {
    BITS[x] += 1;
    x += lowbit(x);
  }
}
int sum(int x) {
  int result = 0;
  while(x) {
    result += BITS[x];
    x -= lowbit(x);
  }
  return result;
}
class MedianFinder {
  int size = 0;
  int low = INT_MAX;
  int high = INT_MIN;
  int get(int cnt) {
    int start = low;
    int end = high;
    while(start < end) {
      int mid = (start + end) >> 1;
      if(sum(mid) < cnt) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }
    return start;
  }
public:
  /** initialize your data structure here. */
  MedianFinder() { 
    memset(BITS, 0, sizeof(BITS));
  }
  
  void addNum(int num) {
    low = min(low, num + 100001);
    high = max(high, num + 100001);
    size += 1;
    add(num + 100001);
  }
  
  double findMedian() {
    if(low == high) return low - 100001;
    if(size & 1) return get(size / 2 + 1) - 100001;
    return (get(size / 2) + get(size / 2 + 1)) / 2.0 - 100001;
  }
};

// Accepted
// 18/18 cases passed (88 ms)
// Your runtime beats 97.8 % of cpp submissions
// Your memory usage beats 19.92 % of cpp submissions (47.1 MB)
```
