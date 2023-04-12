#include <iostream>

//const storylines
const int GAMEOVER = 0;
const int CHOOSEWORLD = 1;
const int VENERA = 2;
const int ERKIR = 3;
const int UTARID = 4;
const int VARRIVAL =5;

//prototypes
void intro();
void wrongInput();
void gamePlay();
int scenarioType = CHOOSEWORLD;


int main() {
   intro();
   gamePlay();




    return 0;
}

void intro(){
    std::cout << "A group of astronomers are in a future setting where intergalactic space travel is made possible through Astral "
                 "gates that use hyperspace to travel. Ships can travel through Astral gates to reach different galaxies and planets. "
                 "Among the astronomers there is Captain Mary Somerville, the Medic Charles Messier, the scientist and cook Christiaan "
                 "Huygens, and the engineer Caroline Herschel. The astronomers experienced their communication system breaking as they "
                 "were exploring different planets. Without their communication system they are now unable to ask Earth to open an Astral "
                 "gate for them to get back home. As a team, they must travel back to the previous planets they visited in the current "
                 "galaxy they are in to collect supplies from the space hubs and fix their communication system. They need a transmitter, "
                 "transductor, and receiver to replace the current ones in the communciation system that doesn't work. If they are unable to"
                 " fix their communication system, they will be unable to return home. Along the way, you will be helping them make decisions "
                 "that will impact whether or not they will make it back to Earth. \n";
}
void wrongInput(){
    std::cout<<"You have entered an invalid choice.\n";
}

void gamePlay(){
    do{
        switch (scenarioType){
            case CHOOSEWORLD:
                int worldChoice;
                std::cout << "The astronomers are gathered around the ships map to choose which world they will search. "
                             "Choose which world for them below:\n 1) Venera\n 2) Erkir\n 3) Utarid\n";
                std::cin>> worldChoice;
                if (worldChoice == 1){
                    scenarioType=VENERA;
                }
                else if(worldChoice==2){
                    scenarioType=ERKIR;
                }
                else if(worldChoice==3){
                    scenarioType=UTARID;
                }
                else{
                    wrongInput();
                    scenarioType=CHOOSEWORLD;
                }

                break;

            case VENERA:
                int directionChoice;
                std::cout<< "The team has arrived at Venera. Should the astronomers search for the supply hub by choosing a"
                            " direction, or finding higher ground?\n 1) North\n 2) South\n 3) East\n 4) West\n 5) Search "
                            "for higher ground\n";
                std::cin>>directionChoice;
                if(directionChoice<5){
                    std::cout<< "The astronomers have walked 7 miles and have not found anything. They do not have much "
                                "time to find the hub before it gets dark, they decide to search for higher ground. Once "
                                "they found higher ground they spotted the hub quickly. They wish that they would have "
                                "searched for higher ground first.\n";
                    scenarioType = VARRIVAL;

                }
                else if(directionChoice==5){
                    std::cout<< "The astronomers found where the hub was with ease and are glad they did not spend their "
                                "time searching aimlessly.\n";
                    scenarioType = VARRIVAL;
                }
                else{
                    wrongInput();
                    scenarioType=VENERA;
                }
                break;

            case ERKIR:
                break;

            case UTARID:
                break;

            case VARRIVAL:
                int roomChoice;
                std::cout<<"The hub has two rooms, the room to the left contains living areas and the room to the right"
                           " contains storage. The right room door is locked, should they try to unlock it or "
                           "search the unlocked room to the left?\n 1) Left\n 2) Right\n";
                std::cin>>roomChoice;
                break;
        };
    } while (scenarioType>0);


}