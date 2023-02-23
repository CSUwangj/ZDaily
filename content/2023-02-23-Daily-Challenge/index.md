+++
updated = 2023-02-23T08:25:49+08:00
title = "2023-02-23 Daily Challenge"
path = "2023-02-23-Daily-Challenge"
date = 2023-02-23T08:25:49+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/ipo/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 23

## Description

**IPO**

<p>Suppose LeetCode will start its <strong>IPO</strong> soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the <strong>IPO</strong>. Since it has limited resources, it can only finish at most <code>k</code> distinct projects before the <strong>IPO</strong>. Help LeetCode design the best way to maximize its total capital after finishing at most <code>k</code> distinct projects.</p>

<p>You are given <code>n</code> projects where the <code>i<sup>th</sup></code> project has a pure profit <code>profits[i]</code> and a minimum capital of <code>capital[i]</code> is needed to start it.</p>

<p>Initially, you have <code>w</code> capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.</p>

<p>Pick a list of <strong>at most</strong> <code>k</code> distinct projects from given projects to <strong>maximize your final capital</strong>, and return <em>the final maximized capital</em>.</p>

<p>The answer is guaranteed to fit in a 32-bit signed integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
<strong>Output:</strong> 6
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= w &lt;= 10<sup>9</sup></code></li>
	<li><code>n == profits.length</code></li>
	<li><code>n == capital.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= profits[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= capital[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();

pair<int, int> projects[100000];
class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int len = profits.size();
    for(int i = 0; i < len; ++i) {
      projects[i].first = capital[i];
      projects[i].second = profits[i];
    }
    sort(projects, projects + len);
    
    priority_queue<int> pq;
    for(int pos = 0, end = len; k; --k) {
      while(pos < len && projects[pos].first <= w) {
        pq.push(projects[pos].second);
        pos += 1;
      }
      if(pq.empty()) break;
      w += pq.top();
      pq.pop();
    }

    return w;
  }
};

// Accepted
// 35/35 cases passed (179 ms)
// Your runtime beats 99.01 % of cpp submissions
// Your memory usage beats 99.45 % of cpp submissions (74.9 MB)
```
