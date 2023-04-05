+++
updated = 2023-04-05T08:22:25+08:00
title = "2023-04-05 Daily Challenge"
path = "2023-04-05-Daily-Challenge"
date = 2023-04-05T08:22:25+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/minimize-maximum-of-array/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 5

## Description

**Minimize Maximum of Array**

<p>You are given a <strong>0-indexed</strong> array <code>nums</code> comprising of <code>n</code> non-negative integers.</p>

<p>In one operation, you must:</p>

<ul>
	<li>Choose an integer <code>i</code> such that <code>1 &lt;= i &lt; n</code> and <code>nums[i] &gt; 0</code>.</li>
	<li>Decrease <code>nums[i]</code> by 1.</li>
	<li>Increase <code>nums[i - 1]</code> by 1.</li>
</ul>

<p>Return<em> the <strong>minimum</strong> possible value of the <strong>maximum</strong> integer of </em><code>nums</code><em> after performing <strong>any</strong> number of operations</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,7,1,6]
<strong>Output:</strong> 5
<strong>Explanation:</strong>
One set of optimal operations is as follows:
1. Choose i = 1, and nums becomes [4,6,1,6].
2. Choose i = 3, and nums becomes [4,6,2,5].
3. Choose i = 1, and nums becomes [5,5,2,5].
The maximum integer of nums is 5. It can be shown that the maximum number cannot be less than 5.
Therefore, we return 5.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [10,1]
<strong>Output:</strong> 10
<strong>Explanation:</strong>
It is optimal to leave nums as is, and since 10 is the maximum value, we return 10.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
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
  int minimizeArrayValue(vector<int>& nums) {
    long long sum = accumulate(nums.begin(), nums.end(), 0LL);
    double average = 1.0 * sum / nums.size();
    long long current_sum = 0;
    int answer = ceil(average);
    for(int i = 0; i < nums.size(); ++i) {
      current_sum += nums[i];
      if(average * (i + 1) < current_sum) {
        answer = max<int>(answer, (current_sum + i) / (i + 1));
      }
    }
    return answer;
  }
};

// Accepted
// 68/68 cases passed (100 ms)
// Your runtime beats 98.83 % of cpp submissions
// Your memory usage beats 99 % of cpp submissions (70.4 MB)
```
