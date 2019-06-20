/**
 * Project Bilheteria
 */


#ifndef _VOO_H
#define _VOO_H

#include "Evento.h"


class Voo: public Evento {
public: 
  string destino;
  string origem;
  string companhia;
  string numero_de_assentos;
};

#endif //_VOO_H