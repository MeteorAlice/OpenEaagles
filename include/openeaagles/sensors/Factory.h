//------------------------------------------------------------------------------
// Class: Factory
//
// Description: Class factory
//------------------------------------------------------------------------------
#ifndef __oe_Sensor_Factory_H__
#define __oe_Sensor_Factory_H__

namespace oe {

namespace basic { class Object; }

namespace Sensor {

class Factory
{
public:
   static basic::Object* createObj(const char* name);

protected:
   Factory();   // prevent object creation
};

}  // end namespace Sensor
}  // end namespace oe

#endif
