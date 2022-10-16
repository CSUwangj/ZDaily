+++
title = "2021-11-09 Daily-Challenge"
path = "2021-11-09-Daily-Challenge"
date = 2021-11-09 19:01:35+08:00
updated = 2021-11-09 20:03:38+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 9

## Description

**Number of Valid Words for Each Puzzle**

With respect to a given `puzzle` string, a `word` is *valid* if both the following conditions are satisfied:

- `word` contains the first letter of `puzzle`.

- For each letter in

   

  ```
  word
  ```

  , that letter is in

   

  ```
  puzzle
  ```

  .

  - For example, if the puzzle is `"abcdefg"`, then valid words are `"faced"`, `"cabbage"`, and `"baggage"`, while
  - invalid words are `"beefed"` (does not include `'a'`) and `"based"` (includes `'s'` which is not in the puzzle).

Return *an array* `answer`*, where* `answer[i]` *is the number of words in the given word list* `words` *that is valid with respect to the puzzle* `puzzles[i]`.

 

**Example 1:**

```
Input: words = ["aaaa","asas","able","ability","actt","actor","access"], puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
Output: [1,1,3,2,4,0]
Explanation: 
1 valid word for "aboveyz" : "aaaa" 
1 valid word for "abrodyz" : "aaaa"
3 valid words for "abslute" : "aaaa", "asas", "able"
2 valid words for "absoryz" : "aaaa", "asas"
4 valid words for "actresz" : "aaaa", "asas", "actt", "access"
There are no valid words for "gaswxyz" cause none of the words in the list contains letter 'g'.
```

**Example 2:**

```
Input: words = ["apple","pleas","please"], puzzles = ["aelwxyz","aelpxyz","aelpsxy","saelpxy","xaelpsy"]
Output: [0,1,3,2,0]
```

 

**Constraints:**

- `1 <= words.length <= 10^5`
- `4 <= words[i].length <= 50`
- `1 <= puzzles.length <= 10^4`
- `puzzles[i].length == 7`
- `words[i]` and `puzzles[i]` consist of lowercase English letters.
- Each `puzzles[i] `does not contain repeated characters.

## Solution

``` cpp
class Solution {
  int bitmask(const string &s) {
    int mask = 0;
    for(auto c : s) {
      mask |= (1 << (c - 'a'));
    }
    return mask;
  }
public:
  vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    unordered_map<int, int> count;
    for(auto &word : words) {
      sort(word.begin(), word.end());
      word.resize(unique(word.begin(), word.end()) - word.begin());
      count[bitmask(word)] += 1;
    }

    vector<int> answer;
    answer.reserve(puzzles.size());

    for(auto &puzzle : puzzles) {
      int first = (1 << (puzzle.front() - 'a'));
      int result = count[first];

      int mask = bitmask(puzzle.substr(1));
      for(int submask = mask; submask; submask = (submask - 1) & mask) {
        result += count[submask | first];
      }
      answer.push_back(result);
    }

    return answer;
  }
};

// Accepted
// 10/10 cases passed (176 ms)
// Your runtime beats 81.43 % of cpp submissions
// Your memory usage beats 61.43 % of cpp submissions (47.3 MB)
```

``` cpp
struct TrieNode {
  int count = 0;
  TrieNode *child[26] = {};
};
void insert(TrieNode *root, const string &word) {
  TrieNode *cur = root;
  for(auto c : word) {
    c -= 'a';
    if(!cur->child[c]) {
      cur->child[c] = new TrieNode();
    }
    cur = cur->child[c];
  }
  cur->count += 1;
}
class Solution {
  int dfs(TrieNode *root, bool hasFirst, const string &puzzle/*, int level */) {
    int total = hasFirst ? root->count : 0;
    // cout << puzzle << level << ' ' << total << endl;
    for(auto c : puzzle) {
      int i = c - 'a';
      if(root->child[i]) {
        total += dfs(root->child[i], hasFirst || c == puzzle.front(), puzzle/*, level + 1 */);
      }
    }
    // cout << puzzle << level << ' ' << total << endl;
    return total;
  }
public:
  vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    TrieNode *root = new TrieNode();
    for(auto &word : words) {
      sort(word.begin(), word.end());
      word.erase(unique(word.begin(), word.end()), word.end());
      if(word.size() > 7) continue;
      insert(root, word);
    }

    vector<int> answer;
    answer.reserve(puzzles.size());
    for(const auto &puzzle : puzzles) {
      answer.push_back(dfs(root, false, puzzle/*, 0 */));
    }

    return answer;
  }
};

// Accepted
// 10/10 cases passed (208 ms)
// Your runtime beats 70.95 % of cpp submissions
// Your memory usage beats 30.95 % of cpp submissions (73.4 MB)
```
