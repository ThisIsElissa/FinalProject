
#include "planet.h"

#ifndef FINALPROJECT_UTARID_H
#define FINALPROJECT_UTARID_H

class utarid : public planet {
private:
    int utaridHubScenarioChoice;
    int engineerChoice;
    int utaridDoorChoice;
    int transmitterCount = 0;

public:
    void welcomeUtarid();
    void utaridHubScenario();
    void engineerScenario();
    void findingTransmitter();
    void findHub();
    void playUtarid();
    int getTransmitterCount();
};

#endif
