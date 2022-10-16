+++
title = "2020-12-19 Daily-Challenge"
path = "2020-12-19-Daily-Challenge"
date = 2020-12-19 12:32:57+08:00
updated = 2020-12-19 22:48:03+08:00

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [November LeetCoding Challenge](https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3571/) with `cpp`.

<!-- more -->

# LeetCode Review

## Letter Combinations of a Phone Number

no need to review

why this problem is `Medium`?

## Transpose File

use `head` and `wc` to get columns number, use `seq` to iterate, use `echo` and `cut` to output.

``` bash
n=`head -n 1 file.txt | wc -w`

for i in `seq 1 $n`
do
    echo `cut -d ' ' -f $i file.txt`
done
```

## Increasing Triplet Subsequence

better solution

``` cpp
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX, middle = INT_MAX;
        for(auto i : nums) {
            if(i < min) {
                min = i;
            } else if (i > min && i < middle) {
                middle = i;
            } else if (i > middle) {
                return true;
            }
        }
        return false;
    }
};
```

## Count Number of Teams

BIT solution

``` cpp
class Solution {
    constexpr static int sz = 100001;
    vector<int> BIT = vector<int>(sz);
    
    int lowbit(int x) {
        return x&(-x);
    }
    
    void add(int x) {
        while(x < sz) {
            BIT[x] += 1;
            x += lowbit(x);
        }
    }
    
    int sum(int x) {
        int s = 0;
        while(x) {
            s += BIT[x];
            x -= lowbit(x);
        }
        return s;
    }
    
    void reset() {
        fill(BIT.begin(), BIT.end(), 0);
    }
public:
    int numTeams(vector<int>& rating) {
        int len = rating.size();
        vector<int> leftLess(len), leftMore(len);
        for(int i = 0; i < len; ++i) {
            int less = sum(rating[i]);
            int more = i - less;
            leftLess[i] = less;
            leftMore[i] = more;
            add(rating[i]);
        }
        reset();
        int answer = 0;
        for(int i = len-1; i >= 0; --i) {
            int less = sum(rating[i]);
            int more = len-1-i - less;
            answer += leftLess[i] * more;
            answer += leftMore[i] * less;
            add(rating[i]);
        }
        return answer;
    }
};
```

## 4Sum II

use just one map

``` cpp
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> AB;
        for(auto i : A) {
            for(auto j : B) {
                AB[i+j] += 1;
            }
        }
        int answer = 0;
        for(auto i : C) {
            for(auto j : D) {
                answer += AB[-i-j];
            }
        }
        return answer;
    }
};
```

## Find Peak Element

$O(n)$ solution

``` cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[len-1] > nums[len-2]) return len-1;
        for(int i = 1; i < len-1; ++i) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
        }
        return -1;
    }
};
```

## Validate Binary Search Tree

morris traversal, but strange RE on leetcode

``` cpp
class Solution {
    TreeNode *cur, *prev;
    bool check(TreeNode *cur, TreeNode *prev) {
        if(!prev || (prev->val < cur->val)) return true;
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        cur = root, prev = nullptr;
        while(cur) {
            if(!(cur->left)) {
                if(!check(cur, prev)) break;
                prev = cur;
                cur = cur->right;
            } else {
                TreeNode *pred = cur->left;
                while(pred->right != nullptr && pred->right != cur) pred = pred->right;
                if(pred->right) {
                    pred->right = nullptr;
                    if(!check(cur, prev)) break;
                    prev = cur;
                    cur = cur->right;
                } else {
                    pred->right = cur;
                    cur = cur->left;
                }
            }
        }
        cout << "fuck u" << endl;
        return cur == nullptr;
    }
};
```

## Distant Barcodes

$O(n)$ solution

``` cpp
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> cnt;
        int len = barcodes.size();
        vector<int> answer(len);
        int maxCnt = 0;
        int num;
        for(auto i : barcodes) {
            cnt[i] += 1;
            if(cnt[i] > maxCnt) {
                maxCnt = cnt[i];
                num = i;
            }
        }
        int pos = 0;
        cnt.erase(num);
        while(maxCnt--) {
            answer[pos] = num;
            pos += 2;
        }
        if(pos >= len) pos = 1;
        for(auto [num, cnt] : cnt) {
            while(cnt--) {
                answer[pos] = num;
                pos += 2;
                if(pos >= len) pos = 1;
            }
        }
        return answer;
    }
};
```

## Squares of a Sorted Array

nothing to say

``` cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer;
        for(auto i : nums) {
            answer.push_back(i*i);
        }
        sort(answer.begin(), answer.end());
        return answer;
    }
};
```

## Minimum ASCII Delete Sum for Two Strings

LCS can use just 2 row vector to represent whole dp. optimization trick from backpack problem.

but cannot reduce to one dimensional, because `dp[i-1][j-1]` has already rewritten by program.

