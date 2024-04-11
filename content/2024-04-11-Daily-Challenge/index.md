+++
updated = 2024-04-11T23:30:31+08:00
title = "2024-04-11 Daily Challenge"
path = "2024-04-11-Daily-Challenge"
date = 2024-04-11T23:30:31+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/remove-k-digits/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 11

## Description

**Remove K Digits**

<p>Given string num representing a non-negative integer <code>num</code>, and an integer <code>k</code>, return <em>the smallest possible integer after removing</em> <code>k</code> <em>digits from</em> <code>num</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num = &quot;1432219&quot;, k = 3
<strong>Output:</strong> &quot;1219&quot;
<strong>Explanation:</strong> Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> num = &quot;10200&quot;, k = 1
<strong>Output:</strong> &quot;200&quot;
<strong>Explanation:</strong> Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> num = &quot;10&quot;, k = 2
<strong>Output:</strong> &quot;0&quot;
<strong>Explanation:</strong> Remove all the digits from the number and it is left with nothing which is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= num.length &lt;= 10<sup>5</sup></code></li>
	<li><code>num</code> consists of only digits.</li>
	<li><code>num</code> does not have any leading zeros except for the zero itself.</li>
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
  string removeKdigits(string num, int k) {
    string monoStack;
    int pos = 0;
    int len = num.length();
    while(pos < len) {
      while(k && monoStack.size() && monoStack.back() > num[pos]) {
        monoStack.pop_back();
        k -= 1;
      }
      if(num[pos] != '0' || monoStack.size()) monoStack.push_back(num[pos]);
      pos += 1;
    }
    while(k && monoStack.size()) {
      monoStack.pop_back();
      k -= 1;
    }
    if(monoStack.size()) return monoStack;
    return "0";
  }
};

// Accepted
// 40/40 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 88 % of cpp submissions (6.9 MB)
```
