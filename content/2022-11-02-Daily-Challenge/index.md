+++
updated = 2022-11-02T12:14:32+08:00
title = "2022-11-02 Daily Challenge"
path = "2022-11-02-Daily-Challenge"
date = 2022-11-02T12:14:32+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/minimum-genetic-mutation/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 2

## Description

**Minimum Genetic Mutation**

<p>A gene string can be represented by an 8-character long string, with choices from <code>&#39;A&#39;</code>, <code>&#39;C&#39;</code>, <code>&#39;G&#39;</code>, and <code>&#39;T&#39;</code>.</p>

<p>Suppose we need to investigate a mutation from a gene string <code>start</code> to a gene string <code>end</code> where one mutation is defined as one single character changed in the gene string.</p>

<ul>
	<li>For example, <code>&quot;AACCGGTT&quot; --&gt; &quot;AACCGGTA&quot;</code> is one mutation.</li>
</ul>

<p>There is also a gene bank <code>bank</code> that records all the valid gene mutations. A gene must be in <code>bank</code> to make it a valid gene string.</p>

<p>Given the two gene strings <code>start</code> and <code>end</code> and the gene bank <code>bank</code>, return <em>the minimum number of mutations needed to mutate from </em><code>start</code><em> to </em><code>end</code>. If there is no such a mutation, return <code>-1</code>.</p>

<p>Note that the starting point is assumed to be valid, so it might not be included in the bank.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> start = &quot;AACCGGTT&quot;, end = &quot;AACCGGTA&quot;, bank = [&quot;AACCGGTA&quot;]
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> start = &quot;AACCGGTT&quot;, end = &quot;AAACGGTA&quot;, bank = [&quot;AACCGGTA&quot;,&quot;AACCGCTA&quot;,&quot;AAACGGTA&quot;]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> start = &quot;AAAAACCC&quot;, end = &quot;AACCCCCC&quot;, bank = [&quot;AAAACCCC&quot;,&quot;AAACCCCC&quot;,&quot;AACCCCCC&quot;]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>start.length == 8</code></li>
	<li><code>end.length == 8</code></li>
	<li><code>0 &lt;= bank.length &lt;= 10</code></li>
	<li><code>bank[i].length == 8</code></li>
	<li><code>start</code>, <code>end</code>, and <code>bank[i]</code> consist of only the characters <code>[&#39;A&#39;, &#39;C&#39;, &#39;G&#39;, &#39;T&#39;]</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
  const string chars = "ACGT";
public:
  int minMutation(string start, string end, vector<string>& bank) {
    if(start == end) return 0;
    set<string> valid(bank.begin(), bank.end());
    if(!valid.count(end)) return -1;
    valid.erase(start);
    queue<string> q;
    q.push(start);
    int step = 0;
    while(q.size()) {
      int sz = q.size();
      while(sz--) {
        auto current = q.front();
        q.pop();
        if(current == end) return step;
        for(auto &c : current) {
          int origin = c;
          for(auto mutation : chars) {
            c = mutation;
            if(!valid.count(current)) continue;
            valid.erase(current);
            q.push(current);
          }
          c = origin;
        }
      }
      step += 1;
    }
    return -1;
  }
};

// Accepted
// 15/15 cases passed (5 ms)
// Your runtime beats 18.63 % of cpp submissions
// Your memory usage beats 81.49 % of cpp submissions (6.5 MB)
```
