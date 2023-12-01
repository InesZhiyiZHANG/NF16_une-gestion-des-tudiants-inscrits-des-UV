#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "TP04.h"

T_Noeud * creerEtu(char * prenom , char * nom , char * code){
    T_Noeud * ajout_etu = (T_Noeud*)malloc(sizeof(T_Noeud));
    strcpy( ajout_etu->nom , nom );
    strcpy( ajout_etu->prenom , prenom );
    ajout_etu->listeInscription = ajouterInscription(ajout_etu->listeInscription , code);
    return ajout_etu;
}

T_Element * ajouterInscription(T_Element* liste, char* code){

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

    if(tete == NULL)
        return ajout;

    while(tete->suivant != NULL){
        tete = tete->suivant;
    }
    tete->suivant = ajout;
    return liste;

}
/*----------------------------------------------------------------------------------------------------*/

int comparer_Etu ( T_Noeud* etu , char* nom, char* prenom)
{
    int prenomcmp = strcmp( etu->prenom , prenom) ;
    if (prenomcmp == 0)
        return strcmp(etu->nom , nom);
    return prenomcmp;//return 1:ajout est avant ; -1:apres
}

/*----------------------------------------------------------------------------------------------------*/

T_Noeud * chercher_Etu(T_Arbre abr, char* nom, char* prenom)
{
    if (abr == NULL || comparer_Etu(abr , nom , prenom) == 0)
        return abr;

    if ( comparer_Etu(abr , nom , prenom) < 0 )
        return chercher_Etu(abr->filsDroit , nom , prenom);
    else
        return chercher_Etu(abr->filsGauche , nom , prenom);
}

/*----------------------------------------------------------------------------------------------------*/

T_Arbre ajouterEtuRec(T_Noeud* arbre, T_Noeud* ajoutetu) {
    if (arbre == NULL) {
        return ajoutetu;
    }

    if (comparer_Etu(arbre, ajoutetu->nom, ajoutetu->prenom) == 0) {
        printf("L'etudiant existe deja!!!\n");
        return arbre;
    }

    if (comparer_Etu(arbre, ajoutetu->nom, ajoutetu->prenom) > 0) {
        ajoutetu->filsGauche = ajouterEtuRec(arbre->filsGauche, ajoutetu);
    } else {
        ajoutetu->filsDroit = ajouterEtuRec(arbre->filsDroit, ajoutetu);
    }

    return arbre;
}



T_Arbre inscrire(T_Arbre abr, char* nom, char* prenom, char* code)
{
    T_Noeud* etu = chercher_Etu(abr , nom , prenom); //pour chercher l'etudiant

    if (etu == NULL) //l’étudiant n’est pas encoreprésent dans l’ABR
    {
        //comparer le position et le etu_ajout
        etu = creerEtu(prenom , nom ,code);
        etu->listeInscription = ajouterInscription(etu->listeInscription , code);
        abr = ajouterEtu(abr , etu);

    }
    else //l’étudiant est dans l’ABR
    {
        etu->listeInscription = ajouterInscription(etu->listeInscription , code);

    }
    return abr ;
}

/*----------------------------------------------------------------------------------------------------*/


T_Arbre chargerFichier(T_Arbre abr, char *filename){
    FILE * fichier = fopen(filename , "r");

    char nom[20] , prenom[20] , code[10];
    int nbbloc , nbligne;
    if(fichier == NULL){
        perror("Erreur d'ouvrir\n");
        return abr;
    }

    char ligne[100];
    nbligne = 1;
    while(fgets(ligne , sizeof(ligne) , fichier) != NULL){

        nbbloc = sscanf(ligne , "«%[^;];%[^;];%[^»]" , prenom , nom , code);
        if(nbbloc == 3){
            T_Noeud * ajoutetu = creerEtu(prenom , nom ,code);
            //检查这个文档里要添加的同学是否存在
            if(chercher_Etu(abr, nom , prenom) == NULL){//该同学不存在
                ajouterEtuRec(abr, ajoutetu);
            }
            else{//该同学存在，所以只更新uvliste
                T_Noeud * existe_etu = chercher_Etu( abr , nom , prenom);
                ajouterInscription( existe_etu->listeInscription , code);
            }
        }
        else{
            printf("le %d eme ligne n'est pas valide!\n" , nbligne);
        }
        nbligne++;


    }
    return abr;

}













