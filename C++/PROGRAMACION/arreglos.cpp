#include <iostream>
using namespace std;
#include <random>
#include <ctime>
#include <iomanip>
const int MAX = 50;
void ingresar(int notas[MAX],const int MAX);
void ordenar (int notas[MAX]);
void buscar (int notas[MAX]);
void eliminar (int notas[MAX]);
void insertar (int notas[MAX]);
int menu_principal(int opc);
int menu_opcion_1(int opc);
void palindromo();
void duplicados ();
void dados ();
int p =0,ne=0; 
int main (){
    int op =0,opcion=0;
    while (opcion!=5){
        opcion = menu_principal(op);
        switch (opcion){
            case 1:{
                int op = 0;
                while (op!=6){
                    op = menu_opcion_1(op); 
                    switch (op){
                        int notas[MAX];
                        case 1:
                            ingresar (notas,MAX);
                        break;   
                        case 2:
                            buscar (notas);  
                        break;
                        case 3:
                            eliminar (notas);
                        break;
                        case 4:
                            insertar(notas);
                        break;
                        case 5:
                            ordenar(notas);
                        break;
                    }
                }
            break;    
            }
            case 2:
                palindromo ();
            break;
            case 3:
                duplicados ();
            break;
            case 4:
                dados();
            break;
            case 5:
                exit (5);
            break;
            default:
            break;
        }
    }
    if (opcion==5){exit(5);}
    system ("pause");
    return 0;
}

//MENU PRINCIPAL TERMINADO
int menu_principal(int opc){
    cout<<"\t\t M E N U  D E  O P C I O N E S"<<endl;
    cout<<"1.- CALIFICACIONES"<<endl;
    cout<<"2.- PALINDROMO"<<endl;
    cout<<"3.- DUPLICADOS"<<endl;
    cout<<"4.- DADOS"<<endl;
    cout<<"5.- SALIR"<<endl;
    cout<<" > Ingrese su opcion: ";
    cin>>opc;        
    while (opc<1 || opc>5){
        cout<<"\t\t [NO SE TIENE ESA OPCION]"<<endl;
        cout<<" > Ingrese su opcion: ";
        cin>>opc;
    }
    return opc;
}

//MENU NOTAS TERMINADO
int menu_opcion_1 (int opc){
    int opx = 0;
    cout<<"\t------------------------------------------------"<<endl;
    cout<<"\t\t S I S T E M A  D E  N O T A S"<<endl;
    cout<<"1.- AGREGAR NOTAS"<<endl;
    cout<<"2.- BUSCAR NOTAS"<<endl;
    cout<<"3.- ELIMINAR NOTAS"<<endl;
    cout<<"4.- INSERTAR NOTAS"<<endl;
    cout<<"5.- ORDENAR NOTAS"<<endl;
    cout<<"6.- SALIR"<<endl;
    cout<<" > Ingrese su opcion: ";
    cin>>opx;
    while(opx<1 || opx>6){
        cout<<"\t\t [NO SE TIENE ESA OPCION]"<<endl;
        cout<<" > Ingrese su opcion: ";
        cin>>opx;
    }
    cout<<"\t------------------------------------------------"<<endl;
    return opx;
}

//INGRESAR TERMINADO
void ingresar(int notas[MAX],const int MAX){
    bool band = true;
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<"\t 1) N O T A S : A G R E G A R"<<"\t\"PARA TERMINAR INGRESE [0] O UNA CANTIDAD NEGATIVA\""<<endl;
    while (band == true && p<MAX){
        cout<<" > Ingrese la nota: ";
        cin>>notas[p];
        if (notas[p] <= 0){
            band = false;
        }
        else{p++;}
    }
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    if (p>=MAX){
        cout<<"\t\t[NO SE PUEDEN AGREGAR MAS NOTAS]\n"<<endl;
    }
}

//BUSCAR TERMINADO
void buscar (int notas[MAX]){
    int num =0,aux=0,z =0,j=0,mitad=0;
    bool band = true;
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<"\t 2) N O T A S : B U S C A R"<<endl;
    cout<<" > Ingrese la nota a buscar: ";
    cin>>num;
    j = MAX-1;
    do{
        for (z =0;z<p;z++){ 
            for (j=0;j<p-1;j++){
                if (notas[j]>notas[j+1]){
                    aux = notas[j];
                    notas[j] = notas[j+1];
                    notas[j+1] = aux;
                }
            }
        }
        band = true;
    } while (band == false);
    z=0;
    do{
        mitad = (z+j)/2;
        if (notas[mitad]>=num){j = mitad-1;}
        if (notas[mitad]<=num){z = mitad+1;}
    } while (z<=j); 
    if (notas[mitad] == num){
        cout<<"\t\t -----> N U M E R O  E N C O N T R A D O, posicion ["<<z-1<<"]"<<endl;
    }
    else{
        cout<<"\t\tE L E M E N T O   N O   E N C O N T R A D O"<<endl;
    }
}

//ELIMINAR TERMINADO
void eliminar (int notas[MAX]){
    bool band = false,band2 = false;
    while (band2 == false && ne<p){
        int num = 0,j=0;
        cout<<"-------------------------------------------------------------------------------------"<<endl;
        cout<<"\t 3) N O T A S : E L I M I N A R"<<endl;
        cout<<" > Ingrese la nota a eliminar: ";
        cin>>num;
        while (band == false && j<p){
            if (notas[j] == num){
                band = true;
            }
            j++;
        }
        if (band == true){
            notas[j-1] = 0;
            cout<<"\t\t[N U M E R O   E L I M I N A D O]"<<endl;
            ne++;
            band2 = true;
        }
        else{cout<<"\t\t[N U M E R O   N O   E N C O N T R A D O]"<<endl;}
    }
    if (ne>=p){
        cout<<"-------------------------------------------------------------------------------------"<<endl;
        cout<<"\t\t[NO SE  PUEDEN ELIMINAR MAS DATOS]"<<endl;
    }
}

