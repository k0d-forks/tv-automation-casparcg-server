/*
* Copyright (c) 2011 Sveriges Television AB <info@casparcg.com>
*
* This file is part of CasparCG (www.casparcg.com).
*
* CasparCG is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* CasparCG is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with CasparCG. If not, see <http://www.gnu.org/licenses/>.
*
* Author: Robert Nagy, ronag89@gmail.com
*/

#pragma once

#include <common/memory/safe_ptr.h>

#include <boost/noncopyable.hpp>

#include <memory>

namespace caspar { namespace core {
		
class device_buffer : boost::noncopyable
{
public:
	
	int stride() const;	
	int width() const;
	int height() const;
		
	void bind(int index);
	void unbind();
		
	void begin_read();
	bool ready() const;
private:
	friend class ogl_device;
	device_buffer(int width, int height, int stride);

	int id() const;

	struct implementation;
	safe_ptr<implementation> impl_;
};
	
unsigned int format(int stride);

}}