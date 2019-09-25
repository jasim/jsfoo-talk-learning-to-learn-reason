// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Json = require("@glennsl/bs-json/src/Json.bs.js");
var Json_decode = require("@glennsl/bs-json/src/Json_decode.bs.js");

function show(u) {
  console.log(u[/* name */1] + (", " + String(u[/* id */0])));
  return /* () */0;
}

function parse(json) {
  return /* record */[
          /* id */Json_decode.field("id", Json_decode.$$int, json),
          /* name */Json_decode.field("name", Json_decode.string, json)
        ];
}

var invalidJson = "{\"id\": 10}";

var result = Json.parse(invalidJson);

exports.show = show;
exports.parse = parse;
exports.invalidJson = invalidJson;
exports.result = result;
/* result Not a pure module */
