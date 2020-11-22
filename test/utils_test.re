open Test_framework;
open Ls;

/** Test suite for the Utils module. */;

let test_hello_with_name = (name, {expect, _}) => {
  let greeting = Utils.greet(name);
  let expected = "Hello " ++ name ++ "!";
  expect.string(greeting).toEqual(expected);
};

let () =
  describe("Utils") @@
  (
    ({test, _}) => {
      test("can greet Tom", test_hello_with_name("Tom"));
      test("can greet John", test_hello_with_name("John"));
    }
  );
