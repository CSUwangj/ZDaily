+++
title = "2021-08-18 Daily-Challenge"
path = "2021-08-18-Daily-Challenge"
date = 2021-08-18 19:03:00+08:00
updated = 2021-08-18 21:12:22+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Count Pairs With XOR in a Range](https://leetcode.com/problems/count-pairs-with-xor-in-a-range/description/) and leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3893/) with `cpp`.

<!-- more -->

# Count Pairs With XOR in a Range

## Description

Given a **(0-indexed)** integer array `nums` and two integers `low` and `high`, return *the number of **nice pairs***.

A **nice pair** is a pair `(i, j)` where `0 <= i < j < nums.length` and `low <= (nums[i] XOR nums[j]) <= high`.

 

**Example 1:**

```
Input: nums = [1,4,2,7], low = 2, high = 6
Output: 6
Explanation: All nice pairs (i, j) are as follows:
    - (0, 1): nums[0] XOR nums[1] = 5 
    - (0, 2): nums[0] XOR nums[2] = 3
    - (0, 3): nums[0] XOR nums[3] = 6
    - (1, 2): nums[1] XOR nums[2] = 6
    - (1, 3): nums[1] XOR nums[3] = 3
    - (2, 3): nums[2] XOR nums[3] = 5
```

**Example 2:**

```
Input: nums = [9,8,4,2,1], low = 5, high = 14
Output: 8
Explanation: All nice pairs (i, j) are as follows:
    - (0, 2): nums[0] XOR nums[2] = 13
    - (0, 3): nums[0] XOR nums[3] = 11
    - (0, 4): nums[0] XOR nums[4] = 8
    - (1, 2): nums[1] XOR nums[2] = 12
    - (1, 3): nums[1] XOR nums[3] = 10
    - (1, 4): nums[1] XOR nums[4] = 9
    - (2, 3): nums[2] XOR nums[3] = 6
    - (2, 4): nums[2] XOR nums[4] = 5
```

 

**Constraints:**

- `1 <= nums.length <= 2 * 10^4`
- `1 <= nums[i] <= 2 * 10^4`
- `1 <= low <= high <= 2 * 10^4`

## Solution

better way to enumerate the pairs using trie tree

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct TrieNode {
  int count = 0;
  TrieNode *child[2] = {};
};

void insert(TrieNode *root, int num) {
  TrieNode *cur = root;
  root->count += 1;
  for(int i = 14; i >= 0; --i) {
    int index = 0;
    if(num & (1 << i)) {
      index = 1;
    }
    if(!cur->child[index]) {
      cur->child[index] = new TrieNode();
    }
    cur = cur->child[index];
    cur->count += 1;
  }
}

int solveOne(TrieNode *cur, int num, int low, int high, int rest, bool mustLessThanHigh = false, bool mustGreaterThanLow = false) {
  // cout << num << ' ' << low <<  ' ' << high << ' ' << rest << ' ' << mustLessThanHigh << ' ' << mustGreaterThanLow <<endl;
  if(!cur) return 0;
  if(rest == -1) return cur->count;
  if(mustGreaterThanLow && mustLessThanHigh) return cur->count;
  int result = 0;
  bool ok[2] = { true, true };
  bool lowBit = low & (1 << rest);
  bool highBit = high & (1 << rest);
  bool numBit = (num & (1 << rest));
  // cout <<"## " << num << ' ' << low <<  ' ' << high << ' ' << rest << ' ' << mustLessThanHigh << ' ' << mustGreaterThanLow <<endl;
  if(!mustGreaterThanLow) {
    if(lowBit) {
      ok[numBit] = false;
    }
  }
  if(!mustLessThanHigh) {
    if(!highBit) {
      ok[!numBit] = false;
    }
  }
  for(int i = 0; i < 2; ++i) {
    if(!ok[i]) continue;
    if(i == numBit) {
      if(highBit) {
        result += solveOne(cur->child[i], num, low, high, rest - 1, true, mustGreaterThanLow);
      } else {
        result += solveOne(cur->child[i], num, low, high, rest - 1, mustLessThanHigh, mustGreaterThanLow);
      }
    } else {
      if(!lowBit) {
        result += solveOne(cur->child[i], num, low, high, rest - 1, mustLessThanHigh, true);
      } else {
        result += solveOne(cur->child[i], num, low, high, rest - 1, mustLessThanHigh, mustGreaterThanLow);
      }
    }
  }
  return result;
}

int solve(vector<int> &nums, int low, int high) {
  TrieNode *root = new TrieNode();
  int answer = 0;
  for(auto n : nums) {
    answer += solveOne(root, n, low, high, 14);
    insert(root, n);
  }
  return answer;
}
class Solution {
public:
  int countPairs(vector<int>& nums, int low, int high) {
    return solve(nums, low, high);
  }
};

// Accepted
// 63/63 cases passed (280 ms)
// Your runtime beats 30.08 % of cpp submissions
// Your memory usage beats 36.72 % of cpp submissions (71.6 MB)
```

more elegant way

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct TrieNode {
  int count = 0;
  TrieNode *child[2] = {};
};

void insert(TrieNode *root, int num) {
  TrieNode *cur = root;
  root->count += 1;
  for(int i = 14; i >= 0; --i) {
    int index = !!(num & (1 << i));
    if(!cur->child[index]) {
      cur->child[index] = new TrieNode();
    }
    cur = cur->child[index];
    cur->count += 1;
  }
}
int find(TrieNode *root, int num, int target) {
  TrieNode *cur = root;
  int result = 0;
  for(int i = 14; i >= 0; --i) {
    // cout << "#" << num << ' ' << target << ' ' << i << ' ' << result << endl;
    if(!cur) break;
    bool numBit = num & (1 << i);
    bool targetBit = target & (1 << i);
    if(targetBit) {
      if(cur->child[numBit]) result += cur->child[numBit]->count;
      cur = cur->child[!numBit];
    } else {
      cur = cur->child[numBit];
    }
  }
  if(cur) result += cur->count;
  return result;
}
int solve(vector<int> &nums, int low, int high) {
  TrieNode *root = new TrieNode();
  int answer = 0;
  for(auto n : nums) {
    answer += find(root, n, high) - find(root, n, low - 1);
    // cout << find(root, n, high) << ' ' << find(root, n, low - 1) << ' ' << answer << endl;
    insert(root, n);
  }
  return answer;
}
class Solution {
public:
  int countPairs(vector<int>& nums, int low, int high) {
    return solve(nums, low, high);
  }
};

// Accepted
// 63/63 cases passed (164 ms)
// Your runtime beats 98.05 % of cpp submissions
// Your memory usage beats 36.72 % of cpp submissions (71.6 MB)
```

# August LeetCoding Challenge 18

## Description

**Decode Ways**

A message containing letters from `A-Z` can be **encoded** into numbers using the following mapping:

```
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
```

To **decode** an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, `"11106"` can be mapped into:

- `"AAJF"` with the grouping `(1 1 10 6)`
- `"KJF"` with the grouping `(11 10 6)`

Note that the grouping `(1 11 06)` is invalid because `"06"` cannot be mapped into `'F'` since `"6"` is different from `"06"`.

Given a string `s` containing only digits, return *the **number** of ways to **decode** it*.

The answer is guaranteed to fit in a **32-bit** integer.

 

**Example 1:**

```
Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
```

**Example 2:**

```
Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
```

**Example 3:**

```
Input: s = "0"
Output: 0
Explanation: There is no character that is mapped to a number starting with 0.
The only valid mappings with 0 are 'J' -> "10" and 'T' -> "20", neither of which start with 0.
Hence, there are no valid ways to decode this since all digits need to be mapped.
```

**Example 4:**

```
Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
```

 

**Constraints:**

- `1 <= s.length <= 100`
- `s` contains only digits and may contain leading zero(s).


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
  int numDecodings(string s) {
    int len = s.length();
    int dp = 1;
    int dp_ = 0;
    for(int i = 0; i < len && dp; i++) {
      int nextDP = 0;
      if(s[i] > '0') {
        nextDP = dp;
      }
      if(i) {
        int code = (s[i - 1] - '0') * 10 + s[i] - '0';
        if(code > 9 && code < 27) {
          nextDP += dp_;
        }
      }
      dp_ = dp;
      dp = nextDP;
    }
    return dp;
  }
};

// Accepted
// 269/269 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 90.44 % of cpp submissions (6.1 MB)
```
