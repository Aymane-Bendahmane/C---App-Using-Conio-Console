#include <stdio.h>
#include <stdlib.h>
#include<conio2.h>
#include <windows.h>
struct categorie{
int code;
};
typedef struct categorie cat;
/****************************************/
struct chambre{
int nbr;
int tele;
int nbrcat;
 cat t_cate[9];
};
typedef struct chambre rom;
/*******************************************/
struct hotel {
int nbr_etoils;
char name[50];
char adress[100];
char cph[50];
int tele_hotel;
int id ;
int nbr_chambre;
rom t_chambre[80];
};
typedef struct hotel hot;
/************************************/
struct classe{
int nbr_hotel;
hot t_hotel[8];
};typedef struct classe clas;
/**************************************/
struct reservation{
char S_dat[50];
char E_dat[50];
int nbr_jour;
char chosen_hotel[50];
int room_numbre;
float priz;
};typedef struct reservation rv;
/*************************************/
struct client{
char name[50];
char prenom[50];
char adress[50];
char ville[50];
char pays[50];
char phone[50];
char email[50];
int nbr_reservation;
rv t_resv[50];
};typedef struct client client;
/***********************************************************************************************************************/
cat *saisir_categorie(){
cat *e=malloc(sizeof(cat));
printf("   Code categore          :");
scanf("%d",&e->code);

return e;
}
/****************************************/
void afficher_categorie(cat *e){
printf("Code categore           : %d\n",e->code);
}
/**************************************/
rom *saisir_chambre(){
    int i;
rom *e=malloc(sizeof(rom));

printf("   Le numero du Chambre   :");
scanf("%d",&e->nbr);
printf("   Le telephone du Chambre:");
scanf("%d",&e->tele);
printf("   Le nombre de categorie :");
scanf("%d",&e->nbrcat);
for (i=0 ;  i<e->nbrcat  ; i++){
    e->t_cate[i]=*saisir_categorie();
}

return e;
}
/****************************************/
void afficher_chambre(rom *e){
    int i;
puts("같같같같같같같같같같같같같같같캜HAMBRES같같같같같같같같같같같같같같같같같같같같�\n");
printf("Le numero du Chambre    : %d\n",e->nbr);
printf("Le telephone du Chambre : %d\n",e->tele);
printf("Le nombre de categorie  : %d\n",e->nbrcat);
for (i=0 ;  i<e->nbrcat ; i++){
    afficher_categorie(&e->t_cate[i]);
}

}
/***********************************************/
hot *saisir_hotel(){
int i;
hot *a=malloc(sizeof(hot));
printf("Nombre d'etoiles  :");
scanf("%d",&a->nbr_etoils);
printf("Hotel name        :");
scanf("%s",a->name);
printf("Hotel adress      :");
scanf("%s",a->adress);

printf("Cph (FAUX/VRAI)   :");
scanf("%s",a->cph);
printf("Numero hotel      :");
scanf("%d",&a->tele_hotel);
printf("Hotel Code        :");
scanf("%d",&a->id);
printf("Nombre de chambre :");
scanf("%d",&a->nbr_chambre);
for (i=0   ;    i   <    a->nbr_chambre    ;  i++){

    a->t_chambre[i]=*saisir_chambre();

}
return a;
}
/****************************************************/
void afficher_hotel(hot*a){
int i;
puts("께께께께께께께께께께께께께께께께 HOTEL 께께께께께께께께께께께께께께께께께께께께�\n");
printf("Nombre d'etoiles  : %d\n",a->nbr_etoils);
printf("Hotel name        : %s\n",a->name);
printf("Hotel adress      : %s\n",a->adress);
printf("Cph (FAUX/VRAI)   : %s\n",a->cph);
printf("Numero hotel      : %d\n",a->tele_hotel);
printf("Nombre de chambre : %d\n",a->nbr_chambre);
for (i=0   ;    i   <    a->nbr_chambre   ;  i++){


    afficher_chambre(&a->t_chambre[i]);

}
puts("께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께\n");
}
/***************************************************/
clas *saisir_classes(){
    clrscr();
  textcolor(WHITE);
  gotoxy(1,1);
clas*e=malloc(sizeof(clas));
int i;
cprintf("Nbr Hotel    :");
scanf("%d",&e->nbr_hotel);
  gotoxy(1,3);
for (i=0 ; i  < e->nbr_hotel ; i++ ){
        printf("--------------------------------------------------------------------------------\n");
    e->t_hotel[i]=*saisir_hotel();
}
return e;
}
/***************************************************/
void afficher_classes(clas*e){
    int i;system("cls");
  gotoxy(20,10);
printf("\n--------------------------------------------------------------------------------\n");
printf("                                Nombre Hotel : =======> [%d]\n\n",e->nbr_hotel);
for (i=0 ; i  < e->nbr_hotel ; i++ ){
printf("--------------------------------------------------------------------------------\n");
    afficher_hotel(&e->t_hotel[i]);

}


}
/***************************************************/
void sauvgarder(FILE * f,clas*a){
char name[50];
int i,j,b;
printf("Sauvegarder sous : ");
scanf("%s",name);
f=fopen(name,"w");
fprintf(f,"Nbr Hotel: %d\n",a->nbr_hotel);
for (i=0  ; i < a->nbr_hotel ; i++ ){
fprintf(f,"Nombre d'etoiles  : %d\n",a->t_hotel[i].nbr_etoils);
fprintf(f,"Hotel name        : %s\n",a->t_hotel[i].name);
fprintf(f,"Hotel adress      : %s\n",a->t_hotel[i].adress);
fprintf(f,"Cph (FAUX/VRAI)   : %s\n",a->t_hotel[i].cph);
fprintf(f,"Numero hotel      : %d\n",a->t_hotel[i].tele_hotel);
fprintf(f,"Nombre de chambre : %d\n",a->t_hotel[i].nbr_chambre);
for (j=0 ; j < a->t_hotel[i].nbr_chambre ; j++){
fprintf(f,"Le numero du Chambre    : %d\n",a->t_hotel[i].t_chambre[j].nbr);
fprintf(f,"Le telephone du Chambre : %d\n",a->t_hotel[i].t_chambre[j].tele);
fprintf(f,"Le nombre de categorie  : %d\n",a->t_hotel[i].t_chambre[j].nbrcat);
for (b=0   ;  b <a->t_hotel[i].t_chambre[j].nbrcat ;  b++)   {
fprintf(f,"Code categore           : %d\n",a->t_hotel[i].t_chambre[j].t_cate[b].code);
}
}
}
fclose(f);
}
/**************************************************/
clas *restorer(FILE * f){
clas *a=malloc(sizeof(clas));

char name[33];
int i,j,b;
clrscr();
 textcolor(WHITE);
 textbackground(BLACK);
 gotoxy(1,1);
cprintf("Restaurer : ");
scanf("%s",name);

f=fopen(name,"r");
fscanf(f,"Nbr Hotel: %d\n",&a->nbr_hotel);
for (i=0  ; i < a->nbr_hotel ; i++ ){
fscanf(f,"Nombre d'etoiles  : %d\n",&a->t_hotel[i].nbr_etoils);
fscanf(f,"Hotel name        : %s\n",a->t_hotel[i].name);
fscanf(f,"Hotel adress      : %s\n",a->t_hotel[i].adress);
fscanf(f,"Cph (FAUX/VRAI)   : %s\n",a->t_hotel[i].cph);
fscanf(f,"Numero hotel      : %d\n",&a->t_hotel[i].tele_hotel);
fscanf(f,"Nombre de chambre : %d\n",&a->t_hotel[i].nbr_chambre);
for (j=0 ; j < a->t_hotel[i].nbr_chambre ; j++){
fscanf(f,"Le numero du Chambre    : %d\n",&a->t_hotel[i].t_chambre[j].nbr);
fscanf(f,"Le telephone du Chambre : %d\n",&a->t_hotel[i].t_chambre[j].tele);
fscanf(f,"Le nombre de categorie  : %d\n",&a->t_hotel[i].t_chambre[j].nbrcat);
for (b=0   ;  b <a->t_hotel[i].t_chambre[j].nbrcat ;  b++)   {
fscanf(f,"Code categore           : %d\n",&a->t_hotel[i].t_chambre[j].t_cate[b].code);
}
}
}
fclose(f);
return a;
}
/****************************************************/
clas *ajouter_hotel(clas*e){
e->t_hotel[e->nbr_hotel]=*saisir_hotel();
e->nbr_hotel=e->nbr_hotel+1;
return e;
}
/***************************************************/
clas *ajouter_rom(clas*e){
printf("Chose : \n\n");
int i;
for (i=0 ; i< e->nbr_hotel ; i++){
printf("%d..Hotel\t",i);
}
int a;
scanf("%d\n",&a);
e->t_hotel[a].t_chambre[e->t_hotel[a].nbr_chambre]=*saisir_chambre();
e->t_hotel[a].nbr_chambre=e->t_hotel[a].nbr_chambre+1;
return e;
}
/***************************************************/
void laoding(void){
int i;
char ch=177,ce=178;
textcolor(YELLOW);
//textbackground(WHITENESS);
clrscr();
gotoxy(20,9);
printf("Laoding..!!");
gotoxy(20,10);
for(i=0;i<=26;i++){

    printf("%c",ch);
}
gotoxy(20,10);
for(i=0;i<=26;i++){
Sleep(50);
    printf("%c",ce);

}

}
/****************************************************/

