+++
updated = 2025-10-24T18:55:50+02:00
title = "2025-10-24 Daily Challenge"
path = "2025-10-24-Daily-Challenge"
date = 2025-10-24T18:55:50+02:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [October LeetCoding Challenge](https://leetcode.com/problems/next-greater-numerically-balanced-number/) with `cpp`.

<!-- more -->

# October LeetCoding Challenge 24

## Description

**Next Greater Numerically Balanced Number**

<p>An integer <code>x</code> is <strong>numerically balanced</strong> if for every digit <code>d</code> in the number <code>x</code>, there are <strong>exactly</strong> <code>d</code> occurrences of that digit in <code>x</code>.</p>

<p>Given an integer <code>n</code>, return <em>the <strong>smallest numerically balanced</strong> number <strong>strictly greater</strong> than </em><code>n</code><em>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> 22
<strong>Explanation:</strong> 
22 is numerically balanced since:
- The digit 2 occurs 2 times. 
It is also the smallest numerically balanced number strictly greater than 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1000
<strong>Output:</strong> 1333
<strong>Explanation:</strong> 
1333 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times. 
It is also the smallest numerically balanced number strictly greater than 1000.
Note that 1022 cannot be the answer because 0 appeared more than 0 times.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 3000
<strong>Output:</strong> 3133
<strong>Explanation:</strong> 
3133 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times.
It is also the smallest numerically balanced number strictly greater than 3000.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution

``` cpp
class Solution {
  const vector<int> nums = {1, 22, 122, 212, 221, 333, 1333, 3133, 3313, 3331, 4444, 14444, 22333, 23233, 23323, 23332, 32233, 32323, 32332, 33223, 33232, 33322, 41444, 44144, 44414, 44441, 55555, 122333, 123233, 123323, 123332, 132233, 132323, 132332, 133223, 133232, 133322, 155555, 212333, 213233, 213323, 213332, 221333, 223133, 223313, 223331, 224444, 231233, 231323, 231332, 232133, 232313, 232331, 233123, 233132, 233213, 233231, 233312, 233321, 242444, 244244, 244424, 244442, 312233, 312323, 312332, 313223, 313232, 313322, 321233, 321323, 321332, 322133, 322313, 322331, 323123, 323132, 323213, 323231, 323312, 323321, 331223, 331232, 331322, 332123, 332132, 332213, 332231, 332312, 332321, 333122, 333212, 333221, 422444, 424244, 424424, 424442, 442244, 442424, 442442, 444224, 444242, 444422, 515555, 551555, 555155, 555515, 555551, 666666, 1224444};
public:
  int nextBeautifulNumber(int n) {
    return *upper_bound(nums.begin(), nums.end(), n);
  }
};

// Accepted
// 145/145 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 87.44 % of cpp submissions (8.3 MB)
```

generator code:

``` cpp
#include<bits/stdc++.h>

using namespace std;

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

int main() {
  vector<string> nums{"1", "22", "333", "4444", "55555", "666666"};
  vector<int> result;
  for(int i = 1; i < (1 << 6); ++i) {
    string tmp;
    for(int j = 0; j < 6; ++j) {
      if((1 << j) & i) tmp += nums[j];
    }
    if(tmp.length() > 7) continue;
    sort(tmp.begin(), tmp.end());
    do{
      result.push_back(stoi(tmp));
    } while(next_permutation(tmp.begin(), tmp.end()));
  }
  sort(result.begin(), result.end());
  cout << result << endl;
  return 0;
}
```
