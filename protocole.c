#include<stdio.h>
#include<stdlib.h>
#include"protocole.h"
#include<string.h>


int tr_to_str(char * message, trame tr){ //retourne la longueur final de message pour avoir la taille à envoyer dans write
 
  ApplicationA(message, tr);
  PresentationA(message, tr);
  SessionA(message);

  return strlen(message);

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
      sprintf(message, "INFO"); 
      break;
    
    default:
      break;
  }

 return EXIT_SUCCESS;

}

int PresentationA(char * message, trame tr){ //à définir

  return EXIT_SUCCESS;
}

int SessionA(char * message){ //Rajoute la taille des données dans le message
  
  int taille=strlen(message);
  char mess[TAILLE_MAX_MESSAGE];

  sprintf(mess,"%s",message);

  sprintf(message, "%i %s", taille, mess);
 
  return EXIT_SUCCESS;

} 


int str_to_tr(char * message, trame * tr){

  if (SessionR(message)==EXIT_SUCCESS){ //On continue de transposer en trame si le message est reçu en totalité
    PresentationR(message,tr);
    ApplicationR(message, tr);
  }
  else{
    printf("Attention tous les paquets émis n'ont pas été reçu... Message à renvoyer\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

int SessionR(char * message){ //Vérifie la taille indiquée et la taille reçue
 
   char taille[6];
   sscanf(message, "%s", taille);

   sprintf(message,"%s",message+strlen(taille)+1);

   if (atoi(taille)==sizeof(message)){
     return EXIT_SUCCESS;
   }
   else{
     return EXIT_FAILURE;
  }

}

int PresentationR(char * message, trame * tr){ //A définir
   
  return EXIT_SUCCESS; 

}

int ApplicationR(char * message, trame * tr){//Remplit le champ tr.message et tr.type_message

  char mot[6];

  sscanf(message, "%s", mot);
  
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
 
  return EXIT_SUCCESS;

}
