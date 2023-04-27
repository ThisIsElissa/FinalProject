//
// Created by eliss on 4/25/2023.
//

#ifndef FINALPROJECT_ERKIR_H
#define FINALPROJECT_ERKIR_H
#include "planet.h"

class erkir : public planet {
private:
    int finishEkir;
    int transductorCount=0;
public:
    void welcome();
    void getFinishErkir();
    void findTransductor();
    void doErkirHub();
    void doMedic();
    int getTransductorCount();
};

#endif //FINALPROJECT_ERKIR_H
