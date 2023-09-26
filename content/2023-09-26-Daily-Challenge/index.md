+++
updated = 2023-09-26T08:19:33+08:00
title = "2023-09-26 Daily Challenge"
path = "2023-09-26-Daily-Challenge"
date = 2023-09-26T08:19:33+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/remove-duplicate-letters/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 26

## Description

**Remove Duplicate Letters**

<p>Given a string <code>s</code>, remove duplicate letters so that every letter appears once and only once. You must make sure your result is <span data-keyword="lexicographically-smaller-string"><strong>the smallest in lexicographical order</strong></span> among all possible results.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;bcabc&quot;
<strong>Output:</strong> &quot;abc&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;cbacdcbc&quot;
<strong>Output:</strong> &quot;acdb&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Note:</strong> This question is the same as 1081: <a href="https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/" target="_blank">https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/</a></p>


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
  string removeDuplicateLetters(string s) {
    vector<int> cnt(26);
    vector<int> used(26);
    for(auto c : s) {
      cnt[c - 'a'] += 1;
    }

    string answer;
    for(auto c : s) {
      if(used[c - 'a']) {
        cnt[c - 'a'] -= 1;
        continue;
      }
      while(answer.length() && answer.back() > c && cnt[answer.back() - 'a']) {
        used[answer.back() - 'a'] = false;
        answer.pop_back();
      }
      answer.push_back(c);
      used[c - 'a'] = true;
      cnt[c - 'a'] -= 1;
    }
    return answer;
  }
};

// Accepted
// 290/290 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 49.69 % of cpp submissions (6.9 MB)
```
