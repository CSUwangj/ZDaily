+++
updated = 2024-08-07T16:57:36+08:00
title = "2024-08-07 Daily Challenge"
path = "2024-08-07-Daily-Challenge"
date = 2024-08-07T16:57:36+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/integer-to-english-words/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 7

## Description

**Integer to English Words**

<p>Convert a non-negative integer <code>num</code> to its English words representation.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num = 123
<strong>Output:</strong> &quot;One Hundred Twenty Three&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> num = 12345
<strong>Output:</strong> &quot;Twelve Thousand Three Hundred Forty Five&quot;
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> num = 1234567
<strong>Output:</strong> &quot;One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


## Solution

``` cpp
class Solution {
  const string ZERO = "Zero";
  const vector<pair<int, string>> units = {
    { 1000000000, "Billion" },
    { 1000000, "Million" },
    { 1000, "Thousand" },
    { 1, "" }
  };
  vector<string> ge20 = {
    "", // 0
    "", // 10
    "Twenty",
    "Thirty",
    "Forty",
    "Fifty",
    "Sixty",
    "Seventy",
    "Eighty",
    "Ninety" 
  };
  vector<string> lt20 = {
    "",
    "One",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine",
    "Ten",
    "Eleven",
    "Twelve",
    "Thirteen",
    "Fourteen",
    "Fifteen",
    "Sixteen",
    "Seventeen",
    "Eighteen",
    "Nineteen",
  };

  string numberLT1000ToWords(int num)  {
    string result;
    if (num >= 100)  {
      result += lt20[num / 100] + " Hundred";
      if (num % 100 == 0) return result;
      result += " ";
      num %= 100;
    }
        if (!num) return result;
    if (num < 20) {
      result += lt20[num];
    } else {
      result += ge20[num/10];
      if (num % 10)  result += " " + lt20[num % 10];
    }

    return result;
  }

  void numberPartToWords(string &result, int &num, const int threshold, const string &unit)  {
    if (num >= threshold)  {
      if (result.length()) result += " ";
      result += numberLT1000ToWords(num / threshold);
      if (unit.length()) result += " " + unit;
      num %= threshold;
    }
  }

  public:
    string numberToWords(int num)  {
      if (!num) return move(ZERO);
      string answer = "";
      for (const auto &[threshold, unit]: units) {
        numberPartToWords(answer, num, threshold, unit);
      }

      return answer;
    }
};
```
