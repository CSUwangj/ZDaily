+++
updated = 2025-06-12T02:07:37+08:00
title = "2025-06-11 Daily Challenge"
path = "2025-06-11-Daily-Challenge"
date = 2025-06-12T02:07:37+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 11

## Description

**Maximum Difference Between Even and Odd Frequency II**

<p>You are given a string <code>s</code> and an integer <code>k</code>. Your task is to find the <strong>maximum</strong> difference between the frequency of <strong>two</strong> characters, <code>freq[a] - freq[b]</code>, in a <span data-keyword="substring">substring</span> <code>subs</code> of <code>s</code>, such that:</p>

<ul>
	<li><code>subs</code> has a size of <strong>at least</strong> <code>k</code>.</li>
	<li>Character <code>a</code> has an <em>odd frequency</em> in <code>subs</code>.</li>
	<li>Character <code>b</code> has an <em>even frequency</em> in <code>subs</code>.</li>
</ul>

<p>Return the <strong>maximum</strong> difference.</p>

<p><strong>Note</strong> that <code>subs</code> can contain more than 2 <strong>distinct</strong> characters.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;12233&quot;, k = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>

<p><strong>Explanation:</strong></p>

<p>For the substring <code>&quot;12233&quot;</code>, the frequency of <code>&#39;1&#39;</code> is 1 and the frequency of <code>&#39;3&#39;</code> is 2. The difference is <code>1 - 2 = -1</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;1122211&quot;, k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>For the substring <code>&quot;11222&quot;</code>, the frequency of <code>&#39;2&#39;</code> is 3 and the frequency of <code>&#39;1&#39;</code> is 2. The difference is <code>3 - 2 = 1</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;110&quot;, k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>s</code> consists only of digits <code>&#39;0&#39;</code> to <code>&#39;4&#39;</code>.</li>
	<li>The input is generated that at least one substring has a character with an even frequency and a character with an odd frequency.</li>
	<li><code>1 &lt;= k &lt;= s.length</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int maxDifference(string s, int k) {
    int len = s.length();
    int answer = INT_MIN;

    for(int a = 0; a < 5; ++a) {
      for(int b = 0; b < 5; ++b) {
        if(a == b) continue;

        vector<int> prefixA(len + 1);
        vector<int> prefixB(len + 1);
        for(int i = 0; i < len; ++i) {
          prefixA[i + 1] = prefixA[i] + (s[i] == a + '0');
          prefixB[i + 1] = prefixB[i] + (s[i] == b + '0');
        }

        int maxParityAB[2][2] = {{INT_MIN, INT_MIN}, {INT_MIN, INT_MIN}};
        int begin = 0;
        for(int end = k; end <= len; ++end) {
          while(end - begin >= k && prefixA[end] > prefixA[begin] && prefixB[end] > prefixB[begin]) {
            int parityA = prefixA[begin] % 2;
            int parityB = prefixB[begin] % 2;

            maxParityAB[parityA][parityB] = max(maxParityAB[parityA][parityB], prefixB[begin] - prefixA[begin]);
            begin += 1;
          }

          int parityA = prefixA[end] % 2;
          int parityB = prefixB[end] % 2;
          int need = maxParityAB[1 - parityA][parityB];

          if(need != INT_MIN) {
            answer = max(answer, prefixA[end] - prefixB[end] + need);
          }
        }
      }
    }

    if(answer == INT_MIN) answer = -1;
    return answer;
  }
};

// Accepted
// 690/690 cases passed (101 ms)
// Your runtime beats 64.1 % of cpp submissions
// Your memory usage beats 56.41 % of cpp submissions (72.2 MB)
```
