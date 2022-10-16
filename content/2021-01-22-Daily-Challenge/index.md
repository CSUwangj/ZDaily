+++
title = "2021-01-22 Daily-Challenge"
path = "2021-01-22-Daily-Challenge"
date = 2021-01-22 18:00:59+08:00
updated = 2021-01-22 19:05:05+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [To Lower Case](https://leetcode.com/problems/to-lower-case), [Predict the Winner](https://leetcode.com/problems/predict-the-winner/) and leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3611/) with `cpp`.

<!-- more -->

# To Lower Case

## Description

Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

 

**Example 1:**

```
Input: "Hello"
Output: "hello"
```

**Example 2:**

```
Input: "here"
Output: "here"
```

**Example 3:**

```
Input: "LOVELY"
Output: "lovely"
```

## Solution

``` cpp
class Solution {
public:
    string toLowerCase(string str) {
        string answer;
        for(auto c : str) {
            if(c > 'Z' || c < 'A') answer.push_back(c);
            else answer.push_back(c + 32);
        }
        return answer;
    }
};
```

# Predict the Winner

## Description

Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

**Example 1:**

```
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return False.
```

 

**Example 2:**

```
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
```

 

**Constraints:**

- 1 <= length of the array <= 20.
- Any scores in the given array are non-negative integers and will not exceed 10,000,000.
- If the scores of both players are equal, then player 1 is still the winner.

## Solution

similar to interval dynamic programming, but only change at front and last.

``` cpp
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> dp[2];
        dp[0].resize(len, vector<int>(len));
        dp[1].resize(len, vector<int>(len));
        for(int i = 0; i < len; ++i) {
            dp[1][i][i] = nums[i];
        }
        for(int i = 1; i < len; ++i) {
            for(int j = 0; j+i < len; ++j) {
                int takeFrontFirst = nums[j] + dp[0][j+1][j+i];
                int takeFrontSecond = dp[1][j+1][j+i];
                int takeLastFirst = nums[j+i] + dp[0][j][j+i-1];
                int takeLastSecond = dp[1][j][j+i-1];
                if(takeFrontFirst > takeLastFirst) {
                    dp[0][j][j+i] = takeFrontSecond;
                    dp[1][j][j+i] = takeFrontFirst;
                } else {
                    dp[0][j][j+i] = takeLastSecond;
                    dp[1][j][j+i] = takeLastFirst;
                }
            }
        }
        return dp[1][0][len-1] >= dp[0][0][len-1];
    }
};
```

# January LeetCoding Challenge 22

## Description

**Find the Most Competitive Subsequence**

Two strings are considered **close** if you can attain one from the other using the following operations:

- Operation 1: Swap any two existing characters.
  - For example, `abcde -> aecdb`
- Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
  - For example, `aacabb -> bbcbaa` (all `a`'s turn into `b`'s, and all `b`'s turn into `a`'s)

You can use the operations on either string as many times as necessary.

Given two strings, `word1` and `word2`, return `true` *if* `word1` *and* `word2` *are **close**, and* `false` *otherwise.*

 

**Example 1:**

```
Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
```

**Example 2:**

```
Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
```

**Example 3:**

```
Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
```

**Example 4:**

```
Input: word1 = "cabbba", word2 = "aabbss"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any amount of operations.
```

 

**Constraints:**

- `1 <= word1.length, word2.length <= 105`
- `word1` and `word2` contain only lowercase English letters.

## Solution

``` cpp
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;
        int cnt1[26] = {0};
        int cnt2[26] = {0};
        for(auto c : word1) cnt1[c-'a'] += 1;
        for(auto c : word2) cnt2[c-'a'] += 1;
        for(int i = 0; i < 26; ++i) {
            if((cnt1[i] && !cnt2[i]) || (!cnt1[i] && cnt2[i])) return false;
        }
        sort(cnt1, cnt1+26);
        sort(cnt2, cnt2+26);
        for(int i = 0; i < 26; ++i) {
            if(cnt1[i] != cnt2[i]) return false;
        }
        return true;
    }
};
```
