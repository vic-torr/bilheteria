/**
 * Project Untitled
 */


#ifndef _VOO_H
#define _VOO_H

#include "Evento.h"


class Voo: public Evento {
public: 
  void destino;
  void origem;
  void companhia;
  void numero_de_assentos;
};

#endif //_VOO_H