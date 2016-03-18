#include<stdio.h>
#include<stdlib.h>
#include"protocole.h"
#include<string.h>


char * tr_to_str(trame * tr){

  char * mess=calloc(sizeof(int), TAILLE_MAX_MESSAGE);

  switch (tr->type_message){
    case hello:
      sprintf(mess, "HELLO %s", tr->message);
      break;

    case quit:
      sprintf(mess, "QUIT");
      break;
    
    case texte:
      sprintf(mess, "MSG %s", tr->message);
      break;

    case fileProposition:
      sprintf(mess, "File P %s", tr->message); 
      break;
  
    case fileAcceptation:
      sprintf(mess, "File A %s", tr->message); 
      break;
  
    case fileTransfert:
      sprintf(mess, "File T %s", tr->message); 
      break;
  
    case groupJoin:
      sprintf(mess, "JOIN %s", tr->message); 
      break;
  
    case annuaireNew:
      sprintf(mess, "NEW %s", tr->message); 
      break;
  
    case annuaireAsk:
      sprintf(mess, "ASK %s", tr->message); 
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
    if (strcmp(mess, "FILE")>0){
      pointeur=pointeur+3;
    }
    else{
      pointeur++;
    }
    while (*pointeur != '\n'){
      sprintf(buffer,"%s%c", buffer, *pointeur);
      pointeur++;
    }
  }
  else{
    exit(EXIT_FAILURE);
  }
  return buffer;
}


trame str_to_tr(char * mess){

trame tr;
tr.taille=sizeof(mess);

  if(strcmp(mess,"HELLO")>0){
    tr.type_message=hello;
    strcpy(tr.message, Recup_message("HELLO",mess));
  }
  else if(strcmp(mess,"QUIT")==0){
    tr.type_message=quit;
    strcpy(tr.message, Recup_message("QUIT",mess));
  }
  else if (strcmp(mess, "MSG")>0){
    tr.type_message=texte;
    strcpy(tr.message, Recup_message("MSG",mess));
  }
  else if (strcmp(mess, "FILE P")>0){
    tr.type_message=fileProposition;
    strcpy(tr.message, Recup_message("FILE P", mess));
  }
  else if (strcmp(mess, "FILE A")>0){
    tr.type_message=fileAcceptation;
    strcpy(tr.message, Recup_message("FILE A", mess));
  }
  else if (strcmp(mess, "FILE T")>0){
    tr.type_message=fileTransfert;
    strcpy(tr.message, Recup_message("FILE T", mess));
  }
  else if (strcmp(mess, "JOIN")>0){
    tr.type_message=groupJoin;
    strcpy(tr.message, Recup_message("JOIN", mess));
  }
  else if(strcmp(mess,"NEW")>0){
    tr.type_message=annuaireNew;
    strcpy(tr.message, Recup_message("NEW", mess));
  }
  else if(strcmp(mess,"ASK")>0){
    tr.type_message=annuaireAsk;
    strcpy(tr.message,Recup_message("ASK", mess));
  }
  else if(strcmp(mess, "INFO")>0){
    tr.type_message=annuaireInfo;
    strcpy(tr.message, Recup_message("INFO", mess));
  }

 return tr;
}
