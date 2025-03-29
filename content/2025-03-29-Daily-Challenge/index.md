+++
updated = 2025-03-29T13:24:30+08:00
title = "2025-03-29 Daily Challenge"
path = "2025-03-29-Daily-Challenge"
date = 2025-03-29T13:24:30+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/apply-operations-to-maximize-score/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 29

## Description

**Apply Operations to Maximize Score**

<p>You are given an array <code>nums</code> of <code>n</code> positive integers and an integer <code>k</code>.</p>

<p>Initially, you start with a score of <code>1</code>. You have to maximize your score by applying the following operation at most <code>k</code> times:</p>

<ul>
	<li>Choose any <strong>non-empty</strong> subarray <code>nums[l, ..., r]</code> that you haven&#39;t chosen previously.</li>
	<li>Choose an element <code>x</code> of <code>nums[l, ..., r]</code> with the highest <strong>prime score</strong>. If multiple such elements exist, choose the one with the smallest index.</li>
	<li>Multiply your score by <code>x</code>.</li>
</ul>

<p>Here, <code>nums[l, ..., r]</code> denotes the subarray of <code>nums</code> starting at index <code>l</code> and ending at the index <code>r</code>, both ends being inclusive.</p>

<p>The <strong>prime score</strong> of an integer <code>x</code> is equal to the number of distinct prime factors of <code>x</code>. For example, the prime score of <code>300</code> is <code>3</code> since <code>300 = 2 * 2 * 3 * 5 * 5</code>.</p>

<p>Return <em>the <strong>maximum possible score</strong> after applying at most </em><code>k</code><em> operations</em>.</p>

<p>Since the answer may be large, return it modulo <code>10<sup>9 </sup>+ 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [8,3,9,3,8], k = 2
<strong>Output:</strong> 81
<strong>Explanation:</strong> To get a score of 81, we can apply the following operations:
- Choose subarray nums[2, ..., 2]. nums[2] is the only element in this subarray. Hence, we multiply the score by nums[2]. The score becomes 1 * 9 = 9.
- Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 1, but nums[2] has the smaller index. Hence, we multiply the score by nums[2]. The score becomes 9 * 9 = 81.
It can be proven that 81 is the highest score one can obtain.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [19,12,14,6,10,18], k = 3
<strong>Output:</strong> 4788
<strong>Explanation:</strong> To get a score of 4788, we can apply the following operations: 
- Choose subarray nums[0, ..., 0]. nums[0] is the only element in this subarray. Hence, we multiply the score by nums[0]. The score becomes 1 * 19 = 19.
- Choose subarray nums[5, ..., 5]. nums[5] is the only element in this subarray. Hence, we multiply the score by nums[5]. The score becomes 19 * 18 = 342.
- Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 2, but nums[2] has the smaller index. Hence, we multipy the score by nums[2]. The score becomes 342 * 14 = 4788.
It can be proven that 4788 is the highest score one can obtain.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length == n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= min(n * (n + 1) / 2, 10<sup>9</sup>)</code></li>
</ul>


## Solution

``` cpp
inline long long qpow(long long base, long long exp, long long mod) {
  long long result = 1;
  while(exp) {
    if(exp & 1) {
      result *= base;
      result %= mod;
    }
    base *= base;
    base %= mod;
    exp >>= 1;
  }
  return result;
}
class Solution {
  const int MOD = 1e9 + 7;
  static vector<int> primeScores;
public:
  int maximumScore(vector<int>& nums, int k) {
    int len = nums.size();
    vector<int> scores(len);
    for(int i = 0; i < len; ++i) {
      scores[i] = primeScores[nums[i]];
    }
    vector<int> left(len, -1);
    vector<int> right(len, len);
    vector<int> mono;
    for(int i = 0; i < len; ++i) {
      while(mono.size() && scores[mono.back()] < scores[i]) {
        mono.pop_back();
      }
      if(mono.size()) left[i] = mono.back();
      mono.push_back(i);
    }
    mono.clear();
    for(int i = len - 1; i >= 0; --i) {
      while(mono.size() && scores[mono.back()] <= scores[i]) {
        mono.pop_back();
      }
      if(mono.size()) right[i] = mono.back();
      mono.push_back(i);
    }
  
    vector<long long> count(len);
    for(int i = 0; i < len; ++i) {
      count[i] = 1LL * (i - left[i]) * (right[i] - i);
    }
    map<int, long long> ops;
    for(int i = 0; i < len; ++i) {
      ops[-nums[i]] += count[i];
    }

    long long answer = 1;
    for(auto [num, count] : ops) {
      if(k > count) {
        answer *= qpow(-num, count, MOD);
        answer %= MOD;
        k -= count;
      } else {
        answer *= qpow(-num, k, MOD);
        answer %= MOD;
        break;
      }
    }
    return answer;
  }
};

vector<int> Solution::primeScores = []() {
  vector<int> result(100001, 0);
  result[1] = 0;
  for(int i = 2; i < 50001; ++i) {
    if(result[i]) continue;
    for(int j = i * 2; j < 100001; j += i) {
      result[j] += 1;
    }
  }
  for(int i = 2; i < 100001; ++i) {
    result[i] += !result[i];
  }
  return result;
}();

// Accepted
// 870/870 cases passed (167 ms)
// Your runtime beats 86.06 % of cpp submissions
// Your memory usage beats 59.39 % of cpp submissions (147.3 MB)
```
