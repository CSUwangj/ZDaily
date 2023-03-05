+++
updated = 2023-03-05T10:58:11+08:00
title = "2023-03-05 Daily Challenge"
path = "2023-03-05-Daily-Challenge"
date = 2023-03-05T10:58:11+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/jump-game-iv/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 5

## Description

**Jump Game IV**

<p>Given an array of&nbsp;integers <code>arr</code>, you are initially positioned at the first index of the array.</p>

<p>In one step you can jump from index <code>i</code> to index:</p>

<ul>
	<li><code>i + 1</code> where:&nbsp;<code>i + 1 &lt; arr.length</code>.</li>
	<li><code>i - 1</code> where:&nbsp;<code>i - 1 &gt;= 0</code>.</li>
	<li><code>j</code> where: <code>arr[i] == arr[j]</code> and <code>i != j</code>.</li>
</ul>

<p>Return <em>the minimum number of steps</em> to reach the <strong>last index</strong> of the array.</p>

<p>Notice that you can not jump outside of the array at any time.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [100,-23,-23,404,100,23,23,23,3,404]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You need three jumps from index 0 --&gt; 4 --&gt; 3 --&gt; 9. Note that index 9 is the last index of the array.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [7]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Start index is the last index. You do not need to jump.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> arr = [7,6,9,6,9,6,9,7]
<strong>Output:</strong> 1
<strong>Explanation:</strong> You can jump directly from index 0 to index 7 which is last index of the array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>8</sup> &lt;= arr[i] &lt;= 10<sup>8</sup></code></li>
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
  int minJumps(vector<int>& arr) {
    if(arr.size() < 3) return arr.size() - 1;
    unordered_map<int, vector<int>> positions;
    int len = arr.size();
    vector<bool> posVisit(len);
    for(int i = 0; i < len; ++i) {
      positions[arr[i]].push_back(i);
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    posVisit[0] = true;

    while(q.size()) {
      auto [cnt, pos] = q.front();
      if(pos == len - 1) return cnt;
      q.pop();
      if(pos && !posVisit[pos - 1]) {
        q.push({cnt + 1, pos - 1});
        posVisit[pos - 1] = true;
      }
      if(pos < len - 1 && !posVisit[pos + 1]) {
        q.push({cnt + 1, pos + 1});
        posVisit[pos + 1] = true;
      }
      int num = arr[pos];
      for(auto next : positions[num]) {
        if(next == pos) continue;
        posVisit[next] = true;
        q.push({cnt + 1, next});
      }
      positions[num].clear();
    }
    return - 1;
  }
};

// Accepted
// 33/33 cases passed (163 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 69.4 % of cpp submissions (73.9 MB)
```
