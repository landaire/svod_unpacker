#ifndef NOWIDE_STREAMBUF_H
#define NOWIDE_STREAMBUF_H

#include "config.h"
#include <streambuf>
#include <stdio.h>
#include <memory>
#include <vector>

namespace nowide {

	class io_device {
	public:
		typedef enum {
			set,
			cur,
			end
		} pos_type;
		virtual size_t read(char *pos,size_t length)
		{
			return 0;
		}
		virtual size_t write(char const *pos,size_t length)
		{
			return 0;
		}
		virtual long long seek(long long position,pos_type pos = set)
		{
			return -1;
		}
		virtual ~io_device()
		{
		}
	};

	class NOWIDE_API streambuf : public std::streambuf {
	public:

		streambuf();
		~streambuf();
		
		void device(std::auto_ptr<io_device> d);
		void device(io_device &d);

		void reset_device();

		io_device &device();
		void set_buffer_size(size_t n);

	protected:

		// Seek

		virtual std::streampos seekoff(	std::streamoff off,
						std::ios_base::seekdir way,
						std::ios_base::openmode m = std::ios_base::in | std::ios_base::out);
		virtual std::streampos seekpos(	std::streampos pos,
						std::ios_base::openmode m = std::ios_base::in | std::ios_base::out);
		
		// Get
		
		virtual int underflow();

		// Put
		
		virtual int overflow(int c = EOF);
		virtual int sync();
		
	private:

		std::vector<char> buffer_out_;
		std::vector<char> buffer_in_;

		size_t buffer_size_;

		struct _data;
		std::auto_ptr<_data> d; // for future use

		std::auto_ptr<io_device> device_auto_ptr_;
		io_device *device_;

	};
} // nowide


#endif
