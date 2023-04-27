#ifndef FINALPROJECT_PLANET_H
#define FINALPROJECT_PLANET_H


class planet {
private:

public:
    virtual void welcome() = 0;
    static void wrongInput();//general template for user entering wrong input
    //void findHub();
    void planetChoice();
    void explorePlanet();
    void invRand();
};
/*
#ifndef FINALPROJECT_VENERA_H
#define FINALPROJECT_VENERA_H

class venera : public planet {
public:
    void welcomeVenera();
    void roomChoice();
};
#endif //FINALPROJECT_VENERA_H
*/

#endif //FINALPROJECT_PLANET_H
