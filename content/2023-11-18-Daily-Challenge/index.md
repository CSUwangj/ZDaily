+++
updated = 2023-11-18T13:44:53+08:00
title = "2023-11-18 Daily Challenge"
path = "2023-11-18-Daily-Challenge"
date = 2023-11-18T13:44:53+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/frequency-of-the-most-frequent-element/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 18

## Description

**Frequency of the Most Frequent Element**

<p>The <strong>frequency</strong> of an element is the number of times it occurs in an array.</p>

<p>You are given an integer array <code>nums</code> and an integer <code>k</code>. In one operation, you can choose an index of <code>nums</code> and increment the element at that index by <code>1</code>.</p>

<p>Return <em>the <strong>maximum possible frequency</strong> of an element after performing <strong>at most</strong> </em><code>k</code><em> operations</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,4], k = 5
<strong>Output:</strong> 3<strong>
Explanation:</strong> Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,4,8,13], k = 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are multiple optimal solutions:
- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,9,6], k = 2
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
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
  using ll = long long;
public:
  int maxFrequency(vector<int>& nums, int k) {
    if(nums.size() == 1) return 1;
    sort(nums.begin(), nums.end());
    int begin = 0;
    int answer = 0;
    ll currentSum = nums[0];
    ll beginSum = 0;
    for(int end = 1; end < nums.size(); ++end) {
      currentSum += nums[end];
      while(begin < end && 1LL * nums[end] * (end + 1 - begin) - (currentSum - beginSum) > k) {
        beginSum += nums[begin];
        begin += 1;
      }
      answer = max(answer, end - begin + 1);
    }
    return answer;
  }
};

// Accepted
// 71/71 cases passed (128 ms)
// Your runtime beats 97.54 % of cpp submissions
// Your memory usage beats 25.45 % of cpp submissions (99.5 MB)
```
