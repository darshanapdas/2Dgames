#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float xpos = 35;
float ypos = 15;

static int width = 7;
static int height = 15;
int i, j;
static float divposx = 48;
static float divposy = 100;
int divHeight = 10;
int divWidth = 3;
int gap = 20;
int movd = 100;
static int score = 0;
static int nail_count = 0;
float petrol_x = 32;
float petrol_y = 50;
float oil_x = 50;
float oil_y = 50;
int game_over = 0;

char buffer[10];

void init(void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_FLAT);
}

void drawText(char ch[],int xpos, int ypos)
{
    int numofchar = strlen(ch);
    glLoadIdentity ();
    glRasterPos2f( xpos , ypos);
    for (i = 0; i <= numofchar - 1; i++)
    {

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);
    }
}

 //This function is used to write the score on the opengl window at xpos and ypos
 //here ch[] contains the number in string and numtext is number of digits to use in display the number
void drawTextNum(char ch[],int numtext,int xpos, int ypos)
{
    int len;
    int k;
    k = 0;
    len = numtext - strlen(ch);
    glLoadIdentity ();
    glRasterPos2f( xpos , ypos);
    for (i = 0; i <=numtext - 1; i++)
    {
    if ( i < len )
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'0');
    else
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[k]);
        k++;
    }

    }
}

void display(void) {

  if(game_over == 0) {
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);

  ///Background
    glPushMatrix();

  	glColor3f(0, 1, 0);
  	glRectf(0, 0, 100, 100);

  		//ROAD
  	glColor3f(0.2,0.2,0.2);
    glRectf(30, 0, 70, 100);
    glPopMatrix();



    //Dividers
    glPushMatrix();
    glColor3f(1, 1, 1);
    int i = 0;
    for(i = -10; i <= 10; i++)
      glRectf(divposx, divposy + gap*i, divposx + divWidth, divposy + divHeight + gap*i );
    glPopMatrix();

    //Petrol
    glPushMatrix();
    glColor3f(1, 1, 0);
    glRectf(petrol_x, petrol_y, petrol_x+5, petrol_y+5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1, 0, 0);
    drawText("Fuel", petrol_x+0.5, petrol_y + 2);
    glPopMatrix();

    //Spilled Oil
    glPushMatrix();
    glColor3f(0, 0, 0);
    glRectf(oil_x, oil_y, oil_x+4, oil_y+6);
    glEnd();
    glPushMatrix();
    glColor3f(1, 1, 1);
    drawText("Nail", oil_x, oil_y + 2);
    glPopMatrix();

    glPopMatrix();

    //Car
    glPushMatrix();
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(xpos+2, ypos+height+2);
    glVertex2i(xpos, ypos+height);
    glVertex2i(xpos+width, ypos+height);
    glVertex2i(xpos+width-2, ypos+height + 2);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glRectf(xpos, ypos+1, xpos-1, ypos+4);
    glRectf(xpos+width, ypos+1, xpos+1+width, ypos+4);
    glRectf(xpos, ypos+height-2, xpos-1, ypos+height-5);
    glRectf(xpos+width, ypos+height-2, xpos+1+width, ypos+height-5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 0, 0);
    glRectf(xpos, ypos, xpos + width, ypos + height);
    glPopMatrix();

    drawText("Score: ", 80, 80);
    snprintf(buffer, sizeof(buffer), "%d", score);
    drawTextNum(buffer, 6, 90, 80);
   }
   else {
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    glPushMatrix();
    glColor3f(1, 1, 1);
    drawText("GAME OVER!", 45, 50);
    drawText("Your Score: ",40, 40);
    snprintf(buffer, sizeof(buffer), "%d", score);
    drawTextNum(buffer, 6, 55, 40);
    glPopMatrix();
   }

  glutSwapBuffers();
}



void reshape (int w, int h) {
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  glOrtho(0,100,0,100,0,100);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void moveBullet() {
  if(nail_count == 3) {
    game_over = 1;
  }
  if((xpos <= petrol_x && xpos+width >= petrol_x+5) && (ypos >= petrol_y && ypos-height<=petrol_y-5)){
    petrol_x = 32 + rand()%30;
    petrol_y = 40 + rand()%70;
    score++;
  }
  if((xpos <= oil_x && xpos+width >= oil_x+4) && (ypos >= oil_y && ypos-height<=oil_y-6)) {
    oil_x = 32 + rand()%30;
    oil_y = 50 + rand()%90;
    nail_count++;
  }


   if(petrol_y <= 0) {
     petrol_x = 32 + rand()%30;
     petrol_y = 40 + rand()%70;
   }
   if(oil_y <= 0) {
     oil_x = 32 + rand()%30;
     oil_y = 40 + rand()%90;
   }
   oil_y -= 1;
   petrol_y -= 1;
   divposy -= 1 ;
   if(divposy < 0 )
    divposy = 100;
   glutPostRedisplay();
}


void keyboard (unsigned char key, int x, int y) {
  switch(key) {
    case 'd':
      xpos += 3;
      if(xpos+width > 70)
        xpos -= width;
      break;
    case 'a':
      xpos -= 3;
      if(xpos < 30)
        xpos += 5;
      break;
    case 'w':
      ypos += 3;
      if(ypos+height > 100)
        ypos -= height;
      break;
    case 'z':
      ypos -= 3;
      if(ypos < 0)
        ypos += 10;
      break;
    default:
      break;
  }
  glutPostRedisplay();

}



int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (900, 900);
  glutInitWindowPosition (50, 50);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(moveBullet);
  glutKeyboardFunc(keyboard);

  glutMainLoop();
  return 0;
}
