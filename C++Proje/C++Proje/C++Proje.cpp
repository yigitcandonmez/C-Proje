#include <fstream>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <dos.h>


using namespace std;

class Fatura
{
public:
    string isim;
    string alici;
    string adres;
    int fiyat;
    int etiket;
    float indirim;
    char* dt;

    

    void BilgiGir()
    {
        
        cout.setf(ios::right);
        cout << "\n\n";
        cout << setw(20) << "\t\t\t\tUrunun ismini giriniz: ";
        cin >> isim;
        cout << "\n\n";
        cout << setw(20) << "\t\t\t\tUrunun fiyatini giriniz: ";
        cin >> fiyat;
        cout << "\n\n";
        cout << setw(20) << "\t\t\t\tUrunun etiket numarasini giriniz: ";
        cin >> etiket;
        cout << "\n\n";
        cout << setw(20) << "\t\t\t\tUrunun indirim degerini giriniz: ";
        cin >> indirim;
        cout << "\n\n";
        cout << setw(20) << "\t\t\t\tUrunun aLicisinin ismini giriniz: ";
        cin >> alici;
        cout << "\n\n";
        cout << setw(20) << "\t\t\t\tUrunun alicisinin adresini giriniz: ";
        cin >> adres;


    }
    void BilgiYazdir()
    {
        
        cout.setf(ios::left);
        
        cout << setw(60) << "\t\tUrunun ismi: " << isim << endl;
        cout << setw(60) << "\t\tUrunun fiyati: " << fiyat << "$" << endl;
        cout << setw(60) << "\t\tUrunun etiket numarasi: " << etiket << endl;
        cout << setw(60) << "\t\tUrunun indirim degeri: " << indirim << endl;
        cout << setw(60) << "\t\tUrunun alicisi ismi: " << alici << endl;
        cout << setw(60) << "\t\tUrun alicisi adresi: " << adres << endl;
        cout << "\n\n";
    }
};

class irsaliye
{
public:
    Fatura faturalar[100];
    int faturasayisi;
    fstream dosya;

    irsaliye()
    {
        faturasayisi = 0;
        dosya.open("kayit.txt", ios::out | ios::in | ios::app);
        dosya.setf(ios::left);
    }

    void faturaEkle() 
    {
        
        faturalar[faturasayisi].BilgiGir();
        Fatura O = faturalar[faturasayisi];
        dosya  << setw(20) << O.isim << setw(20) << O.fiyat << setw(20) << O.etiket << setw(20) << O.indirim << setw(20) << O.alici << setw(20) << O.adres << endl;
    }

    void faturaBul(string birey)
    {
        Fatura X;
        while (!dosya.eof()){

        
        dosya >> X.isim;
        dosya >> X.fiyat;
        dosya >> X.etiket;
        dosya >> X.indirim;
        dosya >> X.alici;
        dosya >> X.adres;

        if (X.alici == birey) {
            cout << "\n\n";
            X.BilgiYazdir();
            cout << "\n\n";
        }
    }
    
    
    
    
    }

    void faturaSil(int kod)
    {
        int sil = 0;
        fstream günceldosya;
        günceldosya.open("güncelfatura.txt", ios::out | ios::in | ios::app);
        Fatura D;
        while (!dosya.eof()) {


            dosya >> D.isim;
            dosya >> D.fiyat;
            dosya >> D.etiket;
            dosya >> D.indirim;
            dosya >> D.alici;
            dosya >> D.adres;

            if (D.etiket != kod) {

                günceldosya.setf(ios::left);
                günceldosya << setw(20) << D.isim << setw(20) << D.fiyat << setw(20) << D.etiket << setw(20) << D.indirim << setw(20) << D.alici << setw(20) << D.adres << endl;
                dosya.close();
                remove("kayit.txt");
                cout << "basarili";
                
                


            }
        }
    }
    void faturaSirala() {
        Fatura Y;
        while (!dosya.eof()) {


            dosya >> Y.isim;
            dosya >> Y.fiyat;
            dosya >> Y.etiket;
            dosya >> Y.indirim;
            dosya >> Y.alici;
            dosya >> Y.adres;
            Y.BilgiYazdir();
        }
    }
};

int main()
{
    irsaliye ftr;
    enbas:
    system("color F0");
    int info;
    string info2;
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << setw(70) << dt << endl;
    cout << "\n";
    cout << setw(97) << "Faturalandirma programimiza hos geldiniz, yapmak istediginiz islemi seciniz.";
    cout << "\n\n";
    cout << setw(93) << "Faturalarin sisteme gecmesi icin uygulamayi kapatip acmaniz gerekli.";
    cout << "\n\t\t**------------------------------------------------------------------------------------** ";
    cout << "\n\n";
    cout << setw(60) << "1. Fatura Ekle";
    cout << "\n\n";
    cout << setw(60) << "2.  Fatura Bul";
    cout << "\n\n";
    cout << setw(64) << "3.  Fatura Listele";
    cout << "\n\n";
    cout << setw(67) << "4.  Fatura Sil /BETA!";
    cout << "\n\n";
    cout << setw(60) << "5.   Cikis Yap";
    cout << "\n\n";
    cout << "\n\t\t**------------------------------------------------------------------------------------** ";
    cout << "\n\n";
    cout << setw(45) << "---------->\t";
    cin >> info;
    if (info == 1) {
        ftr.faturaEkle();
        cout << "\n\n";
        cout << setw(70)<<"Devam etmek istiyor musunuz? Y/N?";
        cin >> info2;
        if (info2 == "Y") {
            ftr.faturaEkle();
        }
        else {
            system("break");
        }
    }
    else if (info == 2) {
        string infobirey;
        cout << "\n\n";
        cout << setw(70) << "Faturanin kesilmis oldugu alicinin ismini giriniz: ";
        cin >> infobirey;
        ftr.faturaBul(infobirey);
        
        
    }
    else if (info == 3) {
        ftr.faturaSirala();
        
    }
    else if (info == 4) {
        int infoetiket;
        cout << "\n\n";
        cout << setw(80) << "Silmek istediginiz faturanin etiket numarasini giriniz: ";
        cin >> infoetiket;
        ftr.faturaSil(infoetiket);
    }
    




}

