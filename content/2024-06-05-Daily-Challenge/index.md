+++
updated = 2024-06-05T09:34:08+08:00
title = "2024-06-05 Daily Challenge"
path = "2024-06-05-Daily-Challenge"
date = 2024-06-05T09:34:08+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/find-common-characters/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 5

## Description

**Find Common Characters**

<p>Given a string array <code>words</code>, return <em>an array of all characters that show up in all strings within the </em><code>words</code><em> (including duplicates)</em>. You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> words = ["bella","label","roller"]
<strong>Output:</strong> ["e","l","l"]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> words = ["cool","lock","cook"]
<strong>Output:</strong> ["c","o"]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> consists of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<string> commonChars(vector<string>& words) {
    map<char, int> answerCount;
    for(int i = 'a'; i <= 'z'; ++i) answerCount[i] = 100;
    for(const auto &word : words) {
      map<char, int> result;
      for(auto c : word) result[c] += 1;
      for(int i = 'a'; i <= 'z'; ++i) {
        answerCount[i] = min(answerCount[i], result[i]);
      }
    }
    vector<string> answer;
    for(auto [c, times] : answerCount) {
      for(int i = 0; i < times; ++i) {
        answer.push_back(string(1, c)) ;
      }
    }
    return answer;
  }
};
```
