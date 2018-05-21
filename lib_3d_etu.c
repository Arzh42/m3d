#include "lib_surface.h"
#include "lib_3d.h"
#include "lib_2d.h"
#include "lib_mat.h"
#include <math.h>




t_point3d *definirPoint3d_etu(double x, double y, double z)	// attention malloc
{
	t_point3d *p;

	p  = (t_point3d*) malloc(sizeof(t_point3d));
	if (p!=NULL)
	{
		p->xyzt[0] = x;
		p->xyzt[1] = y;
		p->xyzt[2] = z;
		p->xyzt[3] = 1;
	}

	return p;
}


t_point3d *definirVecteur3d_etu(double x, double y, double z)
{
	t_point3d *p;

	p  = (t_point3d*) malloc(sizeof(t_point3d));
	if (p!=NULL)
	{
		p->xyzt[0] = x;
		p->xyzt[1] = y;
		p->xyzt[2] = z;
		p->xyzt[3] = 0;
	}

	return p;
}
t_point3d *copierPoint3d_etu(t_point3d *t) {
	return definirPoint3d_etu(t->xyzt[0],t->xyzt[1],t->xyzt[2]);
};

t_triangle3d *definirTriangle3d_etu(t_point3d * a, t_point3d * b, t_point3d * c){
	t_triangle3d *p;

	p  = (t_triangle3d*) malloc(sizeof(t_triangle3d));
	if (p!=NULL)
	{
		p->abc[0] = a;
		p->abc[1] = b;
		p->abc[2] = c;
	}

	return p;
};
t_triangle3d *copierTriangle3d_etu(t_triangle3d *t){
	if (t==NULL) {
		printf("erruer copy\n");
	}
	return definirTriangle3d_etu(
		copierPoint3d_etu(t->abc[0]),
		copierPoint3d_etu(t->abc[1]),
		copierPoint3d_etu(t->abc[2]));
};
void differenceVecteur3d_etu(t_point3d *v1, t_point3d *v2){
	v1->xyzt[0] = v1->xyzt[0]-v2->xyzt[0];
	v1->xyzt[1] = v1->xyzt[1]-v2->xyzt[1];
	v1->xyzt[2] = v1->xyzt[2]-v2->xyzt[2];
}; //v1 = v1-v2
void sommeVecteur3d_etu(t_point3d *v1, t_point3d *v2){
	v1->xyzt[0] = v1->xyzt[0]+v2->xyzt[0];
	v1->xyzt[1] = v1->xyzt[1]+v2->xyzt[1];
	v1->xyzt[2] = v1->xyzt[2]+v2->xyzt[2];
}; //v1 = v1+v2
void divisionVecteur3d_etu(t_point3d *v1, int n){
	v1->xyzt[0] = v1->xyzt[0]/n;
	v1->xyzt[1] = v1->xyzt[1]/n;
	v1->xyzt[2] = v1->xyzt[2]/n;
}; //v1 = v1/n
t_point3d* centreGraviteTriangle3d_etu(t_triangle3d *t){
	return definirPoint3d_etu(
		(t->abc[0]->xyzt[0]+t->abc[1]->xyzt[0]+t->abc[2]->xyzt[0])/3,
		(t->abc[0]->xyzt[1]+t->abc[1]->xyzt[1]+t->abc[2]->xyzt[1])/3,
		(t->abc[0]->xyzt[2]+t->abc[1]->xyzt[2]+t->abc[2]->xyzt[2])/3
		);
};

double zmoyen_etu(t_triangle3d *t){
	return (t->abc[0]->xyzt[2]+t->abc[1]->xyzt[2]+t->abc[2]->xyzt[2])/3;
};
void remplirTriangle3d_etu(t_surface * surface, t_triangle3d * triangle, Uint32 c, double l, double h, double d){
	t_triangle2d * triangle2d;
	t_point3d * tmp;
	t_point2d * pa;
	t_point2d * pb;
	t_point2d * pc;
	double x;
	double y;
	double sx = surface->x;
	double sy = surface->y;
	double dz;
	double ratio = (double)(surface->x)/(double)(surface->y);
	tmp = triangle->abc[0];
	dz = (tmp->xyzt[2]);
	x = (tmp->xyzt[0])*d/(dz);
	y = surface->y-(tmp->xyzt[1])*d/(dz);
	pa = definirPoint2d(x,y);


	tmp = triangle->abc[1];
	dz = (tmp->xyzt[2]);
	x = (tmp->xyzt[0])*d/(dz);
	y = surface->y-(tmp->xyzt[1])*d/(dz);
	pb = definirPoint2d(x,y);


	tmp = triangle->abc[2];
	dz = (tmp->xyzt[2]);
	x = (tmp->xyzt[0])*d/(dz);
	y = surface->y-(tmp->xyzt[1])*d/(dz);
	pc = definirPoint2d(x,y);


	triangle2d = definirTriangle2d(pa,pb,pc);
	remplirTriangle2d(surface,triangle2d,c);
};

void translationTriangle3d_etu(t_triangle3d *t, t_point3d *vecteur){
	double trans[4][4] = {{1,0,0,vecteur->xyzt[0]},{0,1,0,vecteur->xyzt[1]},{0,0,1,vecteur->xyzt[2]},{0,0,0,0}};
	transformationTriangle3d(t,trans);
};
void rotationTriangle3d_etu(t_triangle3d *t, t_point3d *centre, float degreX, float degreY, float degreZ){
	double rotX[4][4] = {{1,0,0,0},{0,cos(degreX),-1*sin(degreX),0},{0,sin(degreX),cos(degreX),0},{0,0,0,0}};
	double rotY[4][4] = {{cos(degreY),0,sin(degreY),0},{0,1,0,0},{-1*sin(degreY),0,cos(degreY),0},{0,0,0,0}};
	double rotZ[4][4] = {{cos(degreZ),-1*sin(degreZ),0,0},{sin(degreZ),cos(degreZ),0,0},{0,0,0,0}};
	translationTriangle3d_etu(t,centre);
	transformationTriangle3d_etu(t,rotX);
	transformationTriangle3d_etu(t,rotY);
	transformationTriangle3d_etu(t,rotZ);
};



void __copierPoint3d_etu(t_point3d * src, t_point3d * dest)
{
	
	memcpy(dest->xyzt, src->xyzt, 4*sizeof(double));
}



void transformationTriangle3d_etu(t_triangle3d *t, double mat[4][4])
{
	t_point3d *p3dtmp;
	int i;
	if (t!=NULL&&t->abc!=NULL) {
		p3dtmp = (t_point3d*)malloc(sizeof(t_point3d));
		if (p3dtmp!=NULL)
		{
			for(i=0; i<3; i++)
			{
				multiplication_vecteur(p3dtmp, mat, t->abc[i]);
				__copierPoint3d_etu(p3dtmp, t->abc[i]);

			}
		}

		free(p3dtmp);
		
	}

}