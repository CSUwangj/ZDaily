+++
title = "2020-10-17 Daily-Challenge"
path = "2020-10-17-Daily-Challenge"
date = 2020-10-17 13:48:44+08:00
updated = 2020-10-17 19:48:04+08:00
in_search_index = true

[taxonomies]
tags = ["Design", "Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [October LeetCoding Challenge](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3498/) with `cpp`.

BTW I decided to write solution directly on website rather than on VSCode when reviewing.

<!-- more -->

# LeetCode review

## Buddy Strings

rewrite it with any_of

``` cpp
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size())return false;
        vector<int> cnt(128);
        int pos = -1;
        for(int i = 0; i < A.size(); ++i) {
            cnt[A[i]] ++;
            if(A[i] != B[i] && pos == -1) {
                pos = i;
            } else if (A[i] != B[i]) {
                char temp = A[i];
                A[i] = A[pos];
                A[pos] = temp;
                return A == B;
            }
        }
        return pos==-1 && any_of(cnt.begin()+64, cnt.begin()+128, [](int a){return a>1;});
    }
};
```

## Subsets

dfs need more space for recursion, move parameters to class members will be helpful

``` cpp
class Solution {
    void dfs(vector<vector<int>>& answer, vector<int>& current, vector<int>& nums, int index){
        if(index == nums.size()) {
            answer.push_back(current);
            return;
        }
        dfs(answer, current, nums, index+1);
        current.push_back(nums[index]);
        dfs(answer, current, nums, index+1);
        current.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> tmp;
        dfs(answer, tmp, nums, 0);
        return answer;
    }
};
```

## Self Dividing Numbers

cpp20 has ranges, but can't use it yet...

``` cpp
class Solution {
    bool isSDN(int a) {
        int cur = a;
        while(cur) {
            if(!(cur%10) || a%(cur%10)) return false;
            cur /= 10;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        while(left <= right) {
            if(isSDN(left)) ans.push_back(left);
            left += 1;
        }
        return ans;
    }
};
```

## Data Stream as Disjoint Intervals

I need more practice

and this solution runs slower

``` cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size()-1);
        dp[0] = nums[0], dp[1] = max(nums[1], nums[0]);
        for(int i = 2; i < nums.size()-1; ++i){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        int ans = dp[nums.size()-2];
        dp[0] = nums[1], dp[1] = max(nums[1], nums[2]);
        for(int i = 3; i < nums.size(); ++i) {
            dp[i-1] = max(dp[i-2], dp[i-3]+nums[i]);
        }
        return max(ans, dp[nums.size()-2]);
    }
};
```

## Path Sum III

use recursive way to write it. 

``` cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int sum;
    int ans;
    void dfs(TreeNode* root, int cur, bool inPath) {
        if(!root) return;
        if(cur == root->val) ans += 1;
        if(!inPath) {
            dfs(root->left, cur, false);
            dfs(root->right, cur, false);
        }
        dfs(root->left, cur-root->val, true);
        dfs(root->right, cur-root->val, true);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        this->sum = sum;
        dfs(root, sum, false);
        return ans;
    }
};
```

## Rotate Array

using reverse to rotate, what a trick

``` cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
```

## Count Negative Numbers in a Sorted Matrix

``` cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), cur = col-1;
        int ans = 0;
        for(int i = 0; i < row; ++i) {
            int j = cur;
            while(j >= 0) {
                if(grid[i][j] < 0) {
                    ans += row - i;
                } else {
                    cur = j;
                    break;
                }
                j -= 1;
            }
            if(j == -1) break;
        }
        return ans;
    }
};
```

## Search a 2D Matrix

can not use `binary_search` directly

``` cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size() || !matrix[0].size()) return false;
        int begin = 0, end = matrix.size()-1;
        vector<int> &a = matrix[0];
        while(begin < end) {
            int mid = (begin + end) / 2;
            cout << matrix[mid].front() << endl;
            if(matrix[mid].front() > target) {
                end = mid - 1;
            } else if (matrix[mid].back() < target) {
                begin = mid + 1;
            } else {
                break;
            }
        }
        a = matrix[(begin+end)/2];
        return binary_search(a.begin(), a.end(), target);
    }
};
```

# October LeetCoding Challenge16

**Repeated DNA Sequences**

All DNA is composed of a series of nucleotides abbreviated as `'A'`, `'C'`, `'G'`, and `'T'`, for example: `"ACGAATTCCG"`. When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

**Example 1:**

```
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
```

**Example 2:**

```
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
```

**Constraints:**

- `0 <= s.length <= 105`
- `s[i]` is `'A'`, `'C'`, `'G'`, or `'T'`.

## Solution

enumerate all permutations will exhaust all time, but enumerate positions of pattern won't.

``` cpp
class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;
    if(s.size() <= 10) return ans;
    map<string, int> mp;
    for(auto it = s.begin(), ite = it+10; ite != s.end(); ++it, ++ite) {
      string news(it,ite);
      mp[news] += 1;
    }
    string news(s.end()-10, s.end());
    mp[news] += 1;
    for(auto it : mp) {
      if(it.second > 1) {
        ans.push_back(it.first);
      }
    }
    return ans;
  }
};
```