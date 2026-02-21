#include <iostream>
using namespace std;

void intercambiar(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int x, y;
    cout << "Ingrese x y y: ";
    cin >> x >> y;
    if (!cin) {
        cerr << "Entrada invalida: debe ingresar dos enteros.\n";
        return 1;
    }

    intercambiar(x, y);

    cout << "Despues del intercambio: x=" << y << " y=" << x << endl;
    return 0;
}
