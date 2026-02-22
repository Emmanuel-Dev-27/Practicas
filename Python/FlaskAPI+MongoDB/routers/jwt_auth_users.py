from fastapi import APIRouter, Depends, HTTPException, status
from pydantic import BaseModel
from fastapi.security import OAuth2PasswordBearer, OAuth2PasswordRequestForm
from datetime import datetime, timedelta, timezone
import os

import jwt
from jwt.exceptions import InvalidTokenError
from pwdlib import PasswordHash 
from typing import Optional

# Cargar valores sensibles desde variables de entorno
SECRET_KEY = os.getenv("JWT_SECRET_KEY", "ecb6def41d3f9c6451f437e0a040e8bd0b8f5af4b41af5488ea58d423469b4d0")
ALGORITHM = os.getenv("JWT_ALGORITHM", "HS256")
ACCESS_TOKEN_EXPIRE_MINUTES = int(os.getenv("ACCESS_TOKEN_EXPIRE_MINUTES", "30"))

password_hash = PasswordHash.recommended()
oauth2_scheme = OAuth2PasswordBearer(tokenUrl="login")

router = APIRouter(
  prefix="/jwtauth",
  tags=["jwtauth"],
  responses={status.HTTP_404_NOT_FOUND: {"message": "No encontrado"}}
)

class User(BaseModel):
  full_name: str
  username: str
  email: str
  disabled: bool

class UserDB(User):
  password: str

users_db = {
  "encr" : {
    "full_name": "Emmanuel Cedeño",
    "username": "encr",
    "email": "encr@hola.com",
    "disabled": False,
    "password": password_hash.hash("1234")
  },
  "Nat" : {
    "full_name": "Monica Carrero",
    "username": "Nat",
    "email": "nat@hola.com",
    "disabled": False,
    "password": password_hash.hash("4321")
  },
  "pepe" : {
    "full_name": "Angelica Cedeño",
    "username": "pepe",  
    "email": "pepe@hola.com",
    "disabled": True,
    "password": password_hash.hash("5678")
  }
}

def search_user_db(username: str):
	if username in users_db:
		return UserDB(**users_db[username])

def verify_password(plain_password, hashed_password):
    return password_hash.verify(plain_password, hashed_password)
  
def create_access_token(data: dict, expires_delta: Optional[timedelta] = None):
    to_encode = data.copy()
    expire = datetime.now(timezone.utc) + (expires_delta or timedelta(minutes=ACCESS_TOKEN_EXPIRE_MINUTES))
    to_encode.update({"exp": expire})
    return jwt.encode(to_encode, SECRET_KEY, algorithm=ALGORITHM)

async def get_current_user(token: str = Depends(oauth2_scheme)):
  credentials_exception = HTTPException(
    status_code=status.HTTP_401_UNAUTHORIZED,
    detail="Could not validate credentials",
    headers={"WWW-Authenticate": "Bearer"},
  )
  try:
    payload = jwt.decode(token, SECRET_KEY, algorithms=[ALGORITHM])
    username: str = payload.get("sub")
    if username is None:
      raise credentials_exception
  except InvalidTokenError:
    raise credentials_exception
  
  user_dict = users_db.get(username)
  if user_dict is None:
    raise credentials_exception
  return User(**user_dict)

@router.post("/login")
async def login(form_data: OAuth2PasswordRequestForm = Depends()):
  user_dict = users_db.get(form_data.username)
  if not user_dict or not verify_password(form_data.password, user_dict["password"]):
    raise HTTPException(
      status_code=status.HTTP_401_UNAUTHORIZED,
      detail="Incorrect username or password",
      headers={"WWW-Authenticate": "Bearer"},
    )

  access_token = create_access_token(
    data={"sub": form_data.username}, 
    expires_delta=timedelta(minutes=ACCESS_TOKEN_EXPIRE_MINUTES)
  )
  return {"access_token": access_token, "token_type": "bearer"}

@router.get("/users/me", response_model=User)
async def read_users_me(current_user: User = Depends(get_current_user)):
  return current_user