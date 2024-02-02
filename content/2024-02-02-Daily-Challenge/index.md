+++
updated = 2024-02-02T15:24:20+08:00
title = "2024-02-02 Daily Challenge"
path = "2024-02-02-Daily-Challenge"
date = 2024-02-02T15:24:20+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/sequential-digits/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 2

## Description

**Sequential Digits**

<p>An&nbsp;integer has <em>sequential digits</em> if and only if each digit in the number is one more than the previous digit.</p>

<p>Return a <strong>sorted</strong> list of all the integers&nbsp;in the range <code>[low, high]</code>&nbsp;inclusive that have sequential digits.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> low = 100, high = 300
<strong>Output:</strong> [123,234]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> low = 1000, high = 13000
<strong>Output:</strong> [1234,2345,3456,4567,5678,6789,12345]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>10 &lt;= low &lt;= high &lt;= 10^9</code></li>
</ul>


## Solution

``` cpp
const vector<int> nums{1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789};
class Solution {
public:
  vector<int> sequentialDigits(int low, int high) {
    int diff = 0;
    vector<int> answer;
    for(auto num : nums) {
      diff = diff * 10 + 1;
      if(num > high) break;
      while(num % 10 && num <= high) {
        if(num >= low) answer.push_back(num);
        num += diff;
      }
    }
    return answer;
  }
};

// Accepted
// 23/23 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 76.43 % of cpp submissions (6.2 MB)
```
