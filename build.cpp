#include <iostream>

struct Node{
    int data;
    Node *next;
};

Node* build1234(){
    Node *n1 = new Node;
    n1 -> data = 1;
    n1 -> next = nullptr;

    Node *n2 = new Node;
    n2 -> data = 2;
    n2 -> next = nullptr;

    Node *n3 = new Node;
    n3 -> data = 3;
    n3 -> next = nullptr;

    Node *n4 = new Node;
    n4 -> data = 4;
    n4 -> next = nullptr;

    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;

    return n1;
}

void push_front(Node* &I, int value){
    Node* ni = new Node;
    ni->data = value;
    ni->next = I;
    I = ni;
}

Node* get_last(Node *L){
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

//Limpar as posições

void pop_front(Node* &H){
    if(H -> next == nullptr)return;

    Node* target = H;
    H = H -> next;

    delete target;
}

Node* prev_get_last(Node *L){
    if(L == nullptr) return nullptr;

    Node* anterior = new Node;
    anterior = nullptr;
    Node* atual = new Node;
    atual = L;
    Node* frente = new Node;
    frente = L->next;

    while(frente != nullptr ){
        anterior = atual;
        atual = frente;
        frente = frente->next;
    }
    return anterior;
}


//Verificar se só tiver um elemento
void pop_back(Node* &H){
    if(H == nullptr) return;

    Node* prev = prev_get_last(H);
    
    delete prev->next;

    prev -> next = nullptr;

    /** jeito do professor: 
     * Node* target = prev->next;
     * prev->next = nullptr;
     * delete target;
     *  */
}

int size_list(Node* L){
    int size = 0;
    while(L != nullptr){
        ++size;
    }
    return size;
}

Node* get_prev(Node* &L, int idx){
    
}

void pop_at(Node* &H, int idx){
    if(H == nullptr || size_list(H) < idx || idx < 0)return;
    
}

void clear(Node* L){

}

void reverse(Node* L){

}

int main(){

    Node* L = build1234();
    Node* prev = L->next;

    print_list(L);

    std::cout << "\nInsertion front: \n";
    push_front(L, 0);
    print_list(L);

    std::cout << "\nInsertion back: \n";
    push_back(L, 5);
    print_list(L);

    std::cout << "\nInsertion center: \n";
    insert(L, prev, 12);
    print_list(L);

    std::cout << "\nPop front: \n";
    pop_front(L);
    print_list(L);

    std::cout << "\nPop back: \n";
    pop_back(L);
    print_list(L);

    std::cout << "\nPop at: \n";
    pop_at(L, 2);
    print_list(L);

    return 0;
}