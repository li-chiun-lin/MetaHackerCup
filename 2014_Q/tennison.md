# Problem

You may be familiar with the works of Alfred Lord Tennyson, the famous English poet. In this problem we will concern ourselves with Tennison, the less famous English tennis player. As you know, tennis is not so much a game of skill as a game of luck and weather patterns. The goal of tennis is to win $K$ sets before the other player. However, the chance of winning a set is largely dependent on whether or not there is weather.

Tennison plays best when it's sunny, but sometimes, of course, it rains. Tennison wins a set with probability $p_s$ when it's sunny, and with probability $p_r$ when it's raining. The chance that there will be sun for the first set is $p_i$. Luckily for Tennison, whenever he wins a set, the probability that there will be sun increases by $p_u$ with probability $p_w$. Unfortunately, when Tennison loses a set, the probability of sun decreases by $p_d$ with probability $p_l$. What is the chance that Tennison will be successful in his match?

Rain and sun are the only weather conditions, so $P(rain) = 1 - P(sun)$ at all times. Also, probabilities always stay in the range $[0, 1]$. If $P(sun)$ would ever be less than $0$, it is instead $0$. If it would ever be greater than $1$, it is instead $1$.

## Input

Input begins with an integer $T$, the number of tennis matches that Tennison plays.  
For each match, there is a line containing an integer $K$, followed by the probabilities $p_s, p_r, p_i, p_u, p_w, p_d, p_l$ in that order. All of these values are given with exactly three places after the decimal point.
