#ifndef FMSAPI_GLOBAL_H
#define FMSAPI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(FMSAPI_LIBRARY)
#  define FMSAPI_EXPORT Q_DECL_EXPORT
#else
#  define FMSAPI_EXPORT Q_DECL_IMPORT
#endif

#endif // FMSAPI_GLOBAL_H
