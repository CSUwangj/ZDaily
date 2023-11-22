+++
updated = 2023-11-22T11:31:14+08:00
title = "2023-11-22 Daily Challenge"
path = "2023-11-22-Daily-Challenge"
date = 2023-11-22T11:31:14+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/diagonal-traverse-ii/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 22

## Description

**Diagonal Traverse II**

<p>Given a 2D integer array <code>nums</code>, return <em>all elements of </em><code>nums</code><em> in diagonal order as shown in the below images</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/04/08/sample_1_1784.png" style="width: 158px; height: 143px;" />
<pre>
<strong>Input:</strong> nums = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> [1,4,2,7,5,3,8,6,9]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/04/08/sample_2_1784.png" style="width: 230px; height: 177px;" />
<pre>
<strong>Input:</strong> nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
<strong>Output:</strong> [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i].length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= sum(nums[i].length) &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i][j] &lt;= 10<sup>5</sup></code></li>
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
  using vii = vector<int>::iterator;
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    int maxTraverse = 0;
    for(int i = 0; i < nums.size(); ++i) {
      maxTraverse = max<int>(maxTraverse, nums[i].size() + i);
    }

    vector<int> answer;
    queue<pair<vii, vii>> q;
    q.push({nums[0].begin(), nums[0].end()});
    for(int i = 0; i < maxTraverse; ++i) {
      int sz = q.size();
      if(i + 1 < nums.size()) {
        q.push({nums[i + 1].begin(), nums[i + 1].end()});
      }
      for(int _ = 0; _ < sz; ++_) {
        auto [it, eit] = q.front();
        q.pop();
        answer.push_back(*it);
        // cout << i << ' ' << _ << ' ' << *it << endl;
        ++it;
        if(it != eit) q.push({it, eit});
      }
    } 
    return answer;
  }
};

// Accepted
// 56/56 cases passed (108 ms)
// Your runtime beats 96.79 % of cpp submissions
// Your memory usage beats 83.33 % of cpp submissions (70.1 MB)
```
