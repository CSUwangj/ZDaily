+++
title = "2019-03-02 Daily Challenge"
path = "2019-03-02-daily-challenge"
date = 2019-03-02T12:38:25+00:00
updated = 2020-09-19T20:01:27.633312+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Valid Braces* in *JavaScript*.
<!-- more -->

# CodeWars

## Problem

### Valid Braces

Write a function that takes a string of braces, and determines if the order of the braces is valid. It should return `true` if the string is valid, and `false` if it's invalid.

This Kata is similar to the [Valid Parentheses](https://www.codewars.com/kata/valid-parentheses) Kata, but introduces new characters: brackets `[]`, and curly braces `{}`. Thanks to `@arnedag` for the idea!

All input strings will be nonempty, and will only consist of parentheses, brackets and curly braces: `()[]{}`.

### What is considered Valid?

A string of braces is considered valid if all braces are matched with the correct brace.

## Examples

```py
"(){}[]"   =>  True
"([{}])"   =>  True
"(}"       =>  False
"[(])"     =>  False
"[({})](]" =>  False
```

## Solution

```js
function validBraces(braces){
  let stack = [];
  for (let i = 0; i < braces.length; ++i) {
    if (braces[i] === "(" || braces[i] === "[" || braces[i] === "{") {
      stack.push(braces[i]);
    } else {
      if (!stack.length) return false;
      if (braces[i] === ")") {
        if (stack[stack.length-1] !== "(") return false;
        stack.pop();
      } else if (braces[i] === "]") {
        if (stack[stack.length-1] !== "[") return false;
        stack.pop();
      } else {
        if (stack[stack.length-1] !== "{") return false;
        stack.pop();
      } 
    }
  }
  return !stack.length;
}

function validBraces(braces){
  let matches = { '(':')', '{':'}', '[':']' };
  let stack = [];
  for (let i = 0; i < braces.length; i++) {
    let currentChar = braces[i];
    if (matches[currentChar]) stack.push(currentChar);
    else if (currentChar !== matches[stack.pop()]) return false;
  }
  return stack.length === 0; 
}

function validBraces(braces){
  while(/\(\)|\[\]|\{\}/g.test(braces)){braces = braces.replace(/\(\)|\[\]|\{\}/g,"")}
  return !braces.length;
 }
```