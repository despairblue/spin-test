let home = {
  let env_var =
    switch (Sys.os_type) {
    | "Unix" => "HOME"
    | _ => "APPDATA"
    };
  Sys.getenv_opt(env_var)
  |> Option.to_result(~none=Ls_error.missing_env(env_var));
};

let default_cache_dir =
  Result.map(
    home => "ls" |> Filename.concat(".cache") |> Filename.concat(home),
    home,
  );

let default_config_dir =
  Result.map(
    home => "ls" |> Filename.concat(".config") |> Filename.concat(home),
    home,
  );

let cache_dir =
  Sys.getenv_opt("LS_CACHE_DIR")
  |> Option.map(Result.ok)
  |> Option.value(~default=default_cache_dir);

let config_dir =
  Sys.getenv_opt("LS_CONFIG_DIR")
  |> Option.map(Result.ok)
  |> Option.value(~default=default_config_dir);
