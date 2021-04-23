+++
title = "2021-04-19 Daily-Challenge"
path = "2021-04-19-Daily-Challenge"
date = 2021-04-19 20:16:33+08:00
updated = 2021-04-19 22:44:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Combination Sum](https://leetcode.com/problems/combination-sum/), [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/), [Combination Sum III](https://leetcode.com/problems/combination-sum-iii/), [Longest Happy String](https://leetcode.com/problems/longest-happy-string/)  and leetcode's [April LeetCoding Challenge](https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3713/) with `cpp`.

<!-- more -->

# Longest Happy String

## Description

A string is called *happy* if it does not have any of the strings `'aaa'`, `'bbb'` or `'ccc'` as a substring.

Given three integers `a`, `b` and `c`, return **any** string `s`, which satisfies following conditions:

- `s` is *happy* and longest possible.
- `s` contains **at most** `a` occurrences of the letter `'a'`, **at most** `b` occurrences of the letter `'b'` and **at most** `c` occurrences of the letter `'c'`.
- `s `will only contain `'a'`, `'b'` and `'c'` letters.

If there is no such string `s` return the empty string `""`.

 

**Example 1:**

```
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
```

**Example 2:**

```
Input: a = 2, b = 2, c = 1
Output: "aabbc"
```

**Example 3:**

```
Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It's the only correct answer in this case.
```

 

**Constraints:**

- `0 <= a, b, c <= 100`
- `a + b + c > 0`

``` cpp
class Solution {
  void pushRest(vector<pair<int, char>> &container, string &result) {
    if(container[1].first) {
      result.push_back(container[1].second);
      container[1].first -= 1;
    } else {
      result.push_back(container[2].second);
      container[2].first -= 1;
    }
  }
  string enoughMost(vector<pair<int, char>> &container, int max, int rest) {
    string result;
    while(max && rest) {
      if(max > rest) {
        result.push_back(container[0].second);
        result.push_back(container[0].second);
        pushRest(container, result);
        max -= 2;
        rest -= 1;
      } else {
        result.push_back(container[0].second);
        pushRest(container, result);
        max -= 1;
        rest -= 1;
      }
    }
    for(int i = 0; i < min(max, 2); ++i) {
      result.push_back(container[0].second);
    }
    return result;
  }
  string enoughRest(vector<pair<int, char>> &container, int max, int rest) {
    string result;
    while(max && rest) {
      if(rest > max) {
        pushRest(container, result);
        pushRest(container, result);
        result.push_back(container[0].second);
        rest -= 2;
        max -= 1;
      } else {
        pushRest(container, result);
        result.push_back(container[0].second);
        max -= 1;
        rest -= 1;
      }
    }
    return result;
  }
public:
  string longestDiverseString(int a, int b, int c) {
    vector<pair<int, char>> container{{a, 'a'}, {b, 'b'}, {c, 'c'}};
    sort(container.begin(), container.end(), greater<pair<int, char>>());
    int sum = a + b + c;
    int max = container[0].first;
    int rest = sum - max;
    if(max >= rest) {
      return enoughMost(container, max, rest);
    }
    return enoughRest(container, max, rest);
  }
};

// max > 2 * rest + 2
// mmrmmrmmrmmrmmrmm...

// 2 * rest + 2 >= max >= rest
// mmrmmrmmrmrmrmrm...

// rest > max > second > third
// rrmrrmrrmrmrmrmr...
```

# Combination Sum

## Description

Given an array of **distinct** integers `candidates` and a target integer `target`, return *a list of all **unique combinations** of* `candidates` *where the chosen numbers sum to* `target`*.* You may return the combinations in **any order**.

The **same** number may be chosen from `candidates` an **unlimited number of times**. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is **guaranteed** that the number of unique combinations that sum up to `target` is less than `150` combinations for the given input.

 

**Example 1:**

```
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
```

**Example 2:**

```
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
```

**Example 3:**

```
Input: candidates = [2], target = 1
Output: []
```

**Example 4:**

```
Input: candidates = [1], target = 1
Output: [[1]]
```

**Example 5:**

```
Input: candidates = [1], target = 2
Output: [[1,1]]
```

 

**Constraints:**

- `1 <= candidates.length <= 30`
- `1 <= candidates[i] <= 200`
- All elements of `candidates` are **distinct**.
- `1 <= target <= 500`

## Solution

``` cpp
class Solution {
  void solve(
    vector<vector<int>> &answer,
    vector<int> &tmp,
    vector<int> &candidates,
    int index,
    int rest
  ) {
    if(!rest) {
      answer.push_back(tmp);
      return;
    }
    if(index == candidates.size()) return;
    int curSize = tmp.size();
    while(rest >= 0) {
      solve(answer, tmp, candidates, index + 1, rest);
      rest -= candidates[index];
      tmp.push_back(candidates[index]);
    }
    while(curSize < tmp.size()) tmp.pop_back();
  }
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> answer;
    vector<int> tmp;
    solve(answer, tmp, candidates, 0, target);
    return answer;
  }
};
```

# Combination Sum II

## Description

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.

Each number in `candidates` may only be used **once** in the combination.

**Note:** The solution set must not contain duplicate combinations.

 

**Example 1:**

```
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```

**Example 2:**

```
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
```

 

**Constraints:**

- `1 <= candidates.length <= 100`
- `1 <= candidates[i] <= 50`
- `1 <= target <= 30`

## Solution

``` cpp
class Solution {
  void solve(
    set<vector<int>> &answer,
    vector<int> &tmp,
    vector<int> &candidates,
    int index,
    int rest
  ) {
    if(!rest) {
      answer.insert(tmp);
      return;
    }
    if(index == candidates.size() || candidates[index] > rest) return;
    solve(answer, tmp, candidates, index + 1, rest);
    rest -= candidates[index];
    tmp.push_back(candidates[index]);
    solve(answer, tmp, candidates, index + 1, rest);
    tmp.pop_back();
  }
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    set<vector<int>> answer;
    sort(candidates.begin(), candidates.end());
    vector<int> tmp;
    solve(answer, tmp, candidates, 0, target);
    return vector<vector<int>>(answer.begin(), answer.end());
  }
};
```

# Combination Sum III

## Description

Find all valid combinations of `k` numbers that sum up to `n` such that the following conditions are true:

- Only numbers `1` through `9` are used.
- Each number is used **at most once**.

Return *a list of all possible valid combinations*. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

**Example 1:**

```
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
```

**Example 2:**

```
Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
```

**Example 3:**

```
Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations. [1,2,1] is not valid because 1 is used twice.
```

**Example 4:**

```
Input: k = 3, n = 2
Output: []
Explanation: There are no valid combinations.
```

**Example 5:**

```
Input: k = 9, n = 45
Output: [[1,2,3,4,5,6,7,8,9]]
Explanation:
1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45
There are no other valid combinations.
```

 

**Constraints:**

- `2 <= k <= 9`
- `1 <= n <= 60`

## Solution

``` cpp
class Solution {
  void solve(
    vector<vector<int>> &answer,
    vector<int> &tmp,
    int index,
    int rest,
    int k
  ) {
    if(rest == 0 && tmp.size() == k) {
      answer.push_back(tmp);
      return;
    }
    if(tmp.size() >= k || index > 9 || index > rest) return;
    solve(answer, tmp, index + 1, rest, k);
    rest -= index;
    tmp.push_back(index);
    solve(answer, tmp, index + 1, rest, k);
    tmp.pop_back();
  }
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> answer;
    vector<int> tmp;
    solve(answer, tmp, 1, n, k);
    return vector<vector<int>>(answer.begin(), answer.end());
  }
};
```

# April LeetCoding challenge19

## Description

**Combination Sum IV**

Given an array of **distinct** integers `nums` and a target integer `target`, return *the number of possible combinations that add up to* `target`.

The answer is **guaranteed** to fit in a **32-bit** integer.

 

**Example 1:**

```
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
```

**Example 2:**

```
Input: nums = [9], target = 3
Output: 0
```

 

**Constraints:**

- `1 <= nums.length <= 200`
- `1 <= nums[i] <= 1000`
- All the elements of `nums` are **unique**.
- `1 <= target <= 1000`

 

**Follow up:** What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?

## Solution

``` cpp
class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1);
    dp[0] = 1;
    for(int i = 1; i <= target; ++i) {
      for(auto num : nums) {
        if(num <= i && INT_MAX - dp[i] > dp[i - num]) dp[i] += dp[i - num];
      }
    }
    return dp[target];
  }
};
```
