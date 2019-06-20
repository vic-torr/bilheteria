/**
 * Project Bilheteria
 */


#ifndef _BILHETEPARTIDA_H
#define _BILHETEPARTIDA_H

#include "Bilhete.h"
#include "Partida_futebol.h"


class BilhetePartida: public Bilhete, public Partida_futebol {
};

#endif //_BILHETEPARTIDA_H