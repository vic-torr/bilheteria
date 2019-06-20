/**
 * Project Bilheteria
 */


#ifndef _BILHETE_H
#define _BILHETE_H

#include "Evento.h"


class Bilhete {
public: 
  string layout;
  string metodo_de_impressao;
  string nome;
  
virtual string imprime() = 0;
};

class BilheteFilme: public Bilhete, public FIlme {
};

class BilhetePartida: public Bilhete, public Partida_futebol {
};

class BilheteVoo: public Bilhete, public Voo {
};


#endif //_BILHETE_H