#ifndef TP04_h
#define TP04_h

/*----------------------------------------------------------------------------------------------------*/

typedef struct Element{
    char* code_uv;
    struct Element* suivant;
}T_Element;

/*----------------------------------------------------------------------------------------------------*/

typedef struct Noeud{
    char * nom;
    char * prenom;
    T_Element * listeInscriptions;
    struct Noeud * filsGauche;
    struct Noeud * filsDroit;
}T_Noeud;

/*----------------------------------------------------------------------------------------------------*/

typedef T_Noeud * T_Arbre;

/*----------------------------------------------------------------------------------------------------*/


void convertmaj(char * str);

T_Noeud * creerEtu(char * prenom , char * nom , char * code);

T_Element * ajouterInscription(char * nom , char * prenom ,T_Element* liste, char* code);


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

void afficherEtuInfo(T_Noeud* etu);

/*----------------------------------------------------------------------------------------------------*/

void afficherInscriptions(T_Arbre abr);

/*----------------------------------------------------------------------------------------------------*/

int calcul_nb_liste(T_Noeud* etu, T_Element** liste);
int rechercherUVdEtus(T_Noeud* etu, char *code);

/*----------------------------------------------------------------------------------------------------*/

void afficherInscriptionsUV(T_Arbre abr, char *code, char* p_indicateur);

/*----------------------------------------------------------------------------------------------------*/

T_Noeud* obtenirEtu(T_Arbre abr, char *nom, char *prenom);

/*----------------------------------------------------------------------------------------------------*/

T_Noeud* obtenirMinimumEtu(T_Noeud* etu);

/*----------------------------------------------------------------------------------------------------*/

T_Noeud* obtenirParent(T_Arbre abr, char *nom, char *prenom);

/*----------------------------------------------------------------------------------------------------*/

T_Noeud* obtenirSuccesseur(T_Arbre abr, T_Noeud* etu);

/*----------------------------------------------------------------------------------------------------*/

T_Arbre supprimerInscription(T_Arbre abr, char *nom, char *prenom, char *code, char* p_indicateur);

/*----------------------------------------------------------------------------------------------------*/

T_Arbre supprimerTousLesInscriptions(T_Arbre abr, char* nom, char* prenom);

/*----------------------------------------------------------------------------------------------------*/

T_Arbre libererArbre(T_Arbre abr);

/*----------------------------------------------------------------------------------------------------*/

void viderBuffer();

/*----------------------------------------------------------------------------------------------------*/

#endif // TP04_h
