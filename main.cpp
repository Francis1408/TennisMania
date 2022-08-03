#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include "Sprite1.h"
#include "Texture.h"
#include "Gamemode.h"
#include "Refresh.h"
#include "Board.h"
#define WIDTH   300.0
#define HEIGHT  300.0
#define PI 3.1415

struct sprite player1;
struct sprite player2;
struct sprite ball;
float i=0,j=PI/4;
int keyB[256]={0};
enum game{Play,Menu,Pause,Selection,Exit,Restart,P1Win,P2Win,HowtoPlay} ;
int gamemode = Menu;
float x = 0;
int mkey = 1;
float skey = 0, aux;
int selecStep = 0;
int P1Character =0;
int P2Character =0;
int King =0;
int p1hit, p2hit =0;
float uP1=0,uP2=0,dP1=0,dP2=0;
float p1movUp, p1movDown,p1status, p2movUp, p2movDown,p2status = 0;
float P1set, P2set;
GLuint idPlayer1;GLuint idBoard; GLuint idCourt; GLuint idBall; GLuint idBush; GLuint idCrowd; GLuint idPause;
GLuint idExit; GLuint idReset; GLuint idLogo; GLuint idWallpaper; GLuint idSelect; GLuint idStart;
GLuint idHow2Play; GLuint nameSheet; GLuint idSelection; GLuint Crown; GLuint idp1Win; GLuint idp2Win; GLuint options;
GLuint idp1; GLuint idp2; GLuint matchpoint; GLuint locker;
GLuint acozp1; GLuint acozp1hit;GLuint acozp2;GLuint acozp2hit;GLuint acozup;GLuint acozdown;GLuint acozvictory;GLuint acozdefeat;GLuint acozicon;
GLuint acozpoints;
GLuint bobp1; GLuint bobp1hit;GLuint bobp2;GLuint bobp2hit;GLuint bobup;GLuint bobdown;GLuint bobvictory;
GLuint bobdefeat;GLuint bobicon;GLuint bobpoints;
GLuint sammyp1; GLuint sammyp1hit;GLuint sammyp2;GLuint sammyp2hit;GLuint sammyup;GLuint sammydown;GLuint sammyvictory;
GLuint sammydefeat;GLuint sammyicon;GLuint sammypoints;
GLuint harryp1; GLuint harryp1hit;GLuint harryp2;GLuint harryp2hit;GLuint harryup;GLuint harrydown;GLuint harryvictory;
GLuint harrydefeat;GLuint harryicon;GLuint harrypoints;
GLuint pamp1; GLuint pamp1hit;GLuint pamp2;GLuint pamp2hit;GLuint pamup;GLuint pamdown;GLuint pamvictory;
GLuint pamdefeat;GLuint pamicon;GLuint pampoints;
GLuint brianp1; GLuint brianp1hit;GLuint brianp2;GLuint brianp2hit;GLuint brianup;GLuint briandown;GLuint brianvictory;
GLuint briandefeat;GLuint brianicon;GLuint brianpoints; //TOTAS AS VARIAVEIS DO JOGO


void resetGame(){
 uP1=0,uP2=0,dP1=0,dP2=0,P1set=0,P2set=0;skey = 0;
 selecStep = 0;
 P1Character =0;
 P2Character = 0;   // REINICIA TODAS AS VARIAVEIS DO JOGO
}

void uptadeP1(int timer){
    p1hit = 0;
    if(p1movUp<1)
        p1movUp++;
    else
        p1movUp=0;

    if(p1movDown<1)
        p1movDown++;
    else
        p1movDown=0;     //ATUALIZIA AS VARIAVEIS DO P1

    if(p1status<2)
        p1status++;
    else
        p1status=0;


glutTimerFunc(500,uptadeP1,0);
}
void uptadeP2(int timer){
   p2hit = 0;
   if(p2movUp<1)
        p2movUp++;
    else
        p2movUp=0;           //ATUALIZA AS VARIAVEIS DO P2

    if(p2movDown<1)
        p2movDown++;
    else
        p2movDown=0;

    if(p2status<2)
        p2status++;
    else
        p2status=0;

glutTimerFunc(500,uptadeP2,0);
}

int king(int King){
    if((dP1*10.0)+(uP1)>(dP2*10.0)+(uP2))
        King = 1;

    else if((dP1*10.0)+(uP1)<(dP2*10.0)+(uP2))
        King = 2;
                                              //ANALISA QUEM E O REIZINHO
    else
        King=0;

return King;
}
void p1Win(){
    if(P1set == 3.0){
    gamemode = P1Win;
    } //ANALISA SE P P1 GANHOU A PARTIDA
}

void p2Win(){
    if(P2set == 3.0){
    gamemode = P2Win;
    } //ANALISA SE O P2 GANHOU A PARTIDA
}
void scoreReset(){
uP1=0,uP2=0,dP1=0,dP2=0;

}
void p1Game(){
    if((dP1*10.0)+(uP1)== 12.0){
        P1set++;
        p1Win();           //ANALISA SE O P1 GANHOU O SET
        scoreReset();
    }
}
void p2Game(){
    if((dP2*10.0)+(uP2)== 12.0){  //ANALISA SE O P2 GANHOU O SET
        P2set++;
        p2Win();
        scoreReset();
    }
}

