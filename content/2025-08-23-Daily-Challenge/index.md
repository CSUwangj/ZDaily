+++
updated = 2025-08-23T21:20:26+02:00
title = "2025-08-23 Daily Challenge"
path = "2025-08-23-Daily-Challenge"
date = 2025-08-23T21:20:26+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [August LeetCoding Challenge](https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/) with `cpp`.

<!-- more -->

# August LeetCoding Challenge 23

## Description

**Find the Minimum Area to Cover All Ones II**

<p>You are given a 2D <strong>binary</strong> array <code>grid</code>. You need to find 3 <strong>non-overlapping</strong> rectangles having <strong>non-zero</strong> areas with horizontal and vertical sides such that all the 1&#39;s in <code>grid</code> lie inside these rectangles.</p>

<p>Return the <strong>minimum</strong> possible sum of the area of these rectangles.</p>

<p><strong>Note</strong> that the rectangles are allowed to touch.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[1,0,1],[1,1,1]]</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/05/14/example0rect21.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 280px; height: 198px;" /></p>

<ul>
	<li>The 1&#39;s at <code>(0, 0)</code> and <code>(1, 0)</code> are covered by a rectangle of area 2.</li>
	<li>The 1&#39;s at <code>(0, 2)</code> and <code>(1, 2)</code> are covered by a rectangle of area 2.</li>
	<li>The 1 at <code>(1, 1)</code> is covered by a rectangle of area 1.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[1,0,1,0],[0,1,0,1]]</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/05/14/example1rect2.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 356px; height: 198px;" /></p>

<ul>
	<li>The 1&#39;s at <code>(0, 0)</code> and <code>(0, 2)</code> are covered by a rectangle of area 3.</li>
	<li>The 1 at <code>(1, 1)</code> is covered by a rectangle of area 1.</li>
	<li>The 1 at <code>(1, 3)</code> is covered by a rectangle of area 1.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= grid.length, grid[i].length &lt;= 30</code></li>
	<li><code>grid[i][j]</code> is either 0 or 1.</li>
	<li>The input is generated such that there are at least three 1&#39;s in <code>grid</code>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  // Function to calculate the minimum area of rectangle enclosing all ones in a submatrix 
  int minimumArea(vector<vector<int>>& grid, int mminX, int mmaxX, int mminY, int mmaxY) {
    int minX = 40;
    int minY = 40;
    int maxX = -1;
    int maxY = -1;
    bool found = false;
    for(int i = mminX; i <= mmaxX; i++) {  
      for(int j = mminY; j <= mmaxY; j++){
        if(!grid[i][j]) continue;
        minX = min(minX, i);
        maxX = max(maxX, i);
        maxY = min(maxY, j);
        minY = max(minY, j);
        found = true;
      }
    }
    return found ? ((maxX - minX + 1) * (minY - maxY + 1)) : 0;
  }
  
  int minimumSum(vector<vector<int>>& grid) {
    int x = grid.size();
    int y = grid.front().size();
    int answer = INT_MAX;
    int one, two, three;

    /*
    -------------
    |  (1)  |
    |       |
    -------------
    | (2) | (3) |
    |   |   |
    -------------
    */
    for(int i = 0; i < x; i++){
      one = minimumArea(grid, 0, i, 0, y - 1);
      for(int j = 0; j < y; j++){
        two = minimumArea(grid, i + 1, x - 1, 0, j);
        three = minimumArea(grid, i + 1, x - 1, j+1, y-1);
        answer = min(answer, one + two + three);
      }
    }
    
    /*
    -------------
    |   | (2) |
    |   |   |
      (1) -------
    |   |   |
    |   | (3) |
    -------------
    */
    for(int j = 0; j < y; j++){
      one = minimumArea(grid, 0, x-1, 0, j);
      for(int i = 0; i < x; i++){
        two = minimumArea(grid, 0, i, j+1, y-1);
        three = minimumArea(grid, i + 1, x - 1, j+1, y-1);
        answer = min(answer, one + two + three);
      }
    }
    
    /*
    -------------
    |   |   |
    | (2) |   |
    ------- (1) |
    |   |   |
    | (3) |   |
    -------------
    */
    for(int j = y-1; j >= 0; j--){
      one = minimumArea(grid, 0, x-1, j+1, y-1);
      for(int i = 0; i < x; i++){
        two = minimumArea(grid, 0, i, 0, j);
        three = minimumArea(grid, i + 1, x - 1, 0, j);
        answer = min(answer, one + two + three);
      }
    }
        
        
    /*
    -------------
    | (2) | (3) |
    |   |   |
    ------------
    |       |
    |  (1)  |
    -------------
    */
    for(int i = x-1; i >= 0; i--){
      one = minimumArea(grid, i+1, x-1, 0, y - 1);
      for(int j = 0; j < y; j++){
        two = minimumArea(grid, 0, i, 0, j);
        three = minimumArea(grid, 0, i, j+1, y-1);
        answer = min(answer, one + two + three);
      }
    }
    
    /*
    -------------
    |  (1)  |
    -------------
    |  (2)  |
    -------------
    |  (3)  |
    -------------
    */
    for(int i = 0; i < x; i++){
      for(int j = i+1; j < x; j++){
        one = minimumArea(grid, 0, i, 0, y-1);
        two = minimumArea(grid, i+1, j, 0, y-1);
        three = minimumArea(grid, j+1, x-1, 0, y-1);
        answer = min(answer, one + two + three);
      }
    }
    
     /*
    -------------
    |   |   |   |
    |   |   |   |
    |(1)|(2)|(3)|
    |   |   |   |
    |   |   |   |
    -------------
    */    
    for(int i = 0; i < y; i++){
      for(int j = i + 1; j < y; j++){
        one = minimumArea(grid, 0, x - 1, 0, i);
        two = minimumArea(grid, 0, x - 1, i + 1, j);
        three = minimumArea(grid, 0, x - 1, j + 1, y - 1);
        answer = min(answer, one + two + three);
      }
    }
    
    return answer;
  }
};
```
