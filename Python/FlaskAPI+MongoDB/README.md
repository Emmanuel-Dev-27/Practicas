# User API (FastAPI)

Documentación interactiva disponible en `/docs` (Swagger) y `/redoc`.

## Variables de entorno

El proyecto carga variables desde un archivo `.env`. No comitees tu `.env` real; usa `.env.example` como plantilla.

- MONGO_URI: cadena de conexión a MongoDB (por ejemplo `mongodb://user:pass@host:27017`).
- MONGO_DB: nombre de la base de datos (por defecto `test`).
- JWT_SECRET_KEY: clave para firmar los JWT (obligatoria en producción).
- JWT_ALGORITHM: algoritmo JWT (por defecto `HS256`).
- ACCESS_TOKEN_EXPIRE_MINUTES: expiración del token en minutos (por defecto `30`).

## Endpoints principales

- `GET /` — mensaje de bienvenida.
- `POST /basicauth/login` — login con credenciales básicas (entorno de desarrollo).
- `GET /basicauth/users/me` — devuelve el usuario actual (basicauth).
- `POST /jwtauth/login` — obtiene `access_token` (JWT).
- `GET /jwtauth/users/me` — devuelve usuario autenticado por JWT.
- `GET /usersdb/` — lista usuarios desde MongoDB.
- `POST /usersdb/` — crea un usuario en MongoDB.
- `PUT /usersdb/` — actualiza un usuario.
- `GET /usersdb/{id}` — obtiene usuario por id.
- `DELETE /usersdb/{id}` — elimina usuario por id.

## Ejecutar localmente

1. Copia `.env.example` a `.env` y ajusta los valores.
2. Crear entorno virtual e instalar dependencias (recomendado):

```bash
# Crear un entorno virtual (Linux/macOS)
python3 -m venv .venv

# Activar el entorno (bash/zsh)
source .venv/bin/activate

# (Opcional) instalar paquete para venv si no está disponible en Debian/Ubuntu
# sudo apt update && sudo apt install -y python3-venv

# Actualizar pip e instalar dependencias desde requirements.txt
pip install --upgrade pip
pip install -r requirements.txt
```

3. Ejecuta en modo desarrollo (ejemplo):

```bash
fastapi dev main.py
```

La interfaz de documentación estará disponible en `http://localhost:8000/docs`.

## Seguridad

- No dejes secretos en el código; mueve `JWT_SECRET_KEY` a variables de entorno.
- Añade `.env` a `.gitignore`.
- En producción, considera usar un secrets manager (AWS Secrets Manager, Vault, Azure Key Vault) en lugar de archivos `.env`.

## Notas

- `.env.example` contiene las variables mínimas que usa la aplicación (MONGO_* y JWT_*).