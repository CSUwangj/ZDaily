+++
title = "2019-03-03 Daily Challenge"
path = "2019-03-03-daily-challenge"
date = 2019-03-03T00:28:53+00:00
updated = 2020-09-19T20:01:27.633312+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Directions Reduction* in *JavaScript*.
<!-- more -->

# CodeWars

## Problem

### Directions Reduction

##### Once upon a time, on a way through the old wild west,…

… a man was given directions to go from one point to another. The directions were "NORTH", "SOUTH", "WEST", "EAST". Clearly "NORTH" and "SOUTH" are opposite, "WEST" and "EAST" too. Going to one direction and coming back the opposite direction is a needless effort. Since this is the wild west, with dreadfull weather and not much water, it's important to save yourself some energy, otherwise you might die of thirst!

##### How I crossed the desert the smart way.

The directions given to the man are, for example, the following:

```
["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"].
```

or

```
{ "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" };
```

or (haskell)

```
[North, South, South, East, West, North, West]
```

You can immediatly see that going "NORTH" and then "SOUTH" is not reasonable, better stay to the same place! So the task is to give to the man a simplified version of the plan. A better plan in this case is simply:

```
["WEST"]
```

or

```
{ "WEST" }
```

or (haskell)

```
[West]
```

or (rust)

```
[WEST];
```

#### Other examples:

In `["NORTH", "SOUTH", "EAST", "WEST"]`, the direction `"NORTH" + "SOUTH"` is going north and coming back *right away*. What a waste of time! Better to do nothing.

The path becomes `["EAST", "WEST"]`, now `"EAST"` and `"WEST"` annihilate each other, therefore, the final result is `[]` (nil in Clojure).

In ["NORTH", "EAST", "WEST", "SOUTH", "WEST", "WEST"], "NORTH" and "SOUTH" are not directly opposite but they become directly opposite after the reduction of "EAST" and "WEST" so the whole path is reducible to ["WEST", "WEST"].

#### Task

Write a function `dirReduc` which will take an array of strings and returns an array of strings with the needless directions removed (W<->E or S<->N side by side).

The Haskell version takes a list of directions with `data Direction = North | East | West | South`. The Clojure version returns nil when the path is reduced to nothing. The Rust version takes a slice of `enum Direction {NORTH, SOUTH, EAST, WEST}`.

#### Examples

```javascript
dirReduc(["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"]) => ["WEST"]
dirReduc(["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH"]) => []
```

#### See more examples in "Example Tests"

#### Note

Not all paths can be made simpler. The path ["NORTH", "WEST", "SOUTH", "EAST"] is not reducible. "NORTH" and "WEST", "WEST" and "SOUTH", "SOUTH" and "EAST" are not directly opposite of each other and can't become such. Hence the result path is itself : ["NORTH", "WEST", "SOUTH", "EAST"].

## Solution

```js
function dirReduc(arr){
  let match = {"NORTH": "SOUTH", "EAST": "WEST", "SOUTH": "NORTH", "WEST": "EAST"};
  let ans = [];
  for (const dir of arr) {
    if (!ans.length || match[dir] !== ans[ans.length-1]) ans.push(dir);
    else ans.pop();
  }
  return ans;
}

function dirReduc(arr) {
  let str = arr.join(''), pattern = /NORTHSOUTH|EASTWEST|SOUTHNORTH|WESTEAST/;
  while (pattern.test(str)) str = str.replace(pattern,'');
  return str.match(/(NORTH|SOUTH|EAST|WEST)/g)||[];
}

function dirReduc(arr){
  let match = {"NORTH": "SOUTH", "EAST": "WEST", "SOUTH": "NORTH", "WEST": "EAST"};
  return arr.reduce((dirs, cur) => {
    if (!dirs.length || match[cur] !== dirs[dirs.length-1]) dirs.push(cur);
    else dirs.pop();
    return dirs;
  }, []);
}
```