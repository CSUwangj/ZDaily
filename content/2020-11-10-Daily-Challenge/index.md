+++
title = "2020-11-10 Daily-Challenge"
path = "2020-11-10-Daily-Challenge"
date = 2020-11-10 07:59:31+08:00
updated = 2020-11-10 18:40:50+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done *Number of Atoms* on [leetcode](https://leetcode.com/problems/number-of-atoms/) and leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/featured/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3526/) with `cpp`.

<!-- more -->

# Number of Atoms

## Description

Given a chemical `formula` (given as a string), return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.

Two formulas concatenated together to produce another formula. For example, H2O2He3Mg4 is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula. For example, (H2O2) and (H2O2)3 are formulas.

Given a `formula`, return *the count of all elements as a string in the following form*: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

**Example 1:**

```
Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.
```

**Example 2:**

```
Input: formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
```

**Example 3:**

```
Input: formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
```

**Example 4:**

```
Input: formula = "Be32"
Output: "Be32"
```

**Constraints:**

- `1 <= formula.length <= 1000`
- `formula` consists of English letters, digits, `'('`, and `')'`.
- `formula` is always valid.

## Solution

writing this solution make me feel excited

``` cpp
class Solution {
  string parseAtom(string &formula, int &position) {
    string atom = "";
    atom += formula[position];
    position += 1;
    while(position < formula.size() && islower(formula[position])) {
      atom += formula[position];
      position += 1;
    }
    return atom;
  }
  
  map<string, int> parseFormula(string &formula, int &position) {
    map<string, int> currentCount;
    while(position < formula.size() && formula[position] != ')') {
      if(isupper(formula[position])) {
        string atom = parseAtom(formula, position);
        int count = parseCount(formula, position);
        currentCount[atom] += count;
      } else if(formula[position] == '(') {
        position += 1;
        map<string, int> subCount = parseFormula(formula, position);
        int count = parseCount(formula, position);
        for(auto &[atom, acount] : subCount) {
          currentCount[atom] += acount * count;
        }
      }
    }
    if(position < formula.size()) position += 1;
    return currentCount;
  }
  
  int parseCount(string &formula, int &position) {
    if(position >= formula.size() || !isdigit(formula[position])) return 1;
    int count = 0;
    while(position < formula.size() && isdigit(formula[position])) {
      count *= 10;
      count += formula[position] - '0';
      position += 1;
    }
    return count;
  }
public:
  string countOfAtoms(string formula) {
    int position = 0;
    map<string, int> count = parseFormula(formula, position);

    string answer = "";
    for(auto &[atom, acount] : count) {
      answer += atom;
      if(acount != 1) answer += to_string(acount);
    }

    return answer;
  }
};
```

# November LeetCoding Challenge10

## Description

**Flipping an Image**

Given a binary matrix `A`, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed. For example, flipping `[1, 1, 0]` horizontally results in `[0, 1, 1]`.

To invert an image means that each `0` is replaced by `1`, and each `1` is replaced by `0`. For example, inverting `[0, 1, 1]` results in `[1, 0, 0]`.

**Example 1:**

```
Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
```

**Example 2:**

```
Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
```

**Notes:**

- `1 <= A.length = A[0].length <= 20`
- `0 <= A[i][j] <= 1`

## Solution

nothing to say

``` cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> answer;
        for(auto &row : A) {
            vector<int> newRow;
            for(auto it = row.rbegin(); it != row.rend(); ++it) {
                newRow.push_back(!(*it));
            }
            answer.push_back(newRow);
        }
        return answer;
    }
};
```
