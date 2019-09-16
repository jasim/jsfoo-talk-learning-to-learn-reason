let _baseCredit = audience => max(audience - 30, 0);

module Tragedy = {
  type t = {
    name: string,
    audience: int,
  };
  let audience = t => t.audience;
  let amount = t => {
    let extra = () => 1000 * (t.audience - 30);
    40000 + (t.audience > 30 ? extra() : 0);
  };
  let volumeCredit = t => _baseCredit(t.audience) + 0;
};

module Comedy = {
  type t = {
    name: string,
    audience: int,
  };
  let audience = t => t.audience;
  let amount = t => {
    let extra = () => 10000 + 500 * (t.audience - 20);
    let result = 30000 + 300 * t.audience;
    result + (t.audience > 20 ? extra() : 0);
  };
  let volumeCredit = t => _baseCredit(t.audience) + t.audience / 5;
};

type play =
  | Tragedy(Tragedy.t)
  | Comedy(Comedy.t);

let amount = t =>
  switch (t) {
  | Tragedy(play) => Tragedy.amount(play)
  | Comedy(play) => Comedy.amount(play)
  };

let volumeCredit = t =>
  switch (t) {
  | Tragedy(tragedy) => Tragedy.volumeCredit(tragedy)
  | Comedy(comedy) => Comedy.volumeCredit(comedy)
  };

let _sum = List.fold_left((+), 0);
let totalAmount = ts => ts |> List.map(amount) |> _sum;
let totalVolumeCredit = ts => ts |> List.map(volumeCredit) |> _sum;

let ts = [
  Tragedy({name: "Hamlet", audience: 55}),
  Comedy({name: "As you like it", audience: 35}),
  Tragedy({name: "Othello", audience: 40}),
];
ts |> List.map(t => (amount(t) / 100, volumeCredit(t)));

totalAmount(ts);
totalVolumeCredit(ts);