type t = [ | `Missing_env_var(string)];

let to_string =
  fun
  | `Missing_env_var(s) =>
    Printf.sprintf(
      "The environment variable %S is needed, but could not be found in your environment.\nHint: Try setting it and run the program again.",
      s,
    );

let missing_env = env => `Missing_env_var(env);
