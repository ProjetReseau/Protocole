#define MAX_CONNECTE 20
#define TAILLE_PSEUDO 20
#define TAILLE_MAX_MESSAGE 512



typedef enum type {

  hello,
  quit,
  texte,
  fileProposition,
  fileAcceptation,
  fileTransfert,
  groupJoin,
  annuaireNew,
  annuaireAsk,
  annuaireInfo

}type;

typedef struct trame {

  int taille; // Taille du truc en octet
  type type_message; //Message texte ? Fichier ? Audio ? Video ?  
  //char pseudo_destination[TAILLE_PSEUDO][MAX_CONNECTE];
  char message[TAILLE_MAX_MESSAGE];

}trame;
