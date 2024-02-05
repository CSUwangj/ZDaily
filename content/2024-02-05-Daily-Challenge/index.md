+++
updated = 2024-02-05T23:07:38+08:00
title = "2024-02-05 Daily Challenge"
path = "2024-02-05-Daily-Challenge"
date = 2024-02-05T23:07:38+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/first-unique-character-in-a-string/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 5

## Description

**First Unique Character in a String**

<p>Given a string <code>s</code>, <em>find the first non-repeating character in it and return its index</em>. If it does not exist, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "leetcode"
<strong>Output:</strong> 0
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "loveleetcode"
<strong>Output:</strong> 2
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s = "aabb"
<strong>Output:</strong> -1
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int firstUniqChar(string s) {
    vector<int> pos(26, INT_MAX - 1);
    for(int i = 0; i < s.length(); ++i) {
      if(pos[s[i] - 'a'] == INT_MAX - 1) {
        pos[s[i] - 'a'] = i;
      } else {
        pos[s[i] - 'a'] = INT_MAX;
      }
    }
    int result = *min_element(pos.begin(), pos.end());
    return result > s.length() ? -1 : result;
  }
};

// Accepted
// 105/105 cases passed (15 ms)
// Your runtime beats 97.21 % of cpp submissions
// Your memory usage beats 24.32 % of cpp submissions (11.9 MB)
```
