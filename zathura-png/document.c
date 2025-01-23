#include "plugin.h"

zathura_error_t png_document_open(zathura_document_t* document) {
  /* get path and password */
  const char* filename = zathura_document_get_path(document);

  cairo_surface_t* surface = cairo_image_surface_create_from_png(filename);

  if (cairo_surface_status(surface) != CAIRO_STATUS_SUCCESS)
    return ZATHURA_ERROR_UNKNOWN;

  /* save poppler document for further usage */
  zathura_document_set_data(document, surface);

  zathura_document_set_number_of_pages(document, 1);

  return ZATHURA_ERROR_OK;
}

zathura_error_t png_document_free(zathura_document_t* document, void* data) {
  if (document == NULL) {
    return ZATHURA_ERROR_INVALID_ARGUMENTS;
  }

  cairo_surface_t* surface = data;
  if (cairo_surface_status(surface) == CAIRO_STATUS_SUCCESS) {
    cairo_surface_destroy(surface);
    g_object_unref(surface);
    zathura_document_set_data(document, NULL);
  }

  return ZATHURA_ERROR_OK;
}
