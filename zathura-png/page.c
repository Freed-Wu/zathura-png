/* SPDX-License-Identifier: Zlib */

#include "plugin.h"

zathura_error_t png_page_init(zathura_page_t* page) {
  if (page == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  zathura_document_t* document = zathura_page_get_document(page);
  cairo_surface_t* surface     = zathura_document_get_data(document);

  if (cairo_surface_status(surface) != CAIRO_STATUS_SUCCESS)
    return ZATHURA_ERROR_UNKNOWN;

  /* calculate dimensions */
  double width  = cairo_image_surface_get_width(surface);
  double height = cairo_image_surface_get_height(surface);
  zathura_page_set_width(page, width);
  zathura_page_set_height(page, height);
  zathura_page_set_data(page, surface);

  return ZATHURA_ERROR_OK;
}

zathura_error_t png_page_clear(zathura_page_t* page, void* data) {
  if (page == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  return ZATHURA_ERROR_OK;
}

zathura_error_t png_page_render_cairo(zathura_page_t* page, void* data, cairo_t* cairo, bool printing) {
  if (page == NULL || data == NULL || cairo == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  cairo_surface_t* surface = data;
  cairo_set_source_surface(cairo, surface, 0, 0);
  cairo_paint(cairo);

  return ZATHURA_ERROR_OK;
}
