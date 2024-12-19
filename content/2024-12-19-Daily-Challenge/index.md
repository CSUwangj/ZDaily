+++
updated = 2024-12-19T22:38:32+08:00
title = "2024-12-19 Daily Challenge"
path = "2024-12-19-Daily-Challenge"
date = 2024-12-19T22:38:32+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/max-chunks-to-make-sorted/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 19

## Description

**Max Chunks To Make Sorted**

<p>You are given an integer array <code>arr</code> of length <code>n</code> that represents a permutation of the integers in the range <code>[0, n - 1]</code>.</p>

<p>We split <code>arr</code> into some number of <strong>chunks</strong> (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.</p>

<p>Return <em>the largest number of chunks we can make to sort the array</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [4,3,2,1,0]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn&#39;t sorted.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,0,2,3,4]
<strong>Output:</strong> 4
<strong>Explanation:</strong>
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == arr.length</code></li>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>0 &lt;= arr[i] &lt; n</code></li>
	<li>All the elements of <code>arr</code> are <strong>unique</strong>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxChunksToSorted(vector<int>& arr) {
    vector<int> newArr(arr.begin(), arr.end());
    sort(newArr.begin(), newArr.end());
    map<int, set<int>> positions;
    for(int i = 0; i < arr.size(); ++i) {
      positions[newArr[i]].insert(i);
    }
    int answer = 0;
    int end = -1;
    for(int i = 0; i < arr.size(); ++i) {
      int pos = *positions[arr[i]].begin();
      positions[arr[i]].erase(pos);
      end = max(end, pos);
      if(end == i) {
        answer += 1;
        end = -1;
      }
    }
    return answer;
  }
};

// Accepted
// 52/52 cases passed (3 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 20.72 % of cpp submissions (9.3 MB)
```
