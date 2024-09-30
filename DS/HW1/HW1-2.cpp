// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstring>

using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int v, Node* n) : value(v), next(n) {}
};

void print_list(Node* n) {
    if (n == NULL) {
        cout << "\n";
        return;
    }
    cout << n->value <<" ";
    print_list(n->next);
}
void insert_node(int v, Node** n) {
    if (*n == NULL || (*n)->value >= v) {
        *n = new Node(v, *n);
    }
    else {
        insert_node(v, &(*n)->next);
    }
}

void delete_node(int v, Node** n) {
    if (*n == NULL) 
        return;

    if ((*n)->value == v) {
        Node* temp = *n;
        *n = (*n)->next;
        delete temp;
        delete_node(v, n);
    } else {
        delete_node(v, &(*n)->next);
    }
}


char c;
int i;

int main() {
    Node* head = NULL;

    while (true) {
        cout << "Input or Delete? ";
        cin >> c;
        if (tolower(c) == 'i') {
            cout << "Input an integer? ";
            cin >> i;
            insert_node(i,&head);
        }
        else if (tolower(c) == 'd') {
            cout << "Delete which integer? ";
            cin >> i;
            delete_node(i,&head);
        }
        print_list(head);
    }
}
