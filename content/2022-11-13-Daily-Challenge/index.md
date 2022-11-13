+++
updated = 2022-11-13T14:05:42+08:00
title = "2022-11-13 Daily Challenge"
path = "2022-11-13-Daily-Challenge"
date = 2022-11-13T14:05:42+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/reverse-words-in-a-string/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 13

## Description

**Reverse Words in a String**

<p>Given an input string <code>s</code>, reverse the order of the <strong>words</strong>.</p>

<p>A <strong>word</strong> is defined as a sequence of non-space characters. The <strong>words</strong> in <code>s</code> will be separated by at least one space.</p>

<p>Return <em>a string of the words in reverse order concatenated by a single space.</em></p>

<p><b>Note</b> that <code>s</code> may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;the sky is blue&quot;
<strong>Output:</strong> &quot;blue is sky the&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;  hello world  &quot;
<strong>Output:</strong> &quot;world hello&quot;
<strong>Explanation:</strong> Your reversed string should not contain leading or trailing spaces.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;a good   example&quot;
<strong>Output:</strong> &quot;example good a&quot;
<strong>Explanation:</strong> You need to reduce multiple spaces between two words to a single space in the reversed string.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> contains English letters (upper-case and lower-case), digits, and spaces <code>&#39; &#39;</code>.</li>
	<li>There is <strong>at least one</strong> word in <code>s</code>.</li>
</ul>

<p>&nbsp;</p>
<p><b data-stringify-type="bold">Follow-up:&nbsp;</b>If the string data type is mutable in your language, can&nbsp;you solve it&nbsp;<b data-stringify-type="bold">in-place</b>&nbsp;with&nbsp;<code data-stringify-type="code">O(1)</code>&nbsp;extra space?</p>


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
  string reverseWords(string s) {
    reverse(s.begin(), s.end());
    int len = s.length();
    bool hasSpace = true;
    int newLength = 0;
    for(int i = 0; i < len; ++i) {
      if(s[i] != ' ' || !hasSpace) {
        if(s[i] == ' ') hasSpace = true;
        else hasSpace = false;
        s[newLength] = s[i];
        newLength += 1;
      }
    }
    if(!newLength) return "";
    if(s[newLength-1] == ' ') newLength -= 1;
    s.resize(newLength);
    len = newLength;
    int begin = -1, end = -1;
    for(int i = 0; i < len; ++i) {
      if(s[i] != ' ') {
        if(begin == -1) begin = i;
        end = i+1;
      } else {
        if(begin != -1 && begin != end-1) {
          reverse(s.begin() + begin, s.begin() + end);
        }
        begin = -1;
        end = -1;
      }
    }
    if(begin != -1 && begin != end-1) reverse(s.begin() + begin, s.begin() + end);
    return move(s);
  }
};

// Accepted
// 58/58 cases passed (4 ms)
// Your runtime beats 91.32 % of cpp submissions
// Your memory usage beats 83.99 % of cpp submissions (7.1 MB)
```
