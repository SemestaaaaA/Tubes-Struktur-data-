#include <iostream>
using namespace std;

class pengantri {
public:
    string namaq;
    int nomorq;
    pengantri* prev;
    pengantri* next;
    
    pengantri(string namaMember, int nomorq) {
        namaq = namaMember;
        this->nomorq = nomorq;
        prev = nullptr;
        next = nullptr;
    }
};


class ruangq{// INI QUE nyaa Antrian
public:
    pengantri* head;
    pengantri* tail;
    int noAntrean;
    
public:
    int REALCAP;
    int MAXCAP;

    ruangq() {
        head = nullptr;
        tail = nullptr;
        REALCAP = 0;
        MAXCAP = 10; // Titik ter MAXXWIN Stocknya
    }
    void ruangqin(string namaMember, int nomorq) {
        if (REALCAP >= MAXCAP) {
            cout << "antrean penuh!!! tolong tunggu.\n";
            return;
        }
        pengantri* nqueqe = new pengantri(namaMember, nomorq);
        if (head == nullptr) {
            head = nqueqe;
            tail = nqueqe;
        } else {
            nqueqe->prev = tail;
            tail->next = nqueqe;
            tail = nqueqe;
        }
        REALCAP++;
    }
    void displayPengantri() const {
        pengantri* temp = head;
        while (temp != nullptr) {
            cout << "(" << temp->namaq << "|" << temp->nomorq << "   )->\n";
            temp = temp->next;
        }
        cout << "Isi terkini dari antrean" << endl;
    }

    void keluarPengantri() {
        if (tail == nullptr) {
            cout << "Antrean Kosong!!!" << endl;
            return;
        }
        pengantri* temp = head;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        REALCAP++;
    }

    void displayAntrean() const {
        cout << "Status Antrean: " << (MAXCAP - REALCAP) << " slot(s) tersedia." << endl;
    }
    
};
int main(){
    ruangq tunggu;
    tunggu.ruangqin("aco", 1);
}
