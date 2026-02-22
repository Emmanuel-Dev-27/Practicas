# Contactos Flask (MySQL Direct)

Descripción: Aplicación web para la gestión de contactos que utiliza `flask_mysqldb` para interactuar directamente con una base de datos MySQL mediante consultas SQL crudas. Implementa un sistema completo de CRUD con mensajes flash para retroalimentación al usuario.

Conceptos Técnicos Aplicados:
> - Conexión directa a MySQL sin ORM.
> - Ejecución de sentencias SQL (`SELECT`, `INSERT`, `UPDATE`, `DELETE`).
> - Gestión de cursores y transacciones.
> - Uso de `flash` para notificaciones en la interfaz.
> - Renderizado de plantillas con Jinja2.

Stack: Python, Flask, MySQL, HTML/CSS.

Cómo ejecutar:
1. Configurar los parámetros de conexión MySQL en `App.py`.
2. Ejecutar `python App.py`.

Notas de aprendizaje: Este ejercicio permitió practicar la escritura de SQL nativo y entender el manejo de cursores en Python, proporcionando un control total sobre las consultas a la base de datos.
