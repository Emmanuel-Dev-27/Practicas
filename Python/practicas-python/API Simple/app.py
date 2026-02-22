from flask import Flask, jsonify, request, render_template

app = Flask(__name__)

from productos import products

@app.route('/')
def page():
  return render_template('pagina.html')

@app.route("/ping")
def ping():
  return jsonify({"message":"pong"})

@app.route('/products')
def getproducts():
  return jsonify({"message": "Products list", "products": products})

@app.route('/products', methods=['POST'])
def addProduct():
  newProduct = {
    "name" : request.json['name'],
    "price" : request.json['price'],
    "quantity" : request.json['quantity']
  }
  products.append(newProduct)
  return jsonify({"message": "Products added succefully", "products": products}) 

@app.route('/products/<string:product_name>')
def getproduct(product_name):
  productsFound = [product for product in products if product["name"] == product_name]
  if (len(productsFound) > 0):
    return jsonify({"message":"Product found", "product": productsFound[0]})
  return jsonify({"message":"Product not found"})

@app.route('/products/<string:product_name>', methods=['PUT'])
def editProduct(product_name):
  productFound = [product for product in products if product["name"] == product_name]
  if (len(product_name) > 0):
    productFound[0]['name'] = request.json['name']
    productFound[0]['price'] = request.json['price']
    productFound[0]['quantity'] = request.json['quantity']
    return jsonify({"message": "Product Updated", 
                    "product edit": productFound[0]
    })
  return jsonify({"message": "Product not found"})

@app.route('/products/<string:product_name>', methods=['DELETE'])
def deleteProduct(product_name):
  productFound = [product for product in products if product["name"] == product_name]
  if (len(productFound) > 0):
    products.remove(productFound[0])
    return jsonify({"message": "Product deleted", "Products list": products})
  return jsonify({"message": "Product not found"})


if __name__ == '__main__':
  app.run(debug=True, port=4000) 