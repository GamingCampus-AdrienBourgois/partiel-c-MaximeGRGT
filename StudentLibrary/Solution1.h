#pragma once

// Don't forget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_1

enum class TemperatureUnits
{
	CELSIUS,
	FAHRENHEIT,
	KELVIN
};

class Solution1 // Temperature converter
{
public:
	static float Rounding(float _value);
	static float ConvertTemperature(float value, TemperatureUnits fromUnit, TemperatureUnits toUnit);
};

#endif
