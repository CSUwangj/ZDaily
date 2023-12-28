+++
updated = 2023-12-28T14:32:29+08:00
title = "2023-12-28 Daily Challenge"
path = "2023-12-28-Daily-Challenge"
date = 2023-12-28T14:32:29+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/string-compression-ii/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 28

## Description

**String Compression II**

<p><a href="http://en.wikipedia.org/wiki/Run-length_encoding">Run-length encoding</a> is a string compression method that works by&nbsp;replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string&nbsp;<code>&quot;aabccc&quot;</code>&nbsp;we replace <font face="monospace"><code>&quot;aa&quot;</code></font>&nbsp;by&nbsp;<font face="monospace"><code>&quot;a2&quot;</code></font>&nbsp;and replace <font face="monospace"><code>&quot;ccc&quot;</code></font>&nbsp;by&nbsp;<font face="monospace"><code>&quot;c3&quot;</code></font>. Thus the compressed string becomes <font face="monospace"><code>&quot;a2bc3&quot;</code>.</font></p>

<p>Notice that in this problem, we are not adding&nbsp;<code>&#39;1&#39;</code>&nbsp;after single characters.</p>

<p>Given a&nbsp;string <code>s</code>&nbsp;and an integer <code>k</code>. You need to delete <strong>at most</strong>&nbsp;<code>k</code> characters from&nbsp;<code>s</code>&nbsp;such that the run-length encoded version of <code>s</code>&nbsp;has minimum length.</p>

<p>Find the <em>minimum length of the run-length encoded&nbsp;version of </em><code>s</code><em> after deleting at most </em><code>k</code><em> characters</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aaabcccd&quot;, k = 2
<strong>Output:</strong> 4
<b>Explanation: </b>Compressing s without deleting anything will give us &quot;a3bc3d&quot; of length 6. Deleting any of the characters &#39;a&#39; or &#39;c&#39; would at most decrease the length of the compressed string to 5, for instance delete 2 &#39;a&#39; then we will have s = &quot;abcccd&quot; which compressed is abc3d. Therefore, the optimal way is to delete &#39;b&#39; and &#39;d&#39;, then the compressed version of s will be &quot;a3c3&quot; of length 4.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aabbaa&quot;, k = 2
<strong>Output:</strong> 2
<b>Explanation: </b>If we delete both &#39;b&#39; characters, the resulting compressed string would be &quot;a4&quot; of length 2.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aaaaaaaaaaa&quot;, k = 0
<strong>Output:</strong> 3
<strong>Explanation: </strong>Since k is zero, we cannot delete anything. The compressed string is &quot;a11&quot; of length 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= s.length</code></li>
	<li><code>s</code> contains only lowercase English letters.</li>
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
  uint8_t memo[101][27][101][104] = {};
  string s;
  uint8_t solve(
    uint8_t pos,
    uint8_t last,
    uint8_t last_length,
    uint8_t to_delete
  ) {
    if(memo[pos][last][last_length][to_delete] != 255) {
      
      return memo[pos][last][last_length][to_delete];
    }
    if(pos + to_delete >= s.length()) {
      uint8_t add = !last_length ? 0 :
                    last_length == 1 ? 1 :
                    last_length < 10 ? 2 :
                    last_length < 100 ? 3 : 4;
      return memo[pos][last][last_length][to_delete] = add;
    }
    uint8_t result = 255;
    if(to_delete) {
      result = solve(pos + 1, last, last_length, to_delete - 1);
    }
    if(s[pos] - 'a' == last) {
      result = min(result, solve(pos + 1, last, last_length + 1, to_delete));
    } else {
      uint8_t add = !last_length ? 0 :
                    last_length == 1 ? 1 :
                    last_length < 10 ? 2 :
                    last_length < 100 ? 3 : 4;
      result = min<uint8_t>(result, add + solve(pos + 1, s[pos] - 'a', 1, to_delete));
    }
    return memo[pos][last][last_length][to_delete] = result;
  }
public:
  int getLengthOfOptimalCompression(string s, int k) {
    this->s = s;
    memset(memo, -1, sizeof(memo[0]) * (s.length() + 1));
    return solve(0, 26, 0, k);
  }
};

// Accepted
// 144/144 cases passed (1168 ms)
// Your runtime beats 8.99 % of cpp submissions
// Your memory usage beats 64.04 % of cpp submissions (38.2 MB)
```
