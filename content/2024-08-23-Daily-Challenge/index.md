+++
updated = 2024-08-23T15:14:38+08:00
title = "2024-08-23 Daily Challenge"
path = "2024-08-23-Daily-Challenge"
date = 2024-08-23T15:14:38+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/fraction-addition-and-subtraction/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 23

## Description

**Fraction Addition and Subtraction**

<p>Given a string <code>expression</code> representing an expression of fraction addition and subtraction, return the calculation result in string format.</p>

<p>The final result should be an <a href="https://en.wikipedia.org/wiki/Irreducible_fraction" target="_blank">irreducible fraction</a>. If your final result is an integer, change it to the format of a fraction that has a denominator <code>1</code>. So in this case, <code>2</code> should be converted to <code>2/1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> expression = &quot;-1/2+1/2&quot;
<strong>Output:</strong> &quot;0/1&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> expression = &quot;-1/2+1/2+1/3&quot;
<strong>Output:</strong> &quot;1/3&quot;
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> expression = &quot;1/3-1/2&quot;
<strong>Output:</strong> &quot;-1/6&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The input string only contains <code>&#39;0&#39;</code> to <code>&#39;9&#39;</code>, <code>&#39;/&#39;</code>, <code>&#39;+&#39;</code> and <code>&#39;-&#39;</code>. So does the output.</li>
	<li>Each fraction (input and output) has the format <code>&plusmn;numerator/denominator</code>. If the first input fraction or the output is positive, then <code>&#39;+&#39;</code> will be omitted.</li>
	<li>The input only contains valid <strong>irreducible fractions</strong>, where the <strong>numerator</strong> and <strong>denominator</strong> of each fraction will always be in the range <code>[1, 10]</code>. If the denominator is <code>1</code>, it means this fraction is actually an integer in a fraction format defined above.</li>
	<li>The number of given fractions will be in the range <code>[1, 10]</code>.</li>
	<li>The numerator and denominator of the <strong>final result</strong> are guaranteed to be valid and in the range of <strong>32-bit</strong> int.</li>
</ul>


## Solution

``` cpp
inline int gcd(int a, int b) {
  if(b) {
    while((a %= b) && (b %= a));
  }
  return abs(a + b);
}
inline int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}
class fraction {
  int denominator;
  int numerator;

public:
  fraction(int d, int n): denominator(d), numerator(n) {}
  fraction operator+(const fraction &a) {
    int finalNumerator = lcm(numerator, a.numerator);
    int finalDenominator = denominator * finalNumerator / numerator + a.denominator * finalNumerator / a.numerator;
    if(!finalDenominator) finalNumerator = 1;
    int g = gcd(finalNumerator, finalDenominator);
    return fraction(finalDenominator / g, finalNumerator / g);
  }
  fraction operator-(const fraction &a) {
    int finalNumerator = lcm(numerator, a.numerator);
    int finalDenominator = denominator * finalNumerator / numerator - a.denominator * finalNumerator / a.numerator;
    if(!finalDenominator) finalNumerator = 1;
    int g = gcd(finalNumerator, finalDenominator);
    return fraction(finalDenominator / g, finalNumerator / g);
  }
  string stringlify() {
    return to_string(denominator) + "/" + to_string(numerator);
  }
};
class Solution {
public:
  string fractionAddition(string expression) {
    int pos = 0;
    bool isAdd = true;
    fraction result(0, 1);
    while(pos < expression.length()) {
      bool isNegative = false;
      int denominator;
      int numerator;
      if(expression[pos] == '-') {
        isNegative = true;
        pos += 1;
      }
      if(expression[pos] == '1' && expression[pos + 1] =='0') {
        denominator = 10;
        pos += 3;
      } else {
        denominator = expression[pos] - '0';
        pos += 2;
      }
      if(pos <= expression.length() - 2 && expression[pos] == '1' && expression[pos + 1] =='0') {
        numerator = 10;
        pos += 2;
      } else {
        numerator = expression[pos] - '0';
        pos += 1;
      }
      fraction current(isNegative ? -denominator : denominator, numerator);
      if(isAdd) {
        result = result + current;
      } else {
        result = result - current;
      }
      if(pos < expression.length() && expression[pos] == '+') {
        isAdd = true;
      } else {
        isAdd = false;
      }
      pos += 1;
    }

    return result.stringlify();
  }
};
```
