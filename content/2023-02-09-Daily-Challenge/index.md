+++
updated = 2023-02-09T22:41:57+08:00
title = "2023-02-09 Daily Challenge"
path = "2023-02-09-Daily-Challenge"
date = 2023-02-09T22:41:57+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [February LeetCoding Challenge](https://leetcode.com/problems/naming-a-company/) with `cpp`.

<!-- more -->

# February LeetCoding Challenge 9

## Description

**Naming a Company**

<p>You are given an array of strings <code>ideas</code> that represents a list of names to be used in the process of naming a company. The process of naming a company is as follows:</p>

<ol>
	<li>Choose 2 <strong>distinct</strong> names from <code>ideas</code>, call them <code>idea<sub>A</sub></code> and <code>idea<sub>B</sub></code>.</li>
	<li>Swap the first letters of <code>idea<sub>A</sub></code> and <code>idea<sub>B</sub></code> with each other.</li>
	<li>If <strong>both</strong> of the new names are not found in the original <code>ideas</code>, then the name <code>idea<sub>A</sub> idea<sub>B</sub></code> (the <strong>concatenation</strong> of <code>idea<sub>A</sub></code> and <code>idea<sub>B</sub></code>, separated by a space) is a valid company name.</li>
	<li>Otherwise, it is not a valid name.</li>
</ol>

<p>Return <em>the number of <strong>distinct</strong> valid names for the company</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> ideas = [&quot;coffee&quot;,&quot;donuts&quot;,&quot;time&quot;,&quot;toffee&quot;]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The following selections are valid:
- (&quot;coffee&quot;, &quot;donuts&quot;): The company name created is &quot;doffee conuts&quot;.
- (&quot;donuts&quot;, &quot;coffee&quot;): The company name created is &quot;conuts doffee&quot;.
- (&quot;donuts&quot;, &quot;time&quot;): The company name created is &quot;tonuts dime&quot;.
- (&quot;donuts&quot;, &quot;toffee&quot;): The company name created is &quot;tonuts doffee&quot;.
- (&quot;time&quot;, &quot;donuts&quot;): The company name created is &quot;dime tonuts&quot;.
- (&quot;toffee&quot;, &quot;donuts&quot;): The company name created is &quot;doffee tonuts&quot;.
Therefore, there are a total of 6 distinct company names.

The following are some examples of invalid selections:
- (&quot;coffee&quot;, &quot;time&quot;): The name &quot;toffee&quot; formed after swapping already exists in the original array.
- (&quot;time&quot;, &quot;toffee&quot;): Both names are still the same after swapping and exist in the original array.
- (&quot;coffee&quot;, &quot;toffee&quot;): Both names formed after swapping already exist in the original array.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> ideas = [&quot;lack&quot;,&quot;back&quot;]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no valid selections. Therefore, 0 is returned.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= ideas.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= ideas[i].length &lt;= 10</code></li>
	<li><code>ideas[i]</code> consists of lowercase English letters.</li>
	<li>All the strings in <code>ideas</code> are <strong>unique</strong>.</li>
</ul>


## Solution

``` cpp
class Solution {
public:
  long long distinctNames(vector<string>& ideas) {
    long long answer = 0;

    unordered_set<string> suffixes[26];
    for(const auto &idea : ideas) {
      suffixes[idea[0] - 'a'].insert(idea.substr(1));
    }

    for(int i = 0; i < 25; ++i) {
      for(int j = i + 1; j < 26; ++j) {
        int same = 0;
        for(const auto &suffix : suffixes[i]) {
          if(suffixes[j].count(suffix)) {
            same += 1;
          }
        }

        answer += 2 * (suffixes[i].size() - same) * (suffixes[j].size() - same);
      }
    }

    return answer;
  }
};

// Accepted
// 89/89 cases passed (458 ms)
// Your runtime beats 90.24 % of cpp submissions
// Your memory usage beats 43.9 % of cpp submissions (83.4 MB)
```
