+++
updated = 2024-05-23T13:37:47+08:00
title = "2024-05-23 Daily Challenge"
path = "2024-05-23-Daily-Challenge"
date = 2024-05-23T13:37:47+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/the-number-of-beautiful-subsets/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 23

## Description

**The Number of Beautiful Subsets**

<p>You are given an array <code>nums</code> of positive integers and a <strong>positive</strong> integer <code>k</code>.</p>

<p>A subset of <code>nums</code> is <strong>beautiful</strong> if it does not contain two integers with an absolute difference equal to <code>k</code>.</p>

<p>Return <em>the number of <strong>non-empty beautiful </strong>subsets of the array</em> <code>nums</code>.</p>

<p>A <strong>subset</strong> of <code>nums</code> is an array that can be obtained by deleting some (possibly none) elements from <code>nums</code>. Two subsets are different if and only if the chosen indices to delete are different.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,4,6], k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1], k = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> The beautiful subset of the array nums is [1].
It can be proved that there is only 1 beautiful subset in the array [1].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 20</code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 1000</code></li>
</ul>


## Solution

``` cpp
class Solution {
    vector<int> visit = vector<int>(1001);
    bool isBeautiful(vector<int>& nums, int k, int subset) {
        bool ok = true;
        for(int i = 0; i < nums.size() && ok; ++i) {
            if(!((1 << i) & subset)) continue;
            if(nums[i] > k && visit[nums[i] - k]) ok = false;
            if(nums[i] + k < 1001 && visit[nums[i] + k]) ok = false;
            visit[nums[i]] = true;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(!((1 << i) & subset)) continue;
            visit[nums[i]] = false;
        }
        return ok;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int allCombinations = (1 << nums.size());
        if(isBeautiful(nums, k, allCombinations - 1)) return allCombinations - 1;
        int answer = 0;
        for(int i = 1; i < allCombinations; ++i) {
            answer += isBeautiful(nums, k, i);
        }

        return answer;
    }
};
```
