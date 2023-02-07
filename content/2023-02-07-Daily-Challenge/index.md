+++
updated = 2023-02-07T11:33:47+08:00
title = "2023-02-07 Daily Challenge"
path = "2023-02-07-Daily-Challenge"
date = 2023-02-07T11:33:47+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/fruit-into-baskets/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 7

## Description

**Fruit Into Baskets**

<p>You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array <code>fruits</code> where <code>fruits[i]</code> is the <strong>type</strong> of fruit the <code>i<sup>th</sup></code> tree produces.</p>

<p>You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:</p>

<ul>
	<li>You only have <strong>two</strong> baskets, and each basket can only hold a <strong>single type</strong> of fruit. There is no limit on the amount of fruit each basket can hold.</li>
	<li>Starting from any tree of your choice, you must pick <strong>exactly one fruit</strong> from <strong>every</strong> tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.</li>
	<li>Once you reach a tree with fruit that cannot fit in your baskets, you must stop.</li>
</ul>

<p>Given the integer array <code>fruits</code>, return <em>the <strong>maximum</strong> number of fruits you can pick</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> fruits = [<u>1,2,1</u>]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can pick from all 3 trees.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> fruits = [0,<u>1,2,2</u>]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> fruits = [1,<u>2,3,2,2</u>]
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= fruits.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= fruits[i] &lt; fruits.length</code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int totalFruit(vector<int>& fruits) {
    map<int, int> count;
    int answer = 0;
    int current = 0;
    int left = 0;
    int right = 0;
    while(right < fruits.size()) {
      while(count.size() < 3 && right < fruits.size()) {
        count[fruits[right]] += 1;
        current += 1;
        right += 1;
      }
      answer = max(answer, current - (count.size() == 3));
      while(count.size() > 2) {
        count[fruits[left]] -= 1;
        if(!count[fruits[left]]) {
          count.erase(fruits[left]);
        }
        current -= 1;
        left += 1;
      }
    }
    return answer;
  }
};

// Accepted
// 91/91 cases passed (171 ms)
// Your runtime beats 81.22 % of cpp submissions
// Your memory usage beats 5.78 % of cpp submissions (75.4 MB)
```
