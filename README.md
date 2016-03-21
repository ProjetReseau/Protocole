# Protocole

18/03 : Améliration à apporter :
Récupération du nom de fichier puis utilisation d'un script ? pour récupérer des données (taille, empalcement, format,..) de ce fichier et les placer dans le message

- [ ] Fonctions `str_to_tr` et `tr_to_str` à tester concrêtement.
- [ ] Code mettant en forme le protocole dédié.

### Description du protocole :

*A FAIRE : terminer de décrir le protocole.*
Problème couche session : tcp, flux d'octet -> gérer la taille des messages (tout émis = tout reçu)

* __HELLO *pseudo*__ : Pour s'annoncer et donner son pseudo
* __MSG *message*__ : Pour envoyer un message
* __QUIT__ : Pour dire qu'on se déconnecte
* __FILE P *nom_fichier (à déterminer)*__ : Proposer un fichier à envoyer au destinataire
* __FILE A *nom_fichier (à déterminer)*__ : Accepter l'envoi du fichier
* __FILE T *nom_fichier données*__ : Paquet contenant des données du fichier en cours de transfert
  * *à implémenter éventuellement :* __FILE E *(à déterminer)*__ : Fin de l'envoi du fichier
* __JOIN *nom_groupe*__ : Permet de rejoindre un groupe
* __NEW *pseudo (le notre)*__ : Permet de s'enregistrer auprès du serveur d'annuaire
* __ASK *pseudo (d'un autre)*__ : Demande l'extrémité correspondant au pseudo au serveur d'annuaire 
* __INFO__ : Demande la liste de tout ceux qui se sont enregistrés auprès du serveur d'annuaire
* ...
