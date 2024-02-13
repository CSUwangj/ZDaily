+++
updated = 2024-02-13T19:40:42+08:00
title = "2024-02-13 Daily Challenge"
path = "2024-02-13-Daily-Challenge"
date = 2024-02-13T19:40:42+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 13

## Description

**Find First Palindromic String in the Array**

<p>Given an array of strings <code>words</code>, return <em>the first <strong>palindromic</strong> string in the array</em>. If there is no such string, return <em>an <strong>empty string</strong> </em><code>&quot;&quot;</code>.</p>

<p>A string is <strong>palindromic</strong> if it reads the same forward and backward.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;abc&quot;,&quot;car&quot;,&quot;ada&quot;,&quot;racecar&quot;,&quot;cool&quot;]
<strong>Output:</strong> &quot;ada&quot;
<strong>Explanation:</strong> The first string that is palindromic is &quot;ada&quot;.
Note that &quot;racecar&quot; is also palindromic, but it is not the first.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;notapalindrome&quot;,&quot;racecar&quot;]
<strong>Output:</strong> &quot;racecar&quot;
<strong>Explanation:</strong> The first and only string that is palindromic is &quot;racecar&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;def&quot;,&quot;ghi&quot;]
<strong>Output:</strong> &quot;&quot;
<strong>Explanation:</strong> There are no palindromic strings, so the empty string is returned.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> consists only of lowercase English letters.</li>
</ul>


## Solution

``` cpp
bool isPalindrom(string word) {
  auto it = word.begin();
  auto rit = word.rbegin();
  while(it != word.end()) {
    if(*it != *rit) return false;
    ++it;
    ++rit;
  }
  return true;
}
class Solution {
public:
  string firstPalindrome(vector<string>& words) {
    for(auto word : words) {
      if(isPalindrom(word)) return word;
    }
    return "";
  }
};

// Accepted
// 266/266 cases passed (49 ms)
// Your runtime beats 54.9 % of cpp submissions
// Your memory usage beats 7.01 % of cpp submissions (30 MB)
```
