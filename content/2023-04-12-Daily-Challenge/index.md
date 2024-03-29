+++
updated = 2023-04-12T14:43:44+08:00
title = "2023-04-12 Daily Challenge"
path = "2023-04-12-Daily-Challenge"
date = 2023-04-12T14:43:44+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [April LeetCoding Challenge](https://leetcode.com/problems/simplify-path/) with `cpp`.

<!-- more -->

# April LeetCoding Challenge 12

## Description

**Simplify Path**

<p>Given a string <code>path</code>, which is an <strong>absolute path</strong> (starting with a slash <code>&#39;/&#39;</code>) to a file or directory in a Unix-style file system, convert it to the simplified <strong>canonical path</strong>.</p>

<p>In a Unix-style file system, a period <code>&#39;.&#39;</code> refers to the current directory, a double period <code>&#39;..&#39;</code> refers to the directory up a level, and any multiple consecutive slashes (i.e. <code>&#39;//&#39;</code>) are treated as a single slash <code>&#39;/&#39;</code>. For this problem, any other format of periods such as <code>&#39;...&#39;</code> are treated as file/directory names.</p>

<p>The <strong>canonical path</strong> should have the following format:</p>

<ul>
	<li>The path starts with a single slash <code>&#39;/&#39;</code>.</li>
	<li>Any two directories are separated by a single slash <code>&#39;/&#39;</code>.</li>
	<li>The path does not end with a trailing <code>&#39;/&#39;</code>.</li>
	<li>The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period <code>&#39;.&#39;</code> or double period <code>&#39;..&#39;</code>)</li>
</ul>

<p>Return <em>the simplified <strong>canonical path</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> path = &quot;/home/&quot;
<strong>Output:</strong> &quot;/home&quot;
<strong>Explanation:</strong> Note that there is no trailing slash after the last directory name.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> path = &quot;/../&quot;
<strong>Output:</strong> &quot;/&quot;
<strong>Explanation:</strong> Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> path = &quot;/home//foo/&quot;
<strong>Output:</strong> &quot;/home/foo&quot;
<strong>Explanation:</strong> In the canonical path, multiple consecutive slashes are replaced by a single one.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= path.length &lt;= 3000</code></li>
	<li><code>path</code> consists of English letters, digits, period <code>&#39;.&#39;</code>, slash <code>&#39;/&#39;</code> or <code>&#39;_&#39;</code>.</li>
	<li><code>path</code> is a valid absolute Unix path.</li>
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
public:
  string simplifyPath(string path) {
    string cur;
    vector<string> folders;
    path.push_back('/');
    for(auto c : path) {
      if(c == '/') {
        if(cur == "..") {
          if(folders.size()) folders.pop_back();
        } else if (cur.length() && cur != ".") {
          folders.push_back(cur);
        }
        cur.clear();
      } else {
        cur.push_back(c);
      }
    }


    if(folders.empty()) return "/";

    string answer;
    for(auto &folder : folders) {
      answer.push_back('/');
      answer += folder;
    }
    return answer;
  }
};

// Accepted
// 258/258 cases passed (4 ms)
// Your runtime beats 78.99 % of cpp submissions
// Your memory usage beats 85.65 % of cpp submissions (7.8 MB)
```
