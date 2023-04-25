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
void visitedPlanet();// prompts user to choose a different world
void utaridCase();
void veneraCase();

/*

void invRand();//random inventory assignment for items needed

*/

//Inventory
int foundReceiver= 0;
int foundTransductor = 0;
int foundTransmitter = 0;
int inventoryCount = foundReceiver+foundTransductor+foundTransmitter;



int main() {
    intro();
    gamePlay();



    return 0;
}




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
                playAgain();
                break;
            case CHOOSEWORLD:
                worldPrompt();//user chooses world
                break;

            case ERKIR:

                break;

            case UTARID:
                utaridCase();
                break;

            case VENERA:
                veneraCase();

                break;

        }
    }


}


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

    }
}

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
    std::cout<< foundTransductor << "\nTransmitter: " << foundTransmitter << "\n\n\n";
}

void visitedPlanet(){
    std::cout<< "\n================================================================================================\n"
                "You have already searched this world and found an item. The team will have to visit another planet.\n"
                "================================================================================================\n\n";
    worldPrompt();
}


void utaridCase(){
    utarid uTest;
    if(foundTransmitter==0){
        uTest.welcomeUtarid(); //player enters utarid scenario
        if(uTest.getTransmitterCount()==1){
            foundTransmitter++;//adds to transmitter count
            printInv();//prints players current inventory
            worldPrompt();//prompts user to choose new world
        }
        else{
            playAgain();
        }
    }
    else{
        visitedPlanet();//prompts user to choose another planet
    }

}

void veneraCase(){
    venera vTest;
    if(foundReceiver==0){
        vTest.welcomeVenera();//player enters venera scenario
        if(vTest.getReceiverCount() == 1){
            foundReceiver++;//adds to receiver count
            printInv();//prints players current inventory
            worldPrompt();//prompts user to choose new world
        }
        else {
            playAgain();//
        }
    }
    else{
        visitedPlanet();//prompts user to choose another planet
    }

}