[%bs.raw {|require('./app.css')|}];

open Types;

let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,
  render: _self =>
    <div className="App">
      <div className="App-header">
      <Game />
      </div>
      
    </div>,
};
