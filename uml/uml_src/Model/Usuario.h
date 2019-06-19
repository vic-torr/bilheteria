/**
 * Project Untitled
 */


#ifndef _USUARIO_H
#define _USUARIO_H

class Usuario {
public: 
  sting Nome;
  
void comprar_bilhete();
  
void realiza_compra();
private: 
  string RG;
  string CPF;
  string num_cartao;
  int bandeira_cartao;
  int saldo;
};

#endif //_USUARIO_H