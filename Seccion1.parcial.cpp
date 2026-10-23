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

void PrintList(Node* head){
    Node* current = head;

    while(current != nullptr){
        std::cout<<current->data<<" -> ";
        current = current->next;
    }

    std::cout<<std::endl;
}


int main (){




    return 0; 
}