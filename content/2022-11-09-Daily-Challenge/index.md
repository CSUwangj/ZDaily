+++
updated = 2022-11-09T13:11:05+08:00
title = "2022-11-09 Daily Challenge"
path = "2022-11-09-Daily-Challenge"
date = 2022-11-09T13:11:05+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [November LeetCoding Challenge](https://leetcode.com/problems/online-stock-span/) with `cpp`.

<!-- more -->

# November LeetCoding Challenge 9

## Description

**Online Stock Span**

<p>Design an algorithm that collects daily price quotes for some stock and returns <strong>the span</strong> of that stock&#39;s price for the current day.</p>

<p>The <strong>span</strong> of the stock&#39;s price today is defined as the maximum number of consecutive days (starting from today and going backward) for which the stock price was less than or equal to today&#39;s price.</p>

<ul>
	<li>For example, if the price of a stock over the next <code>7</code> days were <code>[100,80,60,70,60,75,85]</code>, then the stock spans would be <code>[1,1,1,2,1,4,6]</code>.</li>
</ul>

<p>Implement the <code>StockSpanner</code> class:</p>

<ul>
	<li><code>StockSpanner()</code> Initializes the object of the class.</li>
	<li><code>int next(int price)</code> Returns the <strong>span</strong> of the stock&#39;s price given that today&#39;s price is <code>price</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;StockSpanner&quot;, &quot;next&quot;, &quot;next&quot;, &quot;next&quot;, &quot;next&quot;, &quot;next&quot;, &quot;next&quot;, &quot;next&quot;]
[[], [100], [80], [60], [70], [60], [75], [85]]
<strong>Output</strong>
[null, 1, 1, 1, 2, 1, 4, 6]

<strong>Explanation</strong>
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today&#39;s price of 75) were less than or equal to today&#39;s price.
stockSpanner.next(85);  // return 6
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= price &lt;= 10<sup>5</sup></code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>next</code>.</li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class StockSpanner {
  vector<pair<int, int>> container;
public:
  StockSpanner() { }
    
  int next(int price) {
    if(container.empty() || container.back().first > price) {
      container.push_back({price, 1});
    } else {
      container.back().first = price;
      container.back().second += 1;
      while(container.size() > 1 && container.back().first >= container[container.size() - 2].first) {
        // cout << container.back().first << ' ' << container.back().second << endl;
        container[container.size() - 2].first = container.back().first;
        container[container.size() - 2].second += container.back().second;
        container.pop_back();
      }
    }
    return container.back().second;
  }
};

// Accepted
// 99/99 cases passed (318 ms)
// Your runtime beats 77.79 % of cpp submissions
// Your memory usage beats 98.88 % of cpp submissions (84.1 MB)
```
