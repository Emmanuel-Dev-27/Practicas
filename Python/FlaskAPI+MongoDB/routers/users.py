from fastapi import APIRouter, HTTPException
from pydantic import BaseModel

router = APIRouter(prefix="/users", tags=["users"], responses={404: {"message": "Not found"}})

class User(BaseModel):
    id: int 
    name: str
    username: str
    age: int

users_list = [
    User( id = 1, name = "user", username = "user1", age = 20),
    User(id = 2, name = "user33", username = "user2", age = 25)]


@router.get("/")
async def users():
    return users_list


#path parameter
@router.get("/{id}")
async def user(id: int):
    return search_user(id)

#query parameter
@router.get("/query/") # ejemplo: /userquery/?id=1
async def userquery(id: int):
    return search_user(id)


#post method
@router.post("/", response_model=User, status_code=201)
async def create_user(user: User):
    if type(search_user(user.id)) == User:
        raise HTTPException(status_code=404, detail="User already exists")

    users_list.append(user)
    return user

#put method
# @app.put("/user/{id}")
# async def update_user(id: int, user: User):
#     found_user = search_user(id)
#     if type(found_user) == User:
#         found_user.name = user.name
#         found_user.username = user.username
#         found_user.age = user.age
#         return found_user
#     else:
#         return {"error": "User not found"}

@router.put("/")
async def update_user(user: User):
    for index, saved_user in enumerate(users_list):
        if saved_user.id == user.id:
            users_list[index] = user
            return user
    return {"error": "User not found"}

#delete method
@router.delete("/{id}")
async def delete_user(id: int):
    for index, saved_user in enumerate(users_list):
        if saved_user.id == id:
            del users_list[index]
            return {"message": "User deleted successfully"}
    return {"error": "User not found"}

def search_user(id: int):
    users = filter(lambda user: user.id == id, users_list)
    try:
        return list(users)[0]
    except:
        return {"error": "User not found"}
