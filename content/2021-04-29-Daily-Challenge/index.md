+++
title = "2021-04-29 Daily-Challenge"
path = "2021-04-29-Daily-Challenge"
date = 2021-04-29 18:20:02+08:00
updated = 2021-04-29 20:47:42+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Minimum Insertion Steps to Make a String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/) and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3723/) with `cpp`.

<!-- more -->

# Minimum Insertion Steps to Make a String Palindrome

## Description

Given a string `s`. In one step you can insert any character at any index of the string.

Return *the minimum number of steps* to make `s` palindrome.

A **Palindrome String** is one that reads the same backward as well as forward.

 

**Example 1:**

```
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.
```

**Example 2:**

```
Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
```

**Example 3:**

```
Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
```

**Example 4:**

```
Input: s = "g"
Output: 0
```

**Example 5:**

```
Input: s = "no"
Output: 1
```

 

**Constraints:**

- `1 <= s.length <= 500`
- All characters of `s` are lower case English letters.

## Solution

I first write this

``` cpp
class Solution {
  int minInsert(string &s, string &l) {
    int len = s.length();
    int llen = l.length();
    vector<int> dp(len + 1);
    for(int i = 0; i < llen; ++i) {
      int prev = 0;
      for(int j = 0; j < len; ++j) {
        dp[i + 1] = max(prev, dp[i + 1]);
        if(s[j] == l[i]) {
          dp[j + 1] = max(dp[j] + 1, dp[j + 1]);
        }
        prev = dp[j + 1];
      }
    }
    return len + llen - 2 * dp.back();
  }
public:
  int minInsertions(string s) {
    int len = s.length();
    int answer = len - 1;
    for(int i = 1; i < len - 1; ++i) {
      cout << i << ' ';
      string l = s.substr(i);
      string st = s.substr(0, i);
      cout << st << ' ' << l << endl;
      reverse(l.begin(), l.end());
      answer = min(answer, minInsert(st, l));
      l.pop_back();
      answer = min(answer, minInsert(st, l));
    }
    return answer;
  }
};
```

try to optimize

``` cpp
auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
  vector<vector<int>> dp;
  int minInsert(string &s1, string &s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    // cout << "$$$$$$";
    for(int i = 0; i <= len2; ++i) {
      dp[0][i] = 0;
      dp[1][i] = 0;
    }
    for(int i = 0; i < len1; ++i) {
      for(int j = 1; j <= len2; ++j) {
        int parity = i & 1;
        dp[parity][j] = max(dp[!parity][j], dp[parity][j - 1]);
        if(s2[j - 1] == s1[i]) {
          dp[parity][j] = max(dp[parity][j], dp[!parity][j - 1] + 1);
        }
      }
    }
    return len1 + len2 - 2 * dp[!(len1 & 1)][len2];
  }
  bool isPalindrome(string &s) {
    int len = s.length();
    for(int i = 0; i * 2 < len; ++i) {
      if(s[i] != s[len - 1 - i]) return false;
    }
    return true;
  }
public:
  int minInsertions(string s) {
    if(isPalindrome(s)) return 0;
    int len = s.length();
    int answer = len - 1;
    string l;
    string r = s;
    dp.resize(2, vector<int>(len + 1));
    for(int i = 1; i < len; ++i) {
      char c = r.back();
      r.pop_back();
      if(len - 2 * min(i, len - i) >= answer) continue;
      answer = min(answer, minInsert(l, r));
      l.push_back(c);
      answer = min(answer, minInsert(l, r));
    }
    return answer;
  }
};

// abcdefg
// ab gfedc
```

finaly, I read other's post and realized...

``` cpp
auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
  int LCS(string &s1, string &s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    // cout << "$$$$$$";
    vector<vector<int>> dp(2, vector<int>(len2 + 1));
    for(int i = 0; i < len1; ++i) {
      for(int j = 1; j <= len2; ++j) {
        int parity = i & 1;
        dp[parity][j] = max(dp[!parity][j], dp[parity][j - 1]);
        if(s2[j - 1] == s1[i]) {
          dp[parity][j] = max(dp[parity][j], dp[!parity][j - 1] + 1);
        }
      }
    }
    return dp[!(len1 & 1)][len2];
  }
  bool isPalindrome(string &s) {
    int len = s.length();
    for(int i = 0; i * 2 < len; ++i) {
      if(s[i] != s[len - 1 - i]) return false;
    }
    return true;
  }
public:
  int minInsertions(string s) {
    if(isPalindrome(s)) return 0;
    string r = s;
    reverse(r.begin(), r.end());
    return s.length() - LCS(s, r);
  }
}; 
```

# April LeetCoding challenge29

## Description

**Find First and Last Position of Element in Sorted Array**

Given an array of integers `nums` sorted in ascending order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

**Follow up:** Could you write an algorithm with `O(log n)` runtime complexity?

 

**Example 1:**

```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

**Example 2:**

```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```

**Example 3:**

```
Input: nums = [], target = 0
Output: [-1,-1]
```

 

**Constraints:**

- <code>0 <= nums.length <= 10<sup>5</sup></code>
- <code>-10<sup>9</sup> <= nums[i] <= 10<sup>9</sup></code>
- `nums` is a non-decreasing array.
- <code>-10<sup>9</sup> <= target <= 10<sup>9</sup></code>

## Solution

``` cpp
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int len = nums.size();
    if(!len) return{-1, -1};
    int begin = 0;
    int end = len - 1;
    while(begin < end) {
      int mid = (begin + end) >> 1;
      if(nums[mid] < target) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    if(nums[begin] != target) return {-1, -1};
    int left = begin;
    begin = 0;
    end = len - 1;
    while(begin < end) {
      int mid = (begin + end + 1) >> 1;
      if(nums[mid] > target) {
        end = mid - 1;
      } else {
        begin = mid;
      }
    }
    return {left, begin};
  }
};
```

``` cpp
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int len = nums.size();
    if(!len) return{-1, -1};
    auto left = lower_bound(nums.begin(), nums.end(), target);
    if((left == nums.end()) || (*left != target)) return {-1, -1};
    auto right = upper_bound(nums.begin(), nums.end(), target);
    --right;
    int l = left - nums.begin();
    int r = right - nums.begin();
    return {l, r};
  }
};
```
