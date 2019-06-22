#include <iostream>
#include <string>
#include <random>

using namespace std;

#define LIMPA_TELA() system("CLEAR");
#define ok true;

enum
{
    CANCELA,
    DEBITO,
    CREDITO,
    DINHEIRO,
    CORTESIA
};

            enum
            {
                CINEMA,
                VOO,
                FUTEBOL,
                ONIBUS,
                TEATRO,
                FINALIZA
            };
class Usuario
{
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
    int getPreco(){return valor;}
    void setNome_evento(string n) { nome_evento = n; }
    void setData_evento(string d) { data_evento = d; }
    void setHora_evento(string h) { hora_evento = h; }
    void setLocal_evento(string l) { local_evento = l; }
    void setCategoria_evento(string c) { categoria_evento = c; }
    void setNum_bilhetes(int num) { num_bilhetes = num; }
    void setValor(double v) { valor = v; }

    void imprime_evento()
    {
        cout << ".......... " << tipo_evento << ".......... " << endl;
        cout << "Evento..................: " << nome_evento << endl;
        cout << "Data...................: " << data_evento << endl;
        cout << "Hora...................: " << hora_evento << endl;
        cout << "Local..................: " << local_evento << endl;
        cout << "Categoria..............: " << categoria_evento << endl;
        cout << "Ingressos disponiveis..: " << num_bilhetes << endl;
        cout << "Valor do Bilhete.......: " << valor << endl;
    }
};

class Filme : public Evento
{
protected:
    string genero;
public:
    void setGenero(string d){genero = d;}
};
class Voo : public Evento, public BilheteVoo
{
protected:
    string origem;
    string destino;
    string companhia_aerea;

public:
    
    void setOrigem(string o) { origem = o; }
    void setDestino(string d) { destino = d; }
    void setCompanhia_aerea(string ca) { companhia_aerea = ca; }
};

class Partida_futebol : public Evento, public BilheteFutebol
{
protected:
    string Time1;
    string Time2;

public:
    void setTime1(string t1) { Time1 = t1; }
    void setTime2(string t2) { Time2 = t2; }
};

//Classe abstrata Bilhete, cada evento especifico tem uma implementacao desta
class Bilhete : public Evento
{
protected:
    int assento;

public:
    virtual void gerarBilhete() = 0;

    void setAssento(int a) { assento = a; }
    
};

class BilheteFilme : public Bilhete, public Filme
{
private:
    string filme;

public:
    void setFilme(string f) { filme = f; }

    void gerarBilhete()
    {
        cout << "Filme..................:" << filme << endl;
        cout << "Numero do Assento......:" << assento << endl;
    }
};

class BilheteFutebol : public Bilhete, public Partida_futebol
{
private:
    int num_arquibancada;

public:
    void setNum_arquibancada(int num_arq) { num_arquibancada = num_arq; }

    void gerarBilhete()
    {
        cout << "Time 1.................:" << Time1 << endl;
        cout << "Time 2.................:" << Time2 << endl;
        cout << "Numero da Arquibancada.:" << num_arquibancada << endl;
    }
};

class BilheteVoo : public Bilhete, public Voo
{
private:
public:
    void gerarBilhete()
    {
        cout << "Origem.................:" << origem << endl;
        cout << "Destino................:" << destino << endl;
        cout << "Companhia Aerea........:" << companhia_aerea << endl;
    }
};

class Pagamento
{
    Usuario *usuario;
    Evento *evento;
    bool pagamentoRealizado;
    static int debitoCont, bilhetes_cortesia; //tds objetos tem a msm variavel
    

public:
    Pagamento(){pagamentoRealizado=false;}
    bool pagamentoEfetuado() { return pagamentoRealizado; }
    Pagamento(Usuario *u, Evento *e) : usuario(u), evento(e){};

    int debito()
    {
        cout << "Pagamento em de'bito, insira os seguintes dados:" << endl;
        cout << "Bandeira do Cartao:" << endl;
        string bandeira_cartao;
        cin >> bandeira_cartao;
        usuario->setBandeira_cartao(bandeira_cartao);
        cout << "Numero do Cartao:" << endl;
        string num_cartao;
        cin >> num_cartao;
                usuario->setNum_cartao(bandeira_cartao);

        if (debitoCont > 4)
            debitoCont = 0;
        //aceita 1 pedidos a cada 5 bilhetes
        if (debitoCont == 4 && usuario->pagar(evento->getPreco()) == true)
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
    }
    //sorteia se aprova transacao
    bool aprovar()
    {
        return (rand() % 10 == 0);
    }

