//	Program developed by
//	Asier Blazquez Garcia

// to compile it: gcc dibujar-triangulo.c -lGL -lGLU -lglut g



#include <GL/glut.h>
#include <stdio.h>

static float	 LOCAL_Red = 0.0f;

void dibujartriangulo (xa, xb, xc, ya, yb, yc){
	
	//cual es el alto y
	int yalto=ya;
	int xalto=xa;
	if(yb>yalto){
		yalto=yb;
		xalto=xb;
	}
	
	if(yc>yalto){
		yalto=yc;
		xalto=xc;
	}
	
	//cual es el bajo y
	int ybajo=ya;
	int xbajo=xa;
	 
	if (yb<ybajo){
		ybajo=yb;
		xbajo=xb;
	}
	if (yc<ybajo){
		ybajo=yc;
		xbajo=xc;
	}
	
	//cual es el medio y
	int ymedio;
	int xmedio;
	if(yalto>ya && ya>ybajo){
		ymedio=ya;
		xmedio=xa;}
	if(yalto>yb && yb>ybajo){
		ymedio=yb;
		xmedio=xb;
	}
	if(yalto>yc && yc>ybajo){
		ymedio=yc;
		xmedio=xc;		
	}
	
	glBegin( GL_POINTS );
    glColor3f( 0.0f, 1.0f, 0.0f );
	
	float maldaAltaMedia= ((float)xalto-(float)xmedio)/((float)ymedio-yalto);
    float maldaMediaBaja= ((float)xmedio-xbajo)/((float)ybajo-ymedio);
    float maldaAltaBaja=  ((float)xalto-xbajo)/((float)ybajo-yalto);
	float entrada;
	float salida;
	float auxentrada=xalto;
	float auxsalida=xalto;
	int auxy;
	int auxx;
	
		for(auxy=yalto;auxy>ymedio;auxy--){
			
			auxentrada= auxentrada + maldaAltaMedia;
			auxsalida= auxsalida + maldaAltaBaja;
			 
			if (auxentrada< auxsalida){
				entrada= auxentrada;
				salida= auxsalida;
			}
			else{
				entrada=auxsalida;
				salida= auxentrada;
			}
			//dibujar 	 
			for(auxx=entrada; auxx<=salida; auxx++){
				glVertex3f( auxx, auxy, 0.0f );				
			}
		}
			
			//for de media a baja
			
			
			for(auxy=ymedio; auxy >ybajo; auxy--){
				
				
				auxentrada= auxentrada + maldaMediaBaja;
				auxsalida= auxsalida + maldaAltaBaja;
				
				if (auxentrada< auxsalida){
				entrada= auxentrada;
				salida= auxsalida;
			}
			else{
				entrada=auxsalida;
				salida= auxentrada;
			}
			
				
			//dibujar 	 
			for(auxx=entrada; auxx<=salida; auxx++){
				glVertex3f( auxx, auxy, 0.0f );				
			}
				}
		
		
		glEnd();
		
		
 }
	
	

static void marraztu(void)
{
float i,j;
	glClear( GL_COLOR_BUFFER_BIT );

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 500.0, 0.0, 500.0,-250.0, 250.0);
//triangulo
glColor3f( 1.0f, 1.0f, 1.0f );

	glBegin( GL_POINTS );
	
	int xa, xb, xc, ya, yb, yc;
	
	
		

		printf("Introduce xa: ");
			scanf("%d",&xa);
		printf("Introduce ya: ");
			scanf("%d",&ya);
		printf("Introduce xb: ");
			scanf("%d",&xb);
		printf("Introduce yb: ");
			scanf("%d",&yb);
		printf("Introduce xc: ");
			scanf("%d",&xc);
		printf("Introduce yc: ");
			scanf("%d",&yc);

	
	
	
	

		
	
	//punto a
	glVertex3f( xa, ya, 0.0f );
	//b	
	glVertex3f( xb, yb, 0.0f );
	//c
	glVertex3f( xc, yc, 0.0f );
	
    dibujartriangulo(xa, xb, xc, ya, yb, yc);
    
    
    	glEnd();

	glFlush();
}
// This function will be called whenever the user pushes one key
static void teklatua (unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'r': 
		if ( LOCAL_Red > 0.01f ) LOCAL_Red -= 0.1f;
		printf ("red   : ");
		break;
	case 'R':
		if ( LOCAL_Red < 1.0f ) LOCAL_Red += 0.1f;
		printf ("red   : ");
		break;
	case 27:  // <ESC>
		exit( 0 );
		break;
	default:
		printf("%d %c\n", key, key );
	}

	printf ("(R = %f) (G = %f) (B = %f) \n", LOCAL_Red, LOCAL_Red, LOCAL_Red );

	// The screen must be drawn to show the new values
	glutPostRedisplay();
}

int main(int argc, char** argv)
{

	printf("This program .................... \n");
	printf("Press <ESC> to finish\n");
	printf("Press < > < > to ..................\n");
	glutInit(&argc,argv);
	glutInitDisplayMode ( GLUT_RGB );
	glutInitWindowSize ( 500, 500 );
	glutInitWindowPosition ( 100, 100 );
	glutCreateWindow( "GL_POINTS" );

	glutDisplayFunc( marraztu );
	glutKeyboardFunc( teklatua );

	glClearColor( 0.0f, 0.0f, 0.7f, 1.0f );

	glutMainLoop();

	return 0;   
}
