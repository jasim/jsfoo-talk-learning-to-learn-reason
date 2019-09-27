open Base;
open Stdio;

type parseContext =
  | Regular
  | Note(list(string));

let beginDelim = "::: notes";
let endDelim = ":::";

let f = (acc, line: string) => {
  let line = String.strip(line);
  let (notes, parseContext) = acc;
  switch (parseContext) {
  | Regular when String.equal(line, beginDelim) => (notes, Note([]))
  | Regular => acc
  | Note(currentNote) when String.equal(line, endDelim) =>
    let notes' = [List.rev(currentNote), ...notes];
    (notes', Regular);
  | Note(currentNote) =>
    let currentNote' = [line, ...currentNote];
    (notes, Note(currentNote'));
  };
};

let getInputFilename = () =>
  if (Array.length(Sys.argv) == 2) {
    Some(Sys.argv[1]);
  } else {
    None;
  };

let showNotes = filename => {
  print_endline(filename);
  let lines = Stdio.In_channel.read_lines(filename);
  let (notes, _) = List.fold(lines, ~init=([], Regular), ~f);
  let notes = List.rev(notes);
  List.iter(
    notes,
    ~f=note => {
      print_endline(String.concat(note, ~sep="\n"));
      print_string("----------\n");
    },
  );
};

let () = {
  switch (getInputFilename()) {
  | Some(filename) => showNotes(filename)
  | None => print_endline("Parameter required: filename")
  };
};