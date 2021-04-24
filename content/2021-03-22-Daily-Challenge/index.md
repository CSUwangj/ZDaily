+++
title = "2021-03-22 Daily-Challenge"
path = "2021-03-22-Daily-Challenge"
date = 2021-03-22 16:23:00+08:00
updated = 2021-03-19 17:33:24+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Water Bottles](https://leetcode.com/problems/water-bottles/) and leetcode's [March LeetCoding Challenge](https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3681/) with `cpp`.

<!-- more -->

# Water Bottles

## Description

Given `numBottles` full water bottles, you can exchange `numExchange` empty water bottles for one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Return the **maximum** number of water bottles you can drink.

 

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2020/07/01/sample_1_1875.png)**

```
Input: numBottles = 9, numExchange = 3
Output: 13
Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 9 + 3 + 1 = 13.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/07/01/sample_2_1875.png)

```
Input: numBottles = 15, numExchange = 4
Output: 19
Explanation: You can exchange 4 empty bottles to get 1 full water bottle. 
Number of water bottles you can drink: 15 + 3 + 1 = 19.
```

**Example 3:**

```
Input: numBottles = 5, numExchange = 5
Output: 6
```

**Example 4:**

```
Input: numBottles = 2, numExchange = 3
Output: 2
```

 

**Constraints:**

- `1 <= numBottles <= 100`
- `2 <= numExchange <= 100`

## Solution

``` cpp
class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int bottle = 0;
    int drink = 0;
    while(numBottles) {
      drink += numBottles;
      bottle = bottle + numBottles;
      numBottles = bottle / numExchange;
      bottle = bottle % numExchange;
    }
    return drink;
  }
};
```

# March LeetCoding Challenge22

## Description

**Vowel Spellchecker**

Given a `wordlist`, we want to implement a spellchecker that converts a query word into a correct word.

For a given `query` word, the spell checker handles two categories of spelling mistakes:

- Capitalization: If the query matches a word in the wordlist (

  case-insensitive

  ), then the query word is returned with the same case as the case in the wordlist.

  - Example: `wordlist = ["yellow"]`, `query = "YellOw"`: `correct = "yellow"`
  - Example: `wordlist = ["Yellow"]`, `query = "yellow"`: `correct = "Yellow"`
  - Example: `wordlist = ["yellow"]`, `query = "yellow"`: `correct = "yellow"`

- Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (

  case-insensitive

  ), then the query word is returned with the same case as the match in the wordlist.

  - Example: `wordlist = ["YellOw"]`, `query = "yollow"`: `correct = "YellOw"`
  - Example: `wordlist = ["YellOw"]`, `query = "yeellow"`: `correct = ""` (no match)
  - Example: `wordlist = ["YellOw"]`, `query = "yllw"`: `correct = ""` (no match)

In addition, the spell checker operates under the following precedence rules:

- When the query exactly matches a word in the wordlist (**case-sensitive**), you should return the same word back.
- When the query matches a word up to capitlization, you should return the first such match in the wordlist.
- When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
- If the query has no matches in the wordlist, you should return the empty string.

Given some `queries`, return a list of words `answer`, where `answer[i]` is the correct word for `query = queries[i]`.

 

**Example 1:**

```
Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
```

 

**Note:**

- `1 <= wordlist.length <= 5000`
- `1 <= queries.length <= 5000`
- `1 <= wordlist[i].length <= 7`
- `1 <= queries[i].length <= 7`
- All strings in `wordlist` and `queries` consist only of **english** letters.

## Solution

``` cpp
class Solution {
  string stringTolower(string word) {
    for(auto &c : word) c = tolower(c);
    return word;
  }
  
  string vowelUnify(string word) {
    word = stringTolower(word);
    for(auto &c : word) {
      switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
          c = '?';
      }
    }
    return word;
  }
public:
  vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    unordered_set<string> words(wordlist.begin(), wordlist.end());
    unordered_map<string, string> capitError;
    unordered_map<string, string> vowelError;
    for(auto word : wordlist) {
      string vowel = vowelUnify(word);
      if(!vowelError.count(vowel)) vowelError[vowel] = word;
      string lower = stringTolower(word);
      if(!capitError.count(lower)) capitError[lower] = word;
    }
    
    vector<string> answer;
    for(auto query : queries) {
      if(words.count(query)) {
        answer.push_back(query);
        continue;
      }
      string lower = stringTolower(query);
      if(capitError.count(lower)) {
        answer.push_back(capitError[lower]);
        continue;
      }
      string vowel = vowelUnify(query);
      if(vowelError.count(vowel)) {
        answer.push_back(vowelError[vowel]);
        continue;
      }
      answer.push_back("");
    }
    
    return answer;
  }
};
```
