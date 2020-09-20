+++
title = "2019-03-18 Daily Challenge"
path = "2019-03-18-daily-challenge"
date = 2019-03-18T19:18:45+00:00
updated = 2020-09-19T20:01:27.638299+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Binary multiple of 3* in *JavaScript*.

FSM is interesting!

<!-- more -->

# CodeWars

## Problem

### Binary multiple of 3

In this kata, your task is to create a regular expression capable of evaluating binary strings (strings with only `1`s and `0`s) and determining whether the given string represents a number divisible by 3.

Take into account that:

- An empty string *might* be evaluated to true (it's not going to be tested, so you don't need to worry about it - unless you want)
- The input should consist only of binary digits - no spaces, other digits, alphanumeric characters, etc.
- There might be leading `0`s.

### Examples (Javascript)

- `multipleof3Regex.test('000')` should be `true`
- `multipleof3Regex.test('001')` should be `false`
- `multipleof3Regex.test('011')` should be `true`
- `multipleof3Regex.test('110')` should be `true`
- `multipleof3Regex.test(' abc ')` should be `false`

You can check more in the example test cases

### Note

There's a way to develop an automata (FSM) that evaluates if strings representing numbers in a given base are divisible by a given number. You might want to check an example of an automata for doing this same particular task [here](http://math.stackexchange.com/questions/140283/why-does-this-fsm-accept-binary-numbers-divisible-by-three).

If you want to understand better the inner principles behind it, you might want to study how to get the modulo of an arbitrarily large number taking one digit at a time.

## Solution

All you need to do is to build a Finite-state machine.

If you've learned CP, you'll know that regular expression is same as DFA(If I don't get it wrong).

Also, here is an [interesting website](http://ivanzuzak.info/noam/webapps/fsm_simulator/) for regular expression.

```js
var multipleOf3Regex = /^(0*(1(1|(01*0)+1))*)*$/;
```