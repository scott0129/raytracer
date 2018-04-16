#ifndef OBJECTCOLLECTION_H
#define OBJECTCOLLECTION_H

#include "Vector.h"
#include "Objects.h"
#include <list>



class objectCollection {
public:

  virtual Hittable* intersect(Vector pos, Vector vect) = 0;

  void setSize(size_t newSize) {size = newSize;}
  size_t getSize() { return size; }
  void setObjArray(Hittable** newObj) {objects = newObj;}
  Hittable** objArray() { return objects; }

private:
  size_t size;
  Hittable** objects;

};

class BVM : public objectCollection {

public:

  struct BVMNode {

    BVMNode(Vector lo, Vector hi) : axis(-1), obj(NULL){
      loPoint = lo;
      hiPoint = hi;
    };

    bool isLeaf() {
      return (left == NULL && right == NULL);
    }

    int axis;
    double divide;

    Vector loPoint;
    Vector hiPoint;

    BVMNode* left;
    BVMNode* right;

    Hittable* obj;

  };

  BVM(Hittable** objArray, size_t size, Vector low, Vector high);
  Hittable* intersect(Vector pos, Vector vect);
  void printTree() {
    recPrint(root);
  }

private:
  bool isLeaf(BVMNode node);
  BVMNode* root;

  void recPrint(BVMNode* root) {
    if (root == NULL) {return;}
    std::cout << "hiPoint is: " << root->hiPoint.toString() << " and loPoint is: " << root->loPoint.toString() << " axis: " << root->axis << " ";
    if (root->isLeaf()) {
      std::cout << "<- leaf containing " << root->obj->getCenter().toString();
      std::cout << " leafLoPoint: " << root->obj->loCorner().toString();
    }
    std::cout << std::endl;
    recPrint(root->left);
    recPrint(root->right);
  }

};

class nonBVM : objectCollection {
public:
  nonBVM(Hittable** objArray, size_t size);
  Hittable* intersect(Vector pos, Vector vect);

};


#endif
