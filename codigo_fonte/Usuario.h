/**
 * Project Bilheteria
 */
#include <cstring>

#ifndef _USUARIO_H
#define _USUARIO_H

class Usuario {
public: 
  string Nome;
  
void comprar_bilhete();
  
void realiza_compra();
private: 
  string RG;
  string CPF;
  string num_cartao;
  int bandeira_cartao;
  int saldo;
};

class Usuario
{
    private:
    string nome;
    string cpf;
    string num_cartao;
    string bandeira_cartao;
    //string saldo; Usuario informa o proprio saldo?

    public:
    Usuario(string nome, string cpf, string num_cartao, string bandeira_cartao)
    {
        this->nome=nome;
        this->cpf=cpf;
        this->bandeira_cartao=bandeira_cartao;
        this->num_cartao=num_cartao;
    }
    string getNome()               {return nome;}
    string getCpf()                {return cpf;}
    string getNum_cartao()         {return num_cartao;}
    string getBandeira_cartao()    {return bandeira_cartao;}
};

#endif //_USUARIO_H