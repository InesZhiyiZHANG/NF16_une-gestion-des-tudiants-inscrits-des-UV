#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP04.h"

int main()
{
    T_Arbre abr = NULL; // Initialiser un arbre vide
    T_Noeud* etu = NULL; // Initialiser un etudiant vide
    char indicateur = 0;
    char* p_indicateur = &indicateur;

    char choix = '0';
    while (choix != '6')
    {
        printf("\n============================================================");
        printf("\n1. Inscrire un etudiant a une UV");
        printf("\n2. Charger un fichier d'inscriptions");
        printf("\n3. Afficher tous les etudiants");
        printf("\n4. Afficher les inscrits a une UV");
        printf("\n5. Supprimer une inscription");
        printf("\n6. Quitter");
        printf("\n============================================================");
        printf("\nVotre choix ? ");
        choix = getchar();

        switch (choix)
        {
            case '1':
            {
                char* nom[50], prenom[50], code[6];
                printf("\n> Entrez le nom et le prenom de l'etudiant(e) et puis l'UV a inscrire : ");
                scanf("%s %s %s", nom, prenom, code);
                convertmaj(nom);
                convertmaj(prenom);
                convertmaj(code);
                abr = inscrire(abr, nom, prenom, code);
                if(abr) //si le nœud de T_Arbre « abr » n'est pas vide
                    printf("> Inscription reussie de [%s %s] a la UV [%s].\n\n\n\n", nom, prenom, code);
                else
                    printf("> Echec de l'inscription.\n\n\n\n");
                break;
            }
            case '2':
            {
                char* fichier[100];
                printf("\n> Saisissez le nom du fichier : ");
                scanf("%s", fichier);
                abr = chargerFichier(abr, fichier);
                printf("\n\n\n");
                break;
            }
            case '3':
            {
                printf("\n> %-8s %-8s     %-8s\n\n", "NOM", "PRENOM", "CODE DE UV");
                if(abr) //si le nœud de T_Arbre « abr » n'est pas vide
                    afficherInscriptions(abr);
                else
                    printf("  %-8s %-8s     %-8s\n", "*VIDE*", "*VIDE*", "*VIDE*");
                printf("\n\n\n");
                break;
            }
            case '4':
            {
                if(abr) //si le nœud de T_Arbre « abr » n'est pas vide
                {
                    char* code[6];
                    printf("\n> Saisissez le code d'UV : ");
                    scanf("%s", code);
                    printf("\n");
                    convertmaj(code);
                    indicateur = 0; //Enregistrer si il y a des étudiants inscrits à cette UV
                    afficherInscriptionsUV(abr, code, p_indicateur);
                    if(!indicateur) //Si il n'y a pas d'étudiants inscrits à cette UV
                    {
                        printf("> Il n'y a pas d'etudiants inscrits a cette UV.\n");
                        indicateur = 0; //Réinitialisation de l'indicateur
                    }
                    printf("\n\n\n");
                }
                else
                    printf("\n> Aucun resultat.\n\n\n\n");
                break;
            }
            case '5':
            {
                if(abr) //si le nœud de T_Arbre « abr » n'est pas vide
                {
                    char* nom[50], prenom[50], code[6];
                    printf("\n> Entrez le nom et le prenom de l'etudiant(e) et puis l'UV a Supprimer : ");
                    scanf("%s %s %s", nom, prenom, code);
                    convertmaj(nom);
                    convertmaj(prenom);
                    convertmaj(code);
                    etu = chercher_Etu(abr, nom, prenom);
                    if(etu) //si le nœud de T_Noeud « etu » n'est pas vide
                    {
                        indicateur = 0; //Enregistrez si l'étudiant est inscrit à cette UV
                        abr = supprimerInscription(abr, nom, prenom, code, p_indicateur);
                        if(!indicateur) //L'étudiant n'est pas inscrit à cette UV
                        {
                            printf("> [%s %s] n'est pas inscrit a la UV [%s].\n\n\n\n", nom, prenom, code);
                            indicateur = 0; //Réinitialisation de l'indicateur
                        }
                        else
                            printf("> Suppression reussie de [%s %s] de la UV [%s].\n\n\n\n", nom, prenom, code);
                    }
                    else
                        printf("> Aucune trace de l'etudiant nomme %s %s.\n\n\n\n", nom, prenom);
                }
                else
                    printf("\n> Echec de la suppression.\n\n\n\n");
                break;
            }
            case '6':
            {
                if(abr) //si le nœud de T_Arbre « abr » n'est pas vide
                    abr = libererArbre(abr);
                printf("\n> La memoire allouee dynamiquement a ete liberee avec succes.\n\n\n\n");
                break;
            }
            default: printf("\nERREUR : Votre choix est invalide !\n\n\n\n");
        }
        viderBuffer();
    }

/***************************************************************/
   /* 测试添加liste
   T_Element *liste = NULL;

    liste = ajouterInscription(liste, "CSE101");
    liste = ajouterInscription(liste, "MAT201");
    liste = ajouterInscription(liste, "PHY301");
    liste = ajouterInscription(liste, "CSE101");  // 重复的 UV

    // 打印列表内容
    T_Element *courant = liste;
    while (courant != NULL) {
        printf("%s ", courant->code_uv);
        courant = courant->suivant;
    }

    // 释放列表内存
    courant = liste;
    while (courant != NULL) {
        T_Element *temp = courant;
        courant = courant->suivant;
        free(temp);
    }*/

//*********************************************************************//

//    // 输出单个学生信息（测试函数[afficherEtuInfo]）
//    printf("--------------------------------------------------\n\n");
//    printf("[FONCTION afficherEtuInfo]\n\n");
//    etu = chercher_Etu(abr, "Johnson", "Alice");
//    afficherEtuInfo(etu);
//    printf("\n");

//    //查看学生是否注册了某一课程（测试函数[rechercherUVdEtu]）
//    printf("\n\n--------------------------------------------------\n\n");
//    printf("[FONCTION rechercherUVdEtu]\n\n");
//    etu = chercher_Etu(abr, "Martin", "Jacques");
//    printf("Martin Jacques est inscrit a HIT102 ? [%d]\n", rechercherUVdEtu(etu, "HIT102"));
//    printf("Martin Jacques est inscrit a MCH102 ? [%d]\n", rechercherUVdEtu(etu,  "MCH102"));

//    //查看注册了某一课程的所有学生（测试函数[afficherInscriptionsUV]）
//    printf("\n\n--------------------------------------------------\n\n");
//    printf("[FONCTION afficherInscriptionsUV]\n\n");
//    printf("Etudiants inscrits à BIO501 : \n");
//    afficherInscriptionsUV(abr, "BIO501");
//    printf("\nEtudiants inscrits à ZZZ999 : \n");
//    afficherInscriptionsUV(abr, "ZZZ999");

//    //查看姓名按字母排序最靠前的学生（测试函数[obtenirMinimumEtu]）
//    printf("\n\n--------------------------------------------------\n\n");
//    printf("[FONCTION obtenirMinimumEtu]\n\n");
//    etu = obtenirMinimumEtu(abr);
//    printf("Etu minimum : %s %s\n", etu->nom, etu->prenom);

//    //查看某学生节点的父节点（测试函数[obtenirParent]）
//    printf("\n\n--------------------------------------------------\n\n");
//    printf("[FONCTION obtenirParent]\n\n");
//    printf("- - - - - - - - - - - - - - - - - - - - \n\n");
//    printf("Noeud parent de Doe John : ");
//    etu = obtenirParent(abr, "Doe", "John");
//    if(etu)
//        printf("%s %s\n\n", etu->nom, etu->prenom);
//    else
//        printf("Adresse du parent : %p\n\n", etu);
//    printf("- - - - - - - - - - - - - - - - - - - - \n\n");
//    printf("Noeud parent de Bott Emmy : ");
//    etu = obtenirParent(abr, "Bott", "Emmy");
//    if(etu)
//        printf("%s %s\n\n", etu->nom, etu->prenom);
//    else
//        printf("Adresse du parent : %p\n\n", etu);
//    printf("- - - - - - - - - - - - - - - - - - - - \n\n");
//    printf("Noeud parent de Fac Kittel : ");
//    etu = obtenirParent(abr, "Fac", "Kittel");
//    if(etu)
//        printf("%s %s\n\n", etu->nom, etu->prenom);
//    else
//        printf("Adresse du parent : %p\n\n", etu);
//    printf("- - - - - - - - - - - - - - - - - - - - \n\n");
//    printf("Noeud parent de ZZZ ZZZ : ");
//    etu = obtenirParent(abr, "ZZZ", "ZZZ");
//    if(etu)
//        printf("%s %s\n\n", etu->nom, etu->prenom);
//    else
//        printf("Adresse du parent : %p\n\n", etu);

//    //查看某学生节点的后继节点（测试函数[obtenirSuccesseur]）
//    printf("\n\n--------------------------------------------------\n\n");
//    printf("[FONCTION obtenirSuccesseur]\n\n");
//    printf("- - - - - - - - - - - - - - - - - - - - \n\n");
//    etu = chercher_Etu(abr, "Doe", "John");
//    etu = obtenirSuccesseur(abr, etu);
//    if(etu)
//        printf("Successeur de Doe John : %s %s\n\n", etu->nom, etu->prenom);
//    else
//        printf("Successeur de Doe John : %p\n\n", etu);
//    printf("- - - - - - - - - - - - - - - - - - - - \n\n");
//    etu = chercher_Etu(abr, "Fac", "Kittel");
//    etu = obtenirSuccesseur(abr, etu);
//    if(etu)
//        printf("Successeur de Fac Kittel : %s %s\n\n", etu->nom, etu->prenom);
//    else
//        printf("Successeur de Fac Kittel : %p\n\n", etu);
//    printf("- - - - - - - - - - - - - - - - - - - - \n\n");
//    etu = chercher_Etu(abr, "Zackin", "Zoma");
//    etu = obtenirSuccesseur(abr, etu);
//    if(etu)
//        printf("Successeur de Zackin Zoma : %s %s\n\n", etu->nom, etu->prenom);
//    else
//        printf("Successeur de Zackin Zoma : %p\n\n", etu);
//    printf("- - - - - - - - - - - - - - - - - - - - \n\n");
//    etu = chercher_Etu(abr, "ZZZ", "ZZZ");
//    etu = obtenirSuccesseur(abr, etu);
//    if(etu)
//        printf("Successeur de ZZZ ZZZ : %s %s\n\n", etu->nom, etu->prenom);
//    else
//        printf("Successeur de ZZZ ZZZ : %p\n\n", etu);

//    //将某学生注册的课程删除（测试函数[supprimerInscription]）
//    afficherInscriptions(abr); /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    printf("\n\n--------------------------------------------------\n\n");
//    printf("[FONCTION supprimerInscription]\n\n");
//    printf("- - - - - - - - - - - - - - - - - - - - \n\n");
//    printf("* Supprimer l'inscription de Bott Emmy a HIT102 :\n");
//    abr = supprimerInscription(abr, "Bott", "Emmy", "HIT102");
//    etu = chercher_Etu(abr, "Bott", "Emmy");
//    afficherEtuInfo(etu);
//    printf("\n\n- - - - - - - - - - - - - - - - - - - - \n\n");
//    printf("* Supprimer l'inscription de Dupond Marcel a MCH102 :\n");
//    abr = supprimerInscription(abr, "Dupond", "Marcel", "MCH102");
//    afficherInscriptions(abr);
//    printf("\n- - - - - - - - - - - - - - - - - - - - \n\n");
//    printf("* Supprimer l'inscription de Fac Kittel a ART130 :\n");
//    abr = supprimerInscription(abr, "Fac", "Kittel", "ART130");
//    etu = chercher_Etu(abr, "Fac", "Kittel");
//    afficherEtuInfo(etu);
//    printf("\n\n* Supprimer l'inscription de Fac Kittel a BIO501 :\n");
//    abr = supprimerInscription(abr, "Fac", "Kittel", "BIO501");
//    afficherInscriptions(abr);
//    printf("\n- - - - - - - - - - - - - - - - - - - - \n\n");
//    printf("* Supprimer l'inscription de Tom Effos a MAT091 :\n");
//    abr = supprimerInscription(abr, "Tom", "Effos", "MAT091");
//    etu = chercher_Etu(abr, "Tom", "Effos");
//    afficherEtuInfo(etu);
//    printf("\n\n* Supprimer l'inscription de Fac Kittel a ENG159 :\n");
//    abr = supprimerInscription(abr, "Tom", "Effos", "ENG159");
//    afficherInscriptions(abr);

//    //将某学生注册的所有课程删除（测试函数[supprimerTousLesInscriptions]）
//    printf("\n\n--------------------------------------------------\n\n");
//    printf("[FONCTION supprimerTousLesInscriptions]\n\n");
//    abr = supprimerTousLesInscriptions(abr, "Doe", "John");
//    afficherInscriptions(abr);

//    //释放所有动态分配的内存空间（测试函数[libererArbre]）
//    printf("\n\n--------------------------------------------------\n\n");
//    printf("[FONCTION libererArbre]\n\n");
//    abr = libererArbre(abr);
//    afficherInscriptions(abr);
    return 0;

}
