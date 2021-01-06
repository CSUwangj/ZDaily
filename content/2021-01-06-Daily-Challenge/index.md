+++
title = "2021-01-06 Daily-Challenge"
path = "2021-01-06-Daily-Challenge"
date = 2021-01-06 18:06:44+08:00
updated = 2021-01-06 18:54:10+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Verbal Arithmetic Puzzle](https://leetcode.com/problems/verbal-arithmetic-puzzle/) on leetcode and leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3594/) with `cpp`.

<!-- more -->

# Verbal Arithmetic Puzzle

## Description

Given an equation, represented by `words` on left side and the `result` on right side.

You need to check if the equation is solvable under the following rules:

- Each character is decoded as one digit (0 - 9).
- Every pair of different characters they must map to different digits.
- Each `words[i]` and `result` are decoded as one number **without** leading zeros.
- Sum of numbers on left side (`words`) will equal to the number on right side (`result`). 

Return `True` if the equation is solvable otherwise return `False`.

**Example 1:**

```
Input: words = ["SEND","MORE"], result = "MONEY"
Output: true
Explanation: Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652
```

**Example 2:**

```
Input: words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
Output: true
Explanation: Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4
Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214
```

**Example 3:**

```
Input: words = ["THIS","IS","TOO"], result = "FUNNY"
Output: true
```

**Example 4:**

```
Input: words = ["LEET","CODE"], result = "POINT"
Output: false
```

**Constraints:**

- `2 <= words.length <= 5`
- `1 <= words[i].length, result.length <= 7`
- `words[i], result` contains only upper case English letters.
- Number of different characters used on the expression is at most 10.

## Solution

reverse the numbers so we can determine if we need to go deeper earlier.

``` cpp
class Solution {
    int mp[128];
    unordered_map<char, bool> leading;
    bool used[10] = {false};
    int maxLength = 0;
    bool dfs(vector<string>& words, string &result, int index, int sIndex, int sum) {
        if(sIndex > maxLength) return true;
        if(index == words.size()) {
            if(mp[result[sIndex]] != -1 && mp[result[sIndex]] != sum%10) return false;
            if(mp[result[sIndex]] == -1 && used[sum%10]) return false;
            if(sum % 10 == 0 && leading[result[sIndex]]) return false;
            bool u = used[sum%10];
            if(!u) {
                mp[result[sIndex]] = sum%10;
                used[sum%10] = true;
            }
            if(dfs(words, result, 0, sIndex+1, sum/10)) return true;
            if(!u){
                used[sum%10] = false;
                mp[result[sIndex]] = -1;
            }
            return false;
        }
        if(sIndex >= words[index].length()) return dfs(words, result, index+1, sIndex, sum);
        if(mp[words[index][sIndex]] != -1) return dfs(words, result, index+1, sIndex, sum+mp[words[index][sIndex]]);
        for(int i = leading[words[index][sIndex]]; i < 10; ++i) {
            if(used[i]) continue;
            used[i] = true;
            mp[words[index][sIndex]] = i;
            if(dfs(words, result, index+1, sIndex, sum+i)) return true;
            used[i] = false;
            mp[words[index][sIndex]] = -1;
        }
        return false;
    }
public:
    bool isSolvable(vector<string>& words, string result) {
        for(auto &word : words) {
            if(word.length() > 1) leading[word[0]] = true;
            if(maxLength < word.length()) maxLength = word.length();
            for(auto c : word) {
                mp[c] = -1;
            }
        }
        if(result.length() > 1) leading[result[0]] = true;
        if(maxLength > result.length()) return false;
        maxLength = result.length();
        for(auto c : result) {
            mp[c] = -1;
        }
        reverse(result.begin(), result.end());
        for(auto &word : words) {
            reverse(word.begin(), word.end());
        }
        return dfs(words, result, 0, 0, 0);
    }
};
```

# January LeetCoding Challenge6

## Description

**Kth Missing Positive Number**

Given an array `arr` of positive integers sorted in a **strictly increasing order**, and an integer `k`.

*Find the* `kth` *positive integer that is missing from this array.*

**Example 1:**

```
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
```

**Example 2:**

```
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
```

**Constraints:**

- `1 <= arr.length <= 1000`
- `1 <= arr[i] <= 1000`
- `1 <= k <= 1000`
- `arr[i] < arr[j]` for `1 <= i < j <= arr.length`

## Solution

``` cpp
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int pos = 0;
        int prev = 0;
        arr.push_back(INT_MAX);
        while(k) {
            while(arr[pos] - prev == 1) {
                prev = arr[pos];
                pos += 1;
            }
            if(prev + k < arr[pos]) return prev+k;
            else {
                k -= arr[pos] - prev - 1;
                prev = arr[pos];
                pos += 1;
            }
        }
        return -1;
    }
};
```