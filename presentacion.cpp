#include <iostream>
#include <string>

using namespace std;

class PresentacionPersonal {
private:
    string nombre;
    string perfil;
    int edad;
    string pais;
    string ciudad;

public:
    PresentacionPersonal(const string& nom, const string& perf, int ed, const string& p, const string& c) {
        nombre = nom;
        perfil = perf;
        edad = ed;
        pais = p;
        ciudad = c;
    }

    void mostrarPresentacion() const {
        cout << "===========================================\n";
        cout << "           PRESENTACION PERSONAL           \n";
        cout << "===========================================\n";
        cout << "Nombre : " << nombre << "\n";
        cout << "Perfil : " << perfil << "\n";
        cout << "Edad   : " << edad << " anios\n";
        cout << "Pais   : " << pais << "\n";
        cout << "Ciudad : " << ciudad << "\n";
        cout << "===========================================\n";
    }
};

int main() {
    PresentacionPersonal miPresentacion(
        "John Edison Sarmiento",
        "Estudiante Programacion Software",
        36,
        "Colombia",
        "Bogota DC"
    );

    miPresentacion.mostrarPresentacion();

    return 0;
}

