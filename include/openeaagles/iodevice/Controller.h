
#ifndef __oe_iodevice_Controller_H__
#define __oe_iodevice_Controller_H__

#include "openeaagles/base/IoDevice.h"

namespace oe {

namespace base { class Number; }

namespace iodevice {

//------------------------------------------------------------------------------
// Class: Controller
//
// Description: Physically packages a set of analog and digital data reading
//              together to represent a controller interface (game, hotas, etc)
//
// Factory name: Controller
//
// Slots:
//    deviceIndex <Number>    Unit index
//
//------------------------------------------------------------------------------
class Controller : public base::IoDevice
{
    DECLARE_SUBCLASS(Controller, base::IoDevice)

public:
   Controller();

   virtual unsigned int getDeviceIndex() const;
   virtual bool setDeviceIndex(const int value);

   unsigned short getNumDiscreteInputChannels() const override;
   unsigned short getNumDiscreteInputPorts() const override;
   bool getDiscreteInput(bool* const value, const unsigned int channel, const unsigned int port) const override;
   unsigned short getNumAnalogInputs() const override;
   bool getAnalogInput(double* const value, const unsigned int channel) const override;

protected:

   // Slot functions
   virtual bool setSlotDeviceIndex(const base::Number* const msg);

   unsigned int deviceIndex; // Device index

   // ---
   // analog
   // ---
   static const unsigned short MAX_AI = 16;
   unsigned short numAI;    // Number of analog channels
   double inData[MAX_AI];   // Input analog array

   // ---
   // digital bits
   // ---
   static const unsigned short MAX_DI = 32;
   unsigned short numDI;      // Number of input bits
   bool inBits[MAX_DI];       // Input bit array

private:
   void initData();
};

}
}

#endif

