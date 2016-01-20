/*  =========================================================================
    kdt_node - node source file

    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of the Global Domination Project.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

/*
@header
    This class implements a node of a kdtree.
@discuss
    Nodes are what make trees work.  They have their point that represents them,
    data associated with them, and left and right childs.
@end
*/

#include "kdt_classes.h"

struct _kdt_node_t {
    zlist_t *point;
    int value;
    kdt_node_t *left_child;
    kdt_node_t *right_child;
};

// --------------------------------------------------------------------------
// Constructor

kdt_node_t *
kdt_node_new (void) {
    kdt_node_t *self = (kdt_node_t *) zmalloc (sizeof (kdt_node_t));
    assert (self);
    return self;
}

// --------------------------------------------------------------------------
// Destructor

void
kdt_node_destroy (kdt_node_t **self_p) {
    assert (self_p);
    if (*self_p) {
        kdt_node_t *self = *self_p;
        free (self);
        *self_p = NULL;
    }
}

// --------------------------------------------------------------------------
// Self test of this class

void
kdt_node_test (bool verbose) {
    printf (" * kdt_node: ");
    //  @selftest
    kdt_node_t *node = kdt_node_new();
    kdt_node_destroy (&node);
    // @end
    printf ("OK\n");
}