/* CFFI - An Io interface to C
Copyright (c) 2006 Trevor Fancher. All rights reserved.
All code licensed under the New BSD license.
*/

#ifndef IoCFFIDataType_DEFINED
#define IoCFFIDataType_DEFINED 1

#include "IoObject.h"
#include <ffi.h>

#define ISCFFIDataType(self) IoObject_hasCloneFunc_(self, (IoTagCloneFunc *)IoCFFIDataType_rawClone)

typedef IoObject IoCFFIDataType;

typedef struct IoCFFIDataType
{
	union
	{
		char			c[1];
		unsigned char	C[1];
		short			s;
		unsigned short	S;
		int				i;
		unsigned int	I;
		long			l;
		unsigned long	L;
		float			f;
		double			d;
		char			*str;
	}					type;
	int					needToFreeStr;
	void				*valuePointer;
} IoCFFIDataTypeData;

IoTag			*IoCFFIDataType_newTag(void *state);
IoCFFIDataType	*IoCFFIDataType_proto(void *state);
IoCFFIDataType	*IoCFFIDataType_rawClone(IoCFFIDataType *self);
IoCFFIDataType	*IoCFFIDataType_new(void *state);
void			IoCFFIDataType_free(IoCFFIDataType *self);
void			IoCFFIDataType_mark(IoCFFIDataType *self);

IoObject 		*IoCFFIDataType_asBuffer(IoCFFIDataType *self, IoObject *locals, IoMessage *m);
IoCFFIDataType	*IoCFFIDataType_value(IoCFFIDataType *self, IoObject *locals, IoMessage *m);
IoCFFIDataType	*IoCFFIDataType_setValue(IoCFFIDataType *self, IoObject *locals, IoMessage *m);
IoObject		*IoCFFIDataType_size(IoCFFIDataType *self, IoObject *locals, IoMessage *m);

void			*IoCFFIDataType_ValuePointerFromObject_(IoCFFIDataType* self, IoObject *o);
IoObject		*IoCFFIDataType_rawSetValue(IoCFFIDataType *self, IoObject *value);
IoObject		*IoCFFIDataType_setValueFromData(IoCFFIDataType *self, void *value);
ffi_type		*IoCFFIDataType_ffiType(IoCFFIDataType *self);
IoObject		*IoCFFIDataType_objectFromData_(IoCFFIDataType *self, void *data);
void			*IoCFFIDataType_valuePointer(IoCFFIDataType *self);
void			IoCFFIDataType_setValuePointer_(IoCFFIDataType* self, void *ptr);

#endif
