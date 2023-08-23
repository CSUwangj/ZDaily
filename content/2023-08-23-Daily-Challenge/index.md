+++
updated = 2023-08-23T11:20:41+08:00
title = "2023-08-23 Daily Challenge"
path = "2023-08-23-Daily-Challenge"
date = 2023-08-23T11:20:41+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/reorganize-string/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 23

## Description

**Reorganize String**

<p>Given a string <code>s</code>, rearrange the characters of <code>s</code> so that any two adjacent characters are not the same.</p>

<p>Return <em>any possible rearrangement of</em> <code>s</code> <em>or return</em> <code>&quot;&quot;</code> <em>if not possible</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "aab"
<strong>Output:</strong> "aba"
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "aaab"
<strong>Output:</strong> ""
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
  using pi = pair<int, int>;
public:
  string reorganizeString(string s) {
    int cnt[26] = {};
    for(auto c : s) {
      cnt[c - 'a'] += 1;
    }
    priority_queue<pi> pq;

    for(int i = 0; i < 26; ++i) {
      if(cnt[i]) pq.push({cnt[i], i});
    }
    if(pq.top().first > s.length() - pq.top().first + 1) return "";

    string answer;
    while(pq.size()) {
      auto [cnt, c] = pq.top();
      pq.pop();
      answer.push_back(c + 'a');
      if(pq.size()) {
        auto [cnt2, c2] = pq.top();
        pq.pop();
        answer.push_back(c2 + 'a');
        if(cnt2 > 1) pq.push({cnt2 - 1, c2});
      }
      if(cnt > 1) pq.push({cnt - 1, c});
    }
    return answer;
  }
};

// Accepted
// 70/70 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 46.07 % of cpp submissions (6.3 MB)
```
