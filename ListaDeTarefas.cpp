#include <iostream>
#include <string>
#include <iomanip>

struct Node{
    int id;
    std::string task;
    Node* next;
};

void push_back(Node* &L, int id, std::string task){
    Node* new_task = new Node;

    new_task->id = id;
    new_task->task = task;
    new_task->next = nullptr;

    if(L == nullptr){
        L = new_task;
    }else{
        Node* present_task = L;
        while(present_task->next != nullptr){
            present_task = present_task->next;
        }
        present_task->next = new_task;
    }
}

void add_task(Node* &L, std::string task){

}

void remove_task(Node* &L, std::string task){

}

void print_tasks(Node* L){
    std::cout << "Tasks:\n\n";

    std::cout << std::string(50, '-') << "\n";
    std::cout << std::left
              << std::setw(5) << "Id"
              << std::setw(45) << "Tarefa" << "\n";
    std::cout << std::string(50, '-') << "\n";

    while(L != nullptr){
        std::cout << std::left
            << std::setw(5) << L->id
            << std::setw(45) << L->task << "\n";
        L = L->next;
    }
}

int main(){
    Node* T = nullptr; 

    push_back(T, 1, "Estudar listas encadeadas");
    push_back(T, 2, "Implementar função de remoção");
    push_back(T, 3, "Testar a lista");

    print_tasks(T);

    return 0;
}