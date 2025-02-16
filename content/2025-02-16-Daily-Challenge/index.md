+++
updated = 2025-02-16T12:27:20+08:00
title = "2025-02-16 Daily Challenge"
path = "2025-02-16-Daily-Challenge"
date = 2025-02-16T12:27:20+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 16

## Description

**Construct the Lexicographically Largest Valid Sequence**

<p>Given an integer <code>n</code>, find a sequence that satisfies all of the following:</p>

<ul>
	<li>The integer <code>1</code> occurs once in the sequence.</li>
	<li>Each integer between <code>2</code> and <code>n</code> occurs twice in the sequence.</li>
	<li>For every integer <code>i</code> between <code>2</code> and <code>n</code>, the <strong>distance</strong> between the two occurrences of <code>i</code> is exactly <code>i</code>.</li>
</ul>

<p>The <strong>distance</strong> between two numbers on the sequence, <code>a[i]</code> and <code>a[j]</code>, is the absolute difference of their indices, <code>|j - i|</code>.</p>

<p>Return <em>the <strong>lexicographically largest</strong> sequence</em><em>. It is guaranteed that under the given constraints, there is always a solution. </em></p>

<p>A sequence <code>a</code> is lexicographically larger than a sequence <code>b</code> (of the same length) if in the first position where <code>a</code> and <code>b</code> differ, sequence <code>a</code> has a number greater than the corresponding number in <code>b</code>. For example, <code>[0,1,9,0]</code> is lexicographically larger than <code>[0,1,5,6]</code> because the first position they differ is at the third number, and <code>9</code> is greater than <code>5</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> [3,1,2,3,2]
<strong>Explanation:</strong> [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 5
<strong>Output:</strong> [5,3,1,4,3,5,2,4,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 20</code></li>
</ul>


## Solution

``` cpp
class Solution {
  vector<bool> vis;
  vector<int> answer;
  int n;
  bool solve(int index) {
    if(index == 2 * n - 1) return true;
    // cout << "#" << answer << endl;
    if(answer[index]) return solve(index + 1);
    for(int i = min(n, 2 * n - 2 - index); i > 1 ; --i) {
      // cout << index << ' ' << i << endl;
      if(vis[i]) continue;
      // cout << "???" << endl;
      if(i != 1 && answer[i + index]) continue;
      // cout << "????" << endl;
      answer[index] = i;
      answer[index + i] = i;
      vis[i] = true;
      if(solve(index + 1)) return true;
      answer[index] = 0;
      answer[index + i] = 0;
      vis[i] = false;
    }
    if(!vis[1]) {
      answer[index] = 1;
      vis[1] = true;
      if(solve(index + 1)) return true;
      vis[1] = false;
      answer[index] = 0;
    }
    return false;
  }
public:
  vector<int> constructDistancedSequence(int n) {
    this->n = n;
    vis.resize(n + 1);
    answer.resize(n * 2 - 1);
    solve(0);
    return answer;
  }
};

// Accepted
// 20/20 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 36.8 % of cpp submissions (8.6 MB)
```
