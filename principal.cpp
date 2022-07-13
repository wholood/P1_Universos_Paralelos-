#include <iostream>

using namespace std;

int main (){
    int ubiM, senM0, senM1, senM2; //Ubicacion inicial de los 3 marios y Sentido X Y de cada mario  
    int sxm0, sxm1, sxm2, sym0, sym1, sym2; //sentido x y Y de mario y sus copias 1 y 2
    int ubix, ubiy, xm1, xm2, ym1, ym2; //Ubicación x y Y de la copia 1 y 2

    int numS, datS1, datS2, datS3; //Numero de scuttlebugs (Max3) y sus datos (x y vida)
    int xs1, xs2, xs3, ys1, ys2, ys3, vidas1, vidas2, vidas3;//Desgloce de datos

    int estrella, beneficio; //Ubicación x y de la estrella y el contador de beneficio
    int Xestrella, Yestrella; //Desgloce de coordenadas

    int m, movimiento, mx, my, mariox, marioy; 
    //Numero de movimientos que tendrán, el movimiento a realizar, su desgloce y la copia para usar con el sentido de mario

    int aux;

    //Lectura de variables
    cin>>ubiM;
    cin>>senM0;
    //**********Validacion del sentido

    /*cin>>senM1;
    cin>>senM2;

    cin>>numS;

    switch (numS){ //Dependiendo del numero de scuttlebugs habrá lectura de sus datos
        case 1: 
            cin>>datS1;
            break;
        case 2:
            cin>>datS1;
            cin>>datS2;
            break;
        case 3:
            cin>>datS1;
            cin>>datS2;
            cin>>datS3;
            break;
        default: //Si no se introduce un numero entre 1 y 3 finalizará el programa.
            return 0;
    }

    cin>>estrella;
    cin>>m;
*/
    for (int i = 0; i < m; i++){ 
        cin>>movimiento;
        //**********Desglozamos Mov en mx y my

    //Movemos al mario original.

        if(sxm0==-1){ //Validamos que el sentido de mario en x sea -1
            ubix+=mx*(-1); //Hacemos que el movimiento sea en ese sentido y sumamos
        }
        else{//Si no es -1
            ubix+=mx;//Sumamos
        }

        if(sym0==-1){ //validamos que el sentido de mario en y sea -1
            ubiy+=my*(-1); //Hacemos que el movimiento sea en ese sentido y sumamos
        }
        else{//si no es -1
            ubiy+=my; //sumamos
        }


    //Cambio de sentido de las copias
        if(ubix<0){ //Cuando x es menor que 0 Mario puede estar en el 2do o 3er cuadrante
            if(ubiy>=0){//Validamos que el mario original haya quedado en el 2do cuadrante
                sxm1*=(-1); //Cambiamos solo el sentido en X de sus copias
                sxm2*=(-1);  
            }
            else{ //ym0<0 Validamos que el mario original haya quedado en el 3er cuadrante
                sym1*=(-1); //Cambiamos solo el sentido en y de sus copias
                sym2*=(-1); 
            }
        }
        else if(ubix>=0 && ubiy<0){ //Validamos que el mario original haya quedado en el 3er cuadrante
            sxm1*=(-1); //Cambiamos solo el sentido en X de sus copias
            sxm2*=(-1);
            sym1*=(-1); //Cambiamos solo el sentido en y de sus copias
            sym2*=(-1);
        }

    //Movimiento de la copia 1
        if(sxm1==-1){ //Validamos que el sentido de la copia 1 en x sea -1
            xm1+=mx*(-1); //Hacemos que el movimiento sea en ese sentido y sumamos
        }
        else{//Si no es -1
            xm1+=mx;//Sumamos
        }

        if(sym1==-1){ //validamos que el sentido de la copia 1 en y sea -1
            ym1+=my*(-1); //Hacemos que el movimiento sea en ese sentido y sumamos
        }
        else{//si no es -1
            ym1+=my; //sumamos
        }

    //Movimiento de la copia 2
        if(sxm2==-1){ //Validamos que el sentido de la copia 2 en x sea -1
            xm2+=mx*(-1); //Hacemos que el movimiento sea en ese sentido y sumamos
        }
        else{//Si no es -1
            xm2+=mx;//Sumamos
        }

        if(sym2==-1){ //validamos que el sentido de la copia 2 en y sea -1
            ym2+=my*(-1); //Hacemos que el movimiento sea en ese sentido y sumamos
        }
        else{//si no es -1
            ym2+=my; //sumamos
        }

        //Colision con la estrella
        //Colision con el scuttlebug m0, m1, m2

        //si beneficio > 0 {beneficio --}


    }
    return 0;
}