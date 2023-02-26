+++
updated = 2023-02-26T15:53:57+08:00
title = "2023-02-26 Daily Challenge"
path = "2023-02-26-Daily-Challenge"
date = 2023-02-26T15:53:57+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/edit-distance/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 26

## Description

**Edit Distance**

<p>Given two strings <code>word1</code> and <code>word2</code>, return <em>the minimum number of operations required to convert <code>word1</code> to <code>word2</code></em>.</p>

<p>You have the following three operations permitted on a word:</p>

<ul>
	<li>Insert a character</li>
	<li>Delete a character</li>
	<li>Replace a character</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> word1 = &quot;horse&quot;, word2 = &quot;ros&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
horse -&gt; rorse (replace &#39;h&#39; with &#39;r&#39;)
rorse -&gt; rose (remove &#39;r&#39;)
rose -&gt; ros (remove &#39;e&#39;)
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> word1 = &quot;intention&quot;, word2 = &quot;execution&quot;
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
intention -&gt; inention (remove &#39;t&#39;)
inention -&gt; enention (replace &#39;i&#39; with &#39;e&#39;)
enention -&gt; exention (replace &#39;n&#39; with &#39;x&#39;)
exention -&gt; exection (replace &#39;n&#39; with &#39;c&#39;)
exection -&gt; execution (insert &#39;u&#39;)
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= word1.length, word2.length &lt;= 500</code></li>
	<li><code>word1</code> and <code>word2</code> consist of lowercase English letters.</li>
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
  int minDistance(string word1, string word2) {
    int dp[501][501];
    int len1 = word1.length();
    int len2 = word2.length();
    for(int i = 0; i <= len1; ++i) {
      dp[i][0] = i;
    }
    for(int j = 0; j <= len2; ++j) {
      dp[0][j] = j;
    }
    for(int i = 0; i < len1; ++i) {
      for(int j = 0; j < len2; ++j) {
        dp[i + 1][j + 1] = min(dp[i][j + 1], dp[i + 1][j]) + 1;
        if(word1[i] != word2[j]) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
        else dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
        cout << dp[i + 1][j + 1] << ' ';
      }
      cout << endl;
    }
    return dp[len1][len2];
  }
};

// Accepted
// 1146/1146 cases passed (24 ms)
// Your runtime beats 27.06 % of cpp submissions
// Your memory usage beats 82.21 % of cpp submissions (7.2 MB)
```
