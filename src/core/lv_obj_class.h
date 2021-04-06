/**
 * @file lv_obj_class.h
 *
 */

#ifndef LV_OBJ_CLASS_H
#define LV_OBJ_CLASS_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
#include <stdbool.h>

/*********************
 *      DEFINES
 *********************/


/**********************
 *      TYPEDEFS
 **********************/

struct _lv_obj_t;

typedef enum {
    LV_OBJ_CLASS_EDITABLE_INHERIT,      /**< Check the base class. Must have 0 value to let zero initialized class inherit*/
    LV_OBJ_CLASS_EDITABLE_TRUE,
    LV_OBJ_CLASS_EDITABLE_FALSE,
}lv_obj_class_editable_t;

/**
 * Describe the common methods of every object.
 * Similar to a C++ class.
 */
typedef struct _lv_obj_class_t {
    const struct _lv_obj_class_t * base_class;
    void (*constructor_cb)(struct _lv_obj_t * obj);
    void (*destructor_cb)(struct _lv_obj_t * obj);
    lv_event_cb_t event_cb;         /**< Object type specific event function*/
    lv_coord_t width_def;
    lv_coord_t height_def;
    uint32_t editable : 2;          /**< Value from ::lv_obj_class_editable_t*/
    uint32_t instance_size : 20;
}lv_obj_class_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create an object form a class descriptor
 * @param class_p pointer to a class
 * @param parent pointer to an object where the new object should be created
 * @return pointer to the created object
 */
struct _lv_obj_t * lv_obj_create_from_class(const struct _lv_obj_class_t * class_p, struct _lv_obj_t * parent);

void _lv_obj_destruct(struct _lv_obj_t * obj);

bool lv_obj_is_editable(struct _lv_obj_t * obj);

/**********************
 *      MACROS
 **********************/


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_OBJ_CLASS_H*/
