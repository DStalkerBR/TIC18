#ifndef VENDA_HPP
#define VENDA_HPP

#include <vector>
#include <string>

using namespace std;

class ItemVenda {
    private:
        int codigo;
        string nome;
        double preco;
        int qtde;
        double valor_item;

    public:
        void set_codigo(int novo_codigo);
        void set_nome(const string& novo_nome);
        void set_preco(double novo_preco);
        void set_qtde(int nova_quantidade);
        void calcula_valor();

        int get_codigo() const;
        const string& get_nome() const;
        double get_preco() const;
        int get_qtde() const;
        double get_valor() const;
};


class Venda{
    private:
        int codigo;
        vector<ItemVenda*> itens_venda;
        double valor_venda;
    public:
        void set_codigo(int novo_codigo);
        void insere_item(ItemVenda* item_venda);
        void calcula_valor();

        int get_codigo() const;
        double get_valor() const;
};


class Vendas{
    private:
        vector<Venda *> vendas;

    public:
        void insere_venda (Venda* nova_venda);
        vector<Venda *> obter_vendas ();

};

#endif