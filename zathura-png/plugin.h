/* SPDX-License-Identifier: Zlib */

#ifndef PNG_H
#define PNG_H

#include <stdbool.h>

#include <cairo.h>

#include <girara/macros.h>

#include <zathura/page.h>
#include <zathura/document.h>
#include <zathura/plugin-api.h>

/**
 * Open a png document
 *
 * @param document Zathura document
 * @return ZATHURA_ERROR_OK when no error occurred, otherwise see
 *    zathura_error_t
 */
GIRARA_HIDDEN zathura_error_t png_document_open(zathura_document_t* document);

/**
 * Closes and frees the internal document structure
 *
 * @param document Zathura document
 * @return ZATHURA_ERROR_OK when no error occurred, otherwise see
 *    zathura_error_t
 */
GIRARA_HIDDEN zathura_error_t png_document_free(zathura_document_t* document, void* poppler_document);

/**
 * Initializes the page with the needed values
 *
 * @param page The page object
 * @return ZATHURA_ERROR_OK when no error occurred, otherwise see
 *    zathura_error_t
 */
GIRARA_HIDDEN zathura_error_t png_page_init(zathura_page_t* page);

/**
 * Frees the data that is used by the plugin in the page
 *
 * @param page Page
 * @return ZATHURA_ERROR_OK when no error occurred, otherwise see
 *    zathura_error_t
 */
GIRARA_HIDDEN zathura_error_t png_page_clear(zathura_page_t* page, void* poppler_page);

/**
 * Renders a page onto a cairo object
 *
 * @param page Page
 * @param cairo Cairo object
 * @param printing Set to true if page should be rendered for printing
 * @return ZATHURA_ERROR_OK when no error occurred, otherwise see
 *    zathura_error_t
 */
GIRARA_HIDDEN zathura_error_t png_page_render_cairo(zathura_page_t* page, void* poppler_page, cairo_t* cairo,
                                                    bool printing);

#endif // PNG_H
