+++
updated = 2024-11-10T08:29:53+08:00
title = "2024-11-10 Daily Challenge"
path = "2024-11-10-Daily-Challenge"
date = 2024-11-10T08:29:53+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 10

## Description

**Shortest Subarray With OR at Least K II**

<p>You are given an array <code>nums</code> of <strong>non-negative</strong> integers and an integer <code>k</code>.</p>

<p>An array is called <strong>special</strong> if the bitwise <code>OR</code> of all of its elements is <strong>at least</strong> <code>k</code>.</p>

<p>Return <em>the length of the <strong>shortest</strong> <strong>special</strong> <strong>non-empty</strong> <span data-keyword="subarray-nonempty">subarray</span> of</em> <code>nums</code>, <em>or return</em> <code>-1</code> <em>if no special subarray exists</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3], k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>The subarray <code>[3]</code> has <code>OR</code> value of <code>3</code>. Hence, we return <code>1</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,1,8], k = 10</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>The subarray <code>[2,1,8]</code> has <code>OR</code> value of <code>11</code>. Hence, we return <code>3</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2], k = 0</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>The subarray <code>[1]</code> has <code>OR</code> value of <code>1</code>. Hence, we return <code>1</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  int k;
  bitset<30> B;
  void update(vector<int> &freq, unsigned x, bool add = true) {
    bitset<30> b(x);
    for(int i = 0; i < 30; ++i) {
      freq[i] += add ? b[i] : -b[i];
    }
  }

  bool check(vector<int> &freq) {
    int b = 0;
    for(int i = 0; i < 30; ++i) {
      if(freq[i] > 0) b |= (1 << i);
    }
    return b >= k;
  }
public:
  int minimumSubarrayLength(vector<int>& nums, int k) {
    if(!k) return 1;
    this->k = k;
    B = bitset<30>(k);

    vector<int> freq(30);
    int len = nums.size();
    int answer = INT_MAX;
    for(int begin = 0, end = 0; end < len; ++end) {
      int x = nums[end];
      if(x >= k) return 1;
      update(freq, x);
      while(begin < end && check(freq)) {
        answer = min(answer, end - begin + 1);
        update(freq, nums[begin], false);
        begin += 1;
      }
    }
    return answer == INT_MAX ? -1 : answer;
  }
};
```
