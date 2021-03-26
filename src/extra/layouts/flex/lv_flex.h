/**
 * @file lv_flex.h
 *
 */

#ifndef LV_FLEX_H
#define LV_FLEX_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../../../core/lv_obj.h"
#if LV_USE_FLEX

/*********************
 *      DEFINES
 *********************/

#define LV_OBJ_FLAG_FLEX_IN_NEW_TRACK   LV_OBJ_FLAG_LAYOUT_1
LV_EXPORT_CONST_INT(LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);

#define _LV_FLEX_COLUMN        (1 << 0)
#define _LV_FLEX_WRAP       (1 << 2)
#define _LV_FLEX_REVERSE    (1 << 3)

/**********************
 *      TYPEDEFS
 **********************/

/*Can't include lv_obj.h because it includes this header file*/
struct _lv_obj_t;

typedef enum {
    LV_FLEX_PLACE_START,
    LV_FLEX_PLACE_END,
    LV_FLEX_PLACE_CENTER,
    LV_FLEX_PLACE_SPACE_EVENLY,
    LV_FLEX_PLACE_SPACE_AROUND,
    LV_FLEX_PLACE_SPACE_BETWEEN,
}lv_flex_place_t;

typedef enum {
    LV_FLEX_FLOW_ROW                 = 0x00,
    LV_FLEX_FLOW_COLUMN              = _LV_FLEX_COLUMN,
    LV_FLEX_FLOW_ROW_WRAP            = LV_FLEX_FLOW_ROW | _LV_FLEX_WRAP,
    LV_FLEX_FLOW_ROW_REVERSE         = LV_FLEX_FLOW_ROW | _LV_FLEX_REVERSE,
    LV_FLEX_FLOW_ROW_WRAP_REVERSE    = LV_FLEX_FLOW_ROW | _LV_FLEX_WRAP | _LV_FLEX_REVERSE,
    LV_FLEX_FLOW_COLUMN_WRAP         = LV_FLEX_FLOW_COLUMN | _LV_FLEX_WRAP,
    LV_FLEX_FLOW_COLUMN_REVERSE      = LV_FLEX_FLOW_COLUMN | _LV_FLEX_REVERSE,
    LV_FLEX_FLOW_COLUMN_WRAP_REVERSE = LV_FLEX_FLOW_COLUMN | _LV_FLEX_WRAP | _LV_FLEX_REVERSE,
}lv_flex_flow_t;

/**********************
 * GLOBAL VARIABLES
 **********************/
extern uint32_t LV_LAYOUT_FLEX;
extern lv_style_prop_t LV_STYLE_FLEX_FLOW;
extern lv_style_prop_t LV_STYLE_FLEX_MAIN_PLACE;
extern lv_style_prop_t LV_STYLE_FLEX_CROSS_PLACE;
extern lv_style_prop_t LV_STYLE_FLEX_TRACK_PLACE;
extern lv_style_prop_t LV_STYLE_FLEX_GROW;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize a felx layout the default values
 * @param flex pointer to a flex layout descriptor
 */
void lv_flex_init(void);

/**
 * Set hot the item should flow
 * @param flex pointer to a flex layout descriptor
 * @param flow an element of `lv_flex_flow_t`.
 */
void lv_obj_set_flex_flow(lv_obj_t * obj, lv_flex_flow_t flow);

/**
 * Set how to place (where to align) the items an tracks
 * @param flex pointer: to a flex layout descriptor
 * @param main_place where to place the items on main axis (in their track). Any value of `lv_flex_place_t`.
 * @param cross_place where to place the item in their track on the cross axis. `LV_FLEX_PLACE_START/END/CENTER`
 * @param track_place where to place the tracks in the cross direction. Any value of `lv_flex_place_t`.
 */
void lv_obj_set_flex_place(lv_obj_t * obj, lv_flex_place_t main_place, lv_flex_place_t cross_place, lv_flex_place_t track_cross_place);

/**
 * Sets the width or height (on main axis) to grow the object in order fill the free space
 * @param obj pointer to an object. The parent must have flex layout else nothing will happen.
 * @param grow a value to set how much free space to take proportionally to other growing items.
 */
void lv_obj_set_flex_grow(lv_obj_t * obj, uint8_t grow);



