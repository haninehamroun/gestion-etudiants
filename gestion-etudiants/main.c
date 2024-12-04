#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct etudiant
{
    int  code ;
    char np[50];
    float moyenne ;
    int ann ;
    char spe[50];
};
struct cellule_etudiant
{
    struct etudiant info ;
    struct cellule_etudiant * suivant ;
};
//fonction pour verifier si la chaine contient que des lettres alphabétiques

int est_chaine(char *ch) {
    for (int i = 0; ch[i] != '\0'; i++) {
        if (!isalpha(ch[i]) && ch[i] != ' ')
            {
            return 0;
            }
    }
    return 1;
}
//fonction pour assurer que le chaîne de caractères est composée seulements de chiffres.

int est_numerique(char *chaine) {
    for (int i=0;chaine[i]!='\0';i++)
    {
        if (!isdigit(chaine[i]))
            {
            return 0;
            }
    }
    return 1;
}

//fonction pour remplir un tableau par les coordonnés des  étudiants

void remplir_tab(struct etudiant t[],int n)
{
    int i ;
    for (i=0;i<n;i++)
    {

         char code_chaine[20];
         char annee_chaine[20];
         int code,annee;

         do
            {
                printf("\nCode : ");
                scanf("%s",code_chaine);

                 if (!est_numerique(code_chaine))
                    {
                        printf("Le code doit etre un nombre entier positif .\n");
                    }

            } while (!est_numerique(code_chaine) );

        code = atoi(code_chaine);
        t[i].code = code;
        do
        {
            fflush(stdin);
            printf("\nNom et Prenom : "); gets(t[i].np);
            if (!est_chaine(t[i].np))
                {
                printf("Le nom et le prenom doivent contenir uniquement des lettres.\n");
                }
        } while (!est_chaine(t[i].np));
        do
        {
            do
            {
                printf("\nMoyenne : "); scanf("%f",&t[i].moyenne);
                if (t[i].moyenne<0)
                    {
                        printf("La moyennee doit etre  positif .\n");
                    }

            } while (t[i].moyenne<0 );

            if (t[i].moyenne > 20)
                {
                printf("La moyenne doit etre comprise entre 0 et 20.\n");
                }
        }
        while ( t[i].moyenne > 20);
        do
        {
                    printf("\nAnnee : "); scanf("%s",&annee_chaine);
                     if (!est_numerique(annee_chaine))
                    {
                        printf("L'annee doit etre un nombre entier positif .\n");
                    }

        }while (!est_numerique(annee_chaine) );

             annee = atoi(annee_chaine);
             t[i].ann = annee;
        do
        {
            fflush(stdin);
            printf("\nSpecialite : "); gets(t[i].spe);
            if (!est_chaine(t[i].spe)) {
                printf("La specialite doit contenir uniquement des lettres.\n");
            }
        } while (!est_chaine(t[i].spe));
    }

  }


//fonction pour enregistrer les étudiants dans un fichier

void remplir_fichier_tab(char nomf[],struct etudiant t[], int n)
{
    FILE * f ;
    f=fopen(nomf,"a");
    if(f==NULL)
        printf("Ouverture impossible \n ");
    else
    {
        int i ;
        for (i=0;i<n;i++)
        {
            fwrite(&t[i],sizeof(struct etudiant),1,f);
        }
        fclose(f);
    }
}

// fonction pour ajouter un étudiant en tête de liste

struct cellule_etudiant* ajouter_etudiant_entete(struct cellule_etudiant *tete , struct etudiant e)
{
    struct cellule_etudiant* p=(struct cellule_etudiant* )malloc(sizeof( struct cellule_etudiant));
    p->info.code=e.code;
    strcpy(p->info.np,e.np);
    p->info.moyenne=e.moyenne;
    p->info.ann=e.ann;
    strcpy(p->info.spe,e.spe);
    p->suivant=tete;
    tete=p;
    return tete;
}
// fonction pour donner le pointeur sur le dernier element de la liste

