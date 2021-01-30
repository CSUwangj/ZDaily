+++
title = "2021-01-30 Daily-Challenge"
path = "2021-01-30-Daily-Challenge"
date = 2021-01-30 12:32:33+08:00
updated = 2021-01-30 23:31:13+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is Saturday, I gonna review the tasks I've done this week, and finish today's leetcode's [January LeetCoding Challenge](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/583/week-5-january-29th-january-31st/3622/) with `cpp`.

<!-- more -->

# LeetCode Review

## Check If All 1's Are at Least Length K Places Away

too easy to review

## Path With Minimum Effort

too easy to review

## Concatenation of Consecutive Binary Numbers

using math relations in binary representation, check [explanation by DBabichev](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3618/discuss/1037323/Python-O(n)-and-O(log2-n)-fast-and-short-explained) for more

``` cpp
class Solution {
    const long long MOD = 1e9+7;
    long long pow(long long base, long long exp) {
        long long res = 1;
        while(exp) {
            if(exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
    vector<int> getB(int n, int len) {
        vector<int> result;
        for(int i = 0; i < len; ++i) result.push_back(1 << i);
        int rest = n - (1 << len) + 1;
        for(int i = len; i >= 0; --i) {
            if((rest & (1 << i))) result.push_back(1 << i);
        }
        return move(result);
    }
public:
    int concatenatedBinary(int n) {
        if(n == 1) return 1;
        int blen = log2(n) + 1;
        
        vector<int> B = getB(n, blen-1);
        int len = B.size();
        vector<int> A(len);
        vector<int> C(len);
        vector<int> D(len);
        for(int i = 1; i < blen; ++i) C[i-1] = i;
        for(int i = blen-1; i < len; ++i) C[i] = blen;
        for(int i = 1; i < len; ++i) D[len-i-1] = D[len-i] + C[len-i]*B[len-i];
        A[0] = B[0];
        for(int i = 1; i < len; ++i) A[i] = B[i] + A[i-1];
        long long answer = 0;
        for(int i = 0; i < len; ++i) {
            long long t1 = pow(2LL, B[i]*C[i]) - 1;
            long long t2 = pow(pow(2LL, C[i])-1, MOD-2);
            long long t3 = ((A[i]-B[i]+1+t2)*t1-B[i]) % MOD;
            answer += t2 * t3 % MOD * pow(2LL, D[i]);
            answer %= MOD;
        }
        return answer;
    }
};
```

## Smallest String With A Given Numeric Value

too easy to review

## Vertical Order Traversal of a Binary Tree

too easy to review

## Circular Array Loop

slow/fast pointer

``` cpp
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; ++i) if(nums[i] % len == 0) nums[i] = 0;
        for(int i = 0; i < len; ++i) {
            if(!nums[i]) continue;
            bool positive = nums[i] > 0;
            int slow = i, fast = i;
            bool back = false;
            do {
                if(!nums[fast] || ((nums[fast] > 0) != positive)) {
                    back = true;
                    break;
                }
                fast += nums[fast];
                fast = ((fast % len) + len) % len;
                if(!nums[fast] || ((nums[fast] > 0) != positive)) {
                    back = true;
                    break;
                }
                fast += nums[fast];
                fast = ((fast % len) + len) % len;
                slow += nums[slow];
                slow = ((slow % len) + len) % len;
            } while(slow != fast);
            // cout << i << ' ' << slow << ' ' << fast << endl;
            if(!back) return true;
            int cur = i, nxt;
            while(nums[cur] && (nums[cur] > 0) == positive) {
                nxt = cur + nums[cur];
                nxt = ((nxt % len) + len) % len;
                nums[cur] = 0;
                cur = nxt;
            }
        }
        return false;
    }
};
```

## Letter Tile Possibilities

