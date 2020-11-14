+++
title = "2020-11-14 Daily-Challenge"
path = "2020-11-14-Daily-Challenge"
date = 2020-11-14 20:59:21+08:00
updated = 2020-11-15 00:22:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I just finish today's leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3530/) with `cpp`.

<!-- more -->

# LeetCode Review

## Powerful Integers

``` cpp
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if(bound < 2) return vector<int>();
        unordered_set<int> answer;
        for(int a = 1; a < bound; a *= x) {
            for(int b = 1; a + b <= bound; b *= y) {
                answer.insert(a+b);
                if(y == 1) break;
            }
            if(x == 1) break;
        }
        return vector<int>{answer.begin(), answer.end()};
    }
};
```

## Maximum Difference Between Node and Ancestor

normal solution

``` cpp
class Solution {
    int answer = 0;
    void maxAncestorDiff(TreeNode* root, int minVal, int maxVal) {
        if(!root) return;
        minVal = min(root->val, minVal);
        maxVal = max(root->val, maxVal);
        answer = max(maxVal - minVal, answer);
        maxAncestorDiff(root->left, minVal, maxVal);
        maxAncestorDiff(root->right, minVal, maxVal);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        maxAncestorDiff(root, INT_MAX, INT_MIN);
        return answer;
    }
};
```

## Check If It Is a Good Array

``` cpp
class Solution {
    int gcd(int a, int b) {
        return b ? gcd(b, a%b) : a;
    }
public:
    bool isGoodArray(vector<int>& nums) {
        int current = nums[0];
        for(int i = 0; i < nums.size(); ++i) {
            current = gcd(current, nums[i]);
        }
        return current == 1;
    }
};
```

## Valid Square

not so elegant

``` cpp
class Solution {
    double distance(vector<int>& p1, vector<double>& p2) {
        return (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
    }
    int distance(vector<int>& p1, vector<int>& p2) {
        return (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
    }
    bool equal(double a, double b) {
        return abs(a-b) < 1e-4;
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<double> center = {(p1[0]+p2[0]+p3[0]+p4[0])/4.0, (p1[1]+p2[1]+p3[1]+p4[1])/4.0};
        
        double d1 = distance(p1, center);
        double d2 = distance(p2, center);
        double d3 = distance(p3, center);
        double d4 = distance(p4, center);
        
        int d5 = distance(p1, p2);
        int d6 = distance(p1, p3);
        int d7 = distance(p1, p4);
        
        if(d5 == 0 || d6 == 0 || d7 == 0) return false;
        
        if(equal(d1, d2) && equal(d2, d3) && equal(d3, d4)) {
            // is rectangle
            if(d5 == d7 || d5 == d6 || d6 == d7) return true;
        }
        return false;
    }
};
```

## Student Attendance Record I

``` cpp
class Solution {
public:
    bool checkRecord(string s) {
        int lCnt = 0, aCnt = 0;
        bool isL = false;
        for(auto c : s) {
            if(c == 'L') {
                lCnt += 1;
            } else {
                lCnt = 0;
            }
            if(lCnt > 2) return false;
            if(c == 'A') {
                aCnt += 1;
            }
            if(aCnt > 1) return false;
        }
        return true;
    }
};
```

## Plus One

``` cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int curVal;
        for(auto it = digits.rbegin(); carry && it != digits.rend(); ++it) {
            curVal = *it + carry;
            *it = curVal % 10;
            carry = curVal / 10;
        }
        if(carry) digits.insert(digits.begin(), 1, 1);
        return digits;
    }
};
```

## Flipping an Image

``` cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int len = A.size();
        for(auto &row : A) {
            for(int i = 0; i*2 <= len-1; ++i) {
                int tmp = row[i]^1;
                row[i] = row[len-1-i]^1;
                row[len-i-1] = tmp;
            }
        }
        return A;
    }
};
```

# November LeetCoding Challenge14

**Poor Pigs**

## Description

There are 1000 buckets, one and only one of them is poisonous, while the rest are filled with water. They all look identical. If a pig drinks the poison it will die within 15 minutes. What is the minimum amount of pigs you need to figure out which bucket is poisonous within one hour?

Answer this question, and write an algorithm for the general case.

**General case:**

If there are `n` buckets and a pig drinking poison will die within `m` minutes, how many pigs (`x`) you need to figure out the **poisonous** bucket within `p` minutes? There is exactly one bucket with poison.

**Note:**

1. A pig can be allowed to drink simultaneously on as many buckets as one would like, and the feeding takes no time.
2. After a pig has instantly finished drinking buckets, there has to be a **cool down time** of *m* minutes. During this time, only observation is allowed and no feedings at all.
3. Any given bucket can be sampled an infinite number of times (by an unlimited number of pigs).

## Solution

check Zhihu for more explanation

``` cpp
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int base = 1 + minutesToTest / minutesToDie;
        return ceil(log(buckets) / log(base));
    }
};
```
