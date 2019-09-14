# Learning to Learn ReasonML

Jasim A Basheer
@jasim_ab

# What is Reason: code vs code

## Getting up

- Turn off alarm
- Get out of bed

## Breakfast

- Eat eggs
- Drink coffee

# In the evening

## Dinner

- Eat spaghetti
- Drink wine

------------------

## Going to sleep

- Get in bed
- Count sheep

------------------

~~~~ {.javascript}
switch (play.type) {
  case "tragedy":  
    return new TragedyCalculator(aPerformance, aPlay);
    
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
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

------------------

~~~~ {.javascript}
type type_ =
  | Tragedy
  | Comedy;

type play = {
  name: string,
  audience: int,
  type_,
};
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
