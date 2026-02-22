from flask import Flask
from flask_cors import CORS

from routes.user import api
from utils.database import init_db  # Import init_db

app = Flask(__name__)
CORS(app)  # Initialize CORS

app.register_blueprint(api)

with app.app_context():
    init_db()  # Initialize the database

if __name__ == '__main__':
  app.run(port=4000, debug=True)

