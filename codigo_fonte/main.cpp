#include <iostream>
#include <string>
#include <random>

using namespace std;

#define LIMPA_TELA() \
  if (system("CLS")) \
    system("clear");
#define ok true;

enum
{
  CANCELA = 0,
  DEBITO,
  CREDITO,
  DINHEIRO,
  CORTESIA
};

enum
{
  CINEMA = 1,
  VOO,
  FUTEBOL,
  FINALIZA
};
class Usuario
{
  friend class Bilheteria;

protected:
  string nome;
  string cpf;
  string num_cartao;
  string bandeira_cartao;
  int saldo;

public:
  Usuario(string nome = "", string cpf = "", string num_cartao = "", string bandeira_cartao = "")
  {
    this->nome = nome;
    this->cpf = cpf;
    this->bandeira_cartao = bandeira_cartao;
    this->num_cartao = num_cartao;
    saldo = 1000;
  }
  string getNome() { return nome; }
  string getCpf() { return cpf; }
  string getNum_cartao() { return num_cartao; }
  string getBandeira_cartao() { return bandeira_cartao; }
  void setNome(string nome) { this->nome = nome; }
  void setCpf(string cpf) { this->cpf = cpf; }
  void setNum_cartao(string bandeira_cartao) { this->bandeira_cartao = bandeira_cartao; }
  void setBandeira_cartao(string num_cartao) { this->num_cartao = num_cartao; }
  bool pagar(int preco)
  {
    if (saldo > preco)
    {
      saldo -= preco;
      return true;
    }
    else
      return false;
  }
};
class Evento
{
  friend class BilheteFilme;
  friend class BilhetePartida;
  friend class BilheteVoo;
  friend class Bilheteria;

protected:
  string tipo_evento,
      nome_evento,
      data_evento,
      hora_evento,
      local_evento,
      categoria_evento;
  int num_bilhetes;
  int valor;

public:
  int getPreco() { return valor; }
  void setCategoria_evento(string c) { categoria_evento = c; }
  void setNome_evento(string n) { nome_evento = n; }
  void setData_evento(string d) { data_evento = d; }
  void setHora_evento(string h) { hora_evento = h; }
  void setLocal_evento(string l) { local_evento = l; }
  void setNum_bilhetes(int num) { num_bilhetes = num; }
  void setValor(double v) { valor = v; }

  void imprime_evento()
  {
    cout << ".......... " << categoria_evento << ".......... " << endl;
    cout << "Nome...................: " << nome_evento << endl;
    cout << "Data...................: " << data_evento << endl;
    cout << "Hora...................: " << hora_evento << endl;
    cout << "Local..................: " << local_evento << endl;
    cout << "Ingressos disponiveis..: " << num_bilhetes << endl;
    cout << "Valor do Bilhete.......: " << valor << endl;
  }
};

class Filme : public Evento
{
  friend class BilheteFilme;

protected:
  string genero;

public:
  void setGenero(string d) { genero = d; }
};
class Voo : public Evento
{
  friend class BilheteVoo;

protected:
  string origem;
  string destino;
  string companhia_aerea;

public:
  void setOrigem(string o) { origem = o; }
  void setDestino(string d) { destino = d; }
  void setCompanhia_aerea(string ca) { companhia_aerea = ca; }
};

class Partida_futebol : public Evento
{
  friend class BilheteFutebol;

protected:
  string Time1;
  string Time2;

public:
  void setTime1(string t1) { Time1 = t1; }
  void setTime2(string t2) { Time2 = t2; }
};

//Classe abstrata Bilhete, cada evento especifico tem uma implementacao desta
class Bilhete
{
protected:
  int assento;

public:
  virtual void gerarBilhete(Usuario *usuario) = 0;
  void setAssento(int a) { assento = a; }
};

class BilheteFilme : public Bilhete, public Filme
{
private:
  string dubladoOuLegendado;

public:
  BilheteFilme(Filme *filme, string dub_sub)
  {
    tipo_evento = filme->tipo_evento;
    nome_evento = filme->nome_evento;
    data_evento = filme->data_evento;
    hora_evento = filme->hora_evento;
    local_evento = filme->local_evento;
    categoria_evento = filme->categoria_evento;
    num_bilhetes = filme->num_bilhetes;
    valor = filme->valor;
    genero = filme->genero;
    dubladoOuLegendado = dub_sub;
  }
  void setdubladoOuLegendado(string x) { dubladoOuLegendado = x; }

