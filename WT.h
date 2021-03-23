/******************************************************************************/
/* WT.H                                                                       */
/******************************************************************************/

#ifndef WT_H
#define WT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "LC.h"

#define DEBUG_WT 0



/******************************************************************************/
/* STRUCTURES                                                                 */
/******************************************************************************/
typedef struct noeud {
    struct noeud *fils[4];
	int tab[5];
    //char term;
    } Noeud;





/******************************************************************************/
/* PROTOTYPES                                                                 */
/******************************************************************************/
/* Crée un nouveau noeud                                                      */
Noeud *nouveauNoeud();
/* Ajoute un mot dans l'arbre                                                 */
void ajouteMotArbre(Noeud *racine,char *str,int seq);
/* Cherche un mot dans l'arbre                                                */
int chercheMotArbre(Noeud *racine,char *str);

char *chercheMotCommmun(Noeud *racine, char *mot, int prof);


#endif

