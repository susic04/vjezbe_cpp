/*Zadatak: Evidencija studenata
Napiši program koji:
Definira struct Student s poljima:
string ime;
string prezime;
int godina_rodenja;
double prosjek;
U main():
pita korisnika koliko studenata želi unijeti
unosi podatke za svakog studenta i sprema ih u niz ili vector struktura
Program treba:
ispisati sve studente
pronaći studenta s najvećim prosjekom
(opcionalno) sortirati studente po prosjeku silazno
*/

#include <iostream>
using namespace std;
struct Student{
    string ime;
    string prezime;
    int godina_rodenja;
    float prosjek;
};
int najveci_prosjek(Student studenti[], int n){
    int najbolji = 0;

    for(int i = 0; i < n; i++){
        if(studenti[i].prosjek > studenti[najbolji].prosjek){
            najbolji = i;
        }
    }
    return najbolji;
}
void sortiranje(Student studenti[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(studenti[j].prosjek < studenti[j+1].prosjek){
                Student temp = studenti[j];
                studenti[j] = studenti[j+1];
                studenti[j+1] = temp;
            }
        }
    }
}
int main(){
    int broj_studenata = 2;
    Student studenti[broj_studenata];
    for(int i = 0; i < broj_studenata; i++){
        cout << "Unesi ime studenta: " << endl;
        cin >> studenti[i].ime;
        cout << "Unesi prezime studenta: " << endl;
        cin >> studenti[i].prezime;
        cout << "Unesi godinu rodenja studenta: " << endl;
        cin >> studenti[i].godina_rodenja;
        cout << "Unesi prosjek studenta: " << endl;
        cin >> studenti[i].prosjek;
    }
    cout << " Svi studenti: " << endl;
    for(int i = 0; i < broj_studenata; i++){
        cout << studenti[i].ime << " " 
        << studenti[i].prezime << ", rođen: " <<  
        studenti[i].godina_rodenja  << ", sa prosjekom: " << 
        studenti[i].prosjek << endl;
    }

    int indeks = najveci_prosjek(studenti, broj_studenata);
    cout << "Student sa najvecim prosjekom je:" << endl;
    cout << studenti[indeks].ime << " " <<
    studenti[indeks].prezime;
    cout << ", sa prosjekom: " << studenti[indeks].prosjek << endl;
    return 0;
}