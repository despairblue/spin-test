let term: Cmdliner.Term.t(int);

let handle_errors: Result.t(unit, Ls.Ls_error.t) => int;

let envs: list(Cmdliner.Term.env_info);

let exits: list(Cmdliner.Term.exit_info);

module Let_syntax: {
  let (let+): (Cmdliner.Term.t('a), 'a => 'b) => Cmdliner.Term.t('b);

  let (and+):
    (Cmdliner.Term.t('a), Cmdliner.Term.t('b)) => Cmdliner.Term.t(('a, 'b));
};