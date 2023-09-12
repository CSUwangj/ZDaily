+++
updated = 2023-09-12T08:26:32+08:00
title = "2023-09-12 Daily Challenge"
path = "2023-09-12-Daily-Challenge"
date = 2023-09-12T08:26:32+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 12

## Description

**Minimum Deletions to Make Character Frequencies Unique**

<p>A string <code>s</code> is called <strong>good</strong> if there are no two different characters in <code>s</code> that have the same <strong>frequency</strong>.</p>

<p>Given a string <code>s</code>, return<em> the <strong>minimum</strong> number of characters you need to delete to make </em><code>s</code><em> <strong>good</strong>.</em></p>

<p>The <strong>frequency</strong> of a character in a string is the number of times it appears in the string. For example, in the string <code>&quot;aab&quot;</code>, the <strong>frequency</strong> of <code>&#39;a&#39;</code> is <code>2</code>, while the <strong>frequency</strong> of <code>&#39;b&#39;</code> is <code>1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aab&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong> <code>s</code> is already good.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aaabbbcc&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> You can delete two &#39;b&#39;s resulting in the good string &quot;aaabcc&quot;.
Another way it to delete one &#39;b&#39; and one &#39;c&#39; resulting in the good string &quot;aaabbc&quot;.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ceabaacb&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> You can delete both &#39;c&#39;s resulting in the good string &quot;eabaab&quot;.
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;contains only lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
  bool noDeletion(int *cnt) {
    int pos = 0;
    while(pos < 26 && !cnt[pos]) pos += 1;
    if(!pos) pos += 1;
    while(pos < 26 && cnt[pos] != cnt[pos - 1]) pos += 1;
    return pos == 26;
  }
public:
  int minDeletions(string s) {
    int cnt[26] = {};
    for(auto c : s) {
      cnt[c - 'a'] += 1;
    }
    sort(cnt, cnt + 26);
    if(noDeletion(cnt)) return 0;
    int pos = 0;
    while(pos < 26 && !cnt[pos]) pos += 1;
    int answer = 0;
    for(int i = pos + 1; i < 26; ++i) {
      if(cnt[i] != cnt[i - 1]) continue;
      for(int j = i - 1; j >= pos; --j) {
        if(!cnt[j] || cnt[j] != cnt[j + 1]) break;
        cnt[j] -= 1;
        answer += 1;
      }
    }
    return answer;
  }
};

// Accepted
// 103/103 cases passed (43 ms)
// Your runtime beats 92.49 % of cpp submissions
// Your memory usage beats 77.52 % of cpp submissions (17.2 MB)
```
