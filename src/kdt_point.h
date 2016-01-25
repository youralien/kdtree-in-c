/*  =========================================================================
    kdt_point - point header file

    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of the Global Domination Project.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#ifndef KDT_POINT_H_INCLUDED
#define KDT_POINT_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @interface
//  Create a new ktd_point API
kdt_point_t *
    kdt_point_new (void);

//  Destroy a point
void
    kdt_point_destroy (kdt_point_t **self_p);

// populate point with values from a float array
void
    kdt_point_populate_with_float (kdt_point_t *self, float array[], int size);

// access the element of the point at index
void *
    kdt_point_index (kdt_point_t *self, int index);

// access the elemnt of the point at index (where the element is a float)
float
    kdt_point_index_float (kdt_point_t *self, int index);

//  Self test of this class
void
    kdt_point_test (bool verbose);
//  @end

#ifdef __cplusplus
}
#endif

#endif
