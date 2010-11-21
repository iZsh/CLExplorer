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

#include "clstats.h"

#include <iostream>

using namespace std;

void device_stats(cl_device_id device_id)
{
  int err;
	size_t returned_size;
	
  // Report the device vendor and device name
  // 
  cl_char vendor_name[1024] = {0};
  cl_char device_name[1024] = {0};
  cl_char device_profile[1024] = {0};
  cl_uint clock_frequency = 0;
  cl_char device_extensions[1024] = {0};
  size_t profiling_timer_resolution = 0;
  cl_uint vector_types[] =
  {
    CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR,
    CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT,
    CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT,
    CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG,
    CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT,
    CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE
  }; 
  const char *vector_type_names[] = {"char","short","int","long","float","double"};
  cl_uint vector_width = 0;
  
  cl_uint device_address_bits = 0;
  cl_uint mem_base_addr_align = 0;
  cl_uint min_data_type_align_size = 0;
  cl_ulong global_mem_size = 0;
  cl_ulong global_mem_cache_size = 0;
  cl_ulong max_mem_alloc_size = 0;
  cl_device_local_mem_type local_mem_type = 0;
  cl_ulong local_mem_size = 0;
  cl_ulong max_constant_buffer_size = 0;
  
  cl_uint max_compute_units;
  size_t max_work_item_dims = 0;
  size_t max_work_group_size = 0;
  size_t max_work_item_sizes[3] = {0};
  
  cl_bool image_support = false;
  cl_uint max_read_image_args = 0, max_write_image_args = 0;
  size_t image2d_max_width = 0, image2d_max_height = 0;
  cl_uint max_samplers = 0;
  
  // General
  err = clGetDeviceInfo(device_id, CL_DEVICE_VENDOR, sizeof(vendor_name), vendor_name, &returned_size);
  err|= clGetDeviceInfo(device_id, CL_DEVICE_NAME, sizeof(device_name), device_name, &returned_size);
  err|= clGetDeviceInfo(device_id, CL_DEVICE_PROFILE, sizeof(device_profile), device_profile, &returned_size);
  err|= clGetDeviceInfo(device_id, CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(clock_frequency), &clock_frequency, &returned_size);
  err|= clGetDeviceInfo(device_id, CL_DEVICE_EXTENSIONS, sizeof(device_extensions), device_extensions, &returned_size);
  err|= clGetDeviceInfo(device_id, CL_DEVICE_PROFILING_TIMER_RESOLUTION, sizeof(profiling_timer_resolution), &profiling_timer_resolution, &returned_size);
  
  // Memory	
  err|= clGetDeviceInfo(device_id, CL_DEVICE_ADDRESS_BITS, sizeof(device_address_bits), &device_address_bits, &returned_size);
  err|= clGetDeviceInfo(device_id, CL_DEVICE_MEM_BASE_ADDR_ALIGN, sizeof(mem_base_addr_align), &mem_base_addr_align, &returned_size);
  err|= clGetDeviceInfo(device_id, CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE, sizeof(min_data_type_align_size), &min_data_type_align_size, &returned_size);
  
  err|= clGetDeviceInfo(device_id, CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(global_mem_size), &global_mem_size, &returned_size);
  err|= clGetDeviceInfo(device_id, CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE, sizeof(global_mem_cache_size), &global_mem_cache_size, &returned_size);
  err|= clGetDeviceInfo(device_id, CL_DEVICE_MAX_MEM_ALLOC_SIZE, sizeof(max_mem_alloc_size), &max_mem_alloc_size, &returned_size);
  
  err|= clGetDeviceInfo(device_id, CL_DEVICE_LOCAL_MEM_TYPE, sizeof(local_mem_type), &local_mem_type, &returned_size);
  err|= clGetDeviceInfo(device_id, CL_DEVICE_LOCAL_MEM_SIZE, sizeof(local_mem_size), &local_mem_size, &returned_size);
  
  err|= clGetDeviceInfo(device_id, CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE, sizeof(max_constant_buffer_size), &max_constant_buffer_size, &returned_size);
  
  // Work
  err|= clGetDeviceInfo(device_id, CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(max_work_group_size), &max_work_group_size, &returned_size);
  err|= clGetDeviceInfo(device_id, CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, sizeof(max_work_item_dims), &max_work_item_dims, &returned_size);
  err|= clGetDeviceInfo(device_id, CL_DEVICE_MAX_WORK_ITEM_SIZES, sizeof(max_work_item_sizes), max_work_item_sizes, &returned_size);
  err|= clGetDeviceInfo(device_id, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(max_compute_units), &max_compute_units, &returned_size);
  
  // Image
  err|= clGetDeviceInfo(device_id, CL_DEVICE_IMAGE_SUPPORT, sizeof(image_support), &image_support, &returned_size);
  err|= clGetDeviceInfo(device_id, CL_DEVICE_MAX_READ_IMAGE_ARGS, sizeof(max_read_image_args), &max_read_image_args, &returned_size);
  err|= clGetDeviceInfo(device_id, CL_DEVICE_MAX_WRITE_IMAGE_ARGS, sizeof(max_write_image_args), &max_write_image_args, &returned_size);
  err|= clGetDeviceInfo(device_id, CL_DEVICE_IMAGE2D_MAX_WIDTH, sizeof(image2d_max_width), &image2d_max_width, &returned_size);
  err|= clGetDeviceInfo(device_id, CL_DEVICE_IMAGE2D_MAX_HEIGHT, sizeof(image2d_max_height), &image2d_max_height, &returned_size);
  err|= clGetDeviceInfo(device_id, CL_DEVICE_MAX_SAMPLERS, sizeof(max_samplers), &max_samplers, &returned_size);
  
  cout << "===============================================================" << endl;
  cout << "Vendor: " << vendor_name << endl;
  cout << "Device Name: " << device_name << endl;
  cout << "===============================================================" << endl;
  
  cout << "General:" << endl;
  cout << "• Profile: " << device_profile << endl;
  cout << "• Clock Frequency: " << clock_frequency << "Mhz" << endl;
  cout << "• Supported Extensions: " << device_extensions << endl;
  cout << "• Timer Resolution: " << profiling_timer_resolution << "ns" << endl;
  
  for(int i=0; i < 6; ++i){
    err|= clGetDeviceInfo(device_id, vector_types[i], sizeof(clock_frequency), &vector_width, &returned_size);
    cout << "• Vector type width for: " << vector_type_names[i] << " = " << vector_width << endl;
  }
  cout << endl;
  
  cout << "Memory:" << endl;
  cout << "• General:" << endl;
  cout << "\tAddress bits: " << device_address_bits << endl;
  cout << "\tMem base Addr: " << mem_base_addr_align << endl;
  cout << "\tMin data type align size: " << min_data_type_align_size << endl;
  cout << "• Global:" << endl;
  cout << "\tGlobal Mem Size: " << global_mem_size / (1024 * 1024) << "MB" << endl;
  cout << "\tGlobal Mem Cache Size (Bytes): " << global_mem_cache_size << endl;
  cout << "\tMax Mem Alloc Size: " << max_mem_alloc_size / (1024 * 1024) << "MB" << endl;
  cout << "• Local:" << endl;
  cout << "\tLocal Mem Type (Local=1, Global=2): " << local_mem_type << endl;
  cout << "\tLocal Mem Size: " << (int)local_mem_size / 1024 << "KB" << endl;
  cout << "• Constant:" << endl;
  cout << "\tMax Constant Buffer Size: " << max_constant_buffer_size / 1024 << "KB" << endl;
  cout << endl;
  
  cout << "Work:" << endl;
  cout << "• Max Compute Units: " << max_compute_units << endl;
  cout << "• Max Work Group Size: " << max_work_group_size << endl;
  cout << "• ∫Max Work Item Dims: " << max_work_item_dims << endl;
  for(size_t i=0;i<max_work_item_dims;i++) 
    cout << "• Max Work Items in Dim " << i + 1 << ": " << max_work_item_sizes[i] << endl;
  cout << endl;
  
  cout << "Image:" << endl;
  cout << "• Image support: " << image_support << endl;
  cout << "• Max number of simulataneous read images: " << max_read_image_args << endl;
  cout << "• Max number of simulataneous write images: " << max_write_image_args << endl;
  cout << "• Max width of 2D image: " << image2d_max_width << endl;
  cout << "• Max height of 2D image: " << image2d_max_height << endl;	
  cout << "• Max Samplers: " << max_samplers << endl;
  cout << endl;
}

void get_all_devices_stats()
{
  cl_uint nb_devices = 0;
  cl_int err = 0;
  cl_device_id devices[16] = {0};
  
  err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_ALL, 16, devices, &nb_devices);
  if (err != CL_SUCCESS) {
    cout << "Cannot get the devices listing" << endl;
    return;
  }
	
  for (cl_uint i = 0; i < nb_devices; ++i)
    device_stats(devices[i]);
}
