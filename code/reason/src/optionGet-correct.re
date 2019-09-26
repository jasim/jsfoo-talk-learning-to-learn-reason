open Belt;

type user = {id: int};

let showNext = u => {
  Js.log("You will be user " ++ string_of_int(u.id + 1));
};

let users = [||];
let lastUserIndex = Array.length(users) - 1;
let lastUser = users[lastUserIndex];

switch(lastUser) {
  | None => Js.log("No users in the list")
  | Some(user) => showNext(user)
};
