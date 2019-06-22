#include <iostream>
#include <cstring>

using namespace std;

#define LIMPA_TELA() system(CLEAR);

class Usuario
{
protected:
    string nome;
    string cpf;
    string num_cartao; 
    string bandeira_cartao;

public:
    Usuario(string nome = "", string cpf = "", string num_cartao = "", string bandeira_cartao = "")
    {
        this->nome = nome;
        this->cpf = cpf;
        this->bandeira_cartao = bandeira_cartao;
        this->num_cartao = num_cartao;
    }
    string getNome() { return nome; }
    string getCpf() { return cpf; }
    string getNum_cartao() { return num_cartao; }
    string getBandeira_cartao() { return bandeira_cartao; }
    void setNome(string nome) { this->nome = nome; }
    void setCpf(string cpf) { this->cpf = cpf; }
    void setNum_cartao(string bandeira_cartao) { this->bandeira_cartao = bandeira_cartao; }
    void setBandeira_cartao(string num_cartao) { this->num_cartao = num_cartao; }
};
class Evento
{
protected:
    string nome_evento;
    string data_evento;
    string hora_evento;
    string local_evento;
    string categoria_evento;
    int num_bilhetes;
    double valor;

public:
    void setNome_evento(string n) { nome_evento = n; }
    void setData_evento(string d) { data_evento = d; }
    void setHora_evento(string h) { hora_evento = h; }
    void setLocal_evento(string l) { local_evento = l; }
    void setCategoria_evento(string c) { categoria_evento = c; }
    void setNum_bilhetes(int num) { num_bilhetes = num; }
    void setValor(double v) { valor = v; }

    imprime_evento()
    {
        cout << "Evento..................: " << nome_evento << endl;
        cout << "Data...................: " << data_evento << endl;
        cout << "Hora...................: " << hora_evento << endl;
        cout << "Local..................: " << local_evento << endl;
        cout << "Categoria..............: " << categoria_evento << endl;
        cout << "Ingressos disponiveis..: " << num_bilhetes << endl;
        cout << "Valor do Bilhete.......: " << valor << endl;
    }
};

class Filme : public Evento, public BilheteFilme
{
    protected:
public:
    Filme()
    {
        setNome_evento("Cinema");
        setData_evento("28/06/19");
        setHora_evento("21:00");
        setLocal_evento("CineBrasil");
        setValor(22.5);
        setCategoria_evento("Acao/Ficcao");
        setNum_bilhetes(50);
        setFilme("Vingadores");
        setAssento(10);
    }
};
class Voo : public Evento, public BilheteVoo
{
    protected:
public:
    Voo()
    {
        setNome_evento("Passagem Aerea");
        setData_evento("01/07/19");
        setHora_evento("5:00");
        setLocal_evento("Aeroporto de Confins");
        setValor(350);
        setCategoria_evento("Viagem");
        setNum_bilhetes(200);
        setNum_poltrona(14);
        setOrigem("Belo Horizonte");
        setDestino("Los Angeles");
        setCompanhia_aerea("AZUL");
    }
};

class Partida_futebol : public Evento, public BilheteFutebol
{
    protected:
public:
    Partida_futebol()
    {
        setNome_evento("Jogo de Futebol");
        setData_evento("30/07/19");
        setHora_evento("20:00");
        setLocal_evento("Mineirao");
        setValor(95);
        setCategoria_evento("Esporte");
        setNum_bilhetes(700);
        setTime1("Atletico Mineiro");
        setTime2("Cruzeiro");
        setNum_arquibancada(9);
    }
};

class Bilhete
{
    protected:
     int assento;
public:
    virtual string gerarBilhete()=0;
};

class BilheteFilme : public Bilhete
{
private:
    string filme;
    int assento;

public:
    void setFilme(string f) { filme = f; }
    void setAssento(int a) { assento = a; }

    imp_bilhete_filme()
    {
        cout << "Filme..................:" << filme << endl;
        cout << "Numero do Assento......:" << assento << endl;
    }
};

class BilheteCinema: public Bilhete, public Filme
{
protected:
    /* data */
public:
BilheteCinema(/* args */)
{
}
    BilheteCinema(/* args */);
    ~BilheteCinema();
};

class BilheteFutebol : public Bilhete, public Partida_futebol
{
private:
    string Time1;
    string Time2;
    int num_arquibancada;

public:
    void setTime1(string t1) { Time1 = t1; }
    void setTime2(string t2) { Time2 = t2; }
    void setNum_arquibancada(int num_arq) { num_arquibancada = num_arq; }

    imp_bilhete_futebol()
    {
        cout << "Time 1.................:" << Time1 << endl;
        cout << "Time 2.................:" << Time2 << endl;
        cout << "Numero da Arquibancada.:" << num_arquibancada << endl;
    }
};

class BilheteVoo : public Bilhete, public Voo
{
private:
    int num_poltrona;
    string origem;
    string destino;
    string companhia_aerea;

public:
    void setNum_poltrona(int np) { num_poltrona = np; }
    void setOrigem(string o) { origem = o; }
    void setDestino(string d) { destino = d; }
    void setCompanhia_aerea(string ca) { companhia_aerea = ca; }

