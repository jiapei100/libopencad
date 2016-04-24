/*******************************************************************************
 *  Project: libopencad
 *  Purpose: OpenSource CAD formats support library
 *  Author: Alexandr Borzykh, mush3d at gmail.com
 *  Author: Dmitry Baryshnikov, bishop.dev@gmail.com
 *  Language: C++
 *******************************************************************************
 *  The MIT License (MIT)
 *
 *  Copyright (c) 2016 Alexandr Borzykh
 *  Copyright (c) 2016 NextGIS, <info@nextgis.com>
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *******************************************************************************/

#ifndef OPENCAD_H
#define OPENCAD_H

#define OCAD_VERSION    "0.1.0"
#define OCAD_VERSION_MAJOR 0
#define OCAD_VERSION_MINOR 1
#define OCAD_VERSION_REV   0

#ifndef OCAD_COMPUTE_VERSION
#define OCAD_COMPUTE_VERSION(maj,min,rev) ((maj)*10000+(min)*100+rev) // maj - any, min < 99, rev < 99
#endif

#define OCAD_VERSION_NUM OCAD_COMPUTE_VERSION(OCAD_VERSION_MAJOR,OCAD_VERSION_MINOR,OCAD_VERSION_REV)

/*  check if the current version is at least major.minor.revision */
#define CHECK_VERSION(major,minor,rev) \
    (OCAD_VERSION_MAJOR > (major) || \
    (OCAD_VERSION_MAJOR == (major) && OCAD_VERSION_MINOR > (minor)) || \
    (OCAD_VERSION_MAJOR == (major) && OCAD_VERSION_MINOR == (minor) && OCAD_VERSION_REV >= (release)))


#ifdef OCAD_STATIC
  #define EXTERN extern
#else
#   if defined (_WIN32) || defined (WINDOWS)
#    ifdef OCAD_EXPORTS
#      ifdef __GNUC__
#        define EXTERN extern __attribute__((dllexport))
#      else        
#        define EXTERN extern __declspec(dllexport)
#      endif 
#    else
#      ifdef __GNUC__
#        define EXTERN extern __attribute__((dllimport))
#      else        
#        define EXTERN extern __declspec(dllimport)
#      endif 
#    endif
#   else
#     if __GNUC__ >= 4
#       define EXTERN __attribute__((visibility("default")))
#     else
#       define EXTERN                extern
#     endif 
#   endif
#endif

#endif // OPENCAD_H
