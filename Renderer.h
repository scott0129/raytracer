#ifndef RENDERER_H
#define RENDERER_H

#include "Objects.h"
#include "Vector.h"
#include <iostream>
#include <png++/png.hpp>
#include <png++/image.hpp>
#include <stdlib.h>
#include <float.h>
#include "objectCollection.h"
#include <time.h>


class Renderer {
public:
  void run();
private:
  double logit(double input);

  double sigmoid(double input);

  png::color pixelScalar(png::color color1, double multip);

  png::color pixelMultiply(png::color color1, png::color color2);

  png::color pixelAdd(png::color color1, png::color color2);

  png::color phongModel(Vector castPoint, Vector castRay, double tVal, Vector toLight, Hittable* object);


};

#endif