+++
updated = 2025-09-16T00:30:25+02:00
title = "2025-09-15 Daily Challenge"
path = "2025-09-15-Daily-Challenge"
date = 2025-09-16T00:30:25+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/maximum-number-of-words-you-can-type/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 15

## Description

**Maximum Number of Words You Can Type**

<p>There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.</p>

<p>Given a string <code>text</code> of words separated by a single space (no leading or trailing spaces) and a string <code>brokenLetters</code> of all <strong>distinct</strong> letter keys that are broken, return <em>the <strong>number of words</strong> in</em> <code>text</code> <em>you can fully type using this keyboard</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> text = &quot;hello world&quot;, brokenLetters = &quot;ad&quot;
<strong>Output:</strong> 1
<strong>Explanation:</strong> We cannot type &quot;world&quot; because the &#39;d&#39; key is broken.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> text = &quot;leet code&quot;, brokenLetters = &quot;lt&quot;
<strong>Output:</strong> 1
<strong>Explanation:</strong> We cannot type &quot;leet&quot; because the &#39;l&#39; and &#39;t&#39; keys are broken.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> text = &quot;leet code&quot;, brokenLetters = &quot;e&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong> We cannot type either word because the &#39;e&#39; key is broken.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= brokenLetters.length &lt;= 26</code></li>
	<li><code>text</code> consists of words separated by a single space without any leading or trailing spaces.</li>
	<li>Each word only consists of lowercase English letters.</li>
	<li><code>brokenLetters</code> consists of <strong>distinct</strong> lowercase English letters.</li>
</ul>


## Solution

``` cpp
map<string, int> split(string &s, char spliter = ' ') {
  map<string, int> result;
  for(int i = 0; i < s.length(); ++i) {
    string st;
    while(i < s.length() && s[i] != spliter) {
      st += s[i];
      i += 1;
    }
    if(st.size()) result[st] += 1;
  }
  return result;
}
class Solution {
public:
  int canBeTypedWords(string text, string brokenLetters) {
    auto words = split(text);
    set<char> broken(brokenLetters.begin(), brokenLetters.end());
    int answer = 0;
    for(auto &[word, count] : words) {
      bool ok = true;
      for(auto c : word) {
        if(broken.count(c)) {
          ok = false;
          break;
        }
      }
      if(ok) answer += count;
    }
    return answer;
  }
};

// Accepted
// 20/20 cases passed (3 ms)
// Your runtime beats 19.27 % of cpp submissions
// Your memory usage beats 16.28 % of cpp submissions (9.8 MB)
```
