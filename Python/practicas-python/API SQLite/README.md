# Task Manager (Flask + SQLite)

Descripción: Un gestor de tareas ligero que utiliza SQLite como base de datos local y SQLAlchemy como ORM. Permite crear, marcar como completadas y eliminar tareas mediante una interfaz web sencilla.

Conceptos Técnicos Aplicados:
> - Configuración de base de datos local con `SQLite`.
> - Uso de `render_template` para servir plantillas HTML dinámicas (`Jinja2`).
> - Gestión de sesiones y commits en base de datos.
> - Manejo de rutas y parámetros dinámicos (`/done/<id>`).

Stack: Python, Flask, SQLite, Jinja2.

Cómo ejecutar:
1. Instalar Flask y Flask-SQLAlchemy.
2. Ejecutar `python app.py`.
3. Acceder a `http://localhost:4002`.

Notas de aprendizaje: Este proyecto sirvió para entender el flujo completo de una aplicación web pequeña, desde la persistencia local hasta el renderizado de vistas en el servidor.
