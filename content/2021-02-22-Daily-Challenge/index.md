+++
title = "2021-02-22 Daily-Challenge"
path = "2021-02-22-Daily-Challenge"
date = 2021-02-22 20:23:09+08:00
updated = 2021-02-19 21:28:01+08:00
in_search_index = true

[taxonomies]
tags = ["Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today I have done [Dungeon Game](https://leetcode.com/problems/dungeon-game/) and leetcode's [February LeetCoding Challenge](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3649/) with `cpp`.

<!-- more -->

# Dungeon Game

## Description

The demons had captured the princess (**P**) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (**K**) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (*negative* integers) upon entering these rooms; other rooms are either empty (*0's*) or contain magic orbs that increase the knight's health (*positive* integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

 

**Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.**

For example, given the dungeon below, the initial health of the knight must be at least **7** if he follows the optimal path `RIGHT-> RIGHT -> DOWN -> DOWN`.

<table class="dungeon">
	<tbody>
		<tr>
			<td>-2 (K)</td>
			<td>-3</td>
			<td>3</td>
		</tr>
		<tr>
			<td>-5</td>
			<td>-10</td>
			<td>1</td>
		</tr>
		<tr>
			<td>10</td>
			<td>30</td>
			<td>-5 (P)</td>
		</tr>
	</tbody>
</table>
 

**Note:**

- The knight's health has no upper bound.
- Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

## Solution

think directly is hard, because higher HP doesn't means higher minimum HP, think about the dungeon below

<table class="dungeon">
	<tbody>
		<tr>
			<td>0 (K)</td>
			<td>-3</td>
		</tr>
		<tr>
			<td>-5</td>
			<td>5</td>
		</tr>
		<tr>
			<td>10</td>
			<td>30 (P)</td>
		</tr>
	</tbody>
</table>

0 -> -5 -> 10 -> 30 will get higher HP, but requires King with 6 initial HP. 0 -> -3 -> 5 -> 30 only needs 4 initial HP.

but there is still a solution, we can check if a initial HP is enough for pass through the dungeon with simple DP, then we can use binary search to find minimum initial HP.

``` cpp
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int maxHP = 1;
        for(auto &rows : dungeon) for(auto h : rows) if(h < 0) maxHP -= h;
        int minHP = 1;
        int rows = dungeon.size();
        int cols = dungeon.front().size();
        while(minHP < maxHP) {
            int middle = ((minHP + maxHP) >> 1);
            vector<vector<int>> dp = dungeon;
            dp[0][0] += middle;
            for(int i = 0; i < rows; ++i) {
                for(int j = 0; j < cols; ++j) {
                    if(!i && !j) continue;
                    int val = -1;
                    if(i && dp[i-1][j] > 0 && dp[i][j] + dp[i-1][j] > 0) {
                        val = max(val, dp[i][j] + dp[i-1][j]);
                    }
                    if(j && dp[i][j-1] > 0 && dp[i][j] + dp[i][j-1] > 0) {
                        val = max(val, dp[i][j] + dp[i][j-1]);
                    }
                    dp[i][j] = val;
                }
            }
            if(dp.back().back() <= 0) {
                minHP = middle + 1;
            } else {
                maxHP = middle;
            }
        }
        return minHP;
    }
};
```

BTW if think backforward, problem is just a simple DP...

# February LeetCoding Challenge22

**Longest Word in Dictionary through Deleting**

## Description

Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

**Example 1:**

```
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
```





**Example 2:**

```
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
```



**Note:**

1. All the strings in the input will only contain lower-case letters.
2. The size of the dictionary won't exceed 1,000.
3. The length of all the strings in the input won't exceed 1,000.

## Solution

``` cpp
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        unordered_map<int, int> pos;
        int len = 0;
        int position = -1;
        for(int i = 0; i < d.size(); ++i) {
            if(d[i].length()) pos[i] = 0;
        }
        vector<int> toClear;
        for(auto c : s) {
            toClear.clear();
            // cout << c << ": ";
            for(auto &[index, offset] : pos) {
                // cout << " " << index << ' '<< offset<<'|';
                if(c != d[index][offset]) continue;
                offset += 1;
                if(offset == d[index].length()) toClear.push_back(index);
            }
            for(auto toC : toClear) {
                pos.erase(toC);
                if(d[toC].length() < len || (d[toC].length() == len && d[toC] > d[position])) continue; 
                len = d[toC].length();
                position = toC;
            }
            // cout<< endl;
        }
        return position == -1 ? "" : d[position];
    }
};
```