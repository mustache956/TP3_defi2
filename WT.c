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
	
	if (str[0] == '\0'){
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


char *chercheMotCommun (Noeud *racine, char* mot, int prof) {

	int sum = 0;
	

	
	for (int i = 0; i < 5; i++) {
		if (racine->tab[i] == 1) {
			sum++;
		}
	}
	
	
	
	if (sum == 5) {
		for (int i = 0; i < 4; i++) {
			if(racine->fils[i] != NULL) {
				mot[prof] = ref2[i]+'A';
        
				//printf("%d     ", ref2[i]);
				//printf("%c     ", ref2[i]+ 'A');
				//printf("mot = %s\n", mot);

				chercheMotCommun(racine->fils[i], mot, prof+1);
				mot[prof] = '\0';
			}
		}
	}
  else
    return NULL;

  if (prof == 5)
	  printf("le mot est %s\n", mot);
  else   
		//printf("le mot est pas bon %s\n", mot);
  
	return NULL;

}

void commun(Noeud *racine) {
  //printf("ai");
	char mot[6] = "";
	chercheMotCommun(racine, mot, 0);
	return;

}

























