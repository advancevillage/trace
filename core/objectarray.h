#ifndef __OBJECT__ARRAY__
#define __OBJECT__ARRAY__

#ifndef __OBJECT__
#include "object.h"
#endif // __OBJECT__

#ifndef __USED__VECTOR__
#define __USED__VECTOR__
#include <vector>
using namespace std;
#endif // __USED__VECTOR__

class ObjectArray{
protected:
    vector<Object> _objAry;

public:
    ObjectArray();
    ObjectArray(vector<Object>& objAry);
    ObjectArray(ObjectArray& oa);
    void operator=(vector<Object>& objAry);
    void operator=(ObjectArray& oa);
    void operator=(Object& obj);

public:
    vector<Object> GetObjectArray()const;
    void Add(Object obj);
    void Add(vector<Object> objAry);
    void ClearAll();
    void SetAllShow(const bool ishow);
    int GetSize()const;

};

#endif // __OBJECT__ARRAY__
