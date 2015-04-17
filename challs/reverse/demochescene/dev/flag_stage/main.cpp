#include <unistd.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SDL/SDL.h>
#include <SDL/SDL_timer.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>

#define SIGN(x) ((x) < 0 ? -1 : 1)
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define FRAMES_PER_SECOND 20

#define WALLXP 30
#define WALLXN -30

#define WALLYP 30
#define WALLYN -30

#define WALLZP 1
#define WALLZN -100

#define ENDLIFE 500

//FLAG{HOPE_YOU_LIKED_IT}


const int flag[][133] =
{
  { 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0 },
    { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
      { 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
{ 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0 }
};


  
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
 
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f }; 

volatile char g_sound_byte = 0;
int g_sound_level = 0;

class Sphere;

Sphere *tabSphere[700] = {};
int nb_sphere = 0;
bool chaos = false;

class Sphere
{
public:
  double x;
  double y;
  double z;

  double endx;
  double endy;
  double endz;
  
  double size;
  double precisionLong;
  double precisionLat;

  double startvelx;
  double startvely;
  double startvelz;

  double velx;
  double vely;
  double velz;
  double persistance;

  double r;
  double g;
  double b;

  int lifetick;
  
  Sphere(double px, double py, double pz, double ps)
  {
    x = px;
    y = py;
    z = pz;
    size = ps;
    precisionLong = 5;
    precisionLat = 5;
    startvelx = velx = (rand()%2000-1000)/2000.;
    startvely = vely = (rand()%2000-1000)/2000.;
    startvelz = velz = (rand()%2000-1000)/2000.;
    persistance = 0.99;
    r = (rand()%1000)/1000.;
    g = (rand()%1000)/1000.;
    b = (rand()%1000)/1000.;

    endx = 0;
    endy = 0;
    endz = 0;
    
    lifetick = 0;
    init_endpos();
  }
  
  bool operator==(const Sphere &o)
  {
    int match = 0;
    if (ABS(x-o.x) <= size + o.size)
      {
	match++;
      }
    if (ABS(y-o.y) <= size + o.size)
      {
	match++;
      }
    if (ABS(z-o.z) <= size + o.size)
      {
	match++;
      }
    return match == 3;
  }

  void draw(double sizecoef = 1)
  {
    precisionLat = lifetick / 20 + 4;
    if (precisionLat > 50)
      precisionLat = 50;

    precisionLong = lifetick / 20 + 4;
    if (precisionLong > 50)
      precisionLong = 50;

    glColor3d(r,g,b);
    glPushMatrix();
    glTranslated(x,y,z);
    glutSolidSphere(size * sizecoef, precisionLong, precisionLat);
    glPopMatrix();
  }

  void anim()
  {
    if (lifetick > ENDLIFE && !chaos)
      {
    	movetoend();
    	lifetick++;
    	return;
      }
    x += velx + sin(lifetick / 10.) / (startvelx * 80);
    y += vely + sin(lifetick / 10.) / (startvely * 80);
    z += velz + sin(lifetick / 10.) / (startvelz * 80);



    velx *= persistance;
    vely *= persistance;
    velz *= persistance;

    if (x >= ((chaos) ? 60 : WALLXP) || x <= ((chaos) ? -60 : WALLXN))
      velx *= -1;
    if (y >= ((chaos) ? 30 : WALLYP) || y <= ((chaos) ? -30 : WALLYN))
      vely *= -1;
    if (z >= ((chaos) ? -2 : WALLZP) || z <= ((chaos) ? -150 : WALLZN))
      velz *= -1;

    lifetick++;
  }

  void init_endpos()
  {
    int cnt = -1;
    
    for (int y = 0 ; y < 5 ; y++)
    {
      for (int x = 132 ; x >= 0 ; x--)
  	{
  	  if (flag[4-y][x] == 1)
	    {
	      cnt++;
	      if (cnt == nb_sphere)
		{
		  endx = (x - 67) * 1.4;
		  endy = y * 1.8;
		  endz = -150;
		}
	    }
	}
    }
    if (endx == 0 && endy == 0 && endz == 0)
      printf("%d\n", nb_sphere);

  }
  
  void movetoend()
  {
    size = 0.9;

    velx *= 0.5;
    vely *= 0.5;
    velz *= 0.5;

    if (ABS(startvelx) < 0.5)
      startvelx *= 2;
    if (ABS(startvely) < 0.5)
      startvely *= 2;
    if (ABS(startvelz) < 0.5)
      startvelz *= 2;

    if (x < endx)
      x += ABS(startvelx) * 2;
    else if (x > endx)
      x -= ABS(startvelx) * 2;
    
    if (y < endy)
      y += ABS(startvely) * 2;
    else if (y > endy)
      y -= ABS(startvely) * 2;

    if (z < endz)
      z += ABS(startvelz) * 2;
    else if (z > endz)
      z -= ABS(startvelz) * 2;

    if (ABS(x - endx) < 3)
      x = endx;
    if (ABS(y - endy) < 3)
      y = endy;
    if (ABS(z - endz) < 3)
      z = endz;

  }

  void colid(Sphere &o, bool allowrec=true)
  {
    if (lifetick > ENDLIFE && !chaos)
      return;
    double sumx = ABS(o.velx) + ABS(velx);
    double sumy = ABS(o.vely) + ABS(vely);
    double sumz = ABS(o.velz) + ABS(velz);

    
    if (allowrec)
      o.colid(*this, false);
    
    velx = sumx * SIGN(velx);
    vely = sumy * SIGN(vely);
    velz = sumz * SIGN(velz);

    if (ABS(velx) > 1)
      velx = SIGN(velx) * 1;
    if (ABS(vely) > 1)
      vely = SIGN(vely) * 1;
    if (ABS(velz) > 1)
      velz = SIGN(velz) * 1;
    
    if (ABS(velx) + ABS(vely) + ABS(velz) >
	ABS(o.velx) + ABS(o.vely) + ABS(o.velz))
      {
	o.r = r;
	o.g = g;
	o.b = b;
      }
    else
      {
	r = o.r;
	g = o.g;
	b = o.b;
      }

  }

};

static void resize(int width, int height)
{
  const float ar = (float) width / (float) height;
 
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-ar, ar, -1.0, 1.0, 2.0, 150.0);
 
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity() ;
}

