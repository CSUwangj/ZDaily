+++
title = "2021-07-20 Daily-Challenge"
path = "2021-07-20-Daily-Challenge"
date = 2021-07-20 19:53:59+08:00
updated = 2021-07-20 20:27:29+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Invalid Transactions](https://leetcode.com/problems/invalid-transactions/description/) and leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3819/) with `cpp`.

<!-- more -->

# Invalid Transactions

## Description

A transaction is possibly invalid if:

- the amount exceeds `$1000`, or;
- if it occurs within (and including) `60` minutes of another transaction with the **same name** in a **different city**.

You are given an array of strings `transaction` where `transactions[i]` consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.

Return a list of `transactions` that are possibly invalid. You may return the answer in **any order**.

 

**Example 1:**

```
Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
Output: ["alice,20,800,mtv","alice,50,100,beijing"]
Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.
```

**Example 2:**

```
Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
Output: ["alice,50,1200,mtv"]
```

**Example 3:**

```
Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
Output: ["bob,50,1200,mtv"]
```

 

**Constraints:**

- `transactions.length <= 1000`
- Each `transactions[i]` takes the form `"{name},{time},{amount},{city}"`
- Each `{name}` and `{city}` consist of lowercase English letters, and have lengths between `1` and `10`.
- Each `{time}` consist of digits, and represent an integer between `0` and `1000`.
- Each `{amount}` consist of digits, and represent an integer between `0` and `2000`.

## Solution
not elegant nor efficient

``` cpp
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
  bool operator<(const Transaction& another) const { return this->time < another.time; }
};

class Solution {
  unordered_map<string, vector<Transaction>> transactions;
public:
  vector<string> invalidTransactions(vector<string>& transactionStrings) {
    for(auto &tx : transactionStrings) {
      auto transaction = Transaction(tx);
      transactions[transaction.name].push_back(transaction);
    }
    vector<string> answer;
    for(auto &[name, transactions] : transactions) {
      int len = transactions.size();
      sort(transactions.begin(), transactions.end());
      vector<bool> invalid(len);
      for(int i = 0; i < len; ++i) {
        // cout << transactions[i].to_string() << endl;
        bool ok = true;
        for(int j = i - 1; j >= 0 && transactions[i].time - transactions[j].time <= 60; --j) {
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
    }
    return answer;
  }
};

// Accepted
// 36/36 cases passed (20 ms)
// Your runtime beats 87.55 % of cpp submissions
// Your memory usage beats 75.97 % of cpp submissions (13.3 MB)
```

# July LeetCoding Challenge20

## Description

**Shuffle an Array**

Given an integer array `nums`, design an algorithm to randomly shuffle the array. All permutations of the array should be **equally likely** as a result of the shuffling.

Implement the `Solution` class:

- `Solution(int[] nums)` Initializes the object with the integer array nums.
- `int[] reset()` Resets the array to its original configuration and returns it.
- `int[] shuffle()` Returns a random shuffling of the array.

 

**Example 1:**

```
Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result.
                       // Any permutation of [1,2,3] must be equally likely to be returned.
                       // Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]
```

 

**Constraints:**

- `1 <= nums.length <= 200`
- `-10^6 <= nums[i] <= 10^6`
- All the elements of `nums` are **unique**.
- At most `5 * 10^4` calls **in total** will be made to `reset` and `shuffle`.

## Solution

``` cpp
using random_param = uniform_int_distribution<int>::param_type;
class Solution {
  vector<int> arr;
  int len;
  random_device rd;
  mt19937 gen{rd()};
  uniform_int_distribution<int> distr;
public:
  Solution(vector<int>& nums): arr(nums) {
    len = nums.size();
  }
  
  /** Resets the array to its original configuration and return it. */
  vector<int> reset() {
    return arr;
  }
  
  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> result = arr;
    for(int i = len - 1; i ; --i) {
      distr.param(random_param(0, i));
      int idx = distr(gen);
      swap(result[idx], result[i]);
    }
    return result;
  }
};
```
