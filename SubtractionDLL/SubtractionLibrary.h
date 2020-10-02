#pragma once

#define SUBTRACTIONLIBRARY_EXPORT __declspec(dllexport)
#define SUBTRACTIONLIBRARY_IMPORT __declspec(dllimport)

SUBTRACTIONLIBRARY_EXPORT float subtract(float a, float b);