# Protocole

12/04 :
Application du protocole en trois étapes (Application, Présentation, Session)
Attention changement typage fonction tr_to_str.

- [ ] passer de trame à string: tr_to_str(data, trame_write);
- [ ] passer de string à trame: str_to_tr(data, &trame);

18/03 : Améliration à apporter :
Récupération du nom de fichier puis utilisation d'un script ? pour récupérer des données (taille, empalcement, format,..) de ce fichier et les placer dans le message

### Description du protocole :

*A FAIRE : terminer de décrir le protocole.*
Problème couche session : tcp, flux d'octet -> gérer la taille des messages (tout émis = tout reçu)


* __taille HELLO *pseudo*__ : Pour s'annoncer et donner son pseudo
* __taille MSG *message*__ : Pour envoyer un message
* __taille QUIT__ : Pour dire qu'on se déconnecte
* __taille FILE P *nom_fichier (à déterminer)*__ : Proposer un fichier à envoyer au destinataire
* __taille FILE A *nom_fichier (à déterminer)*__ : Accepter l'envoi du fichier
* __taille FILE T *nom_fichier données*__ : Paquet contenant des données du fichier en cours de transfert
  * *à implémenter éventuellement :* __FILE E *(à déterminer)*__ : Fin de l'envoi du fichier
* __taille JOIN *nom_groupe*__ : Permet de rejoindre un groupe
* __taille NEW *pseudo (le notre)*__ : Permet de s'enregistrer auprès du serveur d'annuaire
* __taille ASK *pseudo (d'un autre)*__ : Demande l'extrémité correspondant au pseudo au serveur d'annuaire 
* __taille INFO__ : Demande la liste de tout ceux qui se sont enregistrés auprès du serveur d'annuaire
* ...
