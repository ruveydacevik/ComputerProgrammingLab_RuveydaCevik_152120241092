#include <iostream>
#include <string>

using namespace std;

struct Node{
    string word;
    Node* next;

};
     Node* head= NULL;

     void add(string newWord);
     Node* yeniNode = new Node();
     yeniNode->word = newWord;
     yeniNode->next = NULL;

   if (head == NULL) {
        head = yeniNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = yeniNode;
    }

    void undo() {
    if (head == NULL)
        return;
    if (head -> next == NULL) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;

        while (temp -> next -> next != NULL) {
            temp = temp -> next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

        void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << "[" << temp -> word << "] -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}


     int main(){

         string input;

    while (true) {
        cout << "write a word (UNDO: Geri, EXIT: Cikis): ";
        cin >> input;

        if (input == "EXIT") break;

        if (input == "UNDO") {
            undo();
        } else {
            add(input);
        }

        display();
    }



         return 0;
     }