  void gerarBilhete(Usuario *usuario)
  {
    cout << ".......... " << tipo_evento << ".......... " << endl;
    cout << "Nome:..................: " << nome_evento << endl;
    cout << "Data...................: " << data_evento << endl;
    cout << "Hora...................: " << hora_evento << endl;
    cout << "Local..................: " << local_evento << endl;
    cout << "Categoria..............: " << categoria_evento << endl;
    cout << "Valor do Bilhete.......: " << valor << endl;
    cout << "Dublado ou legendado...: " << dubladoOuLegendado << endl;
    cout << "Aseento numero.........: " << assento << endl;
    cout << "Comprador..............: " << usuario->getNome() << endl;
  }
};

class BilheteFutebol : public Bilhete, public Partida_futebol
{
private:
  string camarote;

public:
  BilheteFutebol(Partida_futebol *partida, string camarote)
  {
    categoria_evento = partida->categoria_evento;

    nome_evento = partida->nome_evento;
    data_evento = partida->data_evento;
    hora_evento = partida->hora_evento;
    local_evento = partida->local_evento;
    num_bilhetes = partida->num_bilhetes;
    valor = partida->valor;
    Time1 = partida->Time1;
    Time2 = partida->Time2;
    this->camarote = camarote;
  }

  void gerarBilhete(Usuario *usuario)
  {
    cout << "Categoria..............: " << categoria_evento << endl;
    cout << "Evento.................: " << nome_evento << endl;
    cout << "Data...................: " << data_evento << endl;
    cout << "Hora...................: " << hora_evento << endl;
    cout << "Local..................: " << local_evento << endl;
    cout << "Valor do Bilhete.......: " << valor << endl;
    cout << "Time 1.................: " << Time1 << endl;
    cout << "Time 2.................: " << Time2 << endl;
    cout << "Camarote/Normal:.......: " << camarote << endl;
    cout << "Aseento numero.........: " << assento << endl;
    cout << "Comprador..............: " << usuario->getNome() << endl;
  }
};

class BilheteVoo : public Bilhete, public Voo
{
private:
  string classeLuxo;

public:
  BilheteVoo(Voo *voo, string classe_Luxo)
  {
    tipo_evento = voo->tipo_evento;
    nome_evento = voo->nome_evento;
    data_evento = voo->data_evento;
    hora_evento = voo->hora_evento;
    local_evento = voo->local_evento;
    categoria_evento = voo->categoria_evento;
    num_bilhetes = voo->num_bilhetes;
    valor = voo->valor;
    destino = voo->destino;
    origem = voo-> origem;
    companhia_aerea = voo->companhia_aerea;
    classeLuxo = classe_Luxo;
  }
  void gerarBilhete(Usuario *usuario)
  {
    cout << "Categoria..............: " << categoria_evento << endl;
    cout << "Nome...................: " << nome_evento << endl;
    cout << "Data...................: " << data_evento << endl;
    cout << "Hora...................: " << hora_evento << endl;
    cout << "Local..................: " << local_evento << endl;
    cout << "Valor do Bilhete.......: " << valor << endl;
    cout << "Origem.................: " << origem << endl;
    cout << "Destino................: " << destino << endl;
    cout << "Companhia Aerea........: " << companhia_aerea << endl;
    cout << "Assento numero.........: " << assento << endl;
    cout << "Comprador..............: " << usuario->getNome() << endl;
  }
};

class Pagamento
{

  bool pagamentoRealizado;
  int debitoCont, bilhetes_cortesia, bilhetesVendidos; //tds objetos tem a msm variavel
public:
  Pagamento()
  {
    debitoCont = 0;
    bilhetesVendidos = 0;
    bilhetes_cortesia = 0;
    pagamentoRealizado = false;
  }
  bool pagamentoEfetuado() { return pagamentoRealizado; }
  
