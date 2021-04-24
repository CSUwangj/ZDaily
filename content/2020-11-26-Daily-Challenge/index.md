+++
title = "2020-11-26 Daily-Challenge"
path = "2020-11-26-Daily-Challenge"
date = 2020-11-26 20:12:13+08:00
updated = 2020-11-26 21:27:07+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Maximum Length of Pair Chain* on [leetcode](https://leetcode.com/problems/maximum-length-of-pair-chain/) and leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3544/) with `cpp`.

<!-- more -->

# Maximum Length of Pair Chain

## Description

You are given `n` pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair `(c, d)` can follow another pair `(a, b)` if and only if `b < c`. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

**Example 1:**

```
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
```

**Note:**

1. The number of given pairs will be in the range [1, 1000].

## Solution

simple DP

but solution show me that greedy approach will be faster

``` cpp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int len = pairs.size();
        vector<int> dp(len, 1);
        for(int i = 1; i < len; ++i) {
            for(int j = 0; j < i; ++j) {
                if(pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1); 
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
```

# November LeetCoding Challenge26

## Description

**Longest Substring with At Least K Repeating Characters**

Given a string `s` and an integer `k`, return *the length of the longest substring of* `s` *such that the frequency of each character in this substring is less than or equal to* `k`.

**Example 1:**

```
Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
```

**Example 2:**

```
Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
```

**Constraints:**

- `1 <= s.length <= 104`
- `s` consists of only lowercase English letters.
- `1 <= k <= 105`

## Solution

sliding window runs with time complexity as $O(N)$

will try divide-and-conquer later

``` cpp
class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> occurence;
        for(auto c : s) {
            occurence[c] += 1;
        }
        int len = s.size();
        int maxChars = occurence.size();
        int answer = 0;
        for(int chars = 1; chars <= maxChars; ++chars) {
            occurence.clear();
            int cnt = 0, start = 0, end = 0;
            for(; end < len; ++end) {
                if(occurence[s[end]] == 0) {
                    cnt += 1;
                }
                occurence[s[end]] += 1;
                while(cnt > chars) {
                    occurence[s[start]] -= 1;
                    if(occurence[s[start]] == 0) {
                        cnt -= 1;
                    }
                    start += 1;
                }
                bool sat = true;
                for(auto [c, cnt] : occurence) {
                    if(cnt && cnt < k) sat = false;
                }
                if(sat) answer = max(answer, end-start+1);
            }
        }
        return answer;
    }
};
```