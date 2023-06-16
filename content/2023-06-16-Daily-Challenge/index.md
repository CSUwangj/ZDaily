+++
updated = 2023-06-16T10:55:17+08:00
title = "2023-06-16 Daily Challenge"
path = "2023-06-16-Daily-Challenge"
date = 2023-06-16T10:55:17+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 16

## Description

**Number of Ways to Reorder Array to Get Same BST**

<p>Given an array <code>nums</code> that represents a permutation of integers from <code>1</code> to <code>n</code>. We are going to construct a binary search tree (BST) by inserting the elements of <code>nums</code> in order into an initially empty BST. Find the number of different ways to reorder <code>nums</code> so that the constructed BST is identical to that formed from the original array <code>nums</code>.</p>

<ul>
	<li>For example, given <code>nums = [2,1,3]</code>, we will have 2 as the root, 1 as a left child, and 3 as a right child. The array <code>[2,3,1]</code> also yields the same BST but <code>[3,2,1]</code> yields a different BST.</li>
</ul>

<p>Return <em>the number of ways to reorder</em> <code>nums</code> <em>such that the BST formed is identical to the original BST formed from</em> <code>nums</code>.</p>

<p>Since the answer may be very large, <strong>return it modulo </strong><code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/12/bb.png" style="width: 121px; height: 101px;" />
<pre>
<strong>Input:</strong> nums = [2,1,3]
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can reorder nums to be [2,3,1] which will yield the same BST. There are no other ways to reorder nums which will yield the same BST.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/12/ex1.png" style="width: 241px; height: 161px;" />
<pre>
<strong>Input:</strong> nums = [3,4,5,1,2]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The following 5 arrays will yield the same BST: 
[3,1,2,4,5]
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/12/ex4.png" style="width: 121px; height: 161px;" />
<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no other orderings of nums that will yield the same BST.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= nums.length</code></li>
	<li>All integers in <code>nums</code> are <strong>distinct</strong>.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
const int MOD = 1e9 + 7;
constexpr int qmul(int a, int b, int m) {
  int result = 0;
  while(b) {
    if(b & 1) {
      result += a;
      result %= m;
    }
    a += a;
    a %= m;
    b >>= 1;
  }
  return result;
}
constexpr int qpow(int b, int e, int m) {
  int result = 1;
  while(e) {
    if(e & 1) {
      result = qmul(result, b, m);
    }
    b = qmul(b, b, m);
    e >>= 1;
  }
  return result;
}
constexpr int inv(int a) {
  return qpow(a, MOD - 2, MOD);
}

constexpr int C(int m, int n) {
  int result = 1;
  for(int i = max(m, n - m) + 1; i <= n; ++i) {
    result = qmul(result, i, MOD);
  }
  for(int i = 1; i <= min(m, n - m); ++i) {
    result = qmul(result, inv(i), MOD);
  }
  return result;
}

class Solution {
  pair<int, int> children[1001];
  int nodes[1001];
  int len;
  void constructTree(vector<int> &nums) {
    len = nums.size();
    for(int i = 1; i <= len; ++i) {
      children[i] = {-1, -1};
      nodes[i] = 1;
    }
    construct(nums, 0, INT_MIN, INT_MAX);
  }
  void construct(vector<int> &nums, int index, int leftBound, int rightBound) {
    int root = nums[index];
    bool left = false;
    bool right = false;
    // cout << root << ' ' << leftBound << ' ' << rightBound << endl;
    for(int i = index + 1; i < nums.size() && !(left && right); i++) {
      if(!left && nums[i] < root && nums[i] > leftBound) {
        construct(nums, i, leftBound, min(rightBound, root));
        children[root].first = nums[i];
        nodes[root] += nodes[nums[i]];
        left = true;
      }
      if(!right && nums[i] > root && nums[i] < rightBound) {
        construct(nums, i, max(leftBound, root), rightBound);
        children[root].second = nums[i];
        nodes[root] += nodes[nums[i]];
        right = true;
      }
    }
  }
public:
  int numOfWays(vector<int>& nums) {
    constructTree(nums);
    // for(int i = 1; i <= len; ++i) {
    //   cout << i << ": " << children[i].first << " " << children[i].second << ' ' << nodes[i] << endl;
    // }
    queue<int> q;
    q.push(nums[0]);
    int answer = 1;
    while(q.size()) {
      int cur = q.front();
      q.pop();
      if(children[cur].first != -1) {
        q.push(children[cur].first);
        if(children[cur].second != -1) {
          answer = qmul(answer, C(nodes[children[cur].first], nodes[cur] - 1), MOD);
        }
      }
      if(children[cur].second != -1) {
        q.push(children[cur].second);
      }
    }
    return (answer + MOD - 1) % MOD;
  }
};

// Accepted
// 161/161 cases passed (396 ms)
// Your runtime beats 27.01 % of cpp submissions
// Your memory usage beats 97.41 % of cpp submissions (13.1 MB)
```
