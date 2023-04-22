+++
updated = 2023-04-22T17:45:32+08:00
title = "2023-04-22 Daily Challenge"
path = "2023-04-22-Daily-Challenge"
date = 2023-04-22T17:45:32+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 22

## Description

**Minimum Insertion Steps to Make a String Palindrome**

<p>Given a string <code>s</code>. In one step you can insert any character at any index of the string.</p>

<p>Return <em>the minimum number of steps</em> to make <code>s</code>&nbsp;palindrome.</p>

<p>A&nbsp;<b>Palindrome String</b>&nbsp;is one that reads the same backward as well as forward.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;zzazz&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong> The string &quot;zzazz&quot; is already palindrome we do not need any insertions.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;mbadm&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> String can be &quot;mbdadbm&quot; or &quot;mdbabdm&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;leetcode&quot;
<strong>Output:</strong> 5
<strong>Explanation:</strong> Inserting 5 characters the string becomes &quot;leetcodocteel&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


## Solution

``` cpp
auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
  int LCS(string &s1, string &s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    // cout << "$$$$$$";
    vector<vector<int>> dp(2, vector<int>(len2 + 1));
    for(int i = 0; i < len1; ++i) {
      for(int j = 1; j <= len2; ++j) {
        int parity = i & 1;
        dp[parity][j] = max(dp[!parity][j], dp[parity][j - 1]);
        if(s2[j - 1] == s1[i]) {
          dp[parity][j] = max(dp[parity][j], dp[!parity][j - 1] + 1);
        }
      }
    }
    return dp[!(len1 & 1)][len2];
  }
  bool isPalindrome(string &s) {
    int len = s.length();
    for(int i = 0; i * 2 < len; ++i) {
      if(s[i] != s[len - 1 - i]) return false;
    }
    return true;
  }
public:
  int minInsertions(string s) {
    if(isPalindrome(s)) return 0;
    string r = s;
    reverse(r.begin(), r.end());
    return s.length() - LCS(s, r);
  }
};

// Accepted
// 58/58 cases passed (71 ms)
// Your runtime beats 57.64 % of cpp submissions
// Your memory usage beats 89.32 % of cpp submissions (6.8 MB)
```
