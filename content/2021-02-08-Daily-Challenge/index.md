+++
title = "2021-02-08 Daily-Challenge"
path = "2021-02-08-Daily-Challenge"
date = 2021-02-08 18:00:59+08:00
updated = 2021-02-08 18:58:31+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Find and Replace Pattern](https://leetcode.com/problems/find-and-replace-pattern/) and leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3633/) with `cpp`.

<!-- more -->

# Find and Replace Pattern

## Description

You have a list of `words` and a `pattern`, and you want to know which words in `words` matches the pattern.

A word matches the pattern if there exists a permutation of letters `p` so that after replacing every letter `x` in the pattern with `p(x)`, we get the desired word.

(*Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.*)

Return a list of the words in `words` that match the given pattern. 

You may return the answer in any order.

 

**Example 1:**

```
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.
```

 

**Note:**

- `1 <= words.length <= 50`
- `1 <= pattern.length = words[i].length <= 20`

## Solution

instead of check if a word can be matched by pattern, we can perform strightforward permutation: replace characters with continuous letters.

check `repermute()` for more information

``` cpp
class Solution {
    string repermute(vector<int> &mp, string word) {
        fill(mp.begin(), mp.end(), 0);
        char letter = 'a';
        for(auto &c : word) {
            if(mp[c - 'a'] == 0) {
                mp[c - 'a'] = letter++;
            }
            c = mp[c - 'a'];
        }
        return word;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<int> mp(26);
        pattern = repermute(mp, pattern);
        
        int len = words.size();
        vector<string> answer;
        for(auto word : words) {
            if(word.length() != pattern.length()) continue;
            if(repermute(mp, word) == pattern) {
                answer.push_back(word);
            }
        }
        
        return answer;
    }
};
```

# February LeetCoding Challenge 8

## Description

**Peeking Iterator**

Given an Iterator class interface with methods: `next()` and `hasNext()`, design and implement a PeekingIterator that support the `peek()` operation -- it essentially peek() at the element that will be returned by the next call to next().

**Example:**

```
Assume that the iterator is initialized to the beginning of the list: [1,2,3].

Call next() gets you 1, the first element in the list.
Now you call peek() and it returns 2, the next element. Calling next() after that still return 2. 
You call next() the final time and it returns 3, the last element. 
Calling hasNext() after that should return false.
```

**Follow up**: How would you extend your design to be generic and work with all types, not just integer?

## Solution

this problem is kind of weird

``` cpp
class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {}

	int peek() {
        auto it = *this;
        return it.next();
	}
};
```

```
13 / 13 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 7.7 MB
```