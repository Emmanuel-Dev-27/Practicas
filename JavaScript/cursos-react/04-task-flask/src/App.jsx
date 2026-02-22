import { useState } from 'react'
import { BrowserRouter, Route, Routes } from "react-router-dom";
import { About } from './components/About.jsx';
import { Users } from './components/Users.jsx';
import { Navbar } from './components/Navbar.jsx';

function App() {

  return (
    <BrowserRouter>
      <Navbar/>
      <div className='conteiner p-4' >
        <Routes>
          
          <Route path='/about' Component={About} />
          <Route path='/users' element={<Users/>} />
        </Routes>
      </div>
    </BrowserRouter>
  )
}

export default App
