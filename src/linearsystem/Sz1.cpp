
#include "openeaagles/linearsystem/Sz1.hpp"
#include "openeaagles/base/Number.hpp"
#include <iostream>

namespace oe {
namespace linearsystem {

IMPLEMENT_SUBCLASS(Sz1, "Sz1")

//------------------------------------------------------------------------------
// slot table for this class type
//------------------------------------------------------------------------------
BEGIN_SLOTTABLE(Sz1)
    "n1",      //  1: N1
    "N1",      //  2: N1
    "n2",      //  3: N2
    "N2",      //  4: N2
    "d1",      //  5: D1
    "D1",      //  6: D1
    "d2",      //  7: D2
    "D2",      //  8: D2
END_SLOTTABLE(Sz1)

// Map slot table to handles
BEGIN_SLOT_MAP(Sz1)
   ON_SLOT( 1, setSlotN1,   base::Number)
   ON_SLOT( 2, setSlotN1,   base::Number)
   ON_SLOT( 3, setSlotN2,   base::Number)
   ON_SLOT( 4, setSlotN2,   base::Number)
   ON_SLOT( 5, setSlotD1,   base::Number)
   ON_SLOT( 6, setSlotD1,   base::Number)
   ON_SLOT( 7, setSlotD2,   base::Number)
   ON_SLOT( 8, setSlotD2,   base::Number)
END_SLOT_MAP()

Sz1::Sz1()
{
   STANDARD_CONSTRUCTOR()
}

EMPTY_COPYDATA(Sz1)
EMPTY_DELETEDATA(Sz1)


//------------------------------------------------------------------------------
// Set slot functions
//------------------------------------------------------------------------------

bool Sz1::setSlotN1(const base::Number* const msg)
{
   bool ok = false;
   if (msg != nullptr) {
      setN1( msg->getReal() );
      ok = true;
   }
   return ok;
}

bool Sz1::setSlotN2(const base::Number* const msg)
{
   bool ok = false;
   if (msg != nullptr) {
      setN2( msg->getReal() );
      ok = true;
   }
   return ok;
}

bool Sz1::setSlotD1(const base::Number* const msg)
{
   bool ok = false;
   if (msg != nullptr) {
      setD1( msg->getReal() );
      ok = true;
   }
   return ok;
}

bool Sz1::setSlotD2(const base::Number* const msg)
{
   bool ok = false;
   if (msg != nullptr) {
      setD2( msg->getReal() );
      ok = true;
   }
   return ok;
}

std::ostream& Sz1::serialize(std::ostream& sout, const int i, const bool slotsOnly) const
{
    int j = 0;
    if ( !slotsOnly ) {
        sout << "( " << getFactoryName() << std::endl;
        j = 4;
    }

    BaseClass::serialize(sout,i+j,true);

    indent(sout,i+j);
    sout << "N1:   " << getN1() << std::endl;

    indent(sout,i+j);
    sout << "N2:   " << getN2() << std::endl;

    indent(sout,i+j);
    sout << "D1:   " << getD1() << std::endl;

    indent(sout,i+j);
    sout << "D2:   " << getD2() << std::endl;

    if ( !slotsOnly ) {
        indent(sout,i);
        sout << ")" << std::endl;
    }

    return sout;
}

}
}
