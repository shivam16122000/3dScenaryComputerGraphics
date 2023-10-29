#include <cstdlib>
#include <cmath>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h> 
#include "getBMP.h"
#define PI 3.14159265

static int width, height; // Size of the OpenGL window.
static float angle = 0.0; // Angle of the spacecraft.
static float xVal = 0, zVal = 89; // Co-ordinates of the spacecraft.
static float eyeY = 26;
static unsigned int texture[8];
static int id = 0; // Currently displayed texture id.


void loadTextures()
{
	// Local storage for image data.
	imageFile *image[9];

	// Load the image.
	image[0] = getBMP("../Textures/snow.bmp");
	image[1] = getBMP("../Textures/tile.bmp");
	image[2] = getBMP("../Textures/blue.bmp");
	image[3] = getBMP("../Textures/blue.bmp");
	image[4] = getBMP("../Textures/snow.bmp");
	image[5] = getBMP("../Textures/treeleaf.bmp");
	image[6] = getBMP("../Textures/treewood.bmp");


	// Create texture object texture[0]. 
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	

	// Specify image data for currently active texture object.
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[0]->width, image[0]->height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[0]->data);




	// Set texture parameters for wrapping.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Set texture parameters for filtering.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[1]->width, image[1]->height, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, image[1]->data);

		// Set texture parameters for wrapping.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// Set texture parameters for filtering.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glBindTexture(GL_TEXTURE_2D, texture[2]);


		// Specify image data for currently active texture object.
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[2]->width, image[2]->height, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, image[2]->data);




		// Set texture parameters for wrapping.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// Set texture parameters for filtering.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


		glBindTexture(GL_TEXTURE_2D, texture[3]);


		// Specify image data for currently active texture object.
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[3]->width, image[3]->height, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, image[3]->data);




		// Set texture parameters for wrapping.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// Set texture parameters for filtering.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);



		glBindTexture(GL_TEXTURE_2D, texture[4]);


		// Specify image data for currently active texture object.
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[4]->width, image[4]->height, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, image[4]->data);




		// Set texture parameters for wrapping.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// Set texture parameters for filtering.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);





		glBindTexture(GL_TEXTURE_2D, texture[5]);


		// Specify image data for currently active texture object.
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[5]->width, image[5]->height, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, image[5]->data);




		// Set texture parameters for wrapping.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// Set texture parameters for filtering.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);




		glBindTexture(GL_TEXTURE_2D, texture[6]);


		// Specify image data for currently active texture object.
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[6]->width, image[6]->height, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, image[6]->data);




		// Set texture parameters for wrapping.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// Set texture parameters for filtering.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


}


void printTree(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3,float tx, float ty, float tz) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[5]);



	glPushMatrix();
	glScalef(6, 6, 6);
	glTranslatef(tx, ty,tz);


	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0); glVertex3f(x1, y1, z1);
	glTexCoord2f(1.0, 0.0); glVertex3f(x2, y2, z2);
	glTexCoord2f(1.0, 1.0); glVertex3f(x3, y3, z3);



	glEnd();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}

void triangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3,  float r, float g, float b, float t = 0) {
	
	if (t==1) {
		printTree(x1, y1, z1, x2, y2, z2, x3, y3, z3, 24, 0, -12);
	}
	else if (t == 2) {
		printTree(x1, y1, z1, x2, y2, z2, x3, y3, z3, 0, 0, -2);
	}
	else if (t == 3) {
		printTree(x1, y1, z1, x2, y2, z2, x3, y3, z3, 24, 0, -2);
	}
	else if (t == 4) {
		printTree(x1, y1, z1, x2, y2, z2, x3, y3, z3, 0, 0, 8);
	}
	else if (t == 5) {
		printTree(x1, y1, z1, x2, y2, z2, x3, y3, z3, 24, 0, 8);
	}

	else {
		printTree(x1, y1, z1, x2, y2, z2, x3, y3, z3, 0, 0, -12);
	
	}
	
}
void cuboid(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4, float r, float g, float b,float t=0,float tx=0,float ty=0,float tz=0) {

//	float m[16];
//	for (int i = 0; i <= 15; i++) {
//		m[i] = 0;
//	}
//	m[0] = m[5] = m[10] = 1;
//	m[7] = 1 / 70;
	if (t==1) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[1]);



		glPushMatrix();
		glScalef(6, 6, 6);

		
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); glVertex3f(x1, y1, z1);
		glTexCoord2f(1.0, 0.0); glVertex3f(x2, y2, z2);
		glTexCoord2f(1.0, 1.0); glVertex3f(x3, y3, z3);
		glTexCoord2f(0.0, 1.0); glVertex3f(x4, y4, z4);


		glEnd();

		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	else if (t == 2) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);



		glPushMatrix();
		glScalef(6, 6, 6);


		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); glVertex3f(x1, y1, z1);
		glTexCoord2f(1.0, 0.0); glVertex3f(x2, y2, z2);
		glTexCoord2f(1.0, 1.0); glVertex3f(x3, y3, z3);
		glTexCoord2f(0.0, 1.0); glVertex3f(x4, y4, z4);


		glEnd();

		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	else if (t == 3) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[3]);



		glPushMatrix();
		glScalef(6, 6, 6);


		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); glVertex3f(x1, y1, z1);
		glTexCoord2f(1.0, 0.0); glVertex3f(x2, y2, z2);
		glTexCoord2f(1.0, 1.0); glVertex3f(x3, y3, z3);
		glTexCoord2f(0.0, 1.0); glVertex3f(x4, y4, z4);


		glEnd();

		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	else if (t == 6) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[6]);



		glPushMatrix();
		glScalef(6, 6, 6);
		glTranslatef(tx, ty, tz);


		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); glVertex3f(x1, y1, z1);
		glTexCoord2f(1.0, 0.0); glVertex3f(x2, y2, z2);
		glTexCoord2f(1.0, 1.0); glVertex3f(x3, y3, z3);
		glTexCoord2f(0.0, 1.0); glVertex3f(x4, y4, z4);


		glEnd();

		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	else {
		glPushMatrix();

		glColor3f(r, g, b);

		glScalef(6, 6, 6);
		glBegin(GL_POLYGON);
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x3, y3, z3);
		glVertex3f(x4, y4, z4);
		glEnd();

		glPopMatrix();
	}
	

	

	
}

void setup(void)
{
	
	glEnable(GL_DEPTH_TEST); // Enable depth testing.

							 // Turn on OpenGL lighting.
	//glEnable(GL_LIGHTING);

	// Light property vectors.
	float lightAmb[] = { 0.0, 0.0, 0.0, 1.0 };
	float lightDifAndSpec0[] = { 1.0, 1.0, 1.0, 1.0 };
	float lightDifAndSpec1[] = { 0.0, 1.0, 0.0, 1.0 };
	float globAmb[] = { 0.2, 0.2, 0.2, 1.0 };

	// Light0 properties.
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec0);

	// Light1 properties.
	glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDifAndSpec1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lightDifAndSpec1);

	glEnable(GL_LIGHT0); // Enable particular light source.
	glEnable(GL_LIGHT1); // Enable particular light source.
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // Enable local viewpoint

														 // Create texture ids.
	glGenTextures(10, texture);

	// Load external texture. 
	loadTextures();

	// Specify how texture values combine with current surface color values.
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	// Turn on OpenGL texturing.
	//glEnable(GL_TEXTURE_2D);
														 
	
	glDisable(GL_DEPTH_TEST);
}

