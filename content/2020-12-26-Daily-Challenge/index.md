+++
title = "2020-12-26 Daily-Challenge"
path = "2020-12-26-Daily-Challenge"
date = 2020-12-26 15:38:47+08:00
updated = 2020-12-26 23:59:16+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3571/) with `cpp`.

<!-- more -->

# LeetCode Review

## Smallest Range I

nothing to say 

``` cpp
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int mmin = INT_MAX, mmax = INT_MIN;
        for(auto i : A) {
            mmin = min(mmin, i);
            mmax = max(mmax, i);
        }
        return max(mmax-mmin-2*K, 0);
    }
};
```

## Smallest Range II

``` cpp
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        if(A.size() < 2) return 0;
        sort(A.begin(), A.end());
        int answer = A.back() - A.front();
        for(int i = 1; i < A.size(); ++i) {
            int high = max(A.back()-K, A[i-1]+K);
            int low = min(A.front()+K, A[i]-K);
            answer = min(answer, high-low);
        }
        return answer;
    }
};
```

## Shopping Offers

don't want to review it.

## Next Greater Element III

don't want to write a next_permutation

## Make Two Arrays Equal by Reversing Sub-arrays

too easy to review

## Path Sum

too easy to review

## Swap Nodes in Pairs

too easy to review

## Diagonal Traverse

too easy to review

## Balanced Binary Tree

``` cpp
class Solution {
    pair<int, bool> helper(TreeNode *root) {
        if(!root) return make_pair(0, true);
        auto [heightLeft, balancedLeft] = helper(root->left);
        auto [heightRight, balancedRight] = helper(root->right);
        int diff = abs(heightLeft-heightRight);
        auto balanced = balancedLeft && balancedRight && diff < 2;
        return make_pair(1+max(heightLeft, heightRight),  balanced);
    }
public:
    bool isBalanced(TreeNode* root) {
        auto [_height, balanced] = helper(root);
        return balanced;
    }
};
```

## Unique Substrings in Wraparound String

no need to update previous letter because it is already updated when iterated over it.

``` cpp
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int cnt[26] = {0};
        int length = 0;
        int pLength = p.length();
        for(int i = 0; i < pLength; ++i) {
            char last = p[i] == 'a' ? 'z' : p[i]-1;
            int index = p[i] - 'a';
            if(i && p[i-1] != last) {
                length = 0;
            }
            length += 1;
            cnt[index] = max(cnt[index], length);
        }
        
        int answer = 0;
        for(int i = 0; i < 26; ++i) answer += cnt[i];
        return answer;
    }
};
```

BTW following solution seems more efficient

``` cpp
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int length[26] = {0};
        int pos = 0, len = p.length();
        int currentLength = 0;
        int lastChar = -1;
        while(pos < len) {
            int currentChar = p[pos]-'a';
            int prevChar = (currentChar - 1 + 26) % 26;
            if(lastChar != prevChar) {
                currentLength = 0;
            }
            currentLength += 1;
            if(length[currentChar] < currentLength) {
                length[currentChar] = currentLength;
            }
            lastChar = currentChar;
            pos += 1;
        }
        int answer = 0;
        for(int i = 0; i < 26; ++i) {
            answer += length[i];
        }
        return answer;
    }
};
```

## 3Sum

use dfs with set

``` cpp
class Solution {
    int len;
    
    vector<vector<int>> twoSum(vector<int> &nums, int target, int start) {
        vector<vector<int>> answer;
        unordered_set<int> st;
        for(int i = start; i < len; ++i) {
            if(answer.size() && answer.back()[1] == nums[i]) continue;
            if(st.count(nums[i])) {
                answer.push_back(vector<int>{target-nums[i], nums[i]});
            }
            st.insert(target-nums[i]);
        }
        return answer;
    }
    
    vector<vector<int>> kSum(vector<int> &nums, int target, int start, int k) {
        vector<vector<int>> answer;
        if(nums[start] * k > target || target > nums.back() * k) return answer;
        if(k == 2) return twoSum(nums, target, start);
        for(int i = start; i <= len-k; ++i) {
            if(i != start && nums[i] == nums[i-1]) continue;
            for(auto &vec : kSum(nums, target-nums[i], i+1, k-1)) {
                answer.push_back({nums[i]});
                answer.back().insert(answer.back().end(), vec.begin(), vec.end());
            }
        }
        return answer;
    }
    
    void init(vector<int> &nums) {
        len = nums.size();
        sort(nums.begin(), nums.end());
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return vector<vector<int>>();
        init(nums);
        return kSum(nums, 0, 0, 3);
    }
};
```

## 4Sum

use dfs with set

``` cpp
class Solution {
    int len;
    
    vector<vector<int>> twoSum(vector<int> &nums, int target, int start) {
        vector<vector<int>> answer;
        unordered_set<int> st;
        for(int i = start; i < len; ++i) {
            if(answer.size() && answer.back()[1] == nums[i]) continue;
            if(st.count(nums[i])) {
                answer.push_back(vector<int>{target-nums[i], nums[i]});
            }
            st.insert(target-nums[i]);
        }
        return answer;
    }
    
    vector<vector<int>> kSum(vector<int> &nums, int target, int start, int k) {
        vector<vector<int>> answer;
        if(nums[start] * k > target || target > nums.back() * k) return answer;
        if(k == 2) return twoSum(nums, target, start);
        for(int i = start; i <= len-k; ++i) {
            if(i != start && nums[i] == nums[i-1]) continue;
            for(auto &vec : kSum(nums, target-nums[i], i+1, k-1)) {
                answer.push_back({nums[i]});
                answer.back().insert(answer.back().end(), vec.begin(), vec.end());
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
        if(nums.size() < 4) return vector<vector<int>>();
        init(nums);
        return kSum(nums, target, 0, 4);
    }
};
```

# December LeetCoding Challenge26

## Description

**Decode Ways**

## Description

A message containing letters from `A-Z` is being encoded to numbers using the following mapping:

```
'A' -> 1
'B' -> 2
...
'Z' -> 26
```

Given a **non-empty** string containing only digits, determine the total number of ways to decode it.

The answer is guaranteed to fit in a **32-bit** integer.

**Example 1:**

```
Input: s = "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
```

**Example 2:**

```
Input: s = "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
```

**Example 3:**

```
Input: s = "0"
Output: 0
Explanation: There is no character that is mapped to a number starting with '0'. We cannot ignore a zero when we face it while decoding. So, each '0' should be part of "10" --> 'J' or "20" --> 'T'.
```

**Example 4:**

```
Input: s = "1"
Output: 1
```

**Constraints:**

- `1 <= s.length <= 100`
- `s` contains only digits and may contain leading zero(s).

## Solution

simple DP

``` cpp
class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        vector<int> dp(len+1);
        dp[0] = 1;
        for(int i = 0; i < len; ++i) {
            if(s[i] > '0') {
                dp[i+1] = dp[i];
            } if(i) {
                int code = (s[i-1]-'0')*10 + s[i]-'0';
                if(code > 9 && code < 27) {
                    dp[i+1] += dp[i-1];
                }
            }
        }
        return dp.back();
    }
};
```
