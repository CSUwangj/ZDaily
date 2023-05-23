+++
updated = 2023-05-23T14:57:03+08:00
title = "2023-05-23 Daily Challenge"
path = "2023-05-23-Daily-Challenge"
date = 2023-05-23T14:57:03+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/kth-largest-element-in-a-stream/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 23

## Description

**Kth Largest Element in a Stream**

<p>Design a class to find the <code>k<sup>th</sup></code> largest element in a stream. Note that it is the <code>k<sup>th</sup></code> largest element in the sorted order, not the <code>k<sup>th</sup></code> distinct element.</p>

<p>Implement <code>KthLargest</code> class:</p>

<ul>
	<li><code>KthLargest(int k, int[] nums)</code> Initializes the object with the integer <code>k</code> and the stream of integers <code>nums</code>.</li>
	<li><code>int add(int val)</code> Appends the integer <code>val</code> to the stream and returns the element representing the <code>k<sup>th</sup></code> largest element in the stream.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;KthLargest&quot;, &quot;add&quot;, &quot;add&quot;, &quot;add&quot;, &quot;add&quot;, &quot;add&quot;]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
<strong>Output</strong>
[null, 4, 5, 5, 8, 8]

<strong>Explanation</strong>
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= val &lt;= 10<sup>4</sup></code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>add</code>.</li>
	<li>It is guaranteed that there will be at least <code>k</code> elements in the array when you search for the <code>k<sup>th</sup></code> element.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class KthLargest {
  priority_queue<int, vector<int>, greater<int>> pq;
public:
  KthLargest(int k, vector<int>& nums) {
    int len = nums.size();
    for(int i = 0; i < len && i < k; ++i) {
      pq.push(nums[i]);
    }
    for(int i = k; i < len; ++i) {
      pq.push(nums[i]);
      pq.pop();
    }
    if(len < k) pq.push(INT_MIN);
  }
  
  int add(int val) {
    pq.push(val);
    pq.pop();
    return pq.top();
  }
};

// Accepted
// 10/10 cases passed (20 ms)
// Your runtime beats 99.9 % of cpp submissions
// Your memory usage beats 17.93 % of cpp submissions (19.9 MB)
```
