//------------------------------------------------------------------------------
// Class: Factory
//
// Description: Class factory
//------------------------------------------------------------------------------
#ifndef __oe_Instruments_Factory_H__
#define __oe_Instruments_Factory_H__

namespace oe {

namespace basic { class Object; }

namespace Instruments {

class Factory
{
public:
   static basic::Object* createObj(const char* name);

protected:
   Factory();   // prevent object creation
};

}  // end namespace Instruments
}  // end namespace oe

#endif
