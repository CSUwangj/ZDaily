+++
updated = 2022-06-19 18:14:00+08:00
title = "2022-06-19 Daily-Challenge"
path = "2022-06-19-Daily-Challenge"
date = 2022-06-19 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/search-suggestions-system/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 19

## Description

**Search Suggestions System**

DYou are given an array of strings `products` and a string `searchWord`.

Design a system that suggests at most three product names from `products` after each character of `searchWord` is typed. Suggested products should have common prefix with `searchWord`. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return *a list of lists of the suggested products after each character of* `searchWord` *is typed*.

 

**Example 1:**

```
Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
```

**Example 2:**

```
Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
```

**Example 3:**

```
Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
```

 

**Constraints:**

- `1 <= products.length <= 1000`
- `1 <= products[i].length <= 3000`
- `1 <= sum(products[i].length) <= 2 * 104`
- All the strings of `products` are **unique**.
- `products[i]` consists of lowercase English letters.
- `1 <= searchWord.length <= 1000`
- `searchWord` consists of lowercase English letters.

## Solution

``` cpp
auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    sort(products.begin(), products.end());
    vector<vector<string>> answer;
    auto begin = products.begin();
    auto end = products.end();
    for(int i = 0; i < searchWord.length(); ++i) {
      auto cmp = [=](string a, string b) {
        return a[i] < b[i];
      };
      auto newBegin = lower_bound(begin, end, searchWord, cmp);
      auto newEnd = upper_bound(begin, end, searchWord, cmp);
      begin = newBegin;
      end = newEnd;
      if(newEnd - newBegin > 3) newEnd = newBegin + 3;
      if(newEnd - newBegin <= 0) break;
      answer.push_back(vector<string>(newBegin, newEnd));
    }
    while(answer.size() < searchWord.length()) answer.push_back({});
    return answer;
  }
};

// Accepted
// 41/41 cases passed (80 ms)
// Your runtime beats 72.27 % of cpp submissions
// Your memory usage beats 64.07 % of cpp submissions (39.2 MB)
```
