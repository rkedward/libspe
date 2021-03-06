// This file is part of libspe, a C++ library to interface with spe files.
// Copyright (c) 2012 Karthik Periagaram <karthik.periagaram@gmail.com>
//
// libspe is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// libspe is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with libspe.  If not, see <http://www.gnu.org/licenses/>.

#include <string>
#include "../spe.h"

#include <vector>
#include "speutils.h"
 
#include <dirent.h>
#include <fnmatch.h>

#include <ostream>

int filter( const struct dirent* file )
{
  return !fnmatch( "*.spe", file->d_name, FNM_CASEFOLD );
}

std::vector<std::string> lsspe( const std::string directory )
{
  std::vector<std::string> filePaths;
  
  if( !opendir( directory.c_str() ) ) return filePaths; // Invalid directory

  struct dirent** files;
  int numFiles = scandir( directory.c_str(), &files, filter, alphasort );
  
  if( numFiles == 0 ) return filePaths; // No files found
  
  for( int i = 0; i < numFiles; i++ ) {
    filePaths.push_back( ( directory.find_last_of( '/' ) + 1 == directory.size() )? directory + std::string( files[ i ]->d_name ) : directory + "/" + std::string( files[ i ]->d_name ) );
  }
  
  return filePaths;
}

std::ostream& operator<< ( std::ostream& out, speFile& image )
{
  out << image.filePath();
  if( !image.dataType() ) {
    out << ": Invalid file.";
    return out;
  }
  out << ": " << image.rows() << "×" << image.cols() << ", " << image.frames() << " frames ";
  switch( image.dataType() ) {
    case 1:
      out << "(float).";
      break;
    case 2:
      out << "(long).";
      break;
    case 3:
      out << "(int).";
      break;
    case 4:
      out << "(unsigned).";
      break;
    default:
      out << "(unknown).";
      break;
  }
  return out;
}
