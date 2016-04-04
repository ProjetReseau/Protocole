#include<stdio.h>
#include<stdlib.h>
#include"protocole.h"
#include<string.h>


char * tr_to_str(trame tr){

  char * mess=calloc(sizeof(int), TAILLE_MAX_MESSAGE);

  switch (tr.type_message){
    case hello:
      sprintf(mess, "HELLO %i %s", tr.taille , tr.message);
      break;

    case quit:
      sprintf(mess, "QUIT");
      break;
    
    case texte:
      sprintf(mess, "MSG %i %s",tr.taille, tr.message);
      break;

    case fileProposition:
      sprintf(mess, "File_P %i %s",tr.taille, tr.message); 
      break;
  
    case fileAcceptation:
      sprintf(mess, "File_A %i %s",tr.taille, tr.message); 
      break;
  
    case fileTransfert:
      sprintf(mess, "File_T %i %s",tr.taille, tr.message); 
      break;
  
    case groupJoin:
      sprintf(mess, "JOIN %i %s",tr.taille, tr.message); 
      break;
  
    case annuaireNew:
      sprintf(mess, "NEW %i %s",tr.taille, tr.message); 
      break;
  
    case annuaireAsk:
      sprintf(mess, "ASK %i %s",tr.taille, tr.message); 
      break;
  
    case annuaireInfo:
      sprintf(mess, "INFO"); 
      break;
    
    default:
      break;
  }

  

  return mess;
}

char * Recup_message(char * mot, char * mess, char * taille){
 
char * pointeur=NULL;
char * buffer=calloc(sizeof(int), TAILLE_MAX_MESSAGE);

  pointeur=strstr(mess, mot);
  if (pointeur!=NULL){
    while(*pointeur != ' '){
      pointeur++;
    }
    pointeur++;
    while(*pointeur != ' '){
      sprintf(taille,"%s%c", taille, *pointeur);
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

//tr->taille=sizeof(mess);
char * taille = calloc(sizeof(char), 8);


  if(strncmp("HELLO", mess, 4)==0){
    tr->type_message=hello;
    strcpy(tr->message, Recup_message("HELLO", mess, taille));
  }
  else if(strncmp("QUIT", mess, 4)==0){
    tr->type_message=quit;
    strcpy(tr->message, Recup_message("QUIT", mess, taille));
  }
  else if (strncmp("MSG", mess, 3)==0){
    tr->type_message=texte;
    strcpy(tr->message, Recup_message("MSG", mess, taille));
  }
  else if (strncmp("File_P", mess, 6)==0){
    tr->type_message=fileProposition;
    strcpy(tr->message, Recup_message("File_P", mess, taille));
  }
  else if (strncmp("File_A", mess, 6)==0){
    tr->type_message=fileAcceptation;
    strcpy(tr->message, Recup_message("File_A", mess, taille));
  }
  else if (strncmp("File_T", mess, 6)==0){
    tr->type_message=fileTransfert;
    strcpy(tr->message, Recup_message("File_T", mess, taille));
  }
  else if (strncmp("JOIN", mess, 4)==0){
    tr->type_message=groupJoin;
    strcpy(tr->message, Recup_message("JOIN", mess, taille));
  }
  else if(strncmp("NEW", mess, 3)==0){
    tr->type_message=annuaireNew;
    strcpy(tr->message, Recup_message("NEW", mess, taille));
  }
  else if(strncmp("ASK", mess, 3)==0){
    tr->type_message=annuaireAsk;
    strcpy(tr->message,Recup_message("ASK", mess, taille));
  }
  else if(strncmp("INFO", mess, 4)==0){
    tr->type_message=annuaireInfo;
    strcpy(tr->message, Recup_message("INFO", mess, taille));
  }
  tr->taille=(int) taille;

  if (sizeof(tr->message)==tr->taille){
	return EXIT_SUCCESS;	
  }

  return EXIT_FAILURE;

}