/****************************************************/
rv *saisir_reservation(clas*c){
int i;rv*e=malloc(sizeof(rv));int x;int y;

printf("Date de Debut (jj/mm/aa):");
scanf("%s",e->S_dat);
printf("Date de Fin   (jj/mm/aa):");
scanf("%s",e->E_dat);

printf("--------------------------------Chose You Hotel---------------------------------\n");
for (i=0  ; i<c->nbr_hotel ;i++){
    printf("          %d..%s          \t",i,c->t_hotel[i].name);
}
scanf("%d",&x);
if (x==0){
printf("--------------------------------------------------------------------------------\n");
              printf("Combien De Jour ?(200 DH PAR NUIT !!) : ");
              scanf("%d",&e->nbr_jour);
              e->priz=e->nbr_jour*200;
              }
else {
printf("--------------------------------------------------------------------------------\n");
              printf("Combien De Jour ?(400 DH PAR NUIT !!) : ");
              scanf("%d",&e->nbr_jour);
              e->priz=e->nbr_jour*400;
}

strcpy(e->chosen_hotel,c->t_hotel[x].name);

printf("-------------------------------Available Rooms----------------------------------\n");
for (i=0 ;  i<c->t_hotel[x].nbr_chambre;i++){
    printf("          Room=%d        \t",i);
}
scanf("%d",&y);
e->room_numbre=c->t_hotel[x].t_chambre[y].nbr;

return e;
}
/**************************************************/
void afficher_reservation(rv *e){
printf("----------------------------------------------\n");
printf("========>Debut : %s      | Fin   : %s\n",e->S_dat,e->E_dat);
printf("========>Nombre de Jours : %d\n",e->nbr_jour);
printf("========>Votre Choix     : %s\n",e->chosen_hotel);
printf("========>Room Number     : %d\n",e->room_numbre);
printf("========>Prix            : %fDH\n",e->priz);

}

