#include "planet.h"

#ifndef FINALPROJECT_VENERA_H
#define FINALPROJECT_VENERA_H

class venera : public planet {
private:
    int finishVenera;
    int receiverCount=0;
public:
    void welcomeVenera();
    void roomChoice();
    int getFinishVenera();
    int getReceiverCount();
    void findHub();
    //int kitchenScenario();
};

#endif //FINALPROJECT_VENERA_H