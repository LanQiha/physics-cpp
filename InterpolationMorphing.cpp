#define __STDC_LIMIT_MACROS
#include <stdint.h>

#include<Grapic.h>

using namespace grapic;

using namespace std;

struct Point{
float x, y;
};

struct Polygon{
int n;
Point p[89];
};

void initPoly1(Polygon& p)
{
	p.n=90;
	p.p[0]={457.888489,250.000000};
	p.p[1]={461.038269,273.794373};
	p.p[2]={462.098755,297.708679};
	p.p[3]={458.933167,320.202209};
	p.p[4]={445.752594,337.187347};
	p.p[5]={429.762878,349.331512};
	p.p[6]={411.802368,356.302551};
	p.p[7]={398.585785,362.648682};
	p.p[8]={396.368134,375.219177};
	p.p[9]={391.321472,384.060120};
	p.p[10]={388.516205,388.516205};
	p.p[11]={388.516205,388.516205};
	p.p[12]={388.516205,388.516205};
	p.p[13]={386.561371,390.614868};
	p.p[14]={378.687439,396.368134};
	p.p[15]={369.273224,402.356812};
	p.p[16]={357.174652,407.008606};
	p.p[17]={343.207825,410.993347};
	p.p[18]={337.078552,434.325165};
	p.p[19]={323.334625,451.729309};
	p.p[20]={303.090027,459.983093};
	p.p[21]={280.028595,463.164581};
	p.p[22]={256.515411,480.964722};
	p.p[23]={230.559830,479.809906};
	p.p[24]={206.946777,468.574554};
	p.p[25]={187.165695,453.761810};
	p.p[26]={168.946243,443.799957};
	p.p[27]={159.159210,422.696960};
	p.p[28]={149.399277,409.387451};
	p.p[29]={136.601776,404.665222};
	p.p[30]={126.444084,398.585785};
	p.p[31]={118.512169,392.031616};
	p.p[32]={112.315010,387.134521};
	p.p[33]={112.315010,387.134521};
	p.p[34]={112.315010,387.134521};
	p.p[35]={112.315010,386.233093};
	p.p[36]={105.961411,379.492981};
	p.p[37]={102.305794,368.760590};
	p.p[38]={101.563614,354.673645};
	p.p[39]={88.360321,347.426270};
	p.p[40]={73.982582,337.533051};
	p.p[41]={57.362782,325.009033};
	p.p[42]={46.442875,306.898834};
	p.p[43]={38.114288,285.654480};
	p.p[44]={40.227848,261.785858};
	p.p[45]={35.979435,237.975494};
	p.p[46]={24.978146,212.135147};
	p.p[47]={16.942471,184.855316};
	p.p[48]={21.568779,161.053650};
	p.p[49]={35.979435,143.568405};
	p.p[50]={55.421864,132.720673};
	p.p[51]={71.315697,123.996590};
	p.p[52]={84.257988,116.727325};
	p.p[53]={94.713890,110.395462};
	p.p[54]={104.510147,106.044449};
	p.p[55]={105.961411,105.961411};
	p.p[56]={105.961411,105.961411};
	p.p[57]={105.961411,105.961411};
	p.p[58]={113.132362,101.563614};
	p.p[59]={122.671585,96.262871};
	p.p[60]={133.723770,90.772820};
	p.p[61]={145.806732,84.257988};
	p.p[62]={159.613388,77.476616};
	p.p[63]={167.718201,52.473759};
	p.p[64]={182.934860,31.644978};
	p.p[65]={205.185303,21.568779};
	p.p[66]={230.753815,21.568779};
	p.p[67]={256.418060,21.568779};
	p.p[68]={282.050446,21.568779};
	p.p[69]={306.664673,24.978146};
	p.p[70]={325.573639,41.276711};
	p.p[71]={332.407166,74.862671};
	p.p[72]={347.021393,81.746788};
	p.p[73]={359.894684,88.360321};
	p.p[74]={371.080444,94.713890};
	p.p[75]={380.637207,100.817703};
	p.p[76]={389.327057,105.961411};
	p.p[77]={392.745331,106.681602};
	p.p[78]={392.745331,106.681602};
	p.p[79]={392.745331,106.681602};
	p.p[80]={397.842865,109.753845};
	p.p[81]={409.387451,113.642807};
	p.p[82]={421.833466,119.726715};
	p.p[83]={436.182343,127.680069};
	p.p[84]={453.761810,137.407501};
	p.p[85]={473.001221,150.676193};
	p.p[86]={482.125336,172.005219};
	p.p[87]={479.809906,198.307449};
	p.p[88]={469.672913,225.232193};
	p.p[89]={457.888489,250.000076};
}

