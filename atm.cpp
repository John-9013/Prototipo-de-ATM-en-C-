#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Constantes del sistema
const string PIN_CORRECTO = "1234";
const double SALDO_INICIAL = 500000.0; // Saldo inicial simulado

// Prototipos de funciones
bool autenticarUsuario();
void mostrarMenu();
void consultarSaldo(double saldo);
void realizarDeposito(double &saldo);
void realizarRetiro(double &saldo);

int main() {
    double saldoActual = SALDO_INICIAL;
    int opcion;
    bool sesionActiva = false;

    cout << "===========================================\n";
    cout << "        BIENVENIDO A TECBANK S.A.          \n";
    cout << "      Sistema ATM TecBank201D v1.0         \n";
    cout << "===========================================\n\n";

    sesionActiva = autenticarUsuario();

    while (sesionActiva) {
        mostrarMenu();
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            if (cin.eof()) break;
            cout << "\nError: Entrada no valida. Intente de nuevo.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (opcion) {
            case 1: consultarSaldo(saldoActual); break;
            case 2: realizarDeposito(saldoActual); break;
            case 3: realizarRetiro(saldoActual); break;
            case 4:
                cout << "\nRetire su tarjeta. Gracias por usar TecBank S.A.\n";
                sesionActiva = false;
                break;
            default:
                cout << "\nOpcion no valida. Por favor, intente de nuevo.\n";
        }
    }
    return 0;
}

bool autenticarUsuario() {
    string pinIngresado;
    int intentos = 3;

    while (intentos > 0) {
        cout << "Por favor, ingrese su PIN de 4 digitos: ";
        if (!(cin >> pinIngresado)) break;

        if (pinIngresado == PIN_CORRECTO) {
            cout << "\nAcceso concedido. Bienvenido.\n";
            return true;
        }
        intentos--;
        cout << "PIN incorrecto. Intentos restantes: " << intentos << "\n\n";
    }

    cout << "Tarjeta bloqueada por motivos de seguridad. Contacte a soporte.\n";
    return false;
}

void mostrarMenu() {
    cout << "\n-------------------------------------------\n";
    cout << "           MENU DE OPERACIONES             \n";
    cout << "-------------------------------------------\n";
    cout << "1. Consultar Saldo\n";
    cout << "2. Realizar Deposito\n";
    cout << "3. Realizar Retiro\n";
    cout << "4. Salir / Terminar\n";
    cout << "-------------------------------------------\n";
}

void consultarSaldo(double saldo) {
    cout << fixed << setprecision(2);
    cout << "\nSu saldo actual es: $" << saldo << "\n";
}

void realizarDeposito(double &saldo) {
    double monto;
    cout << "\nIngrese el monto a depositar: $";
    if (!(cin >> monto)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error: Monto no valido.\n";
        return;
    }

    if (monto > 0) {
        saldo += monto;
        cout << fixed << setprecision(2);
        cout << "Deposito exitoso. Nuevo saldo: $" << saldo << "\n";
    } else {
        cout << "Error: El monto a depositar debe ser mayor a cero.\n";
    }
}

void realizarRetiro(double &saldo) {
    double monto;
    cout << "\nIngrese el monto a retirar: $";
    if (!(cin >> monto)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error: Monto no valido.\n";
        return;
    }

    if (monto <= 0) {
        cout << "Error: El monto a retirar debe ser mayor a cero.\n";
    } else if (monto > saldo) {
        cout << "Error: Fondos insuficientes. Su saldo actual es menor al monto solicitado.\n";
    } else {
        saldo -= monto;
        cout << fixed << setprecision(2);
        cout << "Retiro exitoso. Por favor, retire su dinero.\n";
        cout << "Nuevo saldo: $" << saldo << "\n";
    }
}
