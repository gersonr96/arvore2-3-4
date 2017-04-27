//
//  Arvore.hpp
//  ARVORE 2-3-4
//
//  Created by Gerson Rodrigo on 01/11/16.
//  Copyright © 2016 Gerson Rodrigo. All rights reserved.
//

#ifndef Arvore_hpp
#define Arvore_hpp

#include <stdio.h>
#include "NO.hpp"


//typedef struct NO{
//    struct NO *filhos[4];
//    int chave[3];
//    int nfilhos = 0;
//    int nchaves = 0;
//    
//    
//}no;

class Arvore{
    
    
       public:
    NO *raiz;
    void inserir(int n);
    void remover(int n);
    void buscar(int n);
    
    void mostrar();
    
    Arvore();
    
     private:
     int buscar(NO *node, int chave);
     void inserir(NO *pai, int n);
    
     void dividir_no(NO *node);
    
    bool tem_filho(NO *node);
    
    
    void ordena(int *chaves, int n);
    int achamaior(NO *node, int i);
    
    void mostrar(NO *node);
    
    
    void ajusta(NO *node);
};

#endif /* Arvore_hpp */
