+++
updated = 2025-12-19T21:51:58+01:00
title = "2025-12-19 Daily Challenge"
path = "2025-12-19-Daily-Challenge"
date = 2025-12-19T21:51:58+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/find-all-people-with-secret/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 19

## Description

**Find All People With Secret**

<p>You are given an integer <code>n</code> indicating there are <code>n</code> people numbered from <code>0</code> to <code>n - 1</code>. You are also given a <strong>0-indexed</strong> 2D integer array <code>meetings</code> where <code>meetings[i] = [x<sub>i</sub>, y<sub>i</sub>, time<sub>i</sub>]</code> indicates that person <code>x<sub>i</sub></code> and person <code>y<sub>i</sub></code> have a meeting at <code>time<sub>i</sub></code>. A person may attend <strong>multiple meetings</strong> at the same time. Finally, you are given an integer <code>firstPerson</code>.</p>

<p>Person <code>0</code> has a <strong>secret</strong> and initially shares the secret with a person <code>firstPerson</code> at time <code>0</code>. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person <code>x<sub>i</sub></code> has the secret at <code>time<sub>i</sub></code>, then they will share the secret with person <code>y<sub>i</sub></code>, and vice versa.</p>

<p>The secrets are shared <strong>instantaneously</strong>. That is, a person may receive the secret and share it with people in other meetings within the same time frame.</p>

<p>Return <em>a list of all the people that have the secret after all the meetings have taken place. </em>You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
<strong>Output:</strong> [0,1,2,3,5]
<strong>Explanation:
</strong>At time 0, person 0 shares the secret with person 1.
At time 5, person 1 shares the secret with person 2.
At time 8, person 2 shares the secret with person 3.
At time 10, person 1 shares the secret with person 5.​​​​
Thus, people 0, 1, 2, 3, and 5 know the secret after all the meetings.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3
<strong>Output:</strong> [0,1,3]
<strong>Explanation:</strong>
At time 0, person 0 shares the secret with person 3.
At time 2, neither person 1 nor person 2 know the secret.
At time 3, person 3 shares the secret with person 0 and person 1.
Thus, people 0, 1, and 3 know the secret after all the meetings.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
<strong>Output:</strong> [0,1,2,3,4]
<strong>Explanation:</strong>
At time 0, person 0 shares the secret with person 1.
At time 1, person 1 shares the secret with person 2, and person 2 shares the secret with person 3.
Note that person 2 can share the secret at the same time as receiving it.
At time 2, person 3 shares the secret with person 4.
Thus, people 0, 1, 2, 3, and 4 know the secret after all the meetings.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= meetings.length &lt;= 10<sup>5</sup></code></li>
	<li><code>meetings[i].length == 3</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i </sub>&lt;= n - 1</code></li>
	<li><code>x<sub>i</sub> != y<sub>i</sub></code></li>
	<li><code>1 &lt;= time<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= firstPerson &lt;= n - 1</code></li>
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
  using pi = pair<int, int>;
public:
  vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    map<int, vector<pi>> simultaneousMeeting;
    for(const auto &meeting : meetings) {
      simultaneousMeeting[meeting[2]].push_back({meeting[0], meeting[1]});
    }

    set<int> answerSet{0, firstPerson};
    for(const auto &[_time, meetings] : simultaneousMeeting) {
      if(meetings.size() == 1) {
        if(answerSet.count(meetings[0].first) || answerSet.count(meetings[0].second)) {
          answerSet.insert(meetings[0].first);
          answerSet.insert(meetings[0].second);
        }
        continue;
      }
      map<int, vector<int>> graph;
      set<int> peopleKnown;

      for(const auto &[x, y] : meetings) {
        graph[x].push_back(y);
        graph[y].push_back(x);

        if(answerSet.count(x)) peopleKnown.insert(x);
        if(answerSet.count(y)) peopleKnown.insert(y);
      }
      queue<int> q;
      for(auto people : peopleKnown) q.push(people); 
      
      while(q.size()) {
        auto current = q.front();
        q.pop();
        for(auto next : graph[current]) {
          if(answerSet.count(next)) continue;
          answerSet.insert(next);
          q.push(next);
        }
      }
    }
    return vector<int>(answerSet.begin(), answerSet.end());
  }
};

// Accepted
// 57/57 cases passed (523 ms)
// Your runtime beats 24.46 % of cpp submissions
// Your memory usage beats 19.3 % of cpp submissions (368.1 MB)
```
