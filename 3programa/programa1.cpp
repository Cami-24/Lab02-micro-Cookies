#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Cuantos valores desea ingresar? ";
    cin >> n;
    if (!cin || n <= 0) {
        cerr << "Entrada invalida: debe ingresar un entero mayor que 0.\n";
        return 1;
    }

    int suma = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Valor " << (i + 1) << ": ";
        if (!(cin >> x)) {
            cerr << "Entrada invalida al leer valor.\n";
            return 1;
        }
        suma += x;
    }

    double promedio = suma / n;

    cout << fixed << setprecision(2);
    cout << "Promedio: " << promedio << endl;

    return 0;
}
