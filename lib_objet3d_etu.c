#include "lib_surface.h"
#include "lib_objet3d.h"
#include "lib_3d.h"
#include "lib_2d.h"
#include "lib_mat.h"

t_objet3d* objet_vide_etu(){
	t_objet3d * objet = (t_objet3d *) malloc(sizeof(t_objet3d));
	if (objet!=NULL) {
		objet->est_trie = false;
		objet->est_camera = false;
		objet->largeur = 0;
		objet->hauteur = 0;
		objet->proche = 0;
		objet->loin = 0;
		objet->distance_ecran = 0;
	}
	else {
		printf("erreur création objet\n");
	}

	return objet;
};
t_objet3d *camera_etu(double l, double h, double n, double f, double d){
	t_objet3d * objet = objet_vide();
	objet->est_camera = true;
	objet->largeur = l;
	objet->hauteur = h;
	objet->proche = n;
	objet->loin = f;
	objet->distance_ecran = d;
	return objet;
}; // zone l*h dans le champ n->f
t_objet3d* parallelepipede_etu(double lx, double ly, double lz){
	t_point3d * point1 = definirPoint3d(0,0,0);
	t_point3d * point2 = definirPoint3d(lx,0,0);
	t_point3d * point3 = definirPoint3d(lx,ly,0);
	t_point3d * point4 = definirPoint3d(0,ly,0);
	t_point3d * point5 = definirPoint3d(0,0,lz);
	t_point3d * point6 = definirPoint3d(lx,0,lz);
	t_point3d * point7 = definirPoint3d(lx,ly,lz);
	t_point3d * point8 = definirPoint3d(0,ly,lz);
	t_maillon * maillon1 = malloc(sizeof(t_maillon));
	maillon1->face = definirTriangle3d(point1,point2,point3);
	maillon1->couleur = BLANC;
	maillon1->pt_suiv = (t_maillon *) malloc(sizeof(t_maillon));
	t_maillon * maillon2 = malloc(sizeof(t_maillon));
	maillon2->face = definirTriangle3d(point1,point3,point4);
	maillon2->couleur = NOIR;
	maillon2->pt_suiv = maillon1;
	t_maillon * maillon3 = malloc(sizeof(t_maillon));
	maillon3->couleur = BLANC;
	maillon3->face = definirTriangle3d(point1,point4,point5);
	maillon3->pt_suiv = maillon2;
	t_maillon * maillon4 = malloc(sizeof(t_maillon));
	maillon4->couleur = NOIR;
	maillon4->face = definirTriangle3d(point1,point5,point2);
	maillon4->pt_suiv = maillon3;
	t_maillon * maillon5 = malloc(sizeof(t_maillon));
	maillon5->couleur = BLANC;
	maillon5->face = definirTriangle3d(point1,point2,point3);
	maillon5->pt_suiv = maillon4;
	t_maillon * maillon6 = malloc(sizeof(t_maillon));
	maillon6->couleur = NOIR;
	maillon6->face = definirTriangle3d(point2,point5,point6);
	maillon6->pt_suiv = maillon5;
	t_maillon * maillon7 = malloc(sizeof(t_maillon));
	maillon7->couleur = BLANC;
	maillon7->face = definirTriangle3d(point2,point6,point7);
	maillon7->pt_suiv = maillon6;
	t_maillon * maillon8 = malloc(sizeof(t_maillon));
	maillon8->couleur = NOIR;
	maillon8->face = definirTriangle3d(point2,point7,point3);
	maillon8->pt_suiv = maillon7;
	t_maillon * maillon9 = malloc(sizeof(t_maillon));
	maillon9->couleur = BLANC;
	maillon9->face = definirTriangle3d(point7,point5,point6);
	maillon9->pt_suiv = maillon8;
	t_maillon * maillon10 = malloc(sizeof(t_maillon));
	maillon10->couleur = NOIR;
	maillon10->face = definirTriangle3d(point7,point5,point8);
	maillon10->pt_suiv = maillon9;
	
	t_maillon * maillon11 = malloc(sizeof(t_maillon));
	maillon11->couleur = BLANC;
	maillon11->face = definirTriangle3d(point7,point8,point4);
	maillon11->pt_suiv = maillon10;
	
	t_maillon * maillon12 = malloc(sizeof(t_maillon));
	maillon12->couleur = NOIR;
	maillon12->face = definirTriangle3d(point8,point5,point4);
	maillon12->pt_suiv = maillon11;
	
	t_objet3d * objet = objet_vide();
	objet->tete = maillon12;
	free(point1);
	free(point2);
	free(point3);
	free(point4);
	free(point5);
	free(point6);
	free(point7);
	free(point8);
	return objet;
};
t_objet3d* sphere_etu(double r, double nlat, double nlong){return NULL;};
t_objet3d* sphere_amiga_etu(double r, double nlat, double nlong){return NULL;};
t_objet3d* arbre_etu(double lx, double ly, double lz){
	t_objet3d * parra = parallelepipede(lx,ly,5*lz/6);
	t_point3d * point1 = definirPoint3d(0,0,5*lz/6);
	t_point3d * point2 = definirPoint3d(0,ly,5*lz/6);
	t_point3d * point3 = definirPoint3d(lx,0,5*lz/6);
	t_point3d * point4 = definirPoint3d(lx,ly,5*lz/6);
	t_point3d * point5 = definirPoint3d(lx,ly,lz);
	t_maillon * maillon1 = malloc(sizeof(t_maillon));
	t_maillon * maillon2 = malloc(sizeof(t_maillon));
	t_maillon * maillon3 = malloc(sizeof(t_maillon));
	t_maillon * maillon4 = malloc(sizeof(t_maillon));
	t_objet3d * objet = objet_vide();
	maillon1->face = definirTriangle3d(point1,point2,point5);
	maillon1->pt_suiv = NULL;
	maillon2->face = definirTriangle3d(point2,point3,point5);
	maillon2->pt_suiv = maillon1;
	maillon3->face = definirTriangle3d(point3,point4,point5);
	maillon3->pt_suiv = maillon2;
	maillon4->face = definirTriangle3d(point4,point1,point5);
	maillon4->pt_suiv = maillon3;
	objet->tete = maillon4;
	composerObjet3d(objet,parra);
	return objet;
};
t_objet3d* damier_etu(double lx, double lz, double nx, double nz){
	return NULL;
};
t_objet3d *copierObjet3d_etu(t_objet3d *o){
	t_objet3d * objet = objet_vide();
	t_maillon * maillon = o->tete; //on travaille sur maillon
	t_maillon * previous_maillon = NULL; //Maillon construit précédement
	t_maillon * new_maillon = NULL; //Le nouveau maillon créé
	while (maillon!=NULL) {

		new_maillon = (t_maillon *) malloc(sizeof(t_maillon));
		new_maillon->couleur = maillon->couleur;
		if (maillon->face!=NULL) {
			new_maillon->face = copierTriangle3d(maillon->face);
		}
		new_maillon->pt_suiv = previous_maillon;
		previous_maillon = new_maillon;
		maillon = maillon->pt_suiv;
	
	}
	objet->tete = new_maillon;
	objet->est_trie = o->est_trie;
	objet->est_camera = o->est_camera;
	objet->largeur = o->largeur;
	objet->hauteur = o->hauteur;
	objet->proche = o->proche;
	objet->loin = o->loin;
	objet->distance_ecran = o->distance_ecran;
	return objet;
}; // attention, effectue une copie mirroir
void composerObjet3d_etu(t_objet3d* o, t_objet3d* o2){
	t_maillon * maillon = o->tete;
	t_maillon * previous_maillon = NULL;
	//On cherche la fin de la liste de l'objet 1
	while (maillon!=NULL) {
		previous_maillon = maillon;
		maillon = maillon->pt_suiv;
	}
	//Quand on l'a trouvé on fait pointer vers la tête de la liste de l'objet 2;
	previous_maillon->pt_suiv = o2->tete;
	o2->tete = NULL;
	free(o2);
};
void composerObjet3d_limite_en_z_etu(t_objet3d* o, t_objet3d* o2, t_objet3d *camera){
	t_maillon * maillon = o->tete;
	t_maillon * previous_maillon = NULL;
	//On cherche la fin de la liste de l'objet 1
	while (maillon!=NULL) {
		previous_maillon = maillon;
		maillon = maillon->pt_suiv;
	}
	//Quand on l'a trouvé on fait pointer vers la tête de la liste de l'objet 2;
	previous_maillon->pt_suiv = o2->tete;
	o2->tete = NULL;
	free(o2);
};
void libererObjet3d_etu(t_objet3d *o){
	if (o!=NULL) {
		t_maillon * maillon = o->tete;
		t_maillon * previous_maillon = NULL;
		while (maillon!=NULL) {
			previous_maillon = maillon;
			maillon = maillon->pt_suiv;
			free(previous_maillon);
		}
		free(o);	
	}
	
};
t_point3d *centreGraviteObjet3d_etu(t_objet3d *o){
	t_maillon * maillon = o->tete;
	int sommeX = 0;
	int sommeY = 0;
	int sommeZ = 0;
	int compteur = 0;
	t_point3d* point = NULL;
	while (maillon!=NULL) {
		point = centreGraviteTriangle3d_etu(maillon->face);
		sommeX += point->xyzt[0];
		sommeY += point->xyzt[1];
		sommeZ += point->xyzt[2];
		compteur += 1;
		maillon = maillon->pt_suiv;
	}
	point = definirPoint3d(sommeX/compteur,sommeY/compteur,sommeZ/compteur);
	return point;
};
void dessinerObjet3d_etu(t_surface *surface, t_objet3d* pt_objet, t_objet3d *camera){
	t_maillon * maillon = pt_objet->tete;
	while (maillon!=NULL) {
		remplirTriangle3d(surface,maillon->face,maillon->couleur,camera->largeur,camera->hauteur,camera->distance_ecran);
		maillon = maillon->pt_suiv;
	}
};

void translationObjet3d_etu(t_objet3d* pt_objet, t_point3d *vecteur){
	t_maillon * maillon = pt_objet->tete;
	while (maillon!=NULL) {
		translationTriangle3d(maillon->face,vecteur);
		maillon = maillon->pt_suiv;
	}
};
void translationObjet3d_fast_etu(t_objet3d* pt_objet, t_point3d *vecteur){};
void rotationObjet3d_etu(t_objet3d* pt_objet, t_point3d *centre, float degreX, float degreY, float degreZ){
	t_maillon * maillon = pt_objet->tete;
	while (maillon!=NULL) {
		rotationTriangle3d(maillon->face,centre,degreX,degreY,degreZ);
		maillon = maillon->pt_suiv;
	}
};
void rotationObjet3d_fast_etu(t_objet3d* pt_objet, t_point3d *centre, float degreX, float degreY, float degreZ){};
void transformationObjet3d_etu(t_objet3d* pt_objet, double mat[4][4])
{
	t_maillon* o = pt_objet->tete;
	while (o!=NULL)
	{
		if (o->face!=NULL) {
			transformationTriangle3d(o->face, mat);	
		}
		o = o->pt_suiv;
	}
	pt_objet->est_trie = false;

}