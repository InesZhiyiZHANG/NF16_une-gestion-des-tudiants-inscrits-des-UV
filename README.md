# NF16_une-gestion-des-tudiants-inscrits-des-UV
Dans ce TP, nous utiliserons les arbres binaires de recherche (ABR) et les listes simplement chaînées pour implémenter une gestion des étudiants inscrits à des UV.
L’ABR représente la liste des étudiant(e)s que l’on a inscrit à au moins une UV. Chaque nœud de l'arbre contient
les informations permettant d’identifier un(e) étudiant(e), à savoir son nom et son prénom (on suppose qu’il n’y
a pas deux étudiant(e)s ayant le même nom et prénom), ainsi que la liste des UV auquel il/elle est inscrit(e).
Le nom et le prénom constituent la clé du nœud, et l’ordre alphabétique sert de critère de comparaison entre
deux nœud, par exemple :
DUPOND MARCEL < DUPONT ALBERT < MARTIN JACQUES
Une liste chaînée représente la liste des UV auxquelles un(e) étudiant(e) est inscrit(e). Chaque élément de la liste
contient le code unique pour identifier l’UV (ex : NF16, AI01, etc…).
Important : les codes UV, les noms et les prénoms entrés par l’utilisateur seront convertis systématiquement en
majuscules.
