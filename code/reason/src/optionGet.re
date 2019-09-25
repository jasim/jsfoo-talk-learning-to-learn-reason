open Belt;

type user = {id: int};

let showNext = u => {
  Js.log("You will be user " ++ string_of_int(u.id + 1));
};

let users = [||];
let lastUserIndex = users[Array.length(users) - 1];
let lastUser = users[lastUserIndex];

showNext(lastUser);