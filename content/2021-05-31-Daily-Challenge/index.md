+++
title = "2021-05-31 Daily-Challenge"
path = "2021-05-31-Daily-Challenge"
date = 2021-05-31 15:07:46+08:00
updated = 2021-05-31 23:41:05+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Rectangle Area II](https://leetcode.com/problems/rectangle-area-ii/description/) and leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/602/week-5-may-29th-may-31st/3761/) with `cpp`.

<!-- more -->

# Rectangle Area II

## Description

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
- `0 <= rectangles[i][j] <= 109`
- The total area covered by all rectangles will never exceed `263 - 1` and thus will fit in a **64-bit** signed integer.

## Solution

sweeping line + segment tree, I need review it.

``` cpp
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
    // cout << l << ' '  << r << ' ' << ql << ' ' << qr << endl;
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
// 78/78 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 99.37 % of cpp submissions (8.4 MB)
```

# May LeetCoding Challenge 31

## Description

**Search Suggestions System**

Given an array of strings `products` and a string `searchWord`. We want to design a system that suggests at most three product names from `products` after each character of `searchWord` is typed. Suggested products should have common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return *list of lists* of the suggested `products` after each character of `searchWord` is typed. 

 

**Example 1:**

```
Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
```

**Example 2:**

```
Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
```

**Example 3:**

```
Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
```

**Example 4:**

```
Input: products = ["havana"], searchWord = "tatiana"
Output: [[],[],[],[],[],[],[]]
```

 

**Constraints:**

- `1 <= products.length <= 1000`
- There are no repeated elements in `products`.
- `1 <= Σ products[i].length <= 2 * 10^4`
- All characters of `products[i]` are lower-case English letters.
- `1 <= searchWord.length <= 1000`
- All characters of `searchWord` are lower-case English letters.

## Solution

already done before

``` cpp
auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    sort(products.begin(), products.end());
    vector<vector<string>> answer;
    auto begin = products.begin();
    auto end = products.end();
    for(int i = 0; i < searchWord.length(); ++i) {
      auto cmp = [=](string a, string b) {
        return a[i] < b[i];
      };
      auto newBegin = lower_bound(begin, end, searchWord, cmp);
      auto newEnd = upper_bound(begin, end, searchWord, cmp);
      begin = newBegin;
      end = newEnd;
      if(newEnd - newBegin > 3) newEnd = newBegin + 3;
      if(newEnd - newBegin <= 0) break;
      answer.push_back(vector<string>(newBegin, newEnd));
    }
    while(answer.size() < searchWord.length()) answer.push_back({});
    return answer;
  }
};
```
