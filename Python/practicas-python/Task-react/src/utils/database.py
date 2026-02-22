from flask import g
import sqlite3

from config import DATABASE  # Use relative import

def get_db():
    db = getattr(g, '_database', None)
    if db is None:
        db = g._database = sqlite3.connect(DATABASE)
        db.row_factory = sqlite3.Row  # Para acceder a los resultados como diccionarios
    return db

def init_db():
    db = get_db()
    cursor = db.cursor()
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            email TEXT NOT NULL UNIQUE,
            password TEXT NOT NULL 
        )
    ''')
    db.commit()

def list_users():
    db = get_db()
    cursor = db.cursor()
    cursor.execute('SELECT id, name, email FROM users')
    users = cursor.fetchall()
    return [dict(user) for user in users]
