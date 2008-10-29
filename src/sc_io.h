/*
  This file is part of the SC Library.
  The SC library provides support for parallel scientific applications.

  Copyright (C) 2007,2008 Carsten Burstedde, Lucas Wilcox.

  The SC Library is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  The SC Library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with the SC Library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SC_IO_H
#define SC_IO_H

#ifndef SC_H
#error "sc.h should be included before this header file"
#endif

SC_EXTERN_C_BEGIN;

/** This function writes numeric binary data in VTK base64 encoding.
 * \param vtkfile        Stream openened for writing.
 * \param numeric_data   A pointer to a numeric data array.
 * \param byte_length    The length of the data array in bytes.
 * \return               Returns 0 on success, -1 on file error.
 */
int                 sc_vtk_write_binary (FILE * vtkfile, char *numeric_data,
                                         size_t byte_length);

/** This function writes numeric binary data in VTK compressed format.
 * \param vtkfile        Stream openened for writing.
 * \param numeric_data   A pointer to a numeric data array.
 * \param byte_length    The length of the data array in bytes.
 * \return               Returns 0 on success, -1 on file error.
 */
int                 sc_vtk_write_compressed (FILE * vtkfile,
                                             char *numeric_data,
                                             size_t byte_length);

/** Write memory content to a file.
 * \param [in] ptr      Data array to write to disk.
 * \param [in] size     Size of one array member.
 * \param [in] nmemb    Number of array members.
 * \param [in,out] file File pointer, must be opened for writing.
 * \param [in] errmsg   Error message passed to SC_CHECK_ABORT.
 * \note                This function aborts on file errors.
 */
void                sc_fwrite (const void *ptr, size_t size,
                               size_t nmemb, FILE * file, const char *errmsg);

/** Read file content into memory.
 * \param [out] ptr     Data array to read from disk.
 * \param [in] size     Size of one array member.
 * \param [in] nmemb    Number of array members.
 * \param [in,out] file File pointer, must be opened for reading.
 * \param [in] errmsg   Error message passed to SC_CHECK_ABORT.
 * \note                This function aborts on file errors.
 */
void                sc_fread (void *ptr, size_t size,
                              size_t nmemb, FILE * file, const char *errmsg);

SC_EXTERN_C_END;

#endif /* SC_IO_H */