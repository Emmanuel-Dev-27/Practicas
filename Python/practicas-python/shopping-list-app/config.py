import os


basedir = os.path.abspath(os.path.dirname(__file__))
db_dir = os.path.join(basedir, 'database') 
db_path = os.path.join(db_dir, 'task.db')

if not os.path.exists(db_dir): 
    os.makedirs(db_dir)


DATABASE_CONNECTION_URI = f'sqlite:///{db_path}'