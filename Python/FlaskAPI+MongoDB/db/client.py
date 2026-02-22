from pymongo import MongoClient
from dotenv import load_dotenv
import os

# Cargar .env (si existe)
load_dotenv()

# si es remoto usar:
# uri = mongodb+srv://<database user>:<database password>@<cluster address>
# si es local usar:
# uri = "mongodb://admin:admin@localhost:55001"
# Priorizar MONGO_URI, luego URI (compatibilidad) y por último un localhost por defecto
uri = os.getenv("MONGO_URI") or os.getenv("URI") or "mongodb://localhost:27017"
connect = MongoClient(uri)

# Nombre de la base de datos
db_name = os.getenv("MONGO_DB", "test")
db_client = connect[db_name]

try:
    db_client.admin.command('ping')
    print("Pinged your deployment. You successfully connected to MongoDB!")
except Exception as e:
    print(e)
# db_client = MongoClient()