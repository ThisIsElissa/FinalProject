#include <iostream>
#include <chrono>
#include <thread>

class planet {
private:
    int userPlanet;
    int directionChoice;


public:
    void wrongInput() {//general template for user entering wrong input
        std::cout << "You have entered an invalid choice.\n \n" << std::endl;
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
                   "their communication system.\n\nThey need a transmitter, transductor, and receiver to replace the "
                   "current ones in the communciation system that doesn't work. If they are unable to fix their "
                   "communication system, they will be unable to return home.\n\nAlong the way, you will be helping"
                   " them make decisions that will impact whether or not they will make it back to Earth.\n\n";
        std::this_thread::sleep_for(std::chrono::seconds(3)); // pause for 3 seconds
        std::cout << "Press Enter to continue...";
        std::cin.get(); // wait for user to press Enter
        std::cout << "\n\n"; // add extra line breaks
    }

    void planetChoice() {
            std::cout << "The astronomers are gathered around the ship's map to choose which world they will search. "
                         "Choose which world for them below:\n 1) Venera\n 2) Erkir\n 3) Utarid\n";
            std::cin >> userPlanet;
            switch (userPlanet) {
                case 1: // venera;
                    break;
                case 2: // erkir
                    break;
                case 3: // utarid
                    break;
                default:
                    wrongInput();
            }
        }

    void findHub(){
        std::cout<< "The team has arrived on the planet. Should the astronomers search for the supply hub by choosing a"
                    " direction, or finding higher ground?\n 1) Choose a direction\n 2) Search "
                    "for higher ground\n";
        std::cin>>directionChoice;
        if (directionChoice == 1){
            std::cout<< "The astronomers have walked 7 miles and have not found anything. They do not have much "
                        "time to find the hub before it gets dark, they decide to search for higher ground. Once "
                        "they found higher ground they spotted the hub quickly. They wish that they would have "
                        "searched for higher ground first.\n";
        }
        else if (directionChoice == 2){
            std::cout<< "The astronomers found where the hub was with ease and are glad they did not spend their "
                        "time searching aimlessly.\n";
        }
    }
}; // using recurrsion we could add planetChoice() again to pick a new planet


    class venera : public planet {
    public:
        void welcomeVenera() {
            std::cout << "\nThe crew has successfully landed on planet Venera!\n" << std::endl;

        }
    };

    class erkir : public planet {
    public:
        void welcomeErkir() {
            std::cout << "\nThe crew has successfully landed on planet Erkir!\n" << std::endl;
        }

    };

    class utarid : public planet {
    private:
        int utaridHubScenarioChoice;
        int engineerChoice;

    public:
        void welcomeUtarid() {
            std::cout << "\nThe crew has successfully landed on planet Utarid!\n" << std::endl;
        }

        void utaridHubScenario() {
            std::cout << "Uh oh! Some of the crew have concerns about looking for the supply hub.\nData gathered by "
                         "Scientist Charles Messier shows high levels of radiation on this planet.\nShould the crew:\n1) "
                         "Wait for the sun to go down and search for the supply hub in the dark \n2) Take their chances and"
                         " hope their space suits protect them from the elevated levels of radiation" << std::endl;
            std::cin >> utaridHubScenarioChoice;
            if (utaridHubScenarioChoice == 1) {
                std::cout << "\nAfter closer inspections it was discovered that the spacesuits would not have been "
                             "able to handle the intense radiation.The crew was glad that they decided to wait.\n"
                          << std::endl;
            } else if (utaridHubScenarioChoice == 2) {
                std::cout << "\nThe radiation level on this planet was too much for the crew's spacesuits to handle.\n"
                             "No one survived after stepping out of the space craft.\n" << std::endl;
                std::cout << "Better luck next time!\n" << std::endl;
                exit(2);


            }

        }

        void engineerScenario() {
            std::cout << "\nWhile waiting for the sun to go down, Engineer Caroline Herschel was doing some routine "
                         "maintenance and realized that the ship was low on fuel.\nShe determined that the only way to "
                         "conserve fuel for the remainder of the journey home is to get rid of some equipment. Caroline must "
                         "decide which piece of equipment to get rid of, while also keeping the ship operational. \nShould "
                         "she:\n1) Get rid of the navigation system, and hope someone can read a map\n2) Get rid of the air "
                         "filtration system, and hope they have enough stored/residual oxygen to make it home."
                      << std::endl;
            std::cin >> engineerChoice;
            if (engineerChoice == 1) {
                std::cout << "\nEveryone on the crew can read a map, but there is no universal map of space, and "
                             "without the navigation system the crew couldn't make it back home to Earth and were lost"
                             " in space forever.\n" << std::endl;
                exit(1);
            }
            else if (engineerChoice == 2){
                    std:: cout <<"\nHigh risk, high reward! Luckily there was enough oxygen for the entire crew, and the crew "
                                 "was able to conserve enough fuel for the journey home.\n\nThe sun has finally gone down and it "
                                 "is time to search for the supply hub.\n" << std:: endl;
            }
        }

        void findingReceiver(){
            /*code*/
        }
    };

int main(){
    planet *p;
    utarid u;
    p = &u;

    p->planetChoice(); // call the planetChoice function using the base class pointer
    u.welcomeUtarid(); // call the welcomeUtarid function using the base class pointer
    u.utaridHubScenario(); // call the utaridHubScenario function directly from the utarid object
    p->findHub(); // call the findHub function using the base class pointer

}


