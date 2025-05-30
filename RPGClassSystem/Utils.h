#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <chrono>
#include <thread>
#include <sstream>
#include <memory>

std::string truncateDouble(double value, int decimalPlaces = 3);

std::string truncateFloat(float value, int decimalPlaces = 3);