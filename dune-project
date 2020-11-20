(lang dune 2.0)
(name ls)
(source (github despairblue/ls))
(license MIT)
(authors "Danny Martini")
(maintainers "Danny Martini")

(generate_opam_files true)

(package
 (name ls)
 (synopsis "lists the current directory")
 (description "\
lists the current directory
")
 (depends
  (ocaml (>= 4.08.0))
  (dune (>= 2.0))
  ; Add Rely when released on Opam
  ; (rely :with-test)
  (odoc :with-doc)
  (reason :build)
  cmdliner
  logs
  fmt))
