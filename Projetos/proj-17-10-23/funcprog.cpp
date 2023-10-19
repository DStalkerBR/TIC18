#include "funcprog.hpp"
#include "menu.hpp"

void incluir_produto(Produtos* produtos){
    int codigo;
    string nome;
    double preco;
    Produto *produto = new Produto;

    limpa_tela();
    cout << string(20, '_') << endl;
    cout << "Inclusao de Produtos" << endl;
    cout << string(20, '_') << endl;
    cout << "Codigo do Produto: ";
    cin >> codigo;
    cout << "Nome do Produto: ";
    cin >> nome;
    cout << "Preco do Produto: ";
    cin >> preco;
    cout << string(20, '_') << endl;
    produto->set_codigo(codigo);
    produto->set_nome(nome);
    produto->set_preco(preco);
    produtos->insere_produto(produto);
}

void listar_produtos (Produtos produtos){
    limpa_tela();
    cout << "===================================" << endl;
    cout << "      Lista de Produtos      " << endl;
    cout << "===================================" << endl;
    cout << "Codigo\t\tNome\t\tPreco" << endl;
    cout << "-----------------------------------" << endl;

    for (auto prod : produtos.obtem_lista_produtos()) {
        cout << prod->get_codigo() << "\t\t";
        cout << prod->get_nome() << "\t\t";
        cout << "$" << prod->get_preco() << endl;
    }

    cout << "===================================" << endl;
    cout << "Pressione Enter para continuar..." << endl;
    cin.ignore();
    cin.get();
}

void realizar_venda(Vendas* vendas)
{
    int codigo;
    int cod_item = 0;
    Produtos produtos;
    Produto produto;
    cout << "===================================" << endl;
    cout << "Inicio da Venda" << endl;
    cout << "===================================" << endl;
    cout << "Digite o código da venda: ";
    cin >> codigo;

    while (cod_item != -1){
        cout << "Codigo do Item: ";
        cin >> cod_item;
        if (cod_item != -1){
            // prod = produtos.obter_produto(cod_item);
        }
    }

}
