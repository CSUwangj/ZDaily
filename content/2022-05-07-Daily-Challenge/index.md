+++
updated = 2022-05-07 18:21:00+08:00
title = "2022-05-07 Daily-Challenge"
path = "2022-05-07-Daily-Challenge"
date = 2022-05-07 18:19:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/132-pattern/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 7

## Description

**132 Pattern**

Given an array of `n` integers `nums`, a **132 pattern** is a subsequence of three integers `nums[i]`, `nums[j]` and `nums[k]` such that `i < j < k` and `nums[i] < nums[k] < nums[j]`.

Return *`true` if there is a **132 pattern** in `nums`, otherwise, return `false`.*

 

**Example 1:**

```
Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
```

**Example 2:**

```
Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
```

**Example 3:**

```
Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
```

 

**Constraints:**

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
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
  bool find132pattern(vector<int>& nums) {
    if(nums.size() < 3) return false;
    stack<int> three;
    int two = INT_MIN;
    three.push(nums.back());
    for(int i = nums.size()-1; i >=0 ; --i) {
      if(nums[i] < two) return true;
      while(three.size() && three.top() < nums[i]) {
        two = three.top();
        three.pop();
      }
      three.push(nums[i]);
    }
    return false;
  }
};

// Accepted
// 102/102 cases passed (60 ms)
// Your runtime beats 99.08 % of cpp submissions
// Your memory usage beats 98.98 % of cpp submissions (37.4 MB)
```
