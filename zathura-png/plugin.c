/* SPDX-License-Identifier: Zlib */

#include "plugin.h"

ZATHURA_PLUGIN_REGISTER_WITH_FUNCTIONS("png", VERSION_MAJOR, VERSION_MINOR, VERSION_REV,
                                       ZATHURA_PLUGIN_FUNCTIONS({
                                           .document_open            = png_document_open,
                                           .document_free            = png_document_free,
                                           .page_init                = png_page_init,
                                           .page_clear               = png_page_clear,
                                           .page_render_cairo        = png_page_render_cairo,
                                       }),
                                       ZATHURA_PLUGIN_MIMETYPES({
                                           "image/png",
                                       }))
