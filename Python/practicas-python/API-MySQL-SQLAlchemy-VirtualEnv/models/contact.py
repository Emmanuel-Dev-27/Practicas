from utils.db import db


class Contact(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    fullname = db.Column(db.String(100), nullable=False)
    phone = db.Column(db.String(20), nullable=False)
    email = db.Column(db.String(100), nullable=False)

    def __init__(self, fullname, phone, email):
        self.fullname = fullname
        self.phone = phone
        self.email = email
