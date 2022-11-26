+++
updated = 2022-11-26T10:31:44+08:00
title = "2022-11-26 Daily Challenge"
path = "2022-11-26-Daily-Challenge"
date = 2022-11-26T10:31:44+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/maximum-profit-in-job-scheduling/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 26

## Description

**Maximum Profit in Job Scheduling**

<p>We have <code>n</code> jobs, where every job is scheduled to be done from <code>startTime[i]</code> to <code>endTime[i]</code>, obtaining a profit of <code>profit[i]</code>.</p>

<p>You&#39;re given the <code>startTime</code>, <code>endTime</code> and <code>profit</code> arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.</p>

<p>If you choose a job that ends at time <code>X</code> you will be able to start another job that starts at time <code>X</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/10/10/sample1_1584.png" style="width: 380px; height: 154px;" /></strong></p>

<pre>
<strong>Input:</strong> startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
<strong>Output:</strong> 120
<strong>Explanation:</strong> The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/10/10/sample22_1584.png" style="width: 600px; height: 112px;" /> </strong></p>

<pre>
<strong>Input:</strong> startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
<strong>Output:</strong> 150
<strong>Explanation:</strong> The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
</pre>

<p><strong class="example">Example 3:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/10/10/sample3_1584.png" style="width: 400px; height: 112px;" /></strong></p>

<pre>
<strong>Input:</strong> startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
<strong>Output:</strong> 6
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= startTime.length == endTime.length == profit.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= startTime[i] &lt; endTime[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= profit[i] &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct Job {
  int start;
  int end;
  int profit;
  Job() {}
  Job(int start, int end, int profit): start(start), end(end), profit(profit) {}
  bool operator<(const Job& other) const { 
    return this->start < other.start;
  }
};
class Solution {
public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector<Job> jobs;
    int len = startTime.size();
    for(int i = 0; i < startTime.size(); i++) {
      jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
    }
    sort(jobs.begin(), jobs.end());
    vector<int> dp(len);
    for(int i = 0; i < len; ++i) {
      dp[i] = jobs[i].profit;
    }
    for(int i = 0; i < len; i++) {
      if(i) {
        dp[i] = max(dp[i], dp[i - 1] - jobs[i - 1].profit + jobs[i].profit);
      }
      int pos = lower_bound(jobs.begin() + i, jobs.end(), jobs[i].end, 
        [](const Job& j, int endTime) {
          return j.start < endTime;
        }) - jobs.begin();
      if(pos < len && dp[pos] < dp[i] + jobs[pos].profit) dp[pos] = dp[i] + jobs[pos].profit;
    }
    return *max_element(dp.begin(), dp.end());
  }
};

// Accepted
// 30/30 cases passed (83 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 83.93 % of cpp submissions (50 MB)
```
