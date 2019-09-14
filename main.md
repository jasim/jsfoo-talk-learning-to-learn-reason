---
author:
- Jasim A Basheer
subtitle: Thinking with Types
title: Learning to learn ReasonML
titlepage-note: |
  Talk for JsFoo 2019
institute: "@jasim_ab"
fontsize: 17pt
...

# Don't be afraid of telling lies; be afraid of failing to communicate the truth

\note{
  HELLO!
}

---

## Slide with text and a note

Regular text size

\tiny Jonathan Sarna, *American Judaism* (New Haven: Yale University
Press, 2014)

\note{
NOTES: This is a note page and you ought to be able to tell.
}

## Slide with text and footnote

Surely this is true.^[Jane Doe, *Says It Here* (New York: Oxford 
University Press, 2050).] 

\note{I am sure about this point.}

## This is a heading

Regular text on a slide:

-   One
-   Two
-   Three

\note{
More notes:

Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod
tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At
vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren,
no sea takimata sanctus est Lorem ipsum dolor sit amet.
}

---

## First step

``` {.javascript}
switch (play.type) {
  case "tragedy":  
    return new TragedyCalculator(
      aPerformance, aPlay
    );
    
  case "comedy":
    thisAmount = 30000;
    if (perf.audience > 20) {
      thisAmount += 10000 + 500 * (perf.audience - 20);
    }
    thisAmount += 300 * perf.audience;
    break;
  default:
    throw new Error(`unknown type: ${play.type}`);
}
```

\note{
This might be easier in R or Ruby.
}

---

## Code example

``` {.javascript}
type type_ =
  | Tragedy
  | Comedy;

type play = {
  name: string,
  audience: int,
  type_,
};
```

\note{
This might be easier in R or Ruby.
}
