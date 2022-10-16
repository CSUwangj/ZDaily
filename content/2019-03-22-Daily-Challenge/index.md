+++
title = "2019-03-22 Daily Challenge"
path = "2019-03-22-daily-challenge"
date = 2019-03-22T00:06:05+00:00
updated = 2019-03-23T00:40:49+00:00

[taxonomies]
tags = ["Cryptography",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
I've complete a linear cryptanalysis attack towards simple a toy SPN cipher, I feel very veryyyyy happy!

<!-- more -->

# Steps to follow to finish my attack

1. Generate LAT(linear Approximation Table) of SBOX, if there are many SBOXs, generate LATs for each of SBOX.
2. Find path to construct a good path.(Good for me, I'll explain it later.)
3. Get enough plainttext-cipher pairs, for a bias of $\varepsilon$, a reasonable amount of $\frac{1}{\varepsilon^2}$ is required, the more, the better. But too much does not make much sense.
4. For your constructed path, try to recover keys by following instruction of tutorial.
5. Repeat step 2-4 until you get subkey of last round.
6. Repeat step 1-5 until you get all subkeys except first XOR.
7. Use subkeys to recover first XOR key by reverse encryption process and known plaintext.

I'll show a detailed example by a post, just wait.;D