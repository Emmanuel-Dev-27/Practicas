# User API (FastAPI + MongoDB)

Descripción: Una API REST robusta para la gestión de usuarios que integra persistencia en base de datos NoSQL (MongoDB) y sistemas de seguridad mediante autenticación básica y tokens JWT.

Conceptos Técnicos Aplicados:
> - Creación de APIs asíncronas con `FastAPI`.
> - Integración con MongoDB mediante `Motor` o `PyMongo`.
> - Modelado de datos con `Pydantic` y esquemas BSON.
> - Implementación de Autenticación Básica (Username/Password).
> - Seguridad avanzada mediante JSON Web Tokens (JWT).
> - Organización modular por Routers.

Stack: Python, FastAPI, MongoDB, Pydantic, Uvicorn.

Cómo ejecutar:
1. Instalar dependencias: `pip install -r requirements.txt`.
2. Configurar variables de entorno en un archivo `.env` (Mongo URI).
3. Iniciar el servidor: `uvicorn main:app --reload`.

Notas de aprendizaje: Se practicó la transición de APIs en memoria a persistencia real y la implementación de flujos de seguridad estándar en la industria para proteger endpoints sensibles.