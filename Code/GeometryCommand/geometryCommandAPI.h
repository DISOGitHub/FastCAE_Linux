#ifndef _GEOMETRYCOMMANDAPI_H_
#define _GEOMETRYCOMMANDAPI_H_

#include <QtCore/QtGlobal>


#if defined(GEOMETRYCOMMAND_API)
#define GEOMETRYCOMMANDAPI Q_DECL_EXPORT
#else
#define  GEOMETRYCOMMANDAPI Q_DECL_IMPORT
#endif

#endif
