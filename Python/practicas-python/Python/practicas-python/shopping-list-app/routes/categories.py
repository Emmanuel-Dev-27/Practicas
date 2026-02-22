from flask import Blueprint, render_template, request, redirect, url_for, flash
from models.category import Category, Product, db 


categories = Blueprint("categories", __name__)


@categories.route("/")
def index():
    categories = Category.query.all()
    products = Product.query.all()
    # De momento necesito que funcione asi que me voy por lo que se me ocurre ahora 
    # aunque no sea muy eficionte 
    totals = []
    for category in categories:
        suma = 0
        ob = []
        for product in products:
            if category.id == product.category_id:
                suma += product.price * product.quantity
        ob = [category.id, suma]
        totals.append(ob)
    
    print(totals)
    
    return render_template("index.html", categories=categories, products=products, totals=totals)


@categories.route("/new_category", methods=["POST"])
def new_category():
    nameCategory = request.form["nameCategory"]
    
    print(nameCategory)
    
    new_category = Category(name=nameCategory)

    print(new_category)
    
    db.session.add(new_category)
    db.session.commit()
    
    
    flash("Create category successfully")
    
    return redirect(url_for("categories.index"))


@categories.route("/edit_category/<id>", methods=["GET", "POST"])
def edit_category(id):
    category = Category.query.get(id)
    
    if request.method == "POST":
        
        nameCategory = request.form["nameCategory"]
        category.name = nameCategory
        db.session.commit()

        return redirect(url_for("categories.index"))

    return render_template("edit_category.html", category=category)


@categories.route("/delete_category/<id>")
def delete_category(id):
    category = Category.query.get(id)
    
    products = db.session.query(Product).join(Category).filter(Category.id == id)
    
    for product in products:
        db.session.delete(product)
    
    db.session.delete(category)
    db.session.commit()
    
    flash('Category deleted successfully')
    
    return redirect(url_for("categories.index"))


@categories.route("/new_product", methods=["POST"])
def new_product():
    nameProduct = request.form["nameProduct"]
    quantity = request.form["quantity"]
    price = request.form["price"]
    category_id = request.form["category_id"]
    
    new_product = Product(nameProduct, quantity, price, category_id)
        
    db.session.add(new_product)
    db.session.commit()
    
    flash("Create product successfully")
    
    return redirect(url_for("categories.index"))


@categories.route('/done/<id>')
def check(id):
    product = Product.query.get(id)
    
    product.done = not product.done
    
    db.session.commit()
    
    flash('Product done')
    
    return redirect(url_for("categories.index"))


@categories.route("/edit_product/<id>", methods=["GET", "POST"])
def edit_product(id):
    product = Product.query.get(id)
    categories = Category.query.all()
    
    if request.method == "POST":
        product.nameProduct = request.form["nameProduct"]
        product.quantity = request.form["quantity"]
        product.price = request.form["price"]
        product.category_id = request.form["category_id"]
    
        db.session.commit()
        
        flash('Product Updated')
        
        return redirect(url_for("categories.index"))

    return render_template("edit_product.html", product=product, categories=categories)


@categories.route("/delete_product/<id>")
def delete_product(id):
    product = Product.query.get(id)
    
    db.session.delete(product)
    db.session.commit()
    
    flash('Product deleted successfully')
    
    return redirect(url_for("categories.index"))