#include <iostream>
#include <vector>
 
using namespace std;
 
/*
    1. Crie uma classe abstrata chamada ObjetoGeometrico que contenha os métodos virtuais 
    puros area() e perimetro().
    2. Crie as classes concretas Circulo, Quadrado e Retangulo que herdem da classe 
    ObjetoGeometrico.
    3. Crie uma classe chamada Calculadora que contenha um método c
    hamado calcular() que receba um ObjetoGeometrico e imprima a área e o perímetro do objeto.
    4. Crie um programa que instancie um objeto de cada tipo e 
    passe para o método calcular() da classe Calculadora.
*/
 
 
class ObjGeometrico
{
    public:
        virtual double getArea();
        virtual double getPerimetro();
};
 
/*
     __A__
     |   /
   C |  /B
     | /
     |/
*/
 
class Triangulo : public ObjGeometrico
{
    private:
        double ladoA;
        double ladoB;
        double ladoC;
        double altura;
    public:
        Triangulo(double ladoA, double ladoB, double ladoC, double altura);
        bool eTriangulo(double a, double b, double c);
        double getArea();
        double getPerimetro();
        double getLadoA();
        double getLadoB();
        double getLadoC();
        double getAltura();
        void setLadoA(double ladoA);
        void setLadoB(double ladoB);
        void setLadoC(double ladoC);
        void setAltura(double altura);
};
 
 
class Retangulo: public ObjGeometrico
{
    private:
        double ladoA;
        double ladoB;
    public:
        Retangulo(double ladoA, double ladoB);
        double getArea();
        double getPerimetro();
        double getLadoA();
        double getLadoB();
        void setLadoA(double ladoA);
        void setLadoB(double ladoB);
};
 
class Quadrado: public ObjGeometrico
{
    private:
        double lado;

    public:
        Quadrado(double lado);
        double getArea();
        double getPerimetro();
        double getLado();
        void setLado(double lado);
};
 
 class Circulo: public ObjGeometrico 
 {
    private:
        double raio;
        double pi;
    public:
        Circulo(double raio);
        double getArea();
        double getPerimetro();
        double getRaio();

        void setRaio(double raio);
 };
 
class Calculadora {
    public:
        static void calcular(ObjGeometrico *obj);
};

 
double claculArea(vector<ObjGeometrico*> listaObjetos);
 
int main()
{
    Triangulo triangulo(3,4,5,2);  
    Quadrado quadrado(5);  
    Retangulo retangulo(6,9);  
    Circulo circulo(3.5);

    vector<ObjGeometrico*> listaObjetos;
    // listaObjetos.push_back(&obj);
    listaObjetos.push_back(&triangulo);
    listaObjetos.push_back(&quadrado);
    listaObjetos.push_back(&retangulo);
    listaObjetos.push_back(&circulo);

    for (auto objeto : listaObjetos){
        Calculadora::calcular(objeto);
    }

    double area = claculArea(listaObjetos);
    cout << "Area total: " << area << endl;
    return 0;
}
 
 
double claculArea(vector<ObjGeometrico*> listaObjetos){
    double area = 0;
    for (ObjGeometrico* obj : listaObjetos)
    {
        area += obj->getArea();
    }
    
    return area;
}
 
double ObjGeometrico::getArea()
{
    return 0;
}
 
double ObjGeometrico::getPerimetro()
{
    return 0;
}
 
//Triangulo(double ladoA, double ladoB, double ladoC, double altura)
Triangulo::Triangulo(double a, double b, double c, double h)
{
    if(!eTriangulo(a,b,c))
    {
        std::cout << "Nao eh um triangulo" << std::endl;
        return;
    }
    ladoA = a;
    ladoB = b;
    ladoC = c;
    altura = h;
}
 
bool Triangulo::eTriangulo(double a, double b, double c)
{
    if ((a+b > c) && (a+c > b) && (b+c > a))
    {
        return true;
    }
    else
    {
        return false;
    }
}
 
double Triangulo::getArea()
{
    return (ladoC * altura) / 2;
}
 
 
double Triangulo::getPerimetro()
{
    return ladoA + ladoB + ladoC;
}
 
double Triangulo::getLadoA()
{
    return ladoA;
}
 
double Triangulo::getLadoB()
{
    return ladoB;
}
        
double Triangulo::getLadoC()
{
    return ladoC;
}
double getAltura();
void setLadoA(double ladoA);
void setLadoB(double ladoB);
void setLadoC(double ladoC);
void setAltura(double altura);

Retangulo::Retangulo(double a, double b)
{
    ladoA = a;
    ladoB = b;
}

double Retangulo::getArea()
{
    return ladoA * ladoB;
}

double Retangulo::getPerimetro()
{
    return 2 * (ladoA + ladoB);
}

double Retangulo::getLadoA()
{
    return ladoA;
}

double Retangulo::getLadoB()
{
    return ladoB;
}

void Retangulo::setLadoA(double a)
{
    ladoA = a;
}

void Retangulo::setLadoB(double b)
{
    ladoB = b;
}

Quadrado::Quadrado(double l)
{
    lado = l;
}

double Quadrado::getArea()
{
    return lado * lado;
}

double Quadrado::getPerimetro()
{
    return 4 * lado ;
}

double Quadrado::getLado()
{
    return lado;
}
void Quadrado::setLado(double l)
{
    lado = l;
}

void Calculadora::calcular(ObjGeometrico *obj)
{
    cout << "________________________________" << endl;
    cout << "Area: " << obj->getArea() << endl;
    cout << "Perimetro: " << obj->getPerimetro() << endl;
    cout << "________________________________" << endl;
}

Circulo::Circulo(double raio)
{
    this->raio = raio;
    this->pi = 3.1415;
}

double Circulo::getArea()
{
    return pi * raio * raio;
}

double Circulo::getPerimetro()
{
    return 2 * pi * raio; 
}

double Circulo::getRaio()
{
    return this->raio;
}

void Circulo::setRaio(double raio)
{
    this->raio = raio;
}
