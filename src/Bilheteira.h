/**
 * Project Untitled
 */


#ifndef _BILHETEIRA_H
#define _BILHETEIRA_H

class Bilheteira {
public: 
  void nome_evento;
  void bilhetes_vendidos;
  void saldo;
  void lista_de_clientes;
  
void requisitar_dados();
  
void imprime_bilhete();
  
void realiza_compra();
  
void bilhete_cortesia();
};

#endif //_BILHETEIRA_H