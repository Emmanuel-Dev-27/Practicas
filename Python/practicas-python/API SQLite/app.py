import os
from flask import Flask, redirect, render_template, request, url_for
from flask_sqlalchemy import SQLAlchemy


# Ruta relativa para la base de datos 
basedir = os.path.abspath(os.path.dirname(__file__)) 
db_path = basedir + '/database/tasks.db' 

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///' + db_path
db = SQLAlchemy(app)

class Task(db.Model):
  id = db.Column(db.Integer, primary_key=True)
  content = db.Column(db.String(200))
  done = db.Column(db.Boolean)

# para crear una tabla
  # def __repr__(self):
  #   return f'<Task {self.id} - {self.content}>'

# with app.app_context():
#   db.create_all()

@app.route('/')
def home():
  tasks = Task.query.all()
  return render_template('index.html', tasks = tasks)

@app.route('/create-task', methods=['POST'])
def create():
  task = Task(content=request.form['content'], done=False)
  db.session.add(task)
  db.session.commit()
  return redirect(url_for('home'))

@app.route('/done/<id>')
def done(id):
  task = Task.query.filter_by(id=int(id)).first()
  task.done = not(task.done)
  db.session.commit()
  return redirect(url_for('home'))

# @app.route('/edit/<id>')
# def edit(id):
#   task = Task.query.filter_by(id=int(id)).first()
#   return render_template('edit.html', task=task)

@app.route('/delete/<id>')
def delete(id):
  task = Task.query.filter_by(id=int(id)).delete()
  db.session.commit()
  return redirect(url_for('home'))



if __name__ == '__main__':
  app.run(debug=True, port=4002)