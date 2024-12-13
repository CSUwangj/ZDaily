+++
updated = 2024-12-13T16:29:31+08:00
title = "2024-12-13 Daily Challenge"
path = "2024-12-13-Daily-Challenge"
date = 2024-12-13T16:29:31+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 13

## Description

**Find Score of an Array After Marking All Elements**

<p>You are given an array <code>nums</code> consisting of positive integers.</p>

<p>Starting with <code>score = 0</code>, apply the following algorithm:</p>

<ul>
	<li>Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.</li>
	<li>Add the value of the chosen integer to <code>score</code>.</li>
	<li>Mark <strong>the chosen element and its two adjacent elements if they exist</strong>.</li>
	<li>Repeat until all the array elements are marked.</li>
</ul>

<p>Return <em>the score you get after applying the above algorithm</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,1,3,4,5,2]
<strong>Output:</strong> 7
<strong>Explanation:</strong> We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [<u>2</u>,<u>1</u>,<u>3</u>,4,5,2].
- 2 is the smallest unmarked element, so we mark it and its left adjacent element: [<u>2</u>,<u>1</u>,<u>3</u>,4,<u>5</u>,<u>2</u>].
- 4 is the only remaining unmarked element, so we mark it: [<u>2</u>,<u>1</u>,<u>3</u>,<u>4</u>,<u>5</u>,<u>2</u>].
Our score is 1 + 2 + 4 = 7.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,3,5,1,3,2]
<strong>Output:</strong> 5
<strong>Explanation:</strong> We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,<u>5</u>,<u>1</u>,<u>3</u>,2].
- 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [<u>2</u>,<u>3</u>,<u>5</u>,<u>1</u>,<u>3</u>,2].
- 2 is the only remaining unmarked element, so we mark it: [<u>2</u>,<u>3</u>,<u>5</u>,<u>1</u>,<u>3</u>,<u>2</u>].
Our score is 1 + 2 + 2 = 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  using pi = pair<int, int>;
public:
  long long findScore(vector<int>& nums) {
    long long answer = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for(int i = 0; i < nums.size(); ++i) {
      pq.push({nums[i], i});
    }
    unordered_set<int> marked;
    while(pq.size()) {
      auto [n, pos] = pq.top();
      pq.pop();
      if(marked.count(pos)) continue;
      answer += n;
      marked.insert(pos);
      marked.insert(pos - 1);
      marked.insert(pos + 1);
    }
    return answer;
  }
};

// Accepted
// 1044/1044 cases passed (285 ms)
// Your runtime beats 23.11 % of cpp submissions
// Your memory usage beats 12.09 % of cpp submissions (150.8 MB)
```
