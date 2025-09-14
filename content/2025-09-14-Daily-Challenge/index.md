+++
updated = 2025-09-14T19:08:23+02:00
title = "2025-09-14 Daily Challenge"
path = "2025-09-14-Daily-Challenge"
date = 2025-09-14T19:08:23+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/vowel-spellchecker/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 14

## Description

**Vowel Spellchecker**

<p>Given a <code>wordlist</code>, we want to implement a spellchecker that converts a query word into a correct word.</p>

<p>For a given <code>query</code> word, the spell checker handles two categories of spelling mistakes:</p>

<ul>
	<li>Capitalization: If the query matches a word in the wordlist (<strong>case-insensitive</strong>), then the query word is returned with the same case as the case in the wordlist.

	<ul>
		<li>Example: <code>wordlist = [&quot;yellow&quot;]</code>, <code>query = &quot;YellOw&quot;</code>: <code>correct = &quot;yellow&quot;</code></li>
		<li>Example: <code>wordlist = [&quot;Yellow&quot;]</code>, <code>query = &quot;yellow&quot;</code>: <code>correct = &quot;Yellow&quot;</code></li>
		<li>Example: <code>wordlist = [&quot;yellow&quot;]</code>, <code>query = &quot;yellow&quot;</code>: <code>correct = &quot;yellow&quot;</code></li>
	</ul>
	</li>
	<li>Vowel Errors: If after replacing the vowels <code>(&#39;a&#39;, &#39;e&#39;, &#39;i&#39;, &#39;o&#39;, &#39;u&#39;)</code> of the query word with any vowel individually, it matches a word in the wordlist (<strong>case-insensitive</strong>), then the query word is returned with the same case as the match in the wordlist.
	<ul>
		<li>Example: <code>wordlist = [&quot;YellOw&quot;]</code>, <code>query = &quot;yollow&quot;</code>: <code>correct = &quot;YellOw&quot;</code></li>
		<li>Example: <code>wordlist = [&quot;YellOw&quot;]</code>, <code>query = &quot;yeellow&quot;</code>: <code>correct = &quot;&quot;</code> (no match)</li>
		<li>Example: <code>wordlist = [&quot;YellOw&quot;]</code>, <code>query = &quot;yllw&quot;</code>: <code>correct = &quot;&quot;</code> (no match)</li>
	</ul>
	</li>
</ul>

<p>In addition, the spell checker operates under the following precedence rules:</p>

<ul>
	<li>When the query exactly matches a word in the wordlist (<strong>case-sensitive</strong>), you should return the same word back.</li>
	<li>When the query matches a word up to capitlization, you should return the first such match in the wordlist.</li>
	<li>When the query matches a word up to vowel errors, you should return the first such match in the wordlist.</li>
	<li>If the query has no matches in the wordlist, you should return the empty string.</li>
</ul>

<p>Given some <code>queries</code>, return a list of words <code>answer</code>, where <code>answer[i]</code> is the correct word for <code>query = queries[i]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
<strong>Output:</strong> ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> wordlist = ["yellow"], queries = ["YellOw"]
<strong>Output:</strong> ["yellow"]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= wordlist.length, queries.length &lt;= 5000</code></li>
	<li><code>1 &lt;= wordlist[i].length, queries[i].length &lt;= 7</code></li>
	<li><code>wordlist[i]</code> and <code>queries[i]</code> consist only of only English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
  string stringTolower(string word) {
    for(auto &c : word) c = tolower(c);
    return word;
  }
  
  string vowelUnify(string word) {
    word = stringTolower(word);
    for(auto &c : word) {
      switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
          c = '?';
      }
    }
    return word;
  }
public:
  vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    unordered_set<string> words(wordlist.begin(), wordlist.end());
    unordered_map<string, string> capitError;
    unordered_map<string, string> vowelError;
    for(auto word : wordlist) {
      string vowel = vowelUnify(word);
      if(!vowelError.count(vowel)) vowelError[vowel] = word;
      string lower = stringTolower(word);
      if(!capitError.count(lower)) capitError[lower] = word;
    }
    
    vector<string> answer;
    for(auto query : queries) {
      if(words.count(query)) {
        answer.push_back(query);
        continue;
      }
      string lower = stringTolower(query);
      if(capitError.count(lower)) {
        answer.push_back(capitError[lower]);
        continue;
      }
      string vowel = vowelUnify(query);
      if(vowelError.count(vowel)) {
        answer.push_back(vowelError[vowel]);
        continue;
      }
      answer.push_back("");
    }
    
    return answer;
  }
};

// Accepted
// 55/55 cases passed (42 ms)
// Your runtime beats 49.37 % of cpp submissions
// Your memory usage beats 30.38 % of cpp submissions (42.7 MB)
```
