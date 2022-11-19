+++
updated = 2022-11-19T14:01:31+08:00
title = "2022-11-19 Daily Challenge"
path = "2022-11-19-Daily-Challenge"
date = 2022-11-19T14:01:31+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/erect-the-fence/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 19

## Description

**Erect the Fence**

<p>You are given an array <code>trees</code> where <code>trees[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> represents the location of a tree in the garden.</p>

<p>You are asked to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if <strong>all the trees are enclosed</strong>.</p>

<p>Return <em>the coordinates of trees that are exactly located on the fence perimeter</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/erect2-plane.jpg" style="width: 509px; height: 500px;" />
<pre>
<strong>Input:</strong> points = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
<strong>Output:</strong> [[1,1],[2,0],[3,3],[2,4],[4,2]]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/erect1-plane.jpg" style="width: 509px; height: 500px;" />
<pre>
<strong>Input:</strong> points = [[1,2],[2,2],[4,2]]
<strong>Output:</strong> [[4,2],[2,2],[1,2]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 3000</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 100</code></li>
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
struct Vector {
  int x;
  int y;

  Vector(int x = 0, int y = 0) : x(x), y(y) {}
  Vector(const vector<int> &v) : x(v[0]), y(v[1]) { }

  friend ostream& operator<<(ostream &os, const Vector &v) {
    os << '(' << v.x << ',' << v.y << ')';
    return os;
  }
  bool operator<(const Vector& v) const {
    return this->x < v.x || (this->x == v.x && this->y < v.y);
  }
  Vector operator+(const Vector& v) const {
    return Vector(this->x + v.x, this->y + v.y);
  }
  Vector operator-(const Vector& v) const {
    return Vector(this->x - v.x, this->y - v.y);
  }
};

int cross(const Vector& a, const Vector& b) {
  return a.x * b.y - b.x * a.y;
}
int dot(const Vector& a, const Vector& b) {
  return a.x * b.x + a.y * b.y;
}
class Solution {
public:
  vector<vector<int>> outerTrees(vector<vector<int>>& treesVector) {
    vector<Vector> trees;
    for(const auto &tree : treesVector) {
      trees.push_back(Vector(tree));
    }
    sort(trees.begin(), trees.end());
    int len = trees.size();
    int size = 1;
    vector<int> st{0};
    for(int i = 1; i < len; ++i) {
      while(size > 1 && cross(trees[st[size - 1]] - trees[st[size - 2]], trees[i] - trees[st[size - 1]]) < 0) {
        st.pop_back();
        size -= 1;
      }
      st.push_back(i);
      size += 1;
    }
    int tmp = size;
    for(int i = len - 2; i >= 0; --i) {
      while(size > tmp && cross(trees[st[size - 1]] - trees[st[size - 2]], trees[i] - trees[st[size - 1]]) < 0) {
        st.pop_back();
        size -= 1;
      }
      st.push_back(i);
      size += 1;
    }
    sort(st.begin(), st.end());
    st.resize(unique(st.begin(), st.end()) - st.begin());
    vector<vector<int>> answer;
    for(auto i : st) {
      answer.push_back({trees[i].x, trees[i].y});
    }
    return answer;
  }
};

// Accepted
// 88/88 cases passed (91 ms)
// Your runtime beats 72.8 % of cpp submissions
// Your memory usage beats 69.6 % of cpp submissions (20.7 MB)
```
