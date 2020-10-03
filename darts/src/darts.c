#include "darts.h"
uint8_t score(coordinate_t dart_at)
{
	float hyp;

	hyp = sqrtf(pow(dart_at.x, 2) + pow(dart_at.y, 2));

	if (hyp <= 1)
		return 10;
	else if (hyp > 1 && hyp <= 5)
		return 5;
	else if (hyp > 5 && hyp <= 10)
		return 1;u	
	else
		return 0;
}
