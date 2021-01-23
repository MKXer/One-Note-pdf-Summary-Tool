#pragma once

#include "onenotelib_global.h"
#include "OneNoteFactory.h"

class ONENOTELIB_EXPORT OneNoteLib
{
public:
    OneNoteLib();


    static OneNote::Factory const& factory()
    {
        return OneNote::Factory::factory();
    }

};