  //Pagamento por debito
  //Recebe usuario e evento; 
 //Retorna verdadeiro se for a compra for aceita
  bool debito(Usuario *usuario, Evento *evento)
  {
    cout << "Pagamento em de'bito, insira os seguintes dados:" << endl;
    cout << "Bandeira do Cartao:" << endl;
    string temp;
    cin >> temp;
    usuario->setBandeira_cartao(temp);
    cout << "Numero do Cartao:" << endl;
    cin >> temp;
    usuario->setNum_cartao(temp);

    if (debitoCont > 4)
      debitoCont = 0;
    //aceita 1 pedidos a cada 5 bilhetes
    if (debitoCont == 0 && usuario->pagar(evento->getPreco()) == true)
    {
      cout << "Compra realizada com sucesso! " << endl;
      pagamentoRealizado = true;
    }
    else
    {
      pagamentoRealizado = false;
      cout << "OPERACAO INVALIDA, CANCELANDO TRANSACAO " << endl;
    }
    debitoCont++;
    return pagamentoRealizado;
  }
  //sorteia se aprova transacao d credito
  bool aprovar()
  {
    return (rand() % 10 != 0); // 10% de chance de falhar, caso resto seja zero
  }
//Pagamento por credito
  //Recebe usuario e evento; 
 //Retorna verdadeiro se for a compra for aceita
  bool credito(Usuario *usuario, Evento *evento)
  {
    cout << "Pagamento em cartao de credito, insira os seguintes dados:" << endl;
    string bandeira_cartao;
    cin >> bandeira_cartao;
    usuario->setBandeira_cartao(bandeira_cartao);
    cout << "Numero do Cartao:" << endl;
    string num_cartao;
    cin >> num_cartao;
    usuario->setNum_cartao(bandeira_cartao);
    if (aprovar() && usuario->pagar(evento->getPreco()) == true)
    {
      cout << "Compra realizada com sucesso! " << endl;
      pagamentoRealizado = true;
    }
    else
    {
      cout << "OPERACAO INVALIDA, CANCELANDO TRANSACAO " << endl;
      pagamentoRealizado = false;
    }
    return pagamentoRealizado;
  }
  //Pagamento por dinheiro
  //Recebe usuario e evento; 
 //Retorna verdadeiro se for a compra for aceita
  bool dinheiro(Usuario *usuario, Evento *evento)
  {
    cout << "Pagamento em dinheiro, insira os seguintes dados:" << endl;
    cout << "Valor do pagamento:" << endl;
    int valorPagamento;
    cin >> valorPagamento;
    if ((valorPagamento - evento->getPreco()) > 0)
    {
      cout << "Compra realizada com sucesso!  " << endl;
      cout << "O troco e' de R$" << valorPagamento - evento->getPreco() << endl;
      pagamentoRealizado = true;
    }
    else
    {
      cout << "Valor insuficiente!" << endl;
      pagamentoRealizado = false;
    }
    return pagamentoRealizado;
  }

 //Recebe usuario e evento; 
 //Retorna verdadeiro se for a compra for aceita
  bool cortesia(Usuario *usuario, Evento *evento)
  {
    cout << "Bilhete de cortesia, insira os seguintes dados:" << endl;
    cout << "CPF:" << endl;
    string cpf;
    cin >> cpf;
    bilhetes_cortesia++;
    if (bilhetes_cortesia > 14)
      bilhetes_cortesia = 0;
    //aceita 2 pedidos a cada 15 bilhetes
    if (bilhetes_cortesia == 1 || bilhetes_cortesia == 7)
    {
      cout << "Bilhete aceito!  " << endl;
      pagamentoRealizado = true;
    }
    else
    {
      cout << "Bilhete na'o aceito! " << endl;
      pagamentoRealizado = false;
    }
    return pagamentoRealizado;
  }
};

class Bilheteria : public Evento
{
  Pagamento pagamentoAtual;
  Usuario *usuarioAtual;
  Evento *eventoEscolhido;
  Partida_futebol *partida;
  Filme *filme;
  Voo *voo;
  Bilhete *bilheteAtual;
  bool comprado;

public:
  Bilheteria()
  {
    usuarioAtual = 0;
    eventoEscolhido = 0;
    partida = 0;
    filme = 0;
    voo = 0;
    bilheteAtual = 0;
  }
  void insereFilme(Filme *f) { filme = f; }
  void inserePartida(Partida_futebol *p) { partida = p; }
  void insereVoo(Voo *v) { voo = v; }

  void paginaInicial()
  {
    while (1)
    {
   // Ignore to the end of line

      LIMPA_TELA();
      cout << "    O que deseja comprar?" << endl;
      cout << "--------------------------------" << endl;
      cout << " Menu de Opcoes:" << endl;
      cout << "--------------------------------" << endl;
      cout << "1. Cinema." << endl;
      cout << "2. Passagem Aerea." << endl;
      cout << "3. Futebol." << endl;
      cout << "4. Sair." << endl;
      cout << "---------------------------" << endl;
      int opcao=0;
      cin >> opcao;
  //    LIMPA_TELA();
      if (opcao == FINALIZA)
        break;                                     // retorna pra main
      bilheteAtual = paginaEventoEscolhido(opcao); //imprime o evento e retorna o bilhete

      if (bilheteAtual == nullptr) //Ponteiro nulo e' retornado em caso de opcao invalida
        goto fim;

      leUsuario();
      comprado = compra_bilhete();
      if (comprado == true){
        cout << "Deseja qual assento?" <<  endl;
        int assento=0;
        cin >> assento; 
        bilheteAtual->setAssento(assento);
        imprimeBilhete();
      }
    fim:
      pagina_finaliza();
      string temp;
      cin >> temp;
//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      //cin.get();
    }
  }

  void imprimeBilhete()
  {
    //LIMPA_TELA();
    bilheteAtual->gerarBilhete(usuarioAtual);
  }

