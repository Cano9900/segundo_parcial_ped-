#include <iostream> 
#include <stack>


void RemoveConsecutiveDuplicates(std::stack<int>& values) {
    //Pila vacia, nada se procesa
    if (values.empty()) {
        return;
    }

    std::stack<int> aux; 

    //  pila original desde el tope hacia el fondo
    while (!values.empty()) {
        int current = values.top();
        values.pop(); //la va eliminando

        // Por si la pila auxiliar está vacía  
        // al último elemento lo vamos a guardar en el tope de la pila auxiliar, lo agregamos.
        if (aux.empty() || aux.top() != current) {
            aux.push(current);
        }
    }

    // Invertimos el orden nuevamente para restaurar 
    // la orientación original el tope original debe quedar arriba
    while (!aux.empty()) {
        values.push(aux.top());
        aux.pop();
    }
}

// Función para ver la pila
void ImprimirPila(std::stack<int> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::stack<int> values;

    // Insertamos los elementos desde el fondo hacia el tope
    // para que al imprimir queden: 5 5 5 8 8 3 7 7 2 2 (tope -> fondo)
    int elementos[] = {2, 2, 7, 7, 3, 8, 8, 5, 5, 5};
    for (int num : elementos) {
        values.push(num);
    }

    std::cout << "Pila inicial (tope a fondo):   ";
    ImprimirPila(values);

    // Ejecutamos la función solicitada
    RemoveConsecutiveDuplicates(values);

    std::cout << "Pila resultante (tope a fondo): ";
    ImprimirPila(values);

    return 0;
}
