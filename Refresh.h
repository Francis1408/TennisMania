//FILE PARA DAR REFRESH EM VARIAVEIS QUE MUDAM CONSTANTEMENTE
#define PI 3.1415

int refreshCrowdAni(int x){
if(x==3){
    x=1;
    }
return x;
}

float refreshBallY(float j){
if(j < -5*(PI)/4){
    j=PI/4;

    }
return j;
}
float refreshBallX(float i){
if(i > PI){
    i=0;
}
return i;
}
