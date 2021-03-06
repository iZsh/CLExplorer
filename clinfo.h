// CLExplorer: a simple OpenCL Explorer Tool
// Copyright (c) 2010 iZsh - izsh at fail0verflow.com
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef IZ_CLINFO_H__
#define IZ_CLINFO_H__

#include <OpenCL/OpenCL.h>

void platform_info(cl_platform_id platform_id);
void get_all_platforms_info();

void device_info(cl_device_id device_id);
void get_all_devices_info();

const char * channel_order_to_s(cl_channel_order channel_order);
const char * channel_data_type_to_s(cl_channel_type channel_type);
void get_device_supported_image_formats(cl_device_id device_id);


#endif
