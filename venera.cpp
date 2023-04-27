#include <iostream>
#include "venera.h"

void venera::welcome() {
        std::cout << "\nThe crew has successfully landed on planet Venera!\n" << std::endl;
        findHub();
    }

void venera::findHub(){

    int directionChoice;
    while(receiverCount==0){
        std::cout<< "Should the astronomers search for the supply hub by choosing a"
                    " direction, or finding higher ground?\n 1) Choose a direction\n 2) Search "
                    "for higher ground\n";
        std::cin>>directionChoice;
        switch(directionChoice){
            case 1:
                int toxicWater;
                std::cout<< "The astronomers come across a mysterious body of water while walking.\n"
                            "Scientist Christiaan Huygens believes it may release a toxic gas.\n"
                            "Should they:\n 1) Continue walking past it\n 2) Turn around and search "
                            "for higher ground\n";
                std::cin>> toxicWater;
                if(toxicWater==1){
                    std::cout<< "The scientist was right, the entire group passed out as they walked past "
                                "the gas and died from extended exposure.";
                    return;
                }
                else if(toxicWater==2){
                    std::cout<< "The astronomers found where the hub was with ease after finding higher ground. They are "
                                "glad they did not risk walking past the potentially toxic water.\n";
                    roomChoice();
                    return;
                }
                return;
            case 2:
                std::cout<< "The astronomers found where the hub was with ease and are glad they did not spend their "
                            "time searching aimlessly.\n";
                roomChoice();
                return;
            default: planet::wrongInput();
        }
    }

}


    void venera::roomChoice(){
        int leftRight;
        std::cout<<"The hub has two doors, the door to the left contains living areas and the door to the right"
                   " contains storage. The right storage room door is locked, should they try to unlock it or "
                   "search the unlocked room to the left?\n 1) Search Left \n 2) Try to unlock Right \n";
        std::cin>>leftRight;

        do{

            switch(leftRight){
                case 1:
                    std::cout << "They found a key as they searched the living quarters!\n";
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
                            receiverCount = 0;// 0 means dead
                            //scenarioType=GAMEOVER;
                            return;
                        case 2:
                            leftRight=1;
                            break;

                    }
                    break;
                case 3:
                    std::cout<< "The astronomers unlock the storage room door, where there is a broken radio taken apart.\n"
                                "=============== \nItems Found\n===============\nReceiver: 1\n\n\n";
                    receiverCount = 1; // 1 means completed
                    return;
                default: wrongInput();
            }
        } while(receiverCount==0);

    }

    int venera::getReceiverCount(){
        return receiverCount;
    }




    /*
    void kitchenScenario(){
        case 1://living quarters
            std::cout<< "The living quarters are bare of most supplies, it looks like another group must have been here "
                        "since the astronomers last visited. Should the astronomers search the kitchen or the bedroom area "
                        "first?\n 1) Search kitchen\n 2) Search bedroom\n";
        std::cin>> leftRight;
        leftRight +=1;


        "The scientist has found a key for the locked storage room."
        "The team goes to unlock the storage room door.\n";


        break;
        case 2:
            std::cout<< "The team finds nothing in the kitchen, except the realization that their hunger levels are "
                        "really high. Should they:\n 1) Search the bedroom\n 2) Find something to eat\n";
        std::cin >> leftRight;
        leftRight +=2;
        break;

        case 3:
            std::cout<< "After searching the bedroom, they find the storage room key! \n"
                        "Should they:\n 1) Find something to eat\n 2) Unlock storage room\n";
        std::cin >> leftRight;
        leftRight +=3;
        break;
        case 4:
            std::cout<< "Which food should the team eat:\n 1) Expired canned fish\n 2) Expired mystery vegetable\n";

        std::cin >> leftRight;
        leftRight +=3;
        break;
}
*/