void drawTree(float t,float tx,float ty,float tz) {
	cuboid(-14.0, 2.9, 7.0, -10.0, 2.9, 7.0, -10.0, 2.9, 3.0, -14.0, 2.9, 3.0, 0.5, 0, 0, 6,tx,ty,tz);
	triangle(-14.0, 2.9, 7.0, -10.0, 2.9, 7.0, -12, 14.5, 5.0, 0, 0, 1,t);
	triangle(-10.0, 2.9, 7.0, -10.0, 2.9, 3.0, -12, 14.5, 5.0, 0, 0, 1,t);
	triangle(-14.0, 2.9, 7.0, -14.0, 2.9, 3.0, -12, 14.5, 5.0, 0, 0, 1,t);
	triangle(-14.0, 2.9, 3.0, -10.0, 2.9, 3.0, -12, 10.5, 5.0, 0, 0, 1,t);
	cuboid(-12.5, 0.3, 5.5, -11.5, 0.3, 5.5, -11.5, 2.9, 5.5, -12.5, 2.9, 5.5, 0.1, 0.1, 0, 6,tx,ty,tz);
	cuboid(-11.5, 0.3, 5.5, -11.5, 0.3, 4.5, -11.5, 2.9, 4.5, -11.5, 2.9, 5.5, 0.1, 0.1, 0, 6,tx,ty,tz);
	cuboid(-12.5, 0.3, 5.5, -12.5, 0.3, 4.5, -12.5, 2.9, 4.5, -12.5, 2.9, 5.5, 0.1, 0.1, 0, 6,tx,ty,tz);
	cuboid(-12.5, 0.3, 4.5, -11.5, 0.3, 4.5, -11.5, 2.9, 4.5, -12.5, 2.9, 4.5, 0.1, 0.1, 0, 6,tx,ty,tz);
}

