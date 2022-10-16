+++
title = "2021-05-02 Daily-Challenge"
path = "2021-05-02-Daily-Challenge"
date = 2021-05-02 02:15:30+08:00
updated = 2021-05-02 21:06:05+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Sunday, I gonna review the tasks I've done this week, and finish today's leetcode's [May LeetCoding Challenge](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3729/) with `cpp`.

<!-- more -->

# LeetCode Review

## Unique Paths II

no need to review

## Power of Three

too easy to review

## Furthest Building You Can Reach

no need to review

## Find First and Last Position of Element in Sorted Array

no need to review

## Powerful Integers

no need to review

## Minimum Insertion Steps to Make a String Palindrome

take a string `s` and its mirror `r`, find longest common sequence, use middle point of LCS, then we got the answer.

code is simple, so won't review it.

## Lexicographically Smallest String After Applying Operations

``` cpp
constexpr int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}
class Solution {
private:
  void minHalf(string &s, bool odd, int a) {
    char mmin = s[odd];
    int cnt = 0;
    for(int i = 1; i < 10; ++i) {
      char test = (s[odd] - '0' + i * a) % 10 + '0';
      if(test < mmin) {
        mmin = test;
        cnt = i;
      }
    }
    // cout << s << ' ' << cnt << endl;
    if(!cnt) return;
    for(int i = odd; i < s.length(); i += 2) {
      s[i] = (s[i] - '0' + cnt * a) % 10 + '0';
    }
  }
public: 
  string findLexSmallestString(string s, int a, int b) {
    int len = s.length();
    int t = len / gcd(b, len);
    string answer = s;
    for(int i = 0; i < t; ++i) {
      rotate(s.rbegin(), s.rbegin() + b, s.rend());
      string tmp = s;
      if(b & 1) minHalf(tmp, false, a);
      minHalf(tmp, true, a);
      // cout << s << ' ' << tmp << endl;
      answer = min(answer, tmp);
    }
    return answer;
  }
};

// Accepted
// 80/80 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 99.29 % of cpp submissions (6.4 MB)
```

## K-Similar Strings

<table ><thead ><tr><th ><span ><div><span >Time Submitted</span><span ></span></div></span></th><th ><span ><div><span >Status</span><span ></span></div></span></th><th ><span ><div><span >Runtime</span><span ></span></div></span></th><th ><span ><div><span >Memory</span><span ></span></div></span></th><th ><span ><div><span >Language</span><span ></span></div></span></th></tr></thead><tbody ><tr  data-row-key="487719355"><td >05/02/2021 12:10</td><td ><a href="/submissions/detail/487719355/" target="_blank"  data-submission-id="487719355">Accepted</a></td><td >4 ms</td><td >6.4 MB</td><td >cpp</td></tr><tr  data-row-key="487718613"><td >05/02/2021 12:08</td><td ><a href="/submissions/detail/487718613/" target="_blank"  data-submission-id="487718613">Accepted</a></td><td >24 ms</td><td >18.8 MB</td><td >cpp</td></tr><tr  data-row-key="486282650"><td >04/28/2021 22:05</td><td ><a href="/submissions/detail/486282650/" target="_blank"  data-submission-id="486282650">Accepted</a></td><td >668 ms</td><td >61.3 MB</td><td >cpp</td></tr></tbody></table>

``` cpp
const int MAX = 400;
class Solution {
public:
  int kSimilarity(string s1, string s2) {
    int len = s1.length();
    for(int i = 0; i < len; ++i) {
      if(s1[i] == s2[i]) continue;
      for(int j = i + 1; j < len; ++j) {
        if(s1[i] == s2[j] && s1[j] == s2[i]) {
          swap(s1[i], s1[j]);
          return 1 + kSimilarity(s1.substr(i + 1), s2.substr(i + 1));
        }
      }
      int answer = MAX;
      for(int j = i + 1; j < len; ++j) {
        if(s1[j] == s2[i] && s1[j] != s2[j]) {
          swap(s1[i], s1[j]);
          answer = min(answer, 1 + kSimilarity(s1.substr(i + 1), s2.substr(i + 1)));
          swap(s1[i], s1[j]);
        }
      }
      return answer;
    }
    return 0;
  }
};
```

# May LeetCoding Challenge 2

## Description

**Course Schedule III**

There are `n` different online courses numbered from `1` to `n`. You are given an array `courses` where `courses[i] = [durationi, lastDayi]` indicate that the `ith` course should be taken **continuously** for `durationi` days and must be finished before or on `lastDayi`.

You will start on the `1st` day and you cannot take two or more courses simultaneously.

Return *the maximum number of courses that you can take*.

 

**Example 1:**

```
Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
Output: 3
Explanation: 
There are totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.
```

**Example 2:**

```
Input: courses = [[1,2]]
Output: 1
```

**Example 3:**

```
Input: courses = [[3,2],[4,3]]
Output: 0
```

 

**Constraints:**

- <code>1 <= courses.length <= 10<sup>4</sup></code>
- <code>1 <= durationi, lastDayi <= 10<sup>4</sup></code>

## Solution

I think I was right, but OJ told me I'm wrong. I checked the solution and confirmed that I'm right. Oops, TYPO.

``` cpp
class Solution {
public:
  int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
    });
    // cout << "#######" << endl;
    priority_queue<int> q;
    int cur = 0;
    int answer = 0;
    for(auto &course : courses) {
      // cout << cur << endl;
      if(cur + course[0] <= course[1]) {
        answer += 1;
        cur += course[0];
        q.push(course[0]);
      } else if(q.size() && q.top() > course[0]) {
        cur += course[0] - q.top();
        q.pop();
        q.push(course[0]);
      }
    }
    return answer;
  }
};


// 97 / 97 test cases passed.
// Status: Accepted
// Runtime: 192 ms
// Memory Usage: 56.2 MB
```

check other's solution and found sort pairs is faster:

``` cpp
class Solution {
public:
  int scheduleCourse(vector<vector<int>> &courses) {
    vector<pair<int, int>> cr;
    for(auto &c : courses) cr.push_back(make_pair(c[1], c[0]));
    sort(cr.begin(), cr.end());
    priority_queue<int> q;
    int cur = 0;
    for(auto &[ddl, duration] : cr) {
      if(cur + duration <= ddl) {
        q.push(duration);
        cur += duration;
      } else if(q.size() && q.top() > duration) {
        cur += duration - q.top();
        q.pop();
        q.push(duration);
      }
    }
    return q.size();
  }
};

// Accepted
// 97/97 cases passed (152 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 50.48 % of cpp submissions (60.7 MB)
```

and customized sorting method does not affect performance much 

``` cpp
class Solution {
public:
  int scheduleCourse(vector<vector<int>> &courses) {
    vector<pair<int, int>> cr;
    for(auto &c : courses) cr.push_back(make_pair(c[0], c[1]));
    sort(cr.begin(), cr.end(), [](const pair<int, int> &a, const pair<int, int> &b){
      return a.second < b.second || (a.second == b.second && a.first < b.first);
    });
    priority_queue<int> q;
    int cur = 0;
    for(auto &[duration, ddl] : cr) {
      if(cur + duration <= ddl) {
        q.push(duration);
        cur += duration;
      } else if(q.size() && q.top() > duration) {
        cur += duration - q.top();
        q.pop();
        q.push(duration);
      }
    }
    return q.size();
  }
};

// 97 / 97 test cases passed.
// Status: Accepted
// Runtime: 152 ms
// Memory Usage: 60.7 MB
```
