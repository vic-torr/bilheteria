/**
 * Project Bilheteria
 */


#ifndef _FILME_H
#define _FILME_H

#include "Evento.h"


class FIlme: public Evento {
public: 
  string diretor;
  string genero;
};

#endif //_FILME_H