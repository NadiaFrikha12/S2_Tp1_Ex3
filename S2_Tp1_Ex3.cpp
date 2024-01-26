//Ecrire un programme qui affiche le contenu d’un fichier texte en ignorant les
//lignes de commentaires et en supprimant les espaces qui se trouvent en début de
//ligne. Les lignes dont les deux premiers caractères non blancs sont ‘// ‘ seront
//considérées comme des lignes de commentaires.

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void supression_espace (char* ligne){
	for (int i=0; ligne[i] != '\0'; i++){
		if ( ! isspace(ligne[i]) ) {
			for (int j=i; ligne[j] != '\0' ; j++){ //décalage
				ligne[j]=ligne[j+1];
			}
		}
		else{
			break;
		}
	}
}

void supression_commentaire (char *ligne){
		if ((ligne[0]=='/')&& (ligne[1]=='/')){
			ligne[0]='\0' ; //marquer la ligne comme vide 
		}		
}

void affiche_fichier (FILE *fp){
	
	//déplacer le curceur de fichier au debut
	rewind (fp);
	
	//lecture et affichage du contenu du fichier ligne par ligne 
	char ligne[100]; //pour désigner chaque ligne du fichier
	while ((fgets(ligne,sizeof(ligne),fp)) != NULL){
		// Appel de la fonction de suppression des espaces au début de chaque ligne
        suppression_espace(ligne);
        
        // Appel de la fonction de suppression des lignes de commentaires
        suppression_commentaire(ligne);
        
        //affichage des lignes non vide
        if (ligne[0]!='\0'){
        	puts(ligne);
		}
	}
}

int main(){
	FILE *fp;
	char nom[10]; //le nom du fichier à ouvrir
	char ligne[100]; //pour désigner chaque ligne du fichier
	
	//lire le nom du fichier
	printf("donner le nom du fichier a ouvrir: ");
	gets(nom);
	
	//ouvrir le fichier en mode read
	fp=fopen(nom,"r"); 
	
	//verifier si le pointeur du fichier est valide
	if (fp == NULL){
		printf("le fichier n'a pas put etre ouvert");
		return 0;
	}
	

	//appel de fonction affichage
	affiche_fichier (fp);

	//fermuture du fichier
	fclose (fp);
	
	return 0;
}
