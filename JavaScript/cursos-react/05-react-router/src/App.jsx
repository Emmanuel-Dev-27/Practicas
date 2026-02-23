import { lazy, Suspense } from 'react'

import './App.css'

import { Router } from './Router.jsx'
import Route from './Route.jsx'

const AboutPage = lazy(() => import('./pages/AboutPage.jsx'))
const HomePage = lazy(() => import('./pages/Home.jsx') )
const SearchPage = lazy(() => import('./pages/Search.jsx') )
const Page404 = lazy(() => import('./pages/404.jsx') )

const routes = [
  {
    path: '/search/:query',
    Component: SearchPage
  }
]


function App() {
  return (
    <main>
      <Suspense fallback={<div>Loaiding ... </div>} >
        <Router routes={routes} defaultComponent={Page404} >
          <Route path='/' Component={HomePage} />
          <Route path='/about' Component={AboutPage} />
        </Router>
      </Suspense>
    </main>
  )
}

export default App
