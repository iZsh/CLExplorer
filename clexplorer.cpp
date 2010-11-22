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

#include <iostream>
#include "clinfo.h"

using namespace std;

int main (int argc, char * const argv[])
{
  cout << "===================================" << endl;
  cout << "CLExplorer -- Copyright 2010 iZsh" << endl;
  cout << "A Simple OpenCL Explorer Tool" << endl;
  cout << "===================================" << endl;
  cout << endl;

  get_all_platforms_info();
  get_all_devices_info();
  
  return 0;
}
