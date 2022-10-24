+++
updated = 2022-10-24T12:39:37+08:00
title = "2022-10-24 Daily Challenge"
path = "2022-10-24-Daily-Challenge"
date = 2022-10-24T12:39:37+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 24

## Description

**Maximum Length of a Concatenated String with Unique Characters**

<p>You are given an array of strings <code>arr</code>. A string <code>s</code> is formed by the <strong>concatenation</strong> of a <strong>subsequence</strong> of <code>arr</code> that has <strong>unique characters</strong>.</p>

<p>Return <em>the <strong>maximum</strong> possible length</em> of <code>s</code>.</p>

<p>A <strong>subsequence</strong> is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [&quot;un&quot;,&quot;iq&quot;,&quot;ue&quot;]
<strong>Output:</strong> 4
<strong>Explanation:</strong> All the valid concatenations are:
- &quot;&quot;
- &quot;un&quot;
- &quot;iq&quot;
- &quot;ue&quot;
- &quot;uniq&quot; (&quot;un&quot; + &quot;iq&quot;)
- &quot;ique&quot; (&quot;iq&quot; + &quot;ue&quot;)
Maximum length is 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [&quot;cha&quot;,&quot;r&quot;,&quot;act&quot;,&quot;ers&quot;]
<strong>Output:</strong> 6
<strong>Explanation:</strong> Possible longest valid concatenations are &quot;chaers&quot; (&quot;cha&quot; + &quot;ers&quot;) and &quot;acters&quot; (&quot;act&quot; + &quot;ers&quot;).
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> arr = [&quot;abcdefghijklmnopqrstuvwxyz&quot;]
<strong>Output:</strong> 26
<strong>Explanation:</strong> The only string in arr has all 26 characters.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 16</code></li>
	<li><code>1 &lt;= arr[i].length &lt;= 26</code></li>
	<li><code>arr[i]</code> contains only lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
  int answer = 0;
  int len;
  vector<int> masks;
  vector<int> lens;
  void init(vector<string>& arr) {
    len = arr.size();
    masks.resize(len);
    lens.resize(len);

    for(int i = 0; i < len; ++i) {
      lens[i] = arr[i].length();
      for(auto c : arr[i]) {
        int m = (1 << (c - 'a'));
        if(m & masks[i]) {
          masks[i] = 0;
          lens[i] = 0;
          break;
        }
        masks[i] |= m;
      }
    }
  }

  void solve(int index = 0, int mask = 0, int length = 0) {
    if(index == len) {
      if(length > answer) answer = length;
      return;
    }
    solve(index + 1, mask, length);
    if(lens[index] && (masks[index] & mask) == 0) {
      solve(index + 1, mask | masks[index], length + lens[index]);
    }
  }
public:
  int maxLength(vector<string>& arr) {
    init(arr);
    solve();
    return answer;
  }
};

// Accepted
// 89/89 cases passed (4 ms)
// Your runtime beats 95.93 % of cpp submissions
// Your memory usage beats 92.84 % of cpp submissions (8.1 MB)
```
