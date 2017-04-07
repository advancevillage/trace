#ifndef __OBJECT__NODE__
#define __OBJECT__NODE__

#ifndef __OBJECT__
#include "object.h"
#endif // __OBJECT__

#ifndef __USERD__STRING__
#define __USERD__STRING__
#include <string>
using namespace std;
#endif // __USERD__STRING__

class ObjectNode: public Object{
protected:
    int _id;
    string _name;

public:
    ObjectNode();
    ObjectNode(const int id, const string name);
    ObjectNode(const Object& obj, const int id, const string name);
    ObjectNode(const int x, const int y, const int width, const int height, const cv::Scalar color, const bool ishow, const int id, const string name);
    ObjectNode(const ObjectNode& objnode);
    ObjectNode(ObjectNode& objnode);
    ObjectNode(const Object& obj);
    ObjectNode(Object& obj);
    void operator=(const Object& obj);
    void operator=(Object& obj);
    void operator=(const ObjectNode& objnode);
    void operator=(ObjectNode& objnode);
    ~ObjectNode();

public:
    void SetID(const int id);
    int GetID()const;
    void SetName(const string name);
    string GetName()const;

};


#endif // __OBJECT__NODE__
