+++
title = "2020-10-04 Daily-Challenge"
path = "2020-10-04-Daily-Challenge"
date = 2020-10-04 00:37:44+08:00
updated = 2020-10-04 18:41:04+08:00
in_search_index = true

[taxonomies]
tags = ["Design", "Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3483/) with `cpp`.

<!-- more -->

# The non-Designer's Design Book review

my second answer on P40-41:

- [T] unified font of titles
- [T] unified font color of title
- [T] enlarged image of titles
- [F] same color of title and image
- [T] `Volume...` right align
- [T] 1em indent
- [T] first paragraph doesn't indent

reference answer adds one more difference:

- use mark and guidelines instead of period

my second answer on P42:

- [T] shorten the distance between bullets and items
- [T] change `6` in title to `six`
- [F] enlarge the image so it aligns with the text
- [F] left-align the title
- [T] increase the font size of the title

all right

my second answer on P45:

- top one
  - [T] unify alignment
  - [ ] remove logo beside title
  - [ ] don't use `-` for separation
- bottom one
  - [T] remove unnecessary `Horseback Riding` and `SUMMER ... RIDES`
  - [T] remove abundant `For more information`
  - [T] `Est. 2003` too large
  - [F] unify alignment

the answer to the top one seems to have some problems, so I leave it.

- avoid use two black rectangles, they make eyes jump between them
- add an upper case in URL

my second answer on P54:

- [T] color scheme of orange and blue
- [T] same font of the title
- [T] same serif font
- [T] separate lines
- [T] spacing between

all right but can be more detailed.

my second answer on P55:

- [ ] location of time information
- [ ] font of time information
- [ ] background rectangle
- [ ] overlay of shape
- [ ] style of figure
- [ ] spaceing of border
- [ ] color of figure
- [ ] color of text

this answer is...

- color of green text
- font of green text
- color of white text
- font and shadow of white text
- color of the border
- overlay of elements
- style of figure

my second answer on top of P56:

- [ ] dashed font and ellipse
- [ ] background of text
- [ ] font of the title and bottom text
- [ ] color of orange and blue

this answer is:

- two fonts
- delicate uppercase
- background of the text
- color of blue
- align body and title horizontally

# LeetCode Review

## Probability of a Two Boxes Having The Same Number of Distinct Balls

another DFS with more elegant code and slower speed, more space used.

``` cpp
class Solution {
  long long c[50][50];
  long long perms;
  int total = 0;
  void init() {
    for (int i = 1; i < 50; i++) {
      c[i][i] = 1;
      c[i][0] = 1;
      for (int j = 1; j < i; ++j) {
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
      }
    }
  }
public:
  void dfs(int color1, int color2, int balls1, int balls2, int index, long long ways, vector<int>& balls) {
    if(index == balls.size()) {
      if (color1 == color2 && balls1 == balls2) {
        perms += ways;
      }
      return;
    }
    for(int i = 0; i <= balls[index]; i++) {
      if(balls1 <= total/2 && balls2 <= total/2){
        dfs(color1+(i==0), color2+(i==balls[index]), balls1+i, balls2+balls[index]-i, index+1, ways*c[balls[index]][i], balls);
      }
    }
  }
  double getProbability(vector<int>& balls) {
    for(int i = 0; i < balls.size(); ++i) {
      total += balls[i];
    }
    init();
    dfs(0, 0, 0, 0, 0, 1, balls);
    return 1.0*perms/c[total][total/2];
  }
};
```

## Check If a Word Occurs As a Prefix of Any Word in a Sentence

use KMP get worse result XD

``` cpp
class Solution {
  vector<int> next;
  void build_next(string& s) {
    next.push_back(-1);
    int cur = 0;
    for(int i = 1; i < s.length(); ++i) {
      while(cur && s[i] != s[cur]) {
        cur = next[cur];
      }
      if(s[i] == s[cur]) {
        cur += 1;
      }
      next.push_back(cur);
    }
  }
public:
  int isPrefixOfWord(string sentence, string searchWord) {
    build_next(searchWord);
    int cnt = 0, cur = 0;
    for(int i = 0; i < sentence.length(); ++i) {
      if(sentence[i] == ' ') {
        cur = 0;
        cnt += 1;
        continue;
      }
      while(cur && sentence[i] != searchWord[cur]) {
        cur = next[cur];
      }
      if(sentence[i] == searchWord[cur]) {
        cur += 1;
      }
      if(cur == searchWord.length()) {
        if(i-cur < 0 || sentence[i-cur] == ' ') return cnt+1;
        else cur = 0;
      }
    }
    return -1;
  }
};
```

## As Far from Land as Possible

more elegant BFS

``` cpp
class Solution {
  int length;
  int move[4][2] = {
    {-1,0}, 
    {0, 1},
    {1, 0},
    {0,-1}
  };
  bool isValid(int first, int second) {
    return first >= 0 && second >= 0 && first < length && second < length;
  }
  int bfs(vector<vector<int>>& grid, queue<tuple<int, int, int>>& q) {
    int ans = 0;
    while(q.size()) {
      // this line is only available after cpp17
      auto [ x, y, cnt ] = q.front();
      q.pop();
      if(cnt > ans) ans = cnt;
      for(int i = 0; i < 4; ++i) {
        if(isValid(x+move[i][0], y+move[i][1]) && !grid[x+move[i][0]][y+move[i][1]]) {
          q.push(make_tuple(x+move[i][0], y+move[i][1], cnt+1));
          grid[x+move[i][0]][y+move[i][1]] = 1;
        }
      }
    }
    return ans;
  }
public:
  int maxDistance(vector<vector<int>>& grid) {
    queue<tuple<int, int, int>> q;
    length = grid.size();
    for(int i = 0; i < length; i++) {
      for(int j = 0; j < length; j++) {
        if(grid[i][j] == 1) {
          q.push(make_tuple(i, j, 0));
        }
      }
    }
    if (q.size() == length * length || q.empty()) {
      return -1;
    }
    return bfs(grid, q);
  }
};
```

## Reconstruct Original Digits from English

more elegant way

``` cpp

class Solution {
  int cnt[10];
public:
  string originalDigits(string s) {
    for(int i = 0; i < s.length(); ++i) {
      switch(s[i]){
        case 'z':
          cnt[0] += 1;
          break;
        case 'w':
          cnt[2] += 1;
          break;
        case 'x':
          cnt[6] += 1;
          break;
        case 'g':
          cnt[8] += 1;
          break;
        case 's':
          cnt[7] += 1;
          break;
        case 'v':
          cnt[5] += 1;
          break;
        case 'f':
          cnt[4] += 1;
          break;
        case 't':
          cnt[3] += 1;
          break;
        case 'o':
          cnt[1] += 1;
          break;
        case 'i':
          cnt[9] += 1;
          break;
      }
    }
    cnt[7] -= cnt[6];
    cnt[5] -= cnt[7];
    cnt[4] -= cnt[5];
    cnt[3] -= cnt[2] + cnt[8];
    cnt[1] -= cnt[0] + cnt[2] + cnt[4];
    cnt[9] -= cnt[6] + cnt[8] + cnt[5];
    stringstream ss;
    for(int i = 0; i < 10; ++i) {
      while(cnt[i]) {
        ss << i;
        cnt[i] -= 1;
      }
    }
    return ss.str();
  }
};
```

## Number of Recent Calls

use binary search to get worse result XD

``` cpp
class RecentCounter {
  vector<int> calls;
  int begin = 0;
public:
  int ping(int t) {
    calls.push_back(t);
    if(calls.size() == 1 || t-3000 <= calls[begin]) {
      return calls.size()-begin;
    }
    int end = calls.size();
    while(begin < end) {
      int mid = (begin + end) / 2;
      if(calls[mid] < t-3000) {
        begin = mid+1;
      } else {
        end = mid;
      }
    }
    begin = end;
    return calls.size()-begin;
  }
};
```

## Filter Restaurants by Vegan-Friendly, Price and Distance

finally a more efficient solution

``` cpp
class Solution {
public:
  vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
    vector<int> answer;
    for (int i = 0; i < restaurants.size(); ++i) {
      if (restaurants[i][2] >= veganFriendly && restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance) {
        answer.push_back(i);
      }
    }
    sort(answer.begin(), answer.end(), [&restaurants](int a, int b) {
      return restaurants[a][1] > restaurants[b][1] || (restaurants[a][1] == restaurants[b][1] && restaurants[a][0] > restaurants[b][0]);
    });
    for(int i = 0; i < answer.size(); ++i) {
      answer[i] = restaurants[answer[i]][0];
    }
    return answer;
  }
};
```

## Combination Sum

use DP to solve it, but writing in cpp is really a suffer so I give up.

``` javascript
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
const combinationSum = (candidates, target) = {
  let ans = [[[]]]
  for(let i = 0; i < candidates.length; i += 1) {
    for(let j = candidates[i]; j <= target; j += 1) {
      if(ans[j-candidates[i]] !== undefined && ans[j-candidates[i]].length) {
        for(let k = 0; k < ans[j-candidates[i]].length; k += 1) {
          let tmp = [...ans[j-candidates[i]][k]]
          tmp.push(candidates[i])
          if(ans[j] === undefined) ans[j] = []
          ans[j].push(tmp)
        }
      }
    }
  }
  return ans[target] || []
};
```

## Reshape the Matrix

nothing to say

``` cpp
class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    if(nums.size() * nums[0].size() != r * c) return nums;
    vector<vector<int>> ans;
    vector<int> tmp;
    for(int i = 0; i < r*c; ++i) {
      tmp.push_back(nums[i/nums[0].size()][i%nums[0].size()]);
      if(tmp.size() == c) {
        ans.push_back(tmp);
        tmp.clear();
      }
    }
    return ans;
  }
};
```

## K-diff Pairs in an Array

use map rewrite it

``` cpp

class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    map<int, int> m;
    for(int i = 0; i < nums.size(); ++i) {
      m[nums[i]] += 1;
    }
    int ans = 0;
    if(k == 0) {
      for(auto const& [key, value] : m) {
        if(value > 1) ans += 1;
      }
    } else {
      for(auto const& [key, value] : m) {
        if(m.count(key-k) && m[key-k]) ans += 1;
        if(m.count(key+k) && m[key+k]) ans += 1;
      }
      ans /= 2;
    }
    return ans;
  }
};
```

# October LeetCoding Challenge 4

## Description

**Remove Covered Intervals**

Given a list of `intervals`, remove all intervals that are covered by another interval in the list.

Interval `[a,b)` is covered by interval `[c,d)` if and only if `c <= a` and `b <= d`.

After doing so, return *the number of remaining intervals*.

**Example 1:**

```
Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
```

**Example 2:**

```
Input: intervals = [[1,4],[2,3]]
Output: 1
```

**Example 3:**

```
Input: intervals = [[0,10],[5,12]]
Output: 2
```

**Example 4:**

```
Input: intervals = [[3,10],[4,10],[5,11]]
Output: 2
```

**Example 5:**

```
Input: intervals = [[1,2],[1,4],[3,4]]
Output: 1
```

**Constraints:**

- `1 <= intervals.length <= 1000`
- `intervals[i].length == 2`
- `0 <= intervals[i][0] < intervals[i][1] <= 10^5`
- All the intervals are **unique**.

## Solution

I first wrote it in brute-forcing way.

``` cpp
class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int removeCount = 0;
    for(int i = 0; i < intervals.size(); ++i) {
      for(int j = 0; j < intervals.size(); ++j) {
        if(i != j && intervals[j][0] <= intervals[i][0] && intervals[j][1] >= intervals[i][1]) {
          removeCount += 1;
          break;
        }
      }
    }
    return intervals.size() - removeCount;
  }
};
```

and ask QT for better ways, so, rewrite it with binary indexed tree, and got a worse result XD

``` cpp
class Solution {
  vector<int> bit;
  int lowbit(int x) {
    return x&(-x);
  }
  int sum(int x) {
    int ans = bit[0];
    while(x) {
      ans += bit[x];
      x -= lowbit(x);
    }
    return ans;
  }
  void add(int pos, int val) {
    if (pos == 0) {
      bit[0] = val;
      pos = 1;
    }
    while(pos < bit.size()) {
      bit[pos] += val;
      pos += lowbit(pos);
    }
  }
public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[1] > b[1] || (a[1] == b[1] && a[0] < b[0]);
    });
    int removeCount = 0;
    bit = vector<int>(intervals[0][1]+1, 0);
    for(int i = 0; i < intervals.size(); ++i) {
      removeCount += !!sum(intervals[i][0]);
      // cout << intervals[i][0] << endl;
      add(intervals[i][0], 1);
    }
    return intervals.size() - removeCount;
  }
};
```