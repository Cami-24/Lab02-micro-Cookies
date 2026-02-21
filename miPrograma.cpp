#include <iostream>
#include <string>

using namespace std;

//mis constantes
const int total_galletas = 16;

//mis arreglos

//opciones
string nombres[total_galletas] = {
    "Chispazo",
    "Cinnamon Roll Cookie",
    "Doble Chocolate",
    "Cocada",
    "Caramel Mani",
    "Choco Mani",
    "Croqui Pistacho",
    "Pistacho Nutella",
    "La Oreo",
    "Smore",
    "Dubai Cookie",
    "Chocolate Dubai",
    "Lemon Pie",
    "Kit Kat Cookie",
    "Marmoleada",
    "M&M Festival"
};

//precios
double precios[total_galletas] = {
    25,25,25,25,25,25,25,30,25,25,30,30,25,25,25,25
};

//carrito
int carrito [total_galletas] = {0};


//funciones


//Menú
void mostrarMenu(){
    cout << "\n=== Bienvenido a CookieBoom, las mejoras Galletas NY de Guate ===" << endl;
    cout << "1. Ver catalogo y agregar galletas al carrito" << endl;
    cout << "2. Ver total de galletas" << endl;
    cout << "3. Ver Factura" << endl;
    cout << "4. Salir" << endl;
    cout << "Opcion: ";
}

void mostrarCatalogo() {
    cout << "\n===== CATALOGO =====\n";

    for (int i = 0; i < total_galletas; i++) {   // Uso de ciclo for
        cout << i << ". "
             << nombres[i]
             << " - Q" << precios[i] << endl;
    }
}

//funcion principal

int main(){
    string nombreCliente; //string
    int opcion; //int
    bool programaActivo = true; //bool

    cout << "Ingresa tu nombre: ";
    getline(cin, nombreCliente); //leer string con espacios

    while (programaActivo){

        mostrarMenu();
        cin >> opcion;

        if (opcion == 1) {

            mostrarCatalogo();

            int tipo, cantidad;

            cout << "Seleccione el numero de galleta: ";
            cin >> tipo;

            cout << "Cantidad: ";
            cin >> cantidad;

            if (tipo >= 0 && tipo < total_galletas && cantidad > 0) {
                carrito[tipo] += cantidad;
                cout << "Agregaste " << cantidad
                     << " de " << nombres[tipo] << endl;
            }
            else {
                cout << "Datos invalidos.\n";
            }
        }
        else if (opcion == 2) {

            int total = 0;
            bool vacio = true;

            cout << "\n===== CARRITO =====\n";

            for (int i = 0; i < total_galletas; i++) {
                if (carrito[i] > 0) {
                    cout << nombres[i]
                         << " x" << carrito[i] << endl;
                    total += carrito[i];
                    vacio = false;
                }
            }

            if (vacio) {
                cout << "El carrito está vacío." << endl;
            } else {
                cout << "Total de galletas en el carrito: "
                     << total << endl;
            }
        }

        else if (opcion == 3) {

            double totalPrecio = 0;

            cout << "\n===== FACTURA =====\n";

            for (int i = 0; i < total_galletas; i++) {

                if (carrito[i] > 0) {

                    // Conversión o casteo explícito
                    double subtotal =
                        static_cast<double>(carrito[i]) * precios[i];

                    cout << nombres[i]
                         << " x" << carrito[i]
                         << " = Q" << subtotal << endl;

                    totalPrecio += subtotal;
                }
            }

            cout << "TOTAL A PAGAR: Q"
                 << totalPrecio << endl;
        }

        else if (opcion == 4) {

            cout << "Gracias por su compra, "
                 << nombreCliente;
            cout << "! Vuelva pronto a CookieBoom.\n";

            programaActivo = false;
        }

        else {
            cout << "Opcion invalida.\n";
        }
    }

    return 0;
}