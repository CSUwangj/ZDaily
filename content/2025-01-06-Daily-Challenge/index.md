+++
updated = 2025-01-06T17:15:57+08:00
title = "2025-01-06 Daily Challenge"
path = "2025-01-06-Daily-Challenge"
date = 2025-01-06T17:15:57+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 6

## Description

**Minimum Number of Operations to Move All Balls to Each Box**

<p>You have <code>n</code> boxes. You are given a binary string <code>boxes</code> of length <code>n</code>, where <code>boxes[i]</code> is <code>&#39;0&#39;</code> if the <code>i<sup>th</sup></code> box is <strong>empty</strong>, and <code>&#39;1&#39;</code> if it contains <strong>one</strong> ball.</p>

<p>In one operation, you can move <strong>one</strong> ball from a box to an adjacent box. Box <code>i</code> is adjacent to box <code>j</code> if <code>abs(i - j) == 1</code>. Note that after doing so, there may be more than one ball in some boxes.</p>

<p>Return an array <code>answer</code> of size <code>n</code>, where <code>answer[i]</code> is the <strong>minimum</strong> number of operations needed to move all the balls to the <code>i<sup>th</sup></code> box.</p>

<p>Each <code>answer[i]</code> is calculated considering the <strong>initial</strong> state of the boxes.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> boxes = &quot;110&quot;
<strong>Output:</strong> [1,1,3]
<strong>Explanation:</strong> The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> boxes = &quot;001011&quot;
<strong>Output:</strong> [11,8,5,4,3,4]</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == boxes.length</code></li>
	<li><code>1 &lt;= n &lt;= 2000</code></li>
	<li><code>boxes[i]</code> is either <code>&#39;0&#39;</code> or <code>&#39;1&#39;</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> minOperations(string boxes) {
    int rCount = 0;
    int rDistSum = 0;
    for(auto it = boxes.rbegin(); it != boxes.rend(); ++it) {
      rDistSum += rCount;
      if(*it == '1') rCount += 1;
    }
    int lCount = 0;
    int lDistSum = 0;
    vector<int> answer;
    answer.reserve(boxes.length());
    for(auto c : boxes) {
      lDistSum += lCount;
      lCount += c == '1';
      answer.push_back(lDistSum + rDistSum);
      rCount -= c == '1';
      rDistSum -= rCount;
    }
    return answer;
  }
};

// Accepted
// 95/95 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 50.97 % of cpp submissions (12.1 MB)
```
