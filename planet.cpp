#include "planet.h"

#include <iostream>
#include <chrono>
#include <thread>

     void planet::wrongInput() {//general template for user entering wrong input
        std::cout << "You have entered an invalid choice.\n \n" << std::endl;
    }


    void planet::planetChoice() { // user chooses a planet
        int userPlanet;
        std::cout << "The astronomers are gathered around the ship's map to choose which world they will search. "
                     "\nChoose which world for them below:\n1) Venera\n2) Utarid\n";
        std::cin >> userPlanet;
        std::cout << " " << std::endl;
        switch (userPlanet) {
            case 1: // venera
                std::cout << "Venera gameplay...\n" << std::endl;
                break;
            case 2: // utarid
                std::cout << "Utarid gameplay...\n" << std::endl;
                //explorePlanet();
                break;
            default:
                wrongInput();
                break;
        }
    }
    /*


    void invRand(){
        std::srand(time(NULL));
        int randScene = std::rand() % 3 ;

        switch (randScene) {
            case 1:
                receiverCount+=1;
                std::cout << "============= \nItems Found \n============= \nReceiver: 1\n";
                break;

            case 2:
                transmitterCount+=1;
                std::cout << "============= \nItems Found \n============= \nTransmitter: 1\n";
                break;

            case 3:
                transductorCount+=1;
                std::cout << "============= \nItems Found \n============= \nTransductorCount: 1\n";
                break;
        }

    }
     */