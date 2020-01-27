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

monster choixCible(int index,monster M1,monster M2, monster M3, monster M4){
	int selection;
	monster cible;
	int l;
	switch (index){
		case 1:
			printf("Choisir entre le monstre 1 et le monstre 2\n");
			scanf("%d",&selection);
			while(l!=1){
				switch(selection){
					case 1:
						if (M1.PV<=0){
							printf("Le monstre 1 est mort\n");
						}
						else{
							cible=M1;
							l++;
						}
						break;

					case 2:
						if (M2.PV<=0){
							printf("Le monstre 2 est mort\n");
						}
						else{
							cible=M2;
							l++;
						}
						break;

					default:
						printf("Choisir entre le monstre 1 et le monstre 2\n");
						scanf("%d",&selection);
					break;
				}
			}
			break;

		case 2:
			printf("Choisir entre le monstre 1, le monstre 2 et le monstre 3\n");
			scanf("%d",&selection);
			while(l!=1){
				switch(selection){
					case 1:
						if (M1.PV<=0){
							printf("Le monstre 1 est mort\n");
						}
						else{
							cible=M1;
							l++;
						}
						break;

					case 2:
						if (M2.PV<=0){
							printf("Le monstre 2 est mort\n");
						}
						else{
							cible=M2;
							l++;
						}
						break;

					case 3:
						if (M3.PV<=0){
							printf("Le monstre 3 est mort\n");
						}
						else{
							cible=M3;
							l++;
						}
						break;

					default:
						printf("Choisir entre le monstre 1, le monstre 2 et le monstre 3\n");
						scanf("%d",&selection);
					break;
				}
			}
			break;

		case 3:
			printf("Choisir entre le monstre 1, le monstre 2 et le monstre 3\n");
			scanf("%d",&selection);
			while(l!=1){
				switch(selection){
					case 1:
						if (M1.PV<=0){
							printf("Le monstre 1 est mort\n");
						}
						else{
							cible=M1;
							l++;
						}
						break;

					case 2:
						if (M2.PV<=0){
							printf("Le monstre 2 est mort\n");
						}
						else{
							cible=M2;
							l++;
						}
						break;

					case 3:
						if (M3.PV<=0){
							printf("Le monstre 3 est mort\n");
						}
						else{
							cible=M3;
							l++;
						}
						break;

					case 4:
						if (M4.PV<=0){
							printf("Le monstre 4 est mort\n");
						}
						else{
							cible=M4;
							l++;
						}
						break;

					default:
						printf("Choisir entre le monstre 1, le monstre 2, le monstre 3 et le monstre 4\n");
						scanf("%d",&selection);
					break;
				}
			}
			break;
	}
	return cible;
}

