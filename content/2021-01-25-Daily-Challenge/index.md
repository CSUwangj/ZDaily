+++
title = "2021-01-25 Daily-Challenge"
path = "2021-01-25-Daily-Challenge"
date = 2021-01-25 18:00:59+08:00
updated = 2021-01-25 20:55:23+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Circular Array Loop](https://leetcode.com/problems/circular-array-loop/), [Letter Tile Possibilities](https://leetcode.com/problems/letter-tile-possibilities/) and leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3616/) with `cpp`.

<!-- more -->

# Circular Array Loop

## Description

You are given a **circular** array `nums` of positive and negative integers. If a number *k* at an index is positive, then move forward *k* steps. Conversely, if it's negative (-*k*), move backward *k* steps. Since the array is circular, you may assume that the last element's next element is the first element, and the first element's previous element is the last element.

Determine if there is a loop (or a cycle) in `nums`. A cycle must start and end at the same index and the cycle's length > 1. Furthermore, movements in a cycle must all follow a single direction. In other words, a cycle must not consist of both forward and backward movements.

 

**Example 1:**

```
Input: [2,-1,1,2,2]
Output: true
Explanation: There is a cycle, from index 0 -> 2 -> 3 -> 0. The cycle's length is 3.
```

**Example 2:**

```
Input: [-1,2]
Output: false
Explanation: The movement from index 1 -> 1 -> 1 ... is not a cycle, because the cycle's length is 1. By definition the cycle's length must be greater than 1.
```

**Example 3:**

```
Input: [-2,1,-1,-2,-2]
Output: false
Explanation: The movement from index 1 -> 2 -> 1 -> ... is not a cycle, because movement from index 1 -> 2 is a forward movement, but movement from index 2 -> 1 is a backward movement. All movements in a cycle must follow a single direction.
```

 

**Note:**

1. -1000 ≤ nums[i] ≤ 1000
2. nums[i] ≠ 0
3. 1 ≤ nums.length ≤ 5000

 

**Follow up:**

Could you solve it in **O(n)** time complexity and **O(1)** extra space complexity?

## Solution

note that there range of `nums[i]` is `[-1000, 0)` $\cup$ `(0, 1000]`, so we can use rest of number of `int` to represent `vis[]` and `currentVis[]`, I want to write this and use optimization trick, but I don't have enough time...

``` cpp
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int len = nums.size();
        vector<bool> vis(len);
        for(int i = 0; i < len; ++i) {
            if(vis[i]) continue;
            int pos = i;
            int positive = nums[i] > 0;
            vector<bool> currentVis(len);
            while((nums[pos] > 0) == positive && !vis[pos] && !currentVis[pos]) {
                cout << pos << ' ';
                currentVis[pos] = true;
                pos += nums[pos];
                // cout << nums[i] << ' ' << pos << endl;
                if(pos < 0 || pos >= len) pos = (pos%len + len) % len;
            }
            if(currentVis[pos]) {
                int cirLen = 0;
                int point = pos;
                fill(currentVis.begin(), currentVis.end(), false);
                pos = ((pos + nums[pos])%len + len) % len;
                while(pos != point) {
                    pos += nums[pos];
                    if(pos < 0 || pos >= len) pos = (pos%len + len) % len;
                    cirLen += 1;
                }
                // cout << "len: " << cirLen << endl;
                if(cirLen) return true;
            }
            pos = i;
            while((nums[pos] > 0) == positive && !vis[pos]) {
                vis[pos] = true;
                pos += nums[i];
                if(pos < 0 || pos >= len) pos = (pos%len + len) % len;
            }
        }
        return false;
    }
};
```

oh, slow/fast pointer!

# Letter Tile Possibilities

## Description

You have `n` `tiles`, where each tile has one letter `tiles[i]` printed on it.

Return *the number of possible non-empty sequences of letters* you can make using the letters printed on those `tiles`.

 

**Example 1:**

```
Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
```

**Example 2:**

```
Input: tiles = "AAABBC"
Output: 188
```

**Example 3:**

```
Input: tiles = "V"
Output: 1
```

 

**Constraints:**

- `1 <= tiles.length <= 7`
- `tiles` consists of uppercase English letters.

## Solution

I found it is hard to using dynamic programming to solve it. but data range is small enough for DFS.

``` cpp
class Solution {
    map<char, int> cnt;
    int answer = 0;
    int suffix[128] = {0};
    int cntArr[128] = {0};

    int permutation(int m) {
        int result = 1;
        while(m > 0) result *= m--;
        return result;
    }

    int compute(vector<int> &helper, int all) {
        int result = permutation(all);
        for(auto i : helper) result /= permutation(i);
        return result;
    }

    void dfs(vector<int> &helper, int rest, int all, map<char, int>::iterator it) {
        if(it == cnt.end()) {
            if(rest == 0) {
                // cout << compute(helper, all) << endl;
                answer += compute(helper, all);
            }
            return;
        }
        char c = it->first;
        for(int i = max(0, rest - suffix[c]); i <= min(it->second, rest); ++i) {
            helper.push_back(i);
            ++it;
            dfs(helper, rest-i, all, it);
            --it;
            helper.pop_back();
        }
    }
public:
    int numTilePossibilities(string tiles) {
        int len = tiles.length();
        for(auto c : tiles) { 
            cnt[c] += 1;
            cntArr[c] += 1;
        }
        for(int i = cnt.rbegin()->first; i >= cnt.begin()->first; --i) {
            suffix[i] = suffix[i+1] + cntArr[i+1];
        }
        // for(int i = 'A'; i <= 'Z'; ++i) cout << suffix[i] << ' ';
        vector<int> helper;
        for(int i = 1; i <= len; ++i) {
            dfs(helper, i, i, cnt.begin());
        }
        return answer;
    }
};
```

# January LeetCoding Challenge25

**Check If All 1's Are at Least Length K Places Away**

## Description

Given an array `nums` of 0s and 1s and an integer `k`, return `True` if all 1's are at least `k` places away from each other, otherwise return `False`.

 

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2020/04/15/sample_1_1791.png)**

```
Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.
```

**Example 2:**

**![img](https://assets.leetcode.com/uploads/2020/04/15/sample_2_1791.png)**

```
Input: nums = [1,0,0,1,0,1], k = 2
Output: false
Explanation: The second 1 and third 1 are only one apart from each other.
```

**Example 3:**

```
Input: nums = [1,1,1,1,1], k = 0
Output: true
```

**Example 4:**

```
Input: nums = [0,1,0,1], k = 1
Output: true
```

 

**Constraints:**

- `1 <= nums.length <= 105`
- `0 <= k <= nums.length`
- `nums[i]` is `0` or `1`

## Solution

``` cpp
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int pos = -1e5;
        int len = nums.size();
        for(int i = 0; i < len; ++i) {
            if(nums[i]) {
                if(i - pos < k+1) return false;
                pos = i;
            }
        }
        return true;
    }
};
```
