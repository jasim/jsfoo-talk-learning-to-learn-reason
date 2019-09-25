type user = {
  id: int,
  name: string,
};

let show = u => Js.log(u.name ++ ", " ++ string_of_int(u.id));
let parse = json => {
  id: json |> Json.Decode.field("id", Json.Decode.int),
  name: json |> Json.Decode.field("name", Json.Decode.string),
};

let invalidJson = {j|{"id": 10}|j};

let result = invalidJson |> Json.parse
/* 
switch (result) {
| Some(user) => show(user)
| None => Js.log("Sorry you sent invalid data")
}; */