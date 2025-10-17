+++
updated = 2025-10-17T18:44:20+02:00
title = "2025-10-17 Daily Challenge"
path = "2025-10-17-Daily-Challenge"
date = 2025-10-17T18:44:20+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 17

## Description

**Maximize the Number of Partitions After Operations**

<p>You are given a string <code>s</code> and an integer <code>k</code>.</p>

<p>First, you are allowed to change <strong>at most</strong> <strong>one</strong> index in <code>s</code> to another lowercase English letter.</p>

<p>After that, do the following partitioning operation until <code>s</code> is <strong>empty</strong>:</p>

<ul>
	<li>Choose the <strong>longest</strong> <strong>prefix</strong> of <code>s</code> containing at most <code>k</code> <strong>distinct</strong> characters.</li>
	<li><strong>Delete</strong> the prefix from <code>s</code> and increase the number of partitions by one. The remaining characters (if any) in <code>s</code> maintain their initial order.</li>
</ul>

<p>Return an integer denoting the <strong>maximum</strong> number of resulting partitions after the operations by optimally choosing at most one index to change.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;accca&quot;, k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>The optimal way is to change <code>s[2]</code> to something other than a and c, for example, b. then it becomes <code>&quot;acbca&quot;</code>.</p>

<p>Then we perform the operations:</p>

<ol>
	<li>The longest prefix containing at most 2 distinct characters is <code>&quot;ac&quot;</code>, we remove it and <code>s</code> becomes <code>&quot;bca&quot;</code>.</li>
	<li>Now The longest prefix containing at most 2 distinct characters is <code>&quot;bc&quot;</code>, so we remove it and <code>s</code> becomes <code>&quot;a&quot;</code>.</li>
	<li>Finally, we remove <code>&quot;a&quot;</code> and <code>s</code> becomes empty, so the procedure ends.</li>
</ol>

<p>Doing the operations, the string is divided into 3 partitions, so the answer is 3.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;aabaab&quot;, k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>Initially&nbsp;<code>s</code>&nbsp;contains 2 distinct characters, so whichever character we change, it will contain at most 3 distinct characters, so the longest prefix with at most 3 distinct characters would always be all of it, therefore the answer is 1.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;xxyz&quot;, k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>The optimal way is to change&nbsp;<code>s[0]</code>&nbsp;or&nbsp;<code>s[1]</code>&nbsp;to something other than characters in&nbsp;<code>s</code>, for example, to change&nbsp;<code>s[0]</code>&nbsp;to&nbsp;<code>w</code>.</p>

<p>Then&nbsp;<code>s</code>&nbsp;becomes <code>&quot;wxyz&quot;</code>, which consists of 4 distinct characters, so as <code>k</code> is 1, it will divide into 4 partitions.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
	<li><code>1 &lt;= k &lt;= 26</code></li>
</ul>


## Solution

``` cpp
struct Data{
  short count = 0;
  short splits = 0;
  int mask = 0;
};
class Solution {
public:
  int maxPartitionsAfterOperations(string s, int k) {
    if(k == 26) return 1;
    int len = s.length();
    vector<Data> prefix(len);
    vector<Data> suffix(len);
    int mask = 0;
    int count = 0;
    int splits = 0;
    for(int i = 0; i < len - 1; prefix[i + 1].mask = mask, prefix[i + 1].splits = splits, prefix[i + 1].count = count, ++i) {
      int bit = (1 << (s[i] - 'a'));
      if(mask & bit) continue;
      count += 1;
      if(count <= k) {
        mask |= bit;
      } else {
        splits += 1;
        mask = bit;
        count = 1;
      }
    }
    mask = 0;
    count = 0;
    splits = 0;
    for(int i = len - 1; i ; suffix[i - 1].mask = mask, suffix[i - 1].splits = splits, suffix[i - 1].count = count, --i) {
      int bit = (1 << (s[i] - 'a'));
      if(mask & bit) continue;
      count += 1;
      if(count <= k) {
        mask |= bit;
      } else {
        splits += 1;
        mask = bit;
        count = 1;
      }
    }
    int answer = 0;
    for(int i = 0; i < len; ++i) {
      int segments = prefix[i].splits +suffix[i].splits + 2;
      int mask = prefix[i].mask | suffix[i].mask;
      int count = __builtin_popcount(mask);
      if(prefix[i].count == k && suffix[i].count == k && count < 26) {
        segments += 1;
      } else if(count + 1 <= k) {
        segments -= 1;
      }
      answer = max(answer, segments);
    }
    return answer;
  }
};

// Accepted
// 277/277 cases passed (1 ms)
// Your runtime beats 93.44 % of cpp submissions
// Your memory usage beats 99.18 % of cpp submissions (11 MB)
```
