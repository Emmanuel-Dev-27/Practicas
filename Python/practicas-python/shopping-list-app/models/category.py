from utils.db import db

# Crear la base de datos
def init_db():
    db.create_all()


class Category(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(200), nullable=False)

    def __init__(self, name):
        self.name = name

class Product(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(200), nullable=False)
    quantity = db.Column(db.Integer, nullable=False)
    price = db.Column(db.Float)
    done = db.Column(db.Boolean,default=False)
    category_id = db.Column(db.Integer, db.ForeignKey('category.id'), nullable=False)
    
    def __init__(self, name, quantity, price, category_id):
        self.name = name
        self.quantity = quantity
        self.price = price
        self.category_id = category_id
