import { useState, useEffect, Children } from 'react'
import { EVENT } from './consts'
import { match } from 'path-to-regexp'
import { getCurrentPath } from './utils'

export function Router ({children, routes = [], defaultComponent: Defaultcomponent = () => <h1>404</h1>}) {
  const [currentPath, setCurrenPath] = useState(getCurrentPath())

  useEffect(() => {
    const onLocationChange = () => {
      setCurrenPath(getCurrentPath())
    }

    window.addEventListener(EVENT.PUSHSTATE, onLocationChange)
    window.addEventListener(EVENT.POPSTATE, onLocationChange)

    return () =>{
      window.removeEventListener(EVENT.PUSHSTATE, onLocationChange)
      window.removeEventListener(EVENT.POPSTATE, onLocationChange)

    }
  }, [])

  let routeParams =  {}

  const routeFromChildren = Children.map(children, ({ props, type }) => {
    const { name } = type
    const isRoute = name === 'Route'
    
    return isRoute ? props : null
  })

  const routeToUse = routes.concat(routeFromChildren).filter(Boolean)

  const Page = routeToUse.find(({ path }) => {
    if (path === currentPath) return true

    const matcherURL = match(path, { decode: decodeURIComponent })
    const matched = matcherURL(currentPath)
    if (!matched) return false 

    routeParams = matched.params
    return true
    
  })?.Component

  return Page 
  ? <Page routeParams={routeParams} /> 
  : <Defaultcomponent routeParams={routeParams} /> 
}