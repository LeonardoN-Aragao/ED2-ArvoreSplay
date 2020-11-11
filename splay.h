#ifndef SPLAY_H
#define SPLAY_H

#include "no.h"

class ArvSplay
{
    private:
        NoSplay *raiz;          // nó raiz da árvore
        bool debug;             // indica se o modo debug está ativado

        // Desaloca a subárvore de raiz em p
        NoSplay* libera(NoSplay* p);

        // Retorna um ponteiro para o nó onde se encontra o valor val. O pai do nó encontrado é armazenado no ponteiro "pai",
        // que é retornado por referência. Se val está na raiz, o ponteiro "pai" fica com NULL. Caso val não seja encontrado, 
        // é retornado NULL (e o pai também fica NULL).
        NoSplay* encontraNo(int val, NoSplay **pai);

        // Imprime a subárvore de raiz em p. Os nós são impressos por nível, da direita para a esquerda, de forma que a árvore
        // é exibida no console como se estivesse deitada, com a raiz na margem esquerda. Você também pode usar essa função
        // nos seus testes para imprimir alguma subárvore que desejar (lembre-se que essa função é privada).
        void auxImprime(NoSplay *p, int k);

        // Realiza uma rotação simples para a esquerda. O nó p é rotacionado sobre o seu pai. Você deve implementar esta função
        // Dica: você pode utilizar a função auxImprime(), passando o nó p utilizado como parâmetro para a rotação, para imprimir 
        // a subárvore de raiz em p e se certificar de que a rotação foi realizada com sucesso (observe que essa impressão não 
        // mostrará o pai de p, então certifique-se de verificar se o pai também foi ajustado corretamente).
        void zigEsq(NoSplay *p);

        // Realiza uma rotação simples para a direita. O nó p é rotacionado sobre o seu pai. Você deve implementar esta função.
        // Dica: você pode utilizar a função auxImprime(), passando o nó p utilizado como parâmetro para a rotação, para imprimir 
        // a subárvore de raiz em p e se certificar de que a rotação foi realizada com sucesso (observe que essa impressão não 
        // mostrará o pai de p, então certifique-se de verificar se o pai também foi ajustado corretamente).
        void zigDir(NoSplay *p);

    public:
        // Construtor, cria uma árvore vazia e a inicializa com o modo debug desativado
        ArvSplay();

        // Destrutor, desaloca todos os nós da árvore
        ~ArvSplay();

        // Busca um valor val na árvore e faz splay do mesmo, caso ele seja encontrado. Não está sendo feito splay do nó mais próximo
        // quando o valor não é encontrado (você não precisa se preocupar com isso para esta atividade)
        bool busca(int val);

        // Insere um novo nó na árvore com o valor val e faz splay do mesmo.
        void insere(int val);

        // Imprime a árvore completa
        void imprime();

        // Ativa o modo de debug, para imprimir algumas informações que podem ser úteis durante a depuração do seu código.
        void imprimirInfoDebug(bool d);

        // Imprime informações relativas ao nó p, como o seu valor, o valor do pai (se existir) e o valor do avô (se existir).
        void imprimeFamilia(NoSplay *p);

        // Realiza o splay do nó p, ou seja, leva o nó p para a raiz. Você deve implementar esta função.
        void splay(NoSplay *p);
};

#endif