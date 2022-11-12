+++
updated = 2022-11-12T12:35:25+08:00
title = "2022-11-12 Daily Challenge"
path = "2022-11-12-Daily-Challenge"
date = 2022-11-12T12:35:25+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/find-median-from-data-stream/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 12

## Description

**Find Median from Data Stream**

<p>The <strong>median</strong> is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.</p>

<ul>
	<li>For example, for <code>arr = [2,3,4]</code>, the median is <code>3</code>.</li>
	<li>For example, for <code>arr = [2,3]</code>, the median is <code>(2 + 3) / 2 = 2.5</code>.</li>
</ul>

<p>Implement the MedianFinder class:</p>

<ul>
	<li><code>MedianFinder()</code> initializes the <code>MedianFinder</code> object.</li>
	<li><code>void addNum(int num)</code> adds the integer <code>num</code> from the data stream to the data structure.</li>
	<li><code>double findMedian()</code> returns the median of all elements so far. Answers within <code>10<sup>-5</sup></code> of the actual answer will be accepted.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;MedianFinder&quot;, &quot;addNum&quot;, &quot;addNum&quot;, &quot;findMedian&quot;, &quot;addNum&quot;, &quot;findMedian&quot;]
[[], [1], [2], [], [3], []]
<strong>Output</strong>
[null, null, null, 1.5, null, 2.0]

<strong>Explanation</strong>
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-10<sup>5</sup> &lt;= num &lt;= 10<sup>5</sup></code></li>
	<li>There will be at least one element in the data structure before calling <code>findMedian</code>.</li>
	<li>At most <code>5 * 10<sup>4</sup></code> calls will be made to <code>addNum</code> and <code>findMedian</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>If all integer numbers from the stream are in the range <code>[0, 100]</code>, how would you optimize your solution?</li>
	<li>If <code>99%</code> of all integer numbers from the stream are in the range <code>[0, 100]</code>, how would you optimize your solution?</li>
</ul>


## Solution

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

// 21/21 cases passed (363 ms)
// Your runtime beats 90.42 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (115.3 MB)
```
