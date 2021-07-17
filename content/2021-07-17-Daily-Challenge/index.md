+++
title = "2021-07-17 Daily-Challenge"
path = "2021-07-17-Daily-Challenge"
date = 2021-07-17 11:24:53+08:00
updated = 2021-07-17 23:47:10+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3809/) with `cpp`.

<!-- more -->

# LeetCode Review

## Isomorphic Strings

too easy to review

## Find Peak Element

too easy to review

## Custom Sort String

too easy to review

## Combination Sum II

too easy to review

## Excel Sheet Column Number

too easy to review

## Diagonal Traverse

too easy to review

## Number of Ways to Reorder Array to Get Same BST

when we meet a node, we actually know that how many nodes are in its left/right subtree, and `qmul()` is a trash optimization

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();

#define MOD 1000000007

constexpr int qpow(long long b, int e) {
  long long result = 1;
  while(e) {
    if(e & 1) {
      result = result * b % MOD;
    }
    b = b * b % MOD;
    e >>= 1;
  }
  return result;
}

int _i[1000];
int _c[1000][500];

constexpr int inv(int a) {
  if(_i[a]) return _i[a];
  return _i[a] = qpow(a, MOD - 2);
}
constexpr int C(int m, int n) {
  m = min(m, n - m);
  if(_c[n][m]) return _c[n][m];
  long long result = 1;
  for(int i = m + 1; i <= n; ++i) {
    result = result * i % MOD;
  }
  for(int i = 1; i <= n - m; ++i) {
    result = result * inv(i) % MOD;
  }
  _c[n][m] = result;
  return result;
}

class Solution {
  int len;
  long long answer;
  void solve(vector<int> &nums, int index, int leftBound, int rightBound) {
    int root = nums[index];
    // cout << root << ' ' << leftBound << ' ' << rightBound << endl;
    answer *= C(root - leftBound - 1, rightBound - leftBound - 2);
    answer %= MOD;
    bool needLeft = root - leftBound > 1;
    bool needRight = rightBound - root > 1;
    for(int i = index + 1; i < len && (needLeft || needRight); ++i) {
      if(needLeft && nums[i] < root && nums[i] > leftBound) {
        solve(nums, i, leftBound, root);
        needLeft = false;
      }
      if(needRight && nums[i] > root && nums[i] < rightBound) {
        solve(nums, i, root, rightBound);
        needRight = false;
      }
    }
  }
public:
  int numOfWays(vector<int>& nums) {
    len = nums.size();
    answer = 1;
    solve(nums, 0, 0, len + 1);
    return (answer + MOD - 1) % MOD;
  }
};

// Accepted
// 161/161 cases passed (28 ms)
// Your runtime beats 96.42 % of cpp submissions
// Your memory usage beats 95.59 % of cpp submissions (14.6 MB)
```

## 4Sum

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int len;
  vector<vector<int>> twoSum(vector<int> &nums, int target, int start) {
    vector<vector<int>> answer;
    int end = len - 1;
    // cout << target << ' ' << start << ' ' << end << ' ';
    while(start < end) {
      int result = nums[start] + nums[end];
      if(result == target) {
        answer.push_back({nums[end], nums[start]});
        do { start += 1; } while(start < end && nums[start] == nums[start - 1]);
        do { end -= 1; } while(start < end && nums[end] == nums[end + 1]);
      } else if(result < target) {
        do { start += 1; } while(start < end && nums[start] == nums[start - 1]);
      } else {
        do { end -= 1; } while(start < end && nums[end] == nums[end + 1]);
      }
    } 
    // cout << answer << endl;
    return answer;
  }
  vector<vector<int>> kSum(vector<int> &nums, int target, int start, int k) {
    vector<vector<int>> answer;
    // cout << target << ' ' << start << ' ' << k << endl;
    if(nums[start] * k > target || nums.back() * k < target) return answer;
    if(k == 2) return twoSum(nums, target, start);
    for(int i = start; i <= len - k; ++i) {
      if(i != start && nums[i] == nums[i - 1]) continue;
      for(auto &res : kSum(nums, target - nums[i], i + 1, k - 1)) {
        res.push_back(nums[i]);
        answer.emplace_back(move(res));
      }
    }
    return answer;
  }
  void init(vector<int> &nums) {
    len = nums.size();
    sort(nums.begin(), nums.end());
  }
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    init(nums);
    // cout << nums << endl;
    auto answer = kSum(nums, target, 0, 4);
    for(auto &res : answer) { 
      reverse(res.begin(), res.end());
    }
    return answer;
  }
};

// Accepted
// 283/283 cases passed (15 ms)
// Your runtime beats 91.73 % of cpp submissions
// Your memory usage beats 45.57 % of cpp submissions (13.1 MB)
```

# July LeetCoding Challenge17

## Description

**Three Equal Parts**

You are given an array `arr` which consists of only zeros and ones, divide the array into **three non-empty parts** such that all of these parts represent the same binary value.

If it is possible, return any `[i, j]` with `i + 1 < j`, such that:

- `arr[0], arr[1], ..., arr[i]` is the first part,
- `arr[i + 1], arr[i + 2], ..., arr[j - 1]` is the second part, and
- `arr[j], arr[j + 1], ..., arr[arr.length - 1]` is the third part.
- All three parts have equal binary values.

If it is not possible, return `[-1, -1]`.

Note that the entire part is used when considering what binary value it represents. For example, `[1,1,0]` represents `6` in decimal, not `3`. Also, leading zeros **are allowed**, so `[0,1,1]` and `[1,1]` represent the same value.

 

**Example 1:**

```
Input: arr = [1,0,1,0,1]
Output: [0,3]
```

**Example 2:**

```
Input: arr = [1,1,0,1,1]
Output: [-1,-1]
```

**Example 3:**

```
Input: arr = [1,1,0,0,1]
Output: [0,2]
```

 

**Constraints:**

- `3 <= arr.length <= 3 * 104`
- `arr[i]` is `0` or `1`


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int ones[30000];
class Solution {
public:
  vector<int> threeEqualParts(vector<int>& arr) {
    int len = arr.size();
    int count = 0;
    for(int i = 0; i < len; ++i) {
      if(arr[len - i - 1]) {
        ones[count++] = i;
      }
    }
    if(count % 3) return {-1, -1};
    if(!count) return {0,2};
    int target = count / 3;
    int tailZero = ones[0];
    int headBegin = ones[target * 2] - tailZero;
    int midBegin = ones[target] - tailZero;
    if(ones[target - 1] >= midBegin || ones[target * 2 - 1] >= headBegin) return {-1, -1};
    int tailCur = 0;
    int midCur = midBegin;
    int headCur = headBegin;
    for(int i = 0; i < target; ++i) {
      if(ones[i] - tailCur != ones[target + i] - midCur || ones[target + i] - midCur != ones[target * 2 + i] - headCur) {
        return {-1, -1};
      }
      tailCur = ones[i];
      midCur = ones[target + i];
      headCur = ones[target * 2 + i];
    }
    return {len - ones[target * 2] + tailZero - 1, len - ones[target] + tailZero};
  }
};
```
