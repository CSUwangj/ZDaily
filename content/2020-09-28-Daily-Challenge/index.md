+++
title = "2020-09-28 Daily-Challenge"
path = "2020-09-28-Daily-Challenge"
date = 2020-09-28
updated = 2020-09-28T22:46:35+08:00
in_search_index = true

[taxonomies]
tags = ["Design", "Algorithm"]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++

Today is an example of *The non-Designer's Design Book* on Page 40-41 and *Probability of a Two Boxes Having The Same Number of Distinct Balls* on leetcode with `cpp`.

<!-- more -->

# The non-Designer's Design Book

my answer:
  - [F] use more prominent font for sub title
  - [T] enlarge the logo so it aligns with the title vertically both on top and bottom
  - [T] use same font color for subtitle
  - [T] move welcome message and date information so it aligns with main text both on right and left
  - [T] change picture color to the same color as subtitle
  - [T] remove indent of first paragraph

# Probability of a Two Boxes Having The Same Number of Distinct Balls

## Description

Given 2n balls of k distinct colors. You will be given an integer array balls of size k where balls[i] is the number of balls of color i. 

All the balls will be shuffled uniformly at random, then we will distribute the first n balls to the first box and the remaining n balls to the other box (Please read the explanation of the second example carefully).

Please note that the two boxes are considered different. For example, if we have two balls of colors a and b, and two boxes [] and (), then the distribution [a] (b) is considered different than the distribution [b] (a) (Please read the explanation of the first example carefully).

We want to calculate the probability that the two boxes have the same number of distinct balls.

**Example 1:**

```
Input: balls = [1,1]
Output: 1.00000
Explanation: Only 2 ways to divide the balls equally:
- A ball of color 1 to box 1 and a ball of color 2 to box 2
- A ball of color 2 to box 1 and a ball of color 1 to box 2
In both ways, the number of distinct colors in each box is equal. The probability is 2/2 = 1
```

**Example 2:**

```
Input: balls = [2,1,1]
Output: 0.66667
Explanation: We have the set of balls [1, 1, 2, 3]
This set of balls will be shuffled randomly and we may have one of the 12 distinct shuffles with equale probability (i.e. 1/12):
[1,1 / 2,3], [1,1 / 3,2], [1,2 / 1,3], [1,2 / 3,1], [1,3 / 1,2], [1,3 / 2,1], [2,1 / 1,3], [2,1 / 3,1], [2,3 / 1,1], [3,1 / 1,2], [3,1 / 2,1], [3,2 / 1,1]
After that we add the first two balls to the first box and the second two balls to the second box.
We can see that 8 of these 12 possible random distributions have the same number of distinct colors of balls in each box.
Probability is 8/12 = 0.66667
```

**Example 3:**

```
Input: balls = [1,2,1,2]
Output: 0.60000
Explanation: The set of balls is [1, 2, 2, 3, 4, 4]. It is hard to display all the 180 possible random shuffles of this set but it is easy to check that 108 of them will have the same number of distinct colors in each box.
Probability = 108 / 180 = 0.6
```

**Example 4:**

```
Input: balls = [3,2,1]
Output: 0.30000
Explanation: The set of balls is [1, 1, 1, 2, 2, 3]. It is hard to display all the 60 possible random shuffles of this set but it is easy to check that 18 of them will have the same number of distinct colors in each box.
Probability = 18 / 60 = 0.3
```

**Example 5:**

```
Input: balls = [6,6,6,6,6,6]
Output: 0.90327
```

**Constraints:**

- `1 <= balls.length <= 8`
- `1 <= balls[i] <= 6`
- `sum(balls)` is even.
- Answers within `10^-5` of the actual value will be accepted as correct.

## Solution

First, the answer is 

$$\frac{\Sigma(ways\ of\ pick\ left\ side\ balls) \times(permutations\ ways\ of\ left\ side)\times (permutations\ ways\ of\ right\ side)}{ways\ of\ all\ permutations}$$

where 

$$(ways\ of\ pick\ left\ side\ balls)=\Pi(ways\ of\ pick\ each\ color)$$

For example, example 2 with balls `[2, 1, 1]`, the answer is 

$$\frac{(ways\ of\ pick\ [1, 2])\times A_2^1 \times A_2^1+(ways\ of\ pick\ [1, 3])\times A_2^1 \times A_2^1}{A_4^4}$$

which becomes 

$$\frac{(C_2^1\times C_1^1)\times A_2^1 \times A_2^1+(C_2^1\times C_1^1)\times A_2^1 \times A_2^1}{A_4^4}$$

and the permutations is always multiplied, so first formula can be written as

$$\frac{\Sigma(ways\ of\ pick\ left\ side\ balls)}{(\frac{ways\ of\ all\ permutations}{(permutations\ ways\ of\ left\ side)\times (permutations\ ways\ of\ right\ side)})}$$

the only problem is to find ways of pick left side balls where numbers of color of left side is equal to the right side. We can solve this problem by DFS, and here is my shitty code:

``` cpp
class Solution {
  public:

  int left_color;
  int right_color;
  int min_color;
  int max_color;
  int balls_used;
  int balls_left;
  int number_of_balls;
  int number_of_colors;
  long long answer;
  long long c[50][50];
  vector < int > ball;

  void dfs(long long cur, int idx) {
    if (idx == number_of_colors) {
      if (left_color == right_color) {
        answer += cur;
      }
      return;
    }
    int minballs = max(number_of_balls / 2 - (balls_used + balls_left - ball[idx]), 0);
    int maxballs = min(number_of_balls / 2 - balls_used, ball[idx]);
    for (int i = minballs; i <= maxballs; i++) {
      balls_left -= ball[idx];
      balls_used += i;
      if (i == 0 && left_color <= max_color) {
        dfs(cur, idx + 1);
      } else if (i && i < ball[idx] && left_color < max_color) {
        left_color += 1;
        const long long new_cur = cur * c[ball[idx]][i];
        dfs(new_cur, idx + 1);
        left_color -= 1;
      } else if (i == ball[idx] && left_color < max_color && right_color > min_color) {
        left_color += 1;
        right_color -= 1;
        dfs(cur, idx + 1);
        right_color += 1;
        left_color -= 1;
      }
      balls_left += ball[idx];
      balls_used -= i;
    }
  }

  void init() {
    for (int i = 1; i < 50; i++) {
      c[i][i] = 1;
      c[i][0] = 1;
      for (int j = 1; j < i; ++j) {
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
      }
    }
  }

  void round_init() {
    number_of_colors = ball.size();
    number_of_balls = 0;
    int one = 0;
    for (int i = 0; i < number_of_colors; ++i) {
      if (ball[i] == 1) {
        one += 1;
      }
      number_of_balls += ball[i];
    }
    balls_left = number_of_balls;
    min_color = (number_of_colors + 1) / 2;
    max_color = number_of_colors - (one + 1) / 2;
    right_color = number_of_colors;
    left_color = 0;
    balls_used = 0;
    answer = 0;
  }

  double getProbability(vector < int > & balls) {
    ball = balls;
    init();
    round_init();
    dfs(1, 0);
    return 1.0 * answer / c[number_of_balls][number_of_balls / 2];
  }
};
```