from fastapi import FastAPI
from fastapi.staticfiles import StaticFiles
from dotenv import load_dotenv
import os

# Cargar variables de entorno desde .env antes de importar routers
load_dotenv()

from routers import users, users_db, basic_auth_users, jwt_auth_users

app = FastAPI()

app.include_router(users.router)
app.include_router(users_db.router)
app.include_router(basic_auth_users.router)
app.include_router(jwt_auth_users.router)

app.mount("/static", StaticFiles(directory="static"), name="static")

@app.get("/")
async def root():
	return {"message": "Welcome to the User API"}