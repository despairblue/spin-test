type t = [ | `Missing_env_var(string)];

let to_string: t => string;

let missing_env: string => t;