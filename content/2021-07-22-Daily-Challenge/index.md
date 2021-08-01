+++
title = "2021-07-22 Daily-Challenge"
path = "2021-07-22-Daily-Challenge"
date = 2021-07-22 18:33:49+08:00
updated = 2021-07-22 19:04:52+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Design Browser History](https://leetcode.com/problems/design-browser-history/description/) and leetcode's [July LeetCoding Challenge](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3823/) with `cpp`.

<!-- more -->

# Design Browser History

## Description

You have a **browser** of one tab where you start on the `homepage` and you can visit another `url`, get back in the history number of `steps` or move forward in the history number of `steps`.

Implement the `BrowserHistory` class:

- `BrowserHistory(string homepage)` Initializes the object with the `homepage` of the browser.
- `void visit(string url)` Visits `url` from the current page. It clears up all the forward history.
- `string back(int steps)` Move `steps` back in history. If you can only return `x` steps in the history and `steps > x`, you will return only `x` steps. Return the current `url` after moving back in history **at most** `steps`.
- `string forward(int steps)` Move `steps` forward in history. If you can only forward `x` steps in the history and `steps > x`, you will forward only `x` steps. Return the current `url` after forwarding in history **at most** `steps`.

 

**Example:**

```
Input:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
Output:
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

Explanation:
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
```

 

**Constraints:**

- `1 <= homepage.length <= 20`
- `1 <= url.length <= 20`
- `1 <= steps <= 100`
- `homepage` and `url` consist of '.' or lower case English letters.
- At most `5000` calls will be made to `visit`, `back`, and `forward`.

## Solution

``` cpp
class BrowserHistory {
  string homepage;
  vector<string> history;
  int index = 1;
public:
  BrowserHistory(string _homepage): homepage(_homepage) {
    history.push_back(homepage);
  }
  
  void visit(string url) {
    while(history.size() > index) history.pop_back();
    history.push_back(url);
    index += 1;
  }
  
  string back(int steps) {
    if(index > steps) index = index - steps;
    else index = 1;
    return history[index - 1];
  }
  
  string forward(int steps) {
    if(index + steps > history.size()) index = history.size();
    else index += steps;
    return history[index - 1];
  }
};

// Accepted
// 71/71 cases passed (112 ms)
// Your runtime beats 94.89 % of cpp submissions
// Your memory usage beats 61.84 % of cpp submissions (57.6 MB)
```

# July LeetCoding Challenge 22

## Description

**Partition Array into Disjoint Intervals**

Given an array `nums`, partition it into two (contiguous) subarrays `left` and `right` so that:

- Every element in `left` is less than or equal to every element in `right`.
- `left` and `right` are non-empty.
- `left` has the smallest possible size.

Return the **length** of `left` after such a partitioning. It is guaranteed that such a partitioning exists.

 

**Example 1:**

```
Input: nums = [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
```

**Example 2:**

```
Input: nums = [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]
```

<p><strong>Note:</strong></p>

<ol>
	<li><code>2 &lt;= nums.length&nbsp;&lt;= 30000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li>It is guaranteed there is at least one way to partition <code>nums</code> as described.</li>
</ol>

<div>
<div>&nbsp;</div>
</div>

## Solution

``` cpp
int mmax[30000];
int mmin[30000];
class Solution {
public:
  int partitionDisjoint(vector<int>& nums) {
    int len = nums.size();
    mmax[0] = nums[0];
    mmin[len - 1] = nums[len - 1];
    for(int i = 1; i < len; ++i) {
      mmax[i] = max(mmax[i - 1], nums[i]);
      mmin[len - 1 - i] = min(mmin[len - i], nums[len - 1 - i]);
    }
    for(int i = 1; i < len; ++i) {
      if(mmax[i - 1] <= mmin[i]) return i;
    }
    return -1;
  }
};
```
