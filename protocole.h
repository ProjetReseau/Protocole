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
int tr_to_str(char * message, trame tr);

int ApplicationA(char * message, trame tr);
int PresentationA(char * message, trame tr);
int SessionA(char * message, trame tr);

int FileProtocole(char * message, trame tr);

int ApplicationR(char * message, trame * tr);
int PresentationR(char * message, trame * tr);
int SessionR(char * message, trame * tr);

#endif
