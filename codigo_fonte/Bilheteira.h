/**
 * Project Bilheteria
 */


#ifndef _BILHETEIRA_H
#define _BILHETEIRA_H

#include <Bilhete.h>
#include <Evento.h>
#include <Pagamento.h>
#include <Usuario.h>

class Bilheteira {
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

#endif //_BILHETEIRA_H