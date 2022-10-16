+++
title = "2020-11-24 Daily-Challenge"
path = "2020-11-24-Daily-Challenge"
date = 2020-11-24 18:12:13+08:00
updated = 2020-11-24 18:35:16+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Total Hamming Distance* on [leetcode](https://leetcode.com/problems/total-hamming-distance/) and leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3542/) with `cpp`.

<!-- more -->

# Total Hamming Distance

## Description

The [Hamming distance](https://en.wikipedia.org/wiki/Hamming_distance) between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

**Example:**

```
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
```

**Note:**

1. Elements of the given array are in the range of `0 `to `10^9`
2. Length of the array will not exceed `10^4`.

## Solution

I first came up with a $O(n^2)$ solution, then it failes due to time limit.

``` cpp
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> cache;
        int len = nums.size();
        int answer = 0;
        for(int i = 1; i < len; ++i) {
            if(cache.count(nums[i])) {
                answer += cache[nums[i]];
                continue;
            }
            int acc = 0;
            for(int j = 0; j < i; ++j) {
                acc += __builtin_popcount(nums[i]^nums[j]);
            }
            cache[nums[i]] = acc;
            answer += acc;
        }
        return answer;
    }
};
```

then I check discuss and known how to solve it...

``` cpp
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> count(32, 0);
        int len = nums.size();
        int answer = 0;
        for(int i = 0; i < len; ++i) {
            for(int b = 0; b < 32; ++b) {
                int has = !!(nums[i] & (1<<b));
                answer += count[b]*(!has) + (i-count[b])*has;
                count[b] += has;
            }
        }
        return answer;
    }
};
```

# November LeetCoding Challenge 24

## Description

**Basic Calculator II**

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only **non-negative** integers, `+`, `-`, `*`, `/` operators and empty spaces ``. The integer division should truncate toward zero.

**Example 1:**

```
Input: "3+2*2"
Output: 7
```

**Example 2:**

```
Input: " 3/2 "
Output: 1
```

**Example 3:**

```
Input: " 3+5 / 2 "
Output: 5
```

**Note:**

- You may assume that the given expression is always valid.
- **Do not** use the `eval` built-in library function.

## Solution

infix to postfix, then solve it.

``` cpp
class Solution {
    enum Type { op, num };
    map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
public:
    int calculate(string s) {
        stack<char> opStack;
        string currentNum = "";
        vector<pair<string, Type>> expression;
        for(auto c : s) {
            if(!isdigit(c) && currentNum != "") {
                expression.push_back(make_pair(currentNum, num));
                currentNum = "";
            }
            if(c == ' ') continue;
            if(isdigit(c)) {
                currentNum += c;
            } else {
                while(opStack.size() && priority[opStack.top()] >= priority[c]) {
                    expression.push_back(make_pair(string(1, opStack.top()), op));
                    opStack.pop();
                }
                opStack.push(c);
            }
        }
        if(currentNum != "") expression.push_back(make_pair(currentNum, num));
        while(opStack.size()) {
            expression.push_back(make_pair(string(1, opStack.top()), op));
            opStack.pop();
        }
        stack<int> st;
        for(auto &[token, type] : expression) {
            switch(type){
                case num: 
                    st.push(stoi(token)); 
                    break;
                case op: 
                    int op2 = st.top();
                    st.pop();
                    int op1 = st.top();
                    st.pop();
                    switch(token[0]){
                        case '+': st.push(op1+op2); break;
                        case '-': st.push(op1-op2); break;
                        case '*': st.push(op1*op2); break;
                        case '/': st.push(op1/op2); break;
                    }
            }
        }
        return st.top();
    }
};
```

use std::function is more elegant

``` cpp
class Solution {
    enum Type { op, num };
    map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    map<char, function<int(int, int)>> func = {
        {'+', [](int a, int b){return a+b;}},
        {'-', [](int a, int b){return a-b;}},
        {'*', [](int a, int b){return a*b;}},
        {'/', [](int a, int b){return a/b;}}
    };
public:
    int calculate(string s) {
        stack<char> opStack;
        string currentNum = "";
        vector<pair<string, Type>> expression;
        for(auto c : s) {
            if(!isdigit(c) && currentNum != "") {
                expression.push_back(make_pair(currentNum, num));
                currentNum = "";
            }
            if(c == ' ') continue;
            if(isdigit(c)) {
                currentNum += c;
            } else {
                while(opStack.size() && priority[opStack.top()] >= priority[c]) {
                    expression.push_back(make_pair(string(1, opStack.top()), op));
                    opStack.pop();
                }
                opStack.push(c);
            }
        }
        if(currentNum != "") expression.push_back(make_pair(currentNum, num));
        while(opStack.size()) {
            expression.push_back(make_pair(string(1, opStack.top()), op));
            opStack.pop();
        }
        stack<int> st;
        for(auto &[token, type] : expression) {
            switch(type){
                case num: 
                    st.push(stoi(token)); 
                    break;
                case op: 
                    int op2 = st.top();
                    st.pop();
                    int op1 = st.top();
                    st.pop();
                    st.push(func[token[0]](op1, op2));
            }
        }
        return st.top();
    }
};
```