void p1Score(){
    if(uP1<9){
        uP1++;
    }
    else{        //POUNTUACAO DO P1
        uP1=0;
        dP1++;
    }
}
void p2Score(){
    if(uP2<9){
        uP2++;
    }              //PONTUACAO DO P2
    else{
        uP2=0;
        dP2++;
    }
}
void resetball(){
   ball.centerx = WIDTH/2;
   ball.centery = HEIGHT/2;  //RESETA A POSICAO DA BOLA
}
void resetP1(){
   player1.centerx = WIDTH*0.1;
   player1.centery = HEIGHT/2;
}
void resetP2(){
   player2.centerx = WIDTH*0.9;
   player2.centery = HEIGHT/2;
}
void uptadeAni(int time){
    if(x<1)
        x++;
    else
        x=0;
glutTimerFunc(1000,uptadeAni,0);
}
int boundaryUP(sprite player){
    if(player.centery + (player.height/2)>=HEIGHT*0.75)
        return 0;
    else
        return 1;
}
int boundaryDOWN(sprite player){
    if(player.centery - (player.height/2)<=HEIGHT*0.25)  //ANALISA SE OS JOGADORES NAO PASSARAM OS LIMITES DO CENARIO
        return 0;
    else
        return 1;
}
void moveup(){
    if(keyB[119] == 1 && boundaryUP(player1))
        player1.centery += HEIGHT/50;

    if(keyB[111] == 1 && boundaryUP(player2))  //VELOCIDADE DOS PLAYERS PRA CIMA
        player2.centery += HEIGHT/50;
}
void movedown(){
    if(keyB[115] == 1 && boundaryDOWN(player1))
        player1.centery -= HEIGHT/50;           //VELOCIDADE DOS PLAYERS PARA BAIXO

    if(keyB[108] == 1 && boundaryDOWN(player2))
        player2.centery -= HEIGHT/50;
}
void drawPlayer1(){  //DESENHA TODAS AS ANIMACOES POSSIVEIS DO P1
    if(p1hit == 1 && gamemode == Play){
    glColor3f(1.0, 1.0, 1.0);
    glBindTexture(GL_TEXTURE_2D,player1.hit);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(player1.centerx - (player1.height/2),player1.centery - (player1.width/2), 0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(player1.centerx + (player1.height/2),player1.centery - (player1.width/2), 0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(player1.centerx - (player1.height/2),player1.centery + (player1.width/2), 0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(player1.centerx + (player1.height/2),player1.centery + (player1.width/2), 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
    else if(keyB[119]==1 && gamemode==Play){
    glColor3f(1.0, 1.0, 1.0);
    glBindTexture(GL_TEXTURE_2D,player1.up);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f((p1movUp/2.0),0.0);
        glVertex3f(player1.centerx - (player1.height/2),player1.centery - (player1.width/2), 0.0);
        glTexCoord2f((p1movUp/2.0)+(1.0/2.0),0.0);
        glVertex3f(player1.centerx + (player1.height/2),player1.centery - (player1.width/2), 0.0);
        glTexCoord2f((p1movUp/2.0),1.0);
        glVertex3f(player1.centerx - (player1.height/2),player1.centery + (player1.width/2), 0.0);
        glTexCoord2f((p1movUp/2.0)+(1.0/2.0),1.0);
        glVertex3f(player1.centerx + (player1.height/2),player1.centery + (player1.width/2), 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
    else if(keyB[115]==1 && gamemode == Play){
    glColor3f(1.0, 1.0, 1.0);
    glBindTexture(GL_TEXTURE_2D,player1.down);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f((p1movDown/2.0),0.0);
        glVertex3f(player1.centerx - (player1.height/2),player1.centery - (player1.width/2), 0.0);
        glTexCoord2f((p1movDown/2.0)+(1.0/2.0),0.0);
        glVertex3f(player1.centerx + (player1.height/2),player1.centery - (player1.width/2), 0.0);
        glTexCoord2f((p1movDown/2.0),1.0);
        glVertex3f(player1.centerx - (player1.height/2),player1.centery + (player1.width/2), 0.0);
        glTexCoord2f((p1movDown/2.0)+(1.0/2.0),1.0);
        glVertex3f(player1.centerx + (player1.height/2),player1.centery + (player1.width/2), 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
    else if(gamemode == P2Win){
    glColor3f(1.0, 1.0, 1.0);
    glBindTexture(GL_TEXTURE_2D,player1.defeat);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f((p1movDown/3.0),0.0);
        glVertex3f(player1.centerx - (player1.height/2),player1.centery - (player1.width/2), 0.0);
        glTexCoord2f((p1movDown/3.0)+(1.0/3.0),0.0);
        glVertex3f(player1.centerx + (player1.height/2),player1.centery - (player1.width/2), 0.0);
        glTexCoord2f((p1movDown/3.0),1.0);
        glVertex3f(player1.centerx - (player1.height/2),player1.centery + (player1.width/2), 0.0);
        glTexCoord2f((p1movDown/3.0)+(1.0/3.0),1.0);
        glVertex3f(player1.centerx + (player1.height/2),player1.centery + (player1.width/2), 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
    else if(gamemode == P1Win){
    glColor3f(1.0, 1.0, 1.0);
    glBindTexture(GL_TEXTURE_2D,player1.victory);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f((p1status/3.0),0.0);
        glVertex3f(player1.centerx - (player1.height/2),player1.centery - (player1.width/2), 0.0);
        glTexCoord2f((p1status/3.0)+(1.0/3.0),0.0);
        glVertex3f(player1.centerx + (player1.height/2),player1.centery - (player1.width/2), 0.0);
        glTexCoord2f((p1status/3.0),1.0);
        glVertex3f(player1.centerx - (player1.height/2),player1.centery + (player1.width/2), 0.0);
        glTexCoord2f((p1status/3.0)+(1.0/3.0),1.0);
        glVertex3f(player1.centerx + (player1.height/2),player1.centery + (player1.width/2), 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
   else{
    glColor3f(1.0, 1.0, 1.0);
    glBindTexture(GL_TEXTURE_2D,player1.stop);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(player1.centerx - (player1.height/2),player1.centery - (player1.width/2), 0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(player1.centerx + (player1.height/2),player1.centery - (player1.width/2), 0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(player1.centerx - (player1.height/2),player1.centery + (player1.width/2), 0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(player1.centerx + (player1.height/2),player1.centery + (player1.width/2), 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
        }
}

void drawPlayer2(){ //DESENHA TODAS AS ANIMACOES POSSIVEIS DO P2
    if(p2hit==1 && gamemode == Play){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, player2.hit);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(player2.centerx - (player2.height/2),player2.centery - (player2.width/2), 0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(player2.centerx + (player2.height/2),player2.centery - (player2.width/2), 0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(player2.centerx - (player2.height/2),player2.centery + (player2.width/2), 0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(player2.centerx + (player2.height/2),player2.centery + (player2.width/2), 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
    else if(keyB[111]==1 && gamemode == Play){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, player2.up);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f((p2movUp/2.0),0.0);
        glVertex3f(player2.centerx - (player2.height/2),player2.centery - (player2.width/2), 0.0);
        glTexCoord2f((p2movUp/2.0)+(1.0/2.0),0.0);
        glVertex3f(player2.centerx + (player2.height/2),player2.centery - (player2.width/2), 0.0);
        glTexCoord2f((p2movUp/2.0),1.0);
        glVertex3f(player2.centerx - (player2.height/2),player2.centery + (player2.width/2), 0.0);
        glTexCoord2f((p2movUp/2.0)+(1.0/2.0),1.0);
        glVertex3f(player2.centerx + (player2.height/2),player2.centery + (player2.width/2), 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
    else if(keyB[108]==1&&gamemode == Play){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, player2.down);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f((p2movDown/2.0),0.0);
        glVertex3f(player2.centerx - (player2.height/2),player2.centery - (player2.width/2), 0.0);
        glTexCoord2f((p2movDown/2.0)+(1.0/2.0),0.0);
        glVertex3f(player2.centerx + (player2.height/2),player2.centery - (player2.width/2), 0.0);
        glTexCoord2f((p2movDown/2.0),1.0);
        glVertex3f(player2.centerx - (player2.height/2),player2.centery + (player2.width/2), 0.0);
        glTexCoord2f((p2movDown/2.0)+(1.0/2.0),1.0);
        glVertex3f(player2.centerx + (player2.height/2),player2.centery + (player2.width/2), 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
    else if(gamemode == P2Win){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, player2.victory);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f((p2status/3.0),0.0);
        glVertex3f(player2.centerx - (player2.height/2),player2.centery - (player2.width/2), 0.0);
        glTexCoord2f((p2status/3.0)+(1.0/3.0),0.0);
        glVertex3f(player2.centerx + (player2.height/2),player2.centery - (player2.width/2), 0.0);
        glTexCoord2f((p2status/3.0),1.0);
        glVertex3f(player2.centerx - (player2.height/2),player2.centery + (player2.width/2), 0.0);
        glTexCoord2f((p2status/3.0)+(1.0/3.0),1.0);
        glVertex3f(player2.centerx + (player2.height/2),player2.centery + (player2.width/2), 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
    else if(gamemode == P1Win){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, player2.defeat);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f((p2status/3.0),0.0);
        glVertex3f(player2.centerx - (player2.height/2),player2.centery - (player2.width/2), 0.0);
        glTexCoord2f((p2status/3.0)+(1.0/3.0),0.0);
        glVertex3f(player2.centerx + (player2.height/2),player2.centery - (player2.width/2), 0.0);
        glTexCoord2f((p2status/3.0),1.0);
        glVertex3f(player2.centerx - (player2.height/2),player2.centery + (player2.width/2), 0.0);
        glTexCoord2f((p2status/3.0)+(1.0/3.0),1.0);
        glVertex3f(player2.centerx + (player2.height/2),player2.centery + (player2.width/2), 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }

    else{
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, player2.stop);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(player2.centerx - (player2.height/2),player2.centery - (player2.width/2), 0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(player2.centerx + (player2.height/2),player2.centery - (player2.width/2), 0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(player2.centerx - (player2.height/2),player2.centery + (player2.width/2), 0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(player2.centerx + (player2.height/2),player2.centery + (player2.width/2), 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
}
void drawBall(){ //DESENHA A BOLA
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idBall);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(ball.centerx - (ball.height/2),ball.centery - (ball.width/2), 0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(ball.centerx + (ball.height/2),ball.centery - (ball.width/2), 0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(ball.centerx - (ball.height/2),ball.centery + (ball.width/2), 0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(ball.centerx + (ball.height/2),ball.centery + (ball.width/2), 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
void drawScenario(){   //DESENHA O CENARIO DO JOGO
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idBush);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(WIDTH*0,HEIGHT*0, 0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(WIDTH*0,HEIGHT*0.25, 0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(WIDTH,HEIGHT*0, 0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(WIDTH,HEIGHT*0.25, 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idCrowd);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(x/2.0,1.0);
        glVertex3f(WIDTH*0,HEIGHT, 0.0);
        glTexCoord2f(x/2,0.0);
        glVertex3f(WIDTH*0,HEIGHT*0.88, 0.0);
        glTexCoord2f((x/2.0)+(1.0/2.0),1.0);
        glVertex3f(WIDTH,HEIGHT, 0.0);
        glTexCoord2f((x/2.0)+(1.0/2.0),0.0);
        glVertex3f(WIDTH,HEIGHT*0.88, 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex3f(WIDTH*0,HEIGHT*0.75,0.0);
        glVertex3f(WIDTH*0,HEIGHT*0.88,0.0);
        glVertex3f(WIDTH,HEIGHT*0.75,0.0);
        glVertex3f(WIDTH,HEIGHT*0.88,0.0);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idCourt);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(WIDTH*0,HEIGHT*0.25,0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(WIDTH*0,HEIGHT*0.75,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(WIDTH,HEIGHT*0.25,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(WIDTH,HEIGHT*0.75,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D,player1.icon);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(WIDTH*0.1,HEIGHT*0.05,0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(WIDTH*0.1,HEIGHT*0.15,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(WIDTH*0.2,HEIGHT*0.05,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(WIDTH*0.2,HEIGHT*0.15,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D,player2.icon);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(WIDTH*0.8,HEIGHT*0.05,0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(WIDTH*0.8,HEIGHT*0.15,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(WIDTH*0.9,HEIGHT*0.05,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(WIDTH*0.9,HEIGHT*0.15,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
void drawBoard(){
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex3f(WIDTH*0.32,HEIGHT*0.79,0.0);
        glVertex3f(WIDTH*0.32,HEIGHT*0.88,0.0);
        glVertex3f(WIDTH*0.67,HEIGHT*0.79,0.0);
        glVertex3f(WIDTH*0.67,HEIGHT*0.88,0.0);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idBoard);
    glEnable(GL_TEXTURE_2D);
    boardP1_1(dP1);
    glDisable(GL_TEXTURE_2D);              //FUNCAO PARA DESENHAR E ALTERAR O PLACAR

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idBoard);
    glEnable(GL_TEXTURE_2D);
    boardP1_2(uP1);
    glDisable(GL_TEXTURE_2D);

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idBoard);
    glEnable(GL_TEXTURE_2D);
    boardP2_1(dP2);
    glDisable(GL_TEXTURE_2D);

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idBoard);
    glEnable(GL_TEXTURE_2D);
    boardP2_2(uP2);
    glDisable(GL_TEXTURE_2D);

}
void drawKing(){           //ANALISA E DESENHA O REIZINHO
    if(king(King)==1){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, Crown);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(WIDTH*0.1,HEIGHT*0.15,0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(WIDTH*0.1,HEIGHT*0.2,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(WIDTH*0.2,HEIGHT*0.15,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(WIDTH*0.2,HEIGHT*0.2,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    }
    else if(king(King)==2){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, Crown);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(WIDTH*0.8,HEIGHT*0.15,0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(WIDTH*0.8,HEIGHT*0.2,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(WIDTH*0.9,HEIGHT*0.15,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(WIDTH*0.9,HEIGHT*0.2,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }

}
void drawMatchPoint(){
    if((dP1*10.0)+uP1==11.0 || (dP2*10.0)+uP2==11.0){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, matchpoint);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);                //ANALISA E DENEHA SE FOI MATCHPOINT
        glVertex3f(WIDTH*0.3,HEIGHT*0.05,0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(WIDTH*0.3,HEIGHT*0.2,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(WIDTH*0.7,HEIGHT*0.05,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(WIDTH*0.7,HEIGHT*0.2,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    }

}
void drawPoints(){  // DESENHA OS SETS DE CADA JOGADOR
    if(P1set>0.0){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, player1.points);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(WIDTH*0.2,HEIGHT*0.05,0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(WIDTH*0.2,HEIGHT*0.1,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(WIDTH*0.25,HEIGHT*0.05,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(WIDTH*0.25,HEIGHT*0.1,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
    if(P2set>0.0){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, player2.points);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(WIDTH*0.75,HEIGHT*0.05,0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(WIDTH*0.75,HEIGHT*0.1,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(WIDTH*0.8,HEIGHT*0.05,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(WIDTH*0.8,HEIGHT*0.1,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
    if(P1set>1.0){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, player1.points);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(WIDTH*0.25,HEIGHT*0.05,0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(WIDTH*0.25,HEIGHT*0.1,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(WIDTH*0.3,HEIGHT*0.05,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(WIDTH*0.3,HEIGHT*0.1,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
    if(P2set>1.0){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, player2.points);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(WIDTH*0.7,HEIGHT*0.05,0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(WIDTH*0.7,HEIGHT*0.1,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(WIDTH*0.75,HEIGHT*0.05,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(WIDTH*0.75,HEIGHT*0.1,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
    if(P1set>2.0){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, player1.points);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(WIDTH*0.3,HEIGHT*0.05,0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(WIDTH*0.3,HEIGHT*0.1,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(WIDTH*0.35,HEIGHT*0.05,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(WIDTH*0.35,HEIGHT*0.1,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }

    if(P2set>2.0){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, player2.points);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(WIDTH*0.65,HEIGHT*0.05,0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(WIDTH*0.65,HEIGHT*0.1,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(WIDTH*0.7,HEIGHT*0.05,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(WIDTH*0.7,HEIGHT*0.1,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }

}
void drawGame(){
    drawScenario();
    drawKing();
    drawMatchPoint();
    drawBoard();           //DESENHA A PARTIDA
    drawPlayer1();
    drawPlayer2();
    drawBall();
    drawPoints();
}
void drawScene(){
    glClear(GL_COLOR_BUFFER_BIT);   //DESENHA A CENA DE TODOS OS MODOS DE JOGO
    switch(gamemode){
    case Menu:
    MenuMode(mkey,idLogo,idWallpaper,idSelect,idHow2Play,idStart);
    break;
    case Play:
    drawGame();
    break;
    case Pause:
    drawGame();
    PauseMode(idPause);
    break;
    case Exit:
    drawGame();
    ExitMode(idExit);
    break;
    case Restart:
    drawGame();
    RestartMode(idReset);
    break;
    case Selection:
    SelectionMode(skey,aux,selecStep,nameSheet,idSelect,acozicon,bobicon,pamicon,brianicon,
                  sammyicon,harryicon,idSelection,idp1,idp2,locker);
    break;
    case P1Win:
    drawGame();
    P1WinMode(idp1Win);
    break;
    case P2Win:
    drawGame();
    P2WinMode(idp2Win);
    break;
    case HowtoPlay:
    How2playMode(options);
    break;
    }
    glutSwapBuffers();
}

int ballIn(sprite player){
    if(ball.centery+(ball.width/2)>=player.centery-(player.width/2)&&
       ball.centery-(ball.width/2)<=player.centery+(player.width/2))  //SE A BOLA ENCONSTOU NO PLAYER
        return 1;

    else
        return 0;
}
int scenarioHit(){
    if(ball.centery+(ball.width/2)>=HEIGHT*0.75||
       ball.centery-(ball.width/2)<=HEIGHT*0.25)   //ANALISA SE A BOLA BATEU NO CENARIO
        return 1;
    else
        return 0;
}
int spriteHit(){
    if(ball.centerx+(ball.height/2)>=player2.centerx-(player2.height/2)){
        if(ballIn(player2)){
            p2hit = 1; //SE A BOLA BATEU NO P1
            return 1;    // SE A BOLA BATEU NO P2
        }
        else{
            p1Score();
            p1Game();    //SE NAO BATEU, P1 PONTUA
            resetball();
        }
    }
    else if(ball.centerx-(ball.height/2)<=player1.centerx+(player1.height/2)){
        if(ballIn(player1)){
            p1hit = 1; //P1HIT = ALTERA ANIMACAO DO P1
            return 1;   //SE A BOLA BATEU NO P1
        }
        else{
            p2Score();
            p2Game();   //SE NAO BATEU, P2 PONTUA
            resetball();
        }
    }
    else
        return 0;
}
void ballroute(){
    ball.centerx += (WIDTH/80*cos(i));
    ball.centery += (WIDTH/80*sin(j));
    if(spriteHit()){
        i=refreshBallX(i); // ANALISA SE A BOLA COLIDIU COM UM JOGADOR
        i+= PI;
    }
    else if(scenarioHit()){    //ANALISA SE A BOLA COLIDIU COM O CENARIO
        j=refreshBallY(j);
        j-= PI;
    }
}
void redraw(int timer){
    switch(gamemode){
    case Play:
    ballroute();
    moveup();
    movedown();
    glutPostRedisplay();
    break;

    case Pause:
    drawScene();
    break;

    case Restart:
    drawScene();
    break;

    case Exit:      //REDESENHA OS FRAMES EM CADA MODO DE JOGO
    drawScene();
    break;

    case Menu:
    drawScene();
    break;

    case Selection:
    drawScene();
    break;

    case P1Win:
    drawScene();
    break;

    case P2Win:
    drawScene();
    break;

    case HowtoPlay:
    drawScene();
    break;
    }

 glutTimerFunc(33,redraw,0);
}
void ballStart(){
   ball.centerx = WIDTH/2;
   ball.centery = HEIGHT/2;
   ball.height  = 10.0;   // STATUS INICIAIS DA BOLA
   ball.width   = 10.0;
}
void player1Start(){
   player1.centerx = WIDTH*0.1;
   player1.centery = HEIGHT/2; //STATUS INICIAIS DO P1
   player1.height  = 25.0;
   player1.width   = 25.0;
}
void player2Start(){
   player2.centerx = WIDTH*0.9;
   player2.centery = HEIGHT/2;
   player2.height  = 25.0;  // STATUS INICIAIS DO P2
   player2.width   = 25.0;

}

void start(){
   glClearColor(1, 1, 1, 1);
   player1Start();
   player2Start();
   ballStart();
   idBoard = loadTexture("bin/Debug/board.png");
   idCourt = loadTexture("bin/Debug/court.png");
   idBush  = loadTexture("bin/Debug/Bush.png");    // CARREGA TODAS AS TEXTURAS DO JOGO
   idBall  = loadTexture("bin/Debug/ball.png");
   idCrowd = loadTexture("bin/Debug/crowd.png");
   idPause = loadTexture("bin/Debug/Pause.png");
   idExit  = loadTexture("bin/Debug/Quit.png");
   idReset = loadTexture("bin/Debug/Reset.png");
   idLogo  = loadTexture("bin/Debug/GameLogo.png");
   idWallpaper = loadTexture("bin/Debug/Wall.png");
   idSelect = loadTexture("bin/Debug/RacketSelect.png");
   idSelection = loadTexture("bin/Debug/SelectCharacter.png");
   idStart = loadTexture("bin/Debug/Start.png");
   idHow2Play = loadTexture("bin/Debug/Howtoplay.png");
   nameSheet = loadTexture("bin/Debug/namesheet.png");
   options = loadTexture("bin/Debug/options.png");
   Crown = loadTexture("bin/Debug/crown02.png");
   idp1Win = loadTexture("bin/Debug/p1win.png");
   idp2Win = loadTexture("bin/Debug/p2win.png");
   idp1 = loadTexture("bin/Debug/Player1.png");
   idp2 = loadTexture("bin/Debug/Player2.png");
   matchpoint = loadTexture("bin/Debug/matchpoint.png");
   locker = loadTexture("bin/Debug/locker.png");
   acozp1 = loadTexture("bin/Debug/acozP1.png");
   acozp1hit = loadTexture("bin/Debug/acozP1hit.png");
   acozp2 = loadTexture("bin/Debug/acozP2.png");
   acozp2hit = loadTexture("bin/Debug/acozP2hit.png");
   acozup = loadTexture("bin/Debug/acozup.png");
   acozdown = loadTexture("bin/Debug/acozDown.png");
   acozvictory = loadTexture("bin/Debug/acozwin.png");
   acozdefeat = loadTexture("bin/Debug/acozlose.png");
   acozicon = loadTexture("bin/Debug/acozIcon.png");
   acozpoints = loadTexture("bin/Debug/acozpoints.png");
   bobp1 = loadTexture("bin/Debug/bobP1.png");
   bobp1hit = loadTexture("bin/Debug/bobP1hit.png");
   bobp2 = loadTexture("bin/Debug/bobP2.png");
   bobp2hit = loadTexture("bin/Debug/bobP2hit.png");
   bobup = loadTexture("bin/Debug/bobup.png");
   bobdown = loadTexture("bin/Debug/bobdown.png");
   bobvictory = loadTexture("bin/Debug/bobwin.png");
   bobdefeat = loadTexture("bin/Debug/boblose.png");
   bobicon = loadTexture("bin/Debug/bobIcon.png");
   bobpoints = loadTexture("bin/Debug/bobpoints.png");
   sammyp1 = loadTexture("bin/Debug/sammyP1.png");
   sammyp1hit = loadTexture("bin/Debug/sammyP1hit.png");
   sammyp2 = loadTexture("bin/Debug/sammyP2.png");
   sammyp2hit = loadTexture("bin/Debug/sammyP2hit.png");
   sammyup = loadTexture("bin/Debug/sammyup.png");
   sammydown = loadTexture("bin/Debug/sammydown.png");
   sammyvictory = loadTexture("bin/Debug/sammywin.png");
   sammydefeat = loadTexture("bin/Debug/sammylose.png");
   sammyicon = loadTexture("bin/Debug/sammyIcon.png");
   sammypoints = loadTexture("bin/Debug/sammypoints.png");
   harryp1 = loadTexture("bin/Debug/harryP1.png");
   harryp1hit = loadTexture("bin/Debug/harryP1hit.png");
   harryp2 = player2.stop = loadTexture("bin/Debug/harryP2.png");
   harryp2hit = player2.hit = loadTexture("bin/Debug/harryP2hit.png");
   harryup = loadTexture("bin/Debug/harryup.png");
   harrydown = loadTexture("bin/Debug/harrydown.png");
   harryvictory = loadTexture("bin/Debug/harrywin.png");
   harrydefeat = loadTexture("bin/Debug/harrylose.png");
   harryicon = loadTexture("bin/Debug/harryIcon.png");
   harrypoints = loadTexture("bin/Debug/harrypoints.png");
   pamp1 = loadTexture("bin/Debug/pamP1.png");
   pamp1hit = loadTexture("bin/Debug/pamP1hit.png");
   pamp2 = loadTexture("bin/Debug/pamP2.png");
   pamp2hit = loadTexture("bin/Debug/pamP2hit.png");
   pamup = loadTexture("bin/Debug/pamup.png");
   pamdown = loadTexture("bin/Debug/pamdown.png");
   pamvictory = loadTexture("bin/Debug/pamwin.png");
   pamdefeat = loadTexture("bin/Debug/pamlose.png");
   pamicon = loadTexture("bin/Debug/pamIcon.png");
   pampoints = loadTexture("bin/Debug/pampoints.png");
   brianp1 = loadTexture("bin/Debug/brianP1.png");
   brianp1hit = loadTexture("bin/Debug/brianP1hit.png");
   brianp2 = loadTexture("bin/Debug/brianP2.png");
   brianp2hit = loadTexture("bin/Debug/brianP2hit.png");
   brianup =loadTexture("bin/Debug/brianup.png");
   briandown = loadTexture("bin/Debug/briandown.png");
   brianvictory = loadTexture("bin/Debug/brianwin.png");
   briandefeat = loadTexture("bin/Debug/brianlose.png");
   brianicon = loadTexture("bin/Debug/brianIcon.png");
   brianpoints = loadTexture("bin/Debug/brianpoints.png");
}

void setup()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void redimensiona(int width, int height)
{
  glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, 0,HEIGHT, -1, 1);

    double windowPattern, worldPattern;
    double TopEdge,BottomEdge,RightEdge,LeftEdge;

     windowPattern = ((float)width)/height;
     worldPattern  = ((float) WIDTH)/ HEIGHT;
     if (windowPattern < worldPattern) {        // MANTEM A PROPORCAO
         TopEdge    = width / worldPattern;
         BottomEdge = (height - TopEdge)/2;
         glViewport(0, BottomEdge, width, TopEdge);
    }
     else if (windowPattern > worldPattern) {
         RightEdge = ((float)height)*worldPattern;
         LeftEdge  = (width - RightEdge)/2;
         glViewport(LeftEdge, 0,RightEdge, height);
    }
    else
        glViewport(0, 0, width, height);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
   switch(key) {
      case 13:
        if(gamemode==Menu){
            if(mkey == 1)   //SE SELECIONAR JOGAR
                gamemode = Selection;
            else
                gamemode = HowtoPlay; //SE SELECIONAR COMO JOGAR
        }
        else if(gamemode==Selection){
            if(selecStep==0){
                aux = skey;
                P1Character = (int)skey; // VARIAVEL QUE INDICA QUAL PERSONAGEM O JOGADOR 1 JOGARA
                player1.stop = acozp1;
                switch(P1Character){
                    case 0:
                        player1.up  = acozup;
                        player1.down= acozdown;
                        player1.hit = acozp1hit;
                        player1.stop = acozp1;
                        player1.victory = acozvictory;
                        player1.defeat = acozdefeat;
                        player1.icon  = acozicon;
                        player1.points = acozpoints;
                    break;
                    case 1:
                        player1.up  = bobup;
                        player1.down= bobdown;
                        player1.hit = bobp1hit;
                        player1.stop = bobp1;
                        player1.victory = bobvictory;
                        player1.defeat = bobdefeat;
                        player1.icon  = bobicon;
                        player1.points = bobpoints;    //SELECIONA AS TEXTURAS DO PERSONAGEM ESCOLHIDO
                        break;
                    case 2:
                        player1.up  = sammyup;
                        player1.down= sammydown;
                        player1.hit = sammyp1hit;
                        player1.stop = sammyp1;
                        player1.victory = sammyvictory;
                        player1.defeat = sammydefeat;
                        player1.icon  = sammyicon;
                        player1.points = sammypoints;
                        break;
                    case 3:
                        player1.up  = harryup;
                        player1.down= harrydown;
                        player1.hit = harryp1hit;
                        player1.stop = harryp1;
                        player1.victory = harryvictory;
                        player1.defeat = harrydefeat;
                        player1.icon  = harryicon;
                        player1.points = harrypoints;
                    break;
                    case 4:
                        player1.up  = pamup;
                        player1.down= pamdown;
                        player1.hit = pamp1hit;
                        player1.stop = pamp1;
                        player1.victory = pamvictory;
                        player1.defeat = pamdefeat;
                        player1.icon  = pamicon;
                        player1.points = pampoints;
                        break;
                    case 5:
                        player1.up  = brianup;
                        player1.down= briandown;
                        player1.hit = brianp1hit;
                        player1.stop = brianp1;
                        player1.victory = brianvictory;
                        player1.defeat = briandefeat;
                        player1.icon  = brianicon;
                        player1.points = brianpoints;
                        break;
                        default:
                         break;

                    }
                selecStep++;
            }
            else if(selecStep==1){
                P2Character = (int)skey; // VARIAVEL QUE INDICA QUAL PERSONAGEM O JOGADOR 2 JOGARA
                gamemode = Play;
                switch(P2Character){
                    case 0:
                        player2.up  = acozup;
                        player2.down= acozdown;
                        player2.hit = acozp2hit;
                        player2.stop = acozp2;
                        player2.victory = acozvictory;
                        player2.defeat = acozdefeat;
                        player2.icon  = acozicon;
                        player2.points = acozpoints;
                        break;
                    case 1:
                        player2.up  = bobup;
                        player2.down= bobdown;
                        player2.hit = bobp2hit;
                        player2.stop = bobp2;
                        player2.victory = bobvictory;
                        player2.defeat = bobdefeat;  // SELECIONA AS TEXTURA SDO PERSONAGEM ESCOLHIDO
                        player2.icon  = bobicon;
                        player2.points = bobpoints;
                        break;
                    case 2:
                        player2.up  = sammyup;
                        player2.down= sammydown;
                        player2.hit = sammyp2hit;
                        player2.stop = sammyp2;
                        player2.victory = sammyvictory;
                        player2.defeat = sammydefeat;
                        player2.icon  = sammyicon;
                        player2.points = sammypoints;
                        break;
                    case 3:
                        player2.up  = harryup;
                        player2.down= harrydown;
                        player2.hit = harryp2hit;
                        player2.stop = harryp2;
                        player2.victory = harryvictory;
                        player2.defeat = harrydefeat;
                        player2.icon  = harryicon;
                        player2.points = harrypoints;
                        break;
                    case 4:
                        player2.up  = pamup;
                        player2.down= pamdown;
                        player2.hit = pamp2hit;
                        player2.stop = pamp2;
                        player2.victory = pamvictory;
                        player2.defeat = pamdefeat;
                        player2.icon  = pamicon;
                        player2.points = pampoints;
                        break;
                    case 5:
                        player2.up  = brianup;
                        player2.down= briandown;
                        player2.hit = brianp2hit;
                        player2.stop = brianp2;
                        player2.victory = brianvictory;
                        player2.defeat = briandefeat;
                        player2.icon  = brianicon;
                        player2.points = brianpoints;
                        break;
                        default:
                         break;

                    }
            }
        }
        else if(gamemode == P1Win || gamemode == P2Win){
            gamemode = Menu;
            resetGame(); //QUANDO O JOGO ACABA, O JOGADOR PODE VOLTAR PRO MENU
            }
        break;
      case 27:
         if(gamemode == Play){
             gamemode = Exit; //SE ESTIVER NO MEIO DA PARTIDA, MOSTRA A MENSAGEM SE DESEJA SAIR
         }
         else if(gamemode == HowtoPlay){
            gamemode = Menu;  // VOLTA DO HOW TO PLAY PRO MENU
         }
         else if(gamemode == P1Win || gamemode == P2Win){
            resetGame();
            resetball();
            resetP1();
            resetP2();
            gamemode = Menu; //SE A PARTIDA TEMINAR PODE VOLTAR PRO MENU
         }
         else if(gamemode == Menu){
            exit(0); //SAI DO JOGO
         }
         break;
      case 119:
         if(gamemode == Play){
            keyB[119]=1; //MOVE PLAYER 1 PARA CIMA
         }
         else if(gamemode == Menu){
            if(mkey == 0)
                mkey++; //VAI DA OPCAO HOW TO PLAY PARA O PLAY
         }
         else if(gamemode == Selection){
            if(skey<5.0)
                skey++; //MUDA O PERSONAGEM SELECIONADO
         }
         break;
      case 111:
         keyB[111]=1;
         break;
      case 115:
        if(gamemode == Play){
            keyB[115]=1; //MOVE PLAYER 1 PARA BAIXO
        }
        if(gamemode == Menu){
            if(mkey == 1)
                mkey--; // VAI DO PLAY PARA O HOW TO PLAY
         }
        if(gamemode == Selection){
            if(skey>0)
                skey = skey-1.0; // MUDA O PERSONAGEM SELECIONADO
        }
         break;
      case 108:
         keyB[108]=1; //MOVE O PLAYER 2
         break;
      case 110:
         if(gamemode == Restart || gamemode == Exit){
            gamemode = Play; //VOLTA PARA O JOGO
         }
         break;
      case 112:
         gamemode = Pause; // PAUSA O JOGO
         break;
      case 114:
         gamemode = Restart; // ENTRA NA MENSAGEM DE PAUSE
         break;
      case 121:
         if(gamemode == Pause){
            gamemode = Play; //SAI DO PAUSE
         }
         if(gamemode == Restart){
            resetGame();
            resetP1();
            resetP2(); // REINICIA O JOGO
            resetball();
            gamemode = Play;
         }
         if(gamemode == Exit){
            resetGame();
            resetball();
            resetP1();
            resetP2();  //SAI DA PARTIDA
            gamemode = Menu;
         }
        break;
      default:
         break;

    }
}
void keyboardUP(unsigned char key, int x, int y) {
   switch(key) {
      case 119:
         keyB[119]=0;
         break;
      case 111:
         keyB[111]=0;
         break;
      case 115:       // INDICA QUANDO AS TECLAS NAO ESTAO PRESSIONADAS
         keyB[115]=0;
         break;
      case 108:
         keyB[108]=0;
         break;
      default:
         break;
   }
}
int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Joguinho");

    start();
    glutDisplayFunc(drawScene);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUP);
    glutTimerFunc(500,uptadeP1,0); //TEMPO DE ATUALIZAR AS TEXTURAS DO JOGADOR 1
    glutTimerFunc(500,uptadeP2,0); // TEMPO DE ATUALIZAR AS TEXTURAS DO JOGADOR 2
    glutTimerFunc(1000,uptadeAni,0); // TEMPO DE ATUALIZAR ANIMACAO DO CENARIO
    glutTimerFunc(33,redraw,0); // TAXA DE QUADROS PORSEGUNDO DO JOGO

    setup();

    glutMainLoop();
    return 0;
}
