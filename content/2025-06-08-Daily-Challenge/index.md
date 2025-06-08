+++
updated = 2025-06-09T01:03:00+08:00
title = "2025-06-08 Daily Challenge"
path = "2025-06-08-Daily-Challenge"
date = 2025-06-09T01:03:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/lexicographical-numbers/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 8

## Description

**Lexicographical Numbers**

<p>Given an integer <code>n</code>, return all the numbers in the range <code>[1, n]</code> sorted in lexicographical order.</p>

<p>You must write an algorithm that runs in&nbsp;<code>O(n)</code>&nbsp;time and uses <code>O(1)</code> extra space.&nbsp;</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 13
<strong>Output:</strong> [1,10,11,12,13,2,3,4,5,6,7,8,9]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> [1,2]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  vector<int> lexicalOrder(int n) {
    int curInt = 1;
    vector<int> answer{1};
    while(answer.size() < n) {
      if(curInt * 10 <= n) {
        curInt *= 10;
        answer.push_back(curInt);
      } else {
        while(curInt % 10 == 9 || curInt == n) {
          int count = 1;
          curInt /= 10;
        }
        curInt += 1;
        answer.push_back(curInt);
      }
    }

    return answer;
  }
};

// Accepted
// 27/27 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 69.54 % of cpp submissions (14.1 MB)
```
