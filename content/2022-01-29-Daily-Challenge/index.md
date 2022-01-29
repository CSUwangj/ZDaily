+++
title = "2022-01-29 Daily-Challenge"
path = "2022-01-29-Daily-Challenge"
date = 2022-01-29 12:11:00+08:00
updated = 2022-01-29 12:12:00+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/design-add-and-search-words-data-structure/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 29

## Description

**Largest Rectangle in Histogram**

Given an array of integers `heights` representing the histogram's bar height where the width of each bar is `1`, return *the area of the largest rectangle in the histogram*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg)

```
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/01/04/histogram-1.jpg)

```
Input: heights = [2,4]
Output: 4
```

 

**Constraints:**

- `1 <= heights.length <= 10^5`
- `0 <= heights[i] <= 10^4`

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    vector<int> st{-1};
    heights.push_back(0);
    int len = heights.size();
    int answer = 0;
    for(int i = 0; i < len; ++i) {
      while(st.back() != -1 && heights[i] < heights[st.back()]) {
        int index = st.back();
        st.pop_back();
        int h = heights[index];
        int w = i - st.back() - 1;
        answer = max(answer, h*w);
      }
      st.push_back(i);
    }
    return answer;
  }
};

// Accepted
// 96/96 cases passed (64 ms)
// Your runtime beats 99.7 % of cpp submissions
// Your memory usage beats 45.71 % of cpp submissions (64.8 MB)
```
