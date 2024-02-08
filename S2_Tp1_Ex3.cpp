//Ecrire un programme qui affiche le contenu d’un fichier texte en ignorant les
//lignes de commentaires et en supprimant les espaces qui se trouvent en début de
//ligne. Les lignes dont les deux premiers caractères non blancs sont ‘// ‘ seront
//considérées comme des lignes de commentaires.

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

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

	//lecture et affichage du contenu du fichier ligne par ligne 
	while ((fgets(ligne,sizeof(ligne),fp)) != NULL){
		if ((ligne[0]=='/') && (ligne[1]=='/')){continue;} //ignorer les lignes de commentaires
		int i=0;
		while (isspace(ligne[i])){i++;} 
		for (i;ligne[i] != '\0'; i++){ //commencer à afficher des qu'on trouve la premiere lettre de la ligne
			printf("%c",ligne[i]);
		}
	}
	

	//fermuture du fichier
	fclose (fp);
	
	return 0;
}
