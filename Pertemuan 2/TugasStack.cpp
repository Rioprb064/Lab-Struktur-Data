#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedStack {
    Node* top;  

    LinkedStack() {
        top = NULL;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top; 
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack kosong!\n";
            return;
        }
        Node* temp = top;
        cout << top->data << " dihapus dari stack.\n";
        top = top->next; 
        delete temp;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack kosong!\n";
            return;
        }
        Node* temp = top;
        cout << "Isi stack: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedStack st;
    int num;

    cout << "Masukkan 3 angka untuk push ke stack:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Angka ke-" << i+1 << ": ";
        cin >> num;
        st.push(num);
    }

    st.display(); 

    cout << "\nPop 1 angka\n";
    st.pop();

    st.display(); 

    return 0;
}