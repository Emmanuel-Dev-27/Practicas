import { XFollowCard } from './components/XFollowCard'
import './App.css'

export function App() {
  
  return(
    <section className='App'>
      <XFollowCard 
        initialIsFollowing={true}
        userName="ENCR"  
      >
        Emmanuel Cedeño
      </XFollowCard>

      <XFollowCard 
        userName="NAT" 
      >
        Monica Carrero
      </XFollowCard>
    </section>
  )
}