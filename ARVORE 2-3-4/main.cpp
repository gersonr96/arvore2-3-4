//
//  main.cpp
//  ARVORE 2-3-4
//
//  Created by Gerson Rodrigo on 01/11/16.
//  Copyright © 2016 Gerson Rodrigo. All rights reserved.
//

#include <iostream>
#include "Arvore.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Arvore arv = Arvore();
    
//    arv.inserir(3);
//    arv.inserir(4);
//    arv.inserir(5);
    
    
    for (int i = 0; i < 100; i++)
        arv.inserir(i * rand()%1000);
    
    arv.mostrar();
    
    arv.buscar(-150);
  
    printf("sem crash");
    return 0;
}
