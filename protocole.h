#ifndef __PROTOCOLE__
#define __PROTOCOLE__

#define MAX_CONNECTE 20
#define TAILLE_PSEUDO 20
#define TAILLE_MAX_MESSAGE 512





typedef enum type {

  hello,               //0
  quit,                //1
  texte,               //2
  fileProposition,     //3
  fileAcceptation,     //4
  fileTransfert,       //5
  groupJoin,           //6
  annuaireNew,         //7
  annuaireAsk,         //8
  annuaireInfo         //9

}type;

typedef struct trame {

  int taille; // Taille du message en octet
  type type_message; //Message texte ? Fichier ? Audio ? Video ?  
  //char pseudo_destination[TAILLE_PSEUDO][MAX_CONNECTE];
  char message[TAILLE_MAX_MESSAGE];

}trame;

int str_to_tr(char * mess, trame * tr);
char * tr_to_str(trame tr);
char * Recup_message(char * mot, char * mess, char * taille);

#endif
