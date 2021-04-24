+++
title = "2020-11-19 Daily-Challenge"
path = "2020-11-19-Daily-Challenge"
date = 2020-11-19 07:32:13+08:00
updated = 2020-11-19 18:58:19+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Greatest Sum Divisible by Three* on [leetcode](https://leetcode.com/problems/greatest-sum-divisible-by-three/) and leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3536/) with `cpp`.

<!-- more -->

# Greatest Sum Divisible by Three

## Description

Given an array `nums` of integers, we need to find the maximum possible sum of elements of the array such that it is divisible by three.

**Example 1:**

```
Input: nums = [3,6,5,1,8]
Output: 18
Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
```

**Example 2:**

```
Input: nums = [4]
Output: 0
Explanation: Since 4 is not divisible by 3, do not pick any number.
```

**Example 3:**

```
Input: nums = [1,2,3,4,4]
Output: 12
Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).
```

**Constraints:**

- `1 <= nums.length <= 4 * 10^4`
- `1 <= nums[i] <= 10^4`

## Solution

not so elegant

``` cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
class Solution {
public:
  int maxSumDivThree(vector<int>& nums) {
    vector<int> one;
    vector<int> two;
    int three = 0;
    for(auto num : nums) {
      if(num % 3 == 0) {
        three += num;
      } else if(num % 3 == 1) {
        one.push_back(num);
      } else {
        two.push_back(num);
      }
    }
    sort(one.begin(), one.end(), greater<int>());
    sort(two.begin(), two.end(), greater<int>());
    
    int maxOfOneAndTwo = 0;
    for(int i = 0; i+2 < one.size(); i += 3) {
      maxOfOneAndTwo += one[i] + one[i+1] + one[i+2];
    }
    for(int i = 0; i+2 < two.size(); i += 3) {
      maxOfOneAndTwo += two[i] + two[i+1] + two[i+2];
    }
    if(one.size() > 0 && two.size() > 0) {
      int cur = one[0] + two[0];
      for(int i = 1; i+2 < one.size(); i += 3) {
        cur += one[i] + one[i+1] + one[i+2];
      }
      for(int i = 1; i+2 < two.size(); i += 3) {
        cur += two[i] + two[i+1] + two[i+2];
      }
      maxOfOneAndTwo = max(cur, maxOfOneAndTwo);
    }
    if(one.size() > 1 && two.size() > 1) {
      int cur = one[0] + two[0] + one[1] + two[1];
      for(int i = 2; i+2 < one.size(); i += 3) {
        cur += one[i] + one[i+1] + one[i+2];
      }
      for(int i = 2; i+2 < two.size(); i += 3) {
        cur += two[i] + two[i+1] + two[i+2];
      }
      maxOfOneAndTwo = max(cur, maxOfOneAndTwo);
    }
    return three + maxOfOneAndTwo;
  }
};
```

# November LeetCoding Challenge19

## Description

**Decode String**

Given an encoded string, return its decoded string.

The encoding rule is: `k[encoded_string]`, where the *encoded_string* inside the square brackets is being repeated exactly *k* times. Note that *k* is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, *k*. For example, there won't be input like `3a` or `2[4]`.

**Example 1:**

```
Input: s = "3[a]2[bc]"
Output: "aaabcbc"
```

**Example 2:**

```
Input: s = "3[a2[c]]"
Output: "accaccacc"
```

**Example 3:**

```
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
```

**Example 4:**

```
Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"
```

**Constraints:**

- `1 <= s.length <= 30`
- `s` consists of lowercase English letters, digits, and square brackets `'[]'`.
- `s` is guaranteed to be **a valid** input.
- All the integers in `s` are in the range `[1, 300]`.

## Solution

nothing to say

``` cpp
class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        string current;
        int repeat = 0;
        for(auto c : s) {
            if(islower(c)) {
                current += c;
            } else if (isdigit(c)) {
                repeat *= 10;
                repeat += c - '0';
            } else if (c == '[') {
                st.push(make_pair(current, repeat));
                repeat = 0;
                current = "";
            } else {
                auto [lastString, lastRepeat] = st.top();
                st.pop();
                for(int i = 0; i < lastRepeat; ++i) {
                    lastString += current;
                }
                current = lastString;
            }
        }
        return current;
    }
};
```
