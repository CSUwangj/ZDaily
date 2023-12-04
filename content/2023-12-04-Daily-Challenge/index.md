+++
updated = 2023-12-04T14:00:08+08:00
title = "2023-12-04 Daily Challenge"
path = "2023-12-04-Daily-Challenge"
date = 2023-12-04T14:00:08+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/largest-3-same-digit-number-in-string/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 4

## Description

**Largest 3-Same-Digit Number in String**

<p>You are given a string <code>num</code> representing a large integer. An integer is <strong>good</strong> if it meets the following conditions:</p>

<ul>
	<li>It is a <strong>substring</strong> of <code>num</code> with length <code>3</code>.</li>
	<li>It consists of only one unique digit.</li>
</ul>

<p>Return <em>the <strong>maximum good </strong>integer as a <strong>string</strong> or an empty string </em><code>&quot;&quot;</code><em> if no such integer exists</em>.</p>

<p>Note:</p>

<ul>
	<li>A <strong>substring</strong> is a contiguous sequence of characters within a string.</li>
	<li>There may be <strong>leading zeroes</strong> in <code>num</code> or a good integer.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num = &quot;6<strong><u>777</u></strong>133339&quot;
<strong>Output:</strong> &quot;777&quot;
<strong>Explanation:</strong> There are two distinct good integers: &quot;777&quot; and &quot;333&quot;.
&quot;777&quot; is the largest, so we return &quot;777&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> num = &quot;23<strong><u>000</u></strong>19&quot;
<strong>Output:</strong> &quot;000&quot;
<strong>Explanation:</strong> &quot;000&quot; is the only good integer.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> num = &quot;42352338&quot;
<strong>Output:</strong> &quot;&quot;
<strong>Explanation:</strong> No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= num.length &lt;= 1000</code></li>
	<li><code>num</code> only consists of digits.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  string largestGoodInteger(string num) {
    string answer = "";
    char current = 0;
    for(int i = 2; i < num.size(); ++i) {
      if(num[i] == num[i - 1] && num[i] == num[i - 2] && num[i] > current) {
        answer = num.substr(i - 2, 3);
        current = num[i];
      }
    }

    return answer;
  }
};

// Accepted
// 141/141 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 59.71 % of cpp submissions (6.8 MB)
```