//INSERTAR TERMINADO
void insertar (int notas[MAX]){
    int num = 0, pos = 0;
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<"\t 4) N O T A S : I N S E R T A R"<<endl;
    cout<<" > Ingrese la posicion y numero a insertar(separados por un espacio): ";
    cin>>pos>>num;
    while((pos > p || pos < 0) || num<=0){
        cout<<"\t\t[INGRESE VALORES CORRECTOS]"<<endl;
        cout<<" > Ingrese la posicion y numero a insertar(separados por un espacio): ";
        cin>>pos>>num;
    }
    notas[pos] = num;
    cout<<" > LISTA: ";
    for (int i=0;i<p;i++){
        if (notas[i] != 0){
            cout<<"["<<notas[i]<<"] ";  
        }

    }
    cout<<endl<<"-------------------------------------------------------------------------------------"<<endl;

}

//ORDENAR TERMINADO
void ordenar (int notas[MAX]){
    int aux = 0;
    for (int i =0;i<p;i++){ 
        for (int j=0;j<p-1;j++){
            if (notas[j]>notas[j+1]){
                aux = notas[j];
                notas[j] = notas[j+1];
                notas[j+1] = aux;
            }
        }
    }
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t 5) N O T A S : O R D E N A R"<<endl;
    for (int j = 0;j<p;j++){   
        if (notas[j] != 0){
            cout<<"["<<notas[j]<<"] ";   
        }  
    }
    cout<<endl<<"-------------------------------------------------------------------------------------"<<endl;
   
}

//PALINDROMO TERMINADO 
void palindromo(){
    int num=0;
    bool band = true;
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t P A L I N D R O M O"<<endl;
    cout<<"> Ingrese un numero: ";
    cin>>num;
    if (num>0){
        int aux=0,div=1,i =1,z=0;
        aux = num;
        while(aux/10 != 0){
            aux = aux/10;
            div = div*10;
            i++;
        }
        int arreglo1[i];
        int arreglo2[i];
        while (div!=0){
            int arr1 = 0;
            arr1 = num/div;
            arreglo1[z] = arr1;
            num = num%div;
            div=div/10;
            z++;
        }
        z=0;
        z = i-1;
        for (int j =0;j<i;j++){                 
            arreglo2[j] = arreglo1[z];
            z--;
        }
        for (int k =0;k<i;k++){
            if (arreglo1[k] != arreglo2[k]){
                band = false;
            }
        }
        if (band == true){cout<<"\t\t[EL NUMERO ES PALINDROMO]"<<endl;}
        else{cout<<"\t\t[EL NUMERO NO ES PALINDROMO]"<<endl;}
    }
    cout<<"-------------------------------------------------------------------------------------"<<endl;
}

//DUPLICADOS TERMINADO
void duplicados (){
    int num = 0,i =0;
    int const MAX = 20;
    bool band = true,band2=true;
    int lista[MAX];
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"\tE L I M I N A R   D U P L I C A D O S"<<endl;
    while (i<MAX){
        cout<<" > INGRESE SU NUMERO: ";
        cin>>num;
        while (num<10 || num>100){
            cout<<"\t[N U M E R O   N O   V A L I D O]"<<endl;
            cout<<" > INGRESE SU NUMERO: ";
            cin>>num;
        }    
        lista[i] = num;
        if (i>0){
            for (int j=0;j<i;j++){
                if (lista[j] == num){
                    lista[j] = 0;
                }
            }
        }
        i++;
    }
    cout<<endl;
    cout<<"\t\t\t L I S T A"<<endl;
    for (int k =0;k<i;k++){
        if (lista[k] != 0){
            cout<<"["<<lista[k]<<"] ";
        }
    }
    cout<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
}

//DADOS TERMINADO
void dados (){
    int resultado =0 ;
    int posibilidades [11] = {0};
    default_random_engine motor(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> intAleatorio(1,6);
    for (unsigned int contador =1;contador<=36000;++contador){
        resultado = intAleatorio(motor)+intAleatorio(motor);
        switch (resultado){
            case 2:
                posibilidades[0]++;
            break;
            case 3:
                posibilidades[1]++;
            break;
            case 4:
                posibilidades[2]++;
            break;
            case 5:
                posibilidades[3]++;
            break;
            case 6:
                posibilidades[4]++;
            break;
            case 7:
                posibilidades[5]++;
            break;
            case 8:
                posibilidades[6]++;
            break;
            case 9:
                posibilidades[7]++;
            break;
            case 10:
                posibilidades[8]++;
            break;
            case 11:
                posibilidades[9]++;
            break;
            case 12:
                posibilidades[10]++;
            break;
            default:
                cout<<"ESTE MENSAJE NO DEBERIA SALIR"<<endl;
            break;
        }
    }
    cout<<endl<<"--------------------------------------------------------------------------------------------------------------------"<<endl; 
    cout<<"\t\t\t F R E C U E N C I A   D E   S U M A S"<<endl;
    cout<<"  SUMA 2 |"<<" SUMA 3 |"<<" SUMA 4 |"<<" SUMA 5 |"<<" SUMA 6 |"<<" SUMA 7 |"<<" SUMA 8 |"<<" SUMA 9 |"<<" SUMA 10 |"<<" SUMA 11 |"<<" SUMA 12"<<endl;
    for(int i =0;i<11;i++){
        cout<<setw(4)<<"["<<posibilidades[i]<<"]";
    } 
    cout<<endl<<"--------------------------------------------------------------------------------------------------------------------"<<endl; 
}
