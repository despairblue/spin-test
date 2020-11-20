open Cmdliner;

module Let_syntax = {
  let (let+) = (t, f) => Term.(const(f) $ t);

  let (and+) = (a, b) => Term.(const((x, y) => (x, y)) $ a $ b);
};

open Let_syntax;

let envs = [
  Term.env_info(
    "LS_CACHE_DIR",
    ~doc="The directory where the application data is stored.",
  ),
  Term.env_info(
    "LS_CONFIG_DIR",
    ~doc="The directory where the configuration files are stored.",
  ),
];

let term = {
  let+ log_level = {
    let env = Arg.env_var("LS_VERBOSITY");
    Logs_cli.level(~docs=Manpage.s_common_options, ~env, ());
  };
  Fmt_tty.setup_std_outputs();
  Logs.set_level(log_level);
  Logs.set_reporter(Logs_fmt.reporter(~app=Fmt.stdout, ()));
  0;
};

let error_to_code =
  fun
  | `Missing_env_var(_) => 4;

let handle_errors =
  fun
  | Ok () =>
    if (Logs.err_count() > 0) {
      3;
    } else {
      0;
    }
  | Error(err) => {
      Logs.err(m => m("%s", Ls.Ls_error.to_string(err)));
      error_to_code(err);
    };

let exits = [
  Term.exit_info(3, ~doc="on indiscriminate errors reported on stderr."),
  Term.exit_info(4, ~doc="on missing required environment variable."),
  ...Term.default_exits,
];