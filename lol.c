#include <stdio.h>
#include <stdlib.h>

struct Joueur
{
	int PV;
	int PVMax;
	int MP;
	int MPMax;
	int isTox;
	int Att;
	int Def;
	int XP;
	int XPMax;
	int LVL;
	int ID;
    char Nom[6];
};

typedef struct Joueur joueur;

struct Monster
{
	int PV;
	int MP;
	int MPMax;
	int isTox;
	int Att;
	int Def;
	int ID;
};

typedef struct Monster monster;

int TourJeu(int NAction, joueur lol, int IndexP){
	switch(NAction){
		case 1:
			return lol.Att;
			lol.Def=1;
			break;

		case 2:
			lol.Def=4;
			return 0;
			break;

		case 3:
			return 1;
			lol.Def=1;
			break;

		case 4:
			lol.isTox=0;
			lol.Def=1;
			return 0;
			break;
	}

}

int TourJeuM(int NAction, monster lol, int IndexM){
	switch(NAction){
		case 1:
			return lol.Att;
			lol.Def=1;
			break;

		case 2:
			lol.Def=4;
			return 0;
			break;

		case 3:
			return 1;
			lol.Def=1;
			break;

		case 4:
			lol.isTox=0;
			lol.Def=1;
			return 0;
			break;
	}
}
int main(){
	joueur Tank={150,150,10,10,0,10,1,0,10,1,1,"Tank"};
	joueur Healer={100,100,30,30,0,5,1,0,10,1,2,"Healer"};
	joueur Rogue={50,50,20,20,0,15,1,0,10,1,3,"Rogue"};
	monster M1={50,10,10,0,5,1,1};
	int Choix;
	int i;
	int j;
	int k=0;
	printf("%d\n",Choix);
	printf("Point de vie du monstre :%d\n",M1.PV);
	printf("Point de vie du Tank :%d\n",Tank.PV);
    printf("Point de vie du Healer :%d\n",Tank.PV);
    printf("Point de vie du Rogue :%d\n",Tank.PV);
	for(i=1;i<=3;i++){
		do{
			for(j=1;j<=3;j++){
					switch(j){
                        case 1:
                            k=0;
				            printf("Tour du tank \n");
                            while(k!=1){
								printf("Choisir entre attaque(1)/defense(2)/Sort de poison(3) et Antidote(4)\n");
								scanf("%d",&Choix);
								switch (Choix){
									default:
										printf("Choisir entre attaque(1)/defense(2)/Sort de poison(3) et Antidote(4)[Boucle]\n");
										scanf("%d",&Choix);
										break;

									case 1:
										printf("Attaque puissante du joueur\n");
										printf("-%d PV\n",Tank.Att);
										M1.PV-=TourJeu(Choix,Tank,j)/M1.Def;
										printf("Point de vie du monstre :%d\n",M1.PV);
										k++;
										break;


									case 2:
										TourJeu(Choix,Tank,j);
										k++;
										break;

									case 3:
										if(Tank.MP<=0){
											printf("Pas assez de mana\n");
											printf("Choisir entre attaque(1)/defense(2) et Antidote(4)[Boucle]\n");
											scanf("%d",&Choix);
											break;
										}
										else {
											Tank.MP-=2;
											M1.isTox=1;
											k++;
											break;
										}

									case 4:
										Tank.isTox=0;
										k++;
										break;
								}
							}
                            if(Tank.isTox==1){
                                printf("Le poison inflige -5 au %c\n",Tank.Nom);
                                Tank.PV-=5;
                                printf("Point de vie du %c :%d\n",Tank.Nom,Tank.PV);
                            }
							break;

						case 2:
                            k=0;
							printf("Tour du Healer");
                            while(k!=1){
                                printf("Choisir entre attaque(1)/defense(2)/Sort de poison(3) et Antidote(4)\n");
                                scanf("%d",&Choix);
                                switch (Choix){
                                    default:
                                        printf("Choisir entre defense(1)/attaque(2)/Sort de poison(3) et Antidote(4)\n");
                                        scanf("%d",&Choix);
                                        break;

                                    case 1:
                                        printf("Attaque puissante du joueur\n");
										printf("-%d PV\n",Healer.Att);
										M1.PV-=TourJeu(Choix,Healer,j)/M1.Def;
										printf("Point de vie du monstre :%d\n",M1.PV);
										k++;
										break;

                                    case 2:
                                        TourJeu(Choix,Healer,j);
										k++;
										break;

                                    case 3:
                                        if(Healer.MP<=0){
											printf("Pas assez de mana\n");
											printf("Choisir entre attaque(1)/defense(2) et Antidote(4)[Boucle]\n");
											scanf("%d",&Choix);
											break;
										}
                                        else {
											Healer.MP-=2;
											M1.isTox=1;
											k++;
											break;
										}
                                        break;
                                    case 4:
                                        Healer.isTox=0;
										k++;
                                        break;
                                }
                            }
                            if(Healer.isTox==1){
                                printf("Le poison inflige -5 au %c\n",Healer.Nom);
                                Healer.PV-=5;
                                printf("Point de vie du %c :%d\n",Healer.Nom,Healer.PV);
                            }
                            break;

						case 3:
                            k=0;
							printf("Tour du Rogue");
                            while(k!=1){
                                printf("Choisir entre attaque(1)/defense(2)/Sort de poison(3) et Antidote(4)\n");
                                scanf("%d",&Choix);
                                switch (Choix){
                                    default:
                                        printf("Choisir entre defense(1)/attaque(2)/Sort de poison(3) et Antidote(4)\n");
                                        scanf("%d",&Choix);
                                        break;

                                    case 1:
                                        printf("Attaque puissante du joueur\n");
										printf("-%d PV\n",Rogue.Att);
										M1.PV-=TourJeu(Choix,Rogue,j)/M1.Def;
										printf("Point de vie du monstre :%d\n",M1.PV);
										k++;
										break;

                                    case 2:
                                        TourJeu(Choix,Rogue,j);
										k++;
										break;

                                    case 3:
                                        if(Rogue.MP<=0){
											printf("Pas assez de mana\n");
											printf("Choisir entre attaque(1)/defense(2) et Antidote(4)[Boucle]\n");
											scanf("%d",&Choix);
											break;
										}
                                        else {
											Rogue.MP-=2;
											M1.isTox=1;
											k++;
											break;
										}
                                        break;

                                    case 4:
                                        Rogue.isTox=0;
										k++;
                                        break;

																				case 5:
																				

							}
						}

						k++;
						break;


                                }
                            }
                            if(Rogue.isTox==1){
                                printf("Le poison inflige -5 au %c\n",Rogue.Nom);
                                Rogue.PV-=5;
                                printf("Point de vie du %c :%d\n",Rogue.Nom,Rogue.PV);
                            }
							break;
                    }

            }

			if(M1.PV>0){
                joueur Agro;
                switch(rand()%3+1){
                    case 1:
                        Agro=Tank;
                        break;
                    case 2:
                        Agro=Healer;
                        break;
                    case 3:
                        Agro=Rogue;
                        break;
                }
                while(k!=1){
                    Choix=rand()%4+1;
                    while(M1.MP<=0 && Choix==3){
                        Choix=rand()%3+1;
                    }
                    switch (Choix){
                        default:
                            break;

                        case 1:
                            printf("Attaque puissante du Monstre\n");
                            printf("-%d PV\n",M1.Att);
                            Agro.PV-=TourJeuM(Choix,M1,0)/Agro.Def;
                            printf("Point de vie du %c:%d\n",Agro.Nom,M1.PV);
                            k++;
                            break;

                        case 2:
                            TourJeuM(Choix,M1,0);
                            k++;
                            break;

                        case 3:
                            if(M1.MP<=0){
                                break;
                            }
                            else {
                                M1.MP-=2;
                                Agro.isTox=1;
                                k++;
                                break;
                            }
                            break;

                        case 4:
                            M1.isTox=0;
                            k++;
                            break;
                    }
                }
            }
			if(M1.isTox==1){
				printf("Le poison inflige -5 au monstre\n");
				M1.PV-=5;
				printf("Point de vie du monstre :%d\n",M1.PV);
            }
        }
        while(M1.PV>0&&Tank.PV>0);
        return 0;
    }
}
