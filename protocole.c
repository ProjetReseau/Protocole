#include<stdio.h>
#include<stdlib.h>
#include"protocole.h"
#include<string.h>


char * tr_to_str(trame tr){

  char * mess=calloc(sizeof(int), TAILLE_MAX_MESSAGE);

  switch (tr.type_message){
    case hello:
      sprintf(mess, "HELLO %s", tr.message);
      break;

    case quit:
      sprintf(mess, "QUIT");
      break;
    
    case texte:
      sprintf(mess, "MSG %s", tr.message);
      break;

    case fileProposition:
      sprintf(mess, "File_P %s", tr.message); 
      break;
  
    case fileAcceptation:
      sprintf(mess, "File_A %s", tr.message); 
      break;
  
    case fileTransfert:
      sprintf(mess, "File_T %s", tr.message); 
      break;
  
    case groupJoin:
      sprintf(mess, "JOIN %s", tr.message); 
      break;
  
    case annuaireNew:
      sprintf(mess, "NEW %s", tr.message); 
      break;
  
    case annuaireAsk:
      sprintf(mess, "ASK %s", tr.message); 
      break;
  
    case annuaireInfo:
      sprintf(mess, "INFO"); 
      break;
    
    default:
      break;
  }

  return mess;
}

char * Recup_message(char * mot, char * mess){
 
char * pointeur=NULL;
char * buffer=calloc(sizeof(int), TAILLE_MAX_MESSAGE);

  pointeur=strstr(mess, mot);
  if (pointeur!=NULL){
    while(*pointeur != ' '){
      pointeur++;
    }
    pointeur++;
    while (*pointeur != '\0'){
      sprintf(buffer,"%s%c", buffer, *pointeur);
      pointeur++;
    }
  }
  else{
    exit(EXIT_FAILURE);
  }
  return buffer;
}


int str_to_tr(char * mess, trame * tr){

tr->taille=sizeof(mess);

  if(strncmp("HELLO", mess, 4)==0){
    tr->type_message=hello;
    strcpy(tr->message, Recup_message("HELLO", mess));
  }
  else if(strncmp("QUIT", mess, 4)==0){
    tr->type_message=quit;
    strcpy(tr->message, Recup_message("QUIT", mess));
  }
  else if (strncmp("MSG", mess, 3)==0){
    tr->type_message=texte;
    strcpy(tr->message, Recup_message("MSG", mess));
  }
  else if (strncmp("File_P", mess, 6)==0){
    tr->type_message=fileProposition;
    strcpy(tr->message, Recup_message("File_P", mess));
  }
  else if (strncmp("File_A", mess, 6)==0){
    tr->type_message=fileAcceptation;
    strcpy(tr->message, Recup_message("File_A", mess));
  }
  else if (strncmp("File_T", mess, 6)==0){
    tr->type_message=fileTransfert;
    strcpy(tr->message, Recup_message("File_T", mess));
  }
  else if (strncmp("JOIN", mess, 4)==0){
    tr->type_message=groupJoin;
    strcpy(tr->message, Recup_message("JOIN", mess));
  }
  else if(strncmp("NEW", mess, 3)==0){
    tr->type_message=annuaireNew;
    strcpy(tr->message, Recup_message("NEW", mess));
  }
  else if(strncmp("ASK", mess, 3)==0){
    tr->type_message=annuaireAsk;
    strcpy(tr->message,Recup_message("ASK", mess));
  }
  else if(strncmp("INFO", mess, 4)==0){
    tr->type_message=annuaireInfo;
    strcpy(tr->message, Recup_message("INFO", mess));
  }
 
return EXIT_SUCCESS;

}
