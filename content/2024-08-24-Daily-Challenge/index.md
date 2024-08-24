+++
updated = 2024-08-24T13:58:59+08:00
title = "2024-08-24 Daily Challenge"
path = "2024-08-24-Daily-Challenge"
date = 2024-08-24T13:58:59+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/find-the-closest-palindrome/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 24

## Description

**Find the Closest Palindrome**

<p>Given a string <code>n</code> representing an integer, return <em>the closest integer (not including itself), which is a palindrome</em>. If there is a tie, return <em><strong>the smaller one</strong></em>.</p>

<p>The closest is defined as the absolute difference minimized between two integers.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = &quot;123&quot;
<strong>Output:</strong> &quot;121&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = &quot;1&quot;
<strong>Output:</strong> &quot;0&quot;
<strong>Explanation:</strong> 0 and 2 are the closest palindromes but we return the smallest which is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n.length &lt;= 18</code></li>
	<li><code>n</code> consists of only digits.</li>
	<li><code>n</code> does not have leading zeros.</li>
	<li><code>n</code> is representing an integer in the range <code>[1, 10<sup>18</sup> - 1]</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        set<long long> ans;
        long long largest = pow(10, len) + 1;
        ans.insert(largest);
        long long smallest = pow(10, len-1) - 1;
        ans.insert(smallest);
        string prefix = string(n.begin(), n.begin()+(len+1)/2);
        long long prefixNum = stoll(prefix);
        for(int i = -1; i <= 1; ++i) {
            long long currentHalf = prefixNum + i;
            string currentHalfString = to_string(currentHalf);
            string currentString = currentHalfString + string(currentHalfString.rbegin()+(len&1), currentHalfString.rend());
            ans.insert(stoll(currentString));
        }
        long long num = stoll(n);
        ans.erase(num);
        long long minDiff = LONG_LONG_MAX, answer = 0;
        for(auto l : ans) {
            if(minDiff > abs(num-l)) {
                minDiff = abs(num-l);
                answer = l;
            }
        }
        return to_string(answer);
    }
};
```
