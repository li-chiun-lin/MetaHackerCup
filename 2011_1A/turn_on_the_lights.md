# Problem

A simple game consists of a grid of $R \times C$ buttons. Each button will be either lighted, or unlighted. Whenever you push a button, the state of that button, and its (up to) four neighbors will toggle -- lighted buttons will become unlighted and unlighted buttons will become lighted. Note that the neighbors do not 'wrap' and thus a corner button has only two neighbors, while an edge buttons has three.

In this problem you will be given an initial configuration of the buttons. Your task is to push the right buttons so that, when you are done, all of the lights are turned on. If there are multiple ways to do this, you should determine the minimum number of buttons pushes that it can be done in.