void initPoly2(Polygon& p)
{
	p.n=90;
	p.p[0]={483.291779,250.000000};
	p.p[1]={467.481689,274.520813};
	p.p[2]={452.743011,295.604248};
	p.p[3]={443.799957,315.117432};
	p.p[4]={445.752594,337.187347};
	p.p[5]={438.058197,353.915192};
	p.p[6]={435.251434,371.708374};
	p.p[7]={434.325165,389.744019};
	p.p[8]={427.079926,401.493408};
	p.p[9]={418.422516,409.768616};
	p.p[10]={418.422516,418.422516};
	p.p[11]={418.422516,418.422516};
	p.p[12]={418.422516,418.422516};
	p.p[13]={418.561493,423.564789};
	p.p[14]={418.690094,441.866821};
	p.p[15]={407.924713,451.729309};
	p.p[16]={400.703156,470.776794};
	p.p[17]={389.888367,491.622803};
	p.p[18]={355.879211,474.121826};
	p.p[19]={325.195770,456.849060};
	p.p[20]={300.494476,449.717072};
	p.p[21]={274.327942,422.696960};
	p.p[22]={255.045731,428.864075};
	p.p[23]={235.894913,416.742523};
	p.p[24]={220.139999,401.595032};
	p.p[25]={202.305801,404.665222};
	p.p[26]={186.914902,400.837067};
	p.p[27]={176.034897,390.614868};
	p.p[28]={165.162857,384.412323};
	p.p[29]={149.957840,386.448853};
	p.p[30]={140.996475,381.085480};
	p.p[31]={132.241226,377.201752};
	p.p[32]={127.921143,371.590851};
	p.p[33]={127.921143,371.590851};
	p.p[34]={127.921143,371.590851};
	p.p[35]={127.307678,371.398590};
	p.p[36]={125.448730,361.973633};
	p.p[37]={125.448730,350.151520};
	p.p[38]={126.691132,336.954376};
	p.p[39]={127.921143,323.581573};
	p.p[40]={121.645920,313.830353};
	p.p[41]={113.688416,303.077087};
	p.p[42]={109.526543,289.265564};
	p.p[43]={102.305794,274.852997};
	p.p[44]={96.262871,258.637695};
	p.p[45]={92.361107,241.143265};
	p.p[46]={84.257988,222.110321};
	p.p[47]={79.197540,202.257004};
	p.p[48]={74.862671,181.805176};
	p.p[49]={71.315697,161.141022};
	p.p[50]={68.608406,140.668716};
	p.p[51]={66.780792,120.798691};
	p.p[52]={63.070141,99.690208};
	p.p[53]={9.826738,34.080612};
	p.p[54]={9.826738,12.359534};
	p.p[55]={9.826738,9.826738};
	p.p[56]={9.826738,9.826738};
	p.p[57]={9.826738,9.826738};
	p.p[58]={24.060183,4.962625};
	p.p[59]={56.006775,15.771327};
	p.p[60]={93.710724,35.979435};
	p.p[61]={116.798576,38.114288};
	p.p[62]={139.546097,39.173717};
	p.p[63]={159.041718,31.644978};
	p.p[64]={178.419144,16.942471};
	p.p[65]={209.460175,43.358727};
	p.p[66]={232.763412,45.419975};
	p.p[67]={255.719254,46.442875};
	p.p[68]={278.134216,49.480988};
	p.p[69]={299.740814,52.473759};
	p.p[70]={319.400543,58.325970};
	p.p[71]={337.955933,63.070141};
	p.p[72]={353.554077,70.417786};
	p.p[73]={369.071381,74.862671};
	p.p[74]={381.850342,80.901291};
	p.p[75]={393.690552,85.911270};
	p.p[76]={403.248688,91.568954};
	p.p[77]={406.223572,93.149300};
	p.p[78]={406.223572,93.149300};
	p.p[79]={406.223572,93.149300};
	p.p[80]={410.993347,97.279068};
	p.p[81]={420.974304,103.730118};
	p.p[82]={432.486511,111.650223};
	p.p[83]={447.724884,120.096672};
	p.p[84]={462.098755,132.800735};
	p.p[85]={474.121826,150.177078};
	p.p[86]={484.464111,171.219376};
	p.p[87]={492.836975,195.377167};
	p.p[88]={494.057251,222.482849};
	p.p[89]={483.291779,250.000076};
}

Point makePoint (float x, float y){
Point p;
p.x = x;
p.y = y;
return p;
}

Point operator + (Point a, Point b){
Point c;
c.x = a.x + b.x;
c.y = a.y + b.y;
return c;
}

Point operator - (Point a, Point b){
Point c;
c.x = a.x - b.x;
c.y = a.y - b.y;
return c;
}

Point operator * (Point a, float lambda){
return makePoint(lambda*a.x, lambda*a.y);
}

Point operator * (float lambda, Point a){
return makePoint(lambda*a.x, lambda*a.y);
}

Point operator * (Point a, Point b){
return makePoint(a.x*b.x - a.y*b.y, a.x*b.y + a.y*b.x);
}

void drawPolygon(Polygon& p){
color(200, 200, 200);
for (int i=0; i<88; i++){
line(p.p[i].x, p.p[i].y, p.p[i+1].x, p.p[i+1].y);
}
line(p.p[88].x, p.p[88].y, p.p[0].x, p.p[0].y);
}

Point interpolation_point(Point a, Point b, float t){ // t est un nombre compris entre 0 et 1
return (1-t)*a + t*b;
}

Polygon interpolation_polygon(Polygon a, Polygon b, float t){
Polygon c;
for (int i = 0; i<89; i++){
c.p[i] = interpolation_point(a.p[i], b.p[i], t);
}
return c;
}

int main(int , char**)
{
    bool stop=false;
    winInit("InterpolationMorphing",500,500);
	backgroundColor(120,70,200);
    Polygon a;
    Polygon b;
    Polygon c;
    float t;
    initPoly1(a);
    initPoly2(b);

	while(!stop){
	winClear();

    t = abs(sin(elapsedTime()));
    c = interpolation_polygon(a, b, t);
    drawPolygon(c);

    stop = winDisplay();

    if(isKeyPressed(SDLK_SPACE)){
    winQuit();
    }
    }
	return 0;
}