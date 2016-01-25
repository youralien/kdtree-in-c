/*  =========================================================================
    kdt_kdtree - kdtree header file

    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of the Global Domination Project.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#ifndef KDT_KDTREE_H_INCLUDED
#define KDT_KDTREE_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @interface
//  Create a new KDTree API
kdt_kdtree_t *
    kdt_kdtree_new (void);

//  Destroy a kdtree
void
    kdt_kdtree_destroy (kdt_kdtree_t **self_p);

//  Get dimension of kdtree
const int
    kdt_kdtree_dimension (kdt_kdtree_t *self);

//  Set dimension of kdtree
void
    kdt_kdtree_set_dimension (kdt_kdtree_t *self, const int dimension);

// determine if tree is empty
bool
    kdt_kdtree_empty (kdt_kdtree_t *self);

// Insert specified point with associated value
void
    kdt_kdtree_insert (kdt_kdtree_t *self, kdt_point_t *point, float value);

// find a particular node by returning its pointer (helper function)
kdt_node_t *
    kdt_kdtree_find_node (kdt_kdtree_t *self, kdt_point_t *point);

// Point contained in kdtree
bool
    kdt_kdtree_contains (kdt_kdtree_t *self, kdt_point_t *point);

//  Self test of this class
void
    kdt_kdtree_test (bool verbose);
//  @end

#ifdef __cplusplus
}
#endif

#endif
