//
// Created by eliss on 4/25/2023.
//

#include "erkir.h"
#include <iostream>
#include <thread>

void erkir::welcome()
{
    std::cout << "The crew has reached planet Erkir!" << std::endl;
    std::cout << "Shortly after arriving at Erkir, someone has become mysteriously sick.\n";
    doMedic();
    doErkirHub();
    getFinishErkir();
}

void erkir::findTransductor()
{
    transductorCount++;
}

void erkir::doMedic()
{
    // - Medic: Someone gets mysteriously sick, and the medic has to give them the correct medication. (Choices will be what medicine to give while taking into consideration symptoms)
    bool isSick = true; // assume someone is sick

    std::cout << "Cold symptoms are clear and present. Charlies Messier, the medic, is going to have to administer a treatment.\n";

    while (isSick)
    {
        std::cout << "What medicine should be administered?\n";
        std::cout << "1. Penicillin: Effective against bacterial infections. Side effects may include allergic reactions and gastrointestinal issues.\n";
        std::cout << "2. Benzyl Peroxide: Topical treatment for acne.\n";
        int choice;
        std::cin >> choice;



        if (choice == 1)
        {
            std::cout << "Penicillin administered. The patient's condition improves, and they are no longer sick.\n";
            isSick = false; // person is no longer sick
        }
        else if (choice == 2)
        {
            std::cout << "Benzyl Peroxide administered. Unfortunately, benzyl peroxide is ineffective for treating colds, and the patient's condition does not improve.\n";
            // retry scenario
        }
        else
        {
            std::cout << "Invalid choice or medicine not available. Please choose a valid option.\n";
        }
    }
}

int erkir::getTransductorCount()
{
    return transductorCount;
}

void erkir::getFinishErkir()
{
    if (getTransductorCount()) {
        std::cout << "Having obtained the transductor, the crew has finished business on planet Erkir.\n";
        std::cout << "The crew hastily departs from the planet before someone gets sick again.\n";
    }
}

void erkir::doErkirHub()
{
    int roomChoice;
    // TODO: arrival at hub, search of three different hub rooms, one has transductor, one has nothing, and one room that makes a crew member sick again for some reason:
    // Prompt the user to choose which room to search
    while (getTransductorCount() == 0)
    {
        std::cout << "Which hub room do you want to search? (Enter 1, 2, or 3): ";
        std::cin >> roomChoice;

        if (roomChoice == 1)
        {
            std::cout << "The room the crew decides to enter automatically traps them for an inconvenient\n";
            std::cout << "yet still tolerable amount of time.\n";
            std::cout << "Enjoy the next 12 seconds of contemplation and regret.\n";
            std::cout << "(WAITING).....................\n";
            std::this_thread::sleep_for(std::chrono::seconds(12));
        }
        else if (roomChoice == 2)
        {
            std::cout << "A crew member entered a conspicuous room. Spontaneously, an illness befalls them.\n";
            std::cout << "To your utmost inconvenience, the crew member begins feeling cold symptoms strangely instantaneously.\n";
            std::cout << "It is time for medic Charlie Messier to administer a treatment.\n";
            std::cout << "Whoops, you ran out of penicilin after treating a crew member when you landed.\n";
            std::cout << "Everyone quickly succumbs to the illness.\n";
            return;
        }
        else if (roomChoice == 3)
        {
            std::cout << "The crew found the transductor in a storage closet. Let's get out of here.\n";
            findTransductor();
        }
        else
        {
            std::cout << "Invalid choice. Please choose a valid option.\n";
        }
    }
}