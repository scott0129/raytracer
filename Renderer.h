#ifndef RENDERER_H
#define RENDERER_H

#include "Objects.h"
#include "Vector.h"
#include <vector>
#include <iostream>
#include <png++/png.hpp>
#include <png++/image.hpp>
#include <stdlib.h>
#include <float.h>
#include "objectCollection.h"
#include <time.h>


class Renderer {
public:
    void run(int const argc, char* const argv[]);

    Vector getVertex(const std::string& line);
private:
    double logit(double input);

    double sigmoid(double input);

    png::color pixelScalar(png::color color1, double multip);

    png::color pixelMultiply(png::color color1, png::color color2);

    /**
    Adds 2 pixels together using a sigmoid function. I just personally thought it looked better than linear addition.
    **/
    png::color pixelAdd(png::color color1, png::color color2);

    png::color phongModel(const Vector* castPoint, const Vector* castRay, double tVal, const Vector* toLight, Hittable* object);

    void getArguments(int const argc, char* const argv[], std::string* inputFilename, std::string* outputFilename, int* width, int* height);
};

#endif