void drawScene(void)
{
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();


	
	gluLookAt(xVal - 10 * sin((PI / 180.0) * angle),
		eyeY,
		zVal - 10 * cos((PI / 180.0) * angle),
		xVal - 11 * sin((PI / 180.0) * angle),
		eyeY,
		zVal - 11 * cos((PI / 180.0) * angle),
		0.0,
		1.0,
		0.0);

	glEnable(GL_DEPTH_TEST);


	// TEMPLE START	
	cuboid(-3.0, 0.0, 0.0, 3.0, 0.0, 0.0, 3.0, 0.0, 6.0, -3.0, 0.0, 6.0,0.5,0.5,0.5);

	cuboid(-3.0, 0.0, 0.0, 3.0, 0.0, 0.0, 3.0, 0.5, 0.0, -3.0, 0.5, 0.0, 0.0, 0.0, 1.0,3);
	cuboid(-3.0, 0.0, 6.0, 3.0, 0.0, 6.0, 3.0, 0.5, 6.0, -3.0, 0.5, 6.0, 0.0, 0.0, 1.0,3);
	cuboid(-3.0, 0.0, 0.0, -3.0, 0.5, 0.0, -3.0, 0.5, 6.0, -3.0, 0.0, 6.0, 0.0, 0.0, 1.0,3);
	cuboid(3.0, 0.0, 0.0, 3.0, 0.5, 0.0, 3.0, 0.5, 6.0, 3.0, 0.0, 6.0, 0.0, 0.0, 1.0,3);

	cuboid(-3.0, 0.5, 0.0, 3.0, 0.5, 0.0, 3.0, 0.5, 6.0, -3.0, 0.5, 6.0, 0.5, 0.5, 0.5);



	cuboid(-2.7, 0.5, 0.3, 2.7, 0.5, 0.3, 2.7, 0.5, 5.7, -2.7, 0.5, 5.7, 0.5, 0.5, 0.5);

	cuboid(-2.7, 0.5, 0.3, 2.7, 0.5, 0.3, 2.7, 1.0, 0.3, -2.7, 1.0, 0.3, 0.0, 0.0, 1.0,3);
	cuboid(-2.7, 0.5, 5.7, 2.7, 0.5, 5.7, 2.7, 1.0, 5.7, -2.7, 1.0, 5.7, 0.0, 0.0, 1.0,3);
	cuboid(-2.7, 0.5, 0.3, -2.7, 1, 0.3, -2.7, 1, 5.7, -2.7, 0.5, 5.7, 0.0, 0.0, 1.0,3);
	cuboid(2.7, 0.5, 0.3, 2.7, 1, 0.3, 2.7, 1, 5.7, 2.7, 0.5, 5.7, 0.0, 0.0, 1.0,3);

	cuboid(-2.7, 1.0, 0.3, 2.7, 1.0, 0.3, 2.7, 1.0, 5.7, -2.7, 1.0, 5.7, 0.5, 0.5, 0.5,1);



	cuboid(-2.7, 0.5, 0.3, 2.7, 0.5, 0.3, 2.7, 0.5, 5.7, -2.7, 0.5, 5.7, 0.5, 0.5, 0.5);

	cuboid(-2.7, 0.5, 0.3, 2.7, 0.5, 0.3, 2.7, 1.0, 0.3, -2.7, 1.0, 0.3, 0.0, 0.0, 1.0,3);
	cuboid(-2.7, 0.5, 5.7, 2.7, 0.5, 5.7, 2.7, 1.0, 5.7, -2.7, 1.0, 5.7, 0.0, 0.0, 1.0,3);
	cuboid(-2.7, 0.5, 0.3, -2.7, 1, 0.3, -2.7, 1, 5.7, -2.7, 0.5, 5.7, 0.0, 0.0, 1.0,3);
	cuboid(2.7, 0.5, 0.3, 2.7, 1, 0.3, 2.7, 1, 5.7, 2.7, 0.5, 5.7, 0.0, 0.0, 1.0,3);

	cuboid(-2.7, 1.0, 0.3, 2.7, 1.0, 0.3, 2.7, 1.0, 5.7, -2.7, 1.0, 5.7, 0.5, 0.5, 0.5,1);



	cuboid(-2.4, 1, 0.6, -2.1, 1, 0.6, -2.1, 5, 0.6, -2.4, 5, 0.6, 1, 0, 1,2);
	cuboid(-2.4, 1, 0.9, -2.1, 1, 0.9, -2.1, 5, 0.9, -2.4, 5, 0.9, 1, 0, 1,2);
	cuboid(-2.4, 1, 0.6, -2.4, 5, 0.6, -2.4, 5, 0.9, -2.4, 1, 0.9, 1, 0, 1,2);
	cuboid(-2.1, 1, 0.6, -2.1, 5, 0.6, -2.1, 5, 0.9, -2.1, 1, 0.9, 1, 0, 1,2);


	cuboid(2.1, 1, 0.6, 2.4, 1, 0.6, 2.4, 5, 0.6, 2.1, 5, 0.6, 1, 0, 1,2);
	cuboid(2.1, 1, 0.9, 2.4, 1, 0.9, 2.4, 5, 0.9, 2.1, 5, 0.9, 1, 0, 1,2);
	cuboid(2.1, 1, 0.6, 2.1, 5, 0.6, 2.1, 5, 0.9, 2.1, 1, 0.9, 1, 0, 1,2);
	cuboid(2.4, 1, 0.6, 2.4, 5, 0.6, 2.4, 5, 0.9, 2.4, 1, 0.9, 1, 0, 1,2);


	cuboid(-2.4, 1, 5.1, -2.1, 1, 5.1, -2.1, 5, 5.1, -2.4, 5, 5.1, 1, 0, 1,2);
	cuboid(-2.4, 1, 5.4, -2.1, 1, 5.4, -2.1, 5, 5.4, -2.4, 5, 5.4, 1, 0, 1,2);
	cuboid(-2.4, 1, 5.1, -2.4, 5, 5.1, -2.4, 5, 5.4, -2.4, 1, 5.4, 1, 0, 1,2);
	cuboid(-2.1, 1, 5.1, -2.1, 5, 5.1, -2.1, 5, 5.4, -2.1, 1, 5.4, 1, 0, 1,2);


	cuboid(2.1, 1, 5.1, 2.4, 1, 5.1, 2.4, 5, 5.1, 2.1, 5, 5.1, 1, 0, 1,2);
	cuboid(2.1, 1, 5.4, 2.4, 1, 5.4, 2.4, 5, 5.4, 2.1, 5, 5.4, 1, 0, 1,2);
	cuboid(2.1, 1, 5.1, 2.1, 5, 5.1, 2.1, 5, 5.4, 2.1, 1, 5.4, 1, 0, 1,2);
	cuboid(2.4, 1, 5.1, 2.4, 5, 5.1, 2.4, 5, 5.4, 2.4, 1, 5.4, 1, 0, 1,2);



	cuboid(-3.0, 5, 0.0, 3.0, 5, 0.0, 3.0, 5, 6.0, -3.0, 5, 6.0, 0.5, 0.5, 0.5);

	cuboid(-3.0, 5, 0.0, 3.0, 5, 0.0, 3.0, 5.5, 0.0, -3.0, 5.5, 0.0, 0.0, 0.0, 1.0,3);
	cuboid(-3.0, 5, 6.0, 3.0, 5, 6.0, 3.0, 5.5, 6.0, -3.0, 5.5, 6.0, 0.0, 0.0, 1.0,3);
	cuboid(-3.0, 5, 0.0, -3.0, 5.5, 0.0, -3.0, 5.5, 6.0, -3.0, 5.0, 6.0, 0.0, 0.0, 1.0,3);
	cuboid(3.0, 5.0, 0.0, 3.0, 5.5, 0.0, 3.0, 5.5, 6.0, 3.0, 5.0, 6.0, 0.0, 0.0, 1.0,3);

	cuboid(-3.0, 5.5, 0.0, 3.0, 5.5, 0.0, 3.0, 5.5, 6.0, -3.0, 5.5, 6.0, 0.5, 0.5, 0.5);


	//temple finish

	//tree start

	drawTree(0, 0, 0, -12);
	drawTree(1,24,0,-12);
	drawTree(2, 0, 0, -2);
	drawTree(3,24,0,-2);
	drawTree(4, 0, 0, 8);
	drawTree(5, 24, 0, 8);
	//tree finish



	//Road start
	// Activate texture object.
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	

	glPushMatrix();
	glScalef(3,3,3);

	glColor3f(0.2, 0.3, 0.2);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0); glVertex3f(-30, 0, 30);
	glTexCoord2f(1.0, 0.0);  glVertex3f(30, 0, 30);
	glTexCoord2f(1.0, 1.0); glVertex3f(30, 0, -30);
	glTexCoord2f(0.0, 1.0); glVertex3f(-30, 0, -30);


	glEnd();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glPushMatrix();
	glScalef(3, 3,3);

	glColor3f(0.2, 0.3, 0.2);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0); glVertex3f(-30, 0.1, 30);
	glTexCoord2f(1.0, 0.0); glVertex3f(-17, 0.1, 30);
	glTexCoord2f(1.0, 1.0); glVertex3f(-17, 0.1, -30);
	glTexCoord2f(0.0, 1.0); glVertex3f(-30, 0.1, -30);


	glEnd();

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	//Road end

	//pole light start
	glPushMatrix();
	glColor3f(0.5, 0, 0);
	glTranslatef(65, 30, -65);
	glScalef(1, 17, 1);
	glutSolidCube(5);


	glPopMatrix();


	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(65, 70, -65);
	glutSolidSphere(5, 15, 15);
	glPopMatrix();


	// Light position vectors.	
	float lightPos0[] = { 65, 70, -65,1.0 };
	float lightPos1[] = { 20.0, 10.0, -10.0, 1.0 };

	// Material property vectors.
	float matAmb[] = { 0.0, 0.0, 0.6, 1.0 };
	float matDif[] = { 0.0, 0.0, 0.3, 1.0 };
	float matSpec[] = { 0.6, 0.6, 0.6, 1.0 };
	float matShine[] = { 70 };
	float matEmission[] = { 0.0, 0.0, 0.5, 1.0 };

	// Draw light source spheres after disabling lighting.
	//glDisable(GL_LIGHTING);

	// Light0 and its sphere positioned.
	glPushMatrix();
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	glTranslatef(lightPos0[0], lightPos0[1], lightPos0[2]);
	glColor3f(1.0, 1.0, 1.0);
	glutWireSphere(0.05, 8, 8);
	glPopMatrix();

	// Light1 and its sphere positioned.
	glPushMatrix();
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	glTranslatef(lightPos1[0], lightPos1[1], lightPos1[2]);
	glColor3f(0.0, 1.0, 0.0);
	glutWireSphere(0.05, 8, 8);
	glPopMatrix();

