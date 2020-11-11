#include <iostream>
#include <cstdlib>
#include "splay.h"

ArvSplay::ArvSplay()
{
    raiz = NULL;
    debug = false;
}

ArvSplay::~ArvSplay()
{
    raiz = libera(raiz);
    std::cout << "Arvore desalocada!" << std::endl;
}

NoSplay* ArvSplay::libera(NoSplay *p)
{
    if(p != NULL)
    {
        p->setEsq( libera(p->getEsq()) );
        p->setDir( libera(p->getDir()) );
        delete p;
    }
    return NULL;
}

NoSplay* ArvSplay::encontraNo(int val, NoSplay **pai = NULL)
{   
    NoSplay *p = raiz;
    if(pai != NULL) 
        *pai = NULL;

    while(p != NULL && p->getInfo() != val)
    {
        if(pai != NULL) 
            *pai = p;

        if(val < p->getInfo())
            p = p->getEsq();
        else
            p = p->getDir();
    }

    return p;
}

bool ArvSplay::busca(int val)
{
    NoSplay *p = encontraNo(val);

    if(p == NULL)
        return false;
    else
    {
        splay(p);
        return true;
    }
}

void ArvSplay::insere(int val)
{
    NoSplay *pai;
    NoSplay *p = encontraNo(val, &pai);

    if(p != NULL)
        std::cout << "Valor já inserido!" << std::endl;
    else
    {
        NoSplay *novo = new NoSplay();
        novo->setInfo(val);
        novo->setEsq(NULL);
        novo->setDir(NULL);
        novo->setPai(pai);

        if(pai == NULL)
            raiz = novo;
        else if(val < pai->getInfo())
            pai->setEsq( novo );
        else
            pai->setDir( novo );
        
        splay(novo);
    }
}

void ArvSplay::imprime()
{
    std::cout << std::endl << std::endl;
    std::cout << "******************** ARVORE **************************" << std::endl << std::endl;
    auxImprime(raiz, 0);
    std::cout << std::endl << std::endl;
    std::cout << "******************************************************";
    std::cout << std::endl << std::endl;
}

void ArvSplay::auxImprime(NoSplay* p, int k)
{
    if(p != NULL)
    {
        auxImprime(p->getDir(), k+1);
        for(int i = 0; i < k; i++)
            std::cout << '\t';
        std::cout << p->getInfo() << std::endl;
        auxImprime(p->getEsq(), k+1);
    }
}

void ArvSplay::imprimirInfoDebug(bool d)
{
    debug = d;
}

void ArvSplay::imprimeFamilia(NoSplay *p)
{
    std::cout << "********************" << std::endl; 
    std::cout << "NO\tPAI\tAVO" << std::endl; 
    if(p != NULL)
    {
        std::cout << p->getInfo() << "\t";
        NoSplay *pai = p->getPai();
        if(pai != NULL)
        {
            std::cout << pai->getInfo() << "\t";
            NoSplay *avo = pai->getPai();
            if(avo != NULL)
                std::cout << avo->getInfo() << "\t";
            else
                std::cout << "NULL";
        }
        else
            std::cout << "NULL\tNULL";                
    }
    else
        std::cout << "NULL\tNULL\tNULL";
    std::cout << std::endl << std::endl;
    std::cout << "********************" << std::endl; 
}

/* 
    Aplicar zig esquerdo/direito (se o pai for raiz), zig-zag esquerdo/direito
    (se a sequência avô-pai-filho tiver alternância de direção) 
    ou zig-zig esquerdo/direito (se a sequência avô-pai-filho seguir em uma 
    mesma direção). Lembre-se de atualizar a conexão do nó p com o 
    seu novo pai após a rotação (tanto o ponteiro pai de p quanto o filho 
    esquerdo/direito do seu novo pai, que deve apontar para p). 
    O novo pai será o antigo bisavô (ou nulo, caso o antigo avô fosse a raiz).
*/

void ArvSplay::splay(NoSplay *p)
{
    if(debug) 
        imprimeFamilia(p);

    while(p != raiz)
    {
        //********* IMPLEMENTE SUA SOLUÇÃO AQUI! ***********//
        
        NoSplay * pai = p->getPai();
        NoSplay * avo = NULL;
        if(pai != raiz)
            avo = pai->getPai();
        
        // Caso 1
        if(pai == raiz){
            if(p == pai->getEsq())
                zigDir(p);
            else
                zigEsq(p);
        }

        // Caso 2 e 3
        else if(p == pai->getEsq()){
            if(pai == avo->getEsq()){
                zigDir(pai);
                zigDir(p);
            }
            else{
                zigDir(p);
                zigEsq(p);
            }
        }
        else{
            if(pai == avo->getDir()){
                zigEsq(pai);
                zigEsq(p);
            }
            else{
                zigEsq(p);
                zigDir(p);
            }
        }

        if(debug)
        {
            imprime();
            int op;
            std::cout << "Imprimir proxima iteracao? Sim (1) ou Nao (0)? ";
            std::cin >> op;
            if(op == 0)
            {
                std::cout << "Interrompendo programa!" << std::endl;
                libera(raiz);
                exit(1);
            }
        }
    }
}

void ArvSplay::zigEsq(NoSplay *p)
{ //********* IMPLEMENTE SUA SOLUÇÃO AQUI! ***********//
    NoSplay * pai = p->getPai();

    if(p->getEsq() != NULL){ //troca o pai do filho a esq se existir
        p->getEsq()->setPai(pai);
    }

    p->setPai(pai->getPai());

    if(pai->getPai() == NULL) //Atualiza a raiz e o novo pai do no p
        raiz = p;
    else{
        if (p->getInfo() < p->getPai()->getInfo())
			p->getPai()->setEsq(p);
		else
			p->getPai()->setDir(p);
    }	

    pai->setDir(p->getEsq());
    p->setEsq(pai);
    pai->setPai(p);
}

void ArvSplay::zigDir(NoSplay *p)
{
    //********* IMPLEMENTE SUA SOLUÇÃO AQUI! ***********//
    NoSplay * pai = p->getPai();

    if(p->getDir() != NULL){ //troca o pai do filho a dir se existir
        p->getDir()->setPai(pai);
    }

    p->setPai(pai->getPai());

    if(pai->getPai() == NULL) //Atualiza a raiz e o novo pai do no p
        raiz = p;
    else{
        if (p->getInfo() < p->getPai()->getInfo())
			p->getPai()->setEsq(p);
		else
			p->getPai()->setDir(p);
    }	

    pai->setEsq(p->getDir());
    p->setDir(pai);
    pai->setPai(p);
}