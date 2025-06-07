+++
updated = 2025-06-08T03:20:47+08:00
title = "2025-06-07 Daily Challenge"
path = "2025-06-07-Daily-Challenge"
date = 2025-06-08T03:20:47+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 7

## Description

**Lexicographically Minimum String After Removing Stars**

<p>You are given a string <code>s</code>. It may contain any number of <code>&#39;*&#39;</code> characters. Your task is to remove all <code>&#39;*&#39;</code> characters.</p>

<p>While there is a <code>&#39;*&#39;</code>, do the following operation:</p>

<ul>
	<li>Delete the leftmost <code>&#39;*&#39;</code> and the <strong>smallest</strong> non-<code>&#39;*&#39;</code> character to its <em>left</em>. If there are several smallest characters, you can delete any of them.</li>
</ul>

<p>Return the <span data-keyword="lexicographically-smaller-string">lexicographically smallest</span> resulting string after removing all <code>&#39;*&#39;</code> characters.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;aaba*&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;aab&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>We should delete one of the <code>&#39;a&#39;</code> characters with <code>&#39;*&#39;</code>. If we choose <code>s[3]</code>, <code>s</code> becomes the lexicographically smallest.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;abc&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;abc&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>There is no <code>&#39;*&#39;</code> in the string.<!-- notionvc: ff07e34f-b1d6-41fb-9f83-5d0ba3c1ecde --></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists only of lowercase English letters and <code>&#39;*&#39;</code>.</li>
	<li>The input is generated such that it is possible to delete all <code>&#39;*&#39;</code> characters.</li>
</ul>


## Solution

``` cpp
template<typename T>
std::ostream& operator<<(std::ostream &out, const std::vector<T> &v) {
  if(v.size() == 0) {
    out << "[]" << std::endl;
    return out;
  }
  out << '[' << v[0];
  for(int i = 1; i < v.size(); ++i) {
    out << ", " << v[i];
  }
  out << ']';
  return out;
}
class Solution {
public:
  string clearStars(string s) {
    map<char, vector<int>> charPositions;
    int len = s.length();
    for(int i = 0; i < len; ++i) {
      if(isalpha(s[i])) {
        charPositions[s[i]].push_back(i);
      } else {
        char target = charPositions.begin()->first;
        charPositions[target].pop_back();
        if(charPositions[target].empty()) {
          charPositions.erase(target);
        }
      }
    }
    vector<int> result;
    for(auto [c, positions] : charPositions) {
      for(auto pos : positions) {
        result.push_back(1000 * pos + c);
      }
    }
    // cout << result << endl;
    sort(result.begin(), result.end());
    string answer(result.size(), ' ');
    for(int i = 0; i < result.size(); ++i) {
      answer[i] = result[i] % 1000;
    }
    return answer;
  }
};

// Accepted
// 602/602 cases passed (279 ms)
// Your runtime beats 19.94 % of cpp submissions
// Your memory usage beats 14.04 % of cpp submissions (112.3 MB)
```
