#ifndef TP04_h
#define TP04_h

/*----------------------------------------------------------------------------------------------------*/

typedef struct Element{
    char* code_uv;
    struct Element* suivant;
}T_Element;

/*----------------------------------------------------------------------------------------------------*/

typedef struct Noeud{
    char* nom;
    char* prenom;
    T_Element* listeInscription;
    struct Noeud * filsGauche;
    struct Noeud * filsDroit;
}T_Noeud;

/*----------------------------------------------------------------------------------------------------*/

typedef T_Noeud * T_Arbre;

/*----------------------------------------------------------------------------------------------------*/


/*{
    T_Element* ajout = (T_Element*) malloc(sizeof(T_Element));
    if(ajout)
    {
        strcpy(ajout->code_uv , code);
        ajout->suivant = NULL;
    }
    else
    {
        printf("Echec de l'allocation de memoire.");
        return NULL;
    }

    T_Element* tete = liste;

    if(strcmp(tete->code_uv , code) > 0 || tete == NULL)
    //comparer la premier element 1.apres le ajout || 2.NULL
    {
        ajout->suivant = tete;
        return ajout; //changer le point tete;
    }

    while( tete->suivant != NULL && strcmp(tete->suivant->code_uv , code) < 0 )
    {
        tete = tete->suivant;
    }
    if(tete->suivant == NULL)
    {
        tete->suivant =ajout; //la nouvelle ajouter est la derniere
    }
    else
    {
        ajout->suivant = tete->suivant;
        tete->suivant = ajout;
    }

    return liste;
}*/


/*T_Arbre ajouterEtu(T_Arbre arbre, T_Noeud * ajoutetu){

    T_Noeud * tete = arbre ;
    if( comparer_Etu ( tete , ajoutetu->nom, ajoutetu->prenom) == 0 ){
            printf("l'etudiant est deja existe!!!\n");
            return arbre;
        }
    else if(comparer_Etu ( tete , ajoutetu->nom, ajoutetu->prenom) > 0 || tete == NULL)
    //comparer la premier etu 1.apres le ajout || 2.NULL
    {
        ajoutetu->suivant = tete;
        return ajoutetu; //changer le point tete;头部指针已经改变，所以不能传arbre了
    }



    while( tete->suivant != NULL && comparer_Etu ( tete , ajoutetu->nom, ajoutetu->prenom) < 0 )
    {
        tete = tete->suivant;
    }
    if(tete->suivant == NULL)
    {
        tete->suivant =ajoutetu; //la nouvelle ajouter est la derniere
    }
    else
    {
        ajoutetu->suivant = tete->suivant;
        tete->suivant = ajoutetu;
    }

    return arbre;

    }
}*/

T_Noeud * creerEtu(char * prenom , char * nom , char * code);


T_Element * ajouterInscription(T_Element* liste, char* code);

/*----------------------------------------------------------------------------------------------------*/

int comparer_Etu ( T_Noeud* etu , char* nom, char* prenom);

/*----------------------------------------------------------------------------------------------------*/

T_Noeud* chercher_Etu(T_Arbre abr, char* nom, char* prenom);

/*----------------------------------------------------------------------------------------------------*/

T_Arbre ajouterEtuRec(T_Noeud* arbre, T_Noeud* ajoutetu);



T_Arbre inscrire(T_Arbre abr, char* nom, char* prenom, char* code);


/*----------------------------------------------------------------------------------------------------*/


T_Arbre chargerFichier(T_Arbre abr, char *filename);














/*----------------------------------------------------------------------------------------------------*/

void afficherEtusInfo(T_Noeud etu);


/*----------------------------------------------------------------------------------------------------*/

void afficherInscriptions(T_Arbre abr);

/*----------------------------------------------------------------------------------------------------*/

int rechercherUVdEtus(T_Noeud etu, char *code);



/*----------------------------------------------------------------------------------------------------*/

void afficherInscriptionsUV(T_Arbre abr, char *code);


/*----------------------------------------------------------------------------------------------------*/

T_Noeud* obtenirEtu(T_Arbre abr, char *nom, char *prenom);


/*----------------------------------------------------------------------------------------------------*/

T_Noeud* obtenirMinimumEtu(T_Noeud* etu);


/*----------------------------------------------------------------------------------------------------*/

T_Noeud* obtenirParent(T_Arbre abr, char *nom, char *prenom); ///////////////////////////////////////////////////////////////


/*----------------------------------------------------------------------------------------------------*/

T_Noeud* obtenirSuccesseur(T_Noeud* etu);


/*----------------------------------------------------------------------------------------------------*/

T_Arbre supprimerInscription(T_Arbre abr, char *nom, char *prenom, char *code);


/*----------------------------------------------------------------------------------------------------*/

#endif // TP04_h
