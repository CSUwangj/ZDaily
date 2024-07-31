+++
updated = 2024-07-31T13:44:14+08:00
title = "2024-07-31 Daily Challenge"
path = "2024-07-31-Daily-Challenge"
date = 2024-07-31T13:44:14+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/filling-bookcase-shelves/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 31

## Description

**Filling Bookcase Shelves**

<p>You are given an array <code>books</code> where <code>books[i] = [thickness<sub>i</sub>, height<sub>i</sub>]</code> indicates the thickness and height of the <code>i<sup>th</sup></code> book. You are also given an integer <code>shelfWidth</code>.</p>

<p>We want to place these books in order onto bookcase shelves that have a total width <code>shelfWidth</code>.</p>

<p>We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to <code>shelfWidth</code>, then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. We repeat this process until there are no more books to place.</p>

<p>Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.</p>

<ul>
	<li>For example, if we have an ordered list of <code>5</code> books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.</li>
</ul>

<p>Return <em>the minimum possible height that the total bookshelf can be after placing shelves in this manner</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/06/24/shelves.png" style="height: 500px; width: 337px;" />
<pre>
<strong>Input:</strong> books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelfWidth = 4
<strong>Output:</strong> 6
<strong>Explanation:</strong>
The sum of the heights of the 3 shelves is 1 + 3 + 2 = 6.
Notice that book number 2 does not have to be on the first shelf.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> books = [[1,3],[2,4],[3,2]], shelfWidth = 6
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= books.length &lt;= 1000</code></li>
	<li><code>1 &lt;= thickness<sub>i</sub> &lt;= shelfWidth &lt;= 1000</code></li>
	<li><code>1 &lt;= height<sub>i</sub> &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
public:
  int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    int len = books.size();
    vector<int> dp(len + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= len; ++i) {
      int totalWidth = 0;
      int maxHeight = 0;
      for(int j = i; j ; --j) {
        totalWidth += books[j - 1][0];
        if(totalWidth > shelfWidth) break;
        maxHeight = max(maxHeight, books[j - 1][1]);
        dp[i] = min(dp[i], dp[j - 1] + maxHeight);
      }
    }

    return dp[len];
  }
};
```
