#include "resistor_color.h"

uint16_t  color_code(resistor_band_t color)
{
	resistor_band_t colorTransl;
	colorTransl = color;
	return colorTransl;
}

resistor_band_t* colors()
{
	static resistor_band_t colors[] = { BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE	};
	return colors;
}