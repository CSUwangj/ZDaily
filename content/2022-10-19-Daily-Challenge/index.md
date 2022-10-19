+++
updated = 2022-10-19T13:02:56+08:00
title = "2022-10-19 Daily Challenge"
path = "2022-10-19-Daily-Challenge"
date = 2022-10-19T13:02:56+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/top-k-frequent-words/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 19

## Description

**Top K Frequent Words**

<p>Given an array of strings <code>words</code> and an integer <code>k</code>, return <em>the </em><code>k</code><em> most frequent strings</em>.</p>

<p>Return the answer <strong>sorted</strong> by <strong>the frequency</strong> from highest to lowest. Sort the words with the same frequency by their <strong>lexicographical order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;i&quot;,&quot;love&quot;,&quot;leetcode&quot;,&quot;i&quot;,&quot;love&quot;,&quot;coding&quot;], k = 2
<strong>Output:</strong> [&quot;i&quot;,&quot;love&quot;]
<strong>Explanation:</strong> &quot;i&quot; and &quot;love&quot; are the two most frequent words.
Note that &quot;i&quot; comes before &quot;love&quot; due to a lower alphabetical order.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;the&quot;,&quot;day&quot;,&quot;is&quot;,&quot;sunny&quot;,&quot;the&quot;,&quot;the&quot;,&quot;the&quot;,&quot;sunny&quot;,&quot;is&quot;,&quot;is&quot;], k = 4
<strong>Output:</strong> [&quot;the&quot;,&quot;is&quot;,&quot;sunny&quot;,&quot;day&quot;]
<strong>Explanation:</strong> &quot;the&quot;, &quot;is&quot;, &quot;sunny&quot; and &quot;day&quot; are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 500</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>words[i]</code> consists of lowercase English letters.</li>
	<li><code>k</code> is in the range <code>[1, The number of <strong>unique</strong> words[i]]</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow-up:</strong> Could you solve it in <code>O(n log(k))</code> time and <code>O(n)</code> extra space?</p>


## Solution

``` cpp
class Solution {
  using psi = pair<string, int>;
public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    map<string, int> count;
    for(const auto &word : words) {
      count[word] += 1;
    }
    vector<psi> container(count.begin(), count.end());
    sort(container.begin(), container.end(), [](const psi &a, const psi &b) {
      return a.second > b.second || (a.second == b.second && a.first < b.first);
    });
    vector<string> answer;
    transform(container.begin(), container.begin() + k, back_inserter(answer), [](const psi &a) {
      return a.first;
    });
    return move(answer);
  }
};

// Accepted
// 110/110 cases passed (15 ms)
// Your runtime beats 85.73 % of cpp submissions
// Your memory usage beats 88.37 % of cpp submissions (12.5 MB)
```
