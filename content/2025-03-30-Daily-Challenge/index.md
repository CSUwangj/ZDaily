+++
updated = 2025-03-30T12:11:19+08:00
title = "2025-03-30 Daily Challenge"
path = "2025-03-30-Daily-Challenge"
date = 2025-03-30T12:11:19+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [March LeetCoding Challenge](https://leetcode.com/problems/partition-labels/) with `cpp`.

<!-- more -->

# March LeetCoding Challenge 30

## Description

**Partition Labels**

<p>You are given a string <code>s</code>. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string <code>&quot;ababcc&quot;</code> can be partitioned into <code>[&quot;abab&quot;, &quot;cc&quot;]</code>, but partitions such as <code>[&quot;aba&quot;, &quot;bcc&quot;]</code> or <code>[&quot;ab&quot;, &quot;ab&quot;, &quot;cc&quot;]</code> are invalid.</p>

<p>Note that the partition is done so that after concatenating all the parts in order, the resultant string should be <code>s</code>.</p>

<p>Return <em>a list of integers representing the size of these parts</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ababcbacadefegdehijhklij&quot;
<strong>Output:</strong> [9,7,8]
<strong>Explanation:</strong>
The partition is &quot;ababcbaca&quot;, &quot;defegde&quot;, &quot;hijhklij&quot;.
This is a partition so that each letter appears in at most one part.
A partition like &quot;ababcbacadefegde&quot;, &quot;hijhklij&quot; is incorrect, because it splits s into less parts.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;eccbbbbdec&quot;
<strong>Output:</strong> [10]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  vector<int> partitionLabels(string s) {
    vector<pair<int, int>> pos(26, {-1, -1});
    for(int i = 0; i < s.length(); ++i) {
      if(pos[s[i] - 'a'].first == -1) {
        pos[s[i] - 'a'].first = i;
      }
      pos[s[i] - 'a'].second = i;
    }
    sort(pos.begin(), pos.end());
    vector<int> answer;
    int begin = pos.front().first;
    int end = pos.front().second;
    for(auto [b, e] : pos) {
      if(b > end) {
        if(begin != -1) {
          answer.push_back(end - begin + 1);
        }
        begin = b;
        end = e;
      } else {
        end = max(end, e);
      }
    }
    answer.push_back(end - begin + 1);
    return answer;
  }
};

// Accepted
// 118/118 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 71.56 % of cpp submissions (8.8 MB)
```
