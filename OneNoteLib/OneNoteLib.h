#pragma once

#include "onenotelib_global.h"
#include "OneNoteFactory.h"

class ONENOTELIB_EXPORT OneNoteLib
{
public:
    OneNoteLib();


    static Factory const& factory()
    {
        return Factory::factory();
    }

};
