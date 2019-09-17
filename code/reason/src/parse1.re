type user = {
  id: int,
  name: string,
};

let show = u => Js.log(u.name ++ ", " ++ string_of_int(u.id));

let parse = json => {
  id: json |> Json.Decode.field("id", Json.Decode.int),
  name: json |> Json.Decode.field("name", Json.Decode.string),
};

let validJson = {j|{"id":10, "name": "Test"}|j};

validJson |> Json.parseOrRaise |> parse |> show;