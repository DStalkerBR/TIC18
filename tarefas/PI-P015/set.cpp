#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Set {
    vector<string> items;

    // Adiciona um item ao conjunto.
    int putItem(string item);

    // Verifica se um item existe no conjunto.
    bool existItem(string item) const;

    // Remove um item do conjunto.
    int delItem(string item);

    // Exibe todos os itens no conjunto.
    void showItems(void) const;

    // Realiza a união de dois conjuntos.
    Set unionSet(const Set& outroSet);

    // Realiza a interseção de dois conjuntos.
    Set intersectionSet(const Set& outroSet);

    // Calcula a diferença entre dois conjuntos.
    Set differenceSet(const Set& outroSet);

    // Esvazia o conjunto.
    void emptySet(void);

    // Verifica se o conjunto está vazio.
    bool isEmptySet(void);

    // Verifica se dois conjuntos são iguais.
    bool isIqual(const Set& outroSet) const;

    // Calcula o produto cartesiano de dois conjuntos.
    Set cartesianProduct(const Set& outroSet);

    // Calcula a diferença simétrica entre dois conjuntos.
    Set symetricDifference(const Set& outroSet);
};

int main(int argc, char const* argv[]) {
    Set set1, set2;
    set1.putItem("Joao");
    set1.putItem("Jose");
    set1.putItem("Ana");
    set2.putItem("Jose");
    set2.putItem("Paulo");
    set2.putItem("Ana");

    cout << "Set 1: ";
    set1.showItems();
    cout << "Set 2: ";
    set2.showItems();

    // Realiza a união de Set 1 e Set 2.
    Set resultUniao = set1.unionSet(set2);
    cout << "Uniao de Set 1 e Set 2: ";
    resultUniao.showItems();

    // Realiza a interseção de Set 1 e Set 2.
    Set resultIntersecao = set1.intersectionSet(set2);
    cout << "Intersecao de Set 1 e Set 2: ";
    resultIntersecao.showItems();

    // Calcula a diferença de Set 1 e Set 2.
    Set resultDiferenca = set1.differenceSet(set2);
    cout << "Diferenca de Set 1 e Set 2: ";
    resultDiferenca.showItems();

    // Calcula o produto cartesiano de Set 1 e Set 2.
    Set resultCartesiano = set1.cartesianProduct(set2);
    cout << "Produto Cartesiano de Set 1 e Set 2: ";
    resultCartesiano.showItems();

    // Calcula a diferença simétrica de Set 1 e Set 2.
    Set resultDiferSim = set1.symetricDifference(set2);
    cout << "Diferenca Simetrica de Set 1 e Set 2: ";
    resultDiferSim.showItems();

    return 0;
}


/**
 * Adiciona um item ao conjunto, desde que o item não exista no conjunto.
 *
 * @param item O item a ser adicionado ao conjunto.
 * @return 1 se o item foi adicionado com sucesso, 0 se o item já existia no conjunto.
 */
int Set::putItem(string item) {
    if (!existItem(item)) {
        items.push_back(item);
        return 1;
    }
    return 0;
}

/**
 * Verifica se um item existe no conjunto.
 *
 * @param item O item a ser verificado.
 * @return `true` se o item existe no conjunto, `false` caso contrário.
 */
bool Set::existItem(string item) const {
    return find(this->items.begin(), this->items.end(), item) != this->items.end();
}

/**
 * Remove um item do conjunto, se o item existir no conjunto.
 *
 * @param item O item a ser removido do conjunto.
 * @return 1 se o item foi removido com sucesso, 0 se o item não existia no conjunto.
 */
int Set::delItem(string item) {
    auto it = find(this->items.begin(), this->items.end(), item);
    if (it != this->items.end()) {
        items.erase(it);
        return 1;
    }
    return 0;
}


/**
 * Exibe todos os itens no conjunto.
 */
void Set::showItems(void) const {
    cout << "{ ";
    for (size_t i = 0; i < items.size() - 1; i++) {
        cout << items.at(i) << ", ";
    }
    cout << items.back() << " }" << endl;
}


/**
 * Realiza a união de dois conjuntos.
 *
 * @param outroSet O conjunto a ser unido com o conjunto atual.
 * @return Um novo conjunto contendo a união dos elementos dos dois conjuntos.
 */
Set Set::unionSet(const Set& outroSet) {
    Set unionSet;
    for (const string& item : this->items) {
        unionSet.putItem(item);
    }
    for (const string& item : outroSet.items) {
        unionSet.putItem(item);
    }
    return unionSet;
}


/**
 * Realiza a interseção de dois conjuntos.
 *
 * @param outroSet O conjunto com o qual a interseção será calculada.
 * @return Um novo conjunto contendo os elementos comuns aos dois conjuntos.
 */
Set Set::intersectionSet(const Set& outroSet) {
    Set intersectionSet;
    for (const string& item : this->items) {
        if (outroSet.existItem(item)) {
            intersectionSet.putItem(item);
        }
    }
    return intersectionSet;
}


/**
 * Calcula a diferença entre dois conjuntos.
 *
 * @param outroSet O conjunto com o qual a diferença será calculada.
 * @return Um novo conjunto contendo os elementos que estão no conjunto atual, mas não no conjunto especificado.
 */
Set Set::differenceSet(const Set& outroSet) {
    Set differenceSet;
    for (const string& item : this->items) {
        if (!outroSet.existItem(item)) {
            differenceSet.putItem(item);
        }
    }
    return differenceSet;
}


/**
 * Esvazia o conjunto, removendo todos os itens.
 */
void Set::emptySet(void) {
    this->items.clear();
}


/**
 * Verifica se o conjunto está vazio.
 *
 * @return `true` se o conjunto estiver vazio, `false` caso contrário.
 */
bool Set::isEmptySet(void) {
    return this->items.empty();
}


/**
 * Verifica se dois conjuntos são iguais.
 *
 * @param outroSet O conjunto a ser comparado com o conjunto atual.
 * @return `true` se os conjuntos forem iguais, ou seja, possuírem os mesmos elementos na mesma ordem, `false` caso contrário.
 */
bool Set::isIqual(const Set& outroSet) const {
    return this->items == outroSet.items;
}


/**
 * Calcula o produto cartesiano de dois conjuntos.
 *
 * @param outroSet O conjunto com o qual o produto cartesiano será calculado.
 * @return Um novo conjunto contendo os pares de elementos de ambos os conjuntos no formato "item1 x item2".
 */
Set Set::cartesianProduct(const Set& outroSet) {
    Set cartesianProduct;
    for (const string& item1 : this->items) {
        for (const string& item2 : outroSet.items) {
            cartesianProduct.putItem(item1 + " x " + item2);
        }
    }
    return cartesianProduct;
}


/**
 * Calcula a diferença simétrica entre dois conjuntos.
 *
 * @param outroSet O conjunto com o qual a diferença simétrica será calculada.
 * @return Um novo conjunto que contém os elementos que estão presentes em apenas um dos conjuntos, excluindo os elementos que são comuns a ambos os conjuntos.
 */
Set Set::symetricDifference(const Set& outroSet) {
    Set symetricDifference;
    for (const string& item : this->items) {
        if (!outroSet.existItem(item)) {
            symetricDifference.putItem(item);
        }
    }
    for (const string& item : outroSet.items) {
        if (!this->existItem(item)) {
            symetricDifference.putItem(item);
        }
    }
    return symetricDifference;
}
