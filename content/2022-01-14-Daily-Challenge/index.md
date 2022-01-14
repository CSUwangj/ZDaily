+++
title = "2022-01-14 Daily-Challenge"
path = "2022-01-14-Daily-Challenge"
date = 2022-01-14 18:40:00+08:00
updated = 2022-01-14 18:41:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/string-to-integer-atoi/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 14

## Description

**String to Integer (atoi)**

<p>Implement the <code>myAtoi(string s)</code> function, which converts a string to a 32-bit signed integer (similar to C/C++&#39;s <code>atoi</code> function).</p>

<p>The algorithm for <code>myAtoi(string s)</code> is as follows:</p>

<ol>
	<li>Read in and ignore any leading whitespace.</li>
	<li>Check if the next character (if not already at the end of the string) is <code>&#39;-&#39;</code> or <code>&#39;+&#39;</code>. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.</li>
	<li>Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.</li>
	<li>Convert these digits into an integer (i.e. <code>&quot;123&quot; -&gt; 123</code>, <code>&quot;0032&quot; -&gt; 32</code>). If no digits were read, then the integer is <code>0</code>. Change the sign as necessary (from step 2).</li>
	<li>If the integer is out of the 32-bit signed integer range <code>[-2<sup>31</sup>, 2<sup>31</sup> - 1]</code>, then clamp the integer so that it remains in the range. Specifically, integers less than <code>-2<sup>31</sup></code> should be clamped to <code>-2<sup>31</sup></code>, and integers greater than <code>2<sup>31</sup> - 1</code> should be clamped to <code>2<sup>31</sup> - 1</code>.</li>
	<li>Return the integer as the final result.</li>
</ol>

<p><strong>Note:</strong></p>

<ul>
	<li>Only the space character <code>&#39; &#39;</code> is considered a whitespace character.</li>
	<li><strong>Do not ignore</strong> any characters other than the leading whitespace or the rest of the string after the digits.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;42&quot;
<strong>Output:</strong> 42
<strong>Explanation:</strong> The underlined characters are what is read in, the caret is the current reader position.
Step 1: &quot;42&quot; (no characters read because there is no leading whitespace)
         ^
Step 2: &quot;42&quot; (no characters read because there is neither a &#39;-&#39; nor &#39;+&#39;)
         ^
Step 3: &quot;<u>42</u>&quot; (&quot;42&quot; is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-2<sup>31</sup>, 2<sup>31</sup> - 1], the final result is 42.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;   -42&quot;
<strong>Output:</strong> -42
<strong>Explanation:</strong>
Step 1: &quot;<u>   </u>-42&quot; (leading whitespace is read and ignored)
            ^
Step 2: &quot;   <u>-</u>42&quot; (&#39;-&#39; is read, so the result should be negative)
             ^
Step 3: &quot;   -<u>42</u>&quot; (&quot;42&quot; is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-2<sup>31</sup>, 2<sup>31</sup> - 1], the final result is -42.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;4193 with words&quot;
<strong>Output:</strong> 4193
<strong>Explanation:</strong>
Step 1: &quot;4193 with words&quot; (no characters read because there is no leading whitespace)
         ^
Step 2: &quot;4193 with words&quot; (no characters read because there is neither a &#39;-&#39; nor &#39;+&#39;)
         ^
Step 3: &quot;<u>4193</u> with words&quot; (&quot;4193&quot; is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-2<sup>31</sup>, 2<sup>31</sup> - 1], the final result is 4193.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 200</code></li>
	<li><code>s</code> consists of English letters (lower-case and upper-case), digits (<code>0-9</code>), <code>&#39; &#39;</code>, <code>&#39;+&#39;</code>, <code>&#39;-&#39;</code>, and <code>&#39;.&#39;</code>.</li>
</ul>

## Solution

``` cpp
class Solution {
public:
  int myAtoi(string s) {
    int pos = 0;
    int len = s.length();
    while(pos < len && isspace(s[pos])) pos += 1;
    int cur = 0;
    int sign = 1;
    if(s[pos] == '-') {
      sign = -1;
      pos += 1;
    } else if(s[pos] == '+') {
      sign = 1;
      pos += 1;
    }
    // 2147483648₁₀ & 2147483647₁₀
    while(pos < len && isdigit(s[pos])) {
      if(sign == -1 && (INT_MIN / 10 > cur || (INT_MIN / 10 == cur && s[pos] > '7'))) return INT_MIN;
      if(sign == 1 && (INT_MAX / 10 < cur || (INT_MAX / 10 == cur && s[pos] > '6'))) return INT_MAX;
      cur *= 10;
      cur += sign * (s[pos] - '0');
      pos += 1;
    }
    return cur;
  }
};

// Accepted
// 1082/1082 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 52.29 % of cpp submissions (7 MB)
```
