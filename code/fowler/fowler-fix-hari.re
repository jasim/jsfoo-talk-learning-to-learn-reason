let sum = List.fold_left((+), 0);

module Genre = {
  type t =
    | Tragedy
    | Comedy;

  let cost = (audience, t) =>
    switch (t) {
    | Tragedy =>
      let sizeFactor = () => 1000 * (audience - 30);
      40000 + (audience > 30 ? sizeFactor() : 0);
    | Comedy =>
      let sizeFactor = () => 10000 + 500 * (audience - 20);
      30000 + 300 * audience + (audience > 20 ? sizeFactor() : 0);
    };

  let volumeCredits = (audience, t) =>
    max(audience - 30, 0)
    + (
      switch (t) {
      | Tragedy => 0
      | Comedy => audience / 5
      }
    );
};

module Play = {
  type t = {
    name: string,
    genre: Genre.t,
  };
  let cost = (audience, t) => t.genre |> Genre.cost(audience);
  let volumeCredits = (audience, t) =>
    t.genre |> Genre.volumeCredits(audience);
};

module Performance = {
  type t = {
    play: Play.t,
    audience: int,
  };
  let cost = t => t.play |> Play.cost(t.audience);
  let volumeCredits = t => t.play |> Play.volumeCredits(t.audience);
};

module Invoice = {
  type t = {
    customer: string,
    performances: list(Performance.t),
  };
  let total = t => t.performances |> List.map(Performance.cost) |> sum;
  let volumeCredits = t =>
    t.performances |> List.map(Performance.volumeCredits) |> sum;
};

let hamlet = Play.{name: "Hamlet", genre: Tragedy};
let asYou = Play.{name: "asYou", genre: Comedy};
let othello = Play.{name: "Othello", genre: Tragedy};
let invoice =
  Invoice.{
    customer: "a",
    performances: [
      Performance.{play: hamlet, audience: 55},
      {play: asYou, audience: 35},
      {play: othello, audience: 40},
    ],
  };

Invoice.total(invoice);
Invoice.volumeCredits(invoice);