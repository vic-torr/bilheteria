/**
 * Project Untitled
 */


#ifndef _BILHETE_H
#define _BILHETE_H

class Bilhete {
public: 
  void layout;
  void metodo_de_impressao;
  void nome;
  
virtual string imprime() = 0;
};

#endif //_BILHETE_H