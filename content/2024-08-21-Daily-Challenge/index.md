+++
updated = 2024-08-21T13:41:20+08:00
title = "2024-08-21 Daily Challenge"
path = "2024-08-21-Daily-Challenge"
date = 2024-08-21T13:41:20+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/strange-printer/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 21

## Description

**Strange Printer**

<p>There is a strange printer with the following two special properties:</p>

<ul>
	<li>The printer can only print a sequence of <strong>the same character</strong> each time.</li>
	<li>At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.</li>
</ul>

<p>Given a string <code>s</code>, return <em>the minimum number of turns the printer needed to print it</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aaabbb&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> Print &quot;aaa&quot; first and then print &quot;bbb&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aba&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> Print &quot;aaa&quot; first and then print &quot;b&quot; from the second place of the string, which will cover the existing character &#39;a&#39;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int dp[100][100];
class Solution {
public:
  int strangePrinter(string target) {
    string s;
    s.push_back(target.front());
    for(auto c : target) {
      if(c != s.back()) {
        s.push_back(c);
      }
    }
    int len = s.length();
    for(int l = 0; l < len; ++l) {
      for(int left = 0; left + l < len; ++left) {
        int right = left + l;
        if(!l) {
          dp[left][right] = 1;
        } else {
          dp[left][right] = dp[left][right - 1] + 1;
        }
        for(int middle = left; middle < right; middle += 1) {
          if(s[middle] == s[right]) {
            dp[left][right] = min(dp[left][right], dp[left][middle] + dp[middle + 1][right - 1]);
          }
        }
      }
    }
    return dp[0][len - 1];
  }
};

// Accepted
// 200/200 cases passed (12 ms)
// Your runtime beats 98.86 % of cpp submissions
// Your memory usage beats 66.76 % of cpp submissions (6.3 MB)
```