``` cpp
class Solution {
    int permutation[8] = {1, 1, 2, 6, 24, 120, 720, 5040};
    int answer = 0;
    map<char, int> mp;
    
    int result(vector<int> &chars, int len) {
        int res = permutation[len];
        for(auto cnt : chars) res /= permutation[cnt];
        return res;
    }
    
    void helper(map<char, int>::iterator &it, vector<int> chars, int len, int count) {
        if(it == mp.end()) {
            if(count == len) answer += result(chars, len);
            return;
        }
        
        for(int i = 0; i <= it->second; ++i) {
            chars.push_back(i);
            ++it;
            helper(it, chars, len, count + i);
            --it;
            chars.pop_back();
        }
    }
public:
    int numTilePossibilities(string tiles) {
        for(auto c : tiles) mp[c] += 1;
        vector<int> tmp;
        auto tmpIt = mp.begin();
        for(int i = 1; i <= tiles.length(); ++i) {
            helper(tmpIt, tmp, i, 0);
        }
        return answer;
    }
};
```

## Convert Sorted List to Binary Search Tree

inorder traversal simulation

``` cpp
class Solution {
    ListNode *cur;
    
    int length(ListNode *head) {
        int len = 0;
        while(head) {
            len += 1;
            head = head->next;
        }
        return len;
    }
    
    TreeNode *buildBST(int begin, int end) {
        if(begin > end) return nullptr;
        
        int mid = (begin + end) >> 1;
        TreeNode *left = buildBST(begin, mid - 1);
        
        TreeNode *root = new TreeNode(cur->val);
        root->left = left;
        
        cur = cur->next;
        root->right = buildBST(mid + 1, end);
        
        return root;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = length(head);
        cur = head;
        return buildBST(0, len-1);
    }
};
```

## Sum of Distances in Tree

``` cpp
class Solution {
    vector<int> dp, children, answer;
    vector<vector<int>> neighbors;
    
    void init(int N, vector<vector<int>>& edges) {
        dp.resize(N);
        children.resize(N, 1);
        answer.resize(N);
        neighbors.resize(N);
        
        for(auto &edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }
    }
    
    void initDP(int current, int parent) {
        for(auto neighbor : neighbors[current]) {
            if(neighbor == parent) continue;
            
            initDP(neighbor, current);
            children[current] += children[neighbor];
            dp[current] += children[neighbor] + dp[neighbor];
        }
    }
    
    void swapRootDP(int current, int parent) {
        answer[current] = dp[current];
        
        for(auto neighbor : neighbors[current]) {
            if(neighbor == parent) continue;
            
            dp[current] -= children[neighbor] + dp[neighbor];
            children[current] -= children[neighbor];
            dp[neighbor] += dp[current] + children[current];
            children[neighbor] += children[current];
            
            swapRootDP(neighbor, current);
            dp[neighbor] -= dp[current] + children[current];
            children[neighbor] -= children[current];
            dp[current] += children[neighbor] + dp[neighbor];
            children[current] += children[neighbor];
        }
    }
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        init(N, edges);
        initDP(0, -1);
        swapRootDP(0, -1);
        return move(answer);
    }
};
```

## Rank Teams by Votes

too easy to review

## Integer to Roman

too easy to review

## Water and Jug Problem

too easy to review

## Jump Game V

once found it was a topological sort problem, it's easy.

## Find Longest Awesome Substring

``` cpp
class Solution {
public:
    int longestAwesome(string s) {
        int len = s.length();
        vector<int> dp(1024, len+1);
        dp[0] = -1;
        int answer = 1;
        int current = 0;
        for(int i = 0; i < len; ++i) {
            current ^= 1 << (s[i] - '0');
            if(i < dp[current]) dp[current] = i;
            else answer = max(answer, i-dp[current]);
            for(int j = 0; j < 10; ++j) {
                answer = max(answer, i-dp[current^(1<<j)]);
            }
        }
        return answer;
    }
};
```

## Max Sum of Rectangle No Larger Than K

