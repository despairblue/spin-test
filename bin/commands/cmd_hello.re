open Ls;

let run = (~name) => {
  let greeting = Utils.greet(name);
  Logs.app(m => m("%s", greeting));
  Ok();
};

/* Command line interface */

open Cmdliner;

let doc = "Print \"Hello World!\"";

let sdocs = Manpage.s_common_options;

let exits = Common.exits;

let envs = Common.envs;

let man = [
  `S(Manpage.s_description),
  `P("$(tname) prints a hello world message on the standard output."),
];

let info = Term.info("hello", ~doc, ~sdocs, ~exits, ~envs, ~man);

let term = {
  open Common.Let_syntax;
  let+ _term = Common.term
  and+ name = {
    let doc = "The name to greet.";
    let docv = "NAME";
    Arg.(required & pos(0, some(string), None) & info([], ~doc, ~docv));
  };

  run(~name) |> Common.handle_errors;
};

let cmd = (term, info);
