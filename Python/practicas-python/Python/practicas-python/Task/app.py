from flask import Flask
from routes.tasks import tasks
from flask_sqlalchemy import SQLAlchemy
from config import DATABASE_CONNECTION_URI

app = Flask(__name__)
app.secret_key = 'mysecretkey'
app.config["SQLALCHEMY_DATABASE_URI"] = DATABASE_CONNECTION_URI

app.register_blueprint(tasks)