### Fonction autorisés (libft interdite)

| Fonction                  | Prototype                                                                                       | Explication simple                                                                 |
|---------------------------|-------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------|
| `memset`                  | `void *memset(void *s, int c, size_t n);`                                                       | Remplit une zone mémoire avec un octet c
| `usleep`                  | `int usleep(useconds_t usec);`                                                                  | Fait une pause (usec microsecondes).                                                 |
| `gettimeofday`            | `int gettimeofday(struct timeval *tv, struct timezone *tz);`                                   | Donne l’heure actuelle (secondes + microsecondes).                  |
| `pthread_create`          | `int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);` | Lance un nouveau thread 
| `pthread_detach`          | `int pthread_detach(pthread_t thread);`                                                         |
| `pthread_join`            | `int pthread_join(pthread_t thread, void **retval);`                                            | Attend qu’un thread se termine
| `pthread_mutex_init`      | `int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);`             | Verouille (= cadenas) pour gérer l’accès partagé à une ressource. (fork dans le sujet)         |
| `pthread_mutex_lock`      | `int pthread_mutex_lock(pthread_mutex_t *mutex);`                                               | Ferme le cadenas (bloque l’accès aux autres).                                      |
| `pthread_mutex_unlock`    | `int pthread_mutex_unlock(pthread_mutex_t *mutex);`                                             | Ouvre le cadenas (autorise les autres à accéder).                                  |
| `pthread_mutex_destroy`   | `int pthread_mutex_destroy(pthread_mutex_t *mutex);`                                            | Détruit le cadenas quand on en a plus besoin.                                      |

### Arguments de philo
- `number_of_philosophers` : nbr de philo à table = nbr de fork
- `time_to_die` : temps avant qu’un philo meure s’il ne mange pas en milliseconde
- `time_to_eat` : temps du repas d'un philo en miliseconde 
- `time_to_sleep` : temps du sommeil d'un philo en miliseconde 
- `number_of_times_each_philosopher_must_eat` : (optionnel?bonus?) combien de fois chaque philosophe doit manger

### Sujet _ Philo 

- Des philos sont assis autour d'une table ronde
- Au milieu un bol de spaghetti 
- Autant de fourchette que de philo 
- Chaque philo alterne entre 3 etats : penser, manger, dormir
- Pour manger besoin de 2 fourchettes (une a gauche et une a droite)
- Journée d'un philo : pense, prend une fork puis une deuxieme, mange, repose ses fourchettes et s'endort. 
- Puis recommence sa journée 
- Les philos doivent manger 1 par 1 ! 
- Il meurt quand ? 

### THREAD 

- Sous programme qui sexe avec d'autres dans un même programme
- Plusieurs tache vont s'exécuter en parallele. 
- Partage la même mémoire

### CPU(processeur), core et thread

