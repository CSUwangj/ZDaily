+++
updated = 2022-08-17 18:14:00+08:00
title = "2022-08-17 Daily-Challenge"
path = "2022-08-17-Daily-Challenge"
date = 2022-08-17 18:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/unique-morse-code-words/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 17

## Description

**Unique Morse Code Words**

​	International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:

- `'a'` maps to `".-"`,
- `'b'` maps to `"-..."`,
- `'c'` maps to `"-.-."`, and so on.

For convenience, the full table for the `26` letters of the English alphabet is given below:

```
[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
```

Given an array of strings `words` where each word can be written as a concatenation of the Morse code of each letter.

- For example, `"cab"` can be written as `"-.-..--..."`, which is the concatenation of `"-.-."`, `".-"`, and `"-..."`. We will call such a concatenation the **transformation** of a word.

Return *the number of different **transformations** among all words we have*.

 

**Example 1:**

```
Input: words = ["gin","zen","gig","msg"]
Output: 2
Explanation: The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."
There are 2 different transformations: "--...-." and "--...--.".
```

**Example 2:**

```
Input: words = ["a"]
Output: 1
```

 

**Constraints:**

- `1 <= words.length <= 100`
- `1 <= words[i].length <= 12`
- `words[i]` consists of lowercase English letters.

## Solution

``` cpp
class Solution {
  vector<string> m{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
  int uniqueMorseRepresentations(vector<string>& words) {
    unordered_set<string> answer;
    for(auto &word : words) {
      string code = "";
      for(auto c : word) {
        code += m[c-'a'];
      }
      answer.insert(code);
    }
    return answer.size();
  }
};

// Accepted
// 82/82 cases passed (4 ms)
// Your runtime beats 71.25 % of cpp submissions
// Your memory usage beats 61.19 % of cpp submissions (8.5 MB)
```
