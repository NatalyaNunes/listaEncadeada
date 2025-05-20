#include <iostream>

struct Node_D{
    int data;
    Node_D* next;
    Node_D* prev;
};

Node_D* build_D1234(){
    Node_D* n0 = new Node_D();
    n0->next = nullptr;
    n0->prev = nullptr;

    Node_D* n1 = new Node_D();
    n1->data = 1;
    n1->next = nullptr;
    n1->prev = n0;

    n0->next = n1;

    Node_D* n2 = new Node_D();
    n2->data = 2;
    n2->next = nullptr;
    n2->prev = n1;

    n1->next = n2;

    Node_D* n3 = new Node_D();
    n3->data = 3;
    n3->next = nullptr;
    n3->prev = n2;

    n2->next = n3;

    Node_D* n4 = new Node_D();
    n4->data = 4;
    n4->next = nullptr;
    n4->prev = n3;

    n3->next = n4;

    return n0;
};

void print_list_D(Node_D* L){
    std::cout << "* -> ";
    while(L != nullptr){
        std::cout << L->data << " -> ";
        L = L->next;
    }
    std::cout <<"Null\n";
    
}

int main(){
    Node_D* L = build_D1234();
    print_list_D(L);

    return 0;
}