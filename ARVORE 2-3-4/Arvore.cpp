//
//  Arvore.cpp
//  ARVORE 2-3-4
//
//  Created by Gerson Rodrigo on 01/11/16.
//  Copyright © 2016 Gerson Rodrigo. All rights reserved.
//

#include "Arvore.hpp"
#include <iostream>

using namespace std;

Arvore::Arvore(){
    raiz =  new NO;//(NO*)malloc(sizeof(no*));
//    raiz->nchaves = 0;
//    raiz->nfilhos = 0;
//    
    cout << " Arvore criada com sucesso " <<endl;
}

void Arvore::inserir(int n){

    inserir(raiz, n);
}


void Arvore::inserir(NO *node, int chave){
    
    int tam = 3;
    
    if(tem_filho(node) == true){
        for (int j=0; j< node->nchaves; j++){
            if ( chave < node->chaves[j]){
                tam = j;
                break;
            }
        }
        inserir(node->filhos[tam], chave);

    }
    else{
        
        node->chaves[node->nchaves++] = chave;
        ordena(node->chaves, node->nchaves);
        
        if (node->nchaves > 3){
            dividir_no(node);
            ajusta(node);
        }
    }
    
        
        
}

void Arvore::ordena(int *chaves, int n){
 

        int i,j, aux;
    
        for (i=0; i < n; i++) {
            for (j= i; j< n; j++) {
                aux = chaves[i];
                chaves[i] = chaves[j];
                chaves[j] = aux;
            }
        }
    
    
    
//    int i,j, aux;
//    
//    for (i=0; i < node->nchaves; i++) {
//        for (j=0; j< node->nchaves; j++) {
//            aux = node->chave[i];
//            node->chave[i] = node->chave[j];
//            node->chave[j] = node->chave[i];
//        }
//    }
}

void Arvore::dividir_no(NO *node){
    
    
    NO *no1 =  new NO;
    NO *no2 = new NO;
    
    no1->nchaves = 2;
    for (int i =0; i < no1->nchaves; i++){
        no1->chaves[i] = node->chaves[i];
    }
    no2->nchaves = 1;
    no2->chaves[0] = node->chaves[3];
    if (tem_filho(node) == true)
    {
        no1->filhos[0] = node->filhos[0];
        no1->filhos[1] = node->filhos[1];
        no1->filhos[2] = node->filhos[2];
        no2 = node->filhos[3];
    }
    
    
    
    node->nchaves =1;
    node->chaves[0] = node->chaves[2];
    node->filhos[0] = no1;
    node->filhos[1] = NULL;
    node->filhos[2] = NULL;
    node->filhos[3] = no2;
    
    
    

}


int Arvore::achamaior(NO *node, int i){
    
    int  maior = -9999,indice = 0;
    for ( i=0; i< node->nchaves; i++){
        if (node->chaves[i] > maior){
            maior = node->chaves[i];
            indice = i;
        }
    }
    return indice;

}


bool Arvore::tem_filho(NO *node){
    int i;
    for (i = 0; i < 4; i++){
    
        if (node->filhos[i] != NULL){
            return true;
        }
    }
    return false;
}





void Arvore::ajusta(NO *node){
    
    
    if( tem_filho(node) == true){
        for (int i = 0; i < 4; i++) {
           
            if( node->filhos[i] != NULL && tem_filho(node) == true){
             
                node->chaves[node->nchaves++] = node->filhos[i]->chaves[0];
              
                ordena(node->chaves,node->nchaves);
                
                if (node->nchaves >3)
                    dividir_no(node);
                
                NO *temporario;
                temporario = node->filhos[i];
                
                if (i == 3){
                    node->filhos[3] = temporario->filhos[3];
                    if (node->filhos[1] == NULL){
                        node->filhos[1] = temporario->filhos[0];
                    }else{
                        if (node->filhos[2] == NULL){
                            node->filhos[2] = temporario->filhos[0];
                        }
                    }
                }
                
                if (i == 0){
                    node->filhos[0] = temporario->filhos[0];
                    
                    if(node->filhos[1] == NULL)
                        node->filhos[1] = temporario->filhos[3];
                    else
                        if (node->filhos[2] == NULL)
                            node->filhos[2] = temporario->filhos[3];
                }
                
                if ( i == 1){
                    
                    node->filhos[1] = temporario->filhos[0];
                    if (node->filhos[2] == NULL)
                        node->filhos[2] = temporario->filhos[3];
                }
                
                if (i==2){
                    
                    node->filhos[2] = temporario->filhos[0];
                    if (node->filhos[3] == NULL)
                        node->filhos[3] = temporario->filhos[0];
                }
                
                
            }
        }

    }
}



void Arvore::mostrar(){
    mostrar(raiz);
}

void Arvore::mostrar(NO *node){
    
    int j=0;
    if (node!=NULL){
        
        for (int i = 0; i < 4; i++){
            
            mostrar(node->filhos[i]);
            if (j < node->nchaves){
                cout << node->chaves [j++] << "   ";
            }
        }
    }
}



void Arvore::buscar(int n){
    if (buscar(raiz, n)){
        printf("encontrou");
    }else{
        printf("Nada");
    }
}




int Arvore::buscar(NO *node,int chave){
    int j=0;
    if (node!=NULL){
        
        for (int i = 0; i < 4; i++){
            
            mostrar(node->filhos[i]);
            if (chave ==  node->chaves[j]){
                return  1;
            }else{
                j++;
            }
        }
    }
    return 0;
}




