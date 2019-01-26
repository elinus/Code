#include <iostream>
#include <MallardDuck.h>
#include <ModelDuck.h>
#include <RedheadDuck.h>
#include <RubberDuck.h>
#include <DecoyDuck.h>
#include <FlyRocketPowered.h>

int main()
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
