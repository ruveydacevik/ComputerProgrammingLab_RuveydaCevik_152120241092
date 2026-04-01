#include <iostream>
#include <string>
using namespace std;

struct Package {
    string packageID;
    string destinationCity;
    int dimensions[3];
    Package* next;
};

struct Courier {
    string courierName;
    string vehicleType;
};

Package* stackTop = nullptr;

const int SIZE = 5;
Courier queue[SIZE];
int front = -1, rear = -1;

void push(string id, string city) {
    Package* yeni = new Package;
    yeni->packageID = id;
    yeni->destinationCity = city;
    yeni->next = stackTop;
    stackTop = yeni;
    cout << "Paket eklendi: " << id << endl;
};

void enqueue(string name, string vehicle) {
    if ((rear + 1) % SIZE == front) {
        cout << "Kurye sirasi dolu!" << endl;
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = {name, vehicle};
    cout << "Kurye kaydoldu: " << name << endl;
}


void dispatch() {
    if (stackTop == nullptr || front == -1) {
        cout << "Gonderim yapilamaz: Paket veya Kurye eksik!" << endl;
        return;
    }


    cout << ">> DISPATCH: " << queue[front].courierName << " kuryesi "
         << stackTop->packageID << " paketini aldi." << endl;


    Package* temp = stackTop;
    stackTop = stackTop->next;
    delete temp;

    if (front == rear) front = rear = -1;
    else front = (front + 1) % SIZE;
}


void display() {
    cout << "\n--- DURUM ---" << endl;
    cout << "Paketler (Stack): ";
    Package* p = stackTop;
    while(p) { cout << "[" << p->packageID << "] "; p = p->next; }

    cout << "\nKuryeler (Queue): ";
    if (front != -1) {
        int i = front;
        while(true) {
            cout << "(" << queue[i].courierName << ") ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
    }
    cout << "\n-------------\n";
}

int main() {
    push("P1", "Eskiþehir");
    push("P2", "Kütahya");
    enqueue("Ali", "Motor");
    enqueue("Veli", "Araba");

    display();
    dispatch();
    display();

    return 0;
}
