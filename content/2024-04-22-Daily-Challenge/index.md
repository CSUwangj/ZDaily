+++
updated = 2024-04-22T20:29:17+08:00
title = "2024-04-22 Daily Challenge"
path = "2024-04-22-Daily-Challenge"
date = 2024-04-22T20:29:17+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/open-the-lock/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 22

## Description

**Open the Lock**

<p>You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: <code>&#39;0&#39;, &#39;1&#39;, &#39;2&#39;, &#39;3&#39;, &#39;4&#39;, &#39;5&#39;, &#39;6&#39;, &#39;7&#39;, &#39;8&#39;, &#39;9&#39;</code>. The wheels can rotate freely and wrap around: for example we can turn <code>&#39;9&#39;</code> to be <code>&#39;0&#39;</code>, or <code>&#39;0&#39;</code> to be <code>&#39;9&#39;</code>. Each move consists of turning one wheel one slot.</p>

<p>The lock initially starts at <code>&#39;0000&#39;</code>, a string representing the state of the 4 wheels.</p>

<p>You are given a list of <code>deadends</code> dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.</p>

<p>Given a <code>target</code> representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> deadends = [&quot;0201&quot;,&quot;0101&quot;,&quot;0102&quot;,&quot;1212&quot;,&quot;2002&quot;], target = &quot;0202&quot;
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
A sequence of valid moves would be &quot;0000&quot; -&gt; &quot;1000&quot; -&gt; &quot;1100&quot; -&gt; &quot;1200&quot; -&gt; &quot;1201&quot; -&gt; &quot;1202&quot; -&gt; &quot;0202&quot;.
Note that a sequence like &quot;0000&quot; -&gt; &quot;0001&quot; -&gt; &quot;0002&quot; -&gt; &quot;0102&quot; -&gt; &quot;0202&quot; would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end &quot;0102&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> deadends = [&quot;8888&quot;], target = &quot;0009&quot;
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can turn the last wheel in reverse to move from &quot;0000&quot; -&gt; &quot;0009&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> deadends = [&quot;8887&quot;,&quot;8889&quot;,&quot;8878&quot;,&quot;8898&quot;,&quot;8788&quot;,&quot;8988&quot;,&quot;7888&quot;,&quot;9888&quot;], target = &quot;8888&quot;
<strong>Output:</strong> -1
<strong>Explanation:</strong> We cannot reach the target without getting stuck.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= deadends.length &lt;= 500</code></li>
	<li><code>deadends[i].length == 4</code></li>
	<li><code>target.length == 4</code></li>
	<li>target <strong>will not be</strong> in the list <code>deadends</code>.</li>
	<li><code>target</code> and <code>deadends[i]</code> consist of digits only.</li>
</ul>


## Solution

``` cpp
class Solution {
  void checkAndInsert(
    unordered_set<string> &dead,
    unordered_map<string, int> &cnt,
    queue<string> &q,
    string &cur
  ) {
    int originalCnt = cnt[cur];
    for(auto &c : cur) {
      c = (c - '0' + 9) % 10 + '0';
      if(!dead.count(cur) && !cnt.count(cur)) {
        cnt[cur] = originalCnt + 1;
        q.push(cur);
      }
      c = (c - '0' + 2) % 10 + '0';
      if(!dead.count(cur) && !cnt.count(cur)) {
        cnt[cur] = originalCnt + 1;
        q.push(cur);
      }
      c = (c - '0' + 9) % 10 + '0';
    }
  }
public:
  int openLock(vector<string>& deadends, string target) {
    unordered_set<string> dead(deadends.begin(), deadends.end());
    if(dead.count("0000") || dead.count(target)) return -1;
    unordered_map<string, int> frontBFS{{"0000", 0}}, backBFS{{target, 0}};
    queue<string> frontQ, backQ;
    frontQ.push("0000");
    backQ.push(target);
    int cnt = 0;
    while(frontQ.size() && backQ.size()) {
      int frontSize = frontQ.size();
      for(int i = 0; i < frontSize; ++i) {
        auto cur = frontQ.front();
        frontQ.pop();
        if(backBFS.count(cur)) {
          // cout << "F: " << cur << ' ' << frontBFS[cur] << ' ' << backBFS[cur] << endl;
          return frontBFS[cur] + backBFS[cur];
        }
        checkAndInsert(dead, frontBFS, frontQ, cur);
      }
      int backSize = backQ.size();
      for(int i = 0; i < backSize; ++i) {
        auto cur = backQ.front();
        backQ.pop();
        if(frontBFS.count(cur)) {
          // cout << "B: " << cur << ' ' << frontBFS[cur] << ' ' << backBFS[cur] << endl;
          return frontBFS[cur] + backBFS[cur];
        }
        checkAndInsert(dead, backBFS, backQ, cur);
      }
    }
    return -1;
  }
};
```
