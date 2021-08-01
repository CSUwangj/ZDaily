+++
title = "2021-01-31 Daily-Challenge"
path = "2021-01-31-Daily-Challenge"
date = 2021-01-31 11:24:22+08:00
updated = 2021-01-31 16:15:28+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/583/week-5-january-29th-january-31st/3623/) with `cpp`.

BTW, I participated in Weekly Contest 226.

<!-- more -->

# January LeetCoding Challenge 31

## Description

**Next Permutation**

Implement **next permutation**, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be **[in place](http://en.wikipedia.org/wiki/In-place_algorithm)** and use only constant extra memory.

 

**Example 1:**

```
Input: nums = [1,2,3]
Output: [1,3,2]
```

**Example 2:**

```
Input: nums = [3,2,1]
Output: [1,2,3]
```

**Example 3:**

```
Input: nums = [1,1,5]
Output: [1,5,1]
```

**Example 4:**

```
Input: nums = [1]
Output: [1]
```

 

**Constraints:**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 100`

## Solution

...

``` cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};
```

``` cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int pos = len - 1;
        
        while(pos && nums[pos] <= nums[pos-1]) --pos;
        if(!pos) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int swapPos = len - 1;
        --pos;
        while(nums[swapPos] <= nums[pos]) swapPos -= 1;
        swap(nums[swapPos], nums[pos]);
        reverse(nums.begin() + pos + 1, nums.end());
    }
};
```

# Weekly Contest 226

## 5654. Maximum Number of Balls in a Box

You are working in a ball factory where you have `n` balls numbered from `lowLimit` up to `highLimit` **inclusive** (i.e., `n == highLimit - lowLimit + 1`), and an infinite number of boxes numbered from `1` to `infinity`.

Your job at this factory is to put each ball in the box with a number equal to the sum of digits of the ball's number. For example, the ball number `321` will be put in the box number `3 + 2 + 1 = 6` and the ball number `10` will be put in the box number `1 + 0 = 1`.

Given two integers `lowLimit` and `highLimit`, return *the number of balls in the box with the most balls.*

 

**Example 1:**

```
Input: lowLimit = 1, highLimit = 10
Output: 2
Explanation:
Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
Ball Count:  2 1 1 1 1 1 1 1 1 0  0  ...
Box 1 has the most number of balls with 2 balls.
```

**Example 2:**

```
Input: lowLimit = 5, highLimit = 15
Output: 2
Explanation:
Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
Ball Count:  1 1 1 1 2 2 1 1 1 0  0  ...
Boxes 5 and 6 have the most number of balls with 2 balls in each.
```

**Example 3:**

```
Input: lowLimit = 19, highLimit = 28
Output: 2
Explanation:
Box Number:  1 2 3 4 5 6 7 8 9 10 11 12 ...
Ball Count:  0 1 1 1 1 1 1 1 1 2  0  0  ...
Box 10 has the most number of balls with 2 balls.
```

 

**Constraints:**

- `1 <= lowLimit <= highLimit <= 105`

### Solution

brute force

``` cpp
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> count(100);
        for(int i = lowLimit; i <= highLimit; ++i) {
            int c = i;
            int sum = 0;
            while(c) {
                sum += c % 10;
                c /= 10;
            }
            count[sum] += 1;
        }
        return *max_element(count.begin(), count.end());
    }
};
```

## 5665. Restore the Array From Adjacent Pairs

There is an integer array `nums` that consists of `n` **unique** elements, but you have forgotten it. However, you do remember every pair of adjacent elements in `nums`.

You are given a 2D integer array `adjacentPairs` of size `n - 1` where each `adjacentPairs[i] = [ui, vi]` indicates that the elements `ui` and `vi` are adjacent in `nums`.

It is guaranteed that every adjacent pair of elements `nums[i]` and `nums[i+1]` will exist in `adjacentPairs`, either as `[nums[i], nums[i+1]]` or `[nums[i+1], nums[i]]`. The pairs can appear **in any order**.

Return *the original array* `nums`*. If there are multiple solutions, return **any of them***.

 

**Example 1:**

```
Input: adjacentPairs = [[2,1],[3,4],[3,2]]
Output: [1,2,3,4]
Explanation: This array has all its adjacent pairs in adjacentPairs.
Notice that adjacentPairs[i] may not be in left-to-right order.
```

**Example 2:**

```
Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
Output: [-2,4,1,-3]
Explanation: There can be negative numbers.
Another solution is [-3,1,4,-2], which would also be accepted.
```

**Example 3:**

```
Input: adjacentPairs = [[100000,-100000]]
Output: [100000,-100000]
```

 

**Constraints:**

- `nums.length == n`
- `adjacentPairs.length == n - 1`
- `adjacentPairs[i].length == 2`
- `2 <= n <= 105`
- `-105 <= nums[i], ui, vi <= 105`
- There exists some `nums` that has `adjacentPairs` as its pairs.

### Solution

find a start then build the array

``` cpp
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, int> degree;
        unordered_map<int, vector<int>> neighbors;
        
        for(auto &p : adjacentPairs) {
            degree[p[0]] += 1;
            degree[p[1]] += 1;
            neighbors[p[0]].push_back(p[1]);
            neighbors[p[1]].push_back(p[0]);
        }
        
        queue<int> q;
        for(auto [num, cnt] : degree) {
            if(cnt == 1) {
                q.push(num);
                // reuse as visit
                degree[num] = 0;
                break;
            }
        }
        
        vector<int> answer(adjacentPairs.size()+1);
        int count = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            answer[count++] = cur;
            for(auto n : neighbors[cur]) {
                if(degree[n] != 0) {
                    degree[n] = 0;
                    q.push(n);
                }
            }
        }
        return move(answer);
    }
};
```

## 5667. Can You Eat Your Favorite Candy on Your Favorite Day?

You are given a **(0-indexed)** array of positive integers `candiesCount` where `candiesCount[i]` represents the number of candies of the `ith` type you have. You are also given a 2D array `queries` where `queries[i] = [favoriteTypei, favoriteDayi, dailyCapi]`.

You play a game with the following rules:

- You start eating candies on day `**0**`.
- You **cannot** eat **any** candy of type `i` unless you have eaten **all** candies of type `i - 1`.
- You must eat **at least** **one** candy per day until you have eaten all the candies.

Construct a boolean array `answer` such that `answer.length == queries.length` and `answer[i]` is `true` if you can eat a candy of type `favoriteTypei` on day `favoriteDayi` without eating **more than** `dailyCapi` candies on **any** day, and `false` otherwise. Note that you can eat different types of candy on the same day, provided that you follow rule 2.

Return *the constructed array* `answer`.

 

**Example 1:**

```
Input: candiesCount = [7,4,5,3,8], queries = [[0,2,2],[4,2,4],[2,13,1000000000]]
Output: [true,false,true]
Explanation:
1- If you eat 2 candies (type 0) on day 0 and 2 candies (type 0) on day 1, you will eat a candy of type 0 on day 2.
2- You can eat at most 4 candies each day.
   If you eat 4 candies every day, you will eat 4 candies (type 0) on day 0 and 4 candies (type 0 and type 1) on day 1.
   On day 2, you can only eat 4 candies (type 1 and type 2), so you cannot eat a candy of type 4 on day 2.
