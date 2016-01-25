/*  =========================================================================
    kdt_point - point source file

    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of the Global Domination Project.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

/*
@header
    A point class used in nodes.  It is a thin wrapper around czmqs zlist
@discuss
    Takes the benefits of zlists, plus some nice array helpers like indexing.
@end
*/

#include "kdt_classes.h"

struct _kdt_point_t {
    zlist_t *list;
};

// --------------------------------------------------------------------------
// Constructor

kdt_point_t *
kdt_point_new (void) {
    kdt_point_t *self = (kdt_point_t *) zmalloc (sizeof (kdt_point_t));
    assert (self);
    self->list = zlist_new ();
    return self;
}

// --------------------------------------------------------------------------
// Destructor

void
kdt_point_destroy (kdt_point_t **self_p) {
    assert (self_p);
    if (*self_p) {
        kdt_point_t *self = *self_p;
        free (self);
        *self_p = NULL;
    }
}

// --------------------------------------------------------------------------
// populate point with values from a float array
void
kdt_point_populate_with_float (kdt_point_t *self, float array[], int size) {
    // for (int counter = 0; counter < sizeof(array) / sizeof(float); counter++ ) {
    for (int counter = 0; counter < size; counter++ ) {
        zlist_append(self->list, &array[counter]);
    }
}

// --------------------------------------------------------------------------
// access the element of the point at index
void *
kdt_point_index (kdt_point_t *self, int index) {
    void *component_p = zlist_first(self->list);
    for (int counter = 0; counter < index; counter++)
        component_p = zlist_next(self->list);
    return component_p;
}

// --------------------------------------------------------------------------
// access the elemnt of the point at index (where the element is a float)
float
kdt_point_index_float (kdt_point_t *self, int index) {
    float *float_value_p = kdt_point_index (self, index);
    return *float_value_p;
}

// --------------------------------------------------------------------------
// Self test of this class

void
kdt_point_test (bool verbose) {
    printf (" * kdt_point: ");
    //  @selftest

    //  Constructor
    kdt_point_t *point1 = kdt_point_new ();

    // Populate
    float pointData1[4] = {1.0, 2.0, 4.0, 8.0};
    int size = sizeof(pointData1) / sizeof (float);
    kdt_point_populate_with_float (point1, pointData1, size);

    // Access Index
    float one = 1.0;
    float two = 2.0;
    float four = 4.0;
    float eight = 8.0;
    assert (kdt_point_index_float (point1, 0) == one);
    assert (kdt_point_index_float (point1, 1) == two);
    assert (kdt_point_index_float (point1, 2) == four);
    assert (kdt_point_index_float (point1, 3) == eight);

    // Destructor
    kdt_point_destroy (&point1);

    // @end
    printf ("OK\n");
}