+++
updated = 2023-10-05T15:00:25+08:00
title = "2023-10-05 Daily Challenge"
path = "2023-10-05-Daily-Challenge"
date = 2023-10-05T15:00:25+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/majority-element-ii/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 5

## Description

**Majority Element II**

<p>Given an integer array of size <code>n</code>, find all elements that appear more than <code>&lfloor; n/3 &rfloor;</code> times.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,3]
<strong>Output:</strong> [3]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1]
<strong>Output:</strong> [1]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2]
<strong>Output:</strong> [1,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you solve the problem in linear time and in <code>O(1)</code> space?</p>


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
  vector<int> majorityElement(vector<int>& nums) {
    int elements[2];
    int count[2] = {};
    for(auto c : nums) {
      if(c == elements[0]) {
        count[0] += 1;
      } else if(c == elements[1]) {
        count[1] += 1;
      } else if(!count[0]) {
        elements[0] = c;
        count[0] = 1;
      } else if(!count[1]) {
        elements[1] = c;
        count[1] = 1;
      } else {
        count[0] -= 1;
        count[1] -= 1;
      }
    }
    vector<int> answer;
    for(auto candidate : elements) {
      int count = 0;
      for(auto i : nums) {
        count += i == candidate;
      }
      if(count * 3 > nums.size()) {
        answer.push_back(candidate);
      }
    }
    return answer;
  }
};

// Accepted
// 87/87 cases passed (10 ms)
// Your runtime beats 57.9 % of cpp submissions
// Your memory usage beats 9.77 % of cpp submissions (16.5 MB)
```