3- If you eat 1 candy each day, you will eat a candy of type 2 on day 13.
```

**Example 2:**

```
Input: candiesCount = [5,2,6,4,1], queries = [[3,1,2],[4,10,3],[3,10,100],[4,100,30],[1,3,1]]
Output: [false,true,true,false,false]
```

 

**Constraints:**

- `1 <= candiesCount.length <= 105`
- `1 <= candiesCount[i] <= 105`
- `1 <= queries.length <= 105`
- `queries[i].length == 3`
- `0 <= favoriteTypei < candiesCount.length`
- `0 <= favoriteDayi <= 109`
- `1 <= dailyCapi <= 109`

### Solution

be careful, maybe overflow

``` cpp
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int len = candiesCount.size();
        vector<long long> prefix(candiesCount.size()+1);
        for(int i = 1; i <= len; ++i) prefix[i] = prefix[i-1] + candiesCount[i-1];
        
        int qlen = queries.size();
        vector<bool> answer(qlen);
        for(int i = 0; i < qlen; ++i) {
            long long type = queries[i][0];
            long long day = queries[i][1];
            long long cap = queries[i][2];
            long long mmax = 1LL * (day+1) * cap;
            long long mmin = 1LL * (day+1);
            answer[i] = (mmin <= prefix[type+1]) && (mmax > prefix[type]);
        }
        return move(answer);
    }
};
```

## 5666. Palindrome Partitioning IV

Given a string `s`, return `true` *if it is possible to split the string* `s` *into three **non-empty** palindromic substrings. Otherwise, return* `false`.

A string is said to be palindrome if it the same string when reversed.

 

**Example 1:**

```
Input: s = "abcbdd"
Output: true
Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.
```

**Example 2:**

```
Input: s = "bcbddxy"
Output: false
Explanation: s cannot be split into 3 palindromes.
```

 

**Constraints:**

- `3 <= s.length <= 2000`
- `s` consists only of lowercase English letters.

### Solution

enumerate all possible palindromes, and enumerate all possible length of three palindromes.

``` cpp
class Solution {
public:
    bool checkPartitioning(string s) {
        int len = s.length();
        vector<vector<bool>> palin(len+1, vector<bool>(len+1));
        for(int i = 0; i < len; ++i) {
            palin[i][i+1] = true;
            for(int j = 1; i-j >= 0 && i+j < len; ++j) {
                if(s[i-j] == s[i+j]) palin[i-j][i+j+1] = true;
                else break;
            }
            for(int j = 1; i-j+1 >= 0 && i+j < len; ++j) {
                if(s[i-j+1] == s[i+j]) palin[i-j+1][i+j+1] = true;
                else break;
            }
        }
        for(int i = 1; i < len-1; ++i) {
            if(!palin[0][i]) continue;
            for(int j = 1; j+i < len; ++j) {
                if(palin[i][i+j] && palin[i+j][len]) return true;
            }
        }
        return false;
    }
};
```