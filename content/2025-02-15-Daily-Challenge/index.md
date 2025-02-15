+++
updated = 2025-02-15T12:37:28+08:00
title = "2025-02-15 Daily Challenge"
path = "2025-02-15-Daily-Challenge"
date = 2025-02-15T12:37:28+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/find-the-punishment-number-of-an-integer/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 15

## Description

**Find the Punishment Number of an Integer**

<p>Given a positive integer <code>n</code>, return <em>the <strong>punishment number</strong></em> of <code>n</code>.</p>

<p>The <strong>punishment number</strong> of <code>n</code> is defined as the sum of the squares of all integers <code>i</code> such that:</p>

<ul>
	<li><code>1 &lt;= i &lt;= n</code></li>
	<li>The decimal representation of <code>i * i</code> can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals <code>i</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 10
<strong>Output:</strong> 182
<strong>Explanation:</strong> There are exactly 3 integers i in the range [1, 10] that satisfy the conditions in the statement:
- 1 since 1 * 1 = 1
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 and 1 with a sum equal to 8 + 1 == 9.
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 and 0 with a sum equal to 10 + 0 == 10.
Hence, the punishment number of 10 is 1 + 81 + 100 = 182
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 37
<strong>Output:</strong> 1478
<strong>Explanation:</strong> There are exactly 4 integers i in the range [1, 37] that satisfy the conditions in the statement:
- 1 since 1 * 1 = 1. 
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 + 1. 
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 + 0. 
- 36 since 36 * 36 = 1296 and 1296 can be partitioned into 1 + 29 + 6.
Hence, the punishment number of 37 is 1 + 81 + 100 + 1296 = 1478
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
bool isPunishment(int n, string s, int pos, int sum, int current) {
  if(pos == s.length()) return n == sum + current;
  return isPunishment(n, s, pos + 1, sum + current, s[pos] - '0') || isPunishment(n, s, pos + 1, sum, current * 10 + s[pos] - '0');
}
vector<int> result = []{
  vector<int> result(1001);
  for(int i = 1; i < 1001; ++i) {
    string si = to_string(i * i);
    if(isPunishment(i, si, 0, 0, 0)) {
      result[i] = i * i + result[i - 1];
    } else {
      result[i] = result[i - 1];
    }
  }
  return result;
}();
class Solution {
public:
  int punishmentNumber(int n) {
    return result[n];
  }
};

// Accepted
// 216/216 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 70.03 % of cpp submissions (9.7 MB)
```
