#include "../include/dm.h"

float DistanceManager::distance()
{
	return (this->readFirst()-this->readSecond());
}
