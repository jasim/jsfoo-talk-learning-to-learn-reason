type type_ =
  | Tragedy
  | Comedy;

type play = {
  name: string,
  audience: int,
  type_,
};

let _commonVolumeCredit = play => max(play.audience - 30, 0);

let amount = t =>
  switch (t.type_) {
  | Tragedy =>
    let extra = () => 1000 * (t.audience - 30);
    40000 + (t.audience > 30 ? extra() : 0);

  | Comedy =>
    let extra = () => 10000 + 500 * (t.audience - 20);
    let result = 30000 + 300 * t.audience;
    result + (t.audience > 20 ? extra() : 0);
  };

let volumeCredit = t =>
  _commonVolumeCredit(t)
  + (
    switch (t.type_) {
    | Tragedy => 0
    | Comedy => t.audience / 5
    }
  );

let _sum = List.fold_left((+), 0);
let totalAmount = ts => ts |> List.map(amount) |> _sum;
let totalVolumeCredit = ts => ts |> List.map(volumeCredit) |> _sum;

let ts = [
  {name: "Hamlet", type: Tragedy, audience: 55},
  {name: "As you like it", type_: Comedy, audience: 35},
  {name: "Othello", type_: Tragedy, audience: 40},
];
ts |> List.map(t => (t.name, amount(t) / 100, volumeCredit(t)));

totalAmount(ts);
totalVolumeCredit(ts);