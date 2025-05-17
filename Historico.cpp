#include <iostream>

struct Node{
    int data;
    std::string description;
    Node* next;
};

//push_front
void add_command(Node* &history, int id, std::string command){
    Node* new_command = new Node;

    new_command->data = id;
    new_command->description = command;
    new_command->next = history;

    history = new_command;
}

void print_history(Node* history){
    while(history != nullptr){
        std::cout << history->data << " -> ";
        std::cout << history->description << "\n";
        history = history->next;
    }
}

int main(){
    Node* history = nullptr;
    
    add_command(history, 1, "--help");
    add_command(history, 2, "-v");

    print_history(history);

    return 0;
}