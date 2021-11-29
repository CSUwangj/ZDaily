+++
title = "2021-11-29 Daily-Challenge"
path = "2021-11-29-Daily-Challenge"
date = 2021-11-29 21:18:00+08:00
updated = 2021-11-29 21:19:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/accounts-merge/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 29

## Description

**Accounts Merge**

Given a list of `accounts` where each element `accounts[i]` is a list of strings, where the first element `accounts[i][0]` is a name, and the rest of the elements are **emails** representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely  belong to the same person if there is some common email to both  accounts. Note that even if two accounts have the same name, they may  belong to different people as people could have the same name. A person  can have any number of accounts initially, but all of their accounts  definitely have the same name.

After merging the accounts, return the accounts in the following  format: the first element of each account is the name, and the rest of  the elements are emails **in sorted order**. The accounts themselves can be returned in **any order**.

 

**Example 1:**

```
Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
```

**Example 2:**

```
Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
```

 

**Constraints:**

- `1 <= accounts.length <= 1000`
- `2 <= accounts[i].length <= 10`
- `1 <= accounts[i][j] <= 30`
- `accounts[i][0]` consists of English letters.
- `accounts[i][j] (for j > 0)` is a valid email.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  unordered_map<string, int> id;
  vector<string> id2string;
  unordered_map<int, string> name;
  
  vector<int> parent;
  
  int find(int x) {
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }
  
  void merge(int x, int y) {
    parent[find(y)] = find(x);
  }
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int count = 0;
    for(auto &account : accounts) {
      for(int i = 1; i < account.size(); ++i) {
        if(!id.count(account[i])) {
          id[account[i]] = count++;
          id2string.push_back(account[i]);
        }
      }
      name[id[account[1]]] = account[0];
    }
    parent.resize(count);
    for(int i = 0; i < count; ++i) parent[i] = i;
    for(auto &account : accounts) {
      for(int i = 2; i < account.size(); ++i) {
        merge(id[account[1]], id[account[i]]);
      }
    }
    vector<vector<string>> answer;
    unordered_map<int, vector<int>> tmp;
    for(int i = 0; i < count; ++i) {
      tmp[find(i)].push_back(i);
    }
    for(auto [root, mails] : tmp) {
      vector<string> account{name[root]};
      for(auto id : mails) account.push_back(id2string[id]);
      sort(account.begin() + 1, account.end());
      answer.push_back(account);
    }
    return move(answer);
  }
};

// Accepted
// 50/50 cases passed (72 ms)
// Your runtime beats 95.46 % of cpp submissions
// Your memory usage beats 75.75 % of cpp submissions (35.1 MB)
```
