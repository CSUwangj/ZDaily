+++
updated = 2025-03-11T03:36:32+08:00
title = "2025-03-10 Daily Challenge"
path = "2025-03-10-Daily-Challenge"
date = 2025-03-11T03:36:32+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 10

## Description

**Count of Substrings Containing Every Vowel and K Consonants II**

<p>You are given a string <code>word</code> and a <strong>non-negative</strong> integer <code>k</code>.</p>

<p>Return the total number of <span data-keyword="substring-nonempty">substrings</span> of <code>word</code> that contain every vowel (<code>&#39;a&#39;</code>, <code>&#39;e&#39;</code>, <code>&#39;i&#39;</code>, <code>&#39;o&#39;</code>, and <code>&#39;u&#39;</code>) <strong>at least</strong> once and <strong>exactly</strong> <code>k</code> consonants.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;aeioqq&quot;, k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>There is no substring with every vowel.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;aeiou&quot;, k = 0</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>The only substring with every vowel and zero consonants is <code>word[0..4]</code>, which is <code>&quot;aeiou&quot;</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;</span>ieaouqqieaouqq<span class="example-io">&quot;, k = 1</span></p>

<p><strong>Output:</strong> 3</p>

<p><strong>Explanation:</strong></p>

<p>The substrings with every vowel and one consonant are:</p>

<ul>
	<li><code>word[0..5]</code>, which is <code>&quot;ieaouq&quot;</code>.</li>
	<li><code>word[6..11]</code>, which is <code>&quot;qieaou&quot;</code>.</li>
	<li><code>word[7..12]</code>, which is <code>&quot;ieaouq&quot;</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>5 &lt;= word.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>word</code> consists only of lowercase English letters.</li>
	<li><code>0 &lt;= k &lt;= word.length - 5</code></li>
</ul>


## Solution

``` cpp
inline bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
class Solution {
  long long geK(string word, int k) {
    long long result = 0;
    int start = 0;
    unordered_map<char, int> vowelCount;
    int consonants = 0;

    for(int end = 0; end < word.length(); ++end) {
      char c = word[end];
      if(isVowel(c)) {
        vowelCount[c] += 1;
      } else {
        consonants += 1;
      }

      while(vowelCount.size() == 5 && consonants >= k) {
        result += word.length() - end;
        char cs = word[start];
        if(isVowel(cs)) {
          vowelCount[cs] -= 1;
          if(!vowelCount[cs]) vowelCount.erase(cs);
        } else {
          consonants -= 1;
        }
        start += 1;
      }
    }
    return result;
  }
public:
  long long countOfSubstrings(string word, int k) {
    return geK(word, k) - geK(word, k + 1);
  }
};

// Accepted
// 768/768 cases passed (196 ms)
// Your runtime beats 51.12 % of cpp submissions
// Your memory usage beats 55.62 % of cpp submissions (48.7 MB)
```