struct cellule_etudiant* dernier(struct cellule_etudiant* L)
{
    if (L==NULL)
        return NULL ;
    struct cellule_etudiant* q=L ;
    while (q->suivant != NULL)
        q=q->suivant;
    return q ;
}
// fonction pour ajouter un étudiant en queue  de  la liste

struct cellule_etudiant * ajouter_etudiant_enqueue(struct cellule_etudiant * tete , struct etudiant e)
{
    struct cellule_etudiant * p=(struct cellule_etudiant *) malloc(sizeof(struct cellule_etudiant));
    p->info.code=e.code;
    strcpy(p->info.np,e.np);
    p->info.moyenne=e.moyenne;
    p->info.ann=e.ann;
    strcpy(p->info.spe,e.spe);
    p->suivant=NULL;
    if (tete==NULL)
        tete=p;
    else
    {
        struct cellule_etudiant* q = dernier(tete);
        q->suivant=p;
    }
    return tete;
}
// fonction pour supprimer un étudiant en tête de la  liste

struct cellule_etudiant* supprimer_etudiant_entete (struct cellule_etudiant * tete)
{
    if(tete==NULL)
        return NULL;
    else
    {
         struct cellule_etudiant * p=tete;
        tete=tete->suivant;
        free(p);
        return tete ;
    }
}
// fonction pour donner le pointeur sur le avant dernier element de la liste

struct cellule_etudiant* avant_dernier(struct cellule_etudiant * L)
{
    if ( L==NULL)
    {
        return NULL ;
    }
    struct cellule_etudiant* p=L ;
    while (p->suivant->suivant!=NULL)
        p=p->suivant;
    return p ;
}
// fonction pour supprimer un étudiant en queue de la  liste

struct cellule_etudiant* supprimer_etudiant_enqueue (struct cellule_etudiant * tete)
{
    if(tete==NULL)
        return NULL;
    if (tete->suivant==NULL)
    {
        struct cellule_etudiant * p=tete;
        tete=NULL;
        free(p);
        return tete ;
    }
    struct cellule_etudiant* q=avant_dernier(tete);
    free(q->suivant);
    q->suivant=NULL;
    return tete ;
}
//fonction pour créer un fichier  liste

struct cellule_etudiant* creer_fichier_liste(char nomf[]) {
    FILE* f = fopen(nomf,"r");
    if (f==NULL)
        {
            printf("Ouverture impossible.\n");
            return NULL;
        }

    struct cellule_etudiant* L = NULL;
    struct etudiant E;

    while (fread(&E, sizeof(struct etudiant), 1, f))
        {
        L = ajouter_etudiant_enqueue(L, E);
        }

    fclose(f);
    return L;
}
struct cellule_etudiant* ajouter_tab_a_liste(struct cellule_etudiant* liste, struct etudiant* tab, int n) {
    for (int i = 0; i < n; i++)
        {
            liste = ajouter_etudiant_enqueue(liste,tab[i]);
        }
    return liste;
}


// fonction pour afficher les étudiants qui ont  une moyenne supérieure ou égale à une valeur donnée par l'utilisateur

void afficher_liste(struct cellule_etudiant *tete, float moy )
{
    if (tete==NULL)
    {
        printf("\nliste vide");

    }
    else
    {
        struct cellule_etudiant * p=tete ;
        while(p!=NULL)
        {
            if (p->info.moyenne>= moy)
            {
                printf("\n %d ,%s , %f , %d , %s",p->info.code,p->info.np,p->info.moyenne,p->info.ann,p->info.spe);
            }
            p=p->suivant;
        }
    }
}
//fonction pour rechercher un étudiant par son code

struct cellule_etudiant * rechercher_etudiant(struct cellule_etudiant * tete, int code)
{
    if (tete==NULL)
        return NULL ;
    else
    {
        struct cellule_etudiant * p=tete;
        while(p!=NULL)
        {
            if(p->info.code==code)
                return p;
            else p=p->suivant;
        }
    }
}
// fonction pour calculer la moyenne de la classe

