#include <iostream>
#include <string>
using namespace std;


struct Song {
    string title;
    string artist;
    int ratings[3];
    Song* next;
    Song* prev;
};

Song* head = nullptr;
Song* current = nullptr;


void add(string title, string artist, int ratings[]) {
    Song* newSong = new Song();

    newSong->title = title;
    newSong->artist = artist;

    for (int i = 0; i < 3; i++) {
        newSong->ratings[i] = ratings[i];
    }
    newSong->next = nullptr;

    if (head == nullptr) {
        newSong->prev = nullptr;
        head = newSong;
        current = newSong;
    }
    else {
        Song* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newSong;
        newSong->prev = temp;
    }

}
void nextSong(){
     if (current != nullptr && current->next != nullptr) {
        current = current->next;
    }
}
void prevSong() {
    if (current != nullptr && current->prev != nullptr) {
        current = current->prev;
    }
}
void removeCurrent() {
    if (current == nullptr) return;

    Song* temp = current;
 if (temp->prev != nullptr)
        temp->prev->next = temp->next;
  if (temp->next != nullptr)
        temp->next->prev = temp->prev;


    if (temp == head)
        head = temp->next;


    if (temp->next != nullptr)
        current = temp->next;
    else
        current = temp->prev;

    delete temp;
}
void display() {
    Song* temp = head;

    while (temp != nullptr) {
        if (temp == current)
            cout << "-> ";
        else
            cout << "   ";

        cout << temp->title << " - " << temp->artist << " [";
  for (int i = 0; i < 3; i++) {
            cout << temp->ratings[i];
            if (i < 2) cout << ", ";
        }

        cout << "]" << endl;

        temp = temp->next;
    }

    cout << "-------------------" << endl;
}
int main(){
     int r1[3] = {5, 3, 1};
    int r2[3] = {8, 2, 5};
    int r3[3] = {6, 4, 8};

    add("Song1", "Artist1", r1);
    add("Song2", "Artist2", r2);
    add("Song3", "Artist3", r3);

    display();

    nextSong();
    display();

    prevSong();
    display();

    removeCurrent();
    display();

    return 0;

}


