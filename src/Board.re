let component = ReasonReact.statelessComponent("Board");
let make = (~state: Types.state, ~onMark, ~onRestart, _children) => {
  ...component,
  render: _ =>
    <div className="game-board">
      <button onClick=(_evt => onRestart())>(ReasonReact.string("Reset"))</button>
      <p>(ReasonReact.string("Game status: " ++ switch state.gameState {
      | Playing(Cross) => "Playing(Cross)"
      | Playing(Circle) => "Playing(Circle)"
      | Winner(Cross) => "Winner(Cross)"
      | Winner(Circle) => "Winner(Circle)"
      | Draw => "Draw" 
      }))</p>
      (ReasonReact.string("Board:"))
      (ReasonReact.array(Array.of_list(
        List.mapi((index: int, row: Types.row) => 
        <BoardRow
          key=(string_of_int(index))
          gameState=state.gameState
          row
          onMark
          index
         />, state.board)
      )))
    </div>,
};