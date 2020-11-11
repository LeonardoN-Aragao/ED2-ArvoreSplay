#include <iostream>
#include "splay.h"

using namespace std;

void test1(ArvSplay *arv);
void test2(ArvSplay *arv);
void test3(ArvSplay *arv);
void test4(ArvSplay *arv);
void test5(ArvSplay *arv);
void test6(ArvSplay *arv);
void test7(ArvSplay *arv);
void test8(ArvSplay *arv);

int main()
{
    ArvSplay arv;
    
    // Comente esta linha (ou mude o argumento para false) para desativar as informações de debug
    // arv.imprimirInfoDebug(true);

    // test1(&arv);
    // test2(&arv);
    // test3(&arv);
    // test4(&arv);
    // test5(&arv);
    // test6(&arv);
    // test7(&arv);
    test8(&arv);
    
    cout << "Testes concluidos com sucesso!" << endl;
    return 0;
}

void test1(ArvSplay *arv)
{
    /*
    RESULTADO ESPERADO:
    10
    */

    arv->insere(10);

    arv->imprime();   
}

void test2(ArvSplay *arv)
{
    /*
    RESULTADO ESPERADO:
    20
            10
    */

    arv->insere(10);
    arv->insere(20);

    arv->imprime();   
}

void test3(ArvSplay *arv)
{
    /*
    RESULTADO ESPERADO:
            20
    15
            10
    */

    arv->insere(10);
    arv->insere(20);
    arv->insere(15);

    arv->imprime();   
}

void test4(ArvSplay *arv)
{
    /*
    RESULTADO ESPERADO:
    30
            20
                    15
                            10
    */

    arv->insere(10);
    arv->insere(20);
    arv->insere(15);
    arv->insere(30);

    arv->imprime();   
}

void test5(ArvSplay *arv)
{
    /*
    RESULTADO ESPERADO:
            40
                            30
                    20
                                    15
                            10
    9
    */

    arv->insere(10);
    arv->insere(20);
    arv->insere(15);
    arv->insere(30);
    arv->insere(40);
    arv->insere(9);

    arv->imprime();   
}

void test6(ArvSplay *arv)
{
    /*
    RESULTADO ESPERADO:
                                60
                                            50
                                    40
                                            30
                    25
            20
    10
    */

    arv->insere(10);
    arv->insere(20);
    arv->insere(30);
    arv->insere(40);
    arv->insere(50);
    arv->insere(60);
    arv->insere(25);

    arv->busca(10);

    arv->imprime();   
}

void test7(ArvSplay *arv)
{
    /*
    RESULTADO ESPERADO:
                    60
            55
                            50
                    40
    30
            20
                    10
    */

    arv->insere(60);
    arv->insere(50);
    arv->insere(40);
    arv->insere(30);
    arv->insere(20);
    arv->insere(10);
    arv->insere(55);

    arv->busca(30);

    arv->imprime();   
}

void test8(ArvSplay *arv)
{
    /*
    RESULTADO ESPERADO:
                    60
                            50
            40
    30
            25
                    20
                            10
    */

    arv->insere(10);
    arv->insere(20);
    arv->insere(30);
    arv->insere(40);

    arv->busca(30);
    arv->busca(30);
    arv->busca(40);
    arv->busca(30);

    arv->insere(50);
    arv->insere(60);
    arv->insere(25);

    arv->busca(30);
    arv->busca(30);
    arv->busca(25);
    arv->busca(40);
    arv->busca(30);

    arv->imprime();   
}