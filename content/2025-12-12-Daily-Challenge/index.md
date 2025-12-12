+++
updated = 2025-12-12T10:08:47+01:00
title = "2025-12-12 Daily Challenge"
path = "2025-12-12-Daily-Challenge"
date = 2025-12-12T10:08:47+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [December LeetCoding Challenge](https://leetcode.com/problems/count-mentions-per-user/) with `cpp`.

<!-- more -->

# December LeetCoding Challenge 12

## Description

**Count Mentions Per User**

<p>You are given an integer <code>numberOfUsers</code> representing the total number of users and an array <code>events</code> of size <code>n x 3</code>.</p>

<p>Each <code inline="">events[i]</code> can be either of the following two types:</p>

<ol>
	<li><strong>Message Event:</strong> <code>[&quot;MESSAGE&quot;, &quot;timestamp<sub>i</sub>&quot;, &quot;mentions_string<sub>i</sub>&quot;]</code>

	<ul>
		<li>This event indicates that a set of users was mentioned in a message at <code>timestamp<sub>i</sub></code>.</li>
		<li>The <code>mentions_string<sub>i</sub></code> string can contain one of the following tokens:
		<ul>
			<li><code>id&lt;number&gt;</code>: where <code>&lt;number&gt;</code> is an integer in range <code>[0,numberOfUsers - 1]</code>. There can be <strong>multiple</strong> ids separated by a single whitespace and may contain duplicates. This can mention even the offline users.</li>
			<li><code>ALL</code>: mentions <strong>all</strong> users.</li>
			<li><code>HERE</code>: mentions all <strong>online</strong> users.</li>
		</ul>
		</li>
	</ul>
	</li>
	<li><strong>Offline Event:</strong> <code>[&quot;OFFLINE&quot;, &quot;timestamp<sub>i</sub>&quot;, &quot;id<sub>i</sub>&quot;]</code>
	<ul>
		<li>This event indicates that the user <code>id<sub>i</sub></code> had become offline at <code>timestamp<sub>i</sub></code> for <strong>60 time units</strong>. The user will automatically be online again at time <code>timestamp<sub>i</sub> + 60</code>.</li>
	</ul>
	</li>
</ol>

<p>Return an array <code>mentions</code> where <code>mentions[i]</code> represents the number of mentions the user with id <code>i</code> has across all <code>MESSAGE</code> events.</p>

<p>All users are initially online, and if a user goes offline or comes back online, their status change is processed <em>before</em> handling any message event that occurs at the same timestamp.</p>

<p><strong>Note </strong>that a user can be mentioned <strong>multiple</strong> times in a <strong>single</strong> message event, and each mention should be counted <strong>separately</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">numberOfUsers = 2, events = [[&quot;MESSAGE&quot;,&quot;10&quot;,&quot;id1 id0&quot;],[&quot;OFFLINE&quot;,&quot;11&quot;,&quot;0&quot;],[&quot;MESSAGE&quot;,&quot;71&quot;,&quot;HERE&quot;]]</span></p>

<p><strong>Output:</strong> <span class="example-io">[2,2]</span></p>

<p><strong>Explanation:</strong></p>

<p>Initially, all users are online.</p>

<p>At timestamp 10, <code>id1</code> and <code>id0</code> are mentioned. <code>mentions = [1,1]</code></p>

<p>At timestamp 11, <code>id0</code> goes <strong>offline.</strong></p>

<p>At timestamp 71, <code>id0</code> comes back <strong>online</strong> and <code>&quot;HERE&quot;</code> is mentioned. <code>mentions = [2,2]</code></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">numberOfUsers = 2, events = [[&quot;MESSAGE&quot;,&quot;10&quot;,&quot;id1 id0&quot;],[&quot;OFFLINE&quot;,&quot;11&quot;,&quot;0&quot;],[&quot;MESSAGE&quot;,&quot;12&quot;,&quot;ALL&quot;]]</span></p>

<p><strong>Output:</strong> <span class="example-io">[2,2]</span></p>

<p><strong>Explanation:</strong></p>

<p>Initially, all users are online.</p>

<p>At timestamp 10, <code>id1</code> and <code>id0</code> are mentioned. <code>mentions = [1,1]</code></p>

<p>At timestamp 11, <code>id0</code> goes <strong>offline.</strong></p>

<p>At timestamp 12, <code>&quot;ALL&quot;</code> is mentioned. This includes offline users, so both <code>id0</code> and <code>id1</code> are mentioned. <code>mentions = [2,2]</code></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">numberOfUsers = 2, events = [[&quot;OFFLINE&quot;,&quot;10&quot;,&quot;0&quot;],[&quot;MESSAGE&quot;,&quot;12&quot;,&quot;HERE&quot;]]</span></p>

<p><strong>Output:</strong> <span class="example-io">[0,1]</span></p>

<p><strong>Explanation:</strong></p>

<p>Initially, all users are online.</p>

<p>At timestamp 10, <code>id0</code> goes <strong>offline.</strong></p>

<p>At timestamp 12, <code>&quot;HERE&quot;</code> is mentioned. Because <code>id0</code> is still offline, they will not be mentioned. <code>mentions = [0,1]</code></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= numberOfUsers &lt;= 100</code></li>
	<li><code>1 &lt;= events.length &lt;= 100</code></li>
	<li><code>events[i].length == 3</code></li>
	<li><code>events[i][0]</code> will be one of <code>MESSAGE</code> or <code>OFFLINE</code>.</li>
	<li><code>1 &lt;= int(events[i][1]) &lt;= 10<sup>5</sup></code></li>
	<li>The number of <code>id&lt;number&gt;</code> mentions in any <code>&quot;MESSAGE&quot;</code> event is between <code>1</code> and <code>100</code>.</li>
	<li><code>0 &lt;= &lt;number&gt; &lt;= numberOfUsers - 1</code></li>
	<li>It is <strong>guaranteed</strong> that the user id referenced in the <code>OFFLINE</code> event is <strong>online</strong> at the time the event occurs.</li>
</ul>


## Solution

``` cpp
vector<string> split(const string &s, char spliter = ' ') {
  vector<string> result;
  for(int i = 0; i < s.length(); ++i) {
    string st;
    while(i < s.length() && s[i] != spliter) {
      st += s[i];
      i += 1;
    }
    if(st.size()) result.emplace_back(st);
  }
  return result;
}
class Solution {
  using pi = pair<int, int>;
  int getId(const string &id) {
    return stoi(id.substr(2));
  }
  const string MSG = "MESSAGE";
  const string OFF = "OFFLINE";
  const string ALL = "ALL";
  const string HERE = "HERE";
public:
  vector<int> countMentions(int n, vector<vector<string>>& events) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<int> answer(n);
    vector<bool> online(n, true);

    sort(events.begin(), events.end(), [&](const vector<string> &a, const vector<string> & b) {
      int ta = stoi(a[1]);
      int tb = stoi(b[1]);
      return ta < tb || (ta == tb && a[0] == OFF && b[0] != OFF);
    });
    for(const auto &e : events) {
      int time = stoi(e[1]);
      while(pq.size() && time >= pq.top().first) {
        online[pq.top().second] = true;
        pq.pop();
      }
      if(e[0] == MSG) {
        if(e[2] == ALL) {
          for(auto &c : answer) c += 1;
        } else if(e[2] == HERE) {
          for(int i = 0; i < n; ++i) {
            if(online[i]) answer[i] += 1;
          } 
        } else {
          auto ids = split(e[2]);
          for(auto id : ids) {
            answer[getId(id)] += 1;
          }
        }
      } else {
        int id = stoi(e[2]);
        online[id] = false;
        pq.push({time + 60, id});
      }
    }
    return answer;
  }
};

// Accepted
// 673/673 cases passed (32 ms)
// Your runtime beats 60.99 % of cpp submissions
// Your memory usage beats 26.95 % of cpp submissions (53.4 MB)
```
