+++
updated = 2022-08-18 18:14:00+08:00
title = "2022-08-18 Daily-Challenge"
path = "2022-08-18-Daily-Challenge"
date = 2022-08-18 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/reduce-array-size-to-the-half/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 18

## Description

**Reduce Array Size to The Half**

​	You are given an integer array `arr`. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return *the minimum size of the set so that **at least** half of the integers of the array are removed*.

 

**Example 1:**

```
Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.
```

**Example 2:**

```
Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.
```

 

**Constraints:**

- `2 <= arr.length <= 10^5`
- `arr.length` is even.
- `1 <= arr[i] <= 10^5`

## Solution

``` cpp
auto speedup = []() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> cnt;
    for(auto i : arr) cnt[i] += 1;
    vector<int> amount;
    for(auto [_, c] : cnt) {
      cout << _ << ' '<< c << endl;
      amount.push_back(c);
    }
    sort(amount.begin(), amount.end(), greater<int>());
    for(int i = 1; i < amount.size(); ++i) {
      amount[i] += amount[i-1];
    }
    int target = (arr.size() + 1) / 2;
    return lower_bound(amount.begin(), amount.end(), target) - amount.begin() + 1;
  }
};

// Accepted
// 33/33 cases passed (574 ms)
// Your runtime beats 10.13 % of cpp submissions
// Your memory usage beats 48.79 % of cpp submissions (78.4 MB)
```
