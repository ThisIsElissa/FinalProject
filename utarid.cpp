//
// Created by elissa on 4/24/2023.
//
#include <iostream>
#include "utarid.h"

    void utarid::welcome() {
        std::cout << "\nThe crew has successfully landed on planet Utarid!\n" << std::endl;
        utaridHubScenario();

    }

    void utarid::utaridHubScenario() {
        int utaridHubScenarioChoice;
        std::cout << "\nUh oh! Some of the crew have concerns about looking for the supply hub.\nData gathered by "
                     "Scientist Charles Messier shows high levels of radiation on this planet.\nShould the crew:\n1) "
                     "Wait for the sun to go down and search for the supply hub in the dark \n2) Take their chances and"
                     " hope their space suits protect them from the elevated levels of radiation" << std::endl;
        std::cin >> utaridHubScenarioChoice;
        if (utaridHubScenarioChoice == 1) {
            std::cout << "\n\nAfter closer inspections it was discovered that the spacesuits would not have been "
                         "able to handle the intense radiation.The crew was glad that they decided to wait.\n"
                      << std::endl;
            engineerScenario();
        } else if (utaridHubScenarioChoice == 2) {
            std::cout << "\n\nThe radiation level on this planet was too much for the crew's spacesuits to handle.\n"
                         "No one survived after stepping out of the space craft.\n" << std::endl;
            std::cout << "Better luck next time!\n" << std::endl;
            return;
        }

    }

    void utarid::engineerScenario() {
        int engineerChoice;
        std::cout << "\nWhile waiting for the sun to go down, Engineer Caroline Herschel was doing some routine "
                     "maintenance and realized that\nthe ship was low on fuel. She determined that the only way to "
                     "conserve fuel for the remainder of the journey home is to get rid of some equipment. Caroline "
                     "must decide which piece of equipment to get rid of, while also keeping the ship\noperational. "
                     "Should she:\n1) Get rid of the navigation system, and hope someone can read a map\n2) Get rid of "
                     "the air filtration system, and hope they have enough stored/residual oxygen to make it home."
                  << std::endl;
        std::cin >> engineerChoice;
        if (engineerChoice == 1) {
            std::cout << "\n\nEveryone on the crew can read a map, but there is no universal map of space, and "
                         "without the navigation system the crew couldn't make it back home to Earth and were lost"
                         " in space forever.\n" << std::endl;
            return;
        } else if (engineerChoice == 2) {
            std::cout << "\n\nHigh risk, high reward! Luckily there was enough oxygen for the entire crew, and the crew "
                         "was able to conserve enough\nfuel for the journey home.\n\n\nThe sun has finally gone down and it "
                         "is time to search for the supply hub.\n" << std::endl;
            findHub();
        }
    }

    void utarid::findingTransmitter() {
        int utaridDoorChoice;
        std::cout << "\n\nThe crew enters the supply hub and discovers that the artificial gravity generator is "
                     "broken, and they must float\nthrough the hub. After finding the room labeled storage they"
                     " discover it is locked via a passcode! The crew is divided\nas to how to open the door. Some"
                     " want to try all possible combinations of numbers, while others want to cut through the "
                     "titanium door. It is up to Captain Mary Somerville to make the crucial decision. Should she:"
                     "\n1) Try all possible combinations and risk being locked out\n2) Attempt to cut through the"
                     " titanium doors while floating and not damage their spacesuits" << std::endl;
        std::cin >> utaridDoorChoice;
        if (utaridDoorChoice == 1) {
            std::cout << "\n\nCaptain Mary decided to try her hand at cracking the passcode. She decided to try the"
                         " hub identification number first,\n0560012039, and was shocked to find out it worked. "
                         "The crew was ecstatic they were able to unlock the door their first\nattempt.\n"
                      << std::endl;
            std::cout << "\nAfter a couple minutes of searching the crew was able to find the transmitter and return "
                         "back to the safety of the\nspaceship.\n" << std::endl;
            transmitterCount++;
        } else if (utaridDoorChoice == 2) {
            std::cout << "\n\nThe crew discovered that zero gravity and highly specialized cutting saws were not a "
                         "good match. They unfortunately lostcontrol of the saw and it damaged their spacesuits as "
                         "it floated around in zero gravity.\n" << std::endl;
            return;
        }
    }

void utarid::findHub() {
    int directionChoice;
    std::cout
            << "\nThe team is beginning their search. Should the astronomers search for the supply hub by choosing "
               "a direction, or\nfinding higher ground?\n1) Choose a direction\n2) Search for higher ground\n";
    std::cin >> directionChoice;
    if (directionChoice == 1) {
        std::cout << "\n\nThe astronomers have walked 7 miles and have not found anything. They do not have much "
                     "time to find the hub before it\ngets dark, they decide to search for higher ground. Once "
                     "they found higher ground they spotted the hub quickly. They\nwish that they would have "
                     "searched for higher ground first.\n";
        findingTransmitter();
        
    } else if (directionChoice == 2) {
        std::cout << "\n\nThe astronomers found where the hub was with ease and are glad they did not spend their "
                     "time searching aimlessly.\n";
        findingTransmitter();
    }
}
    void utarid::playUtarid() {
        welcome();
        utaridHubScenario();
        engineerScenario();
        findHub();
        findingTransmitter();
    }
int utarid::getTransmitterCount(){
    return transmitterCount;
}