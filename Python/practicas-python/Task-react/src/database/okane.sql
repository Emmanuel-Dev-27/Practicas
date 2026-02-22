-- Cuenta
CREATE TABLE IF NOT EXISTS cuenta (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nombre VARCHAR(100) NOT NULL, -- Nombre de la cuenta
    descripcion VARCHAR(255),
    tipo VARCHAR(20) NOT NULL CHECK (tipo IN ('cuenta', 'deposito')), -- Tipo de cuenta
    saldo DECIMAL(10, 2) DEFAULT 0.00, -- Saldo actual de la cuenta
    creado DATETIME DEFAULT CURRENT_TIMESTAMP
);

-- Transacción
CREATE TABLE IF NOT EXISTS transactions (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    fecha DATE NOT NULL, -- Fecha de la transacción
    tipo VARCHAR(20) NOT NULL CHECK (tipo IN ('transferencia', 'deposito', 'retiro')), -- Tipo de transacción
    cuenta_id INTEGER NOT NULL, -- Cuenta correspondiente a esta transacción
    monto DECIMAL(10, 2) NOT NULL, -- Monto de la transacción
    descripcion VARCHAR(255),
    creado DATETIME DEFAULT CURRENT_TIMESTAMP
);

-- Relaciones entre las tablas
CREATE TABLE IF NOT EXISTS cuenta_transactions (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    cuenta_id INTEGER NOT NULL, 
    transaction_id INTEGER NOT NULL, 
    FOREIGN KEY (cuenta_id) REFERENCES cuenta(id), 
    FOREIGN KEY (transaction_id) REFERENCES transactions(id)
);

-- Historial de transactions
CREATE TABLE IF NOT EXISTS historial (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    transaction_id INTEGER NOT NULL, 
    fecha DATE NOT NULL, 
    descripcion VARCHAR(255),
    creado DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (transaction_id) REFERENCES transactions(id)
);

-- Historial de cuentas
CREATE TABLE IF NOT EXISTS cuenta_historial (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    account_id INTEGER NOT NULL, 
    fecha DATE NOT NULL, 
    descripcion VARCHAR(255),
    creado DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (account_id) REFERENCES cuenta(id)
);

-- Saldo total
CREATE TABLE IF NOT EXISTS saldo_total AS
SELECT cuenta_id, SUM(monto) AS balance 
FROM (
    SELECT t.cuenta_id, t.monto 
    FROM transactions 
    JOIN cuenta_transactions ON transactions.account_id = cuenta_transactions.cuenta_id
    WHERE transactions.type IN ('transferencia', 'deposito')
) AS subquery;