/*----------------------------------------------------------------------------------------------------*/

void afficherEtusInfo(T_Noeud etu)
{
    if(etu) //si le nœud de T_Noeud « etu » n'est pas vide
    {
        T_Element * UV = etu->listeInscriptions;
        printf("%s %s : ", etu->nom, etu->prenom)
        while(UV) //tant que le nœud de T_Element « UV » n'est pas vide
        {
            printf("%s ", UV->code_uv);
            UV = UV->suivant;
        }
    }
}

/*----------------------------------------------------------------------------------------------------*/

void afficherInscriptions(T_Arbre abr)
{
    if(abr) //si le nœud de T_Arbre « abr » n'est pas vide
    {
        afficherInscriptions(abr->filsGauche);
        afficherEtusInfo(*abr);
        afficherInscriptions(abr->filsDroit);
    }
}

/*----------------------------------------------------------------------------------------------------*/

int rechercherUVdEtus(T_Noeud etu, char *code)
{
    if(etu) //si le nœud de T_Noeud « etu » n'est pas vide
    {
        T_Element *UV = etu->listeInscriptions;
        while(UV) //tant que le nœud de T_Element « UV » n'est pas vide
        {
            if(!strcmp(UV->code_uv, code)) //si les chaînes de caractères « UV->code_uv » et « code » sont identiques
            {
                return 1;
            }
            UV = UV->suivant;
        }
        return 0;
    }
}



/*----------------------------------------------------------------------------------------------------*/

void afficherInscriptionsUV(T_Arbre abr, char *code)
{
    if(abr) //si  le nœud de T_Arbre « abr » n'est pas vide
    {
        int compteur = 0;
        afficherInscriptionsUV(abr->filsGauche);
        if(rechercherUVdEtus(*abr, code))
        {
            compteur += 1;
            printf("%s %s    ", abr->nom, abr->prenom);
            if(!(compteur %5)) //si on a imprimé cinq étudiants dans cette ligne
            {
                compteur = 0;
                printf("\n");
            }
        }
        if(compteur) //si « compteur » n'est pas vide
        {
            printf("\n");
        }
        afficherInscriptionsUV(abr->filsDroit);
    }
}

/*----------------------------------------------------------------------------------------------------*/

T_Noeud* obtenirEtu(T_Arbre abr, char *nom, char *prenom)
{
    if(abr) //si le nœud de T_Arbre « abr » n'est pas vide
    {
        rechercherEtu(abr->filsGauche);
        if(!(abs(strcmp(abr->nom, nom))+abs(strcmp(abr->prenom, prenom)))
        {
            return abr;
        }
        rechercherEtu(abr->filsDroit);
    }
}

/*----------------------------------------------------------------------------------------------------*/

T_Noeud* obtenirMinimumEtu(T_Noeud* etu)
{
    if(!etu) //si le nœud de T_Noeud « etu » n'est pas vide
    {
        while(etu->filsGauche)
        {
            etu = etu->filsGauche;
        }
    }
    return etu;
}

/*----------------------------------------------------------------------------------------------------*/

T_Noeud* obtenirParent(T_Arbre abr, char *nom, char *prenom) ///////////////////////////////////////////////////////////////
{
    if(!abr) //si le nœud de T_Arbre « abr » est vide
    {
        return NULL;
    }
    //Vérification du nœud racine
    int jugementNomGauche = strcmp(abr->filsGauche->nom, nom);
    int jugementPrenomGauche = strcmp(abr->filsGauche->prenom, prenom);
    int jugementNomDroit = strcmp(abr->filsDroit->nom, nom);
    int jugementPrenomDroit = strcmp(abr->filsDroit->prenom, prenom);
    if((jugementNomGauche == 0) && (jugementPrenomGauche == 0)) || ((jugementNomDroit == 0) && (jugementPrenomDroit == 0)))
    {
        return abr;
    }
    //Vérification récursive des sous-arbres de gauche et de droite
    T_Noeud* resultatGauche = obtenirParent(abr->filsGauche, nom, prenom);
    T_Noeud* resultatDroit = obtenirParent(abr->filsDroit, nom, prenom);
    // Renvoi du résultat des recherches dans les sous-arbres de gauche et de droite
    return (resultatGauche) ? resultatGauche : resultatDroit;
}

