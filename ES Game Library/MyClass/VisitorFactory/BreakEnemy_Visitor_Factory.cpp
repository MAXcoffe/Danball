#include "BreakEnemy_Visitor_Factory.h"
#include "../BreakEnemy_Visitor.h"
#include "../Enemy.h"


Visitor* BreakEnemy_Visitor_Factory::factoryMethod(GameObject* object){

	return new BreakEnemy_Visitor((Enemy*)object);

}