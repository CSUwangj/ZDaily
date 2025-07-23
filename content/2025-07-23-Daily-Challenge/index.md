+++
updated = 2025-07-23T15:05:59+08:00
title = "2025-07-23 Daily Challenge"
path = "2025-07-23-Daily-Challenge"
date = 2025-07-23T15:05:59+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/maximum-score-from-removing-substrings/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 23

## Description

**Maximum Score From Removing Substrings**

<p>You are given a string <code>s</code> and two integers <code>x</code> and <code>y</code>. You can perform two types of operations any number of times.</p>

<ul>
	<li>Remove substring <code>&quot;ab&quot;</code> and gain <code>x</code> points.

	<ul>
		<li>For example, when removing <code>&quot;ab&quot;</code> from <code>&quot;c<u>ab</u>xbae&quot;</code> it becomes <code>&quot;cxbae&quot;</code>.</li>
	</ul>
	</li>
	<li>Remove substring <code>&quot;ba&quot;</code> and gain <code>y</code> points.
	<ul>
		<li>For example, when removing <code>&quot;ba&quot;</code> from <code>&quot;cabx<u>ba</u>e&quot;</code> it becomes <code>&quot;cabxe&quot;</code>.</li>
	</ul>
	</li>
</ul>

<p>Return <em>the maximum points you can gain after applying the above operations on</em> <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;cdbcbbaaabab&quot;, x = 4, y = 5
<strong>Output:</strong> 19
<strong>Explanation:</strong>
- Remove the &quot;ba&quot; underlined in &quot;cdbcbbaaa<u>ba</u>b&quot;. Now, s = &quot;cdbcbbaaab&quot; and 5 points are added to the score.
- Remove the &quot;ab&quot; underlined in &quot;cdbcbbaa<u>ab</u>&quot;. Now, s = &quot;cdbcbbaa&quot; and 4 points are added to the score.
- Remove the &quot;ba&quot; underlined in &quot;cdbcb<u>ba</u>a&quot;. Now, s = &quot;cdbcba&quot; and 5 points are added to the score.
- Remove the &quot;ba&quot; underlined in &quot;cdbc<u>ba</u>&quot;. Now, s = &quot;cdbc&quot; and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aabbaaxybbaabb&quot;, x = 5, y = 4
<strong>Output:</strong> 20
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= x, y &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maximumGain(string s, int x, int y) {
    string bigger = "ab";
    string smaller = "ba";
    int sB = x;
    int sS = y;
    if(y > x) {
      swap(bigger, smaller);
      swap(sB, sS);
    }

    int answer = 0;
    vector<char> st;
    for(auto c : s) {
      if(c == bigger[1] && st.size() && st.back() == bigger[0]) {
        answer += sB;
        st.pop_back();
      } else {
        st.push_back(c);
      }
    }
    vector<char> anotherSt;
    for(auto c : st) {
      if(c == smaller[1] && anotherSt.size() && anotherSt.back() == smaller[0]) {
        answer += sS;
        anotherSt.pop_back();
      } else {
        anotherSt.push_back(c);
      }
    }
    return answer;
  }
};

// Accepted
// 77/77 cases passed (16 ms)
// Your runtime beats 95.72 % of cpp submissions
// Your memory usage beats 55.89 % of cpp submissions (28.2 MB)
```
