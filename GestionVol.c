#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int code;
    char destination[20];
    char date[20];
    int nbr_sieges;
} Vol;

Vol vol[100];
int nbr_vol = 0;

void ajouter_vol(){
    printf("Veuillez renseigner le code: ");
    scanf("%d", &vol[nbr_vol].code);
    // vol[nbr_vol].code = nbr_vol;
    printf("Veuillez renseigner la destination: ");
    scanf("%s", vol[nbr_vol].destination);
    printf("Veuillez renseigner la date du vol: ");
    scanf("%s", vol[nbr_vol].date);
    printf("Veuillez renseigner le nombre de sieges: ");
    scanf("%d", &vol[nbr_vol].nbr_sieges);
    nbr_vol++;
    printf("Le vol a ete ajouter avec succes :) \n");
}

void reserv_siege(){
    int code_reserv;
    printf("Entrez le code du vol: ");
    scanf("%d", &code_reserv);
    for(int i = 0; i < nbr_vol; i++)
    {
        if(vol[i].code==code_reserv){
            if(vol[i].nbr_sieges != 0 )
            {    
                vol[code_reserv-1].nbr_sieges--;
                printf("La reservation est faite :) \n");
                return  ;
            }
            else{
                printf("Plus de sieges disponibles \n");
                return ; 
            }
        }   
    }
    printf("Ce vol n'existe pas.\n");
        
} 
void annul_reserv(){
    int code_reserv;
    printf("Entrez le code du vol dont vous souhaitez annuler la reservation : ");
    scanf("%d", &code_reserv);
    for(int i = 0; i < nbr_vol; i++)
    {
        if(vol[i].code==code_reserv){
            vol[code_reserv-1].nbr_sieges++;
            printf("La reservation a ete annuler avec succes :( \n");
            return  ;
        }
    }
    printf("Ce vol n'existe pas.\n");       
}
void affiche_info(){
    if(nbr_vol != 0){
        for(int i=0; i<nbr_vol; i++){
            printf("Les vols sont: \n code:%d \n destination: %s, \n date: %s, \n Nombre de sieges: %d", vol[i].code, vol[i].destination, vol[i].date, vol[i].nbr_sieges);
            printf("\n ***********************************\n");
        
        }
    }
    else{
        printf("Il n'y a pas de vol. ");
        }
}
void affiche_fichier() {
    FILE *file = fopen("NosVols.txt", "w");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    fprintf(file, "Code\tDestination\tDate\t\tSieges_Restants\n");
    fprintf(file, "----------------------------------------------------\n");
    for (int i = 0; i < nbr_vol; i++) {
        fprintf(file, "%d %-15s %-10s %d\n",
                vol[i].code,
                vol[i].destination,
                vol[i].date,
                vol[i].nbr_sieges);
    }
    fclose(file);
    printf("Les donnees ont ete sauvegardees dans 'NosVols.txt' avec succes !\n");
}


 int main (){
    int choix;
   do {
        printf("\n--- Gestion des Reservations de Vols ---\n");
        printf("1. Ajouter un vol\n");
        printf("2. Reserver un siege\n");
        printf("3. Annuler une reservation \n");
        printf("4. Afficher les informations des vols et le nombre de sièges restants\n");
        printf("5. Sauvegarder dans un fichier texte\n");
        printf("Votre choix: ");
        scanf("%d",&choix);
        switch (choix) {
            case 1: ajouter_vol(); break;
            case 2: reserv_siege(); break;
            case 3: annul_reserv(); break;
            case 4: affiche_info(); break;
            case 5: affiche_fichier(); break;
            default: printf("Entrez un  nombre entre 1 et 5. ");
}
    }while(choix!=5);
    

 
 }