/****************************************************/

/******************************************************/
client *saisir_client(clas*a){
client *e=malloc(sizeof(client));int i;
printf("Votre Nom   :");
scanf("%s",e->name);
printf("Votre prenom:");
scanf("%s",e->prenom);
printf("Votre Adress:");
scanf("%s",e->adress);
printf("Votre ville :");
scanf("%s",e->ville);
printf("Votre pays  :");
scanf("%s",e->pays);
printf("Votre Phone :");
scanf("%s",e->phone);
printf("Votre Email :");
scanf("%s",e->email);
printf("Nombre de Reservation :");
scanf("%d",&e->nbr_reservation);
for(i=0 ; i<e->nbr_reservation;i++){
     e->t_resv[i]=*saisir_reservation(a);
}
return e;
}
void afficher_client(client*e){
        gotoxy(12,15);int i;
puts("\n께께께께께께께께께께께께께께� RESERVATION 께께께께께께께께께께께께께께께께께께께\n");
printf("Votre Nom   :%s\n",e->name);
printf("Votre prenom:%s\n",e->prenom);
printf("Votre Adress:%s\n",e->adress);
printf("Votre ville :%s\n",e->ville);
printf("Votre pays  :%s\n",e->pays);
printf("Votre Phone :%s\n",e->phone);
printf("Votre Email :%s\n",e->email);
for(i=0 ; i<e->nbr_reservation;i++){

    afficher_reservation(&e->t_resv[i]);
}
puts("께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께\n");
}

