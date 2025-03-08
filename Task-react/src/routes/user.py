from flask import request, jsonify, Blueprint, g

from utils.database import get_db, list_users

api = Blueprint('api', __name__)

@api.route('/api/users', methods=['POST', 'GET'])
def users():
    if request.method == 'POST':
        requestData = request.json
        db = get_db()
        cursor = db.cursor()
        cursor.execute('''
            INSERT INTO users (name, email, password) VALUES (?, ?, ?)
        ''', (requestData['name'], 
            requestData['email'], 
            requestData['password']))
        db.commit()
        userId = cursor.lastrowid

        return jsonify({'id': userId})
    
    users = list_users()
    return jsonify(users)
    
@api.route('/api/user/<int:id>', methods=['GET']) 
def getUser(id):
    db = get_db()
    cursor = db.cursor()
    cursor.execute('''
                    SELECT id, name, email FROM users WHERE id = ?
                   ''', (id,))
    user = cursor.fetchone()
    return jsonify(dict(user))

@api.route('/api/user/<int:id>', methods=['DELETE'])
def deleteUser(id):
    print(id)
    db = get_db()
    cursor = db.cursor()
    cursor.execute('''
                    DELETE FROM users WHERE id = ?
                   ''', (id,))
    db.commit()

    users = list_users()

    return jsonify(users)

@api.route('/api/user/<int:id>', methods=['PUT'])
def updateUser(id):
    db = get_db()
    cursor = db.cursor()
    requestData = request.json
    cursor.execute('''
                    UPDATE users SET name = ?, email = ?, password = ? WHERE id = ?
                   ''', (requestData['name'], requestData['email'], requestData['password'], id))
    db.commit()
    users = list_users()
    return jsonify(users)    

@api.teardown_app_request  # Correct method name
def teardown_db(exception):
    db = getattr(g, '_database', None)
    if db is not None:
        db.close()