    imp_bilhete_voo()
    {
        cout << "Numero da Poltrona.....:" << num_poltrona << endl;
        cout << "Origem.................:" << origem << endl;
        cout << "Destino................:" << destino << endl;
        cout << "Companhia Aerea........:" << companhia_aerea << endl;
    }
};

class Interface
{
    string nome;
    string cpf;
    string bandeira_cartao;
    string num_cartao;
    Usuario usuario;

public:
    Interface()
    {
        Usuario pessoa(nome, cpf, num_cartao, bandeira_cartao);
    }
    void void paginaInicial()
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
            cin >> opcao;
            cout << "---------------------------" << endl;
            enum
            {
                CINEMA,
                VOO,
                FUTEBOL,
                ONIBUS,
                TEATRO,
                FINALIZA
            };
            switch (opcao)
            {
            case CINEMA:
                pagina_cinema();
                break;
            case VOO:
                pagina_voo();
                break;
            case FUTEBOL:
                pagina_futebol();
                break;
            case ONIBUS:
                pagina_onibus();
                break;
            case TEATRO:
                pagina_teatro();
                break;
            case FINALIZA:
                pagina_finaliza();
                break;
            default:
                break;
            }
            //LIMPA_TELA();
        }
    }
    Usuario *leUsuario()
    {
        cout << "-----------Insira seus dados: ----------------" << endl;
        cout << "Nome:" << endl;
        cin >> nome;
        Usuario pessoa(nome, cpf);
    }
    void compra_bilhete()
    {
        cout << "Escolha a forma de Pagamento:" << endl;
        cout << "1. Debito." << endl;
        cout << "2. Credito." << endl;
        cout << "3. Dinheiro." << endl;
        cout << "4. Cancelar." << endl;

        unsigned int opcaoPagamento = 0;
        cin >> opcaoPagamento;
        enum
        {
            CANCELA,
            DEBITO,
            CREDITO,
            DINHEIRO,
            CORTESIA
        };
        switch (opcaoPagamento)
        {
        case DEBITO:
            break;
        case CREDITO:
            break;
        case DINHEIRO:
            break;
        case CORTESIA:
            break;
        default:
            break;
        }
    }

    void paginaEventoEscolhido(Evento *eventosEcolhido)
    {
        eventosEcolhido.imprimeEvento();
        eventosEcolhido.imprimeBilhete();
        compraBilhete(&pessoa);
    }

    void pagina_cinema()
    {

        Filme escolha_filme;
        escolha_filme.imprime_evento();
        //escolha_filme.imp_bilhete_filme();
        compraBilhete(&pessoa);
    }

    void pagina_voo()
    {
        Voo escolha_voo;
        escolha_voo.imprime_evento();
        //escolha_voo.imp_bilhete_voo();
        compra_bilhete();
    }

    void pagina_futebol()
    {
        Partida_futebol escolha_jogo;
        escolha_jogo.imprime_evento();
        //escolha_jogo.imp_bilhete_futebol();
        compra_bilhete();
    }

    void pagina_finaliza()
    {
        cout << "--------------------------------" << endl;
        cout << "Operacao Finalizada..." << endl;
        return 0;
    }

    int debito()
    {
        cout << "Pagamento em de'bito, insira os seguintes dados:" << endl;
        cout << "Bandeira do Cartao:" << endl;
        cin >> bandeira_cartao;
        cout << "Numero do Cartao:" << endl;
        cin >> num_cartao;
        if (debitoCont > 4)
            debitoCont = 0;
        //aceita 1 pedidos a cada 5 bilhetes
        if (debitoCont == 4 && usuario.saldo > evento.preco)
        {
            usuario.saldo -= evento.preco;
            cout << "Compra realizada com sucesso! " << endl;
        }
        else
            cout << "OPERACAO INVALIDA, CANCELANDO TRANSACAO " << endl;
        debitoCont++;
    }
    int credito()
    {
        cout << "Pagamento em de'bito, insira os seguintes dados:" << endl;
        cout << "Bandeira do Cartao:" << endl;
        cin >> bandeira_cartao;
        cout << "Numero do Cartao:" << endl;
        cin >> num_cartao;
        //sorteia pagamentos aprovados
        srand(time(NULL));
        int ok = 0 = rand() % 10;
        if (ok)
        {
            usuario.saldo -= evento.preco;
            cout << "Compra realizada com sucesso! " << endl;
        }
        else
        {
            cout << "OPERACAO INVALIDA, CANCELANDO TRANSACAO " << endl;
        }
    }
    int dinheiro()
    {
        cout << "Pagamento em dinheiro, insira os seguintes dados:" << endl;
        cout << "Valor do pagamento:" << endl;
        unsigned int valorPagamento;
        cin >> valorPagamento;
        cout << "Compra realizada com sucesso!  " << endl;
        cout << "O troco e' de R$" << valorPagamento - evento.getPreco() << endl;
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
        }
        else
        {
            cout << "Bilhete na'o aceito! " << endl;
        }
    }
};

int main()
{
    int opcao, i, x;
    Interface escolha;

    return 0;
}
