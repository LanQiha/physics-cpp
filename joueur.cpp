#include <Grapic.h>

using namespace grapic;

#include <cstdlib>
#include <ctime>

#include<ostream>

using namespace std;

struct complexe{
    float x;
    float y;
};

complexe makeComplexe (float x, float y){
complexe c;
c.x = x;
c.y = y;
return c;
}

complexe makeComplexeExp (float r, float ThetaRad){
return makeComplexe(r*cos(ThetaRad), r*sin(ThetaRad));
}

float toRadian (float degre){
return ((degre * M_PI) / 180);
}

complexe operator + (complexe a, complexe b){
return makeComplexe(a.x + b.x, a.y + b.y);
}

complexe operator - (complexe a, complexe b){
return makeComplexe(a.x - b.x, a.y - b.y);
}

complexe operator * (complexe a, float b){
return makeComplexe(b * a.x, b * a.y);
}

complexe operator * (float b, complexe a){
return makeComplexe(b * a.x, b * a.y);
}

complexe operator * (complexe a, complexe b){
return makeComplexe((a.x * b.x) - (a.y * b.y), (a.x * b.y) + (a.y * b.x));
}

struct Etoile
{
    complexe etoile;
    complexe satellite;
};

int const MAX = 30;

struct Galaxy
{
    complexe centre;
    Etoile tab[MAX];
    int nb;
};

int const DIMW = 500;
int const CARRE_ETOILE = 50;

void initGalaxy(Galaxy& gala)
{
    gala.centre = makeComplexe(DIMW/2, DIMW/2);
    gala.nb = rand()%MAX + 10;
    for(int i=0; i<gala.nb; i++)
    {
        gala.tab[i].etoile = makeComplexe(rand()%DIMW, rand()%DIMW);
        gala.tab[i].satellite = makeComplexe(gala.tab[i].etoile.x + rand()%CARRE_ETOILE/2, gala.tab[i].etoile.y + rand()%CARRE_ETOILE/2);

    }
}

void drawGalaxy(Galaxy& gala)
{
    for(int i=0; i<gala.nb; i++)
    {
        color(255, 0, 0);
        circleFill(gala.tab[i].etoile.x, gala.tab[i].etoile.y, 10);
        color(0, 0, 255);
        circle(gala.tab[i].satellite.x, gala.tab[i].satellite.y, 5);
    }
}

complexe Rotate(complexe a, complexe c, float angle)
{
    complexe rot;
    rot = makeComplexeExp(1, toRadian(angle));
    return (a-c)*rot + c;
}

void updateGalaxy(Galaxy& gala)
{
    complexe c = makeComplexe(DIMW/2, DIMW/2);
    complexe tr;

    for(int i=0; i<gala.nb; i++)
    {
        tr = gala.tab[i].satellite - gala.tab[i].etoile;
        gala.tab[i].etoile = Rotate(gala.tab[i].etoile, c, 0.01);
        gala.tab[i].satellite = gala.tab[i].etoile + tr;
        gala.tab[i].satellite = Rotate(gala.tab[i].satellite, gala.tab[i].etoile, 0.1);
    }
}

const int MAX_ELECTRONS = 10;
const int MAX_ATOMES = 20;
const int CARRE_ELECTRON = 40*3;
const int CARRE_ATOME = 100*3;

struct Atome
{
    complexe pos;
    int nbElectrons;
    complexe tab[MAX_ELECTRONS];
};

struct Molecule
{
    complexe pos;
    Atome tab[MAX_ATOMES];
    int nbAtomes;
};

void initMolecule(Molecule& mol)
{
    mol.pos = makeComplexe(DIMW/2, DIMW/2);
    mol.nbAtomes = rand()%MAX_ATOMES + 3;
    for(int i=0; i<mol.nbAtomes; i++)
    {
        mol.tab[i].pos = makeComplexe(mol.pos.x - CARRE_ATOME/2 + rand()%CARRE_ATOME, mol.pos.y - CARRE_ATOME/2 + rand()%CARRE_ATOME);
        mol.tab[i].nbElectrons = rand()%MAX_ELECTRONS;
        for(int j=0; j<mol.tab[i].nbElectrons; j++)
        {
            mol.tab[i].tab[j] = makeComplexe(mol.tab[i].pos.x - CARRE_ELECTRON/2 + rand()%CARRE_ELECTRON, mol.tab[i].pos.y - CARRE_ELECTRON/2 + rand()%CARRE_ELECTRON);
            cout << mol.nbAtomes << endl;
            cout << mol.tab[i].nbElectrons << endl;
        }
    }
}



void drawMolecule(Molecule& mol)
{
    color(0, 0, 0);
    circleFill(mol.pos.x, mol.pos.y, 10);
    for(int i=0; i<mol.nbAtomes; i++)
    {
        color(255, 0, 0);
        circleFill(mol.tab[i].pos.x, mol.tab[i].pos.y, 5);

        for(int j=0; j<mol.tab[i].nbElectrons; j++)
        {
            color(0, 0, 255);
            circle(mol.tab[i].tab[j].x, mol.tab[i].tab[j].y, 3);
        }
    }
}

void updateMolecule(Molecule& mol)
{
    complexe tr;

    for(int i=0; i<mol.nbAtomes; i++)
    {
        mol.tab[i].pos = Rotate(mol.tab[i].pos, mol.pos, toRadian(1));
        for(int j=0; j<mol.tab[i].nbElectrons; j++)
        {
            tr = mol.tab[i].tab[j] - mol.tab[i].pos;
            mol.tab[i].tab[j] = mol.tab[i].pos + tr;
            mol.tab[i].tab[j] = Rotate(mol.tab[i].tab[j], mol.tab[i].pos, toRadian(10));
        }
    }
}

void draw_polygon(int cx, int cy, int r, int n)
{
    color(255, 0, 0);
    complexe tab[n];
    complexe centre = makeComplexe(cx, cy);
    for(int i=0; i<n; i++)
    {
        tab[i] = centre + makeComplexeExp(r, toRadian(i*(360/n)));
    }
    for(int j = 0; j<n-1; j++)
    {
        line(tab[j].x, tab[j].y, tab[j+1].x, tab[j+1].y);
    }
    line(tab[0].x, tab[0].y, tab[n-1].x, tab[n-1].y);
}




int main(int , char**)
{
    bool stop=false;

	winInit("joueur",DIMW,DIMW);
	backgroundColor(300,300,300);

	//Galaxy gala;
	//initGalaxy(gala);

	//Molecule mol;
	//initMolecule(mol);

	while(!stop)
    {
	    winClear();

	    //drawGalaxy(gala);
	    //updateGalaxy(gala);

	    //drawMolecule(mol);
	    //updateMolecule(mol);

	    draw_polygon(DIMW/2, DIMW/2, 50, 7);

        stop = winDisplay();
	}

	winQuit();
	return 0;
}
