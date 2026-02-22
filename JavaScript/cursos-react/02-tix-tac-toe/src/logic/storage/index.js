import { TURNS } from '../../constants.js'

export const saveStorageGame = ({board, turn}) => {
  window.localStorage.setItem('board', JSON.stringify(board))
  window.localStorage.setItem('turn', turn)
}

export const resetStorageGame = () => {
  window.localStorage.removeItem('board')
  window.localStorage.removeItem('turn')
}

export const loadStorageBoard = () => {
  const savedBoard = window.localStorage.getItem('board')
  return savedBoard ? JSON.parse(savedBoard) : Array(9).fill(null)
}

export const loadStorageTurn = () => {
  const savedTurn = window.localStorage.getItem('turn')
  return savedTurn ?? TURNS.X
}
