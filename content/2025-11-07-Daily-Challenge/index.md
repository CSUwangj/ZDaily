+++
updated = 2025-11-07T13:24:50+01:00
title = "2025-11-07 Daily Challenge"
path = "2025-11-07-Daily-Challenge"
date = 2025-11-07T13:24:50+01:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/maximize-the-minimum-powered-city/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 7

## Description

**Maximize the Minimum Powered City**

<p>You are given a <strong>0-indexed</strong> integer array <code>stations</code> of length <code>n</code>, where <code>stations[i]</code> represents the number of power stations in the <code>i<sup>th</sup></code> city.</p>

<p>Each power station can provide power to every city in a fixed <strong>range</strong>. In other words, if the range is denoted by <code>r</code>, then a power station at city <code>i</code> can provide power to all cities <code>j</code> such that <code>|i - j| &lt;= r</code> and <code>0 &lt;= i, j &lt;= n - 1</code>.</p>

<ul>
	<li>Note that <code>|x|</code> denotes <strong>absolute</strong> value. For example, <code>|7 - 5| = 2</code> and <code>|3 - 10| = 7</code>.</li>
</ul>

<p>The <strong>power</strong> of a city is the total number of power stations it is being provided power from.</p>

<p>The government has sanctioned building <code>k</code> more power stations, each of which can be built in any city, and have the same range as the pre-existing ones.</p>

<p>Given the two integers <code>r</code> and <code>k</code>, return <em>the <strong>maximum possible minimum power</strong> of a city, if the additional power stations are built optimally.</em></p>

<p><strong>Note</strong> that you can build the <code>k</code> power stations in multiple cities.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> stations = [1,2,4,5,0], r = 1, k = 2
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
One of the optimal ways is to install both the power stations at city 1. 
So stations will become [1,4,4,5,0].
- City 0 is provided by 1 + 4 = 5 power stations.
- City 1 is provided by 1 + 4 + 4 = 9 power stations.
- City 2 is provided by 4 + 4 + 5 = 13 power stations.
- City 3 is provided by 5 + 4 = 9 power stations.
- City 4 is provided by 5 + 0 = 5 power stations.
So the minimum power of a city is 5.
Since it is not possible to obtain a larger power, we return 5.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> stations = [4,4,4,4], r = 0, k = 3
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
It can be proved that we cannot make the minimum power of a city greater than 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == stations.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= stations[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= r&nbsp;&lt;= n - 1</code></li>
	<li><code>0 &lt;= k&nbsp;&lt;= 10<sup>9</sup></code></li>
</ul>


## Solution

``` cpp
template<typename T>
std::ostream& operator<<(std::ostream &out, const std::vector<T> &v) {
  if(v.size() == 0) {
    out << "[]" << std::endl;
    return out;
  }
  out << '[' << v[0];
  for(int i = 1; i < v.size(); ++i) {
    out << ", " << v[i];
  }
  out << ']';
  return out;
}
class Solution {
  int n;
  bool check(const vector<long long> &power, vector<int> &change, long long target, int k, int r) {
    fill(change.begin(), change.end(), 0);
    long long accumulate = 0;
    for(int i = 0; i < n; ++i) {
      if(i > r) accumulate -= change[i - r - 1];
      long long current = power[i] + accumulate;
      if(current >= target) continue;
      if(current + k < target) return false;
      int pos = min(n - 1, i + r);
      change[pos] = target - current;
      accumulate += target - current;
      k -= target - current;
    }
    return true;
  }
public:
  long long maxPower(vector<int>& stations, int r, int k) {
    n = stations.size();
    if(n == 1) return stations[0] + 0ll + k;
    vector<long long> power(n);
    for(int i = 0; i <= r; ++i) {
      power[0] += stations[i];
    }
    for(int i = 1; i < n; ++i) {
      power[i] = power[i - 1];
      if(i + r < n) power[i] += stations[i + r];
      if(i > r) power[i] -= stations[i - r - 1];
    }
    long long low = *min_element(power.begin(), power.end());
    long long high = *max_element(power.begin(), power.end()) + k;
    vector<int> tmp(n);

    while(low < high) {
      long long mid = (low + high + 1) / 2;
      if(check(power, tmp, mid, k, r)) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    return low;
  }
};

// Accepted
// 30/30 cases passed (63 ms)
// Your runtime beats 95.27 % of cpp submissions
// Your memory usage beats 98.11 % of cpp submissions (76.3 MB)
```
