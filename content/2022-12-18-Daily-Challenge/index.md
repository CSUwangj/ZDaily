+++
updated = 2022-12-18T20:17:39+08:00
title = "2022-12-18 Daily Challenge"
path = "2022-12-18-Daily-Challenge"
date = 2022-12-18T20:17:39+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/daily-temperatures/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 18

## Description

**Daily Temperatures**

<p>Given an array of integers <code>temperatures</code> represents the daily temperatures, return <em>an array</em> <code>answer</code> <em>such that</em> <code>answer[i]</code> <em>is the number of days you have to wait after the</em> <code>i<sup>th</sup></code> <em>day to get a warmer temperature</em>. If there is no future day for which this is possible, keep <code>answer[i] == 0</code> instead.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> temperatures = [73,74,75,71,69,72,76,73]
<strong>Output:</strong> [1,1,4,2,1,1,0,0]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> temperatures = [30,40,50,60]
<strong>Output:</strong> [1,1,1,0]
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> temperatures = [30,60,90]
<strong>Output:</strong> [1,1,0]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;temperatures.length &lt;= 10<sup>5</sup></code></li>
	<li><code>30 &lt;=&nbsp;temperatures[i] &lt;= 100</code></li>
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
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> monoStack;
    int len = temperatures.size();
    vector<int> answer(len);
    for(int i = len - 1; i >= 0; --i) {
      while(monoStack.size() && temperatures[monoStack.back()] <= temperatures[i]) {
        monoStack.pop_back();
      }
      if(monoStack.size()) answer[i] = monoStack.back() - i;
      monoStack.push_back(i);
    }
    return answer;
  }
};

// Accepted
// 48/48 cases passed (316 ms)
// Your runtime beats 67.33 % of cpp submissions
// Your memory usage beats 89.86 % of cpp submissions (98.5 MB)
```
