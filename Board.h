//FILE RESPONSAVEL PELO PLACAR

void boardP1_1(float i){
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(i/10.0,0.0);
        glVertex3f(WIDTH*0.33,HEIGHT*0.80,0.0);
        glTexCoord2f(i/10.0,1.0);
        glVertex3f(WIDTH*0.33,HEIGHT*0.87,0.0);
        glTexCoord2f((i/10.0)+(1.0/10.0),0.0);
        glVertex3f(WIDTH*0.4,HEIGHT*0.80,0.0);
        glTexCoord2f((i/10.0)+(1.0/10.0),1.0);
        glVertex3f(WIDTH*0.4,HEIGHT*0.87,0.0);
    glEnd();
}
void boardP1_2(float i){
        glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(i/10.0,0.0);
        glVertex3f(WIDTH*0.4,HEIGHT*0.80,0.0);
        glTexCoord2f(i/10.0,1.0);
        glVertex3f(WIDTH*0.4,HEIGHT*0.87,0.0);
        glTexCoord2f((i/10.0)+(1.0/10.0),0.0);
        glVertex3f(WIDTH*0.47,HEIGHT*0.80,0.0);
        glTexCoord2f((i/10.0)+(1.0/10.0),1.0);
        glVertex3f(WIDTH*0.47,HEIGHT*0.87,0.0);
    glEnd();

}
void boardP2_1(float i){
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(i/10.0,0.0);
        glVertex3f(WIDTH*0.52,HEIGHT*0.80,0.0);
        glTexCoord2f(i/10.0,1.0);
        glVertex3f(WIDTH*0.52,HEIGHT*0.87,0.0);
        glTexCoord2f((i/10.0)+(1.0/10.0),0.0);
        glVertex3f(WIDTH*0.59,HEIGHT*0.80,0.0);
        glTexCoord2f((i/10.0)+(1.0/10.0),1.0);
        glVertex3f(WIDTH*0.59,HEIGHT*0.87,0.0);
    glEnd();
}

void boardP2_2(float i){
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(i/10.0,0.0);
        glVertex3f(WIDTH*0.59,HEIGHT*0.80,0.0);
        glTexCoord2f(i/10.0,1.0);
        glVertex3f(WIDTH*0.59,HEIGHT*0.87,0.0);
        glTexCoord2f((i/10.0)+(1.0/10.0),0.0);
        glVertex3f(WIDTH*0.66,HEIGHT*0.80,0.0);
        glTexCoord2f((i/10.0)+(1.0/10.0),1.0);
        glVertex3f(WIDTH*0.66,HEIGHT*0.87,0.0);
    glEnd();
}
