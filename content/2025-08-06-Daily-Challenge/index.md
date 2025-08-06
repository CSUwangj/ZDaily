+++
updated = 2025-08-07T01:57:21+08:00
title = "2025-08-06 Daily Challenge"
path = "2025-08-06-Daily-Challenge"
date = 2025-08-07T01:57:21+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/fruits-into-baskets-iii/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 6

## Description

**Fruits Into Baskets III**

<p>You are given two arrays of integers, <code>fruits</code> and <code>baskets</code>, each of length <code>n</code>, where <code>fruits[i]</code> represents the <strong>quantity</strong> of the <code>i<sup>th</sup></code> type of fruit, and <code>baskets[j]</code> represents the <strong>capacity</strong> of the <code>j<sup>th</sup></code> basket.</p>

<p>From left to right, place the fruits according to these rules:</p>

<ul>
	<li>Each fruit type must be placed in the <strong>leftmost available basket</strong> with a capacity <strong>greater than or equal</strong> to the quantity of that fruit type.</li>
	<li>Each basket can hold <b>only one</b> type of fruit.</li>
	<li>If a fruit type <b>cannot be placed</b> in any basket, it remains <b>unplaced</b>.</li>
</ul>

<p>Return the number of fruit types that remain unplaced after all possible allocations are made.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">fruits = [4,2,5], baskets = [3,5,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li><code>fruits[0] = 4</code> is placed in <code>baskets[1] = 5</code>.</li>
	<li><code>fruits[1] = 2</code> is placed in <code>baskets[0] = 3</code>.</li>
	<li><code>fruits[2] = 5</code> cannot be placed in <code>baskets[2] = 4</code>.</li>
</ul>

<p>Since one fruit type remains unplaced, we return 1.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">fruits = [3,6,1], baskets = [6,4,7]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li><code>fruits[0] = 3</code> is placed in <code>baskets[0] = 6</code>.</li>
	<li><code>fruits[1] = 6</code> cannot be placed in <code>baskets[1] = 4</code> (insufficient capacity) but can be placed in the next available basket, <code>baskets[2] = 7</code>.</li>
	<li><code>fruits[2] = 1</code> is placed in <code>baskets[1] = 4</code>.</li>
</ul>

<p>Since all fruits are successfully placed, we return 0.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == fruits.length == baskets.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= fruits[i], baskets[i] &lt;= 10<sup>9</sup></code></li>
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
  BITS(vector<int> &original) {
    size = original.size() + 1;
    container.resize(size + 1);
    for(int i = 1; i <= size; ++i) {
      update(i, original[i - 1], original);
    }
  }

  int query(int x) {
    int result = 0;
    while(x >= 1) {
      result = max(result, container[x]);
      x -= 1;
      while(x - lowbit(x) >= 1) {
        result = max(result, container[x]);
        x -= lowbit(x);
      }
    }
    return result;
  }

  void update(int x, int val, vector<int> &original) {
    original[x - 1] = val;
    while(x < size) {
      container[x] = original[x - 1];
      for(int i = 1; i < lowbit(x); i *= 2) {
        container[x] = max(container[x], container[x - i]);
      }
      x += lowbit(x);
    }
  }
};
class Solution {
public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int len = baskets.size();
    BITS bits(len + 1);
    for(int i = 0; i < len; ++i) {
      bits.update(i + 1, baskets[i],baskets);
    }
    // for(int i = 1; i <= len; ++i) {
    //   cout << bits.query(i) << ' ';
    // }
      cout << endl;
    int answer = 0;
    for(auto f : fruits) {
      int low = 1;
      int high = len;
      while(low < high) {
        int mid = (low + high) / 2;
        if(bits.query(mid) < f) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }
      if(baskets[low - 1] < f) {
        answer += 1;
      } else {
        bits.update(low, 0, baskets);
      }
      
      // for(int i = 1; i <= len; ++i) {
      //   cout << bits.query(i) << ' ';
      // }
      // cout << endl;
    }
    return answer;
  }
};

// Accepted
// 740/740 cases passed (1270 ms)
// Your runtime beats 5.06 % of cpp submissions
// Your memory usage beats 91.85 % of cpp submissions (179.5 MB)
```
