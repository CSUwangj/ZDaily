+++
title = "2021-07-24 Daily-Challenge"
path = "2021-07-24-Daily-Challenge"
date = 2021-07-24 15:23:23+08:00
updated = 2021-07-24 23:29:11+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3825/) with `cpp`.

<!-- more -->

# LeetCode Review

## Minimum Subsequence in Non-Increasing Order

too easy to review

## Design Browser History

too easy to review

## Bulb Switcher

too easy to review

## Invalid Transactions

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct Transaction {
  int amount;
  int time;
  string city;
  string name;
  Transaction(int _time = 0, int _amount = 0, string _city = "") : amount(_amount), time(_time), city(_city) {}
  Transaction(string trans) {
    int len = trans.length();
    int pos = 0;
    while(trans[pos] != ',') pos += 1;
    name = trans.substr(0, pos);
    time = 0;
    pos += 1;
    while(trans[pos] != ',') {
      time *= 10;
      time += trans[pos] - '0';
      pos += 1;
    }
    amount = 0;
    pos += 1;
    while(trans[pos] != ',') {
      amount *= 10;
      amount += trans[pos] - '0';
      pos += 1;
    }
    pos += 1;
    city = trans.substr(pos);
  }
  string to_string() {
    return name + "," + ::to_string(time) + "," + ::to_string(amount) + "," + city;
  }
  bool operator<(const Transaction& another) const { 
    return this->name < another.name || (this->name == another.name && this->time < another.time) ; 
  }
};

class Solution {
public:
  vector<string> invalidTransactions(vector<string>& transactionStrings) {
    int len = transactionStrings.size();
    vector<Transaction> transactions;
    for(auto &txString : transactionStrings) {
      transactions.push_back(Transaction(txString));
    }
    vector<bool> invalid(len);
    sort(transactions.begin(), transactions.end());
    vector<string> answer;
    for(int i = 0; i < len; ++i) {
      // cout << transactions[i].to_string() << endl;
      bool ok = true;
      for(int j = i - 1; j >= 0 ; --j) {
        if(transactions[j].name != transactions[i].name) break;
        if(transactions[i].time - transactions[j].time > 60) break;
        if(transactions[i].city != transactions[j].city) {
          invalid[j] = true;
          ok = false;
        }
      }
      if(!ok || transactions[i].amount > 1000) invalid[i] = true;
    }
    for(int i = 0; i < len; ++i) {
      if(invalid[i]) answer.push_back(transactions[i].to_string());
    }
    return answer;
  }
};


// Accepted
// 36/36 cases passed (22 ms)
// Your runtime beats 76.92 % of cpp submissions
// Your memory usage beats 83.37 % of cpp submissions (12.9 MB)`
```

## Rank Transform of an Array

too easy to review

## Shuffle an Array

too easy to review

## Lowest Common Ancestor of a Binary Search Tree

too easy to review

## Push Dominoes

too easy to review

## Partition Array into Disjoint Intervals

``` cpp
class Solution {
public:
  int partitionDisjoint(vector<int>& nums) {
    int mmax = nums[0];
    int maxSoFar = nums[0];
    int index = 0;
    for(int i = 0; i < nums.size(); ++i) {
      if(maxSoFar > nums[i]) {
        index = i;
        maxSoFar = mmax;
      } else {
        mmax = max(mmax, nums[i]);
      }
    }
    return index + 1;
  }
};
```

## Binary Tree Pruning

too easy to review

# July LeetCoding Challenge24

## Description

**Word Ladder II**

A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

- Every adjacent pair of words differs by a single letter.
- Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
- `sk == endWord`

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return *all the **shortest transformation sequences** from* `beginWord` *to* `endWord`*, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words* `[beginWord, s1, s2, ..., sk]`.

 

**Example 1:**

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
```

**Example 2:**

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```

 

**Constraints:**

- `1 <= beginWord.length <= 5`
- `endWord.length == beginWord.length`
- `1 <= wordList.length <= 1000`
- `wordList[i].length == beginWord.length`
- `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.
- `beginWord != endWord`
- All the words in `wordList` are **unique**.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  unordered_map<string, vector<string>> neighbor;
  unordered_set<string> vis;
  unordered_map<string, unordered_map<int, vector<vector<string>>>> cache;
  vector<vector<string>> transform(string beginWord, string endWord, int rest) {
    if(rest == 2) {
      return {{endWord, beginWord}};
    }
    if(cache[beginWord].count(rest)) return cache[beginWord][rest];
    vector<vector<string>> answer;
    for(auto &nxt : neighbor[beginWord]) {
      if(diff(nxt, endWord) > rest - 2 || vis.count(nxt)) continue;
      vis.insert(nxt);
      for(auto &result : transform(nxt, endWord, rest - 1)) {
        result.push_back(beginWord);
        answer.emplace_back(result);
      }
      vis.erase(nxt);
    }
    cache[beginWord][rest] = answer;
    return answer;
  }
  int diff(const string &a, const string &b) {
    int cnt = 0;
    for(int i = 0; i < a.length(); ++i) {
      cnt += a[i] != b[i];
    }
    return cnt;
  }
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    int len = wordList.size();
    if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return {};
    // cout << "###########" << endl;
    for(auto &word : wordList) {
      if(diff(beginWord, word) == 1) neighbor[beginWord].push_back(word);
    }
    for(int i = 0; i < len - 1; ++i) {
      if(wordList[i] == beginWord) continue;
      for(int j = i + 1; j < len; ++j) {
        if(wordList[j] != beginWord && diff(wordList[i], wordList[j]) == 1) {
          neighbor[wordList[i]].push_back(wordList[j]);
          neighbor[wordList[j]].push_back(wordList[i]);
        }
      }
    }
    // for(auto [cur, n] : neighbor) {
    //   cout << cur << ' ' << n << endl;
    // }
    queue<string> q;
    vis.insert(beginWord);
    q.push(beginWord);
    int step = 0;
    int round = 0;
    for(int round = 1; !step && q.size(); ++round) {
      int sz = q.size();
      for(int i = 0; i < sz; ++i) {
        auto cur = q.front();
        q.pop();
        if(cur == endWord) {
          step = round;
          break;
        }
        for(auto nxt : neighbor[cur]) {
          if(vis.count(nxt)) continue;
          vis.insert(nxt);
          q.push(nxt);
        }
      }
    }
    // cout << step << endl;
    if(!step) return {};
    vis.clear();
    vis.insert(beginWord);
    auto answer = transform(beginWord, endWord, step);
    for(auto &result : answer) {
      reverse(result.begin(), result.end());
    }
    return answer;
  }
};

// Accepted
// 32/32 cases passed (36 ms)
// Your runtime beats 22.93 % of cpp submissions
// Your memory usage beats 18.07 % of cpp submissions (13.5 MB)
```
