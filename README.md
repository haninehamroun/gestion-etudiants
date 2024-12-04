Gestion des Étudiants:
Ce projet implémente une gestion simple des étudiants en utilisant des structures de données en langage C. Il permet de manipuler une liste d'étudiants avec des opérations telles que l'ajout, la suppression, la recherche, le calcul de la moyenne de la classe, le tri des étudiants par moyenne et l'affichage des étudiants selon certains critères.

*Fonctionnalités
  -Gestion des étudiants : Chaque étudiant est représenté par une structure contenant son code, son nom et prénom, sa moyenne, son année, et sa spécialité.
  -Tableau d'étudiants : Un tableau dynamique permet de stocker les étudiants.
  -Liste chaînée : La gestion des étudiants se fait aussi via une liste chaînée, permettant l'ajout en tête ou en queue de liste, ainsi que la suppression d'éléments.
  -Opérations sur les étudiants :
Remplissage d'un tableau d'étudiants à partir des entrées de l'utilisateur.
  -Ajout d'étudiants à un fichier binaire (etudiants.dat).
  -Affichage des étudiants qui ont une moyenne supérieure ou égale à une valeur donnée.
  -Recherche d'un étudiant par son code.
  -Calcul de la moyenne générale de la classe.
  -Tri des étudiants par moyenne décroissante.
  -Affichage du premier de la classe.
  -Vérifications de validité : Des vérifications sont effectuées pour s'assurer que les entrées de l'utilisateur sont valides (noms uniquement alphabétiques, codes numériques, moyennes entre 0 et 20, etc.).

*Pour compiler et exécuter ce projet, vous avez besoin de :
  -Un compilateur C (par exemple, Code::Blocks).
  -Système d'exploitation : Windows, Linux, macOS.

*Compilation et Exécution
1-Clonez le repository :
  git clone https://github.com/haninehamroun/gestion-etudiants.git
2-Allez dans le dossier du projet :
  cd gestion-etudiants
3-Compilez le programme :
  gcc -o gestion-etudiants gestion-etudiants.c
4-Exécutez le programme :
  ./gestion-etudiants

*Utilisation
 Au démarrage, le programme propose un menu avec plusieurs options pour gérer les étudiants. Voici les principales fonctionnalités :

  1-Remplir un tableau d'étudiants : Permet d'entrer plusieurs étudiants dans un tableau.
  2-Ajouter des étudiants dans un fichier : Sauvegarde les étudiants dans un fichier binaire (etudiants.dat).
  3-Afficher les étudiants : Affiche les étudiants dont la moyenne est supérieure ou égale à un seuil donné.
  4-Rechercher un étudiant par son code : Permet de rechercher un étudiant spécifique en utilisant son code.
  5-Calculer la moyenne de la classe : Calcule et affiche la moyenne générale de tous les étudiants.
  6-Trier la liste des étudiants : Trie les étudiants par moyenne décroissante.
  7-Afficher le premier de la classe : Affiche l'étudiant ayant la meilleure moyenne.

Auteur :
Créé par Hamroun Hanine, 2024.
