+++
updated = 2023-01-28T12:49:59+08:00
title = "2023-01-28 Daily Challenge"
path = "2023-01-28-Daily-Challenge"
date = 2023-01-28T12:49:59+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [January LeetCoding Challenge](https://leetcode.com/problems/data-stream-as-disjoint-intervals/) with `cpp`.

<!-- more -->

# January LeetCoding Challenge 28

## Description

**Data Stream as Disjoint Intervals**

<p>Given a data stream input of non-negative integers <code>a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub></code>, summarize the numbers seen so far as a list of disjoint intervals.</p>

<p>Implement the <code>SummaryRanges</code> class:</p>

<ul>
	<li><code>SummaryRanges()</code> Initializes the object with an empty stream.</li>
	<li><code>void addNum(int value)</code> Adds the integer <code>value</code> to the stream.</li>
	<li><code>int[][] getIntervals()</code> Returns a summary of the integers in the stream currently as a list of disjoint intervals <code>[start<sub>i</sub>, end<sub>i</sub>]</code>. The answer should be sorted by <code>start<sub>i</sub></code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;SummaryRanges&quot;, &quot;addNum&quot;, &quot;getIntervals&quot;, &quot;addNum&quot;, &quot;getIntervals&quot;, &quot;addNum&quot;, &quot;getIntervals&quot;, &quot;addNum&quot;, &quot;getIntervals&quot;, &quot;addNum&quot;, &quot;getIntervals&quot;]
[[], [1], [], [3], [], [7], [], [2], [], [6], []]
<strong>Output</strong>
[null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

<strong>Explanation</strong>
SummaryRanges summaryRanges = new SummaryRanges();
summaryRanges.addNum(1);      // arr = [1]
summaryRanges.getIntervals(); // return [[1, 1]]
summaryRanges.addNum(3);      // arr = [1, 3]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
summaryRanges.addNum(7);      // arr = [1, 3, 7]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= value &lt;= 10<sup>4</sup></code></li>
	<li>At most <code>3 * 10<sup>4</sup></code> calls will be made to <code>addNum</code> and <code>getIntervals</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> What if there are lots of merges and the number of disjoint intervals is small compared to the size of the data stream?</p>


## Solution

``` cpp
class SummaryRanges {
  vector<vector<int>> m;
public:
  void addNum(int val) {
    auto it = lower_bound(m.begin(), m.end(), vector<int>{val, val});
    int new_begin = val, new_end = val;
    if(it != m.begin() && ((*(--it))[1]+1 < val)) ++it;
    while(it != m.end() && val+1 >= (*it)[0] && val-1 <= (*it)[1]) {
      new_begin = min(new_begin, (*it)[0]);
      new_end = max(new_end, (*it)[1]);
      it = m.erase(it);
    }
    m.insert(it, vector<int> {new_begin, new_end});
  }
  
  vector<vector<int>> getIntervals() {
    vector<vector<int>> ans;
    for(auto &interval: m) {
      ans.push_back(interval);
    }
    return ans;
  }
};

// Accepted
// 9/9 cases passed (56 ms)
// Your runtime beats 92.94 % of cpp submissions
// Your memory usage beats 18.43 % of cpp submissions (34.3 MB)
```
