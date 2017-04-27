//
//  NO.hpp
//  ARVORE 2-3-4
//
//  Created by Gerson Rodrigo on 07/11/16.
//  Copyright © 2016 Gerson Rodrigo. All rights reserved.
//

#ifndef NO_hpp
#define NO_hpp

#include <iostream>


class NO{
//    struct NO *filhos[4];
//    int chave[3];
//    int nfilhos = 0;
//    int nchaves = 0;
//    
    
public:
    NO* filhos[4];
    int nchaves;
    int  chaves[4];
    
    NO(){
        
        nchaves = 0;
        for (int i = 0; i < 4; i ++){
            filhos[i] = NULL;
        }
    }
    
};

#endif /* NO_hpp */
