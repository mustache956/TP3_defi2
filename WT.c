/******************************************************************************/
/* WT.C                                                                       */
/******************************************************************************/

#include "WT.h"

static int ref[26] = {0,-1,1,-1,-1,-1,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3,-1,-1,-1,-1,-1,-1};
static int ref2[4] = {0,2,6,19};

/******************************************************************************/
/* nouveauNoeud                                                               */
/******************************************************************************/
Noeud *nouveauNoeud()
{
    Noeud * n = (Noeud *) malloc(sizeof(Noeud));
    int i;

    for(i=0;i!=4;i++)
        n->fils[i] = NULL;
        
    for(i=0;i<5;i++) {
    	n->tab[i] = 0;
    }
    
    //n->term = 0;

    return n;
}




/******************************************************************************/
/* ajouteMotArbre                                                             */
/******************************************************************************/
void ajouteMotArbre(Noeud *racine,char *str,int seq)
{

	racine->tab[seq] = 1;
	
	if (str[1] == '\0'){
		//racine->term = 1;
		return;
  	}

	
	
	if (racine->fils[ref[str[0]-'A']] == NULL)
	  	racine->fils[ref[str[0]-'A']] = nouveauNoeud();
	

	ajouteMotArbre(racine->fils[ref[str[0]-'A']], str+1, seq);
  	return ;
}



/******************************************************************************/
/* chercheMotArbre                                                            */
/******************************************************************************/
int chercheMotArbre(Noeud *racine,char *str)
{
	if (str[1] == '\0'){
		for (int i = 0; i < 5; i++) {
				if (racine->tab[i] != 1) {
					return 0;
				}
			}
		return 1;
		/*if (racine->term == 1)
			return 1;
		else 
			return 0;*/
	}
	else{
		if (racine->fils[ref[str[0]-'A']] != NULL) {
			return chercheMotArbre(racine->fils[ref[str[0]-'A']], str+1);
		}
		else
			return 0;
  	}
}


/*char *chercheMotCommmun (Noeud *racine, char* mot, int prof) {
	
	int sum = 0;
	
	if (prof == 5)
		return mot;
	
	for (int i = 0; i < 5; i++) {
		if (racine->fils[ref[str[0]-'A']]->tab[i] == 1) {
			sum++;
		}
	}
	
	
	if (sum == 5) {
		mot[prof] = 
		for (int i = 0; i < 4; i++) {
			chercheMotCommun(racine, mot, prof+1);
		}
	}

}*/



























