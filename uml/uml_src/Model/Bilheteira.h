/**
 * Project Untitled
 */


#ifndef _BILHETEIRA_H
#define _BILHETEIRA_H

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