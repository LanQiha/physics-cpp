#include <Grapic.h>

#include <cmath>

#include <iostream>

using namespace grapic;

using namespace std;

const int DIMW = 500;

const int MAX = 50;

struct Vecteur
{
    int x, y;
};

struct Color
{
    unsigned char r, v, b;
};

struct Insects
{
    Vecteur v;
    Color c;
    float naissance;
    float dureeDeVie;
};

struct Population
{
    Insects tabInsects[MAX];
    int nbInsects;
    Image bg;
};

Vecteur makeVecteur (float x, float y){
Vecteur v;
v.x = x;
v.y = y;
return v;
}

Vecteur operator + (Vecteur a, Vecteur b){
return makeVecteur(a.x + b.x, a.y + b.y);
}

Vecteur operator - (Vecteur a, Vecteur b){
return makeVecteur(a.x - b.x, a.y - b.y);
}

Vecteur operator * (Vecteur a, float lambda){
return makeVecteur(lambda*a.x, lambda*a.y);
}

Vecteur operator * (float lambda, Vecteur a){
return makeVecteur(lambda*a.x, lambda*a.y);
}

Vecteur operator * (Vecteur a, Vecteur b){
return makeVecteur(a.x*b.x - a.y*b.y, a.y*b.x + a.x*b.y);
}

Vecteur operator / (Vecteur a, float lambda){
return makeVecteur(a.x/lambda, a.y/lambda);
}

Vecteur operator / (float lambda, Vecteur a){
return makeVecteur(a.x/lambda, a.y/lambda);
}

int distance(Vecteur A, Vecteur B)
{
return (int)(sqrt((A.x - B.x)*(A.x - B.x)+(A.y - B.y)*(A.y - B.y)));
}

Color makeColor(unsigned char r, unsigned char v, unsigned char b){
Color c;
c.r = r;
c.v = v;
c.b = b;
return c;
}

Color operator + (Color col1, Color col2){
return makeColor(col1.r + col2.r, col1.v + col2.v, col1.b + col2.b);
}

Color operator - (Color col1, Color col2){
return makeColor(col1.r - col2.r, col1.v - col2.v, col1.b - col2.b);
}

Color operator * (float lambda, Color col){
return makeColor(lambda*col.r, lambda*col.v, lambda*col.b);
}

Color operator * (Color col, float lambda){
return makeColor(lambda*col.r, lambda*col.v, lambda*col.b);
}

void initInsect(Population &pop, Color good, int range)
{
    int i;
    for(i=0; i<pop.nbInsects; i++)
    {
        pop.tabInsects[i].v = makeVecteur(rand()%DIMW, rand()%DIMW);
        pop.tabInsects[i].c = makeColor(rand()%(good.r + range) + good.r - range,
                                        rand()%(good.v + range) + good.v - range,
                                        rand()%(good.b + range) + good.b - range);
        pop.tabInsects[i].naissance = elapsedTime();
        pop.tabInsects[i].dureeDeVie = -1;
    }
}

void init(Population& pop)
{
    Color good;
    good = makeColor(127, 127, 127);
    pop.nbInsects = 30;
    initInsect(pop, good, 127);
    // pop.bg = image("apps/Cherazade/ble.png");
}

void draw(Population& pop)
{
    // image_draw(pop.bg, 0, 0, DIMW, DIMW);
    int i;
    int nbv = 0;
    for(i=0; i<pop.nbInsects; i++)
    {
        if(pop.tabInsects[i].dureeDeVie<0)
        {
            color(pop.tabInsects[i].c.r, pop.tabInsects[i].c.v, pop.tabInsects[i].c.b);
            circleFill(pop.tabInsects[i].v.x, pop.tabInsects[i].v.y, 3);
            nbv++;
        }
    }

    int x, y;
    color(255, 0, 0);
    circle(x, y, 20);
    mousePos(x, y);

    color(255, 0, 0);
    print(DIMW-30, DIMW-30, nbv);
}

void minMaxMoy(Population& pop, float &mini, float &maxi, float &moy)
{
    int i;
    mini=maxi=moy= -1; //pop.tabInsects[i].dureeDeVie;
    for(i=0; i<pop.nbInsects; i++)
    {
        moy+=pop.tabInsects[i].dureeDeVie;
        if(mini>pop.tabInsects[i].dureeDeVie)
        {
            mini=pop.tabInsects[i].dureeDeVie;
        }
        else
            {
                if(maxi<pop.tabInsects[i].dureeDeVie)
                {
                    maxi=pop.tabInsects[i].dureeDeVie;
                }
            }
    }
    moy=moy/pop.nbInsects;
}

Color averageColorOfGoodInsect(Population pop, float seuil)
{
    Color c;
    int r, v, b, i, nb=0;
    r=v=b=0;
    for(i=0; i<pop.nbInsects; i++)
    {
        if(pop.tabInsects[i].dureeDeVie>seuil)
        {
            nb++;
            r=r+pop.tabInsects[i].c.r;
            v=v+pop.tabInsects[i].c.v;
            b=b+pop.tabInsects[i].c.b;
        }

    }
    c.r=r/nb;
    c.v=v/nb;
    c.b=b/nb;
    return c;
}

void update(Population& pop)
{
    int x, y;
    float d;

    mousePos(x, y);
    Vecteur mouse_pos = makeVecteur(x, y);

    int i;
    int nbv = 0;
    for(i=0; i<pop.nbInsects; i++)
    {
        d=distance(mouse_pos, pop.tabInsects[i].v);
        if(d<20)
        {
            pop.tabInsects[i].dureeDeVie = elapsedTime() - pop.tabInsects[i].naissance;
        }
        if(pop.tabInsects[i].dureeDeVie<0)
        {
            nbv++;
        }
    }

    if(nbv == 0)
    {
         float mini, maxi, moy; Color c;
         minMaxMoy(pop, mini, maxi, moy);
         c=averageColorOfGoodInsect(pop, moy);
         initInsect(pop, c, moy);
    }
}

int main(int , char** )
{
	winInit("Insects", 500, 500);

	Population pop;
	Color good = makeColor(127, 127, 127);
	int range = 10;

	initInsect(pop, good, range);
	init(pop);

    /*while(1)
    {
        winClear();
        update(pop);
        draw(pop);

        winDisplay();
        if(isKeyPressed(SDLK_SPACE))
        {
            winQuit();
        }
    }*/
	return 0;
}
