// apps/Cherazade/ComplexeOiseau

#include<Grapic.h>

using namespace grapic;

#include <iostream>
#include <math.h>

using namespace std;

/* ------------------------------ */



/* ------------------------------ */

const float DIMW = 500;

/* ------------------------------ */



/* ------------------------------ */

struct complexe{
float x, y;
};

struct bird{
float a = 0;
complexe c;
};

/* ------------------------------ */



/* ------------------------------ */

complexe makeComplexe (float x, float y){
complexe c;
c.x = x;
c.y = y;
return c;
}

complexe makeComplexeExp (float r, float thetaRad){
complexe c;
c.x = r*cos(thetaRad);
c.y = r*sin(thetaRad);
return c;
}

complexe operator + (complexe a, complexe b){
complexe c;
c = makeComplexe (a.x + b.x, a.y + b.y);
return c;
}

complexe operator - (complexe a, complexe b){
complexe c;
c.x = a.x - b.x;
c.y = a.y - b.y;
return c;
}

complexe operator * (float lambda, complexe a){
complexe c;
c.x = lambda*a.x;
c.y = lambda*a.y;
return c;
}

complexe operator * (complexe a, float lambda){
return makeComplexe(lambda*a.x, lambda*a.y);
}

complexe operator * (complexe a, complexe b){
complexe c;
c.x = a.x * b.x - a.y * b.y;
c.y = a.x * b.y + a.y * b.x;
return c;
}

complexe Rotate (complexe a, float cx, float cy, float angleRad){
complexe c, b, rot;
c = makeComplexe(cx, cy);
rot = makeComplexeExp(1, angleRad);
b = (a-c) * rot + c;
return b;
}

/* ------------------------------ */



/* ------------------------------ */

void init(bird &bi){
bi.c.x = DIMW/2;
bi.c.y = DIMW/2;
}

void draw (bird &bi){
    color (50, 50, 50);
    circleFill(bi.c.x, bi.c.y, 10);
    color (50, 50, 50);
    line(bi.c.x - 50, bi.c.y - bi.a, bi.c.x, bi.c.y);
    color (50, 50, 50);
    line(bi.c.x + 50, bi.c.y - bi.a, bi.c.x, bi.c.y);
}

void update (bird &bi)
{
            bi.a = 20*cos(elapsedTime()*5);
            complexe t;
            t = Rotate(bi.c, bi.c.x, bi.c.y, bi.a);
            color (50, 50, 50);
            line(bi.c.x - 50, bi.c.y - t.y, bi.c.x, bi.c.y);
            color (50, 50, 50);
            line(bi.c.x + 50, bi.c.y - t.y, bi.c.x, bi.c.y);
}

void updateUp(bird &bi){
    if(isKeyPressed(SDLK_UP)){
            bi.c.y = bi.c.y + 30;
            bi.a = 20*cos(elapsedTime()*10);
            complexe t;
            t = Rotate(bi.c, bi.c.x, bi.c.y, bi.a);
            color (50, 50, 50);
            line(bi.c.x - 50, bi.c.y - t.y, bi.c.x, bi.c.y);
            color (50, 50, 50);
            line(bi.c.x + 50, bi.c.y - t.y, bi.c.x, bi.c.y);
    }else {(bi.c.y = bi.c.y - 0.1);};
}

void updateDown(bird &bi){
    if(isKeyPressed(SDLK_DOWN)){
            bi.c.y = bi.c.y - 30;
            bi.a = 20*cos(elapsedTime()*10);
            complexe t;
            t = Rotate(bi.c, bi.c.x, bi.c.y, bi.a);
            color (50, 50, 50);
            line(bi.c.x - 50, bi.c.y - t.y, bi.c.x, bi.c.y);
            color (50, 50, 50);
            line(bi.c.x + 50, bi.c.y - t.y, bi.c.x, bi.c.y);
    }else {(bi.c.y = bi.c.y - 0.1);};
}

void updateRight (bird &bi)
{
    if (isKeyPressed(SDLK_RIGHT))
    {
        bi.c.x = bi.c.x + 30;
        bi.a = 20*cos(elapsedTime()*10);
        complexe t;
        t = Rotate(bi.c, bi.c.x, bi.c.y, bi.a);
        color (50, 50, 50);
        line(bi.c.x - 50, bi.c.y - t.y, bi.c.x, bi.c.y);
        color (50, 50, 50);
        line(bi.c.x + 50, bi.c.y - t.y, bi.c.x, bi.c.y);
    }
}

void updateLeft (bird &bi)
{
     if (isKeyPressed(SDLK_LEFT))
     {
         bi.c.x = bi.c.x - 30;
         bi.a = 20*cos(elapsedTime()*10);
         complexe t;
         t = Rotate(bi.c, bi.c.x, bi.c.y, bi.a);
         color (50, 50, 50);
         line(bi.c.x - 50, bi.c.y - t.y, bi.c.x, bi.c.y);
         color (50, 50, 50);
         line(bi.c.x + 50, bi.c.y - t.y, bi.c.x, bi.c.y);

     }
}

/*void update(Bird& b)
{
    const float d = 0.1f;
    if (b.c.y > 3) b.c.y-=d;            // fait tomber l'oiseau à chaque fois

    if (isKeyPressed(SDLK_LEFT))   if (b.c.x > 0) b.c.x-=d;
    if (isKeyPressed(SDLK_RIGHT))  if (b.c.x < DIMW) b.c.x+=d;
    if (isKeyPressed(SDLK_UP))
    {
        b.c.y += 2.f*d;                 // fait remonter l'oiseau si KEY_UP
        float t = elapsedTime();
        b.angle = 20.f*cos(50.f*t);     // modifie l'angle des ailes, oscille entre -20 et +20 ° (le 50*t sert à accélérer le mouvement)
    }
    else b.angle = 15.f;
}*/


int main(int , char**)
{
    bool stop=false;
	winInit("Birds",DIMW,DIMW);
	backgroundColor(100,50,200);
	bird bird;
	init(bird);
	while(!stop){
        winClear();
        draw(bird);
        updateUp(bird);
        updateRight(bird);
        updateLeft(bird);
        updateDown(bird);
    stop = winDisplay();
	}
	pressSpace();
	winQuit();
	return 0;
}
