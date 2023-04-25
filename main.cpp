#include <iostream>
#include <cstdlib>
#include "planet.h"
#include "venera.h"
#include "utarid.h"
#include <chrono>
#include <thread>

/*
 * In main. Call gameplay. Gameplay will call V and get Transmitter. Will return transmitter == true.
 * From gameplay to U world. Will return reciever == true.  Will also call check to see if user has all item
 * Will have a check to see if user is dead. Restart if so.
 *
 *
 */




//const storylines
const int GAMEOVER = 0;
const int CHOOSEWORLD = 1;
const int VENERA = 2;
const int ERKIR = 3;
const int UTARID = 4;

//prototypes
int scenarioType = CHOOSEWORLD;//where the initial switch case starts at
void worldPrompt();//function for user to choose world
void gamePlay();// leads to full game/first choice
void playAgain();//prompt user to play again
void intro();//prompt when starting game
void printInv();//print inventory
/*
//prototypes
void wrongInput();//general template for user entering wrong input
void invRand();//random inventory assignment for items needed

*/

//Venera Functions
void roomChoice();//function that prompts user to choose room
void findHub();//function that prompts user to choose direction

//Inventory
int foundReceiver= 0;
int foundTransductor = 0;
int foundTransmitter = 0;
int inventoryCount = foundReceiver+foundTransductor+foundTransmitter;

//finish venera loop


int main() {
    intro();
    gamePlay();



    return 0;
}
/*
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
void wrongInput(){//general template for user entering wrong input
    std::cout<<"You have entered an invalid choice.\n \n";
}

 */



void intro() {
    std::cout
            << "A group of astronomers are in a future setting where intergalactic space travel is made possible "
               "through Astral gates that use hyperspace to travel. Ships can travel through Astral gates to "
               "reach different galaxies and planets.\n\nAmong the astronomers there is Captain Mary Somerville,"
               " the Medic Charles Messier, the scientist and cook Christiaan Huygens, and the engineer Caroline "
               "Herschel.\n\nThe astronomers experienced their communication system breaking as they were exploring"
               " different planets.\nWithout their communication system they are now unable to ask Earth to open an"
               " Astral gate for them to get back home.\n\nAs a team, they must travel back to the previous planets"
               " they visited in the current galaxy they are in to collect supplies from the space hubs and fix "
               "their communication system.\n\nThey need a transmitter, and receiver to replace the "
               "current ones in the communciation system that don't work. If they are unable to fix their "
               "communication system, they will be unable to return home.\n\nAlong the way, you will be helping"
               " them make decisions that will impact whether or not they will make it back to Earth.\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(3)); // pause for 3 seconds
    std::cout << "Press Enter to continue...";
    std::cin.get();
    std::cout << "\n\n";
}

void gamePlay(){
    while(inventoryCount<4){
        switch (scenarioType){
            case GAMEOVER:
                //playAgain();
                break;
            case CHOOSEWORLD:
                worldPrompt();//user chooses world
                break;

            case ERKIR:

                break;

            case UTARID:{
                utarid uTest;
                uTest.welcomeUtarid();
                if(uTest.getTransmitterCount()==1){
                    foundTransmitter++;
                    printInv();
                    worldPrompt();
                }
                else{
                    playAgain();
                }
                break;}

            case VENERA:{
                venera vTest;
                vTest.welcomeVenera();

                if(vTest.getReceiverCount() == 1){
                    foundReceiver++;
                    printInv();
                    worldPrompt();//succeeded, choose world again
                }
                else {
                    playAgain();// p
                }

                break;}

        }
    }


}

/*
void roomChoice(){
    int leftRight;
    std::cout<<"The hub has two doors, the door to the left contains living areas and the door to the right"
               " contains storage. The right storage room door is locked, should they try to unlock it or "
               "search the unlocked room to the left?\n 1) Search Left \n 2) Try to unlock Right \n";
    std::cin>>leftRight;

    do{

        switch(leftRight){
            case 1://living quarters
                std::cout<< "The living quarters are bare of most supplies, it looks like another group must have been here "
                            "since the astronomers last visited. Should the astronomers search the kitchen or the bedroom area "
                            "first?\n 1) Search kitchen\n 2) Search bedroom\n";
                std::cin>> leftRight;

                leftRight = 3;

                break;

            case 2:
                int keyOrSuit;
                std::cout<< "The team is unable to open the door with their space suits on, they might break them. The "
                            "oxygen indicator in the hub shows a safe level, but their suits have not alerted them that "
                            "it is safe. Should they:\n 1) Take off their suits to push on the door\n 2) Keep their suits "
                            "on and search the key in the living area\n";
                std::cin>>keyOrSuit;
                switch(keyOrSuit){
                    case 1:
                        std::cout<<"The oxygen sensor in the hub was faulty. The team has died and you have failed to "
                                   "bring them home.\n";
                        finishVenera=1;
                        scenarioType=GAMEOVER;
                        return;
                    case 2:
                        leftRight=1;
                        break;

                }
                break;
            case 3:
                std::cout<< "The astronomers unlock the storage room door, where there is a broken radio taken apart.\n";
                invRand();
                finishVenera = 1;
                printInv();


                scenarioType = CHOOSEWORLD;
                break;
            case 4:
                std::cout<< "The team finds nothing in the kitchen, except the realization that their hunger levels are "
                            "really high. Should they:\n 1) Find something to eat\n 2) Search the bedroom \n";





        }
    } while(finishVenera==0);



}
*/

void worldPrompt(){//prompt to change case
    int worldChoice;
    std::cout << "The astronomers are gathered around the ship's map to choose which world they will search. "
                 "Choose which world for them below:\n 1) Venera\n 2) Erkir\n 3) Utarid\n";
    std::cin>> worldChoice;
    switch(worldChoice){
        case 1:

            scenarioType=VENERA;

            break;
        case 2:
            scenarioType=ERKIR;
            break;
        case 3:
            scenarioType=UTARID;

            break;
        //default:
            //wrongInput();
    }
}
/*
void findHub(){
    int directionChoice;
    while(receiverCount==0){
        std::cout<< "The team has arrived at Venera. Should the astronomers search for the supply hub by choosing a"
                    " direction, or finding higher ground?\n 1) Choose a direction\n 2) Search "
                    "for higher ground\n";
        std::cin>>directionChoice;
        switch(directionChoice){
            case 1:
                std::cout<< "The astronomers have walked 7 miles and have not found anything. They do not have much "
                            "time to find the hub before it gets dark, they decide to search for higher ground. Once "
                            "they found higher ground they spotted the hub quickly. They wish that they would have "
                            "searched for higher ground first.\n";
                roomChoice();
                return;
            case 2:
                std::cout<< "The astronomers found where the hub was with ease and are glad they did not spend their "
                            "time searching aimlessly.\n";
                roomChoice();
                return;
            default: wrongInput();
        }
    }

}
*/
void playAgain(){
    foundReceiver=0;
    foundTransmitter=0;
    foundTransductor=0;
    std::cout<<"\n\n============= \nYou Lost!\n============= \n\nWould you like to play again? Press 1 to"
               " play again or anything else to exit the game\n";
    std::cin>>scenarioType;

}



void printInv(){
    std::cout<< "=============== \nCurrent Inventory\n===============\nReceiver: " << foundReceiver << "\nTransductor: ";
    std::cout<< foundTransductor << "\nTransmitter: " << foundTransmitter << '\n';
}

