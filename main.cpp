#include <iostream>
#include <chrono>
#include <thread>

class planet {
private:
    int userPlanet;
    int directionChoice;
    int morePlanet;

public:
    int receiverCount = 0;
    int transmitterCount = 0;
    int inventoryCount = receiverCount+transmitterCount;
    void wrongInput() {//general template for user entering wrong input
        std::cout << "You have entered an invalid choice.\n \n" << std::endl;
    }

    virtual void playUtarid(){
        /*all scenarios and functions for planet Utarid*/
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

    void findHub() {
        std::cout
                << "\nThe team is beginning their search. Should the astronomers search for the supply hub by choosing "
                   "a direction, or\nfinding higher ground?\n1) Choose a direction\n2) Search for higher ground\n";
        std::cin >> directionChoice;
        if (directionChoice == 1) {
            std::cout << "\n\nThe astronomers have walked 7 miles and have not found anything. They do not have much "
                         "time to find the hub before it\ngets dark, they decide to search for higher ground. Once "
                         "they found higher ground they spotted the hub quickly. They\nwish that they would have "
                         "searched for higher ground first.\n";
        } else if (directionChoice == 2) {
            std::cout << "\n\nThe astronomers found where the hub was with ease and are glad they did not spend their "
                         "time searching aimlessly.\n";
        }
    }

    void planetChoice() { // user chooses a planet
        std::cout << "The astronomers are gathered around the ship's map to choose which world they will search. "
                     "\nChoose which world for them below:\n1) Venera\n2) Utarid\n";
        std::cin >> userPlanet;
        std::cout << " " << std::endl;
        switch (userPlanet) {
            case 1: // venera
                std::cout << "Venera gameplay...\n" << std::endl;
                break;
            case 2: // utarid
                playUtarid();
                //explorePlanet();
                break;
            default:
                wrongInput();
        }
    }

    void explorePlanet(){
        std::cout << "\nWould you like to explore another planet for more supplies?\n1) Yes\n2) No\n";
        std::cin >> morePlanet;
        std::cout << "\n" << std::endl;
        if (morePlanet ==2) {
            if (inventoryCount !=2){
                std::cout << "The crew did not gather all the supplies needed to fix the communication system, and"
                             " were lost in space forever.\n" << std::endl;
                exit(0);
            }
        }
        else if(morePlanet == 1){
            planetChoice();
        }
    }
};


class venera : public planet {
public:
    void welcomeVenera() {
        std::cout << "\nThe crew has successfully landed on planet Venera!\n" << std::endl;
    }
};


class utarid : public planet {
private:
    int utaridHubScenarioChoice;
    int engineerChoice;
    int utaridDoorChoice;

public:
    void welcomeUtarid() {
        std::cout << "\nThe crew has successfully landed on planet Utarid!\n" << std::endl;
    }

    void utaridHubScenario() {
        std::cout << "\nUh oh! Some of the crew have concerns about looking for the supply hub.\nData gathered by "
                     "Scientist Charles Messier shows high levels of radiation on this planet.\nShould the crew:\n1) "
                     "Wait for the sun to go down and search for the supply hub in the dark \n2) Take their chances and"
                     " hope their space suits protect them from the elevated levels of radiation" << std::endl;
        std::cin >> utaridHubScenarioChoice;
        if (utaridHubScenarioChoice == 1) {
            std::cout << "\n\nAfter closer inspections it was discovered that the spacesuits would not have been "
                         "able to handle the intense radiation.The crew was glad that they decided to wait.\n"
                      << std::endl;
        } else if (utaridHubScenarioChoice == 2) {
            std::cout << "\n\nThe radiation level on this planet was too much for the crew's spacesuits to handle.\n"
                         "No one survived after stepping out of the space craft.\n" << std::endl;
            std::cout << "Better luck next time!\n" << std::endl;
            exit(0);
        }

    }

    void engineerScenario() {
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
            exit(0);
        } else if (engineerChoice == 2) {
            std::cout << "\n\nHigh risk, high reward! Luckily there was enough oxygen for the entire crew, and the crew "
                         "was able to conserve enough\nfuel for the journey home.\n\n\nThe sun has finally gone down and it "
                         "is time to search for the supply hub.\n" << std::endl;
        }
    }

    void findingReceiver() {
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
            std::cout << "\nAfter a couple minutes of searching the crew was able to find the receiver and return "
                         "back to the safety of the\nspaceship.\n" << std::endl;
            receiverCount = receiverCount++;
        } else if (utaridDoorChoice == 2) {
            std::cout << "\n\nThe crew discovered that zero gravity and highly specialized cutting saws were not a "
                         "good match. They unfortunately lostcontrol of the saw and it damaged their spacesuits as "
                         "it floated around in zero gravity.\n" << std::endl;
            exit(0);
        }
    }

    void playUtarid() override {
        welcomeUtarid();
        utaridHubScenario();
        engineerScenario();
        findHub();
        findingReceiver();
        explorePlanet();
    }
};

int main(){
    planet game1;
    game1.intro();
    game1.planetChoice();

    planet* ptr = new utarid(); // lets me access the playUtarid method from my utarid subclass to my planet base class
    ptr-> playUtarid();
    delete ptr;

}