//	glEnable(GL_LIGHTING);

	// Material properties of ball.
//	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
//	glMaterialfv(GL_FRONT, GL_SHININESS, matShine);
//	glMaterialfv(GL_FRONT, GL_EMISSION, matEmission);

	// Ball.
	float m[16];
	for (int i = 0; i <= 15; i++) {
		m[i] = 0;
	}
	m[0] = m[5] = m[10] = 1;
	m[7] = 1 / 70;
	glPushMatrix();
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(40, 10, 40);
	glVertex3f(44, 10, 40);
	glVertex3f(44, 10, 44);
	glVertex3f(40, 10, 44);
	glEnd();
//	glTranslatef(40.0, 20.0, 30);
//	glutSolidSphere(1.5, 200, 200);

	//glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(65, 70, -65);
	glMultMatrixf(m);
	glTranslatef(-65, -70, 65);
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(40, 2, 40);
	glVertex3f(44, 2, 40);
	glVertex3f(44, 2, 44);
	glVertex3f(40, 2, 44);
	glEnd();
//	glTranslatef(40.0, 20.0, 30);
//	glutSolidSphere(1.5, 200, 200);
	glPopMatrix();

	glPopMatrix();



	//glTranslatef(0.0, 50.0,0 ); // Move the ball.
	//glutSolidSphere(1.5, 200, 200);

	//glDisable(GL_LIGHTING);








    


	glDisable(GL_DEPTH_TEST);

	glutSwapBuffers();
}



