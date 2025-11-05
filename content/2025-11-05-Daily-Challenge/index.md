+++
updated = 2025-11-05T22:20:53+01:00
title = "2025-11-05 Daily Challenge"
path = "2025-11-05-Daily-Challenge"
date = 2025-11-05T22:20:53+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 5

## Description

**Find X-Sum of All K-Long Subarrays II**

<p>You are given an array <code>nums</code> of <code>n</code> integers and two integers <code>k</code> and <code>x</code>.</p>

<p>The <strong>x-sum</strong> of an array is calculated by the following procedure:</p>

<ul>
	<li>Count the occurrences of all elements in the array.</li>
	<li>Keep only the occurrences of the top <code>x</code> most frequent elements. If two elements have the same number of occurrences, the element with the <strong>bigger</strong> value is considered more frequent.</li>
	<li>Calculate the sum of the resulting array.</li>
</ul>

<p><strong>Note</strong> that if an array has less than <code>x</code> distinct elements, its <strong>x-sum</strong> is the sum of the array.</p>

<p>Return an integer array <code>answer</code> of length <code>n - k + 1</code> where <code>answer[i]</code> is the <strong>x-sum</strong> of the <span data-keyword="subarray-nonempty">subarray</span> <code>nums[i..i + k - 1]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,1,2,2,3,4,2,3], k = 6, x = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">[6,10,12]</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>For subarray <code>[1, 1, 2, 2, 3, 4]</code>, only elements 1 and 2 will be kept in the resulting array. Hence, <code>answer[0] = 1 + 1 + 2 + 2</code>.</li>
	<li>For subarray <code>[1, 2, 2, 3, 4, 2]</code>, only elements 2 and 4 will be kept in the resulting array. Hence, <code>answer[1] = 2 + 2 + 2 + 4</code>. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.</li>
	<li>For subarray <code>[2, 2, 3, 4, 2, 3]</code>, only elements 2 and 3 are kept in the resulting array. Hence, <code>answer[2] = 2 + 2 + 2 + 3 + 3</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [3,8,7,8,7,5], k = 2, x = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">[11,15,15,15,12]</span></p>

<p><strong>Explanation:</strong></p>

<p>Since <code>k == x</code>, <code>answer[i]</code> is equal to the sum of the subarray <code>nums[i..i + k - 1]</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>nums.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= x &lt;= k &lt;= nums.length</code></li>
</ul>


## Solution

``` cpp
class TwoSet {
  using pi = pair<int, int>;
private:
  int limit;
  long long result = 0;
  set<pi, greater<pi>> sum;
  set<pi, greater<pi>> candidates;
  map<int, int> freq;
  void balanceSets() {
    while(sum.size() == limit && *sum.rbegin() < *candidates.begin()) {
      auto toRemove = *sum.rbegin();
      auto toAdd = *candidates.begin();
      sum.erase(toRemove);
      candidates.insert(toRemove);
      sum.insert(toAdd);
      candidates.erase(toAdd);
      result = result - 1LL * toRemove.first * toRemove.second + 1LL * toAdd.first * toAdd.second;
    }
    while(sum.size() < limit && candidates.size()) {
      auto toAdd = *candidates.begin();
      sum.insert(toAdd);
      candidates.erase(toAdd);
      result += 1LL * toAdd.first * toAdd.second;
    }
  }
public:
  long long getSum() { return result; }
  void add(int num) {
    pair<int, int> target = {freq[num], num};
    freq[num] += 1;
    if(sum.count(target)) {
      sum.erase(target);
      target.first += 1;
      result += num;
      sum.insert(target);
    } else if(candidates.count(target)) {
      candidates.erase(target);
      target.first += 1;
      candidates.insert(target);
    } else {
      target.first += 1;
      candidates.insert(target);
    }
    balanceSets();
  }
  void remove(int num) {
    pair<int, int> target = {freq[num], num};
    freq[num] -= 1;
    if(!freq[num]) freq.erase(num);
    if(sum.count(target)) {
      sum.erase(target);
      target.first -= 1;
      result -= num;
      if(target.first) sum.insert(target);
    } else if(candidates.count(target)) {
      candidates.erase(target);
      target.first -= 1;
      if(target.first) candidates.insert(target);
    }
    balanceSets();
  }
  void printState() {
    cout << "sum: ";
    for(auto [f, n] : sum) {
      cout << "[" << n << ", " << f << "], ";
    }
    cout << endl;
    cout << "candidates: ";
    for(auto [f, n] : candidates) {
      cout << "[" << n << ", " << f << "], ";
    }
    cout << endl;
  }

  TwoSet (int x): limit(x) {}
};
class Solution {
  vector<long long> quickPass(vector<int>& nums, int x) {
    int len = nums.size();
    vector<long long> answer(len - x + 1);
    for(int i = 0; i < x; ++i) {
      answer[0] += nums[i];
    }
    for(int i = 1; i < len - x + 1; ++i) {
      answer[i] = answer[i - 1] - nums[i - 1] + nums[i + x - 1];
    }
    return answer;
  }
public:
  vector<long long> findXSum(vector<int>& nums, int k, int x) {
    if(k == x) return quickPass(nums, k);
    TwoSet ts(x);
    for(int i = 0; i < k; ++i) {
      ts.add(nums[i]);
    }
    // ts.printState();
    int len = nums.size();
    vector<long long> answer(len - k + 1);
    answer[0] = ts.getSum();
    for(int i = 1; i < len - k + 1; ++i) {
      ts.add(nums[i + k - 1]);
      ts.remove(nums[i - 1]);
      answer[i] = ts.getSum();
    // ts.printState();
    }
    return answer;
  }
};

// Accepted
// 784/784 cases passed (851 ms)
// Your runtime beats 38.46 % of cpp submissions
// Your memory usage beats 92.31 % of cpp submissions (265.8 MB)
```
