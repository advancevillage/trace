#ifndef __OBJECT__CONTROLLER__
#define __OBJECT__CONTROLLER__

#ifndef __OBJECT__ARRAY__
#include "objectarray.h"
#endif // __OBJECT__ARRAY__

#ifndef __OBJECT__NODE__
#include "objectnode.h"
#endif // __OBJECT__NODE__

#ifndef __USED__DEQUE__
#define __USED__DEQUE__
#include <deque>
using namespace std;
#endif // __USED__DEQUE__

class ObjectController{
protected:
    deque<ObjectNode> _objnodeAry;

public:
    ObjectController();
    ObjectController(ObjectController& objCtl);
    ObjectController(ObjectArray& oa);
    ObjectController(deque<ObjectNode>& objnodeAry);
    ObjectController(vector<Object>& objAry);
    ~ObjectController();

    void operator=(ObjectController& oc);
    void operator=(ObjectArray& oa);
    void operator=(deque<ObjectNode>& objnodeAry);
    void operator=(vector<Object>& objAry);
    void operator=(ObjectNode& objnode);
    void operator=(Object& obj);


public:
    deque<ObjectNode> GetObjectNodeArray()const;
    int GetSize()const;
    void ClearAll();
    void Add(ObjectNode objnode);
    void Add(Object obj);
    void Add(deque<ObjectNode> objnodeAry);
    void Add(vector<Object> objAry);
    void SetAllShow(const bool ishow);

};


#endif // __OBJECT__CONTROLLER__
