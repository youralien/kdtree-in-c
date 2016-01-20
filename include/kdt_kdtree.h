/*  =========================================================================
    gdom_server - Global Domination service

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

//  Set dimension of kdtree
void
    kdt_kdtree_set_dimension (kdt_kdtree_t *self, const int dimension);

//  Get dimension of kdtree
int
    kdt_kdtree_dimension (kdt_kdtree_t *self);

//  Self test of this class
void
    kdt_kdtree_test (bool verbose);
//  @end

#ifdef __cplusplus
}
#endif

#endif
