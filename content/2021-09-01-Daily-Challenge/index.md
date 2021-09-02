+++
title = "2021-09-01 Daily-Challenge"
path = "2021-09-01-Daily-Challenge"
date = 2021-09-01 18:33:34+08:00
updated = 2021-09-01 19:02:53+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Minimum Area Rectangle II](https://leetcode.com/problems/minimum-area-rectangle-ii/description/) and leetcode's [September LeetCoding Challenge](https://leetcode.com/explore/featured/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3960/) with `cpp`.

<!-- more -->

# Minimum Area Rectangle II

## Description

<p>You are given an array of points in the <strong>X-Y</strong> plane <code>points</code> where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>.</p>

<p>Return <em>the minimum area of any rectangle formed from these points, with sides <strong>not necessarily parallel</strong> to the X and Y axes</em>. If there is not any such rectangle, return <code>0</code>.</p>

<p>Answers within <code>10<sup>-5</sup></code> of the actual answer will be accepted.</p>

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/12/21/1a.png)

```
Input: points = [[1,2],[2,1],[1,0],[0,1]]
Output: 2.00000
Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2018/12/22/2.png)

```
Input: points = [[0,1],[2,1],[1,1],[1,0],[2,0]]
Output: 1.00000
Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2018/12/22/3.png)

```
Input: points = [[0,3],[1,2],[3,1],[1,3],[2,1]]
Output: 0
Explanation: There is no possible rectangle to form from these points.
```

**Example 4:**

![img](https://assets.leetcode.com/uploads/2018/12/21/4c.png)

```
Input: points = [[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
Output: 2.00000
Explanation: The minimum area rectangle occurs at [2,1],[2,3],[3,3],[3,1], with an area of 2.
```

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 50</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 4 * 10<sup>4</sup></code></li>
	<li>All the given points are <strong>unique</strong>.</li>
</ul>


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
	double minAreaFreeRect(vector<vector<int>>& points) {
		set<vector<int>>num;
		for(auto &s : points) {
      num.insert(s);
    }

		double answer = DBL_MAX;
    int len = points.size();
		for(int i = 0; i < len - 2; ++i){
			for(int j = i + 1; j < len - 1; ++j){
				for(int k = j + 1; k < len; ++k){
					double slop_y1 = points[j][1] - points[i][1];
					double slop_x1 = points[j][0] - points[i][0];
					double slop_y2 = points[k][1] - points[i][1];
					double slop_x2 = points[k][0] - points[i][0];
          // cout << slop_y1 << " " << slop_y2 << " " << slop_x1 << " " << slop_x2 << endl;
					if(slop_y1 * slop_y2 + slop_x1 * slop_x2 != 0) continue;

					int lasty = slop_y1 + points[k][1];
					int lastx = slop_x1 + points[k][0];
          // cout << lasty << " " << lastx << endl;

					if(num.count({lastx, lasty})){                        
						answer = min(answer, sqrt(slop_y1 * slop_y1 + slop_x1 * slop_x1) * sqrt(slop_y2 * slop_y2 + slop_x2 * slop_x2));
					}
				}
			}
		}

		return answer == DBL_MAX ? 0 : answer;
	}
};

// Accepted
// 109/109 cases passed (32 ms)
// Your runtime beats 89.34 % of cpp submissions
// Your memory usage beats 71.31 % of cpp submissions (9.8 MB)
```

# September LeetCoding Challenge 1

## Description

**Array Nesting**

You are given an integer array `nums` of length `n` where `nums` is a permutation of the numbers in the range `[0, n - 1]`.

You should build a set `s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... }` subjected to the following rule:

- The first element in `s[k]` starts with the selection of the element `nums[k]` of `index = k`.
- The next element in `s[k]` should be `nums[nums[k]]`, and then `nums[nums[nums[k]]]`, and so on.
- We stop adding right before a duplicate element occurs in `s[k]`.

Return *the longest length of a set* `s[k]`.

 

**Example 1:**

```
Input: nums = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
nums[0] = 5, nums[1] = 4, nums[2] = 0, nums[3] = 3, nums[4] = 1, nums[5] = 6, nums[6] = 2.
One of the longest sets s[k]:
s[0] = {nums[0], nums[5], nums[6], nums[2]} = {5, 6, 2, 0}
```

**Example 2:**

```
Input: nums = [0,1,2]
Output: 1
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] < nums.length`
- All the values of `nums` are **unique**.


## Solution

``` cpp
auto speedup = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
class Solution {
public:
  int arrayNesting(vector<int>& nums) {
    int answer = 0;
    int len = nums.size();
    vector<bool> vis(len);
    for(int i = 0; i < len; ++i) {
      if(vis[i]) continue;
      int cur = i;
      int chain = 0;
      while(!vis[cur]) {
        chain += 1;
        vis[cur] = true;
        cur = nums[cur];
      }
      answer = max(answer, chain);
    }
    return answer;
  }
};

// Accepted
// 856/856 cases passed (12 ms)
// Your runtime beats 96.44 % of cpp submissions
// Your memory usage beats 37.89 % of cpp submissions (30.3 MB)
```
