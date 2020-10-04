#include "grains.h"
#define granInChessBord( grains, sq )( ( sq == 1 ) ? 1 : grains << sq )
uint64_t square(uint8_t index)
{
	uint64_t grains = 1;

	if (index > 64)
		grains = 0;
	else
	{
		switch (index)
		{
		case 0:
			grains = 0;
			break;
		case 1:
			grains = 1;
			break;
		case 2:
			grains = 2;
			break;

		default:
			grains = granInChessBord(grains, (index - 1));
			break;
		}
	}

	return grains;
}


uint64_t total(void)
{
	uint64_t totalGrains = 0;

	for (int i = 3; i <=64; i++)
	{
		totalGrains += square(i);
	}
	
	totalGrains += 3; //To consider square 1 an 2
	return totalGrains;
}