+++
title = "2019-03-23 Daily Challenge"
path = "2019-03-23-daily-challenge"
date = 2019-03-23T23:34:14+00:00
updated = 2019-03-23T23:47:11+00:00
in_search_index = true

[taxonomies]
tags = ["Cryptography",]
categories = [ "DailyChallenge",]
archives = [ "archive",]
+++
Due to visit of my friend, I spent a lot of time playing with him. It's so relaxing, so I'm not productive this weekend. :D

<!-- more -->

I've read [A Tutorial on Linear and Differential Cryptanalysis](https://www.engr.mun.ca/~howard/PAPERS/ldc_tutorial.pdf) back and forth, and figured out what to do with differential cryptanalysis.

# Step to follow to complete differential cryptanalysis attack

1. Generate DDT(Differential Distribution Table) of SBOX, if there are many SBOXs, generate DDTs for each of SBOX.
2. Find path to construct a good path.(Good for me, I'll explain it later.)
3. Get enough plainttext-cipher XOR pairs, for a bias of $\varepsilon$, a roughly amount of $\frac{c}{\varepsilon}$ is required, where $c$ is a small constant. The more pairs, the better. But too much does not make much sense.
4. For your constructed path, try to recover keys by following instruction of tutorial.
5. Repeat step 2-4 until you get subkey of last round.
6. Repeat step 1-5 until you get all subkeys except first XOR.
7. Use subkeys to recover first XOR key by reverse encryption process and known plaintext.

But I haven't finish my attack towards any cipher, so, hope this post does't mislead someone. I'll update it if I prove that it was wrong.