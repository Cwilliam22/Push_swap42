#Push_swap 

Description : 

Push_swap est un projet de l'école 42 dont l'objectif est d'implémenter un algorithme de tri optimisé en utilisant deux piles (stack A et stack B) et un ensemble limité d'instructions.
Le but est de trier une liste d'entiers le plus efficacement possible, en minimisant le nombre d'opérations effectuées.

Fonctionnement :

Le programme prend en entrée une série d'entiers non triés en arguments et affiche une suite d'instructions (parmi un set prédéfini) qui permettent de trier les nombres.

Exemple : 

$ ./push_swap 2 1 3

sa

Instructions disponibles : 
  - sa : swap les deux premiers éléments de A
  - sb : swap les deux premiers éléments de B
  - ss : sa et sb en même temps
  - pa : push de B vers A
  - pb : push de A vers B
  - ra : rotation de A vers le haut
  - rb : rotation de B vers le haut
  - rr : ra et rb en même temps
  - rra : rotation inverse de A
  - rrb : rotation inverse de B
  - rrr : rra et rrb en même temps
