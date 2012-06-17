#ifndef CPPCMS_NOWIDE_CSTDIO_H
#define CPPCMS_NOWIDE_CSTDIO_H

#include <cstdio>
#include <stdio.h>
#include "config.h"
#include "convert.h""

namespace nowide {
#ifndef NOWIDE_WIN_NATIVE
	using std::fopen;
	using std::freopen;
	using std::remove;
	using std::rename;
#else
	inline FILE *fopen(char const *file_name,char const *mode)
	{
		try {
			return _wfopen(convert(file_name).c_str(),convert(mode).c_str());
		}
		catch(bad_utf const &e) {
			return 0;
		}
	}
	inline FILE *freopen(char const *file_name,char const *mode,FILE *stream)
	{
		try {
			return _wfreopen(convert(file_name).c_str(),convert(mode).c_str(),stream);
		}
		catch(bad_utf const &e) {
			return 0;
		}
	}
	inline int rename(char const *old_name,char const *new_name)
	{
		try {
			return _wrename(convert(old_name).c_str(),convert(new_name).c_str());
		}
		catch(bad_utf const &e) {
			return -1;
		}
	}
	inline int remove(char const *name)
	{
		try {
			return _wremove(convert(name).c_str());
		}
		catch(bad_utf const &e) {
			return -1;
		}
	}
#endif
} // nowide

#endif
