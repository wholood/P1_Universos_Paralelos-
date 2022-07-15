#include <iostream>

using namespace std;

int main (){
    int sxm0, sxc1, sxc2, sym0, syc1, syc2; //sentido x y Y de mario y sus copias 1 y 2
    int ubix, ubiy, xc1, xc2, yc1, yc2; //Ubicacion inicial de los 3 marios y Sentido X Y de cada mario

    int numS, xs1, xs2, xs3, ys1, ys2, ys3, vidas1, vidas2, vidas3; //Numero de scuttlebugs (Max3) y sus datos (x y vida)

    int Xestrella, Yestrella, beneficio; //Ubicación x y de la estrella y el contador de beneficio

    int m, movx, movy, mariox, marioy; 
    //Numero de movimientos que tendrán, el movimiento a realizar, su desgloce y la copia para usar con el sentido de mario
    
    bool error=false;
    int aux;

//--------------------------------------------
//----------Lectura de variables--------------
//--------------------------------------------

    cin>>ubix; cin>>ubiy;//ubicación inicial
    mariox=ubix; marioy=ubiy; //clonamos la ubicación para no perder la entrada

    cin>>sxm0; cin>>sym0;//sentido mario
    cin>>sxc1; cin>>syc1;//sentido copia 1
    cin>>sxc2; cin>>syc2;//sentido copia 2
    
    //Validamos los sentidos
    if(sxm0!=1 || sxm0!=-1 || sym0!=1 || sym0!=-1){ //mario
        error=true;
    }
    if(sxc1!=1 || sxc1!=-1 || syc1!=1 || syc1!=-1){ //copia 1
        error=true;
    }
    if(sxc2!=1 || sxc2!=-1 || syc2!=1 || syc2!=-1){ //copia 2
        error=true;
    }
    
    cin>>numS; //numero de scuttlebugs

    switch (numS){ //Dependiendo del numero de scuttlebugs habrá lectura de sus datos
        case 1: 
            cin>>xs1; cin>>ys1; cin>>vidas1;
            break;
        case 2:
            cin>>xs1; cin>>ys1; cin>>vidas1;
            cin>>xs2; cin>>ys2; cin>>vidas2;
            break;
        case 3:
            cin>>xs1; cin>>ys1; cin>>vidas1;
            cin>>xs2; cin>>ys2; cin>>vidas2;
            cin>>xs3; cin>>ys3; cin>>vidas3;
            break;
        default: //Si no se introduce un numero entre 1 y 3 tendremos un error
            error=true;
    }

    cin>>Xestrella; cin>>Yestrella; //posicion de la estrella
    cin>>m;

    //PRUEBA DE SALIDAS
    /*cout<<ubix<<","<<ubiy<<endl;
    cout<<mariox<<","<<marioy<<endl;
    cout<<sxm0<<","<<sym0<<endl;
    cout<<sxc1<<","<<syc1<<endl;
    cout<<sxc2<<","<<syc2<<endl;
    cout<<numS<<endl;
    cout<<xs1<<","<<ys1<<","<<vidas1<<endl;
    cout<<xs2<<","<<ys2<<","<<vidas2<<endl;
    cout<<xs3<<","<<ys3<<","<<vidas3<<endl;
    cout<<"error"<<error<<endl;
    cout<<Xestrella<<","<<Yestrella<<endl;
    cout<<m<<endl;*/


/*
//--------------------------------------------
//------------Bucle de movimiento-------------
//--------------------------------------------
    for (int i = 0; i < m; i++){ 
        cin>>movx; cin>>movy;

    //Movemos al mario original.

        if(sxm0==-1){ //Validamos que el sentido de mario en x sea -1
            mariox+=movx*(-1); //Hacemos que el movimiento sea en ese sentido y sumamos
        }
        else{//Si no es -1
            mariox+=movx;//Sumamos
        }

        if(sym0==-1){ //validamos que el sentido de mario en y sea -1
            marioy+=movy*(-1); //Hacemos que el movimiento sea en ese sentido y sumamos
        }
        else{//si no es -1
            marioy+=movy; //sumamos
        }
    
    //--------------------------------------------
    //------Cambio de sentido de las copias-------
    //--------------------------------------------
        if(mariox<0){ //Cuando x es menor que 0 Mario puede estar en el 2do o 3er cuadrante

            if(marioy>=0){//Validamos que el mario original haya quedado en el 2do cuadrante
                sxc1*=(-1); //Cambiamos solo el sentido en X de sus copias
                sxc2*=(-1);  
            }
            else{ //ym0<0 Validamos que el mario original haya quedado en el 3er cuadrante
                syc1*=(-1); //Cambiamos solo el sentido en y de sus copias
                syc2*=(-1); 
            }
        }
        else if(mariox>=0 && marioy<0){ //Validamos que el mario original haya quedado en el 3er cuadrante
            sxc1*=(-1); //Cambiamos solo el sentido en X de sus copias
            sxc2*=(-1);
            syc1*=(-1); //Cambiamos solo el sentido en y de sus copias
            syc2*=(-1);
        }

    //Movimiento de la copia 1
        if(sxc1==-1){ //Validamos que el sentido de la copia 1 en x sea -1
            xc1+=movx*(-1); //Hacemos que el movimiento sea en ese sentido y sumamos
        }
        else{//Si no es -1
            xc1+=movx;//Sumamos
        }

        if(syc1==-1){ //validamos que el sentido de la copia 1 en y sea -1
            yc1+=movy*(-1); //Hacemos que el movimiento sea en ese sentido y sumamos
        }
        else{//si no es -1
            yc1+=movy; //sumamos
        }

    //Movimiento de la copia 2
        if(sxc2==-1){ //Validamos que el sentido de la copia 2 en x sea -1
            xc2+=movx*(-1); //Hacemos que el movimiento sea en ese sentido y sumamos
        }
        else{//Si no es -1
            xc2+=movx;//Sumamos
        }

        if(syc2==-1){ //validamos que el sentido de la copia 2 en y sea -1
            yc2+=movy*(-1); //Hacemos que el movimiento sea en ese sentido y sumamos
        }
        else{//si no es -1
            yc2+=movy; //sumamos
        }

        //Colision con la estrella
        //Colision con el scuttlebug m0, m1, m2

        //si beneficio > 0 {beneficio --}


    }*/
    return 0;
}