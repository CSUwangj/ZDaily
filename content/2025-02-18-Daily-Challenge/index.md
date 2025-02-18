+++
updated = 2025-02-18T23:34:58+08:00
title = "2025-02-18 Daily Challenge"
path = "2025-02-18-Daily-Challenge"
date = 2025-02-18T23:34:58+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/construct-smallest-number-from-di-string/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 18

## Description

**Construct Smallest Number From DI String**

<p>You are given a <strong>0-indexed</strong> string <code>pattern</code> of length <code>n</code> consisting of the characters <code>&#39;I&#39;</code> meaning <strong>increasing</strong> and <code>&#39;D&#39;</code> meaning <strong>decreasing</strong>.</p>

<p>A <strong>0-indexed</strong> string <code>num</code> of length <code>n + 1</code> is created using the following conditions:</p>

<ul>
	<li><code>num</code> consists of the digits <code>&#39;1&#39;</code> to <code>&#39;9&#39;</code>, where each digit is used <strong>at most</strong> once.</li>
	<li>If <code>pattern[i] == &#39;I&#39;</code>, then <code>num[i] &lt; num[i + 1]</code>.</li>
	<li>If <code>pattern[i] == &#39;D&#39;</code>, then <code>num[i] &gt; num[i + 1]</code>.</li>
</ul>

<p>Return <em>the lexicographically <strong>smallest</strong> possible string </em><code>num</code><em> that meets the conditions.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> pattern = &quot;IIIDIDDD&quot;
<strong>Output:</strong> &quot;123549876&quot;
<strong>Explanation:
</strong>At indices 0, 1, 2, and 4 we must have that num[i] &lt; num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] &gt; num[i+1].
Some possible values of num are &quot;245639871&quot;, &quot;135749862&quot;, and &quot;123849765&quot;.
It can be proven that &quot;123549876&quot; is the smallest possible num that meets the conditions.
Note that &quot;123414321&quot; is not possible because the digit &#39;1&#39; is used more than once.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> pattern = &quot;DDD&quot;
<strong>Output:</strong> &quot;4321&quot;
<strong>Explanation:</strong>
Some possible values of num are &quot;9876&quot;, &quot;7321&quot;, and &quot;8742&quot;.
It can be proven that &quot;4321&quot; is the smallest possible num that meets the conditions.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= pattern.length &lt;= 8</code></li>
	<li><code>pattern</code> consists of only the letters <code>&#39;I&#39;</code> and <code>&#39;D&#39;</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
  bool solve(
    string &result,
    const string &pattern,
    vector<bool> &used,
    int pos
  ) {
    if(pos == pattern.size()) return true;
    char begin = -1;
    char end = -1;
    if(pattern[pos] == 'I') {
      begin = result[pos] + 1;
      end = '9' + 1;
    } else {
      begin = '1';
      end = result[pos];
    }
    for(char c = begin; c < end; ++c) {
      if(used[c - '1']) continue;
      result[pos + 1] = c;
      used[c - '1'] = true;
      if(solve(result, pattern, used, pos + 1)) return true;
      used[c - '1'] = false;
    }
    return false;
  }
public:
  string smallestNumber(string pattern) {
    vector<bool> used(10);
    string answer;
    answer.resize(pattern.size() + 1);
    for(int i = 0; i < 9; ++i) {
      answer[0] = '1' + i;
      used[i] = true;
      if(solve(answer, pattern, used, 0)) break;
      used[i] = false;
    }
    return answer;
  }
};

// Accepted
// 104/104 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 73.43 % of cpp submissions (7.9 MB)
```