- CPU = cerveau de mon nordinateur, traite instructions et effectues les calculs 
- Core = unité d'exe du CPU. Monocoeur ou plusieurs.
_ Chaque core peut exe un thread à la fois. Si CPU 1 coeur = 1 thread à la fois
- Plusieurs core = chaque coeur peut exe un thread distinct et permet aux thread de s'exe en même temps
- Hyper-threading (HT) (dev par Intel au début) : un seul coeur va pouvoir exe plusieurs thread à la fois mais de maniere virtuelle (on va alternet les instruction de chaque thread tres tres tres rapidement, ca donne l'impression que cst au même moment), chaque coeur peux donc exe 2 thread en simult 

- Actuellement plus puissant bureautique : AMD Ryzen Threadripper 3990X 64 core physique (donc 128 en hyperthreadeing

- Cpu de mon pc portable commande : lscpu

 ````
 Intel Core i5-10300H 
 10eme generation
 4 core physique 
 Thread = 8 (grace a l'hyper threading)
 ````
- Comment ca marche l'HT ? Les deux threads sur un 1 vont partagé les mêmes ressources, quand un attend des données ou une ressource l'autre thread s'execute. Ils partage la même mémoire cache, unités d'exe
- Memoire cache; le process a plusieurs niveau de memoire (L1, L2, L3) = stock donné fréquemment utilisé sans avoir a aller les chercher dans la RAM. 
    L1 = plus rapide plus petit
    L2 = plus grande mais plus lente (mais plus rapide que la RAM)
    L3 = encore plus grand maos plus lent, celui la ce partage entre tous les coeurs du process
- Unité d'exe = effectue calcul qui manipule les données. Dans le HT les unités d'exe alterne entre le 1 et le 2 thread. 
- Autre ressource du process = registres, perif entrée sortie (IO), bus de données. 
- Registre un autre type de mémoire (différent du cache), zone de mémoire ultra rapide, stock des donnes tmp a utilisé pendant les calculs. Cst la mémoire la plus rapide que notre CPU peut utilisé mais cst la plus mini en terme de capacités directement situé dans le CPU. Tandis que la che est situé entre le process et la RAM. 
- IO = composants ext qui permet à l'ordi d'intérargit avec le physique : clavier(entrée), souris(entrée), ecran(sortie) disquedur/ssd (entrée et sortie)
- Bus de données = canal de comm entre les différents partie de l'ordinateur. En gros c'est la parole, ou genre l'autoroute.

** Chercher physiquement comment sa se passe dans le CPU avec les puces et les circuts etc 


### Multithreading 

- = utilisation de plusieurs threads dans un programme
- Alterne plusieurs thread sur 1 coeur, s'alterne rapidement ++ donnant l'illusion de la simultanation = Faux parallélisme, multithrad simulé
= Contexte switching 
- Ou alors sont vraiment exe en même temps si plusieurs core = Vrai parallélisme
- Les limites du multithreading sur 1 core = overheads (cout en perf) lorsqu'on passe d'un thread à l'autre. 



#### Piege du multithread ! 

### Race condition 

- Plusieurs thread accéde à une meme ressource partagée au même moment et vont tente de modif la variable en même temps = BEUG, IMPREVISIBLE 
- MUTEX ESSENTIELS 

### Deadlock

- > 2 thread sont bloqués et attendents les ressources que les autres detiennent, tout se stop, rien ne progresse. 

### Starvation (=famine)

- Un thread ne peut jamais accéder à une ressource partagé car il est bloqué par un autre thread. Il n'a jamais assé de temps. 
- Différence avec le Deadlock = deadlock tous les threads sont bloqué, la famine un thread est bloqué sur une période longue mais n estp as complétement bloqué, les autres prennent systématiquement la priorité sur lui. 

### MUTEX (mutual exclusion) 

- Mecanisme de synchronisation. 
- Evite l'accés simultané à une ressource partagée. 
- Evite race condition.
- Vu que nos threads partagent la même mémoire on protége l'accés avec des mutex. Pour ne pas qu'il modifie en même temps la même variable
- Mutex vérouille une section de code, une ressource partagé, pourq'un seul thread puisse l'utiliser à la fois. Il prend, il lock, il utilise, il delock.
- Protége les données partagés. 
- Deadlock= si un mutex n'est pas bien utilisé, les thread peuvent etre bloqué en attendant qu'il soit libérer
- Plusieurs type de mutex 
- Standar = verouille et dévérouille
- Recursif = un thread peut verrouiller un mutex plusieurs fois sans causer de deadlock
- Conditionnel = ? 

### Dans le projet = 

- Donc 1 thread représente un philo 
- Chaque philo va alterner entre 3 etats = penser, manger, dormir
- La ressource partagé c'est les fourchettes. MUTEX sur les fourchettes !
- Fixé un ordre fixe pour la prises des fourchettes 
- Nbr de fourchette = nbr de philo 
- Pour manger des sphaghettos = 2 fourchettes, le philo doit prendre 1 a sa droit 1 a sa gauche
- le philo PENSE a sa fourchette pour manger
- le philo MANGE et repose ses fourchettes
- le philo DORT 
- la simulation STOP = un philo meurt de faim
- Chaque philo doit manger et pas mourir de faim. 
- Les philos ne parlent pas entre eux, ils ne savent pas non plus si qql va mourir.
- Position sur la table : chaque philo à un num allant de 1 + nbr de philo.
- Le numéro 1 est assis entre le dernier et le 2nd. 
- Le numéro 2 est assis entre numéro 1 ( a sa gauche) n°3 ( a sa droite)
- AFFICHAGE 
- Chaque fois qu'un philo change d'état on doit afficher un messages spécifiant sont étant :
````
Prend une fork = timestamp_in_ms X has taken a fork
Mange = timestamp_in_ms X is eating
Dodo = timestamp_in_ms X is sleeping
Pense à manger = timestamp_in_ms X is thinking
Meurt = timestamp_in_ms X died
timestamp = temps en miliseconde, et X = n° du philo
````
- 1 seconde = 1 000 milliseconde 
- Les messages ne doivent pas se chevaucher 
- Si un philo meurt affichage de sa mort dans les 10 millisseconde suivant son décés réel
- IL FAUT eviter que les philo meurent (bien sur), donc bien veiller à ce qu'il ne reste pas trop longtemps sans manger et ainsi survive 
- Quand peuvent ils mourir ?? 

### PARSER 

- Nbr d'arg < 5 = erreur 
- Nbr de philo = 1 (pas assez de fork pour qu'il mange, donc au lieu d'utiliser ses mains il va mourir)
- Pas de nbr negatif, pas de float. int max ? OK ?

### ERREUR de compilation jamais observé avant : 

*** stack smashing detected ***: terminated
- Aborted (core dumped) = dépassement ou écrasement de la mémoire de la pile (stack).
