#include "BreakBox_Visitor_Factory.h"
#include "../Cardboard_Box.h"
#include <typeinfo>
#include "../BreakBoxVisitor.h"

class Cardboard_Box;

Visitor* BreakBox_Visitor_Factory::factoryMethod(GameObject* object){

	if (typeid(*object) != typeid(Cardboard_Box)) return nullptr;

	return new BreakBoxVisitor( (Cardboard_Box*)object );

}


