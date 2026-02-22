import { useEffect, useState } from 'react'
import confetti from 'canvas-confetti'
import './App.css'
import { Square } from './components/Square.jsx'
import { TURNS } from './constants.js'
import { checkWinnerFrom, checkEndGame } from './logic/board.js'
import { WinnerModal } from './components/WinnerModal.jsx'
import { saveStorageGame, loadStorageBoard, loadStorageTurn, resetStorageGame } from './logic/storage/index.js'


function App() {
  const [board, setBoard] = useState(loadStorageBoard())

  const [turn, setTurn] = useState(loadStorageTurn())
  //null (no winner), false (empate)
  const [winner, setWinner] = useState(null) 


  const resetGame = () => {
    setBoard(Array(9).fill(null))
    setTurn(TURNS.X)
    setWinner(null)

    resetStorageGame()
  }

  const updateBoard = (index) => {
    if (board[index] || winner) return

    const newBoard = [...board]
    newBoard[index] = turn
    setBoard(newBoard)

    const newTurn = turn === TURNS.X ? TURNS.O : TURNS.X
    setTurn(newTurn)


    const newWinner = checkWinnerFrom(newBoard)
    if (newWinner) {
      setWinner(newWinner)
      confetti({
        particleCount: 1000,
        spread: 180,
        origin: { y: 0.5 }
      })
    } else if (checkEndGame(newBoard)) {
      setWinner(false)
    }
  }

  useEffect(() => {
    saveStorageGame({board, turn})
  }, [board, turn])
  
  return (
    <main className="board">
      <h1>Game</h1>
      <section className='game' >
        {
          board.map((square, index) => {
            return (
              <Square
                key={index}
                index={index}
                updateBoard={updateBoard}
              >
                {square}
              </Square>
            )
          })
        }
      </section>
      <section className='turn' >
        <Square isSelected={turn === TURNS.X}>
          {TURNS.X}
        </Square>
        <Square isSelected={turn === TURNS.O}>
          {TURNS.O}
        </Square>
      </section>
      
      <button onClick={resetGame} >Reset</button>

      <WinnerModal resetGame={resetGame} winner={winner}/>
    </main>
  )
}
export default App
