/* eslint-disable react/prop-types */
import { useState } from 'react'
import './XFollowCard.css'

export function XFollowCard ({children, userName, initialIsFollowing}) {
  const [isFollowing, setIsFollowing] = useState(initialIsFollowing)

  const text = isFollowing ? 'Siguiendo' : 'Seguir'
  const buttonClassName = isFollowing 
    ? 'x-followCard-button is-following'
    : 'x-followCard-button'

  const handleClick = () => {
    setIsFollowing(!isFollowing)
  }

  return(
    <article className='x-followCard' > 
      <header className='x-followCard-header' >
        <img 
          className='x-followCard-avatar'
          src={`http://localhost/Extras/${userName}.jpg`} 
          alt="Avatar" 
        />
        <div className='x-followCard-info'>
          <strong>{ children }</strong>
          <span className='x-followCard-infoUserName'>@{ userName } </span>
        </div>
      </header>

      <aside>
        <button className={ buttonClassName } onClick={handleClick} >
          {text}
        </button>
      </aside>
    </article>
  )
}