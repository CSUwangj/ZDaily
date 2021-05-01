+++
title = "2021-05-01 Daily-Challenge"
path = "2021-05-01-Daily-Challenge"
date = 2021-05-01 12:37:50+08:00
updated = 2021-05-01 23:59:75+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3728/) with `cpp`.

<!-- more -->

# LeetCode Review

## Power of Four

too easy to review

## Word Pattern

too easy to review

# May LeetCoding Challenge1

## Description

**Prefix and Suffix Search**

Design a special dictionary which has some words and allows you to search the words in it by a prefix and a suffix.

Implement the `WordFilter` class:

- `WordFilter(string[] words)` Initializes the object with the `words` in the dictionary.
- `f(string prefix, string suffix)` Returns *the index of the word in the dictionary* which has the prefix `prefix` and the suffix `suffix`. If there is more than one valid index, return **the largest** of them. If there is no such word in the dictionary, return `-1`.

 

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

input description is vague, think about the situation: words are all begin with "a" and end with "a", there can be 15000 such words, with 15000 call with ("a", "a"), then my solution won't pass

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
```