  void leUsuario()
  {
    cout << "-----------Insira seus dados: ----------------" << endl;
    cout << "Nome:" << endl;
    string nome;
    cin >> nome;
    usuarioAtual = new Usuario;
    usuarioAtual->setNome(nome);
  }
  bool compra_bilhete()
  {
    cout << "Escolha a forma de Pagamento:" << endl;
    cout << "1. Debito." << endl;
    cout << "2. Credito." << endl;
    cout << "3. Dinheiro." << endl;
    cout << "4. Cortesia." << endl;
    cout << "5. Cancelar." << endl;

    unsigned int opcaoPagamento = 0;
    cin >> opcaoPagamento;
    bool status = false;
    switch (opcaoPagamento)
    {
    case DEBITO:
      status = pagamentoAtual.debito(usuarioAtual, eventoEscolhido);
      break;
    case CREDITO:
      status = pagamentoAtual.credito(usuarioAtual, eventoEscolhido);
      break;
    case DINHEIRO:
      status = pagamentoAtual.dinheiro(usuarioAtual, eventoEscolhido);
      break;
    case CORTESIA:
      status = pagamentoAtual.cortesia(usuarioAtual, eventoEscolhido);
      break;
    default:
      break;
    }
    return status;
  }

  Bilhete *paginaEventoEscolhido(int opcao)
  {
    Bilhete *bilhete;
    string temp;
    switch (opcao)
    {
    case CINEMA:
      eventoEscolhido = filme;
      cout << endl
           << "--------- Opcoes Disponiveis: ------" << endl;
      eventoEscolhido->imprime_evento();
      cout << endl
           << "--------- Dublado ou legendado? ------" << endl;
      cin >> temp;
      bilhete = new BilheteFilme(filme, temp);
      break;
    case VOO:
      eventoEscolhido = voo;
      cout << endl
           << "--------- Opcoes Disponiveis: ------" << endl;
      eventoEscolhido->imprime_evento();
      cout << endl
           << "--------- Classe Luxo ou economica? ------" << endl;
      cin >> temp;
      bilhete = new BilheteVoo(voo, temp);
      break;
    case FUTEBOL:
      eventoEscolhido = partida;
      cout << endl
           << "--------- Opcoes Disponiveis: ------" << endl;
      eventoEscolhido->imprime_evento();
      cout << endl
           << "--------- Camarote ou arquibancada? ------" << endl;
      cin >> temp;
      bilhete = new BilheteFutebol(partida, temp);
      break;
    default:
      cout << "Bilhete indisponivel!" << endl;
      return nullptr;
      break;
    }

    return bilhete;
  }

  void pagina_finaliza()
  {
    cout << "--------------------------------" << endl;
    cout << "Operacao Finalizada..." << endl;
  }
};

int main()
{
  int opcao, i, x;
  //Eventos de exemplo:
  Filme filmeVingadores;
  filmeVingadores.setCategoria_evento("Cinema");
  filmeVingadores.setNome_evento("Vingadores");
  filmeVingadores.setData_evento("28/06/19");
  filmeVingadores.setHora_evento("21:00");
  filmeVingadores.setLocal_evento("CineBrasil");
  filmeVingadores.setValor(22.5);
  filmeVingadores.setGenero("Acao/Ficcao");
  filmeVingadores.setNum_bilhetes(50);

  Voo losAngeles;
  losAngeles.setCategoria_evento("Viagem");
  losAngeles.setNome_evento("Passagem Aerea");
  losAngeles.setData_evento("01/07/19");
  losAngeles.setHora_evento("5:00");
  losAngeles.setLocal_evento("Aeroporto de Confins");
  losAngeles.setValor(350);
  losAngeles.setNum_bilhetes(200);
  losAngeles.setOrigem("Belo Horizonte");
  losAngeles.setDestino("Los Angeles");
  losAngeles.setCompanhia_aerea("AZUL");

  Partida_futebol cruVsCam;
  cruVsCam.setCategoria_evento("Partida de futebol");
  cruVsCam.setNome_evento("Cruzeiro vs Clube atletico mineiro");
  cruVsCam.setData_evento("30/07/19");
  cruVsCam.setHora_evento("20:00");
  cruVsCam.setLocal_evento("Mineirao");
  cruVsCam.setValor(95);
  cruVsCam.setNum_bilhetes(700);
  cruVsCam.setTime1("Atletico Mineiro");
  cruVsCam.setTime2("Cruzeiro");

  Bilheteria bilheteriaBeaga;
  bilheteriaBeaga.insereFilme(&filmeVingadores);
  bilheteriaBeaga.inserePartida(&cruVsCam);
  bilheteriaBeaga.insereVoo(&losAngeles);

  bilheteriaBeaga.paginaInicial();
  return 0;
}