int main(){
	int MPM;
	joueur Tank={150,150,10,10,0,10,1,0,10,1,1,"Tank"};
	joueur Healer={100,100,30,30,0,5,1,0,10,1,2,"Healer"};
	joueur Rogue={50,50,20,20,0,15,1,0,10,1,3,"Rogue"};
	MPM=rand()%15+5;
	monster M1={rand()%100+25,MPM,MPM,0,rand()%10+5,1,1};
	printf("Point de vie du monstre %d:%d\n",M1.ID,M1.PV);
	MPM=rand()%15+5;
	monster M2={rand()%100+25,MPM,MPM,0,rand()%10+5,1,2};
	printf("Point de vie du monstre %d:%d\n",M2.ID,M2.PV);
	MPM=rand()%15+5;
	monster M3={rand()%100+25,MPM,MPM,0,rand()%10+5,1,3};
	printf("Point de vie du monstre %d:%d\n",M3.ID,M3.PV);
	MPM=rand()%15+5;
	monster M4={rand()%100+25,MPM,MPM,0,rand()%10+5,1,4};
	printf("Point de vie du monstre %d:%d\n",M4.ID,M4.PV);
	int Choix;
	int i;
	int j;
	int k;
	int l;
	int nbMort;
	monster cible;
	printf("Point de vie du Tank :%d\n",Tank.PV);
    printf("Point de vie du Healer :%d\n",Healer.PV);
    printf("Point de vie du Rogue :%d\n",Rogue.PV);
	for(i=1;i<=3;i++){
		do{
			for(j=1;j<=3;j++){
					switch(j){
	          case 1:
							printf("Tour du tank \n");
              k=0;
              while(k!=1){
								printf("Choisir entre attaque(1)/defense(2)/Sort de poison(3) et Antidote(4)\n");
								scanf("%d",&Choix);
								switch (Choix){
									default:
										printf("Choisir entre attaque(1)/defense(2)/Sort de poison(3) et Antidote(4)[Boucle]\n");
										scanf("%d",&Choix);
										break;

									case 1:
										cible=choixCible(i,M1,M2,M3,M4);
										printf("Attaque puissante du joueur\n");
										printf("-%d PV\n",Tank.Att);
										cible.PV-=TourJeu(Choix,Tank,j)/cible.Def;
										printf("Point de vie du monstre :%d\n",cible.PV);
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
											cible=choixCible(i,M1,M2,M3,M4);
											Tank.MP-=2;
											cible.isTox=1;
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
							printf("Tour du Healer \n");
              while(k!=1){
                  printf("Choisir entre attaque(1)/defense(2)/Sort de poison(3) et Antidote(4)\n");
                  scanf("%d",&Choix);
                  switch (Choix){
                      default:
                        printf("Choisir entre defense(1)/attaque(2)/Sort de poison(3) et Antidote(4)\n");
                        scanf("%d",&Choix);
                        break;

                      case 1:
												cible=choixCible(i,M1,M2,M3,M4);
                        printf("Attaque puissante du joueur\n");
												printf("-%d PV\n",Healer.Att);
												cible.PV-=TourJeu(Choix,Healer,j)/cible.Def;
												if (cible.PV<=0) nbMort++;
												printf("Point de vie du monstre :%d\n",cible.PV);
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
													cible=choixCible(i,M1,M2,M3,M4);
													Healer.MP-=2;
													cible.isTox=1;
													k++;
													break;
												}

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
							printf("Tour du Rogue \n");
              while(k!=1){
                  printf("Choisir entre attaque(1)/defense(2)/Sort de poison(3) et Antidote(4)\n");
                  scanf("%d",&Choix);
                  switch (Choix){
                      default:
                        printf("Choisir entre defense(1)/attaque(2)/Sort de poison(3) et Antidote(4)\n");
                        scanf("%d",&Choix);
                        break;

                      case 1:
												cible=choixCible(i,M1,M2,M3,M4);
                        printf("Attaque puissante du joueur\n");
												printf("-%d PV\n",Rogue.Att);
												cible.PV-=TourJeu(Choix,Rogue,j)/cible.Def;
												printf("Point de vie du monstre :%d\n",cible.PV);
												if (cible.PV<=0) nbMort++;
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
													cible=choixCible(i,M1,M2,M3,M4);
													Rogue.MP-=2;
													cible.isTox=1;
													k++;
													break;
												}

                      case 4:
                        Rogue.isTox=0;
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


			for(int h=1;h<i+1;h++){
				switch(h){
					case 1:
						cible=M1;
						break;

					case 2:
						cible=M2;
						break;

					case 3:
						cible=M3;
						break;

					case 4:
						cible=M4;
						break;
				}

				if(cible.PV>0){
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
	                    while(cible.MP<=0 && Choix==3){
	                        Choix=rand()%3+1;
	                    }
	                    switch (Choix){

	                        case 1:
	                            printf("Attaque puissante du Monstre\n");
	                            printf("-%d PV\n",cible.Att);
	                            Agro.PV-=TourJeuM(Choix,M1,0)/Agro.Def;
	                            printf("Point de vie du %c:%d\n",Agro.Nom,cible.PV);
	                            k++;
	                            break;

	                        case 2:
	                            TourJeuM(Choix,cible,0);
	                            k++;
	                            break;

	                        case 3:
	                            if(cible.MP<=0){
	                                break;
	                            }
	                            else {
	                                cible.MP-=2;
	                                Agro.isTox=1;
	                                k++;
	                                break;
	                            }
	                            break;

	                        case 4:
	                            cible.isTox=0;
	                            k++;
	                            break;
	                    }
	                }
	            }

					if(cible.isTox==1){
						printf("Le poison inflige -5 au monstre %d\n",cible.ID);
						cible.PV-=5;
						printf("Point de vie du monstre :%d\n",cible.PV);
		      }
				}
			}
    while(nbMort==i+1||Tank.PV>0||Rogue.PV>0||Healer.PV>0);
    return 0;
    }
	}
