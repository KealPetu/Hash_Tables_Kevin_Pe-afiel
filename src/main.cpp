#include <fstream>
#include <iostream>
#include <Windows.h>
#include "../lib/colors.h"
using namespace std;

const int KP_CEDULA = 1755968169;
const string KP_NOMBRE= "Kevin Alexander Penafiel Tuz";

struct kpCoordenada{
    int kpCap;
    char kpGeo[4];
    char kpArsenal[7];
    kpCoordenada* next;
};

void kpLoad(){
    string kpLoad = "\\|/-";
    int kpc=0,kpu=1,kpd=2,kpt=3;
    for (int i = 0; i <=100; i++){
        if (i == kpc){
            cout<<"\r\r\r\r\r";
            cout<<CYAN<<kpLoad[0]<<' '<<i<<"% ";
            kpc = kpc+4;
            Sleep(40);
        }else if (i==kpu){
            cout<<"\r\r\r\r\r";
            cout<<CYAN<<kpLoad[1]<<' '<<i<<"% ";
            kpu=kpu+4;
            Sleep(40);
        }else if (i==kpd){
            cout<<"\r\r\r\r\r";
            cout<<CYAN<<kpLoad[2]<<' '<<i<<"% ";
            kpd= kpd+4;
            Sleep(40);
        }else if (i==kpt){
            cout<<"\r\r\r\r\r";
            cout<<CYAN<<kpLoad[3]<<' '<<i<<"% ";
            kpt= kpt+4;
            Sleep(40);
        }
    }
}

void kpShowCoordenada(){
    ifstream kpFile;
    string kpTexto;
    bool kpLineau = true;
    kpFile.open("../files/coordenadas.txt", ios::in);
    cout<<BLUE<<"[+] Leyendo Coordenadas";
    for (int i = 0; i < 3; i++)
    {
        Sleep(1000);
        cout<<BLUE<<'.';
    }
    cout<<endl;
    
    if(kpFile.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        exit(1);
    }else{
        while (!kpFile.eof()){
            getline(kpFile,kpTexto);
            if (kpLineau == true){
                // kpLoad();
                cout<<RED<<"\r\r\r\r\r>> 99% "<<"Error: "<<kpTexto<<" -> stoi"<<endl;
                kpLineau = false;
            }else{
                // kpLoad();
                cout<<GREEN<<"\r\r\r\r\r100% "<<kpTexto<<endl;
            }
        }
    }
    cout<<endl;
}

void kpHash(){

}

void kpDatos(){
    cout<<GRAY<<"[+] Informacion Hash Table de capacidad belica Ucrania"<<endl;
    cout<<GRAY<<"Developer -Nombre: "<<KP_NOMBRE<<endl;
    cout<<GRAY<<"Developer -Cedula: "<<KP_CEDULA<<endl;
    cout<<GRAY<<"Capacidad Belica: 36"<<endl;
    cout<<GRAY<<"Coordenadas Total: 6"<<endl;
    cout<<GRAY<<"Coordenada -SecCarga: 1 5 6 7 8 9"<<WHITE;
}

//  Tipo Bomba  | Patrón Exp. Reg. (AFD)    | último Nro. Cédula    | Agrgar alfabeto
//              |                           |                       |
//  BOMB - II   | a*b+c                     | impar                 | d+ o t+
//  BOMB - IP   | ab*c+                     | par                   | d y t
//  BOMB - IPI  | a+bc*                     | cero                  | d* o t*

//  Último nro de Cédula: 9.

//  Tipo Bomba  | Patrón Exp. Reg. (AFD)
//              |
//  BOMB - II   | a* b+ c d+

void kpAFD(){

}

int main()
{
    kpShowCoordenada();
    kpDatos();
    return 0;
}

