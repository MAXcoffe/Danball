#include "BreakChip_Visitor_Factory.h"
#include "../BreakChip_Visitor.h"
#include "../Cardboard_Chip.h"


Visitor* BreakChip_Visitor_Factory::factoryMethod(GameObject* object){

	return new BreakChip_Visitor(object);

}