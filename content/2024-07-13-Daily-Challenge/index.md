+++
updated = 2024-07-13T20:01:46+08:00
title = "2024-07-13 Daily Challenge"
path = "2024-07-13-Daily-Challenge"
date = 2024-07-13T20:01:46+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [July LeetCoding Challenge](https://leetcode.com/problems/robot-collisions/) with `cpp`.

<!-- more -->

# July LeetCoding Challenge 13

## Description

**Robot Collisions**

<p>There are <code>n</code> <strong>1-indexed</strong> robots, each having a position on a line, health, and movement direction.</p>

<p>You are given <strong>0-indexed</strong> integer arrays <code>positions</code>, <code>healths</code>, and a string <code>directions</code> (<code>directions[i]</code> is either <strong>&#39;L&#39;</strong> for <strong>left</strong> or <strong>&#39;R&#39;</strong> for <strong>right</strong>). All integers in <code>positions</code> are <strong>unique</strong>.</p>

<p>All robots start moving on the line<strong> simultaneously</strong> at the <strong>same speed </strong>in their given directions. If two robots ever share the same position while moving, they will <strong>collide</strong>.</p>

<p>If two robots collide, the robot with <strong>lower health</strong> is <strong>removed</strong> from the line, and the health of the other robot <strong>decreases</strong> <strong>by one</strong>. The surviving robot continues in the <strong>same</strong> direction it was going. If both robots have the <strong>same</strong> health, they are both<strong> </strong>removed from the line.</p>

<p>Your task is to determine the <strong>health</strong> of the robots that survive the collisions, in the same <strong>order </strong>that the robots were given,<strong> </strong>i.e. final heath of robot 1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.</p>

<p>Return <em>an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur.</em></p>

<p><strong>Note:</strong> The positions may be unsorted.</p>

<div class="notranslate" style="all: initial;">&nbsp;</div>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img height="169" src="https://assets.leetcode.com/uploads/2023/05/15/image-20230516011718-12.png" width="808" /></p>

<pre>
<strong>Input:</strong> positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = &quot;RRRRR&quot;
<strong>Output:</strong> [2,17,9,15,10]
<strong>Explanation:</strong> No collision occurs in this example, since all robots are moving in the same direction. So, the health of the robots in order from the first robot is returned, [2, 17, 9, 15, 10].
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><img height="176" src="https://assets.leetcode.com/uploads/2023/05/15/image-20230516004433-7.png" width="717" /></p>

<pre>
<strong>Input:</strong> positions = [3,5,2,6], healths = [10,10,15,12], directions = &quot;RLRL&quot;
<strong>Output:</strong> [14]
<strong>Explanation:</strong> There are 2 collisions in this example. Firstly, robot 1 and robot 2 will collide, and since both have the same health, they will be removed from the line. Next, robot 3 and robot 4 will collide and since robot 4&#39;s health is smaller, it gets removed, and robot 3&#39;s health becomes 15 - 1 = 14. Only robot 3 remains, so we return [14].
</pre>

<p><strong class="example">Example 3:</strong></p>

<p><img height="172" src="https://assets.leetcode.com/uploads/2023/05/15/image-20230516005114-9.png" width="732" /></p>

<pre>
<strong>Input:</strong> positions = [1,2,5,6], healths = [10,10,11,11], directions = &quot;RLRL&quot;
<strong>Output:</strong> []
<strong>Explanation:</strong> Robot 1 and robot 2 will collide and since both have the same health, they are both removed. Robot 3 and 4 will collide and since both have the same health, they are both removed. So, we return an empty array, [].</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= positions.length == healths.length == directions.length == n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= positions[i], healths[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>directions[i] == &#39;L&#39;</code> or <code>directions[i] == &#39;R&#39;</code></li>
	<li>All values in <code>positions</code> are distinct</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int len = positions.size();
    vector<int> indice(len);
    iota(indice.begin(), indice.end(), 0);
    sort(indice.begin(), indice.end(), [&](int a, int b) {
      return positions[a] < positions[b];
    });
    vector<int> st;
    for(auto index : indice) {
      // cout << healths << ' ' << st << endl;
      if(directions[index] == 'R') {
        st.push_back(index);
        continue;
      }
      while(st.size() && healths[index] > healths[st.back()]) {
        healths[index] -= 1;
        healths[st.back()] = 0;
        st.pop_back();
      }
      if(st.size() && healths[index] <= healths[st.back()]) {
        if(healths[index] == healths[st.back()]){
          healths[st.back()] = 0;
          st.pop_back();
        } else {
          healths[st.back()] -= 1;
        }
        healths[index] = 0;
      }
    }
    healths.resize(remove_if(healths.begin(), healths.end(), [](int health) { return !health; }) - healths.begin());
    return healths;
  }
};
```
