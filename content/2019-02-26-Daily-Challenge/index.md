+++
title = "2019-02-26 Daily Challenge"
path = "2019-02-26-daily-challenge"
date = 2019-02-26T00:01:36+00:00
updated = 2020-09-19T20:01:27.631316+00:00
description = "DailyChallenge"
in_search_index = true

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Vowel Count* in *JavaScript*.

<!--more-->

# CodeWars

## Problem

### Vowel Count

Return the number (count) of vowels in the given string.

We will consider a, e, i, o, and u as vowels for this Kata.

The input string will only consist of lower case letters and/or spaces.

## Solution

```js
function getCount(str) {
  return (str.match(/[aeiou]/gi)||[]).length;
}

function getCount(str) {
  return str.replace(/[^aeiou]/gi, "").length;
}

```