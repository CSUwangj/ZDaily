+++
updated = 2025-06-22T03:30:19+08:00
title = "2025-06-21 Daily Challenge"
path = "2025-06-21-Daily-Challenge"
date = 2025-06-22T03:30:19+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 21

## Description

**Minimum Deletions to Make String K-Special**

<p>You are given a string <code>word</code> and an integer <code>k</code>.</p>

<p>We consider <code>word</code> to be <strong>k-special</strong> if <code>|freq(word[i]) - freq(word[j])| &lt;= k</code> for all indices <code>i</code> and <code>j</code> in the string.</p>

<p>Here, <code>freq(x)</code> denotes the <span data-keyword="frequency-letter">frequency</span> of the character <code>x</code> in <code>word</code>, and <code>|y|</code> denotes the absolute value of <code>y</code>.</p>

<p>Return <em>the <strong>minimum</strong> number of characters you need to delete to make</em> <code>word</code> <strong><em>k-special</em></strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>Input: </strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">word = &quot;aabcaba&quot;, k = 0</span></p>

<p><strong>Output: </strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">3</span></p>

<p><strong>Explanation:</strong> We can make <code>word</code> <code>0</code>-special by deleting <code>2</code> occurrences of <code>&quot;a&quot;</code> and <code>1</code> occurrence of <code>&quot;c&quot;</code>. Therefore, <code>word</code> becomes equal to <code>&quot;baba&quot;</code> where <code>freq(&#39;a&#39;) == freq(&#39;b&#39;) == 2</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>Input: </strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">word = &quot;dabdcbdcdcd&quot;, k = 2</span></p>

<p><strong>Output: </strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">2</span></p>

<p><strong>Explanation:</strong> We can make <code>word</code> <code>2</code>-special by deleting <code>1</code> occurrence of <code>&quot;a&quot;</code> and <code>1</code> occurrence of <code>&quot;d&quot;</code>. Therefore, <code>word</code> becomes equal to &quot;bdcbdcdcd&quot; where <code>freq(&#39;b&#39;) == 2</code>, <code>freq(&#39;c&#39;) == 3</code>, and <code>freq(&#39;d&#39;) == 4</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>Input: </strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">word = &quot;aaabaaa&quot;, k = 2</span></p>

<p><strong>Output: </strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">1</span></p>

<p><strong>Explanation:</strong> We can make <code>word</code> <code>2</code>-special by deleting <code>1</code> occurrence of <code>&quot;b&quot;</code>. Therefore, <code>word</code> becomes equal to <code>&quot;aaaaaa&quot;</code> where each letter&#39;s frequency is now uniformly <code>6</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>word</code> consists only of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
  int tryThis(const vector<int> &count, int target, int k) {
    int result = 0;
    for(auto c : count) {
      if(c < target) result += c;
      else result += max(0, c - target - k);
    }
    return result;
  }
public:
  int minimumDeletions(string word, int k) {
    vector<int> count(26);
    for(auto c : word) {
      count[c - 'a'] += 1;
    }
    sort(count.begin(), count.end());
    int answer = INT_MAX;
    for(int i = 0; i < 26; ++i) {
      answer = min(answer, tryThis(count, count[i], k));
    }
    return answer;
  }
};

// Accepted
// 732/732 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 84.11 % of cpp submissions (19.2 MB)
```
