+++
updated = 2023-05-29T11:10:14+08:00
title = "2023-05-29 Daily Challenge"
path = "2023-05-29-Daily-Challenge"
date = 2023-05-29T11:10:14+08:00

[taxonomies]
tags = ["Algorithm"]
categories = ["DailyChallenge"]
archives = ["archive"]
+++

Today I have done leetcode's [May LeetCoding Challenge](https://leetcode.com/problems/design-parking-system/) with `cpp`.

<!-- more -->

# May LeetCoding Challenge 29

## Description

**Design Parking System**

<p>Design a parking system for a parking lot. The parking lot has three kinds of parking spaces: big, medium, and small, with a fixed number of slots for each size.</p>

<p>Implement the <code>ParkingSystem</code> class:</p>

<ul>
	<li><code>ParkingSystem(int big, int medium, int small)</code> Initializes object of the <code>ParkingSystem</code> class. The number of slots for each parking space are given as part of the constructor.</li>
	<li><code>bool addCar(int carType)</code> Checks whether there is a parking space of <code>carType</code> for the car that wants to get into the parking lot. <code>carType</code> can be of three kinds: big, medium, or small, which are represented by <code>1</code>, <code>2</code>, and <code>3</code> respectively. <strong>A car can only park in a parking space of its </strong><code>carType</code>. If there is no space available, return <code>false</code>, else park the car in that size space and return <code>true</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;ParkingSystem&quot;, &quot;addCar&quot;, &quot;addCar&quot;, &quot;addCar&quot;, &quot;addCar&quot;]
[[1, 1, 0], [1], [2], [3], [1]]
<strong>Output</strong>
[null, true, true, false, false]

<strong>Explanation</strong>
ParkingSystem parkingSystem = new ParkingSystem(1, 1, 0);
parkingSystem.addCar(1); // return true because there is 1 available slot for a big car
parkingSystem.addCar(2); // return true because there is 1 available slot for a medium car
parkingSystem.addCar(3); // return false because there is no available slot for a small car
parkingSystem.addCar(1); // return false because there is no available slot for a big car. It is already occupied.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= big, medium, small &lt;= 1000</code></li>
	<li><code>carType</code> is <code>1</code>, <code>2</code>, or <code>3</code></li>
	<li>At most <code>1000</code> calls will be made to <code>addCar</code></li>
</ul>


## Solution

``` cpp
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class ParkingSystem {
  int parkingLot[4];
public:
  ParkingSystem(int big, int medium, int small) {
    parkingLot[1] = big;
    parkingLot[2] = medium;
    parkingLot[3] = small;
  }
  
  bool addCar(int carType) {
    if(!parkingLot[carType]) return false;
    parkingLot[carType] -= 1;
    return true;
  }
};

// Accepted
// 102/102 cases passed (46 ms)
// Your runtime beats 99.19 % of cpp submissions
// Your memory usage beats 99.71 % of cpp submissions (32.9 MB)
```
