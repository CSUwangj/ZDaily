+++
updated = 2025-12-21T20:38:24+01:00
title = "2025-12-21 Daily Challenge"
path = "2025-12-21-Daily-Challenge"
date = 2025-12-21T20:38:24+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/delete-columns-to-make-sorted-ii/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 21

## Description

**Delete Columns to Make Sorted II**

<p>You are given an array of <code>n</code> strings <code>strs</code>, all of the same length.</p>

<p>We may choose any deletion indices, and we delete all the characters in those indices for each string.</p>

<p>For example, if we have <code>strs = [&quot;abcdef&quot;,&quot;uvwxyz&quot;]</code> and deletion indices <code>{0, 2, 3}</code>, then the final array after deletions is <code>[&quot;bef&quot;, &quot;vyz&quot;]</code>.</p>

<p>Suppose we chose a set of deletion indices <code>answer</code> such that after deletions, the final array has its elements in <strong>lexicographic</strong> order (i.e., <code>strs[0] &lt;= strs[1] &lt;= strs[2] &lt;= ... &lt;= strs[n - 1]</code>). Return <em>the minimum possible value of</em> <code>answer.length</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> strs = [&quot;ca&quot;,&quot;bb&quot;,&quot;ac&quot;]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
After deleting the first column, strs = [&quot;a&quot;, &quot;b&quot;, &quot;c&quot;].
Now strs is in lexicographic order (ie. strs[0] &lt;= strs[1] &lt;= strs[2]).
We require at least 1 deletion since initially strs was not in lexicographic order, so the answer is 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> strs = [&quot;xc&quot;,&quot;yb&quot;,&quot;za&quot;]
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
strs is already in lexicographic order, so we do not need to delete anything.
Note that the rows of strs are not necessarily in lexicographic order:
i.e., it is NOT necessarily true that (strs[0][0] &lt;= strs[0][1] &lt;= ...)
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> strs = [&quot;zyx&quot;,&quot;wvu&quot;,&quot;tsr&quot;]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We have to delete every column.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == strs.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 100</code></li>
	<li><code>strs[i]</code> consists of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int minDeletionSize(vector<string>& strs) {
    int sz = strs.size();
    int len = strs.front().length();

    vector<bool> solved(sz - 1, false);
    int unsolved = sz - 1;
    int answer = 0;

    for(int pos = 0; pos < len && unsolved; ++pos) {
      bool bad = false;

      for(int i = 0; !bad && i < sz - 1; ++i) {
        if(solved[i] || strs[i][pos] <= strs[i + 1][pos]) continue;
        bad = true;
      }

      if(bad) {
        answer += 1;
        continue;
      }

      for(int i = 0; i < sz - 1; ++i) {
        if(solved[i] || strs[i][pos] == strs[i + 1][pos]) continue;
        solved[i] = true;
        unsolved -= 1;
      }
    }
    return answer;
  }
};

// Accepted
// 147/147 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 17.99 % of cpp submissions (13 MB)
```
