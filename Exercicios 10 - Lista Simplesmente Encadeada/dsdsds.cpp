#include <iostream>
#include <unordered_map>

// Defini��o da estrutura para um n� da lista encadeada
struct Node {
    std::string data;
    Node* next;
};

// Fun��o para adicionar um n� no in�cio da lista
void push(Node** head_ref, std::string new_data) {
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Fun��o para imprimir a lista encadeada
void printList(Node* node) {
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

// Fun��o para classificar as senhas n�o seguras
Node* naoSeguras(Node* head) {
    std::unordered_map<std::string, int> passwordCount;

    Node* current = head;
    Node* result = nullptr;

    // Contagem da frequ�ncia de cada senha
    while (current != nullptr) {
        passwordCount[current->data]++;
        current = current->next;
    }

    current = head;
    // Verifica��o de senhas n�o seguras
    while (current != nullptr) {
        if (current->data.length() < 4 || passwordCount[current->data] > 5) {
            push(&result, current->data);
        }
        current = current->next;
    }
    return result;
}

// Fun��o principal
int main() {
    // Exemplo de entrada
    Node* head = nullptr;
    push(&head, "abcd");
    push(&head, "defda");
    push(&head, "abcd");
    push(&head, "absd");
    push(&head, "abcd");
    push(&head, "defa");
    push(&head, "ghi");
    push(&head, "abcd");
    push(&head, "abcd");
    push(&head, "abcd");
    push(&head, "jklds");
    push(&head, "mnosd");
    push(&head, "pqrsd");

    std::cout << "Lista original: ";
    printList(head);

    Node* result = naoSeguras(head);
    std::cout << "Senhas n�o seguras: ";
    printList(result);

    return 0;
}
