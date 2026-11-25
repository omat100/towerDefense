#include "iostream"
namespace systems{
    template <typename From, typename To>
    void Combat::combat(From *attacker, To *defender){
        if(!attacker || !defender) return;

        if(!attacker->isAlive() || !defender->isAlive()){
            attacker->clearTarget();
            return;
        }

        defender->healthLost(attacker->getDamage());

        if(!defender->isAlive()) attacker->clearTarget();
    }
}