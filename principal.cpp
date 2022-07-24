#include <iostream>

using namespace std;

int main (){
    int sxm0, sxc1, sxc2, sym0, syc1, syc2; //sentido x y Y de mario y sus copias 1 y 2
    float ubix, ubiy, xc1, xc2, yc1, yc2; //Ubicacion inicial de los 3 marios y Sentido X Y de cada mario

    int numS, vidas1, vidas2, vidas3; //Numero de scuttlebugs (Max3) y sus datos (x y vida)
    float xs1, xs2, xs3, ys1, ys2, ys3; //coordenadas scuttlebugs

    float Xestrella, Yestrella; //Ubicación x y de la estrella y
    int beneficio; // el contador de beneficio

    int m; //Numero de movimientos que tendrán
    float movx, movy, mariox, marioy; //El movimiento a realizar, su desgloce y la copia para usar con el sentido de mario
    
    bool coliM=false, coliC1=false, coliC2=false, error=false; //Indicador de colision de Mario y Copias, indicador de error

//--------------------------------------------
//----------Lectura de variables--------------
//--------------------------------------------

    cin>>ubix; cin>>ubiy;//ubicación inicial
    mariox=ubix; marioy=ubiy; xc1=ubix; xc2=ubix; yc1=ubiy; yc2=ubiy; //Definimos el punto inicial de mario y las copias

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
            xs2=999999*999;//Asignación evita que exista conflicto al evaluar la posicion de mario con scuttlebug inexistentes
            vidas2=1000;
            xs3=999999*999;//Asignación evita que exista conflicto al evaluar la posicion de mario con scuttlebug inexistentes
            vidas3=1000;
            break;
        case 2:
            cin>>xs1; cin>>ys1; cin>>vidas1;
            cin>>xs2; cin>>ys2; cin>>vidas2;
            xs3=999999*999;//Asignación evita que exista conflicto al evaluar la posicion de mario con scuttlebug inexistentes
            vidas3=1000;
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

    if(error==true){
        cout<<"Error en la entrada";
    }
    else{
    ///*
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

        //--------------------------------------------
        //----------------ColisionMario---------------
        //--------------------------------------------
            if ((mariox==xs1 && marioy==ys1) || (mariox==xs2&&marioy==ys2) || (mariox==xs3&&marioy==ys3)){
                if(beneficio==0){//Si no existe beneficio
                    if(mariox==xs1){ //Si fue con S1
                        vidas1-=2;
                    }
                    else if (mariox==xs2){ //Si fue con S2
                        vidas2-=2;
                    }
                    else{
                        vidas3-=2; //Si fue con S3
                    }

                }
                else{ //Si existe beneficio
                    if(mariox==xs1){ //Si fue con S1
                        vidas1=0;
                    }
                    else if (mariox==xs2){ //Si fue con S2
                        vidas2=0;
                    }
                    else{
                        vidas3=0; //Si fue con S3
                    }  
                }

            //--------------------------------------------
            //---------Eliminacion de Enemigo-------------
            //--------------------------------------------
                if(vidas1==0||vidas2==0||vidas3==0){
                    xc1=mariox; //Sincronización de ubicacicón
                    xc2=mariox;
                    yc1=marioy;
                    yc2=marioy;
                    coliM=true;
                }
            }
        //--------------------------------------------
        //----------------Movimiento C1------------------
        //--------------------------------------------
            if(coliM==false){//Si no se elimino un scuttlebug en el movimiento anterior
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

            //Colision
                if ((xc1==xs1 && yc1==ys1) || (xc1==xs2&&xc1==ys2) || (xc1==xs3&&yc1==ys3)){
                    if(beneficio==0){//Si no existe beneficio
                        if(xc1==xs1){ //Si fue con S1
                            vidas1-=1;
                        }
                        else if (xc1==xs2){ //Si fue con S2
                            vidas2-=1;
                        }
                        else{
                            vidas3-=1; //Si fue con S3
                        }

                    }
                    else{ //Si existe beneficio
                        if(xc1==xs1){ //Si fue con S1
                            vidas1=0;
                        }
                        else if (xc1==xs2){ //Si fue con S2
                            vidas2=0;
                        }
                        else{
                            vidas3=0; //Si fue con S3
                        }
                    }
                //--------------------------------------------
                //---------Eliminacion de Enemigo-------------
                //--------------------------------------------
                    if(vidas1==0||vidas2==0||vidas3==0){ //Si elimino
                        mariox=xc1; //Sincronización de ubicacicón
                        xc2=xc1;
                        marioy=yc1;
                        yc2=yc1;
                        coliC1=true; //Indicador
                    }
                }
            }
            
        //--------------------------------------------
        //----------------Movimiento C2--------------
        //--------------------------------------------
            if(coliM==false && coliC1==false){//Si no se elimino un scuttlebug en los movimientos anteriores
            //Movimiento de la copia 2
                if(sxc2==-1){ //Validamos que el sentido de la copia 1 en x sea -1
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

            //Colision
                if ((xc2==xs1 && yc2==ys1) || (xc2==xs2&&xc2==ys2) || (xc2==xs3&&yc2==ys3)){
                    if(beneficio==0){//Si no existe beneficio
                        if(xc2==xs1){ //Si fue con S1
                            vidas1-=1;
                        }
                        else if (xc2==xs2){ //Si fue con S2
                            vidas2-=1;
                        }
                        else{
                            vidas3-=1; //Si fue con S3
                        }

                    }
                    else{ //Si existe beneficio
                        if(xc2==xs1){ //Si fue con S1
                            vidas1=0;
                        }
                        else if (xc2==xs2){ //Si fue con S2
                            vidas2=0;
                        }
                        else{
                            vidas3=0; //Si fue con S3
                        }
                    }
                //--------------------------------------------
                //---------Eliminacion de Enemigo-------------
                //--------------------------------------------
                    if(vidas1==0||vidas2==0||vidas3==0){ //Si elimino
                        mariox=xc2; //Sincronización de ubicacicón
                        xc1=xc2;
                        marioy=yc2;
                        yc1=yc2;
                        coliC2=true; //Indicador
                    }
                }
            }

        //Resta del beneficio    
            if (beneficio>0){
                beneficio--;
            }

        //--------------------------------------------
        //---------Colision con la estrella-----------
        //--------------------------------------------
            if ((mariox==Xestrella && marioy==Yestrella) || (xc1==Xestrella && yc1==Yestrella) || (xc2==Xestrella && yc2==Yestrella)){
                beneficio+=2;
            }

        //Reinicio de colisiones
            coliM=false;
            coliC1=false;
            coliC2=false;
        }

        //Salidas del programa según el final. 
        //“Perfectamente alineados”. “Desincronización total” “Posición de la 1era copia: ” y/o “Posición de la 2da copia: ”
        //Posición del Scuttlebug 2: (2,2); Vida=2
        
    }

    return 0;
}