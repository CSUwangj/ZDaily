+++
updated = 2023-09-23T10:11:53+08:00
title = "2023-09-23 Daily Challenge"
path = "2023-09-23-Daily-Challenge"
date = 2023-09-23T10:11:53+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/longest-string-chain/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 23

## Description

**Longest String Chain**

<p>You are given an array of <code>words</code> where each word consists of lowercase English letters.</p>

<p><code>word<sub>A</sub></code> is a <strong>predecessor</strong> of <code>word<sub>B</sub></code> if and only if we can insert <strong>exactly one</strong> letter anywhere in <code>word<sub>A</sub></code> <strong>without changing the order of the other characters</strong> to make it equal to <code>word<sub>B</sub></code>.</p>

<ul>
	<li>For example, <code>&quot;abc&quot;</code> is a <strong>predecessor</strong> of <code>&quot;ab<u>a</u>c&quot;</code>, while <code>&quot;cba&quot;</code> is not a <strong>predecessor</strong> of <code>&quot;bcad&quot;</code>.</li>
</ul>

<p>A <strong>word chain</strong><em> </em>is a sequence of words <code>[word<sub>1</sub>, word<sub>2</sub>, ..., word<sub>k</sub>]</code> with <code>k &gt;= 1</code>, where <code>word<sub>1</sub></code> is a <strong>predecessor</strong> of <code>word<sub>2</sub></code>, <code>word<sub>2</sub></code> is a <strong>predecessor</strong> of <code>word<sub>3</sub></code>, and so on. A single word is trivially a <strong>word chain</strong> with <code>k == 1</code>.</p>

<p>Return <em>the <strong>length</strong> of the <strong>longest possible word chain</strong> with words chosen from the given list of </em><code>words</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;a&quot;,&quot;b&quot;,&quot;ba&quot;,&quot;bca&quot;,&quot;bda&quot;,&quot;bdca&quot;]
<strong>Output:</strong> 4
<strong>Explanation</strong>: One of the longest word chains is [&quot;a&quot;,&quot;<u>b</u>a&quot;,&quot;b<u>d</u>a&quot;,&quot;bd<u>c</u>a&quot;].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;xbc&quot;,&quot;pcxbcf&quot;,&quot;xb&quot;,&quot;cxbc&quot;,&quot;pcxbc&quot;]
<strong>Output:</strong> 5
<strong>Explanation:</strong> All the words can be put in a word chain [&quot;xb&quot;, &quot;xb<u>c</u>&quot;, &quot;<u>c</u>xbc&quot;, &quot;<u>p</u>cxbc&quot;, &quot;pcxbc<u>f</u>&quot;].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;abcd&quot;,&quot;dbqca&quot;]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The trivial word chain [&quot;abcd&quot;] is one of the longest word chains.
[&quot;abcd&quot;,&quot;dbqca&quot;] is not a valid word chain because the ordering of the letters is changed.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 16</code></li>
	<li><code>words[i]</code> only consists of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
  bool isPredecessor(string &shorterWord, string &longerWord) {
    bool skip = false;
    int len = shorterWord.length();
    int pos = 0;
    while(pos < len) {
      if(skip && shorterWord[pos] != longerWord[pos + 1]) return false;
      if(shorterWord[pos] == longerWord[pos + skip]) pos += 1;
      else skip = true;
    }
    return true;
  }
public:
  int longestStrChain(vector<string>& words) {
    vector<string> strs[17];
    for(auto &word : words) {
      strs[word.length()].push_back(word);
    }
    unordered_map<string, int> len;
    int answer = 1;
    for(int i = 1; i < 17; ++i) {
      for(auto &longerWord : strs[i]) {
        for(auto &shorterWord : strs[i - 1]) {
          if(isPredecessor(shorterWord, longerWord)) {
            len[longerWord] = max(len[shorterWord] + 1, len[longerWord]);
            answer = max(answer, len[longerWord] + 1);
          }
        }
      }
    }
    return answer;
  }
};

// Accepted
// 84/84 cases passed (25 ms)
// Your runtime beats 99.65 % of cpp submissions
// Your memory usage beats 46.71 % of cpp submissions (18.3 MB)
```