static inline void lv_style_set_flex_flow(lv_style_t * style, lv_flex_flow_t value)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_style_set_prop(style, LV_STYLE_FLEX_FLOW, v);
}

static inline void lv_style_set_flex_main_place(lv_style_t * style, lv_flex_place_t value)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_style_set_prop(style, LV_STYLE_FLEX_MAIN_PLACE, v);
}

static inline void lv_style_set_flex_cross_place(lv_style_t * style, lv_flex_place_t value)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_style_set_prop(style, LV_STYLE_FLEX_CROSS_PLACE, v);
}

static inline void lv_style_set_flex_track_place(lv_style_t * style, lv_flex_place_t value)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_style_set_prop(style, LV_STYLE_FLEX_TRACK_PLACE, v);
}

static inline void lv_style_set_flex_grow(lv_style_t * style, uint8_t value)
{
    lv_style_value_t v = {
            .num = (int32_t)value
    };
    lv_style_set_prop(style, LV_STYLE_FLEX_GROW, v);
}



static inline void lv_obj_set_style_flex_flow(lv_obj_t * obj, lv_part_t part, lv_state_t state, lv_flex_flow_t value)
{
    lv_style_value_t v = {
        .num = (int32_t) value
    };
    lv_obj_set_local_style_prop(obj, part, state, LV_STYLE_FLEX_FLOW, v);
}

static inline void lv_obj_set_style_flex_main_place(lv_obj_t * obj, lv_part_t part, lv_state_t state, lv_flex_place_t value)
{
    lv_style_value_t v = {
        .num = (int32_t) value
    };
    lv_obj_set_local_style_prop(obj, part, state, LV_STYLE_FLEX_MAIN_PLACE, v);
}

static inline void lv_obj_set_style_flex_cross_place(lv_obj_t * obj, lv_part_t part, lv_state_t state, lv_flex_place_t value)
{
    lv_style_value_t v = {
        .num = (int32_t) value
    };
    lv_obj_set_local_style_prop(obj, part, state, LV_STYLE_FLEX_CROSS_PLACE, v);
}

static inline void lv_obj_set_style_flex_track_place(lv_obj_t * obj, lv_part_t part, lv_state_t state, lv_flex_place_t value)
{
    lv_style_value_t v = {
        .num = (int32_t) value
    };
    lv_obj_set_local_style_prop(obj, part, state, LV_STYLE_FLEX_TRACK_PLACE, v);
}

static inline void lv_obj_set_style_flex_grow(lv_obj_t * obj, lv_part_t part, lv_state_t state, uint8_t value)
{
    lv_style_value_t v = {
        .num = (int32_t) value
    };
    lv_obj_set_local_style_prop(obj, part, state, LV_STYLE_FLEX_GROW, v);
}

static inline lv_flex_flow_t lv_obj_get_style_flex_flow(const lv_obj_t * obj, uint32_t part)
{
    lv_style_value_t v = lv_obj_get_style_prop(obj, part, LV_STYLE_FLEX_FLOW);
    return (lv_flex_flow_t)v.num;
}

static inline lv_flex_place_t lv_obj_get_style_flex_main_place(const lv_obj_t * obj, uint32_t part)
{
    lv_style_value_t v = lv_obj_get_style_prop(obj, part, LV_STYLE_FLEX_MAIN_PLACE);
    return (lv_flex_place_t)v.num;
}

static inline lv_flex_place_t lv_obj_get_style_flex_cross_place(const lv_obj_t * obj, uint32_t part)
{
    lv_style_value_t v = lv_obj_get_style_prop(obj, part, LV_STYLE_FLEX_CROSS_PLACE);
    return (lv_flex_place_t)v.num;
}

static inline lv_flex_place_t lv_obj_get_style_flex_track_place(const lv_obj_t * obj, uint32_t part)
{
    lv_style_value_t v = lv_obj_get_style_prop(obj, part, LV_STYLE_FLEX_TRACK_PLACE);
    return (lv_flex_place_t)v.num;
}

static inline uint8_t lv_obj_get_style_flex_grow(const lv_obj_t * obj, uint32_t part)
{
    lv_style_value_t v = lv_obj_get_style_prop(obj, part, LV_STYLE_FLEX_GROW);
    return (uint8_t)v.num;
}


/**********************
 *      MACROS
 **********************/

#endif  /*LV_USE_FLEX*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_FLEX_H*/
