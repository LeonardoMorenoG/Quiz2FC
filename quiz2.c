#include <stdlib.h>
#include <stdio.h>
#include <math.h>
float integrarFuncion(float limInferior, float limSuperior, float deltaH);

int main(int argc, char **argv){
  float a=0;
  float b=0;
  float h=0;



  a = atof(argv[1]);
  b = atof(argv[2]);
  h = atof(argv[3]);

    
  float integral= integrarFuncion(a,b,h);
  fprintf(stderr, "%f\n", integral);
  return 0;
}

float integrarFuncion(float limInferior, float limSuperior, float deltaH){
  float deltaX= limSuperior-limInferior;
  int numDeltasH= deltaX/deltaH;
  float deltaH1= deltaX-(numDeltasH*deltaH);
  int i=1;
  float areaTotal = 0;
  float areaRectangulo = 0;
//y fprintf(stderr, "%f, %f, %f \n", a,b,h);
  for(i=1;i<=numDeltasH;i++){
    areaRectangulo = deltaH*(1/sqrt(1+cos(limInferior+deltaH*i)*sin(limInferior+deltaH*i)));
    areaTotal += areaRectangulo;
  }
  areaTotal += deltaH1*(1/sqrt(1+cos(limSuperior)*sin(limSuperior)));
  return areaTotal;
}