void enable_feature(int step)
{
  if (step < 0)
    step = 999999;

  if (step > 0)
    glEnable(GL_LIGHT0);
  if (step > 5)
    glEnable(GL_NORMALIZE);
  if (step > 7)
    glEnable(GL_COLOR_MATERIAL);
  if (step > 7)
    glEnable(GL_LIGHTING);

  if (step > 1)
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
  if (step > 2)
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
  if (step > 3)
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  if (step > 4)
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  if (step > 8)
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
  if (step > 9)
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
  if (step > 10)
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
  if (step > 11)
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); 
}


void disp()
{
  static int tick;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  int i = -1;
  while (tabSphere[++i])
    {
      tabSphere[i]->draw();
    }
  tick++;
  glutSwapBuffers();
}

void coffe()
{
  static unsigned tick = 0;
  int i;
  int j;

  if (tick == 1800)
    {
      chaos = true;
    }

  if (tick == 2000)
    exit(EXIT_SUCCESS);
  if (nb_sphere < 220 && tick % 5 == 0)
    
    {
      tabSphere[nb_sphere++] = new Sphere(0, 0, -10, 1);
    }

  i = -1;
  while (tabSphere[++i])
    {
      tabSphere[i]->anim();
    }


  i = -1;
  while (tabSphere[++i])
    {
      j = -1;
      while (tabSphere[++j])
	{
	  if (i != j && *tabSphere[i] == *tabSphere[j])
	    {
	      tabSphere[i]->colid(*tabSphere[j]);
	    }
	}
    }
  tick++;
}


void *sound(void *data)
{
  int t = 0;
  int sum = 0;
  
  (void) data;
  
  while (1)
    {
      sum += ABS(g_sound_byte);
      if (t % 80 == 0)
	{
	  g_sound_level = sum / 80;
	  sum = 0;
	}
      t++;
    }
  return NULL;
}

int main(int argc, char *argv[])
{
  srand(42);
  
  glutInit(&argc, argv);
  glutInitWindowSize(800,600);
  glutInitWindowPosition(10,10);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

  glutCreateWindow("demochescene");
  
  glClearColor(1,1,1,1);
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
 
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS); 

  enable_feature(-1);

  tabSphere[nb_sphere++] = new Sphere(0, 0, -10, 1);
  
  resize(800, 600);
  pthread_t th;
  pthread_create(&th, NULL, sound, NULL);

  struct timeval oldtime;
  struct timeval curtime;
  long elapsed;

  gettimeofday(&curtime, NULL);
  oldtime = curtime;
  while (1)
    {
      // usleep(100);
      coffe();
      gettimeofday(&curtime, NULL);
      elapsed = (curtime.tv_sec-oldtime.tv_sec)*1000000 + curtime.tv_usec-oldtime.tv_usec;

      oldtime = curtime;
      if (elapsed < 70000)
	usleep(70000 - elapsed);
      disp();
    }
  
  return 0;
}
