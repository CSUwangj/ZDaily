+++
updated = 2024-10-07T08:04:23+08:00
title = "2024-10-07 Daily Challenge"
path = "2024-10-07-Daily-Challenge"
date = 2024-10-07T08:04:23+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/minimum-string-length-after-removing-substrings/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 7

## Description

**Minimum String Length After Removing Substrings**

<p>You are given a string <code>s</code> consisting only of <strong>uppercase</strong> English letters.</p>

<p>You can apply some operations to this string where, in one operation, you can remove <strong>any</strong> occurrence of one of the substrings <code>&quot;AB&quot;</code> or <code>&quot;CD&quot;</code> from <code>s</code>.</p>

<p>Return <em>the <strong>minimum</strong> possible length of the resulting string that you can obtain</em>.</p>

<p><strong>Note</strong> that the string concatenates after removing the substring and could produce new <code>&quot;AB&quot;</code> or <code>&quot;CD&quot;</code> substrings.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ABFCACDB&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can do the following operations:
- Remove the substring &quot;<u>AB</u>FCACDB&quot;, so s = &quot;FCACDB&quot;.
- Remove the substring &quot;FCA<u>CD</u>B&quot;, so s = &quot;FCAB&quot;.
- Remove the substring &quot;FC<u>AB</u>&quot;, so s = &quot;FC&quot;.
So the resulting length of the string is 2.
It can be shown that it is the minimum length that we can obtain.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ACBBD&quot;
<strong>Output:</strong> 5
<strong>Explanation:</strong> We cannot do any operations on the string so the length remains the same.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code>&nbsp;consists only of uppercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int minLength(string s) {
    string answer;
    for(auto c : s) {
      if(answer.length() && ((answer.back() == 'A' && c == 'B') || (answer.back() == 'C' && c == 'D'))) {
        answer.pop_back();
        continue;
      }
      answer.push_back(c);
    }
    return answer.length();
  }
};
```
