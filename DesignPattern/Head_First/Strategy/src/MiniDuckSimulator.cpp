#include <iostream>
#include <Strategy/MallardDuck.h>
#include <Strategy/ModelDuck.h>
#include <Strategy/RedheadDuck.h>
#include <Strategy/RubberDuck.h>
#include <Strategy/DecoyDuck.h>
#include <Strategy/FlyRocketPowered.h>

int main(int argc, char *argv[])
{
    Duck *duck;
    MallardDuck *mallard = new MallardDuck();
    duck = mallard;
    duck->performFly();
    duck->performQuack();
    duck->display();
    duck->swim();
    
    std::cout << "\n";

    RedheadDuck *redhead = new RedheadDuck();
    duck = redhead;
    duck->performFly();
    duck->performQuack();
    duck->display();
    duck->swim();
    
    std::cout << "\n";
  
    RubberDuck *rubber = new RubberDuck();
    duck = rubber;
    duck->performFly();
    duck->performQuack();
    duck->display();
    duck->swim();
    
    std::cout << "\n";

    DecoyDuck *decoy = new DecoyDuck();
    duck = decoy;
    duck->performFly();
    duck->performQuack();
    duck->display();
    duck->swim();
    
    std::cout << "\n";
    
    ModelDuck *model = new ModelDuck();
    duck = model;
    duck->performFly();
    duck->setFlyBehaviour(new FlyRocketPowered());
    duck->performFly();

    return 0;
}
