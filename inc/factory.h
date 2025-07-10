#ifndef FACTORY_H
#define FACTORY_H

/* ============================================================================================== */

typedef enum
{
    SHAPE_CIRCLE,
    SHAPE_RECTANGLE
} shape_type_t;

/* ============================================================================================== */

typedef struct shape shape_t; /* Basic type for every shape */

/* ============================================================================================== */

/**
 * @brief This method creates a shape of the specified type.
 * @param type The type of shape to create (specified by shape_type_t).
 * @return shape_t* Pointer to the created shape object.
 */
shape_t* shape_create(shape_type_t type);

/* ============================================================================================== */

/**
 * @brief This method draws the specified shape (more methods could be exposed here, and should also
 * be added to the private api).
 * @param shape Pointer to the shape object to be drawn.
 */
void shape_draw(shape_t* shape);

/* ============================================================================================== */

/**
 * @brief This method destroys the specified shape, freeing any allocated resources.
 * @param shape Pointer to the shape object to be destroyed.
 */
void shape_destroy(shape_t* shape);

/* ============================================================================================== */

#endif
