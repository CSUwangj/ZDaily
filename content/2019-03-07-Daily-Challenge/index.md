+++
title = "2019-03-07 Daily Challenge"
path = "2019-03-07-daily-challenge"
date = 2019-03-07T10:19:46+00:00
updated = 2020-09-19T20:01:27.633312+00:00
description = "DailyChallenge"

[taxonomies]
tags = [ "CodeWars",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
What I've done today is *Extract the domain name from a URL* in *JavaScript*.

Problem is misleading and description is like shit. Data is poor.

<!-- more -->

# CodeWars

## Problem

### Extract the domain name from a URL

Write a function that when given a URL as a string, parses out just the domain name and returns it as a string. For example:

```javascript
domainName("http://github.com/carbonfive/raygun") == "github" 
domainName("http://www.zombie-bites.com") == "zombie-bites"
domainName("https://www.cnet.com") == "cnet"
```

## Solution

```js
function domainName(url){
  let s = url.replace(/https?:\/\//, "").split("/")[0];
  s = s.split(".");
  if (s.length > 2 && s[s.length-2] == "co") return s[s.length-3];
  else return s[s.length-2];
}
```

In fact subdomain does not need to be "www", so...

Shit problem

{% asset_img 1.png %}