// 
// -----------------------------------------------------------------------------
// errorcodes.h
// -----------------------------------------------------------------------------
//
// Internal error codes for Preview
//
// Copyright © 2021 Tyler Wayne
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef ERRORCODES_INCLUDED
#define ERRORCODES_INCLUDED

enum generalCodes {
  DF_INVRECORD  = -5, // record has the wrong number of rows
  DF_CORRUPT    = -4, // values in the dataframe are inconsistent
  DF_ENOMEM     = -3, // memory allocation failed
  DF_OOBARG     = -2, // argument is out-of-bounds
  DF_NULLARG    = -1, // pointer argument is NULL
  DF_OK         = 0
};

#endif // ERRORCODES_INCLUDED
