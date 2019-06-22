#ifndef _BILHETERIA_H
#define _BILHETERIA_H
#include <cstring>
#include <Bilhete.h>
#include <Evento.h>
#include <Pagamento.h>
#include <Usuario.h>

class Bilheteria {
public: 
  string nome_evento;
  int bilhetes_vendidos;
  int saldo;
  void lista_de_clientes;
  
void requisitar_dados();
  
void imprime_bilhete();
  
void realiza_compra();
  
void bilhete_cortesia();
};

#endif //_BILHETERIA_H