``` cpp
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        vector<vector<int>> dp(2, vector<int>(len2+1));
        for(int i = 0; i < len1; ++i) {
            for(int j = 1; j <= len2; ++j) {
                int parity = i&1;
                dp[parity][j] = max(dp[!parity][j], dp[parity][j-1]);
                if(s2[j-1] == s1[i]) dp[parity][j] = max(dp[parity][j], dp[!parity][j-1] + s1[i]);
            }
        }
        int sum = 0;
        for(auto c : s1) sum += c;
        for(auto c : s2) sum += c;
        return sum - 2*dp[!(len1&1)].back();
    }
};
```

but we can use two variables to maintain information, then we are done!

``` cpp
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        vector<int> dp(len2+1);
        for(int i = 0; i < len1; ++i) {
            int prev = 0;
            for(int j = 1; j <= len2; ++j) {
                int originVal = dp[j];
                dp[j] = max(dp[j], dp[j-1]);
                if(s2[j-1] == s1[i]) dp[j] = max(dp[j], prev + s1[i]);
                prev = originVal;
            }
        }
        int sum = 0;
        for(auto c : s1) sum += c;
        for(auto c : s2) sum += c;
        return sum - 2*dp.back();
    }
};
```

## Palindrome Partitioning

using DP and memorized result to determine palindrome, but get worse performance.

``` cpp
class Solution {
    int len;
    vector<vector<bool>> isPalindrome;
    
    void init(string &s) {
        len = s.length();
        isPalindrome.resize(len+1, vector<bool>(len+1));
        for(int i = 0; i < len; ++i) {
            isPalindrome[i][i] = true;
            isPalindrome[i][i+1] = true;
        }
        for(int i = 2; i <= len; ++i) {
            for(int j = 0; j+i <= len; ++j) {
                isPalindrome[j][j+i] = isPalindrome[j+1][j+i-1] && (s[j] == s[j+i-1]);
            }
        }
    }
    
    void dfs(vector<vector<string>> &answer, vector<string> &container, string &s, int index) {
        if(index == len) {
            answer.push_back(container);
        }
        for(int i = 1; index+i <= len; ++i) {
            if(isPalindrome[index][index+i]) {
                container.push_back(s.substr(index, i));
                dfs(answer, container, s, index+i);
                container.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        init(s);
        vector<vector<string>> answer;
        vector<string> container;
        dfs(answer, container, s, 0);
        return answer;
    }
};
```

# December LeetCoding Challenge 19

## Description

**Cherry Pickup II**

Given a `rows x cols` matrix `grid` representing a field of cherries. Each cell in `grid` represents the number of cherries that you can collect.

You have two robots that can collect cherries for you, Robot #1 is located at the top-left corner (0,0) , and Robot #2 is located at the top-right corner (0, cols-1) of the grid.

Return the maximum number of cherries collection using both robots by following the rules below:

- From a cell (i,j), robots can move to cell (i+1, j-1) , (i+1, j) or (i+1, j+1).
- When any robot is passing through a cell, It picks it up all cherries, and the cell becomes an empty cell (0).
- When both robots stay on the same cell, only one of them takes the cherries.
- Both robots cannot move outside of the grid at any moment.
- Both robots should reach the bottom row in the `grid`.

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2020/04/29/sample_1_1802.png)**

```
Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.
```

**Example 2:**

**![img](https://assets.leetcode.com/uploads/2020/04/23/sample_2_1802.png)**

```
Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
Output: 28
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
Total of cherries: 17 + 11 = 28.
```

**Example 3:**

```
Input: grid = [[1,0,0,3],[0,0,0,3],[0,0,3,3],[9,0,3,3]]
Output: 22
```

**Example 4:**

```
Input: grid = [[1,1],[1,1]]
Output: 4
```

**Constraints:**

- `rows == grid.length`
- `cols == grid[i].length`
- `2 <= rows, cols <= 70`
- `0 <= grid[i][j] <= 100 `

## Solution

BFS with optimization

``` cpp
class Solution {
    bool check(int pos, int cols) {
        return pos >= 0 && pos < cols;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> memo(rows, vector<vector<int>>(cols, vector<int>(cols)));
        // memo[row][robot1col][robot2col] = max cherries
        memo[0][0][cols-1] = grid[0].front() + grid[0].back();
        queue<tuple<int, int, int>> q;
        q.push(make_tuple(0, 0, cols-1));
        while(q.size()) {
            auto [row, pos1, pos2] = q.front();
            if(row == rows-1) break;
            q.pop();
            for(int i = -1; i <= 1; ++i) {
                for(int j = -1; j <= 1; ++j) {
                    int newPos1 = pos1 + i;
                    int newPos2 = pos2 + j;
                    if(check(newPos1, cols) && check(newPos2, cols)) {
                        if(!memo[row+1][newPos1][newPos2]) {
                            q.push(make_tuple(row+1, newPos1, newPos2));
                        }
                        int newVal = memo[row][pos1][pos2] + grid[row+1][newPos1] + grid[row+1][newPos2];
                        if(newPos2 == newPos1) newVal -= grid[row+1][newPos1];
                        memo[row+1][newPos1][newPos2] = max(memo[row+1][newPos1][newPos2], newVal);
                    }
                }
            }
        }
        int answer = 0;
        for(auto &pos2V : memo.back()) {
            for(auto result : pos2V) {
                answer = max(answer, result);
            }
        }
        return answer;
    }
};
```
