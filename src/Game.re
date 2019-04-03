open Types;

type actions = Restart | ClickSquare(string);

let initialState: state = {
    board: [
        [Empty, Empty, Empty], 
        [Empty, Empty, Empty],
        [Empty, Empty, Empty]],
    gameState: Playing(Cross),
    count: 0
    };

let updateBoard = (board, gameState, id) => board 
    |> List.mapi((rowIdx, row) => 
        row  
            |> List.mapi((cellIdx, cell) => 
                string_of_int(rowIdx) ++ string_of_int(cellIdx) === id ?
                    switch (gameState, cell) {
                    | (_, Marked(_)) => cell
                    | (Playing(player), Empty) => Marked(player)
                    | (_, Empty) => Empty
                    }
                    : cell
                )
        )
    

let winningCombs = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],  
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6],
];     

let getWinner = board => {
    let flattenBoard = List.flatten(board);
    let getNth = List.nth(flattenBoard);
 try (
    winningCombs |> List.find(comb => {
        let [n1, n2, n3] = comb;
        switch (getNth(n1), getNth(n2), getNth(n3)) {
            | (Marked(Cross), Marked(Cross), Marked(Cross)) 
            | (Marked(Circle), Marked(Circle), Marked(Circle)) => true
            | _ => false
        };
    }) |> ([n1, _, _]) => getNth(n1) |> (Marked(player)) => Some(player) ) {
        | Not_found => None
    };
}

let isDraw = board => List.flatten(board) |> List.for_all(field => switch(field) {
| Marked(_) => true
| Empty => false
})

let updateGameState = (updatedBoard, oldBoard, gameState) => {
    updatedBoard == oldBoard ?
        gameState : {
            let winner = getWinner(updatedBoard);
            let isDraw = isDraw(updatedBoard);

            switch (winner, isDraw, gameState) {
                | (Some(player), _, _) => Winner(player)  
                | (_, true , _) => Draw
                | (_, _, Playing(Cross)) => Playing(Circle)
                | (_, _, Playing(Circle)) => Playing(Cross)
                | _ => gameState
                };
        }
}

let component = ReasonReact.reducerComponent("Game");
let make = _children => {
  ...component,
  initialState: () => initialState,
  reducer: (action, state) =>
  switch (action) {
  | Restart => ReasonReact.Update(initialState)
  | ClickSquare(id) => {
      let updatedBoard = updateBoard(state.board, state.gameState, id);

      ReasonReact.Update({
          ...state, 
          board: updatedBoard, 
          gameState: updateGameState(updatedBoard, state.board, state.gameState)
        }) 
    }
  },
  render: ({state, send}) =>  <div className="game">
    <Board
        state
        onRestart=(_evt => send(Restart))
        onMark=(id => send(ClickSquare(id)))
    />
    </div>,
};