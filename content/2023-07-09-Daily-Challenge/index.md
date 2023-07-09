+++
updated = 2023-07-09T17:57:11+08:00
title = "2023-07-09 Daily Challenge"
path = "2023-07-09-Daily-Challenge"
date = 2023-07-09T17:57:11+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/substring-with-largest-variance/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 9

## Description

**Substring With Largest Variance**

<p>The <strong>variance</strong> of a string is defined as the largest difference between the number of occurrences of <strong>any</strong> <code>2</code> characters present in the string. Note the two characters may or may not be the same.</p>

<p>Given a string <code>s</code> consisting of lowercase English letters only, return <em>the <strong>largest variance</strong> possible among all <strong>substrings</strong> of</em> <code>s</code>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aababbb&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong>
All possible variances along with their respective substrings are listed below:
- Variance 0 for substrings &quot;a&quot;, &quot;aa&quot;, &quot;ab&quot;, &quot;abab&quot;, &quot;aababb&quot;, &quot;ba&quot;, &quot;b&quot;, &quot;bb&quot;, and &quot;bbb&quot;.
- Variance 1 for substrings &quot;aab&quot;, &quot;aba&quot;, &quot;abb&quot;, &quot;aabab&quot;, &quot;ababb&quot;, &quot;aababbb&quot;, and &quot;bab&quot;.
- Variance 2 for substrings &quot;aaba&quot;, &quot;ababbb&quot;, &quot;abbb&quot;, and &quot;babb&quot;.
- Variance 3 for substring &quot;babbb&quot;.
Since the largest possible variance is 3, we return it.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abcde&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong>
No letter occurs more than once in s, so the variance of every substring is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
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
  int solve(const string &s, int i, int j) {
    int c1 = 0;
    int c2 = 0;
    int result = 0;
    for(auto c : s) {
      if(c == i) {
        c1 += 1;
      } else if (c == j) {
        c2 += 1;
      }
      if(c1 < c2) {
        c1 = 0;
        c2 = 0;
      }
      if(c1 > c2 && c2) {
        result = max(result, c1 - c2);
      }
    }
    return result;
  }
public:
  int largestVariance(string s) {
    vector<int> cnt(26);
    for(auto &c : s) {
      c -= 'a';
      cnt[c] += 1;
    }
    string rs = s;
    reverse(s.begin(), s.end());

    int answer = 0;
    for(int i = 0; i < 26; ++i) {
      for(int j = 0; j < 26; ++j) {
        if(i == j || !cnt[i] || !cnt[j]) continue;
        answer = max(answer, solve(s, i, j));
        answer = max(answer, solve(rs, i, j));
      }
    }

    return answer;
  }
};

// Accepted
// 138/138 cases passed (333 ms)
// Your runtime beats 25.79 % of cpp submissions
// Your memory usage beats 28.93 % of cpp submissions (7 MB)
```
