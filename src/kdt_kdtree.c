/*  =========================================================================
    kdt_kdtree - kdtree source file

    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of the Global Domination Project.
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

/*
@header
    This class implements a kd-tree, that allows clients to build kd-trees,
    query kd-trees for membership, and execute k-NN lookups on them.
@discuss
    What is there to discuss?  Lets go fast in k dimensions yo.
@end
*/

#include "kdt_classes.h"

struct _kdt_kdtree_t {
   int filler; // fill in some attributes 
};

// --------------------------------------------------------------------------
// Constructor
kdt_kdtree_t *
kdt_kdtree_new (void) { // TODO: pass dimension as argument
    kdt_kdtree_t *self = (kdt_kdtree_t *) zmalloc (sizeof (kdt_kdtree_t));
    assert (self);
    return self;
}


// --------------------------------------------------------------------------
// Destructor

void
kdt_kdtree_destroy (kdt_kdtree_t **self_p) {
    assert (self_p);
    if (*self_p) {
        kdt_kdtree_t *self = *self_p;
        free (self);
        *self_p = NULL;
    }   
}


// --------------------------------------------------------------------------
// Self test of this class

void
kdt_kdtree_test (bool verbose)
{
    printf (" * kdt_kdtree: ");
    //  @selftest
    kdt_kdtree_t *kdtree = kdt_kdtree_new (); 
    kdt_kdtree_destroy (&kdtree);
    //  @end
    printf ("OK\n");
}

