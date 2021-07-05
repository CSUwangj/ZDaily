+++
title = "2021-07-05 Daily-Challenge"
path = "2021-07-05-Daily-Challenge"
date = 2021-07-05 20:26:14+08:00
updated = 2021-07-05 22:13:05+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Number of Different Integers in a String](https://leetcode.com/problems/number-of-different-integers-in-a-string/description/) and leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3803/) with `cpp`.

<!-- more -->

# Number of Different Integers in a String

## Description

<p>You are given a string <code>word</code> that consists of digits and lowercase English letters.</p>

<p>You will replace every non-digit character with a space. For example, <code>&quot;a123bc34d8ef34&quot;</code> will become <code>&quot; 123&nbsp; 34 8&nbsp; 34&quot;</code>. Notice that you are left with some integers that are separated by at least one space: <code>&quot;123&quot;</code>, <code>&quot;34&quot;</code>, <code>&quot;8&quot;</code>, and <code>&quot;34&quot;</code>.</p>

<p>Return <em>the number of <strong>different</strong> integers after performing the replacement operations on </em><code>word</code>.</p>

<p>Two integers are considered different if their decimal representations <strong>without any leading zeros</strong> are different.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><code><strong>Input:</strong> word = &quot;a<u>123</u>bc<u>34</u>d<u>8</u>ef<u>34</u>&quot;
<strong>Output:</strong> 3
<strong>Explanation: </strong>The three different integers are &quot;123&quot;, &quot;34&quot;, and &quot;8&quot;. Notice that &quot;34&quot; is only counted once.
</code></pre>

<p><strong>Example 2:</strong></p>

<pre><code><strong>Input:</strong> word = &quot;leet<u>1234</u>code<u>234</u>&quot;
<strong>Output:</strong> 2
</code></pre>

<p><strong>Example 3:</strong></p>

<pre><code><strong>Input:</strong> word = &quot;a<u>1</u>b<u>01</u>c<u>001</u>&quot;
<strong>Output:</strong> 1
<strong>Explanation: </strong>The three integers &quot;1&quot;, &quot;01&quot;, and &quot;001&quot; all represent the same integer because
the leading zeros are ignored when comparing their decimal values.
</code></pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 1000</code></li>
	<li><code>word</code> consists of digits and lowercase English letters.</li>
</ul>

## Solution

``` cpp
class Solution {
  string getNumber(const string &s, int &pos) {
    string result;
    int len = s.length();
    while(pos < len && s[pos] == '0') pos += 1;
    while(pos < len && isdigit(s[pos])) {
      result.push_back(s[pos]);
      pos += 1;
    }
    if(result.length() > 0) return result;
    return "0";
  }
public:
  int numDifferentIntegers(string word) {
    int pos = 0;
    int len = word.length();
    unordered_set<string> st;
    while(pos < len) {
      while(pos < len && !isdigit(word[pos])) pos += 1;
      if(pos < len) st.insert(getNumber(word, pos));
    }

    return st.size();
  }
};
```

# July LeetCoding Challenge5

## Description

**Reshape the Matrix**

In MATLAB, there is a handy function called `reshape` which can reshape an `m x n` matrix into a new one with a different size `r x c` keeping its original data.

You are given an `m x n` matrix `mat` and two integers `r` and `c` representing the row number and column number of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the `reshape` operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/04/24/reshape1-grid.jpg)

```
Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/04/24/reshape2-grid.jpg)

```
Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]
```

 

**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 100`
- `-1000 <= mat[i][j] <= 1000`
- `1 <= r, c <= 300`

## Solution

``` cpp
class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    if(r * c != mat.size() * mat.front().size()) return mat;
    int cnt = 0;
    vector<int> tmp;
    vector<vector<int>> answer;
    for(auto &row : mat) {
      for(auto num : row) {
        tmp.push_back(num);
        if(++cnt % c == 0) {
          answer.push_back(tmp);
          tmp.clear();
        }
      }
    }
    return answer;
  }
};
```
