import { BUTTON, EVENT } from './consts'

export function navigate(href) {
  window.history.pushState({}, '', href)
  const navigationEvent = new Event(EVENT.PUSHSTATE)
  window.dispatchEvent(navigationEvent)
}

export function Link({ target, to, ...prompt }) {
  const handelClick = (event) => {
    
    const isMainEvent = event.button === BUTTON.primary // primary click
    const isModifiedEvent = event.metaKey || event.altKey || event.ctrlKey || event.shiftKey
    const isManageableEvent= target === undefined || target === '_self'
    
    if (isMainEvent && isManageableEvent && !isModifiedEvent) {
      event.preventDefault()
      navigate(to) // navegacion SPA
    }

  }
  return <a onClick={handelClick} href={to} target={target} {...prompt} ></a>
}