/*----------------------------------------------------------------------------------------------------*/

T_Noeud* obtenirSuccesseur(T_Noeud* etu)
{
    if(etu->filsDroit) //si le nœud de T_Noeud « etu » possède un fils droit
    {
        return obtenirMinimumEtu(etu->filsDroit);
    }
    T_Noeud* parent = obtenirParent(etu);
    while(parent && (etu == parent->filsDroit))
    {
        etu = parent;
        parent = obtenirParent(parent);
    }
    return parent;
}

/*----------------------------------------------------------------------------------------------------*/

T_Arbre supprimerInscription(T_Arbre abr, char *nom, char *prenom, char *code)
{
    if(abr) //si le nœud de T_Arbre « abr » n'est pas vide
    {

        T_Noeud* etu = obtenirEtu(abr, nom, prenom);
        if(etu) //si le nœud de T_Noeud « etu » n'est pas vide
        {
            T_Element* UV = etu->listeInscriptions;
            if(UV) //si le nœud de T_Element « UV » n'est pas vide
            {
                while(UV) //si  le nœud de T_Element « UV » n'est pas vide
                {
                    if(!strcmp(UV->code_uv, code)) //si  les chaînes de caractères « UV->code_uv » et « code » sont identiques
                    {
                        free(UV);
                        return abr;
                    }
                    UV = UV->suivant;
                }
            }
            else //si cet étudiant n'a plus aucune inscription
            {
                T_Arbre abr_tmp = abr;
                T_Noeud* parent = obtenirParent(etu);
                int position = -1; //-1 : « etu » n'a pas de parent //0 : « etu » est fils gauche de « parent » //1 : « etu » est fils droit de « parent »
                if(!parent) //si le nœud de T_Noeud « etu » possède un parent « parent »
                {
                     position = (parent->filsGauche == etu) ? 0 : 1;
                }
                if(!(etu->filsGauche+etu->filsDroit)) //si le nœud de T_Noeud « etu » n'a pas de fils
                {
                    if(parent->filsGauche == etu)
                    {
                        parent->filsGauche = NULL;
                    }
                    else
                    {
                        parent->filsDroit = NULL;
                    }
                    free(etu);
                }
                else if((etu->filsGauche && !etu->filsDroit) || (!etu->filsGauche && etu->filsDroit)) //si le nœud de T_Noeud « etu » n'a qu'un seul fils
                {
                    T_Noeud* fils = (etu->filsGauche) ? etu->filsGauche : etu->filsDroite;
                    if(position) //si « etu » est fils gauche de « parent »
                    {
                        parent->filsGauche = fils;
                    }
                    else //si « etu » est fils droit de « parent »
                    {
                        parent->filsDroite = fils;
                    }
                    free(etu);
                }
                else //si le nœud de T_Noeud « etu » possède deux fils
                {
                    T_Noeud* successeur = obtenirSuccesseur(etu);
                    T_Noeud* parent_successeur = obtenirParent(successeur);
                    if(parent_successeur->filsGauche == successeur)
                    {
                        parent_successeur->filsGauche = successeur->filsDroit;
                    }
                    else
                    {
                        parent_successeur->filsDroit = successeur->filsDroit;
                    }
                    etu->nom = successeur->nom;
                    etu->prenom = successeur->prenom;
                    etu->listeInscription = successeur->listeInscription;
                    free(successeur);
                }
            }
        }
    }
}

/*----------------------------------------------------------------------------------------------------*/

