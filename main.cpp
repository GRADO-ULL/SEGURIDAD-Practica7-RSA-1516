#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <string>

#include "funciones.cpp"

using namespace std;

int main()
{
    //Declaración de variables
    int p=0;
    int q=0;
    int d=0;
    int e;
    int n;
    int fi_n=0;
    bool primo_p = false;
    bool primo_q = false;
    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int j = 0;
    
    char* texto_cifrar;
    texto_cifrar = new char[256]; //Texto a cifrar con espacios
    vector<char> texto_acifrar; //Texto a cifrar sin espacios
    
    cout << "Introduzca la informacion requerida:" << endl;
    cout << "\tP: ";
    cin  >> p;
    cout << "\tQ: ";
    cin >> q;
    cout << "\tD: ";
    cin >> d;
    cout << "\tTexto a cifrar:";
    cin.ignore();
    cin.getline(texto_cifrar,256);
    cout << endl;
    
    texto_acifrar = eliminar_espacios(texto_cifrar);
    cout << "Texto sin espacios:" << endl;
    for(int i=0;i<texto_acifrar.size();i++)
    {
        cout << texto_acifrar[i];
    }
    cout << endl;
    
    cout << "------------------------------------------------------------" << endl;
    cout << "Proceso:" << endl;
    cout << "Paso1.- Comprobamos que p y q son primos." << endl;
    
    primo_p = primalidad(p);
    if(primo_p)
        cout << "El numero " << p << " es primo " << endl;
    else
        cout << "El numero " << p << " no es primo " << endl;
    primo_q = primalidad(q);
    if(primo_q)
        cout << "El numero " << q << " es primo " << endl;
    else
        cout << "El numero " << q << " no es primo " << endl;
    
    //-----------------------------------------------------------------------
    cout << "------------------------------------------------------------" << endl;
    cout << "Paso2.- Comprobamos que d es primo con fi de n." << endl;
    
    //Hallando fi_n
    fi_n = (p-1)*(q-1);
    e = algoritmo_euclides(d,fi_n);
    
    cout << "Resultado euclides para d=" << d << ",fi_n=" << fi_n << ": " << e << endl;
    cout << "e => " << e << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Paso3.- Codificacion numerica." << endl;
    cout << "-Generando alfabeto." << endl;
    for(int i=0;i<26;i++)
    {
        cout << alfabeto[i];
        if(i<25)
            cout << ",";
    }
    cout << endl;
    cout << "-Calculamos j." << endl;
    n = p*q;
    calcular(j,n);
    cout << "j => " << j << ", n => " << n << endl;
    cout << "-Dividimos texto a cifrar en bloques de tamanio " << j-1 << " y pasamos a entero los caracteres:" << endl;

    //Contiene los enteros asociados del texto_acifrar<char>
    vector<int> texto_original_entero;
    
    texto_original_entero = pasar_entero(texto_acifrar,alfabeto,j-1);
    cout << endl;
    cout << "Texto original en enteros:";
    imprimir_vector(texto_original_entero);
    
    //Hacemos cifrado
    vector<int> texto_cifrado;
    texto_cifrado.resize(texto_original_entero.size());
    for(int i=0;i<texto_original_entero.size();i++)
    {
        texto_cifrado[i] = exponenciacion_rapida(texto_original_entero[i],e,n);
    }
    cout << endl;
    cout << "Texto cifrado en enteros final:";
    imprimir_vector(texto_cifrado);
    cout << endl;

    cout << "Paso4.- Descifrando..." << endl;
    descifrando(texto_cifrado,d, n);
    cout << endl;
    return 0;
}
