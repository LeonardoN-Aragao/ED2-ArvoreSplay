#ifndef NO_SPLAY_H
#define NO_SPLAY_H

class NoSplay
{
    private:
        int info;
        NoSplay * esq;
        NoSplay * dir;
        NoSplay * pai;

    public:
        NoSplay() {}
        ~NoSplay() {}

        int getInfo() { return info; }
        NoSplay* getEsq() { return esq; }
        NoSplay* getDir() { return dir; }
        NoSplay* getPai() { return pai; }

        void setInfo(int i) { info = i; }
        void setEsq(NoSplay* e) { esq = e; }
        void setDir(NoSplay* d) { dir = d; }
        void setPai(NoSplay* p) { pai = p; }
};

#endif