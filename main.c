#include <stdio.h>
#include <stdlib.h>
#include "TP04.h"

int main()
{


    /*char choix = '0';
    while (choix != '8') {
        printf("\n\n\n\n============================================================");
        printf("\n1. Afficher la liste des blocs de la BlockChain");
        printf("\n2. Afficher toutes les transactions d'un bloc");
        printf("\n3. Afficher toutes les transactions du jour pour un etudiant");
        printf("\n4. Afficher l'historique pour un etudiant");
        printf("\n5. Crediter un compte");
        printf("\n6. Payer un repas");
        printf("\n7. Transferer des EATCoins entre deux etudiants");
        printf("\n8. Quitter");
        printf("\n9. Ajouter un nouveau data");
        printf("\n============================================================");
        printf("\n>>La date du jour : %s, blockID : %d\n", ma_chaine_de_blocs->dateBloc, ma_chaine_de_blocs->idBloc);
        printf("\nVotre choix ? ");

        choix = getchar();

        switch (choix) {*/


/***************************************************************/
   /* �������liste
   T_Element *liste = NULL;


    liste = ajouterInscription(liste, "CSE101");
    liste = ajouterInscription(liste, "MAT201");
    liste = ajouterInscription(liste, "PHY301");
    liste = ajouterInscription(liste, "CSE101");  // �ظ��� UV

    // ��ӡ�б�����
    T_Element *courant = liste;
    while (courant != NULL) {
        printf("%s ", courant->code_uv);
        courant = courant->suivant;
    }

    // �ͷ��б��ڴ�
    courant = liste;
    while (courant != NULL) {
        T_Element *temp = courant;
        courant = courant->suivant;
        free(temp);
    }*/
//*********************************************************************//
   T_Arbre abr = NULL; // ��ʼ��һ������
   abr = chargerFichier(abr, "etu_list.txt");
    //printf("%s",abr->prenom);
   printf("\n\n--------------------------------------------------\n\n");
    printf("[FONCTION afficherInscriptions]\n\n");
    afficherInscriptions(abr);
    if(abr == NULL){
        printf("!!!!!!!!!!!!!!\nvide!\n");
    }

    // ����1�����ѧ������ע��


//    // �������ѧ����Ϣ�����Ժ���[afficherEtuInfo]��
//    printf("--------------------------------------------------\n\n");
//    printf("[FONCTION afficherEtuInfo]\n\n");
//    etu = chercher_Etu(abr, "Johnson", "Alice");
//    afficherEtuInfo(etu);

    //���ȫ��ѧ���Ŀγ���Ϣ�����Ժ���[afficherInscriptions]��

//    //�鿴ѧ���Ƿ�ע����ĳһ�γ̣����Ժ���[rechercherUVdEtu]��
//    printf("\n\n--------------------------------------------------\n\n");
//    printf("[FONCTION rechercherUVdEtu]\n\n");
//    etu = chercher_Etu(abr, "Martin", "Jacques");
//    printf("Martin Jacques est inscrit a HIT102 ? [%d]\n", rechercherUVdEtu(etu, "HIT102"));
//    printf("Martin Jacques est inscrit a MCH102 ? [%d]\n", rechercherUVdEtu(etu,  "MCH102"));
//    return 0;

//    //�鿴ע����ĳһ�γ̵�����ѧ�������Ժ���[afficherInscriptionsUV]��
//    printf("\n\n--------------------------------------------------\n\n");
//    printf("[FONCTION afficherInscriptionsUV]\n\n");
//    printf("Etudiants inscrits �� BIO501 : \n");
//    afficherInscriptionsUV(abr, "BIO501");
//    printf("\nEtudiants inscrits �� ZZZ999 : \n");
//    afficherInscriptionsUV(abr, "ZZZ999");

//    //�鿴��������ĸ�����ǰ��ѧ�������Ժ���[obtenirMinimumEtu]��
//    printf("\n\n--------------------------------------------------\n\n");
//    printf("[FONCTION obtenirMinimumEtu]\n\n");
//    etu = obtenirMinimumEtu(abr);
//    printf("Etu minimum : %s %s\n", etu->nom, etu->prenom);

//    //�鿴ĳѧ���ڵ�ĸ��ڵ㣨���Ժ���[obtenirParent]��
//    printf("\n\n--------------------------------------------------\n\n");
//    printf("[FONCTION obtenirParent]\n\n");
//    printf("- - - - - - - - - - - - - - - - - - - - \n\n");
//    printf("Noeud parent de la racine : ");
//    etu = obtenirParent(abr, "Doe", "John");
//    printf("Adresse du parent : %p\n\n", etu);
//    printf("- - - - - - - - - - - - - - - - - - - - \n\n");
//    printf("Noeud parent de Bott Emmy : ");
//    etu = obtenirParent(abr, "Bott", "Emmy");
//    printf("%s %s\n\n", etu->nom, etu->prenom);
//    printf("- - - - - - - - - - - - - - - - - - - - \n\n");
//    printf("Noeud parent de Fac Kittel : ");
//    etu = obtenirParent(abr, "Fac", "Kittel");
//    printf("%s %s\n\n", etu->nom, etu->prenom);
//    printf("- - - - - - - - - - - - - - - - - - - - \n\n");
//    printf("Noeud parent de ZZZ ZZZ : ");
//    etu = obtenirParent(abr, "ZZZ", "ZZZ");
//    printf("Adresse du parent : %p\n\n", etu);

//    //�鿴ĳѧ���ڵ�ĺ�̽ڵ㣨���Ժ���[obtenirSuccesseur]��
//    printf("\n\n--------------------------------------------------\n\n");
//    printf("[FONCTION obtenirSuccesseur]\n\n");
//    printf("- - - - - - - - - - - - - - - - - - - - \n\n");
//    etu = chercher_Etu(abr, "Doe", "John");
//    etu = obtenirSuccesseur(abr, etu);
//    printf("Successeur de Doe John : %s %s\n\n", etu->nom, etu->prenom);
//    printf("- - - - - - - - - - - - - - - - - - - - \n\n");
//    etu = chercher_Etu(abr, "Fac", "Kittel");
//    etu = obtenirSuccesseur(abr, etu);
//    printf("Successeur de Fac Kittel : %s %s\n\n", etu->nom, etu->prenom);
//    printf("- - - - - - - - - - - - - - - - - - - - \n\n");
//    etu = chercher_Etu(abr, "Zackin", "Zoma");
//    etu = obtenirSuccesseur(abr, etu);
//    printf("Successeur de Zackin Zoma : %p\n\n", etu);
//    printf("- - - - - - - - - - - - - - - - - - - - \n\n");
//    etu = chercher_Etu(abr, "ZZZ", "ZZZ");
//    etu = obtenirSuccesseur(abr, etu);
//    printf("Successeur de ZZZ ZZZ : %p\n\n", etu);

//    //��ĳѧ��ע��Ŀγ�ɾ�������Ժ���[supprimerInscription]��
//    printf("\n\n--------------------------------------------------\n\n");
//    printf("[FONCTION supprimerInscription]\n\n");
//    printf("- - - - - - - - - - - - - - - - - - - - \n\n");
//    printf("* Supprimer l��inscription de Bott Emmy a HIT102 :\n");
//    abr = supprimerInscription(abr, "Bott", "Emmy", "HIT102");
//    etu = chercher_Etu(abr, "Bott", "Emmy");
//    afficherEtuInfo(etu);
//    printf("\n\n- - - - - - - - - - - - - - - - - - - - \n\n");
//    printf("* Supprimer l��inscription de Dupond Marcel a MCH102 :\n");
//    abr = supprimerInscription(abr, "Dupond", "Marcel", "MCH102");
//    afficherInscriptions(abr);
//    printf("\n- - - - - - - - - - - - - - - - - - - - \n\n");
//    printf("* Supprimer l��inscription de Fac Kittel a ART130 :\n");
//    abr = supprimerInscription(abr, "Fac", "Kittel", "ART130");
//    etu = chercher_Etu(abr, "Fac", "Kittel");
//    afficherEtuInfo(etu);
//    printf("\n\n* Supprimer l��inscription de Fac Kittel a BIO501 :\n");
//    abr = supprimerInscription(abr, "Fac", "Kittel", "BIO501");
//    afficherInscriptions(abr);
//    printf("\n- - - - - - - - - - - - - - - - - - - - \n\n");
//    printf("* Supprimer l��inscription de Tom Effos a MAT091 :\n");
//    abr = supprimerInscription(abr, "Tom", "Effos", "MAT091");
//    etu = chercher_Etu(abr, "Tom", "Effos");
//    afficherEtuInfo(etu);
//    printf("\n\n* Supprimer l��inscription de Fac Kittel a ENG159 :\n");
//    abr = supprimerInscription(abr, "Tom", "Effos", "ENG159");
//    afficherInscriptions(abr);

//    //��ĳѧ��ע������пγ�ɾ�������Ժ���[supprimerTousLesInscriptions]��
//    printf("\n\n--------------------------------------------------\n\n");
//    printf("[FONCTION supprimerTousLesInscriptions]\n\n");
//    abr = supprimerTousLesInscriptions(abr, "Doe", "John");
//    afficherInscriptions(abr);

//    //��ĳѧ��ע������пγ�ɾ�������Ժ���[supprimerTousLesInscriptions]��
//    printf("\n\n--------------------------------------------------\n\n");
//    printf("[FONCTION supprimerTousLesInscriptions]\n\n");
//    abr = supprimerTousLesInscriptions(abr, "Doe", "John");
//    afficherInscriptions(abr);

//    //�ͷ����ж�̬������ڴ�ռ䣨���Ժ���[libererArbre]��
//    printf("\n\n--------------------------------------------------\n\n");
//    printf("[FONCTION libererArbre]\n\n");
//    abr = libererArbre(abr);
//    afficherInscriptions(abr);
    printf("\n--------------------------------------------------\n\n");
    return 0;

}
