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
/*int main (){

stack<int>
    numbers.push(1); //encargada de insertar o agregar un elemento nuevo, y la va colocando por encima en la pila. 
    numbers.push(2);
    numbers.push(3);
    numbers.push(4);


}
   
   
   
   
   
   
   
   int main (){



    stack<int> numbers;
    numbers.push(1); //encargada de insertar o agregar un elemento nuevo, y la va colocando por encima en la pila. 
    numbers.push(2);
    numbers.push(3);
    numbers.push(4);

    cout<<"TOP: "<<numbers.top()<<endl; //4
    numbers.pop(); //Eliminar 4 //pop Es la función encargada de eliminar el elemento que le toca salir, la pila borra al que está mero arriba en la cima
    cout<<"TOP: "<<numbers.top()<<endl; //3
    numbers.pop(); //Eliminar 3
    cout<<"TOP: "<<numbers.top()<<endl; //2
    numbers.pop(); //Eliminar 2

    return 0;
}
