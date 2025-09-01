+++
updated = 2025-09-01T23:01:10+02:00
title = "2025-09-01 Daily Challenge"
path = "2025-09-01-Daily-Challenge"
date = 2025-09-01T23:01:10+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/maximum-average-pass-ratio/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 1

## Description

**Maximum Average Pass Ratio**

<p>There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array <code>classes</code>, where <code>classes[i] = [pass<sub>i</sub>, total<sub>i</sub>]</code>. You know beforehand that in the <code>i<sup>th</sup></code> class, there are <code>total<sub>i</sub></code> total students, but only <code>pass<sub>i</sub></code> number of students will pass the exam.</p>

<p>You are also given an integer <code>extraStudents</code>. There are another <code>extraStudents</code> brilliant students that are <strong>guaranteed</strong> to pass the exam of any class they are assigned to. You want to assign each of the <code>extraStudents</code> students to a class in a way that <strong>maximizes</strong> the <strong>average</strong> pass ratio across <strong>all</strong> the classes.</p>

<p>The <strong>pass ratio</strong> of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The <strong>average pass ratio</strong> is the sum of pass ratios of all the classes divided by the number of the classes.</p>

<p>Return <em>the <strong>maximum</strong> possible average pass ratio after assigning the </em><code>extraStudents</code><em> students. </em>Answers within <code>10<sup>-5</sup></code> of the actual answer will be accepted.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> classes = [[1,2],[3,5],[2,2]], <code>extraStudents</code> = 2
<strong>Output:</strong> 0.78333
<strong>Explanation:</strong> You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> classes = [[2,4],[3,9],[4,5],[2,10]], <code>extraStudents</code> = 4
<strong>Output:</strong> 0.53485
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= classes.length &lt;= 10<sup>5</sup></code></li>
	<li><code>classes[i].length == 2</code></li>
	<li><code>1 &lt;= pass<sub>i</sub> &lt;= total<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= extraStudents &lt;= 10<sup>5</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  using pi = pair<int, int>;
public:
  double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    auto calculateGain = [](int passes, int totalStudents) {
      return 1.0 * (passes + 1) / (totalStudents + 1) -
             1.0 * passes / totalStudents;
    };
    priority_queue<pair<double, pi>> pq;
    for(auto &c : classes) {
      pq.push({calculateGain(c[0], c[1]), {c[0], c[1]}});
    }
    while(extraStudents--) {
      auto [gain, c] = pq.top();
      pq.pop();
      pq.push({calculateGain(c.first + 1, c.second + 1), {c.first + 1, c.second + 1}});
    }
    double answer;
    while(pq.size()) {
      auto [gain, c] = pq.top();
      pq.pop();
      answer += 1.0 * c.first / c.second;
    }
    answer /= classes.size();
    return answer;
  }
};

// Accepted
// 88/88 cases passed (327 ms)
// Your runtime beats 37.68 % of cpp submissions
// Your memory usage beats 81.16 % of cpp submissions (97.8 MB)
```
