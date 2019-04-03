// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var BoardRow = require("./BoardRow.bs.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("Board");

function make(state, onMark, onRestart, _children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (param) {
              var match = state[/* gameState */1];
              var tmp;
              tmp = typeof match === "number" ? "Draw" : (
                  match.tag ? (
                      match[0] ? "Winner(Cross)" : "Winner(Circle)"
                    ) : (
                      match[0] ? "Playing(Cross)" : "Playing(Circle)"
                    )
                );
              return React.createElement("div", {
                          className: "game-board"
                        }, React.createElement("button", {
                              onClick: (function (_evt) {
                                  return Curry._1(onRestart, /* () */0);
                                })
                            }, "Reset"), React.createElement("p", undefined, "Game status: " + tmp), "Board:", $$Array.of_list(List.mapi((function (index, row) {
                                    return ReasonReact.element(String(index), undefined, BoardRow.make(state[/* gameState */1], row, onMark, index, /* array */[]));
                                  }), state[/* board */0])));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.make = make;
/* component Not a pure module */
