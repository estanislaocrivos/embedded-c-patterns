#include "factory.h"

/* ============================================================================================== */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* ============================================================================================== */

/* Shape API object */
typedef struct
{
    /* Common methods to all shapes */
    void (*draw)(shape_t* self);
} shape_api_t;

/* ============================================================================================== */

/* Defines the shape_t type declared on .h. This is the base type for any shape. Wrapper for
 * shape_api_t */
struct shape
{
    const shape_api_t* shape_api;
};

/* ============================================================================================== */

/* Circle shape definition */

typedef struct
{
    shape_t base;
    float   radius;
} shape_circle_t;

void circle_draw(shape_t* self)
{
    shape_circle_t* circle = (shape_circle_t*)self;
    printf("Drawing circle with radius %.2f\n", circle->radius);
}

const shape_api_t circle_shape = {.draw = circle_draw};

/* ============================================================================================== */

/* Rectangle shape definition */

typedef struct
{
    shape_t base;
    float   width, height;
} shape_rectangle_t;

void rectangle_draw(shape_t* self)
{
    shape_rectangle_t* rect = (shape_rectangle_t*)self;
    printf("Drawing rectangle %.2f x %.2f\n", rect->width, rect->height);
}

const shape_api_t rectangle_shape = {.draw = rectangle_draw};

/* ============================================================================================== */

shape_t* shape_create(shape_type_t type)
{
    switch (type)
    {
        case SHAPE_CIRCLE:
        {
            shape_circle_t* c = malloc(sizeof(shape_circle_t));
            c->base.shape_api = &circle_shape;
            c->radius         = 5.0f;
            return (shape_t*)c;
        }
        case SHAPE_RECTANGLE:
        {
            shape_rectangle_t* r = malloc(sizeof(shape_rectangle_t));
            r->base.shape_api    = &rectangle_shape;
            r->width             = 4.0f;
            r->height            = 3.0f;
            return (shape_t*)r;
        }
        default:
            return NULL;
    }
}

/* ============================================================================================== */

void shape_draw(shape_t* shape)
{
    if (shape && shape->shape_api && shape->shape_api->draw)
    {
        shape->shape_api->draw(shape);
    }
}

/* ============================================================================================== */

void shape_destroy(shape_t* shape)
{
    free(shape);
}

/* ============================================================================================== */
