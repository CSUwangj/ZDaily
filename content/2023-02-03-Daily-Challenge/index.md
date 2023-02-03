+++
updated = 2023-02-03T11:12:51+08:00
title = "2023-02-03 Daily Challenge"
path = "2023-02-03-Daily-Challenge"
date = 2023-02-03T11:12:51+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/zigzag-conversion/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 3

## Description

**Zigzag Conversion**

<p>The string <code>&quot;PAYPALISHIRING&quot;</code> is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)</p>

<pre>
P   A   H   N
A P L S I I G
Y   I   R
</pre>

<p>And then read line by line: <code>&quot;PAHNAPLSIIGYIR&quot;</code></p>

<p>Write the code that will take a string and make this conversion given a number of rows:</p>

<pre>
string convert(string s, int numRows);
</pre>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;PAYPALISHIRING&quot;, numRows = 3
<strong>Output:</strong> &quot;PAHNAPLSIIGYIR&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;PAYPALISHIRING&quot;, numRows = 4
<strong>Output:</strong> &quot;PINALSIGYAHRPI&quot;
<strong>Explanation:</strong>
P     I    N
A   L S  I G
Y A   H R
P     I
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;A&quot;, numRows = 1
<strong>Output:</strong> &quot;A&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of English letters (lower-case and upper-case), <code>&#39;,&#39;</code> and <code>&#39;.&#39;</code>.</li>
	<li><code>1 &lt;= numRows &lt;= 1000</code></li>
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
  string convert(string s, int numRows) {
    if(numRows == 1) return s;
    int len = s.length();
    string answer;
    for(int row = 0; row < numRows; ++row) {
      for(int pos = row; pos < len; pos += 2 * numRows - 2) {
        answer.push_back(s[pos]);
        if(!row || row == numRows - 1) continue;

        if(pos + 2 * (numRows - row - 1) < len) {
          answer.push_back(s[pos + 2 * (numRows - row - 1)]);
        }
      }
    }
    return answer;
  }
};

// Accepted
// 1157/1157 cases passed (15 ms)
// Your runtime beats 41.89 % of cpp submissions
// Your memory usage beats 65.47 % of cpp submissions (8.3 MB)
```
