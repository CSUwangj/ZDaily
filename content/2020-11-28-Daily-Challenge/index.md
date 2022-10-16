+++
title = "2020-11-28 Daily-Challenge"
path = "2020-11-28-Daily-Challenge"
date = 2020-11-28 02:04:13+08:00
updated = 2020-11-28 16:27:06+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3546/) with `cpp`.

<!-- more -->

# LeetCode Review

## Monotonic Array

nothing to say

``` cpp
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int len = A.size();
        if(len < 2) return true;
        int pos = 1;
        while(pos < len && A[pos] == A[pos-1]) pos += 1;
        if(pos == len) return true;
        if(A[pos] > A[pos-1]) {
            while(pos < len && A[pos] >= A[pos-1]) pos += 1;
            return pos==len;
        }
        while(pos < len && A[pos] <= A[pos-1]) pos += 1;
        return pos==len;
    }
};
```

## House Robber III

tuple is slower

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
    // node -> {max money when rob house, max money when not rob house}
    unordered_map<TreeNode*, tuple<int, int, int>> m;
    void calc(TreeNode* root) {
        if(!root || m.count(root)) return;
        calc(root->left);
        calc(root->right);
        auto [maxRobLeft, maxNotRobLeft, maxLeft] = m[root->left];
        auto [maxRobRight, maxNotRobRight, maxRight] = m[root->right];
        int maxRob = root->val + maxNotRobLeft + maxNotRobRight;
        int maxNotRob = maxLeft + maxRight;
        m[root] = make_tuple(maxRob, maxNotRob, max(maxRob, maxNotRob));
    }
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        calc(root);
        auto [a, b, answer] = m[root];
        return answer;
    }
};
```

## Basic Calculator II

write more code

``` cpp
class Solution {
    bool shouldCompute(char current, char last) {
        if(current == '+' || current == '-') return true;
        if(last == '*' || last == '/') return true;
        return false;
    }
    void compute(stack<int> &n, stack<char> &op) {
        int op2 = n.top();
        n.pop();
        int op1 = n.top();
        n.pop();
        int o = op.top();
        op.pop();
        switch(o){
            case '+':
                n.push(op1+op2);
                break;
            case '-':
                n.push(op1-op2);
                break;
            case '*':
                n.push(op1*op2);
                break;
            case '/':
                n.push(op1/op2);
                break;
        }
    }
public:
    int calculate(string s) {
        int curNum = 0;
        bool inNum = false;
        stack<int> n;
        stack<char> op;
        for(auto c : s) {
            if(inNum && !isdigit(c)) {
                n.push(curNum);
                curNum = 0;
                inNum = false;
            }
            if(c == ' ') continue;
            if(isdigit(c)) {
                curNum *= 10;
                curNum += c - '0';
                inNum = true;
            } else {
                while(op.size() && shouldCompute(c, op.top())) {
                    compute(n, op);
                }
                op.push(c);
            }
        }
        if(inNum) n.push(curNum);
        while(op.size()) {
            compute(n, op);
        }
        return n.top();
    }
};
```

## Total Hamming Distance

seems more elegant

``` cpp
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> cnt(32);
        int len = nums.size();
        int answer = 0;
        for(int i = 0; i < len; ++i) {
            for(int b = 0; b < 32; ++b) {
                int have = ((nums[i] >> b) & 1);
                answer += have*(i-cnt[b]) + (!have)*cnt[b];
                cnt[b] += have;
            }
        }
        return answer;
    }
};
```

## Minimum Flips to Make a OR b Equal to c

nothing to say

``` cpp
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int answer = 0;
        while(a || b || c) {
            if(c & 1) {
                answer += !((a|b)&1);
            } else {
                answer += (a&1) + (b&1);
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return answer;
    }
};
```

## Maximum Length of Pair Chain

more elegant dp

``` cpp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        int cur = INT_MIN;
        int answer = 0;
        for(auto &p : pairs) {
            if(p[0] > cur) {
                cur = p[1];
                answer += 1;
            }
        }
        return answer;
    }
};
```

## Longest Substring with At Least K Repeating Characters

seems $O(n \log n)$ time complexity devide-and-conquer solution

``` cpp
class Solution {
    int helper(string &s, int begin, int end, int k) {
        if(begin >= end) return 0;
        int middle = (begin + end) / 2;
        unordered_map<char, int> cnt, mid;
        for(int i = begin; i < end; ++i) {
            char c = s[i];
            if(!mid.count(c) || abs(mid[c]-middle) > abs(i-middle)) mid[c] = i;
            cnt[c] += 1;
        }
        bool ok = true;
        int partitionPoint = -1;
        for(auto [c, count] : cnt) {
            if(count < k) {
                ok = false;
                if(abs(partitionPoint - middle) > abs(mid[c] - middle)) {
                    partitionPoint = mid[c];
                }
            }
        }
        if(ok) return end-begin;
        return max(helper(s, begin, partitionPoint, k), helper(s, partitionPoint+1, end, k));
    }
public:
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.size(), k);
    }
};
```

## Remove Palindromic Subsequences

nothing to say

``` cpp
class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.empty()) return 0;
        int len = s.size();
        for(int i = 0; 2*i < len; ++i) {
            if(s[i] != s[len-1-i]) return 2;
        }
        return 1;
    }
};
```

## Partition Equal Subset Sum

elegant digit dp

``` cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0, plus<int>());
        if((sum & 1) || nums.empty()) return false;
        bitset<20001> dp;
        dp.set(0);
        for(auto n : nums) {
            dp |= dp << n;
        }
        return dp[sum/2];
    }
};
```

## Smallest Integer Divisible by K

nothing to say

``` cpp
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K % 2 == 0 || K % 5 == 0) return -1;
        int cur = 0;
        for(int i = 1; i <= K; ++i) {
            cur = (cur * 10 + 1) % K;
            if(cur == 0) return i;
        }
        // actually won't go here
        return INT_MAX;
    }
};
```

# November LeetCoding Challenge 28

## Description

**Sliding Window Maximum**

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return *the max sliding window*.

**Example 1:**

```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

**Example 2:**

```
Input: nums = [1], k = 1
Output: [1]
```

**Example 3:**

```
Input: nums = [1,-1], k = 1
Output: [1,-1]
```

**Example 4:**

```
Input: nums = [9,11], k = 2
Output: [11]
```

**Example 5:**

```
Input: nums = [4,-2], k = 2
Output: [4]
```

**Constraints:**

- `1 <= nums.length <= 105`
- `-104 <= nums[i] <= 104`
- `1 <= k <= nums.length`

## Solution

monotonic queue

``` cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> monoQueue;
        int len = nums.size();
        for(int i = 0; i < k; ++i) {
            while(monoQueue.size() && monoQueue.back() < nums[i]) monoQueue.pop_back();
            monoQueue.push_back(nums[i]);
        }
        vector<int> answer{monoQueue.front()};
        for(int i = k; i < len; ++i) {
            while(monoQueue.size() && monoQueue.back() < nums[i]) monoQueue.pop_back();
            if(monoQueue.size() && monoQueue.front() == nums[i-k]) monoQueue.pop_front();
            monoQueue.push_back(nums[i]);
            answer.push_back(monoQueue.front());
        }
        return answer;
    }
};
```
