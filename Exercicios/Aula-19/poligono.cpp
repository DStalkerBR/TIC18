#include<iostream>
#include<vector>
#include<cmath>
#include<string>

class Ponto {
    private:
    float x;
    float y;

    public:
    Ponto(float x=0, float y=0){
        this->x = x;
        this->y = y;
    }

    void setX(float x){
        this->x = x;
    }

    void setY(float y){
        this->y = y;
    }

    void setPonto(float x,float y){
        this->x = x;
        this->y = y;
    }   

    float getX(){
        return x;
    }

    float getY(){
        return y;
    }

    void operator=(std::string dados);


    float getDistancia(Ponto ponto2){
        float distancia;
        distancia = std::sqrt(std::pow(this->x - ponto2.getX(), 2)+ std::pow(this->y - ponto2.getY(), 2));
        return distancia;
    }

};

class Poligono {
    private:
    std::vector<Ponto> pontos;

    public:
    void addPonto(Ponto ponto){
        this->pontos.push_back(ponto);
    }

    std::vector<Ponto> getPontos(){
        return pontos;
    }

    float getPerimetro(){
        float perimetro = 0.0;
        for(int i=0; i<pontos.size()-1; i++){
            perimetro += pontos.at(i).getDistancia(pontos.at(i+1));
        }
        perimetro += pontos.at(pontos.size()-1).getDistancia(pontos.at(0));
        return perimetro;
    }

};

int main(){
    Poligono poligono;
    Ponto ponto;
    float x, y;
    std::cout << "Criando poligono" << std::endl;
    char decisao;
    ponto = "(2,1)";
    std::cout << "(" << ponto.getX() << ", " << ponto.getY() << ")" << std::endl;
    /*
    poligono.addPonto(ponto);
    ponto.setPonto(0, 4);
    poligono.addPonto(ponto);
    ponto.setPonto(-2, 0);
    poligono.addPonto(ponto);
    ponto.setPonto(-2, -1);
    poligono.addPonto(ponto);   
    ponto.setPonto(2, -4); 
    poligono.addPonto(ponto);
    
    do{
        std::cout << "Digite as coordenadas do ponto" << std::endl;
        std::cin >> x >> y;
        ponto.setPonto(x, y);
        poligono.addPonto(ponto);
        std::cout << "Deseja inserir mais pontos" << std::endl;
        std::cin >> decisao;

    }while(decisao != 'n');
    for (Ponto p:poligono.getPontos()){
        std::cout << "(" << p.getX() << ", " << p.getY() << ")" << std::endl;
    }
    std::cout << "Perimetro do poligono: " << poligono.getPerimetro();*/

}

 void Ponto::operator=(std::string dados){
        this->x = dados[1] - '0';
        this->y = dados[3] - '0';
}