+++
updated = 2024-09-29T08:34:48+08:00
title = "2024-09-29 Daily Challenge"
path = "2024-09-29-Daily-Challenge"
date = 2024-09-29T08:34:48+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [September LeetCoding Challenge](https://leetcode.com/problems/all-oone-data-structure/) with `cpp`.

<!-- more -->

# September LeetCoding Challenge 29

## Description

**All O`one Data Structure**

<p>Design a data structure to store the strings&#39; count with the ability to return the strings with minimum and maximum counts.</p>

<p>Implement the <code>AllOne</code> class:</p>

<ul>
	<li><code>AllOne()</code> Initializes the object of the data structure.</li>
	<li><code>inc(String key)</code> Increments the count of the string <code>key</code> by <code>1</code>. If <code>key</code> does not exist in the data structure, insert it with count <code>1</code>.</li>
	<li><code>dec(String key)</code> Decrements the count of the string <code>key</code> by <code>1</code>. If the count of <code>key</code> is <code>0</code> after the decrement, remove it from the data structure. It is guaranteed that <code>key</code> exists in the data structure before the decrement.</li>
	<li><code>getMaxKey()</code> Returns one of the keys with the maximal count. If no element exists, return an empty string <code>&quot;&quot;</code>.</li>
	<li><code>getMinKey()</code> Returns one of the keys with the minimum count. If no element exists, return an empty string <code>&quot;&quot;</code>.</li>
</ul>

<p><strong>Note</strong> that each function must run in <code>O(1)</code> average time complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;AllOne&quot;, &quot;inc&quot;, &quot;inc&quot;, &quot;getMaxKey&quot;, &quot;getMinKey&quot;, &quot;inc&quot;, &quot;getMaxKey&quot;, &quot;getMinKey&quot;]
[[], [&quot;hello&quot;], [&quot;hello&quot;], [], [], [&quot;leet&quot;], [], []]
<strong>Output</strong>
[null, null, null, &quot;hello&quot;, &quot;hello&quot;, null, &quot;hello&quot;, &quot;leet&quot;]

<strong>Explanation</strong>
AllOne allOne = new AllOne();
allOne.inc(&quot;hello&quot;);
allOne.inc(&quot;hello&quot;);
allOne.getMaxKey(); // return &quot;hello&quot;
allOne.getMinKey(); // return &quot;hello&quot;
allOne.inc(&quot;leet&quot;);
allOne.getMaxKey(); // return &quot;hello&quot;
allOne.getMinKey(); // return &quot;leet&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= key.length &lt;= 10</code></li>
	<li><code>key</code> consists of lowercase English letters.</li>
	<li>It is guaranteed that for each call to <code>dec</code>, <code>key</code> is existing in the data structure.</li>
	<li>At most <code>5 * 10<sup>4</sup></code>&nbsp;calls will be made to <code>inc</code>, <code>dec</code>, <code>getMaxKey</code>, and <code>getMinKey</code>.</li>
</ul>


## Solution

``` cpp
class AllOne {
  unordered_map<string, int> count;
  set<pair<int, string>> st;
public:
  AllOne() {
  }
  
  void inc(string key) {
    int n = count[key];
    count[key] += 1;
    st.erase({n, key});
    st.insert({n + 1, key});
  }
  
  void dec(string key) {
    int n = count[key];
    count[key] -= 1;
    st.erase({n, key});
    if(count[key]) st.insert({n - 1, key});
  }
  
  string getMaxKey() {
    if(st.size()) return st.rbegin()->second;
    return "";
  }
  
  string getMinKey() {
    if(st.size()) return st.begin()->second;
    return "";
  }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
```
