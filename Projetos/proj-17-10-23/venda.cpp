#include "venda.hpp"

// Setter para o código
void ItemVenda::set_codigo(int novo_codigo) {
    this->codigo = novo_codigo;
}

// Setter para o nome
void ItemVenda::set_nome(const std::string &novo_nome) {
    this->nome = novo_nome;
}

// Setter para o preço
void ItemVenda::set_preco(double novo_preco) {
    this->preco = novo_preco;
}

// Setter para a quantidade (qtde)
void ItemVenda::set_qtde(int nova_quantidade) {
    this->qtde = nova_quantidade;
}

// Setter para o valor do item
void ItemVenda::calcula_valor() {
    this->valor_item = this->qtde * this->preco;
}

// Getter para o código
int ItemVenda::get_codigo() const{
    return this->codigo;
}

// Getter para o nome
const string& ItemVenda::get_nome() const {
    return nome;
}

// Getter para o preço
double ItemVenda::get_preco() const {
    return preco;
}

// Getter para a quantidade (qtde)
int ItemVenda::get_qtde() const {
    return qtde;
}

// Getter para o valor do item
double ItemVenda::get_valor() const {
    return valor_item;
}

// Setter para o código da venda
void Venda::set_codigo(int novo_codigo)
{
    this->codigo = novo_codigo;
}

// Insere um item na lista de itens da venda
void Venda::insere_item(ItemVenda *item_venda)
{
    this->itens_venda.push_back(item_venda);
}

// Calcula o valor total da venda
void Venda::calcula_valor()
{
    double valor = 0.0;
    for (ItemVenda* item : this->itens_venda){
        valor += item->get_valor();
    }
    valor_venda = valor;
}

int Venda::get_codigo() const
{
    return this->codigo;
}

double Venda::get_valor() const
{
    return this->valor_venda;
}

void Vendas::insere_venda(Venda *nova_venda)
{
    this->vendas.push_back(nova_venda);
}

vector<Venda *> Vendas::obter_vendas()
{
    return this->vendas;
}
