//FILE QUE DESENHA A CENA DE CADA MODO DE JOGO

#define HEIGHT 300.0
#define WIDTH  300.0
    float WarningBW = 100.0;
    float WarningBH = 30.0;
    float WarningBW2 = 100.0;
    float WarningBH2 = 50.0;
    float WarningBW3 = 100.0;
    float WarningBH3 = 50.0;



void PauseMode(GLuint idPause){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idPause);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(WIDTH/2-WarningBW, (3*HEIGHT)/4-WarningBH,0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(WIDTH/2-WarningBW, (3*HEIGHT)/4+WarningBH,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(WIDTH/2+WarningBW, (3*HEIGHT)/4-WarningBH,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(WIDTH/2+WarningBW, (3*HEIGHT)/4+WarningBH,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
void ExitMode(GLuint idExit){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idExit);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(WIDTH/2-WarningBW2, (3*HEIGHT)/4-WarningBH2,0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(WIDTH/2-WarningBW2, (3*HEIGHT)/4+WarningBH2,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(WIDTH/2+WarningBW2, (3*HEIGHT)/4-WarningBH2,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(WIDTH/2+WarningBW2, (3*HEIGHT)/4+WarningBH2,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
void RestartMode(GLuint idReset){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idReset);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(WIDTH/2-WarningBW3, (3*HEIGHT)/4-WarningBH3,0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(WIDTH/2-WarningBW3, (3*HEIGHT)/4+WarningBH3,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(WIDTH/2+WarningBW3, (3*HEIGHT)/4-WarningBH3,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(WIDTH/2+WarningBW3, (3*HEIGHT)/4+WarningBH3,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
void MenuMode(int mkey,GLuint idLogo,GLuint idWallpaper,GLuint idSelect,GLuint idStart,GLuint idHow2Play){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idWallpaper);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0.0,0.0);
    glVertex3f(WIDTH*0,HEIGHT*0,0.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(WIDTH*0,HEIGHT,0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(WIDTH,HEIGHT*0,0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(WIDTH,HEIGHT,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idLogo);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0.0,0.0);
    glVertex3f(WIDTH*0.2,HEIGHT*0.6,0.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(WIDTH*0.2,HEIGHT,0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(WIDTH*0.8,HEIGHT*0.6,0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(WIDTH*0.8,HEIGHT,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idHow2Play);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0.0,0.0);
    glVertex3f(WIDTH*0.25,HEIGHT*0.4,0.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(WIDTH*0.25,HEIGHT*0.5,0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(WIDTH*0.75,HEIGHT*0.4,0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(WIDTH*0.75,HEIGHT*0.5,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);


    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idStart);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0.0,0.0);
    glVertex3f(WIDTH*0.25,HEIGHT*0.2,0.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(WIDTH*0.25,HEIGHT*0.3,0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(WIDTH*0.75,HEIGHT*0.2,0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(WIDTH*0.75,HEIGHT*0.3,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    if(mkey==1){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idSelect);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0.0,0.0);
    glVertex3f(WIDTH*0.05,HEIGHT*0.4,0.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(WIDTH*0.05,HEIGHT*0.5,0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(WIDTH*0.20,HEIGHT*0.4,0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(WIDTH*0.20,HEIGHT*0.5,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
    else if(mkey==0){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idSelect);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0.0,0.0);
    glVertex3f(WIDTH*0.05,HEIGHT*0.2,0.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(WIDTH*0.05,HEIGHT*0.3,0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(WIDTH*0.20,HEIGHT*0.2,0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(WIDTH*0.20,HEIGHT*0.3,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    }
}
void SelectionMode(float skey,float aux,int selecStep,GLuint idNameSheet,GLuint idSelect,GLuint idAcoz,GLuint idBob,GLuint idPam,
                   GLuint idBrian,GLuint idSammy,GLuint idHarry, GLuint idSelection, GLuint idp1, GLuint idp2,GLuint locker){

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, locker);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0.0,0.0);
    glVertex3f(WIDTH*0,HEIGHT*0,0.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(WIDTH*0,HEIGHT,0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(WIDTH,HEIGHT*0,0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(WIDTH,HEIGHT,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idAcoz);
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

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idBob);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0.0,0.0);
    glVertex3f(WIDTH*0.8,HEIGHT*0.2,0.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(WIDTH*0.8,HEIGHT*0.3,0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(WIDTH*0.9,HEIGHT*0.2,0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(WIDTH*0.9,HEIGHT*0.3,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idSammy);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0.0,0.0);
    glVertex3f(WIDTH*0.8,HEIGHT*0.35,0.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(WIDTH*0.8,HEIGHT*0.45,0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(WIDTH*0.9,HEIGHT*0.35,0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(WIDTH*0.9,HEIGHT*0.45,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idHarry);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0.0,0.0);
    glVertex3f(WIDTH*0.8,HEIGHT*0.5,0.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(WIDTH*0.8,HEIGHT*0.6,0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(WIDTH*0.9,HEIGHT*0.5,0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(WIDTH*0.9,HEIGHT*0.6,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idPam);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0.0,0.0);
    glVertex3f(WIDTH*0.8,HEIGHT*0.65,0.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(WIDTH*0.8,HEIGHT*0.75,0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(WIDTH*0.9,HEIGHT*0.65,0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(WIDTH*0.9,HEIGHT*0.75,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idBrian);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0.0,0.0);
    glVertex3f(WIDTH*0.8,HEIGHT*0.8,0.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(WIDTH*0.8,HEIGHT*0.9,0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(WIDTH*0.9,HEIGHT*0.8,0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(WIDTH*0.9,HEIGHT*0.9,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idSelection);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0.0,0.0);
    glVertex3f(WIDTH*0.3,HEIGHT*0.9,0.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(WIDTH*0.3,HEIGHT,0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(WIDTH*0.7,HEIGHT*0.9,0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(WIDTH*0.7,HEIGHT,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idp1);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0.0,0.0);
    glVertex3f(WIDTH*0.1,HEIGHT*0.7,0.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(WIDTH*0.1,HEIGHT*0.8,0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(WIDTH*0.4,HEIGHT*0.7,0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(WIDTH*0.4,HEIGHT*0.8,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idp2);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0.0,1.0);
    glVertex3f(WIDTH*0.1,HEIGHT*0.4,0.0);
    glTexCoord2f(0.0,0.0);
    glVertex3f(WIDTH*0.1,HEIGHT*0.3,0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(WIDTH*0.4,HEIGHT*0.4,0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(WIDTH*0.4,HEIGHT*0.3,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    if(selecStep==0){
        glColor3f(1.0,1.0,1.0);
        glBindTexture(GL_TEXTURE_2D, idNameSheet);
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,(skey/6.0));
        glVertex3f(WIDTH*0.1,HEIGHT*0.5,0.0);
        glTexCoord2f(0.0,((skey/6)+(1.0/6.0)));
        glVertex3f(WIDTH*0.1,HEIGHT*0.6,0.0);
        glTexCoord2f(1.0,(skey/6.0));
        glVertex3f(WIDTH*0.4,HEIGHT*0.5,0.0);
        glTexCoord2f(1.0,((skey/6)+(1.0/6.0)));
        glVertex3f(WIDTH*0.4,HEIGHT*0.6,0.0);
        glEnd();
    }

   else if(selecStep==1){
        glColor3f(1.0,1.0,1.0);
        glBindTexture(GL_TEXTURE_2D, idNameSheet);
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,(aux/6.0));
        glVertex3f(WIDTH*0.1,HEIGHT*0.5,0.0);
        glTexCoord2f(0.0,((aux/6)+(1.0/6.0)));
        glVertex3f(WIDTH*0.1,HEIGHT*0.6,0.0);
        glTexCoord2f(1.0,(aux/6.0));
        glVertex3f(WIDTH*0.4,HEIGHT*0.5,0.0);
        glTexCoord2f(1.0,((aux/6)+(1.0/6.0)));
        glVertex3f(WIDTH*0.4,HEIGHT*0.6,0.0);
        glEnd();

        glColor3f(1.0,1.0,1.0);
        glBindTexture(GL_TEXTURE_2D, idNameSheet);
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,(skey/6.0));
        glVertex3f(WIDTH*0.1,HEIGHT*0.1,0.0);
        glTexCoord2f(0.0,((skey/6)+(1.0/6.0)));
        glVertex3f(WIDTH*0.1,HEIGHT*0.2,0.0);
        glTexCoord2f(1.0,(skey/6.0));
        glVertex3f(WIDTH*0.4,HEIGHT*0.1,0.0);
        glTexCoord2f(1.0,((skey/6)+(1.0/6.0)));
        glVertex3f(WIDTH*0.4,HEIGHT*0.2,0.0);
        glEnd();
    }

    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idSelect);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0.0,0.0);
    glVertex3f(WIDTH*0.6,HEIGHT*(0.05+(0.15*skey)),0.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(WIDTH*0.6,HEIGHT*(0.15+(0.15*skey)),0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(WIDTH*0.75,HEIGHT*(0.05+(0.15*skey)),0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(WIDTH*0.75,HEIGHT*(0.15+(0.15*skey)),0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

}
void How2playMode(GLuint options){
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D,options);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0.0,0.0);
    glVertex3f(WIDTH*0,HEIGHT*0,0.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(WIDTH*0,HEIGHT,0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(WIDTH,HEIGHT*0,0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(WIDTH,HEIGHT,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);


}
void P1WinMode(GLuint idp1Win){
   glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idp1Win);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(WIDTH/2-WarningBW, (3*HEIGHT)/4-WarningBH,0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(WIDTH/2-WarningBW, (3*HEIGHT)/4+WarningBH,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(WIDTH/2+WarningBW, (3*HEIGHT)/4-WarningBH,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(WIDTH/2+WarningBW, (3*HEIGHT)/4+WarningBH,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void P2WinMode(GLuint idp2Win){
   glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, idp2Win);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(0.0,0.0);
        glVertex3f(WIDTH/2-WarningBW, (3*HEIGHT)/4-WarningBH,0.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(WIDTH/2-WarningBW, (3*HEIGHT)/4+WarningBH,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(WIDTH/2+WarningBW, (3*HEIGHT)/4-WarningBH,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(WIDTH/2+WarningBW, (3*HEIGHT)/4+WarningBH,0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

