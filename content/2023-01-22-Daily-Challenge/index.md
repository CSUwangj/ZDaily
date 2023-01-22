+++
updated = 2023-01-22T13:03:22+08:00
title = "2023-01-22 Daily Challenge"
path = "2023-01-22-Daily-Challenge"
date = 2023-01-22T13:03:22+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/palindrome-partitioning/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 22

## Description

**Palindrome Partitioning**

<p>Given a string <code>s</code>, partition <code>s</code> such that every <span data-keyword="substring-nonempty">substring</span> of the partition is a <span data-keyword="palindrome-string"><strong>palindrome</strong></span>. Return <em>all possible palindrome partitioning of </em><code>s</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "aab"
<strong>Output:</strong> [["a","a","b"],["aa","b"]]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "a"
<strong>Output:</strong> [["a"]]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 16</code></li>
	<li><code>s</code> contains only lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
  int len;
  vector<vector<bool>> isPalindrome;
  
  void init(string &s) {
    len = s.length();
    isPalindrome.resize(len+1, vector<bool>(len+1));
    for(int i = 0; i < len; ++i) {
      isPalindrome[i][i] = true;
      isPalindrome[i][i+1] = true;
    }
    for(int i = 2; i <= len; ++i) {
      for(int j = 0; j+i <= len; ++j) {
        isPalindrome[j][j+i] = isPalindrome[j+1][j+i-1] && (s[j] == s[j+i-1]);
      }
    }
  }
    
  void dfs(vector<vector<string>> &answer, vector<string> &container, string &s, int index) {
    if(index == len) {
      answer.push_back(container);
    }
    for(int i = 1; index+i <= len; ++i) {
      if(isPalindrome[index][index+i]) {
        container.push_back(s.substr(index, i));
        dfs(answer, container, s, index+i);
        container.pop_back();
      }
    }
  }
public:
  vector<vector<string>> partition(string s) {
    init(s);
    vector<vector<string>> answer;
    vector<string> container;
    dfs(answer, container, s, 0);
    return answer;
  }
};


// Accepted
// 32/32 cases passed (116 ms)
// Your runtime beats 85.51 % of cpp submissions
// Your memory usage beats 80.3 % of cpp submissions (49.4 MB)
```