/******************************************************/
void facture(FILE*f,client*e){
char name[50];
int i;
printf("Sauvegarder Facture sous : ");
scanf("%s",name);
f=fopen(name,"w");
fprintf(f,"Votre Nom   :%s\n",e->name);
fprintf(f,"Votre prenom:%s\n",e->prenom);
fprintf(f,"Votre Adress:%s\n",e->adress);
fprintf(f,"Votre ville :%s\n",e->ville);
fprintf(f,"Votre pays  :%s\n",e->pays);
fprintf(f,"Votre Phone :%s\n",e->phone);
fprintf(f,"Votre Email :%s\n",e->email);
for(i=0 ; i<e->nbr_reservation;i++){
fprintf(f,"----------------------------------------------\n");
fprintf(f,"========>Debut : %s      | Fin   : %s\n",e->t_resv[i].S_dat,e->t_resv[i].E_dat);
fprintf(f,"========>Nombre de Jours : %d\n",e->t_resv[i].nbr_jour);
fprintf(f,"========>Votre Choix     : %s\n",e->t_resv[i].chosen_hotel);
fprintf(f,"========>Room Number     : %d\n",e->t_resv[i].room_numbre);
fprintf(f,"========>Prix            : %fDH\n",e->t_resv[i].priz);
fprintf(f,"----------------------------------------------\n");
}
fclose(f);
}
/*****************************************************/

int menu(int in){
int a;
int i;
 char temp,ch;

 char items[10][82]={ "-----------------------------------1.SAISIR_HOTEL-------------------------------",
                      "-----------------------------------2.AFFICHER_HOTEL-----------------------------",
                      "-----------------------------------3.SAUVEGARDER_HOTEL--------------------------",
                      "-----------------------------------4.RESTORER_HOTEL-----------------------------",
                      "-----------------------------------5.AJOUTER_HOTEL------------------------------",
                      "-----------------------------------6.AJOUTER_ROOM-------------------------------",
                      "-----------------------------------7.EFFECTUER_RESERVATION----------------------",
                      "-----------------------------------8.AFFICHER_RESERVATION-----------------------",
                      "-----------------------------------8.FACTURE------------------------------------",
                      "-----------------------------------9.Exit---------------------------------------"};
while(1)
 {
   for(i=1;i<=10;i++)
   {
      if(i==in)
      {
        textcolor(BLACK);
        textbackground(WHITE);
      }
      else
      {
        textcolor(GREEN);
        textbackground(BLACK);
   }
  gotoxy(1,i);
  cprintf("%s",items[i-1]);
 }
 ch=getch();
 if(ch==0)
   ch=getch();
 switch(ch)
 {
   case 72:  /* selecting up arrow */
     if(in>1)
       in--;
     break;
   case 80:  /* selecting down arrow */
     if(in<10)
       in++;
     break;
   case 13:
     return in;
  }
 }

}
/*****************************************************/

int main()
{FILE * f;
clas *e;client *k;
  int x=menu(1);
  while(1)
  {int m;

    if(x==1){
            laoding();
            e=saisir_classes();
            system("cls");}
    else if(x==2){
            laoding();
            textcolor(GREEN);
            textbackground(WHITE);
            afficher_classes(e);}
    else if(x==3){
            laoding();
            system("cls");
            sauvgarder(f,e);system("cls");}
    else if(x==4){
            textcolor(WHITE);
            textbackground(BLACK);
            laoding();
            system("cls");
            e=restorer(f);
            system("cls");}
    else if(x==5){
            laoding();
            system("cls");
            e=ajouter_hotel(e);
            system("cls");}
    else if(x==6){
            laoding();
            system("cls");
            e=ajouter_rom(e);
            system("cls");}
    else if(x==7){
            system("cls");
            k=saisir_client(e);
            system("cls");
    }
    else if(x==8){
            laoding();
            textcolor(GREEN);
            textbackground(WHITE);

            system("cls");
            afficher_client(k);
    }
    else if(x==9){
            laoding();
            system("cls");
        facture(f,k);
    }
    else if(x==10){
        system("cls");

            goto out;}
            x=menu(x);
}
out:
return 0;
}
