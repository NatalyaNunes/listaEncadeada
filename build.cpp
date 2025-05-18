#include <iostream>

struct Node{
    int data;
    Node *next;
};

Node* build123(){
    Node *n1 = new Node;
    n1 -> data = 1;
    n1 -> next = nullptr;

    Node *n2 = new Node;
    n2 -> data = 2;
    n2 -> next = nullptr;

    Node *n3 = new Node;
    n3 -> data = 3;
    n3 -> next = nullptr;

    n1 -> next = n2;
    n2 -> next = n3;

    return n1;
}

void push_front(Node* &I, int value){
    Node* ni = new Node;
    ni->data = value;
    ni->next = I;
    I = ni;
}

Node *get_last(Node *L){
    Node *last = L;
    while(L != nullptr ){
        last = L;
        L = L->next;
    }
    return last;
}

void push_back(Node* &L, int value){
    Node* nf = new Node;
    nf->data = value;
    nf->next = nullptr;

    Node* p = get_last(L);
    if(p == nullptr){
        L = nf;
    }else{
        p->next = nf;
    }
}

void insert(Node* &L, Node* prev, int value){
    Node* nn = new Node;
    nn->data = value;
    if(prev == nullptr){
        nn->next = L;
        L = nn;
    }else{
        nn->next = prev->next;
        prev->next = nn;
    }
}

void print_list(Node* L){
    std::cout << "* -> ";
    while(L != nullptr){
        std::cout << L->data << " -> ";
        L = L->next;
    }
    std::cout <<"Null\n";
    
}

int main(){

    Node* L = build123();
    Node* prev = L->next;

    print_list(L);

    std::cout << "Insertion front: \n";
    push_front(L, 0);
    print_list(L);

    std::cout << "Insertion back: \n";
    push_back(L, 5);
    print_list(L);

    std::cout << "Insertion center: \n";
    insert(L, prev, 4);
    print_list(L);

    return 0;
}