// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var App = require("./app.bs.js");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var ServiceWorker = require("./serviceWorker");

((require('./index.css')));

ReactDOMRe.renderToElementWithId(ReasonReact.element(undefined, undefined, App.make(/* array */[])), "root");

ServiceWorker.unregister();

/*  Not a pure module */
