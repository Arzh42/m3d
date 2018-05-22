#include "lib_surface.h"
#include "lib_scene3d.h"
#include "lib_objet3d.h"
#include "lib_3d.h"
#include "lib_2d.h"
#include "lib_mat.h"
#include<math.h>

t_scene3d* definirScene3d_etu(t_objet3d *pt_objet){
	t_scene3d * scene = (t_scene3d *) malloc(sizeof(t_scene3d));
	scene->objet = pt_objet;
	scene->pt_fils = NULL;
	scene->pt_pere = NULL;
	scene->pt_suiv = NULL;
	return scene;
};
t_scene3d* ajouter_relation_etu(t_scene3d* pt_feuille, t_objet3d *pt_objet){
	t_scene3d * newScene = definirScene3d(pt_objet);
	copier_matrice(newScene->montant,pt_feuille->descendant);
	copier_matrice(newScene->descendant,pt_feuille->pt_fils->descendant);
	newScene->pt_suiv = pt_feuille->pt_fils;
	pt_feuille->pt_fils = newScene;
	return newScene;
}; // ajout de l'objet en tete des fils
void translationScene3d_etu(t_scene3d *pt_scene, t_point3d *vecteur) {
	double trans[4][4] = {{1,0,0,vecteur->xyzt[0]},{0,1,0,vecteur->xyzt[1]},{0,0,1,vecteur->xyzt[2]},{0,0,0,1}};
	multiplication_matrice(pt_scene->descendant,pt_scene->descendant,trans);
};
void rotationScene3d_etu(t_scene3d *pt_scene, t_point3d *centre, float degreX, float degreY, float degreZ){
	double rotX[4][4] = {{1,0,0,0},{0,cos(degreX),-1*sin(degreX),0},{0,sin(degreX),cos(degreX),0},{0,0,0,0}};
	double rotY[4][4] = {{cos(degreY),0,sin(degreY),0},{0,1,0,0},{-1*sin(degreY),0,cos(degreY),0},{0,0,0,0}};
	double rotZ[4][4] = {{cos(degreZ),-1*sin(degreZ),0,0},{sin(degreZ),cos(degreZ),0,0},{0,0,0,0}};
	multiplication_matrice(pt_scene->descendant,pt_scene->descendant,rotX);
	multiplication_matrice(pt_scene->descendant,pt_scene->descendant,rotY);
	multiplication_matrice(pt_scene->descendant,pt_scene->descendant,rotZ);
};
void dessinerScene3d_etu(t_surface *surface, t_scene3d* pt_scene){

};
void changerCamera_etu(t_scene3d *pt_objet){

}; // modifie l'arbre de la scene pour que pt_objet en soit la racine, pt_racine ne veut plus rien dire

