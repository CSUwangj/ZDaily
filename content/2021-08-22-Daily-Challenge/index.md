+++
title = "2021-08-22 Daily-Challenge"
path = "2021-08-22-Daily-Challenge"
date = 2021-08-22 20:00:03+08:00
updated = 2021-08-22 20:14:04+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [August LeetCoding Challenge](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3907/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 22

## Description

**Rectangle Area II**

We are given a list of (axis-aligned) `rectangles`. Each `rectangle[i] = [xi1, yi1, xi2, yi2] `, where `(xi1, yi1)` are the coordinates of the bottom-left corner, and `(xi2, yi2)` are the coordinates of the top-right corner of the `ith` rectangle.

Find the total area covered by all `rectangles` in the plane. Since the answer may be too large, return it **modulo** `109 + 7`.

 

**Example 1:**

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/06/rectangle_area_ii_pic.png)

```
Input: rectangles = [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
Output: 6
Explanation: As illustrated in the picture.
```

**Example 2:**

```
Input: rectangles = [[0,0,1000000000,1000000000]]
Output: 49
Explanation: The answer is 1018 modulo (109 + 7), which is (109)2 = (-7)2 = 49.
```

 

**Constraints:**

- `1 <= rectangles.length <= 200`
- `rectanges[i].length = 4`
- `0 <= rectangles[i][j] <= 10^9`
- The total area covered by all rectangles will never exceed `263 - 1` and thus will fit in a **64-bit** signed integer.

## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct Node {
  int l, r, y, v;
  bool operator<(const Node& a) const {
    return this->y < a.y;
  }
};
Node segTree[400];
int sum[1600];
int lazy[1600];
int mp[200];
int mappingLen;
int id(int x) {
  return lower_bound(mp, mp + mappingLen, x) - mp;
}
int query() {
  return sum[0];
}
void pull(int l, int r, int o) {
  // cout << "P " << mp[l] << ' ' << mp[r] << endl;
  if(lazy[o] > 0) sum[o] = mp[r + 1] - mp[l];
  else sum[o] = sum[o * 2 + 1] + sum[o * 2 + 2]; 
}
void update(int l, int r, int ql, int qr, int v, int o = 0) {
  if(ql <= l && r <= qr) {
    lazy[o] += v;
  } else {
    cout << l << ' '  << r << ' ' << ql << ' ' << qr << endl;
    int mid = (l + r) >> 1;
    if(ql <= mid) update(l, mid, ql, qr, v, o * 2 + 1);
    if(qr > mid) update(mid + 1, r, ql, qr, v, o * 2 + 2);
  }
  // cout << "#" << o << ' ' << lazy[o] << ' ';
  pull(l, r, o);
  // cout <<"#" << o << ' '<< sum[o] << endl;
}
const int MOD = 1e9 + 7;
class Solution {
  int n;
  long long prevY;
  void init(vector<vector<int>>& rectangles) {
    n = rectangles.size();
    for(int i = 0; i < n ; ++i) {
      segTree[i * 2].l = rectangles[i][0];
      segTree[i * 2].r = rectangles[i][2];
      segTree[i * 2].y = rectangles[i][1];
      segTree[i * 2].v = 1;
      segTree[i * 2 + 1].l = rectangles[i][0];
      segTree[i * 2 + 1].r = rectangles[i][2];
      segTree[i * 2 + 1].y = rectangles[i][3];
      segTree[i * 2 + 1].v = -1;
      mp[i * 2] = rectangles[i][0];
      mp[i * 2 + 1] = rectangles[i][2];
    }
    sort(segTree, segTree + n * 2);
    sort(mp, mp + n * 2);
    mappingLen = unique(mp, mp + n * 2) - mp;
    for(int i = 0; i < 2 * n; ++i) {
      segTree[i].l = id(segTree[i].l);
      segTree[i].r = id(segTree[i].r);
    }
    prevY = segTree[0].y;
  }
  int solve() {
    long long answer = 0;
    // cout << mappingLen << endl;
    for(int i = 0; i < n * 2; ++i) {
      // cout << sum[0] << ' ' << prevY << ' ' << segTree[i].y << endl;
      // cout << mp[segTree[i].l] << ' '<< mp[segTree[i].r] << ' ' << segTree[i].v <<endl;
      answer += query() * (segTree[i].y - prevY);
      update(0, mappingLen - 1, segTree[i].l, segTree[i].r - 1, segTree[i].v);
      prevY = segTree[i].y;
    }
    answer %= MOD;
    return answer;
  }
public:
  int rectangleArea(vector<vector<int>>& rectangles) {
    init(rectangles);
    return solve();
  }
};

// Accepted
// 78/78 cases passed (24 ms)
// Your runtime beats 23.46 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (8.3 MB)
```