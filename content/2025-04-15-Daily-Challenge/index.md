+++
updated = 2025-04-15T12:36:35+08:00
title = "2025-04-15 Daily Challenge"
path = "2025-04-15-Daily-Challenge"
date = 2025-04-15T12:36:35+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/count-good-triplets-in-an-array/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 15

## Description

**Count Good Triplets in an Array**

<p>You are given two <strong>0-indexed</strong> arrays <code>nums1</code> and <code>nums2</code> of length <code>n</code>, both of which are <strong>permutations</strong> of <code>[0, 1, ..., n - 1]</code>.</p>

<p>A <strong>good triplet</strong> is a set of <code>3</code> <strong>distinct</strong> values which are present in <strong>increasing order</strong> by position both in <code>nums1</code> and <code>nums2</code>. In other words, if we consider <code>pos1<sub>v</sub></code> as the index of the value <code>v</code> in <code>nums1</code> and <code>pos2<sub>v</sub></code> as the index of the value <code>v</code> in <code>nums2</code>, then a good triplet will be a set <code>(x, y, z)</code> where <code>0 &lt;= x, y, z &lt;= n - 1</code>, such that <code>pos1<sub>x</sub> &lt; pos1<sub>y</sub> &lt; pos1<sub>z</sub></code> and <code>pos2<sub>x</sub> &lt; pos2<sub>y</sub> &lt; pos2<sub>z</sub></code>.</p>

<p>Return <em>the <strong>total number</strong> of good triplets</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [2,0,1,3], nums2 = [0,1,2,3]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
There are 4 triplets (x,y,z) such that pos1<sub>x</sub> &lt; pos1<sub>y</sub> &lt; pos1<sub>z</sub>. They are (2,0,1), (2,0,3), (2,1,3), and (0,1,3). 
Out of those triplets, only the triplet (0,1,3) satisfies pos2<sub>x</sub> &lt; pos2<sub>y</sub> &lt; pos2<sub>z</sub>. Hence, there is only 1 good triplet.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The 4 good triplets are (4,0,3), (4,0,2), (4,1,3), and (4,1,2).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= n - 1</code></li>
	<li><code>nums1</code> and <code>nums2</code> are permutations of <code>[0, 1, ..., n - 1]</code>.</li>
</ul>


## Solution

``` cpp
inline constexpr int lowbit(int x) {
  return x & -x;
}
class BITS {
  int size = 0;
  vector<int> container;
public:
  BITS(int n): container(n), size(n) {}
  void add(int x, int val) {
    while(x < size) {
      container[x] += val;
      x += lowbit(x);
    }
  }

  int sum(int x) {
    int result = 0;
    while(x) {
      result += container[x];
      x -= lowbit(x);
    }
    return result;
  }
};
class Solution {
public:
  long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    int len = nums1.size();

    vector<int> pos2(len);
    for(int i = 0; i < len; ++i) {
      pos2[nums2[i]] = i;
    }
    vector<int> indexMapping(len);
    for(int i = 0; i < len; ++i) {
      indexMapping[pos2[nums1[i]]] = i;
    }

    BITS bit(len + 1);
    long long answer = 0;
    for(int val = 0; val < len; ++val) {
      int pos = indexMapping[val];
      int left = bit.sum(pos + 1);
      bit.add(pos + 1, 1);
      int right = (len - 1 - pos) - (val - left);
      answer += 1LL * left * right;
    }
    return answer;
  }
};

// Accepted
// 148/148 cases passed (17 ms)
// Your runtime beats 88.78 % of cpp submissions
// Your memory usage beats 84.62 % of cpp submissions (87.9 MB)
```