``` cpp
class Solution {
    vector<vector<int>> prefix;
    int rows;
    int cols;
    
    void init(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix.front().size();
        prefix.resize(rows+1, vector<int>(cols+1));
        
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                prefix[i+1][j+1] = matrix[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
            }
        }
    }
    
    int sum(int left, int right, int up, int down) {
        return prefix[down][right] - prefix[down][left] - prefix[up][right] + prefix[up][left];
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int target) {
        init(matrix);
        
        int answer = INT_MIN;
        for(int i = 0; i < cols; ++i) {
            for(int j = i+1; j <= cols; ++j) {
                vector<int> arr{0};
                for(int k = 1; k <= rows; ++k) {
                    int s = sum(i, j, 0, k);
                    auto it = lower_bound(arr.begin(), arr.end(), s - target);
                    if(it != arr.end()) {
                        answer = max(answer, s - *it);
                    };
                    arr.insert(lower_bound(arr.begin(), arr.end(), s), s);
                }
            }
        }
        
        return answer;
    }
};
```

## Implement Magic Dictionary

too easy to review

## Possible Bipartition

``` cpp
class Solution {
    vector<vector<int>> dislike;
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikePairs) {
        dislike.resize(N+1);
        
        for(auto &pair : dislikePairs) {
            dislike[pair[0]].push_back(pair[1]);
            dislike[pair[1]].push_back(pair[0]);
        }
        
        vector<int> group(N+1, -1);
        while(true) {
            queue<int> q;
            for(int i = 1; i <= N; ++i) {
                if(group[i] == -1) {
                    q.push(i);
                    group[i] = 0;
                    break;
                }
            }
            if(q.empty()) break;
            while(!q.empty()) {
                int current = q.front();
                q.pop();
                for(auto dis : dislike[current]) {
                    if(group[dis] != -1 && group[dis] == group[current]) return false;
                    if(group[dis] == -1) q.push(dis);
                    group[dis] = group[current] ^ 1;
                }
            }
        }
        return true;
    }
};
```

## Largest Component Size by Common Factor

``` cpp
class Solution {
    unordered_map<int, int> parent, count;
    
    int find(int x) {
        if(!parent.count(x)) parent[x] = x;
        else if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        parent[x] = y;
    }
public:
    int largestComponentSize(vector<int>& A) {
        for(auto num : A) {
            for(int i = 2; i*i <= num; ++i) {
                if(num % i == 0) {
                    merge(num, i);
                    merge(num, num / i);
                }
            }
        }
        int answer = 0;
        for(auto i : A) answer = max(answer, ++count[find(i)]);
        return answer;
    }
};
```

# January LeetCoding Challenge30

**Minimize Deviation in Array**

## Description

You are given an array `nums` of `n` positive integers.

You can perform two types of operations on any element of the array any number of times:

- If the element is **even**, **divide** it by `2`.
  - For example, if the array is `[1,2,3,4]`, then you can do this operation on the last element, and the array will be `[1,2,3,2].`
- If the element is **odd**, **multiply** it by `2`.
  - For example, if the array is `[1,2,3,4]`, then you can do this operation on the first element, and the array will be `[2,2,3,4].`

The **deviation** of the array is the **maximum difference** between any two elements in the array.

Return *the **minimum deviation** the array can have after performing some number of operations.*

 

**Example 1:**

```
Input: nums = [1,2,3,4]
Output: 1
Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.
```

**Example 2:**

```
Input: nums = [4,1,5,20,3]
Output: 3
Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.
```

**Example 3:**

```
Input: nums = [2,10,8]
Output: 3
```

 

**Constraints:**

- `n == nums.length`
- `2 <= n <= 105`
- `1 <= nums[i] <= 109`

## Solution

solution is fucking amazing!

``` cpp
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for(auto i : nums) s.insert((i&1) ? (i<<1) : i);
        
        int answer = *s.rbegin() - *s.begin();
        while((*s.rbegin() & 1) == 0) {
            s.insert(*s.rbegin() >> 1);
            s.erase(*s.rbegin());
            answer = min(answer, *s.rbegin() - *s.begin());
        }
        
        return answer;
    }
};
```