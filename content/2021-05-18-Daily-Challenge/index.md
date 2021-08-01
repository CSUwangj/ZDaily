+++
title = "2021-05-18 Daily-Challenge"
path = "2021-05-18-Daily-Challenge"
date = 2021-05-18 18:21:54+08:00
updated = 2021-05-18 18:44:55+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

I'm busy playing Dungeons & Fighters, so won't do pick up.

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3747/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 18

## Description

**Find Duplicate File in System**

Given a list `paths` of directory info, including the directory path, and all the files with contents in this directory, return *all the duplicate files in the file system in terms of their paths*. You may return the answer in **any order**.

A group of duplicate files consists of at least two files that have the same content.

A single directory info string in the input list has the following format:

- `"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"`

It means there are `n` files `(f1.txt, f2.txt ... fn.txt)` with content `(f1_content, f2_content ... fn_content)` respectively in the directory "`root/d1/d2/.../dm"`. Note that `n >= 1` and `m >= 0`. If `m = 0`, it means the directory is just the root directory.

The output is a list of groups of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:

- `"directory_path/file_name.txt"`

 

**Example 1:**

```
Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
Output: [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
```

**Example 2:**

```
Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)"]
Output: [["root/a/2.txt","root/c/d/4.txt"],["root/a/1.txt","root/c/3.txt"]]
```

 

**Constraints:**

- `1 <= paths.length <= 2 * 104`
- `1 <= paths[i].length <= 3000`
- `1 <= sum(paths[i].length) <= 5 * 105`
- `paths[i]` consist of English letters, digits, `'/'`, `'.'`, `'('`, `')'`, and `' '`.
- You may assume no files or directories share the same name in the same directory.
- You may assume each given directory info represents a unique directory. A single blank space separates the directory path and file info.

 

**Follow up:**

- Imagine you are given a real file system, how will you search files? DFS or BFS?
- If the file content is very large (GB level), how will you modify your solution?
- If you can only read the file by 1kb each time, how will you modify your solution?
- What is the time complexity of your modified solution? What is the most time-consuming part and memory-consuming part of it? How to optimize?
- How to make sure the duplicated files you find are not false positive?

## Solution

``` cpp
auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
  unordered_map<string, vector<string>> mapping;
  void parsePath(string &path) {
    int pos = 0;
    int len = path.length();
    while(pos < len && path[pos] != ' ') pos += 1;
    string base = path.substr(0, pos);
    pos += 1;
    // cout << base << endl;
    while(pos < len) {
      int file = 0;
      while(path[pos + file] != '(') file += 1;
      string fileName = path.substr(pos, file);
      pos += file + 1;
      int content = 0;
      while(path[pos + content] != ')') content += 1;
      string contentString = path.substr(pos, content);
      // cout << fileName << " " << contentString << endl;
      mapping[contentString].push_back(base + "/" + fileName);
      pos += content + 2;
    }
  }
public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    for(auto &path : paths) parsePath(path);
    vector<vector<string>> answer;
    for(auto &[content, files] : mapping) {
      if(files.size() > 1) answer.push_back(files);
    }
    return answer;
  }
};
```
