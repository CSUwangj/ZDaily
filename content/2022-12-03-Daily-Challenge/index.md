+++
updated = 2022-12-03T17:59:36+08:00
title = "2022-12-03 Daily Challenge"
path = "2022-12-03-Daily-Challenge"
date = 2022-12-03T17:59:36+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/sort-characters-by-frequency/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 3

## Description

**Sort Characters By Frequency**

<p>Given a string <code>s</code>, sort it in <strong>decreasing order</strong> based on the <strong>frequency</strong> of the characters. The <strong>frequency</strong> of a character is the number of times it appears in the string.</p>

<p>Return <em>the sorted string</em>. If there are multiple answers, return <em>any of them</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;tree&quot;
<strong>Output:</strong> &quot;eert&quot;
<strong>Explanation:</strong> &#39;e&#39; appears twice while &#39;r&#39; and &#39;t&#39; both appear once.
So &#39;e&#39; must appear before both &#39;r&#39; and &#39;t&#39;. Therefore &quot;eetr&quot; is also a valid answer.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;cccaaa&quot;
<strong>Output:</strong> &quot;aaaccc&quot;
<strong>Explanation:</strong> Both &#39;c&#39; and &#39;a&#39; appear three times, so both &quot;cccaaa&quot; and &quot;aaaccc&quot; are valid answers.
Note that &quot;cacaca&quot; is incorrect, as the same characters must be together.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;Aabb&quot;
<strong>Output:</strong> &quot;bbAa&quot;
<strong>Explanation:</strong> &quot;bbaA&quot; is also a valid answer, but &quot;Aabb&quot; is incorrect.
Note that &#39;A&#39; and &#39;a&#39; are treated as two different characters.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>s</code> consists of uppercase and lowercase English letters and digits.</li>
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
  int count[128] = {};
public:
  string frequencySort(string s) {
    for(auto c : s) {
      count[c] += 1;
    }
    sort(s.begin(), s.end(), [&](char a, char b) {
      return count[a] > count[b] || (count[a] == count[b] && a > b);
    });
    return s;
  }
};

// Accepted
// 33/33 cases passed (61 ms)
// Your runtime beats 8.74 % of cpp submissions
// Your memory usage beats 95.21 % of cpp submissions (8 MB)
```
