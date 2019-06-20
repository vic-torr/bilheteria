/**
 * Project Bilheteria
 */


#ifndef _BILHETE_H
#define _BILHETE_H

class Bilhete {
public: 
  string layout;
  string metodo_de_impressao;
  string nome;
  
virtual string imprime() = 0;
};

#endif //_BILHETE_H