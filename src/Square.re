[%bs.raw {|require('./square.css')|}];

open Types;

let getClass = (gameState: Types.gameState, value: Types.field) => switch gameState {
    | Winner(Circle) when value === Marked(Circle)=> "green"
    | Winner(Cross) when value === Marked(Cross)=> "green"
    | _ => ""
    };

let isFinished = gameState => switch gameState {
    | Winner(Cross) | Winner(Circle) | Draw => true
    | _ => false
}

let drawField = (field: field) => switch field {
    | Marked(Cross) => "X"
    | Marked(Circle) => "O"
    | Empty => ""    
};

let component = ReasonReact.statelessComponent("Square");
let make = (~value: Types.field, ~gameState: Types.gameState, ~onMark, _children) => {
  ...component,
  render: _self =>
    <button
      className=("BoardCell" ++ getClass(gameState, value))
      disabled=(gameState |> isFinished)
      onClick=(_evt => onMark())>
      (value |> drawField |> ReasonReact.string)
    </button>,
};

