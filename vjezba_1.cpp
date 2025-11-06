/*
Zadatak: Knjige u biblioteci
Napiši program koji:
Kreira strukturu Knjiga sa sljedećim članovima:
naslov (niz znakova ili string)
autor (niz znakova ili string)
broj_stranica (int)
Omogućava korisniku da unese podatke za 3 knjige.
Ispisuje podatke svih knjiga na ekran.
Na kraju ispisuje knjigu sa najviše stranica.
*/


#include <stdio.h>
#include <iostream>

using namespace std;

struct Knjiga{
    std::string naslov;
    std::string autor;
    int broj_stranica;
};
int max_br(Knjiga knjige[],int broj){
    int max = knjige[0].broj_stranica;
    for(int i = 1; i < broj; i++){
        if(max < knjige[i].broj_stranica){
            max = knjige[i].broj_stranica;
        }
    }
    return max;
}
int main(){
    int max_stranica = 0;
    const int max_broj_knjiga = 3;
    Knjiga knjige[max_broj_knjiga];
    for(int i = 0; i < max_broj_knjiga; i++){
        cout << "Unesi naslov knjige: " << endl;
        getline(cin, knjige[i].naslov);

        cout << "Unesi naziv autora: " << endl;
        getline(cin, knjige[i].autor);
    
        cout << "Unesi broj stranica: " << endl;
        cin >> knjige[i].broj_stranica;
        cin.ignore();
    }
    int max_stranice = max_br(knjige, 3);
    cout << "Podaci o knjigama:" << endl;

    for(int i = 0; i < max_broj_knjiga; i++){
        cout << "Naslov knjige: " << knjige[i].naslov << endl;
        cout << "Ime autora: " << knjige[i].autor << endl;
        cout << "Broj stranica: " << knjige[i].broj_stranica << endl;
        
    }
    cout << "Najvise stranica: " << max_stranice << endl;

    return 0;
}