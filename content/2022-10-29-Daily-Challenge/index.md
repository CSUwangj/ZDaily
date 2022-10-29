+++
updated = 2022-10-29T12:21:29+08:00
title = "2022-10-29 Daily Challenge"
path = "2022-10-29-Daily-Challenge"
date = 2022-10-29T12:21:29+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/earliest-possible-day-of-full-bloom/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 29

## Description

**Earliest Possible Day of Full Bloom**

<p>You have <code>n</code> flower seeds. Every seed must be planted first before it can begin to grow, then bloom. Planting a seed takes time and so does the growth of a seed. You are given two <strong>0-indexed</strong> integer arrays <code>plantTime</code> and <code>growTime</code>, of length <code>n</code> each:</p>

<ul>
	<li><code>plantTime[i]</code> is the number of <strong>full days</strong> it takes you to <strong>plant</strong> the <code>i<sup>th</sup></code> seed. Every day, you can work on planting exactly one seed. You <strong>do not</strong> have to work on planting the same seed on consecutive days, but the planting of a seed is not complete <strong>until</strong> you have worked <code>plantTime[i]</code> days on planting it in total.</li>
	<li><code>growTime[i]</code> is the number of <strong>full days</strong> it takes the <code>i<sup>th</sup></code> seed to grow after being completely planted. <strong>After</strong> the last day of its growth, the flower <strong>blooms</strong> and stays bloomed forever.</li>
</ul>

<p>From the beginning of day <code>0</code>, you can plant the seeds in <strong>any</strong> order.</p>

<p>Return <em>the <strong>earliest</strong> possible day where <strong>all</strong> seeds are blooming</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/21/1.png" style="width: 453px; height: 149px;" />
<pre>
<strong>Input:</strong> plantTime = [1,4,3], growTime = [2,3,1]
<strong>Output:</strong> 9
<strong>Explanation:</strong> The grayed out pots represent planting days, colored pots represent growing days, and the flower represents the day it blooms.
One optimal way is:
On day 0, plant the 0<sup>th</sup> seed. The seed grows for 2 full days and blooms on day 3.
On days 1, 2, 3, and 4, plant the 1<sup>st</sup> seed. The seed grows for 3 full days and blooms on day 8.
On days 5, 6, and 7, plant the 2<sup>nd</sup> seed. The seed grows for 1 full day and blooms on day 9.
Thus, on day 9, all the seeds are blooming.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/21/2.png" style="width: 454px; height: 184px;" />
<pre>
<strong>Input:</strong> plantTime = [1,2,3,2], growTime = [2,1,2,1]
<strong>Output:</strong> 9
<strong>Explanation:</strong> The grayed out pots represent planting days, colored pots represent growing days, and the flower represents the day it blooms.
One optimal way is:
On day 1, plant the 0<sup>th</sup> seed. The seed grows for 2 full days and blooms on day 4.
On days 0 and 3, plant the 1<sup>st</sup> seed. The seed grows for 1 full day and blooms on day 5.
On days 2, 4, and 5, plant the 2<sup>nd</sup> seed. The seed grows for 2 full days and blooms on day 8.
On days 6 and 7, plant the 3<sup>rd</sup> seed. The seed grows for 1 full day and blooms on day 9.
Thus, on day 9, all the seeds are blooming.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> plantTime = [1], growTime = [1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> On day 0, plant the 0<sup>th</sup> seed. The seed grows for 1 full day and blooms on day 2.
Thus, on day 2, all the seeds are blooming.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == plantTime.length == growTime.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= plantTime[i], growTime[i] &lt;= 10<sup>4</sup></code></li>
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
  int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    vector<pair<int, int>> plant;
    for(int i = 0; i < plantTime.size(); ++i) {
      plant.push_back({growTime[i], plantTime[i]});
    }
    sort(plant.begin(), plant.end());
    int answer = 0;
    for(auto [growTime, plantTime] : plant) {
      answer = max(answer, growTime) + plantTime;
    }
    return answer;
  }
};

// Accepted
// 41/41 cases passed (479 ms)
// Your runtime beats 77.91 % of cpp submissions
// Your memory usage beats 62.85 % of cpp submissions (168.2 MB)
```
