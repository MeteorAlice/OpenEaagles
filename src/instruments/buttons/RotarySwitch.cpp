#include "openeaagles/instruments/buttons/RotarySwitch.h"
#include "openeaagles/basic/PairStream.h"
#include "openeaagles/basic/Pair.h"
#include "openeaagles/basic/Number.h"

namespace oe {
namespace Instruments {

IMPLEMENT_SUBCLASS(RotarySwitch,"RotarySwitch")
EMPTY_SERIALIZER(RotarySwitch)

//------------------------------------------------------------------------------
// Slot table for this form type
//------------------------------------------------------------------------------
BEGIN_SLOTTABLE(RotarySwitch)
    "angles",           // 1) List of angles to use
    "startPosition",    // 2) Starting position we are using
END_SLOTTABLE(RotarySwitch)

//------------------------------------------------------------------------------
//  Map slot table to handles
//------------------------------------------------------------------------------
BEGIN_SLOT_MAP(RotarySwitch)
   ON_SLOT(1, setSlotAngles, basic::PairStream)
   ON_SLOT(2, setSlotStartPosition, basic::Number)
END_SLOT_MAP()

//------------------------------------------------------------------------------
// Constructor
//------------------------------------------------------------------------------
RotarySwitch::RotarySwitch()
{
    STANDARD_CONSTRUCTOR()
    numAngs = 0;
    for (int i = 0; i < MAX_ANGLES; i++) angles[i] = 0;
    angleSD.empty();
    currentPosition = 1;
    startPosition = 1;
}

//------------------------------------------------------------------------------
// copyData() -- copy this object's data
//------------------------------------------------------------------------------
void RotarySwitch::copyData(const RotarySwitch& org, const bool)
{
    BaseClass::copyData(org);
    numAngs = org.numAngs;
    for (int i = 0; i < MAX_ANGLES; i++) angles[i] = org.angles[i];
    angleSD.empty();
    currentPosition = org.currentPosition;
    startPosition = org.startPosition;
}

//------------------------------------------------------------------------------
// deleteData() -- delete this object's data
//------------------------------------------------------------------------------
EMPTY_DELETEDATA(RotarySwitch)

//------------------------------------------------------------------------------
// setSlotNumPositions() - sets number of positions for switch
//------------------------------------------------------------------------------
bool RotarySwitch::setSlotAngles(const basic::PairStream* const x)
{
    bool ok = false;
    numAngs = 0;
    for (int i = 0; i < MAX_ANGLES; i++) angles[i] = 0;
    if (x != nullptr) {
        ok = true;
        const basic::List::Item* item = x->getFirstItem();
        while(item != nullptr) {
            basic::Pair* pair = (basic::Pair*)item->getValue();
            if (pair != nullptr) {
                basic::Number* n = dynamic_cast<basic::Number*>(pair->object());
                if (n != nullptr) {
                    angles[numAngs++] = n->getReal();
                }
            }
            item = item->getNext();
        }
    }
    return ok;
}

//------------------------------------------------------------------------------
// setSlotStartPosition() - set the position we start from
//------------------------------------------------------------------------------
bool RotarySwitch::setSlotStartPosition(const basic::Number* const x)
{
    if (x != nullptr) {
        startPosition = x->getInt();
        currentPosition = startPosition;
    }
    return true;
}

//------------------------------------------------------------------------------
// onSingleClick() ie left mouse click - rotate switch to next position
//------------------------------------------------------------------------------
bool RotarySwitch::onSingleClick()
{
   //are we past last switch position?  if yes move to start position if no move to next switch position
   if(currentPosition == numAngs){
      currentPosition = 1;
   }
   else {
      currentPosition++;
   }

   // let our parent button do the rest
   BaseClass::onSingleClick();

   return true;
}

//------------------------------------------------------------------------------
// updateData() -
//------------------------------------------------------------------------------
void RotarySwitch::updateData(const LCreal dt)
{
    BaseClass::updateData(dt);

    send("switch", UPDATE_VALUE6, angles[currentPosition - 1], angleSD);
}

//------------------------------------------------------------------------------
// getSlotByIndex() for RotarySwitch
//------------------------------------------------------------------------------
basic::Object* RotarySwitch::getSlotByIndex(const int si)
{
    return BaseClass::getSlotByIndex(si);
}

}  // end Instruments namespace
}  // end oe namespace
