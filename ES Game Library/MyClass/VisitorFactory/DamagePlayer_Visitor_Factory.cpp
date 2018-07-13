#include "DamagePlayer_Visitor_Factory.h"
#include "../Damage_Visitor.h"
#include "../Enemy.h"


Visitor* DamagePlayer_Visitor_Factory::factoryMethod(GameObject* object){

	return new Damage_Visitor((Enemy*)object);

}

