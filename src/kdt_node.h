/*  =========================================================================
    kdt_node - node header file

    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of the Global Domination Project.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#ifndef KDT_NODE_H_INCLUDED
#define KDT_NODE_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @interface
//  Create a new ktd_node API
kdt_node_t *
    kdt_node_new (void);

//  Destroy a node
void
    kdt_node_destroy (kdt_node_t **self_p);

// Get left child
kdt_node_t *
    kdt_node_left (kdt_node_t *self);

// Set left child
void
    kdt_node_set_left (kdt_node_t *self, kdt_node_t *left);

// Get right child
kdt_node_t *
    kdt_node_right (kdt_node_t *self);

// Set right child
void
    kdt_node_set_right (kdt_node_t *self, kdt_node_t *right);

//  Self test of this class
void
    kdt_node_test (bool verbose);
//  @end

#ifdef __cplusplus
}
#endif

#endif
