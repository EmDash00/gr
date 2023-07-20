#ifndef GRM_PLOT_INT_H_INCLUDED
#define GRM_PLOT_INT_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

/* ######################### includes ############################################################################### */

#include "args_int.h"
#include "datatype/uint_map_int.h"
#include "grm/error.h"
#include "event_int.h"

#ifdef __cplusplus
}

#include <grm/dom_render/graphics_tree/Element.hxx>

#include <grm/plot.h>
extern "C" {
#else
#include <grm/plot.h>
#endif


/* ######################### internal interface ##################################################################### */

/* ========================= global variables ======================================================================= */

/* ------------------------- plot ----------------------------------------------------------------------------------- */

/* ~~~~~~~~~~~~~~~~~~~~~~~~~ args ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

extern grm_args_t *active_plot_args;


/* ~~~~~~~~~~~~~~~~~~~~~~~~~ event handling ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

extern event_queue_t *event_queue;


/* ~~~~~~~~~~~~~~~~~~~~~~~~~ plot clear ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

extern const char *plot_clear_exclude_keys[];


/* ========================= macros ================================================================================= */

/* ------------------------- plot ----------------------------------------------------------------------------------- */

/* ~~~~~~~~~~~~~~~~~~~~~~~~~ plot arguments ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#define ROOT_DEFAULT_APPEND_PLOTS 0
#define PLOT_DEFAULT_WIDTH 600.0
#define PLOT_DEFAULT_HEIGHT 450.0
#define PLOT_DEFAULT_KIND "line"
#define PLOT_DEFAULT_XGRID 1
#define PLOT_DEFAULT_YGRID 1
#define PLOT_DEFAULT_ZGRID 1

/* ========================= datatypes ============================================================================== */

/* ------------------------- plot ----------------------------------------------------------------------------------- */

/* ~~~~~~~~~~~~~~~~~~~~~~~~~ kind to func ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef err_t (*plot_func_t)(grm_args_t *args);


/* ~~~~~~~~~~~~~~~~~~~~~~~~~ options ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* ========================= functions ============================================================================== */

/* ------------------------- plot ----------------------------------------------------------------------------------- */

/* ~~~~~~~~~~~~~~~~~~~~~~~~~ general ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

err_t plot_init_static_variables(void);


/* ~~~~~~~~~~~~~~~~~~~~~~~~~ plot arguments ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

err_t plot_merge_args(grm_args_t *args, const grm_args_t *merge_args, const char **hierarchy_name_ptr,
                      uint_map_t *hierarchy_to_id, int hold_always);
err_t plot_init_arg_structure(arg_t *arg, const char **hierarchy_name_ptr, unsigned int next_hierarchy_level_max_id);
err_t plot_init_args_structure(grm_args_t *args, const char **hierarchy_name_ptr,
                               unsigned int next_hierarchy_level_max_id);
int plot_check_for_request(const grm_args_t *args, err_t *error);
void plot_set_flag_defaults(void);
void plot_set_attribute_defaults(grm_args_t *subplot_args);
void plot_pre_plot(grm_args_t *plot_args);
void plot_set_text_encoding(void);
void plot_process_wswindow_wsviewport(grm_args_t *plot_args);
err_t plot_pre_subplot(grm_args_t *subplot_args);
int plot_process_subplot_args(grm_args_t *subplot_args);
void plot_process_colormap(grm_args_t *subplot_args);
void plot_process_font(grm_args_t *subplot_args);
err_t plot_process_grid_arguments(const grm_args_t *args);
void plot_process_resample_method(grm_args_t *subplot_args);
void plot_process_window(grm_args_t *subplot_args);
err_t plot_store_coordinate_ranges(grm_args_t *subplot_args);
void plot_post_plot(grm_args_t *plot_args);
void plot_restore_text_encoding(void);
void plot_post_subplot(grm_args_t *subplot_args);
err_t plot_get_args_in_hierarchy(grm_args_t *args, const char **hierarchy_name_start_ptr, const char *key,
                                 uint_map_t *hierarchy_to_id, const grm_args_t **found_args,
                                 const char ***found_hierarchy_ptr);


/* ~~~~~~~~~~~~~~~~~~~~~~~~~ plotting ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

err_t plot_line(grm_args_t *subplot_args);
err_t plot_stairs(grm_args_t *subplot_args);
err_t plot_scatter(grm_args_t *subplot_args);
err_t plot_quiver(grm_args_t *subplot_args);
err_t plot_stem(grm_args_t *subplot_args);
err_t plot_hist(grm_args_t *subplot_args);
err_t plot_barplot(grm_args_t *subplot_args);
err_t plot_contour(grm_args_t *subplot_args);
err_t plot_contourf(grm_args_t *subplot_args);
err_t plot_hexbin(grm_args_t *subplot_args);
err_t plot_heatmap(grm_args_t *subplot_args);
err_t plot_polar_heatmap(grm_args_t *subplot_args);
err_t plot_marginalheatmap(grm_args_t *subplot_args);
err_t plot_wireframe(grm_args_t *subplot_args);
err_t plot_surface(grm_args_t *subplot_args);
err_t plot_plot3(grm_args_t *subplot_args);
err_t plot_scatter3(grm_args_t *subplot_args);
err_t plot_imshow(grm_args_t *subplot_args);
err_t plot_isosurface(grm_args_t *subplot_args);
err_t plot_volume(grm_args_t *subplot_args);
err_t plot_polar(grm_args_t *subplot_args);
err_t plot_polar_histogram(grm_args_t *subplot_args);
err_t plot_pie(grm_args_t *subplot_args);
err_t plot_trisurf(grm_args_t *subplot_args);
err_t plot_tricont(grm_args_t *subplot_args);
err_t plot_shade(grm_args_t *subplot_args);
err_t plot_raw(grm_args_t *subplot_args);


/* ~~~~~~~~~~~~~~~~~~~~~~~~~ auxiliary drawing functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

err_t plot_draw_axes(grm_args_t *args, unsigned int pass);
err_t plot_draw_polar_axes(grm_args_t *args);
err_t plot_draw_legend(grm_args_t *args);
err_t plot_draw_pie_legend(grm_args_t *args);
err_t plot_draw_colorbar(grm_args_t *args, double off, unsigned int colors);
err_t plot_draw_errorbars(grm_args_t *series_args, unsigned int x_length);


/* ~~~~~~~~~~~~~~~~~~~~~~~~~ util ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

const char *next_fmt_key(const char *fmt) UNUSED;
const char *get_compatible_format(const char *key, const char *given_format);
int get_id_from_args(const grm_args_t *args, int *plot_id, int *subplot_id, int *series_id);
grm_args_t *get_subplot_from_ndc_point(double x, double y);
grm_args_t *get_subplot_from_ndc_points(unsigned int n, const double *x, const double *y);
err_t classes_polar_histogram(grm_args_t *subplot_args);

int get_free_id_from_figure_elements();

#ifdef __cplusplus
}

#endif

/* ------------------------- xml ------------------------------------------------------------------------------------ */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NO_LIBXML2
err_t validate_graphics_tree_xml(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* ifndef GRM_PLOT_INT_H_INCLUDED */
