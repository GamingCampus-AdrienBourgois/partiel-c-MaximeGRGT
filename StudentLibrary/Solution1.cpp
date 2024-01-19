#include "Solution1.h"
#include <stdexcept>
#include <iostream>
#include <cmath>

// Don't fortget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_1

float Solution1::Rounding(float _value) {
	return std::round(_value * 100.0) / 100.0;
}

float Solution1::ConvertTemperature(float _value, TemperatureUnits _from, TemperatureUnits _to)
{
	if (_from == _to) {
		return _value;
	}

	float result;

	switch (_from) {
		case TemperatureUnits::CELSIUS:
			switch (_to) {
				case TemperatureUnits::FAHRENHEIT:
					result = _value * (9.f / 5.f) + 32.f;
					break;
				case TemperatureUnits::KELVIN:
					result = _value + 273.f;
					break;
				default:
					throw std::logic_error("invalide ca marche pas");
			}
			break;

		case TemperatureUnits::FAHRENHEIT:
			switch (_to) {
				case TemperatureUnits::CELSIUS:
					result = (_value - 32.f) * (5.f / 9.f);
					break;
				case TemperatureUnits::KELVIN:
					result = (5.f / 9.f) * (_value - 32.f) + 273.f;
					break;
				default:
					throw std::logic_error("invalide ca marche pas");
			}
			break;

		case TemperatureUnits::KELVIN:
			switch (_to) {
				case TemperatureUnits::CELSIUS:
					result = _value - 273.f;
					break;
				case TemperatureUnits::FAHRENHEIT:
					result = (9.f / 5.f) * (_value - 273.f) + 32.f;
					break;
				default:
					throw std::logic_error("invalide ca marche pas");
			}
			break;

		default:
			throw std::logic_error("invalide ca marche pas");
	}

	Solution1::Rounding(result);
	std::cout << "\n";
	std::cout << result;

	return result;
}

#endif
