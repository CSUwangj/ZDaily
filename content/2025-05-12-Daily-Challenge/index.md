+++
updated = 2025-05-12T11:54:15+08:00
title = "2025-05-12 Daily Challenge"
path = "2025-05-12-Daily-Challenge"
date = 2025-05-12T11:54:15+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/finding-3-digit-even-numbers/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 12

## Description

**Finding 3-Digit Even Numbers**

<p>You are given an integer array <code>digits</code>, where each element is a digit. The array may contain duplicates.</p>

<p>You need to find <strong>all</strong> the <strong>unique</strong> integers that follow the given requirements:</p>

<ul>
	<li>The integer consists of the <strong>concatenation</strong> of <strong>three</strong> elements from <code>digits</code> in <strong>any</strong> arbitrary order.</li>
	<li>The integer does not have <strong>leading zeros</strong>.</li>
	<li>The integer is <strong>even</strong>.</li>
</ul>

<p>For example, if the given <code>digits</code> were <code>[1, 2, 3]</code>, integers <code>132</code> and <code>312</code> follow the requirements.</p>

<p>Return <em>a <strong>sorted</strong> array of the unique integers.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> digits = [2,1,3,0]
<strong>Output:</strong> [102,120,130,132,210,230,302,310,312,320]
<strong>Explanation:</strong> All the possible integers that follow the requirements are in the output array. 
Notice that there are no <strong>odd</strong> integers or integers with <strong>leading zeros</strong>.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> digits = [2,2,8,8,2]
<strong>Output:</strong> [222,228,282,288,822,828,882]
<strong>Explanation:</strong> The same digit can be used as many times as it appears in digits. 
In this example, the digit 8 is used twice each time in 288, 828, and 882. 
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> digits = [3,7,5]
<strong>Output:</strong> []
<strong>Explanation:</strong> No <strong>even</strong> integers can be formed using the given digits.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= digits.length &lt;= 100</code></li>
	<li><code>0 &lt;= digits[i] &lt;= 9</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> count(10);
    for(auto d : digits) {
      count[d] += 1;
    }
    vector<int> answer;
    // with more digit better use recursion
    for(int last = 0; last < 10; last += 2) {
      if(!count[last]) continue;
      count[last] -= 1;
      for(int mid = 0; mid < 10; ++mid) {
        if(!count[mid]) continue;
        count[mid] -= 1;
        for(int front = 1; front < 10; ++ front) {
          if(!count[front]) continue;
          answer.push_back(front * 100 + mid * 10 + last);
        }
        count[mid] += 1;
      }
      count[last] += 1;
    }
    sort(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 79/79 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 87.12 % of cpp submissions (12.5 MB)
```

or recursion way to solve it

``` cpp
class Solution {
  void getEvenNumber(
    vector<int> &digits,
    vector<int> &answer,
    int restLen,
    int current = 0,
    bool isFirst = true
  ) {
    if(!restLen) {
      answer.push_back(current);
      return;
    }
    int step = 1;
    int start = 0;
    if(restLen == 1) step += 1;
    if(isFirst && restLen != 1) start = 1;
    for(int d = start; d < 10; d += step) {
      if(!digits[d]) continue;
      digits[d] -= 1;
      getEvenNumber(digits, answer, restLen - 1, current * 10 + d, false);
      digits[d] += 1;
    }
  }
public:
  vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> count(10);
    for(auto d : digits) {
      count[d] += 1;
    }
    vector<int> answer;
    getEvenNumber(count, answer, 3);
    sort(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 79/79 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 87.12 % of cpp submissions (12.5 MB)
```