    int credito()
    {
        cout << "Pagamento em de'bito, insira os seguintes dados:" << endl;
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
    }
    int dinheiro()
    {
        cout << "Pagamento em dinheiro, insira os seguintes dados:" << endl;
        cout << "Valor do pagamento:" << endl;
        unsigned int valorPagamento;
        cin >> valorPagamento;
        if (valorPagamento - evento->getPreco() > 0)
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
    }
    int cortesia()
    {
        cout << "Bilhete de cortesia, insira os seguintes dados:" << endl;
        cout << "CPF:" << endl;
        string cpf;
        cin >> cpf;
        bilhetes_cortesia++;
        if (bilhetes_cortesia > 14)
            bilhetes_cortesia = 0;
        //aceita 2 pedidos a cada 15 bilhetes
        if (bilhetes_cortesia == 0 || bilhetes_cortesia == 7)
        {
            cout << "Bilhete aceito!  " << endl;
            pagamentoRealizado = true;
        }
        else
        {
            cout << "Bilhete na'o aceito! " << endl;
            pagamentoRealizado = false;
        }
    }
};

class Bilheteria : public Evento
{
    string nome;
    string cpf;
    string bandeira_cartao;
    string num_cartao;
    Usuario *usuarioAtual;
    Evento *eventoEscolhido;
    Partida_futebol *partida;
    Filme *filme;
    Voo *voo;
    Bilhete *bilheteAtual;

public:
    void insereFilme(Filme *f){filme = f;}
    void inserePartida(Partida_futebol *p){partida = p;}
    void insereVoo(Voo *v){voo = v;}

    void paginaInicial()
    {
        while (1)
        {
            cout << "    O que deseja comprar?" << endl;
            cout << "--------------------------------" << endl;
            cout << " Menu de Opcoes:" << endl;
            cout << "--------------------------------" << endl;
            cout << "1. Cinema." << endl;
            cout << "2. Passagem Aerea." << endl;
            cout << "3. Futebol." << endl;
            cout << "4. Passagem de Onibus." << endl;
            cout << "5. Teatro." << endl;
            cout << "6. Sair." << endl;
            cout << "---------------------------" << endl;
            int opcao;
            cin >> opcao;


            paginaEventoEscolhido(opcao);
            if (bilheteAtual == nullptr)
            {
                cout << "Bilhete indisponivel!" << endl;
                continue;
            }
            bool comprado = compra_bilhete();
            if (comprado)
            {
                imprimeBilhete();
            }
            else
                continue;
        }
    }

    void imprimeBilhete()
    {
        LIMPA_TELA();
        bilheteAtual->gerarBilhete();
    }

    void leUsuario()
    {
        cout << "-----------Insira seus dados: ----------------" << endl;
        cout << "Nome:" << endl;
        cin >> nome;
        Usuario usuarioAtual(nome);
    }
    bool compra_bilhete()
    {
        cout << "Escolha a forma de Pagamento:" << endl;
        cout << "1. Debito." << endl;
        cout << "2. Credito." << endl;
        cout << "3. Dinheiro." << endl;
        cout << "4. Cancelar." << endl;

        unsigned int opcaoPagamento = 0;
        cin >> opcaoPagamento;

        Pagamento pagamentoAtual(usuarioAtual, eventoEscolhido);
        switch (opcaoPagamento)
        {
        case DEBITO:
            pagamentoAtual.debito();
            break;
        case CREDITO:
            pagamentoAtual.credito();
            break;
        case DINHEIRO:
            pagamentoAtual.dinheiro();
            break;
        case CORTESIA:
            pagamentoAtual.cortesia();
            break;
        default:
            break;
        }
        if (pagamentoAtual.pagamentoEfetuado())
            {return ok;}
        else {return !ok;}
    }

    Bilhete *paginaEventoEscolhido(int opcao)
    {
        switch (opcao)
        {
        case CINEMA:
            eventoEscolhido = filme;
            BilheteFilme *bilhete = new BilheteFilme;
            break;
        case VOO:
            eventoEscolhido = voo;
            BilheteVoo *bilhete = new BilheteVoo;
            break;
        case FUTEBOL:
            eventoEscolhido = partida;
            BilheteFutebol *bilhete = new BilheteFutebol;
            break;
        default:
            return nullptr;
            break;
        }
        *bilheteAtual = *eventoEscolhido; //bilhete herda filme e tem todos campos dele
        eventoEscolhido->imprime_evento();
        return bilheteAtual;
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

//Pelo enunciado nao precisa implementar
/*
    list <Evento*> listaEventos;         
    void inscreveEvento(Evento* evento){listaEventos.push_back(evento);}
    Evento* buscaEvento(string tipo){
        list <Evento*>::iterator first = listaEventos.begin();
        list <Evento*>::iterator last = listaEventos.end();
        for (; first != last; ++first) {
            if ((*first)->tipo == tipo) {
                return *first;
            }
        }
        return *last;
    }
 */