float calculer_moyenne_classe(struct cellule_etudiant* tete) {
    if (tete == NULL)
        return 0.0;
    struct cellule_etudiant* p = tete;
    float somme = 0;
    int count = 0;
    while (p != NULL) {
        somme += p->info.moyenne;
        count++;
        p = p->suivant;
    }
    return somme / count;
}

// fonction pour trier la liste des étudiants par moyenne décroissante

struct cellule_etudiant* trier_par_moyenne(struct cellule_etudiant* tete) {
    if (tete == NULL) return NULL;
    struct cellule_etudiant* i = tete;
    while (i != NULL) {
        struct cellule_etudiant* j = i->suivant;
        while (j != NULL) {
            if (i->info.moyenne < j->info.moyenne) {
                struct etudiant temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
            j = j->suivant;
        }
        i = i->suivant;
    }
    return tete;
}

// fonction pour afficher le premier de la classe

void afficher_premier(struct cellule_etudiant* tete) {
    if (tete == NULL) {
        printf("\nListe vide\n");
        return;
    }
    struct cellule_etudiant* meilleur = tete;
    struct cellule_etudiant* p = tete;
    while (p != NULL) {
        if (p->info.moyenne > meilleur->info.moyenne)
            {
            meilleur = p;
            }
        p = p->suivant;
    }
    printf("\n le premier de la classe est  : %d, %s, %.2f, %d, %s", meilleur->info.code, meilleur->info.np, meilleur->info.moyenne, meilleur->info.ann, meilleur->info.spe);
}
void liberer_liste(struct cellule_etudiant* liste) {
    struct cellule_etudiant* aux;
    while (liste != NULL) {
        aux = liste;
        liste = liste->suivant;
        free(aux);
    }
}


int main() {
    int choix, n;
    struct etudiant* tab = NULL;
    struct cellule_etudiant* liste = NULL;

    do {
        printf("\n*** Gestion des etudiants ***\n");
        printf("1. Remplir un tableau d'etudiants\n");
        printf("2. ajouter le tableau dans le fichier liste \n");
        printf("3. afficher un le fichier liste \n");
        printf("4. Ajouter un etudiant a la liste   \n");
        printf("5. Supprimer un etudiant de la liste \n");
        printf("6. Afficher les etudiants admis\n");
        printf("7. Rechercher un etudiant\n");
        printf("8. Calculer la moyenne de la classe\n");
        printf("9. Trier la liste des etudiants\n");
        printf("10. Afficher le premier de la classe\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Nombre d'etudiants : ");
                scanf("%d",&n);
                tab = (struct etudiant*)malloc(n * sizeof(struct etudiant));
                remplir_tab(tab, n);
                break;

            case 2:

                      if (tab != NULL)
                        {
                            remplir_fichier_tab("etudiants.dat", tab, n);
                            printf("Fichier rempli.\n");
                            liste = ajouter_tab_a_liste(liste, tab, n);
                            printf("etudiants ajoutes a la liste.\n");
                        }
                    else
                                       {
                                           printf("Aucun tableau rempli.\n");
                                       }


                break;
            case 3:
               {
                   FILE *f = fopen("etudiants.dat", "r");
                   if (f == NULL)
                    {
                        printf("Erreur d'ouverture du fichier.\n");
                    }
                   else
                    {
                       fseek(f,0,SEEK_END);
                       long size = ftell(f);
                       if (size == 0)
                        {
                            printf("Le fichier est vide.\n");
                        }
                       else
                        {
                            afficher_liste(liste,0);
                        }
                   fclose(f);
                     }
                   break;
           }


    case 4:
    {
                   struct etudiant  E2;
                   int choix_ajout;
                   char code_chaineE2[20];


         do
            {
                printf("\nCode : ");
                scanf("%s",code_chaineE2);

                 if (!est_numerique(code_chaineE2))
                    {
                        printf("Le code doit etre un nombre entier positif . \n");
                    }

            } while (!est_numerique(code_chaineE2) );

        E2.code = atoi(code_chaineE2);

        do
        {
            fflush(stdin);
            printf("\nNom et Prenom : "); gets(E2.np);
            if (!est_chaine(E2.np))
                {
                printf("Le nom et le prenom doivent contenir uniquement des lettres.\n");
                }
        } while (!est_chaine(E2.np));
        do
        {
            do
            {
                printf("\nMoyenne : "); scanf("%f",&E2.moyenne);
                if (E2.moyenne<0)
                    {
                        printf("La moyennee doit etre  positif . \n");
                    }

            } while (E2.moyenne<0);

            if (E2.moyenne > 20)
                {
                printf("La moyenne doit etre comprise entre 0 et 20.\n");
                }
        }
        while ( E2.moyenne > 20);
        char annee_chaineE2[20];
        int anneeE2;
        do
                {
                    printf("\nAnnee : "); scanf("%s",&annee_chaineE2);
                     if (!est_numerique(annee_chaineE2))
                    {
                        printf(" L'annee doit etre un nombre entier positif . Veuillez reessayer.\n");
                    }

                } while (!est_numerique(annee_chaineE2) );

             anneeE2= atoi(annee_chaineE2);
             E2.ann = anneeE2;
        do
        {
            fflush(stdin);
            printf("\nSpecialite : "); gets(E2.spe);
            if (!est_chaine(E2.spe))
                {
                printf("La specialite doit contenir uniquement des lettres.\n");
                }
        } while (!est_chaine(E2.spe));

                   printf("Voulez-vous ajouter l'etudiant :\n");
                   printf("1. En tete de la liste\n");
                   printf("2. En queue de la liste\n");
                   printf("Votre choix : ");
                   scanf("%d", &choix_ajout);

                   if (choix_ajout == 1)
                    {
                       liste = ajouter_etudiant_entete(liste,E2);
                       printf("etudiant ajoute en tete de la liste.\n");
                    }
                   else if (choix_ajout == 2)
                    {
                        liste = ajouter_etudiant_enqueue(liste,E2);
                        printf("etudiant ajoute en queue de la liste.\n");
                    }
                    else
                    {
                       printf("Choix invalide. etudiant non ajoute.\n");
                    }

                 break;
    }


                case 5:
                {
                    int choix_suppression;
                    printf("Voulez-vous supprimer un etudiant :\n");
                    printf("1. En tete de la liste\n");
                    printf("2. En queue de la liste\n");
                    printf("Votre choix : ");
                    scanf("%d", &choix_suppression);

                    if (choix_suppression == 1)
                        {
                            liste = supprimer_etudiant_entete(liste);
                            printf("etudiant supprime en tete de la liste.\n");
                        }
                    else if (choix_suppression == 2)
                        {
                            liste = supprimer_etudiant_enqueue(liste);
                            printf("etudiant supprime en queue de la liste.\n");
                        }
                    else
                        {
                            printf("Choix invalide. Aucune suppression effectuee.\n");
                        }

              break;
}



            case 6:
                printf("Moyenne minimale pour reussir : ");
                float moy;
                scanf("%f", &moy);
                afficher_liste(liste, moy);
                break;

            case 7: {
                int code;
                printf("Code de l'etudiant a rechercher : ");
                scanf("%d", &code);
                struct cellule_etudiant* p = rechercher_etudiant(liste, code);
                if (p == NULL) {
                    printf("etudiant inexistant.\n");
                } else {
                    printf("Code : %d\nNom et Prenom : %s\nMoyenne : %.2f\nAnnee : %d\nSpecialite : %s\n",
                           p->info.code, p->info.np, p->info.moyenne, p->info.ann, p->info.spe);
                }
                break;
            }

            case 8:
                printf("Moyenne de la classe : %.2f\n", calculer_moyenne_classe(liste));
                break;

            case 9:
                liste = trier_par_moyenne(liste);
                afficher_liste(liste, 0);
                break;
            case 10:
                afficher_premier(liste);
                break;

            case 0:
                printf("Au revoir !\n");
                liberer_liste(liste);
                free(tab);
                break;

            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);
    return 0;
}

