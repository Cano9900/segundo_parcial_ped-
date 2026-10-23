#include <iostream> 

struct Node
{
  int data;
  Node *next;
  Node *prev;
};

void Insert(Node*& head, int data){
    Node* new_node = new Node{data, head, nullptr};

    if(head != nullptr){
        head->prev = new_node;
    }

    head = new_node;
}

void Insertalfinal(Node*& head, int data){
    Node* new_node = new Node{data, nullptr, nullptr};  //next y prev apuntan a nullptr, antes de hcaer los cambios.

    //Si esto ocurre es porque la lista esta vacia
    if(head == nullptr){
        head = new_node;
        return;
    }

    //Pero esto pasa si acaso no esta vacia
    Node* current = head;

    while(current->next != nullptr){
        current = current->next;
    }

    current->next = new_node;  //El current apunta al siguiente que se convierte en el nuevo nodo, y ese nuevo nodo apunta de regreso al anterior. -> <-
    new_node->prev = current;
}

void PrintList(Node* head){
    Node* current = head;

    while(current != nullptr){
        std::cout<<current->data<<" -> ";
        current = current->next;
    }

    std::cout<<std::endl;
}
//Funcion para liberar memoria. 
void Liberarmemoria (Node*& head){

     while(head != nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


int main (){
 Node* lista = nullptr;

    int option = 0;

    do{
        std::cout<<"1. Insertar al inicio"<<std::endl;
        std::cout<<"2. Insertar al final"<<std::endl;
        std::cout<<"3. Imprimir lista"<<std::endl;
        std::cout<<"4. Liberar memoria"<<std::endl;
        
        std::cin>>option;

        switch(option){
            case 1:{
                int n;
                std::cout<<"Ingrese un numero: ";
                std::cin>>n;

                Insert(lista, n);

                break;
            }
            case 2:{
                int n;
                std::cout<<"Ingrese un numero: ";
                std::cin>>n;

                Insertalfinal(lista, n);

                break;
            }
            case 3:{
                PrintList(lista);
                break;
            }
            case 4:{
                std::cout<<"Liberando memoria..."<<std::endl;
                Liberarmemoria(lista);
                break;
            }
        
            default:{
                std::cout<<"Opcion invalida"<<std::endl;
                break;
            }
        }
    }while(option != 100);


    return 0;
}
