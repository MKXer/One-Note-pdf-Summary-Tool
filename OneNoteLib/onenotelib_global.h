#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(ONENOTELIB_LIB)
#  define ONENOTELIB_EXPORT Q_DECL_EXPORT
# else
#  define ONENOTELIB_EXPORT Q_DECL_IMPORT
# endif
#else
# define ONENOTELIB_EXPORT
#endif
