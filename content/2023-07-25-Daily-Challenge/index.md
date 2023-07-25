+++
updated = 2023-07-25T11:22:48+08:00
title = "2023-07-25 Daily Challenge"
path = "2023-07-25-Daily-Challenge"
date = 2023-07-25T11:22:48+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/peak-index-in-a-mountain-array/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 25

## Description

**Peak Index in a Mountain Array**

<p>An array <code>arr</code> a <strong>mountain</strong> if the following properties hold:</p>

<ul>
	<li><code>arr.length &gt;= 3</code></li>
	<li>There exists some <code>i</code> with <code>0 &lt; i &lt; arr.length - 1</code> such that:
	<ul>
		<li><code>arr[0] &lt; arr[1] &lt; ... &lt; arr[i - 1] &lt; arr[i] </code></li>
		<li><code>arr[i] &gt; arr[i + 1] &gt; ... &gt; arr[arr.length - 1]</code></li>
	</ul>
	</li>
</ul>

<p>Given a mountain array <code>arr</code>, return the index <code>i</code> such that <code>arr[0] &lt; arr[1] &lt; ... &lt; arr[i - 1] &lt; arr[i] &gt; arr[i + 1] &gt; ... &gt; arr[arr.length - 1]</code>.</p>

<p>You must solve it in <code>O(log(arr.length))</code> time complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [0,1,0]
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [0,2,1,0]
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> arr = [0,10,5,2]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>arr</code> is <strong>guaranteed</strong> to be a mountain array.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int len = arr.size();
    arr.push_back(-1);
    int low = 0;
    int high = len - 1;
    while(low < high) {
      int mid = (low + high) / 2;
      if(arr[mid] < arr[mid + 1]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};

// Accepted
// 42/42 cases passed (69 ms)
// Your runtime beats 99.98 % of cpp submissions
// Your memory usage beats 40.39 % of cpp submissions (59.7 MB)
```
