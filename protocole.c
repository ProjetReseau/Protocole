#include<stdio.h>
#include<stdlib.h>
#include"protocole.h"
#include<string.h>


int tr_to_str(char * message, trame tr){ //retourne la longueur final de message pour avoir la taille à envoyer dans write

  if (tr.type_message==fileTransfert){
    FileProtocole(message, tr);
  }
  else {
    ApplicationA(message, tr);
    PresentationA(message, tr);
    SessionA(message, tr);
  }
  //printf("Message envoyé : %s\n", message);
  return strlen(message);

}

int FileProtocole(char * message, trame tr){

  sprintf(message, "%i File_T ", tr.taille);
  char taille[6];
  sscanf(message, "%s", taille);
  char * ptr_dest=message+strlen(taille)+strlen("File_T")+2;
  char * ptr_src=tr.message;
  memcpy(ptr_dest,ptr_src,TAILLE_MAX_MESSAGE);

  return EXIT_SUCCESS;
}

int ApplicationA(char * message, trame tr){

  switch (tr.type_message){
    case hello:
      sprintf(message, "HELLO %s", tr.message);
      break;

    case quit:
      sprintf(message, "QUIT");
      break;

    case texte:
      sprintf(message, "MSG %s", tr.message);
      break;

    case fileProposition:
      sprintf(message, "File_P %s", tr.message);
      break;

    case fileAcceptation:
      sprintf(message, "File_A %s", tr.message);
      break;

    case fileTransfert:
      sprintf(message, "File_T %s", tr.message);
      break;

    case groupJoin:
      sprintf(message, "JOIN %s", tr.message);
      break;

    case annuaireNew:
      sprintf(message, "NEW %s", tr.message);
      break;

    case annuaireAsk:
      sprintf(message, "ASK %s", tr.message);
      break;

    case annuaireInfo:
      sprintf(message, "INFO %s", tr.message);
      break;

    default:
      break;
  }

 return EXIT_SUCCESS;

}

int PresentationA(char * message, trame tr){ //à définir

  return EXIT_SUCCESS;
}

int SessionA(char * message, trame tr){ //Rajoute la taille des données dans le message

  char mess[TAILLE_MAX_MESSAGE+32];
  sprintf(mess,"%s",message);
  if (tr.type_message==quit){
    sprintf(message, "0 %s", mess);
  }
  else {
    sprintf(message, "%i %s", tr.taille, mess);
  }
  return EXIT_SUCCESS;

}


int str_to_tr(char * message, trame * tr){
  //printf("Message reçu : %s\n", message);
  char mot[6];
  char taille[6];
  sscanf(message, "%s %s", taille, mot);
  char * ptr_src=message+strlen(taille)+strlen("File_T")+2;
  if (strncmp("File_T", mot, 6)==0){
    tr->type_message=fileTransfert;
    tr->taille=atoi(taille);
    memcpy(tr->message, ptr_src, TAILLE_MAX_MESSAGE);
  }

  else{
    SessionR(message, tr);
    PresentationR(message,tr);
    if (ApplicationR(message, tr)==EXIT_FAILURE){
      printf("Attention tous les paquets émis n'ont pas été reçu... Message à renvoyer\n");
      return EXIT_FAILURE;
    }
  }
  return EXIT_SUCCESS;
}


int SessionR(char * message, trame * tr){ //Remplit le champ tr.taille

   char taille[6];
   char tmp[TAILLE_MAX_MESSAGE+32];

   sscanf(message, "%s", taille);
   tr->taille=atoi(taille);

   sprintf(tmp, "%s", message+strlen(taille)+1);
   sprintf(message, "%s", tmp);

   return EXIT_SUCCESS;
}

int PresentationR(char * message, trame * tr){ //A définir

  return EXIT_SUCCESS;

}

int ApplicationR(char * message, trame * tr){//Remplit le champ tr.message et tr.type_message

  char mot[6];

  sscanf(message, "%s", mot);
  //printf("message :ici->%s<-ici\n", message);
  sprintf(tr->message,"%s",message+strlen(mot)+1);

  if(strncmp("HELLO", mot, 4)==0){
    tr->type_message=hello;
  }
  else if(strncmp("QUIT", mot, 4)==0){
    tr->type_message=quit;
  }
  else if (strncmp("MSG", mot, 3)==0){
    tr->type_message=texte;
  }
  else if (strncmp("File_P", mot, 6)==0){
    tr->type_message=fileProposition;
  }
  else if (strncmp("File_A", mot, 6)==0){
    tr->type_message=fileAcceptation;
  }
  else if (strncmp("File_T", mot, 6)==0){
    tr->type_message=fileTransfert;
  }
  else if (strncmp("JOIN", mot, 4)==0){
    tr->type_message=groupJoin;
  }
  else if(strncmp("NEW", mot, 3)==0){
    tr->type_message=annuaireNew;
  }
  else if(strncmp("ASK", mot, 3)==0){
    tr->type_message=annuaireAsk;
  }
  else if(strncmp("INFO", mot, 4)==0){
    tr->type_message=annuaireInfo;
  }

  if (tr->type_message==quit){
    if (tr->taille==0){
      return EXIT_SUCCESS;
    }
    else{
      return EXIT_FAILURE;
    }
  }
  else if ((int)strlen(tr->message)==tr->taille){
      return EXIT_SUCCESS;
    }
  else{
      return EXIT_FAILURE;
  }
}
