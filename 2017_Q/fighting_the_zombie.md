# Problem

 "Okay, Wizard, cast your spell!"

But which of your many spells to cast? In the ever-popular role-playing game Dungeons & Dragons, or D&D, you determine a spell's damage by rolling polyhedral dice with 4, 6, 8, 10, 12, or 20 sides. Since there's a lot of dice-rolling involved, players use shorthand to denote which dice should be rolled. $X$d$Y$ means "roll a $Y$-sided die $X$ times, and sum the rolls''. Sometimes, you must add or subtract a value $Z$ after you finish rolling, in which case the notation is $X$d$Y$+$Z$ or $X$d$Y$-$Z$ respectively.

In D&D, wizards are powerful but flimsy spellcasters. As a wizard fighting a zombie, your best strategy is to maximize the chance that you can kill the zombie with a single spell before it has a chance to retaliate. What spell should you cast?

## Input

Input begins with an integer $T$, the number of zombies you'll fight. For each zombie, there are two lines.  
The first contains two integers, $H$ and $S$, the minimum amount of damage it takes to defeat the zombie, and the number of spells you have prepared, respectively.  
The second line contains $S$ spell descriptions separated by single spaces. A spell description is simply the amount of damage a spell does in the notation described above.
