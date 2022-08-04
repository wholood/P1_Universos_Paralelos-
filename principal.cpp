#include <iostream>

using namespace std;

int main (){
    int sxm0, sxc1, sxc2, sym0, syc1, syc2; //sentido x y Y de mario y sus copias 1 y 2
    int ubix, ubiy, xc1, xc2, yc1, yc2; //Ubicacion inicial de los 3 marios y Sentido X Y de cada mario

    int numS, vidas1=0, vidas2=0, vidas3=0; //Numero de scuttlebugs (Max3) y sus datos (x y vida)
    int xs1, xs2, xs3, ys1, ys2, ys3; //coordenadas scuttlebugs

    int Xestrella, Yestrella; //Ubicación x y de la estrella y
    int beneficio; // el contador de beneficio

    int m; //Numero de movimientos que tendrán
    int movx, movy, mariox, marioy; //El movimiento a realizar, su desgloce y la copia para usar con el sentido de mario
    
    bool coliM=false, coliC1=false, coliC2=false, error=false; //Indicador de colision de Mario y Copias para condicionar la ejecucion de movimientos, indicador de error
    bool cols1=false, cols2=false, cols3=false, estrellacol=false; //Indicadores para validar si la colision con el enemigo lo llevo a la muerte y por ende cerrar los movimientos

//--------------------------------------------
//----------Lectura de variables--------------
//--------------------------------------------

    cin>>ubix; cin>>ubiy;//ubicación inicial
    mariox=ubix; marioy=ubiy; xc1=ubix; xc2=ubix; yc1=ubiy; yc2=ubiy; //Definimos el punto inicial de mario y las copias

    cin>>sxm0; cin>>sym0;//sentido mario
    cin>>sxc1; cin>>syc1;//sentido copia 1
    cin>>sxc2; cin>>syc2;//sentido copia 2
    
    //Validamos los sentidos
    if((sxm0!=1 && sxm0!=-1) || (sym0!=1 && sym0!=-1)){//mario
        error=true;  
    }
    if((sxc1!=1 && sxc1!=-1) || (syc1!=1 && syc1!=-1)){ //copia 1
        error=true;
    }
    if((sxc2!=1 && sxc2!=-1) || (syc2!=1 && syc2!=-1)){//copia 2
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

    if(m<=0){ //Validar si el numero de movimientos es mayor a cero
        error=true;
    }

    if(error==false){
    //
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
            else if(mariox>=0 && marioy<0){ //Validamos que el mario original haya quedado en el 4to cuadrante
                sxc1*=(-1); //Cambiamos solo el sentido en X de sus copias
                sxc2*=(-1);
                syc1*=(-1); //Cambiamos solo el sentido en y de sus copias
                syc2*=(-1);
            }

        //--------------------------------------------R
        //----------------ColisionMario---------------
        //--------------------------------------------
            if(numS>=1){
                if (mariox==xs1 && marioy==ys1){
                    if(beneficio<=0){//Si no existe beneficio
                        if(mariox==xs1){ //Si fue con S1
                            vidas1-=2;
                            cols1=true;//Indicador de colision
                        } 
                    }
                    else{ //Si existe beneficio
                        if(mariox==xs1){ //Si fue con S1
                            vidas1=0;
                            cols1=true;
                        }
                    }
                }
                if(numS>=2){
                    if (mariox==xs2 && marioy==ys2){
                        if(beneficio<=0){//Si no existe beneficio
                            if(mariox==xs2){ //Si fue con S1
                                vidas2-=2;
                                cols2=true;//Indicador de colision
                            } 
                        }
                        else{ //Si existe beneficio
                            if(mariox==xs2){ //Si fue con S1
                                vidas2=0;
                                cols2=true;
                            }
                        }
                    } 
                }
                if(numS==3){
                    if (mariox==xs3 && marioy==ys3){
                        if(beneficio<=0){//Si no existe beneficio
                            if(mariox==xs3){ //Si fue con S1
                                vidas3-=2;
                                cols3=true;//Indicador de colision
                            } 
                        }
                        else{ //Si existe beneficio
                            if(mariox==xs3){ //Si fue con S1
                                vidas3=0;
                                cols3=true;
                            }
                        }
                    }
                }

            //--------------------------------------------
            //---------Eliminacion de Enemigo-------------
            //--------------------------------------------
                if(cols1==true){
                    if(vidas1<=0){
                        xc1=mariox; //Sincronización de ubicacicón
                        xc2=mariox;
                        yc1=marioy;
                        yc2=marioy;
                        coliM=true;   
                    }
                    cols1=false;
                }
                if(cols2==true){
                    if(vidas2<=0){
                        xc1=mariox; //Sincronización de ubicacicón
                        xc2=mariox;
                        yc1=marioy;
                        yc2=marioy;
                        coliM=true;   
                    }
                    cols2=false;
                }
                if(cols3==true){
                    if(vidas3<=0){
                        xc1=mariox; //Sincronización de ubicacicón
                        xc2=mariox;
                        yc1=marioy;
                        yc2=marioy;
                        coliM=true;   
                    }
                    cols3=false;
                }
            }
        
        //--------------------------------------------
        //---------Colision con la estrella-----------
        //--------------------------------------------
            if (estrellacol==false && mariox==Xestrella && marioy==Yestrella){
                beneficio+=2;
                estrellacol=true;
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
            //--------------------------------------------
            //--------------Colision C1------------------
            //--------------------------------------------
                if(numS>=1){
                    if (xc1==xs1 && yc1==ys1){
                        if(beneficio<=0){//Si no existe beneficio
                            if(xc1==xs1){ //Si fue con S1
                                vidas1-=1;
                                cols1=true;//Indicador de colision
                            } 
                        }
                        else{ //Si existe beneficio
                            if(xc1==xs1){ //Si fue con S1
                                vidas1=0;
                                cols1=true;
                            }
                        }
                    }
                    if(numS>=2){
                        if (xc1==xs2 && yc1==ys2){
                            if(beneficio<=0){//Si no existe beneficio
                                if(xc1==xs2){ //Si fue con S1
                                    vidas2-=1;
                                    cols2=true;//Indicador de colision
                                } 
                            }
                            else{ //Si existe beneficio
                                if(xc1==xs2){ //Si fue con S1
                                    vidas2=0;
                                    cols2=true;
                                }
                            }
                        } 
                    }
                    if(numS==3){
                        if (xc1==xs3 && yc1==ys3){
                            if(beneficio<=0){//Si no existe beneficio
                                if(xc1==xs3){ //Si fue con S1
                                    vidas3-=1;
                                    cols3=true;//Indicador de colision
                                } 
                            }
                            else{ //Si existe beneficio
                                if(xc1==xs3){ //Si fue con S1
                                    vidas3=0;
                                    cols3=true;
                                }
                            }
                        }
                    }
            //--------------------------------------------
            //---------Eliminacion de Enemigo-------------
            //--------------------------------------------
                if(cols1==true){
                        if(vidas1<=0){
                            mariox=xc1; //Sincronización de ubicacicón
                            xc2=xc1;
                            marioy=yc1;
                            yc2=yc1;
                            coliC1=true;   
                        }
                        cols1=false;
                    }
                    if(cols2==true){
                        if(vidas2<=0){
                            mariox=xc1; //Sincronización de ubicacicón
                            xc2=xc1;
                            marioy=yc1;
                            yc2=yc1;
                            coliC1=true;   
                        }
                        cols2=false;
                    }
                    if(cols3==true){
                        if(vidas3<=0){
                            mariox=xc1; //Sincronización de ubicacicón
                            xc2=xc1;
                            marioy=yc1;
                            yc2=yc1;
                            coliC1=true;   
                        }
                        cols3=false;
                    }
                }
                //--------------------------------------------
                //---------Colision con la estrella-----------
                //--------------------------------------------
                if (estrellacol==false && xc1==Xestrella && yc1==Yestrella){
                    beneficio+=2;
                    estrellacol=true;
                }
            }

            
            
            
        //--------------------------------------------
        //----------------Movimiento C2--------------
        //--------------------------------------------
            if(coliM==false && coliC1==false){//Si no se elimino un scuttlebug en los movimientos anteriores
            //Movimiento de la copia 2
                if(sxc2==-1){ //Validamos que el sentido de la copia 1 en x sea -1
                    xc2+=movx*(-1); //Hacemos que el movimiento sea en ese sentido y sumamos
                }
                else{//Si no es -1
                    xc2+=movx;//Sumamos
                }

                if(syc2==-1){ //validamos que el sentido de la copia 1 en y sea -1
                    yc2+=movy*(-1); //Hacemos que el movimiento sea en ese sentido y sumamos
                }
                else{//si no es -1
                    yc2+=movy; //sumamos
                }

            //--------------------------------------------
            //--------------Colision C2------------------
            //--------------------------------------------
                if(numS>=1){
                    if (xc2==xs1 && yc2==ys1){
                        if(beneficio<=0){//Si no existe beneficio
                            if(xc2==xs1){ //Si fue con S1
                                vidas1-=1;
                                cols1=true;//Indicador de colision
                            } 
                        }
                        else{ //Si existe beneficio
                            if(xc2==xs1){ //Si fue con S1
                                vidas1=0;
                                cols1=true;
                            }
                        }
                    }
                    if(numS>=2){
                        if (xc2==xs2 && yc2==ys2){
                            if(beneficio<=0){//Si no existe beneficio
                                if(xc2==xs2){ //Si fue con S1
                                    vidas2-=1;
                                    cols2=true;//Indicador de colision
                                } 
                            }
                            else{ //Si existe beneficio
                                if(xc2==xs2){ //Si fue con S1
                                    vidas2=0;
                                    cols2=true;
                                }
                            }
                        } 
                    }
                    if(numS==3){
                        if (xc2==xs3 && yc2==ys3){
                            if(beneficio<=0){//Si no existe beneficio
                                if(xc2==xs3){ //Si fue con S1
                                    vidas3-=1;
                                    cols3=true;//Indicador de colision
                                } 
                            }
                            else{ //Si existe beneficio
                                if(xc2==xs3){ //Si fue con S1
                                    vidas3=0;
                                    cols3=true;
                                }
                            }
                        }
                    }
                //--------------------------------------------
                //---------Eliminacion de Enemigo-------------
                //--------------------------------------------
                    if(cols1==true){
                        if(vidas1<=0){
                            mariox=xc2; //Sincronización de ubicacicón
                            xc1=xc2;
                            marioy=yc2;
                            yc1=yc2;
                            coliC2=true;   
                        }
                        cols1=false;
                    }
                    if(cols2==true){
                        if(vidas2<=0){
                            mariox=xc2; //Sincronización de ubicacicón
                            xc1=xc2;
                            marioy=yc2;
                            yc1=yc2;
                            coliC2=true;   
                        }
                        cols2=false;
                    }
                    if(cols3==true){
                        if(vidas3<=0){
                            mariox=xc2; //Sincronización de ubicacicón
                            xc1=xc2;
                            marioy=yc2;
                            yc1=yc2;
                            coliC2=true;   
                        }
                        cols3=false;
                    }
                }
            //--------------------------------------------
            //---------Colision con la estrella-----------
            //--------------------------------------------
                if (estrellacol==false && xc2==Xestrella && yc2==Yestrella){
                    beneficio+=2;
                    estrellacol=true;
                }
            }

        //Resta del beneficio    
            if (beneficio>0){
                beneficio--;
            }


        //Reinicio de colisiones
            coliM=false;
            coliC1=false;
            coliC2=false;
        } //Fin del bucle

        //--------------------------------------------
        //----------------Salidas---------------------
        //--------------------------------------------
        if(mariox==xc1&& marioy==yc1 && mariox==xc2 && marioy==yc2){ //Si la ubicación es igual
            cout<<"Perfectamente alineados\n";
            cout<<"Posición de Mario: ("<<mariox<<" ,"<<marioy<<")\n";
        }
        else{ //Si no es igual
            cout<<"Desincronización total\n";
            cout<<"Posición de Mario: ("<<mariox<<" ,"<<marioy<<")\n";
            cout<<"Posición de la 1era copia: ("<<xc1<<" ,"<<yc1<<")\n";
            cout<<"Posición de la 2da copia: ("<<xc2<<" ,"<<yc2<<")\n";
        }

        if(vidas1>0){
            cout<<"Posición del Scuttlebug 1: ("<<xs1<<","<<ys1<<"); Vida="<<vidas1<<endl;
        }
        else if(vidas2>0){
            cout<<"Posición del Scuttlebug 2: ("<<xs2<<","<<ys2<<"); Vida="<<vidas2<<endl;
        }
        else if(vidas3>0){
            cout<<"Posición del Scuttlebug 3: ("<<xs3<<","<<ys3<<"); Vida="<<vidas3<<endl;
        }
    }
    else{
        cout<<"Error en la entrada";
    }

    return 0;
}