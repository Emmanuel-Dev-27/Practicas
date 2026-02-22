import { useState, useEffect } from "react"
import { Await } from "react-router-dom"

const API = import.meta.env.VITE_REACT_API

export function Users () {

  const [name, setName] = useState('')
  const [email, setEmail] = useState('')
  const [password, setPassword] = useState('')

  const [editing, setEditing] = useState(false)
  const [id, setId] = useState('')

  const [listUsers, setListUsers] = useState([])
  
  useEffect(() => {
    getListUsers()
  }, [listUsers])
  

  const getListUsers = async () => {
    const res = await fetch(`${API}/users`)
    const data = await res.json()
    setListUsers(data)
  }

  const deleteUser = async (id) => {
    const userResponse = window.confirm('Are you sure you want to delete it?')
    if (userResponse) {
      const res = await fetch(`${API}/user/${id}`, {
        method: 'DELETE'
      })
      const data = await res.json()
      console.log(data)
    }
  }

  const editUser = async (id) => {
    const res = await fetch(`${API}/user/${id}`)
    const data = await res.json()

    setEditing(true)
    setId(id)

    setName(data.name)
    setEmail(data.email)
    setPassword('')
    
    console.log(data)
  }

  const handleSubmit = async (e) => {
    e.preventDefault()
    
    if(!editing){
      const res = await fetch(`${API}/users`, {
        method: 'POST',
        headers:{
          'Content-type': 'application/json'
        },
        body: JSON.stringify({
          name,
          email,
          password
        })
      })
      const data = await res.json()
      console.log(data)
    } else {
      const res = await fetch(`${API}/user/${id}`, {
        method: 'PUT',
        headers: {
          'Content-type': 'application/json'
        },
        body: JSON.stringify({
          name,
          email,
          password
        })
      })
      const data = await res.json()
      console.log(data)
      setEditing(false)
      setId('')
    }

    setName('')
    setEmail('')
    setPassword('')

  }
  
  return(
    <div className="row">
      <div className="col-md-4">
        <form onSubmit={ handleSubmit } className="card card-body">
        <div className="form-group p-1">
            <input 
              type="text" 
              onChange={e => setName(e.target.value)} 
              value={name}
              className="form-control"
              placeholder="Name"
              autoFocus 
            />
          </div>
          <div className="form-group p-1">
            <input 
              type="email" 
              onChange={e => setEmail(e.target.value)} 
              value={email}
              className="form-control"
              placeholder="Email"
            />
          </div>
          <div className="form-group p-1">
            <input 
              type="password" 
              onChange={e => setPassword(e.target.value)} 
              value={password}
              className="form-control"
              placeholder="Password"
            />
          </div>
          <button className="btn btn-primary btn-block ">
            { editing ? 'Update' : 'Create' }
          </button>
        </form>
      </div>
      <div className="col-md-8">
        <table className="table table-striped">
          <thead>
            <tr>
              <th>name</th>
              <th>Email</th>
              <th>Operaciones</th>
            </tr>
          </thead>
          <tbody>
            {listUsers.map( user => (
              <tr key={user.id}>
                <td>{user.name}</td>
                <td>{user.email}</td>
                <td>
                  <button 
                    className="btn btn-secundary btn-sm btn-block"
                    onClick={e => editUser(user.id)}
                    >
                    Edit
                  </button>
                  <button 
                    className="btn btn-danger btn-sm btn-block"
                    onClick={() => deleteUser(user.id)}
                  >
                    Delete
                  </button>
                </td>
              </tr>
            ))}
          </tbody>
        </table>
      </div>
    </div>
  )
}