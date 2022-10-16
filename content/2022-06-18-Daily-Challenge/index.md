+++
updated = 2022-06-18 18:14:00+08:00
title = "2022-06-18 Daily-Challenge"
path = "2022-06-18-Daily-Challenge"
date = 2022-06-18 18:12:00+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [June LeetCoding Challenge](https://leetcode.com/problems/prefix-and-suffix-search/) with `cpp`.

<!-- more -->

# June LeetCoding Challenge 18

## Description

**Prefix and Suffix Search**

Design a special dictionary with some words that searchs the words in it by a prefix and a suffix.

Implement the `WordFilter` class:

- `WordFilter(string[] words)` Initializes the object with the `words` in the dictionary.
- `f(string prefix, string suffix)` Returns *the index of the word in the dictionary,* which has the prefix `prefix` and the suffix `suffix`. If there is more than one valid index, return **the largest** of them. If there is no such word in the dictionary, return `-1`.

 

**Example 1:**

```
Input
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
Output
[null, 0]

Explanation
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = 'e".
```

 

**Constraints:**

- `1 <= words.length <= 15000`
- `1 <= words[i].length <= 10`
- `1 <= prefix.length, suffix.length <= 10`
- `words[i]`, `prefix` and `suffix` consist of lower-case English letters only.
- At most `15000` calls will be made to the function `f`.

## Solution

``` cpp
class WordFilter {
  map<string, string> idx;
  unordered_map<string, int> ans;
public:
    WordFilter(vector<string>& words) {
      int cnt = 0;
      for(auto &word : words) {
        ans[word] = cnt++;
        int len = word.length();
        for(int i = 1; i <= len; ++i) {
          idx[word.substr(len - i) + "?" + word] = word;
        }
      }
    }
    
    int f(string prefix, string suffix) {
      auto target = suffix + "?" + prefix;
      auto it = idx.lower_bound(target);
      int answer = -1;
      while(it != idx.end() && it->first.rfind(target, 0) == 0) {
        answer = max(answer, ans[it->second]);
        ++it;
      }
      return answer;
    }
};

// Accepted
// 13/13 cases passed (713 ms)
// Your runtime beats 52.99 % of cpp submissions
// Your memory usage beats 90.67 % of cpp submissions (108.8 MB)
```
