+++
title = "2021-03-02 Daily-Challenge"
path = "2021-03-02-Daily-Challenge"
date = 2021-03-02 18:03:31+08:00
updated = 2021-03-02 19:11:22+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Accounts Merge](https://leetcode.com/problems/accounts-merge/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/featured/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3658/) with `cpp`.

<!-- more -->

# Accounts Merge

## Description

Given a list `accounts`, each element `accounts[i]` is a list of strings, where the first element `accounts[i][0]` is a *name*, and the rest of the elements are *emails* representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails **in sorted order**. The accounts themselves can be returned in any order.

**Example 1:**

```
Input: 
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
Explanation: 
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
```



**Note:**

The length of `accounts` will be in the range `[1, 1000]`.

The length of `accounts[i]` will be in the range `[1, 10]`.

The length of `accounts[i][j]` will be in the range `[1, 30]`.

## Solution

string-based set union

``` cpp
class Solution {
    unordered_map<string, string> unionSet;
    unordered_map<string, string> name;
    unordered_map<string, set<string>> sets;
    
    string find(string x) {
        if(x != unionSet[x]) unionSet[x] = find(unionSet[x]);
        return unionSet[x];
    }
    
    void merge(string a, string b) {
        a = find(a);
        b = find(b);
        unionSet[a] = b;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int len = accounts.size();
        for(auto &account : accounts) {
            if(!unionSet.count(account[1])) {
                name[account[1]] = account[0];
                unionSet[account[1]] = account[1];
            }
            for(int i = 2; i < account.size(); ++i) {
                if(!unionSet.count(account[i])) unionSet[account[i]] = account[i];
                merge(account[i], account[1]);
            }
        }
        for(auto &[child, pa] : unionSet) {
            sets[find(child)].insert(child);
        }
        vector<vector<string>> answer;
        for(auto &[pa, children] : sets) {
            vector<string> tmp{name[pa]};
            for(auto child : children) tmp.push_back(child);
            answer.push_back(tmp);
        }
        return move(answer);
    }
};
```

# March LeetCoding Challenge2

**Set Mismatch**

## Description

You have a set of integers `s`, which originally contains all the numbers from `1` to `n`. Unfortunately, due to some error, one of the numbers in `s` got duplicated to another number in the set, which results in **repetition of one** number and **loss of another** number.

You are given an integer array `nums` representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return *them in the form of an array*.

 

**Example 1:**

```
Input: nums = [1,2,2,4]
Output: [2,3]
```

**Example 2:**

```
Input: nums = [1,1]
Output: [1,2]
```

 

**Constraints:**

- $2 \le nums.length \le 10^4$
- $1 \le nums[i] \le 10^4$

## Solution

``` cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len = nums.size();
        vector<bool> used(len);
        int loss = -1;
        int dup = -1;
        for(auto i : nums) {
            if(!used[i - 1]) used[i - 1] = true;
            else dup = i;
        }
        for(int i = 0; i < len; ++i) {
            if(!used[i]) loss = i + 1;
        }
        return vector<int>{dup, loss};
    }
};
```
