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
   int dimension;
   kdt_node_t *root;
};

// --------------------------------------------------------------------------
// Constructor
kdt_kdtree_t *
kdt_kdtree_new (void) {
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
// dimension getter

const int
kdt_kdtree_dimension (kdt_kdtree_t *self) {
    assert (self);
    return self->dimension;
}

// --------------------------------------------------------------------------
// dimension setter

void
kdt_kdtree_set_dimension (kdt_kdtree_t *self, const int dimension) {
    assert (self);
    self->dimension = dimension;
}

// --------------------------------------------------------------------------
// determine if tree is empty
bool
kdt_kdtree_empty (kdt_kdtree_t *self) {
    assert (self);
    return !self->root;
}

// --------------------------------------------------------------------------
// Insert specified point with associated value
void
kdt_kdtree_insert (kdt_kdtree_t *self, kdt_point_t *point, float value) {
    assert (self);
    // Construct node from point and associate value
    kdt_node_t *node = kdt_node_new();
    kdt_node_set_point (node, point);
    kdt_node_set_value (node, value);
    // Insert as root if its the first node in the tree
    if (kdt_kdtree_empty (self)) {
        self->root = node;
    }
    // Insert as left or right child
    // depending on the level we are comparing
    // and the value of the dimension for that level
    else {
        int dimension = kdt_kdtree_dimension (self);
        int level_counter = 0;
        kdt_node_t *head = self->root;
        while (true) {
            // Determine which dimension we will be doing comparisons
            int dim_to_focus = level_counter % dimension;

            kdt_point_t *head_point = kdt_node_point (head);

            // Get components to compare, using dim_to_focus to index
            float *head_point_component_p = kdt_point_index_float (head_point, dim_to_focus);
            float *point_component_p = kdt_point_index_float (point, dim_to_focus);

            // store old parent
            kdt_node_t *parent = head;
            // <= is arbitrary; so equal values will just be stored as left child
            if ( *point_component_p <= *head_point_component_p ) {
                // traverse to left child
                head = kdt_node_left(parent);
                if (!head) {
                    kdt_node_set_left (parent, node);
                    break;
                }
            }
            else {
                // traverse to right child
                head = kdt_node_right(parent);
                if (!head) {
                    kdt_node_set_right (parent, node);
                    break;
                }
            }

            // increment level counter as we are focusing on the next level
            level_counter++;
        }
    }
}

// --------------------------------------------------------------------------
// Self test of this class

void
kdt_kdtree_test (bool verbose)
{
    printf (" * kdt_kdtree: ");
    //  @selftest

    // Constructors
    kdt_kdtree_t *kdtree = kdt_kdtree_new ();

    //  Getter and Setters for dimension == 3
    kdt_kdtree_set_dimension (kdtree, 3);
    assert ( kdt_kdtree_dimension (kdtree) == 3 );

    //  Is tree empty as initialization?
    assert ( kdt_kdtree_empty (kdtree) );

    // Inserting a single element at the root works?
    // ---------------------------------------------
    // Point
    kdt_point_t *point = kdt_point_new ();
    float pointData [3] = {1.0, 1.0, 1.0};
    kdt_point_populate_with_float (point, pointData, 3);
    // Value
    float value = 1.0;
    // Insert
    kdt_kdtree_insert (kdtree, point, value);
    // Should be non empty
    assert ( !kdt_kdtree_empty (kdtree) );
    // Root should contain node with point (1.0, 1.0, 1.0) and value (1.0)
    assert ( kdt_node_point (kdtree->root) == point );
    assert ( kdt_node_value (kdtree->root) == value );

    // Inserting what should be a left child
    // -------------------------------------
    // Point
    kdt_point_t *point_left = kdt_point_new ();
    float pointDataLeft [3] = {-1.0, 1.0, 1.0};
    kdt_point_populate_with_float (point_left, pointDataLeft, 3);
    // Value
    float value_left = 0.0;
    // Insert
    kdt_kdtree_insert (kdtree, point_left, value_left);
    // Left Child of Root should be our point
    assert ( kdt_node_point (kdt_node_left (kdtree->root)) == point_left );
    assert ( kdt_node_value (kdt_node_left (kdtree->root)) == value_left );
    // Right child should be null
    assert ( !kdt_node_right (kdtree->root) );

    // Inserting what should be a left child (level1) right child (level2)
    // -------------------------------------
    // Point
    kdt_point_t *point_leftright = kdt_point_new ();
    float pointDataLeftRight [3] = {-1.0, 2.5, 1.0};
    kdt_point_populate_with_float (point_leftright, pointDataLeftRight, 3);
    // Value
    float value_leftright = 0.0;
    // Insert
    kdt_kdtree_insert (kdtree, point_leftright, value_leftright);
    // Right Child of Left Child of Root should be our point
    assert ( kdt_node_point (kdt_node_right (kdt_node_left (kdtree->root))) == point_leftright );
    assert ( kdt_node_value (kdt_node_right (kdt_node_left (kdtree->root))) == value_leftright );

    //  Destructors
    kdt_kdtree_destroy (&kdtree);

    //  @end
    printf ("OK\n");
}

