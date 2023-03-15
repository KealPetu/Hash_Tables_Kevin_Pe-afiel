// @author  Kevin Alexander Peñafiel Tuz
//@date     15/03/2023
//tema      Hash Tables

#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include "../lib/colors.h"
using namespace std;

#define TABLE_SIZE 10

const int KP_CEDULA = 1755968169;
const string KP_NOMBRE= "Kevin Alexander Penafiel Tuz";

typedef struct kpCoordenada{
    int kpKey;
    string kpGeo;
    string kpArsenal;
    kpCoordenada* next;
}kpCoordenada;

kpCoordenada* kpHashTable [TABLE_SIZE];

void kpInitHashTable(){
    for (int i = 0; i < TABLE_SIZE; i++){
        kpHashTable[i] = NULL;
    }
}

void kpInsert(int key, string kpGeo, string kpArsenal){
    
    kpCoordenada* kpNewCoordenada = new kpCoordenada;
    kpNewCoordenada -> kpGeo = kpGeo;
    kpNewCoordenada -> kpArsenal = kpArsenal;
    kpNewCoordenada->next = NULL;
    if (kpHashTable[key] == NULL) {
        kpHashTable[key] = kpNewCoordenada;
    } else {
        kpCoordenada* kpActual = kpHashTable[key];
        while (kpActual->next != NULL) {
            kpActual = kpActual->next;
        }
        kpActual->next = kpNewCoordenada;
    }
    //kpHashTable[key] = kpNewCoordenada;
}

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

void kpRead(){
    char separador = ' ';
    int i = 0;
    string s;

    ifstream kpFile;
    string kpTexto;
    bool kpLineau = true;
    kpFile.open("./files/coordenadas.txt", ios::in);

    int key;
    string kpGeo;
    string kpArsenal;
    
    cout<<BLUE<<"[+] Leyendo Coordenadas";
    for (int i = 0; i < 3; i++){
        Sleep(1000);
        cout<<BLUE<<'.';
    }
    cout<<endl;
    
    if(kpFile.fail()){
        cout<<RED<<"No se pudo abrir el archivo."<<WHITE<<endl;
        exit(1);
    }else{
        while (!kpFile.eof()){
            kpLoad();
            getline(kpFile,kpTexto);
            while (kpTexto[i] != '\0'){
                if (kpTexto[i] != separador){
                    s += kpTexto[i];
                }else{
                    if (s == "Cap"||s == "Geo" || s == "Arsenal")
                    {
                        cout<<RED<< "Error: " <<s<< " is not a data." <<'\t';
                        s.clear();
                    }else{
                        cout<<GREEN;
                            if ("1" == s||"2"== s||"3"== s||"4"== s||"5"== s||"6"== s||"7"== s||"8"== s||"9"== s||"0"== s){
                                key = (int)s[0] - 48;
                            } 
                            if ("GPS0"== s||"GPS1"== s||"GPS2"== s||"GPS3"== s||"GPS4"== s||"GPS5"== s||"GPS6"== s||"GPS7"== s||"GPS8"== s||"GPS9"== s){
                                kpGeo = s;
                            }
                            if ("ab"== s||"bc"== s||"ac"== s||"bcd"== s||"acd"== s||"bct"== s||"act"== s||"aaabbct"== s||"abbccdt"== s||"aaabbcd"== s)
                            {
                                kpArsenal = s;
                            }
                            
                            
                        cout<<s<<'\t';
                        s.clear();
                    }
                }
            i++;
            }
        i=0;
        if (kpLineau == true){
            kpLineau = false;
        }else{
            kpInsert(key, kpGeo, kpArsenal);
        }
        cout<<WHITE<<endl;
        } 
    }
}

void kpDatos(){
    cout<<GRAY<<endl<<"[+] Informacion"<< endl <<"Hash Table de capacidad belica Ucrania"<<endl;
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
//  BOMB - II   | a* b+ c d+ o t+

void kpPrintHashTable() {
    ofstream kpArchivo;
    kpArchivo.open("./files/data.txt");
    if (kpArchivo.fail()){
        cout<<"No se puede abrir el archivo";
        exit(0);
    }
    
    cout<<endl<<endl;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (kpHashTable[i] != NULL) {
            cout << "Nodos en key " << i << ": ";
            kpArchivo << "Nodos en key " << i << ": ";
            kpCoordenada* kpActual = kpHashTable[i];
            while (kpActual != NULL) {
                int a = 0, b= 0, c = 0, d = 0, t = 0;
                for (int i = 0; i < sizeof(kpActual->kpArsenal); i++)
                {
                    if (kpActual->kpArsenal[i] == 'a'){
                        a++;
                    }else if (kpActual->kpArsenal[i] == 'b')
                    {
                        b++;
                    }else if (kpActual->kpArsenal[i] == 'c'){
                        c++;
                    }else if (kpActual->kpArsenal[i] == 'd'){
                        d++;
                    }else if (kpActual->kpArsenal[i] == 't')
                    {
                        t++;
                    }
                }
                if (a > 1 && b >= 1 && c == 1 && d>=1){
                    cout << "(" << kpActual->kpGeo << ", " << kpActual->kpArsenal << ") "<<RED<<"BOMB-II"<<WHITE;
                    kpArchivo << "(" << kpActual->kpGeo << ", " << kpActual->kpArsenal << ") "<<"BOMB-II"<<endl;
                }else if (a == 0 && b >= 1 && c == 1 && d>=1){
                    cout << "(" << kpActual->kpGeo << ", " << kpActual->kpArsenal << ") "<<RED<<"BOMB-II"<<WHITE;
                    kpArchivo << "(" << kpActual->kpGeo << ", " << kpActual->kpArsenal << ") "<<"BOMB-II"<<endl;
                }else if (a > 1 && b >= 1 && c == 1 && t>=1){
                    cout << "(" << kpActual->kpGeo << ", " << kpActual->kpArsenal << ") "<<RED<<"BOMB-II"<<WHITE;
                    kpArchivo << "(" << kpActual->kpGeo << ", " << kpActual->kpArsenal << ") "<<"BOMB-II"<<endl;                    
                }else if (a == 0 && b >= 1 && c == 1 && t>=1)
                {
                    cout << "(" << kpActual->kpGeo << ", " << kpActual->kpArsenal << ") "<<RED<<"BOMB-II"<<WHITE;
                    kpArchivo << "(" << kpActual->kpGeo << ", " << kpActual->kpArsenal << ") "<<"BOMB-II"<<endl;
                }else{
                    cout << "(" << kpActual->kpGeo << ", " << kpActual->kpArsenal << ") ";  
                    kpArchivo << "(" << kpActual->kpGeo << ", " << kpActual->kpArsenal << ") "<<endl;  
                }            
                kpActual = kpActual->next;
            }
            cout << endl;
        }
    }
    kpArchivo.close();
}

int main()
{
    kpInitHashTable();
    kpRead();
    kpLoad();
    kpDatos();
    cout<<endl;
    kpLoad();
    cout<<WHITE;
    kpPrintHashTable();
    return 0;
}