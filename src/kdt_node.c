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
    struct _kdt_node_t *left;
    struct _kdt_node_t *right;
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
// Get point
zlist_t *
kdt_node_point (kdt_node_t *self) {
    assert (self);
    return self->point;
}

// --------------------------------------------------------------------------
// Set point
void
kdt_node_set_point (kdt_node_t *self, zlist_t *point) {
    assert (self);
    self->point = point;
}

// --------------------------------------------------------------------------
// Get value
const int
kdt_node_value (kdt_node_t *self) {
    assert (self);
    return self->value;
}

// --------------------------------------------------------------------------
// Set value
void
kdt_node_set_value (kdt_node_t *self, const int value) {
    assert (self);
    self->value = value;
}

// --------------------------------------------------------------------------
// Get left child
kdt_node_t *
kdt_node_left (kdt_node_t *self) {
    assert (self);
    return self->left;
}

// --------------------------------------------------------------------------
// Set left child
void
kdt_node_set_left (kdt_node_t *self, kdt_node_t *left) {
    assert (self);
    assert (left);
    self->left = left;
}

// --------------------------------------------------------------------------
// Get right child
kdt_node_t *
kdt_node_right (kdt_node_t *self) {
    assert (self);
    return self->right;
}

// --------------------------------------------------------------------------
// Set right child
void
kdt_node_set_right (kdt_node_t *self, kdt_node_t *right) {
    assert (self);
    assert (right);
    self->right = right;
}

// --------------------------------------------------------------------------
// Self test of this class

void
kdt_node_test (bool verbose) {
    printf (" * kdt_node: ");
    //  @selftest
    kdt_node_t *node = kdt_node_new();

    //  Getter and Setters for Point (1,1,1)
    int pointData [3] = {1, 1, 1};
    zlist_t *point = zlist_new();
    for (int counter = 0; counter < sizeof(pointData) / sizeof(int); counter++ ) {
        zlist_append(point, &pointData[counter]);
    }
    kdt_node_set_point(node, point);
    assert ( kdt_node_point (node) == point );

    //  Getter and Setters for Value 1
    kdt_node_set_value(node, 1);
    assert ( kdt_node_value (node) == 1 );

    //  Getter and Setters for Left/Right child
    kdt_node_t *node_left = kdt_node_new();
    kdt_node_t *node_right = kdt_node_new();
    kdt_node_set_left (node, node_left);
    kdt_node_set_right (node, node_right);
    assert ( kdt_node_left (node) == node_left );
    assert ( kdt_node_right (node) == node_right );

    //  Destructors
    kdt_node_destroy (&node);
    kdt_node_destroy (&node_left);
    kdt_node_destroy (&node_right);

    // @end
    printf ("OK\n");
}