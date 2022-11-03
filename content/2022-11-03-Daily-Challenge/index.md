+++
updated = 2022-11-03T12:06:43+08:00
title = "2022-11-03 Daily Challenge"
path = "2022-11-03-Daily-Challenge"
date = 2022-11-03T12:06:43+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 3

## Description

**Longest Palindrome by Concatenating Two Letter Words**

<p>You are given an array of strings <code>words</code>. Each element of <code>words</code> consists of <strong>two</strong> lowercase English letters.</p>

<p>Create the <strong>longest possible palindrome</strong> by selecting some elements from <code>words</code> and concatenating them in <strong>any order</strong>. Each element can be selected <strong>at most once</strong>.</p>

<p>Return <em>the <strong>length</strong> of the longest palindrome that you can create</em>. If it is impossible to create any palindrome, return <code>0</code>.</p>

<p>A <strong>palindrome</strong> is a string that reads the same forward and backward.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;lc&quot;,&quot;cl&quot;,&quot;gg&quot;]
<strong>Output:</strong> 6
<strong>Explanation:</strong> One longest palindrome is &quot;lc&quot; + &quot;gg&quot; + &quot;cl&quot; = &quot;lcggcl&quot;, of length 6.
Note that &quot;clgglc&quot; is another longest palindrome that can be created.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;ab&quot;,&quot;ty&quot;,&quot;yt&quot;,&quot;lc&quot;,&quot;cl&quot;,&quot;ab&quot;]
<strong>Output:</strong> 8
<strong>Explanation:</strong> One longest palindrome is &quot;ty&quot; + &quot;lc&quot; + &quot;cl&quot; + &quot;yt&quot; = &quot;tylcclyt&quot;, of length 8.
Note that &quot;lcyttycl&quot; is another longest palindrome that can be created.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;cc&quot;,&quot;ll&quot;,&quot;xx&quot;]
<strong>Output:</strong> 2
<strong>Explanation:</strong> One longest palindrome is &quot;cc&quot;, of length 2.
Note that &quot;ll&quot; is another longest palindrome that can be created, and so is &quot;xx&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 10<sup>5</sup></code></li>
	<li><code>words[i].length == 2</code></li>
	<li><code>words[i]</code> consists of lowercase English letters.</li>
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
  int longestPalindrome(vector<string>& words) {
    int count[26][26] = {};
    for(const auto &word : words) {
      count[word[0] - 'a'][word[1] - 'a'] += 1;
    }
    int answer = 0;
    for(int first = 0; first < 25; ++first) {
      for(int second = first + 1; second < 26; ++second) {
        if(count[first][second] && count[second][first]) {
          answer += min(count[first][second], count[second][first]) * 4;
        }
      }
    }
    bool hasMid = false;
    for(int i = 0; i < 26; ++i) {
      answer += (count[i][i] & (INT_MAX - 1)) * 2;
      hasMid |= count[i][i] & 1;
    }
    answer += hasMid * 2;
    return answer;
  }
};

// Accepted
// 120/120 cases passed (411 ms)
// Your runtime beats 90.95 % of cpp submissions
// Your memory usage beats 100.00 % of cpp submissions (166.9 MB)
```
