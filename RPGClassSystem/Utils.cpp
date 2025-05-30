#include "Utils.h"

std::string truncateDouble(double value, int decimalPlaces)
{
    std::ostringstream out;

    out << std::fixed << std::setprecision(decimalPlaces) << value;

    return out.str();
}

std::string truncateFloat(float value, int decimalPlaces)
{
    std::ostringstream out;

    out << std::fixed << std::setprecision(decimalPlaces) << value;

    return out.str();
}
