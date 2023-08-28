+++
updated = 2023-04-28T23:59:07+08:00
title = "2023-04-28 Daily Challenge"
path = "2023-04-28-Daily-Challenge"
date = 2023-04-28T23:59:07+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/similar-string-groups/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 28

## Description

**Similar String Groups**

<p>Two strings <code>X</code>&nbsp;and <code>Y</code>&nbsp;are similar if we can swap two letters (in different positions) of <code>X</code>, so that&nbsp;it equals <code>Y</code>. Also two strings <code>X</code> and <code>Y</code> are similar if they are equal.</p>

<p>For example, <code>&quot;tars&quot;</code>&nbsp;and <code>&quot;rats&quot;</code>&nbsp;are similar (swapping at positions <code>0</code> and <code>2</code>), and <code>&quot;rats&quot;</code> and <code>&quot;arts&quot;</code> are similar, but <code>&quot;star&quot;</code> is not similar to <code>&quot;tars&quot;</code>, <code>&quot;rats&quot;</code>, or <code>&quot;arts&quot;</code>.</p>

<p>Together, these form two connected groups by similarity: <code>{&quot;tars&quot;, &quot;rats&quot;, &quot;arts&quot;}</code> and <code>{&quot;star&quot;}</code>.&nbsp; Notice that <code>&quot;tars&quot;</code> and <code>&quot;arts&quot;</code> are in the same group even though they are not similar.&nbsp; Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.</p>

<p>We are given a list <code>strs</code> of strings where every string in <code>strs</code> is an anagram of every other string in <code>strs</code>. How many groups are there?</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> strs = [&quot;tars&quot;,&quot;rats&quot;,&quot;arts&quot;,&quot;star&quot;]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> strs = [&quot;omv&quot;,&quot;ovm&quot;]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 300</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 300</code></li>
	<li><code>strs[i]</code> consists of lowercase letters only.</li>
	<li>All words in <code>strs</code> have the same length and are anagrams of each other.</li>
</ul>


## Solution

``` cpp
struct UnionSet {
  vector<int> parent;
public:
  UnionSet(int size): parent(size) {
    for(int i = 0; i < size; ++i) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
  }
};
class Solution {
  int len;
  bool isSimilar(const string &a, const string &b) {
    int pos1 = -1;
    int pos = 0;
    while(pos < len && a[pos] == b[pos]) {
      pos += 1;
    }
    if(pos == len) return true;
    pos1 = pos;
    pos += 1;
    while(pos < len && a[pos] == b[pos]) {
      pos += 1;
    }
    if(pos == len) return false;
    if(a[pos1] != b[pos] || b[pos1] != a[pos]) return false;
    pos += 1;
    while(pos < len && a[pos] == b[pos]) {
      pos += 1;
    }
    return pos == len;
  }
public:
  int numSimilarGroups(vector<string>& strs) {
    UnionSet us(strs.size());
    len = strs.front().length();

    int answer = strs.size();
    for(int i = 0; i < strs.size() - 1; ++i) {
      for(int j = i + 1; j < strs.size(); ++j) {
        if(isSimilar(strs[i], strs[j]) && us.find(i) != us.find(j)) {
          us.merge(i, j);
          answer -= 1;
        }
      }
    }

    return answer;
  }
};

// Accepted
// 77/77 cases passed (30 ms)
// Your runtime beats 80.63 % of cpp submissions
// Your memory usage beats 76.83 % of cpp submissions (10.1 MB)
```
