/**
 * Project Bilheteria
 */
#include <cstring>

#ifndef _EVENTO_H
#define _EVENTO_H

class Evento {
public: 
  string nome;
  string data;
  string total_bilhetes;
  string hora;
  string local;
  string tipo;
};


class FIlme: public Evento {
public: 
  string diretor;
  string genero;
};


class Voo: public Evento {
public: 
  string destino;
  string origem;
  string companhia;
  string numero_de_assentos;
};


class Partida_futebol: public Evento {
public: 
  string time1;
  string time2;
};

#endif //_EVENTO_H