void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 117:
		eyeY = eyeY + 0.2;
		glutPostRedisplay();
		break;
	case 100:
		eyeY = eyeY - 0.2;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

void specialKeyInput(int key, int x, int y)
{
	float tempxVal = xVal, tempzVal = zVal, tempAngle = angle;

	// Compute next position.
	if (key == GLUT_KEY_LEFT) tempAngle = angle + 5.0;
	if (key == GLUT_KEY_RIGHT) tempAngle = angle - 5.0;
	if (key == GLUT_KEY_UP)
	{
		tempxVal = xVal - sin(angle * PI / 180.0);
		tempzVal = zVal - cos(angle * PI / 180.0);
	}
	if (key == GLUT_KEY_DOWN)
	{
		tempxVal = xVal + sin(angle * PI / 180.0);
		tempzVal = zVal + cos(angle * PI / 180.0);
	}

	// Angle correction.
	if (tempAngle > 360.0) tempAngle -= 360.0;
	if (tempAngle < 0.0) tempAngle += 360.0;

	

	
		
		xVal = tempxVal;
		zVal = tempzVal;
		angle = tempAngle;
	
	
	glutPostRedisplay();
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 250.0);
	gluPerspective(60.0, (float)w/(float)h, 1.0, 900.0);
	glMatrixMode(GL_MODELVIEW);

	// Pass the size of the OpenGL window.
	width = w;
	height = h;
}

// Main routine.
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3d ground hall");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKeyInput);

	glewExperimental = GL_TRUE;
	glewInit();
	setup();

	glutMainLoop();
}
