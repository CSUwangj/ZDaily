+++
updated = 2024-01-03T13:13:02+08:00
title = "2024-01-03 Daily Challenge"
path = "2024-01-03-Daily-Challenge"
date = 2024-01-03T13:13:02+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/number-of-laser-beams-in-a-bank/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 3

## Description

**Number of Laser Beams in a Bank**

<p>Anti-theft security devices are activated inside a bank. You are given a <strong>0-indexed</strong> binary string array <code>bank</code> representing the floor plan of the bank, which is an <code>m x n</code> 2D matrix. <code>bank[i]</code> represents the <code>i<sup>th</sup></code> row, consisting of <code>&#39;0&#39;</code>s and <code>&#39;1&#39;</code>s. <code>&#39;0&#39;</code> means the cell is empty, while<code>&#39;1&#39;</code> means the cell has a security device.</p>

<p>There is <strong>one</strong> laser beam between any <strong>two</strong> security devices <strong>if both</strong> conditions are met:</p>

<ul>
	<li>The two devices are located on two <strong>different rows</strong>: <code>r<sub>1</sub></code> and <code>r<sub>2</sub></code>, where <code>r<sub>1</sub> &lt; r<sub>2</sub></code>.</li>
	<li>For <strong>each</strong> row <code>i</code> where <code>r<sub>1</sub> &lt; i &lt; r<sub>2</sub></code>, there are <strong>no security devices</strong> in the <code>i<sup>th</sup></code> row.</li>
</ul>

<p>Laser beams are independent, i.e., one beam does not interfere nor join with another.</p>

<p>Return <em>the total number of laser beams in the bank</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/24/laser1.jpg" style="width: 400px; height: 368px;" />
<pre>
<strong>Input:</strong> bank = [&quot;011001&quot;,&quot;000000&quot;,&quot;010100&quot;,&quot;001000&quot;]
<strong>Output:</strong> 8
<strong>Explanation:</strong> Between each of the following device pairs, there is one beam. In total, there are 8 beams:
 * bank[0][1] -- bank[2][1]
 * bank[0][1] -- bank[2][3]
 * bank[0][2] -- bank[2][1]
 * bank[0][2] -- bank[2][3]
 * bank[0][5] -- bank[2][1]
 * bank[0][5] -- bank[2][3]
 * bank[2][1] -- bank[3][2]
 * bank[2][3] -- bank[3][2]
Note that there is no beam between any device on the 0<sup>th</sup> row with any on the 3<sup>rd</sup> row.
This is because the 2<sup>nd</sup> row contains security devices, which breaks the second condition.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/24/laser2.jpg" style="width: 244px; height: 325px;" />
<pre>
<strong>Input:</strong> bank = [&quot;000&quot;,&quot;111&quot;,&quot;000&quot;]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There does not exist two devices located on two different rows.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == bank.length</code></li>
	<li><code>n == bank[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>bank[i][j]</code> is either <code>&#39;0&#39;</code> or <code>&#39;1&#39;</code>.</li>
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
  int numberOfBeams(vector<string>& bank) {
    vector<int> devices;
    for(const auto &row : bank) {
      int c = 0;
      for(auto d : row) {
        c += d - '0';
      }
      if(c) devices.push_back(c);
    }
    int answer = 0;
    for(int i = 1; i < devices.size(); ++i) {
      answer += devices[i] * devices[i - 1];
    }
    return answer;
  }
};

// Accepted
// 147/147 cases passed (82 ms)
// Your runtime beats 85.04 % of cpp submissions
// Your memory usage beats 50.15 % of cpp submissions (23.6 MB)
```
