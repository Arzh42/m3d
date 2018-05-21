#include "lib_surface.h"
#include "lib_scene3d.h"
#include "lib_objet3d.h"
#include "lib_3d.h"
#include "lib_2d.h"
#include "lib_mat.h"

t_scene3d* definirScene3d_etu(t_objet3d *pt_objet){
	t_scene3d * scene = (t_scene3d *) malloc(sizeof(t_scene3d));
	scene->objet = pt_objet;
	return scene;
};
t_scene3d* ajouter_relation_etu(t_scene3d* pt_feuille, t_objet3d *pt_objet){
	t_scene3d * newScene = definirScene3d_etu(pt_objet);
	newScene->pt_fils = pt_feuille;
	return newScene;
}; // ajout de l'objet en tete des fils
void translationScene3d_etu(t_scene3d *pt_scene, t_point3d *vecteur) {

};
void rotationScene3d_etu(t_scene3d *pt_scene, t_point3d *centre, float degreX, float degreY, float degreZ){

};
void dessinerScene3d_etu(t_surface *surface, t_scene3d* pt_scene){

};
void changerCamera_etu(t_scene3d *pt_objet){

}; // modifie l'arbre de la scene pour que pt_objet en soit la racine, pt_racine ne veut plus rien dire

