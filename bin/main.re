open Cmdliner;

let cmds = [Cmd_hello.cmd];

/* Command line interface */

let doc = "lists the current directory";

let sdocs = Manpage.s_common_options;

let exits = Common.exits;

let envs = Common.envs;

let man = [
  `S(Manpage.s_description),
  `P("lists the current directory"),
  `S(Manpage.s_commands),
  `S(Manpage.s_common_options),
  `S(Manpage.s_exit_status),
  `P("These environment variables affect the execution of $(mname):"),
  `S(Manpage.s_environment),
  `S(Manpage.s_bugs),
  `P("File bug reports at $(i,%%PKG_ISSUES%%)"),
  `S(Manpage.s_authors),
  `P("Danny Martini, $(i,https://github.com/despairblue)"),
];

let default_cmd = {
  let term =
    Common.Let_syntax.(
      Term.ret @@
      {
        let+ _ = Common.term;
        `Help((`Pager, None));
      }
    );

  let info =
    Term.info(
      "ls",
      ~version="%%VERSION%%",
      ~doc,
      ~sdocs,
      ~exits,
      ~man,
      ~envs,
    );
  (term, info);
};

let () = Term.(exit_status @@ eval_choice(default_cmd, cmds));
