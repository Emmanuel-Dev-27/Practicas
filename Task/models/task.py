from utils.db import db

# Crear la base de datos
def init_db():
    db.create_all()


class Group(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(255), nullable=False)

    def __init__(self, name):
        self.name = name


class Step(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(255), nullable=False)
    group_id = db.Column(db.Integer, db.ForeignKey('group.id'), nullable=False)
    
    def __init__(self, name, group_id):
        self.name = name
        self.group_id = group_id


class Substep(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(255), nullable=False)
    step_id = db.Column(db.Integer, db.ForeignKey('step.id'), nullable=False)

    def __init__(self, name, step_id):
        self.name = name
        self.step_id = step_id