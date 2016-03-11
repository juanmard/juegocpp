DIALOG Dialog::dialog[] =
{
   /* (proc)                 (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags)                               (d1) (d2) (dp)                                   (dp2) (dp3) */
   { Dialog::marco_callback, 16,  24,  612, 300, 254, 50,  0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_menu_proc,            0,   0,   640, 15,  7,   15,  0,    D_SELECTED | D_GOTFOCUS | D_GOTMOUSE, 0,   0,   Dialog::menu_editor,                   NULL, NULL },
   { d_text_proc,            534, 342, 80,  16,  14,  219, 0,    0,                                    0,   0,   const_cast<char*>("  Modo Edicion  "), NULL, NULL },
   { d_text_proc,            8,   360, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Estado:"),         NULL, NULL },
   { d_box_proc,             92,  336, 128, 80,  16,  164, 0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_list_proc,            385, 342, 144, 60,  50,  219, 0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_bitmap_proc,          552, 412, 83,  64,  0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_text_proc,            100, 360, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("andando"),         NULL, NULL },
   { d_text_proc,            8,   372, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Anterior:"),       NULL, NULL },
   { d_text_proc,            100, 372, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("disparando"),      NULL, NULL },
   { d_text_proc,            8,   384, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Siguiente:"),      NULL, NULL },
   { d_text_proc,            100, 384, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("saltando"),        NULL, NULL },
   { d_text_proc,            8,   400, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Posicion:"),       NULL, NULL },
   { d_text_proc,            100, 400, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("00X, 00Y"),        NULL, NULL },
   { d_text_proc,            8,   344, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Nombre:"),         NULL, NULL },
   { d_text_proc,            100, 344, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Sin nombre"),      NULL, NULL },
   { NULL,                   0,   0,   0,   0,   0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL }
};
DIALOG Dialog::dialog[] =
{
   /* (proc)                 (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags)                               (d1) (d2) (dp)                                   (dp2) (dp3) */
   { Dialog::marco_callback, 16,  24,  612, 300, 254, 50,  0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_menu_proc,            0,   0,   640, 15,  7,   15,  0,    D_SELECTED | D_GOTFOCUS | D_GOTMOUSE, 0,   0,   Dialog::menu_editor,                   NULL, NULL },
   { d_box_proc,             0,   428, 640, 150, 255, 0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_text_proc,            534, 342, 80,  16,  14,  219, 0,    0,                                    0,   0,   const_cast<char*>("  Modo Edicion  "), NULL, NULL },
   { d_text_proc,            8,   360, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Estado:"),         NULL, NULL },
   { d_list_proc,            385, 342, 144, 60,  50,  219, 0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_bitmap_proc,          552, 412, 83,  64,  0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_text_proc,            100, 360, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("andando"),         NULL, NULL },
   { d_text_proc,            8,   372, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Anterior:"),       NULL, NULL },
   { d_text_proc,            100, 372, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("disparando"),      NULL, NULL },
   { d_text_proc,            8,   384, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Siguiente:"),      NULL, NULL },
   { d_text_proc,            100, 384, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("saltando"),        NULL, NULL },
   { d_text_proc,            8,   400, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Posicion:"),       NULL, NULL },
   { d_text_proc,            100, 400, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("00X, 00Y"),        NULL, NULL },
   { d_text_proc,            8,   344, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Nombre:"),         NULL, NULL },
   { d_text_proc,            100, 344, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Sin nombre"),      NULL, NULL },
   { d_box_proc,             92,  336, 128, 76,  0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { NULL,                   0,   0,   0,   0,   0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL }
};
DIALOG Dialog::dialog[] =
{
   /* (proc)                 (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags)                               (d1) (d2) (dp)                                   (dp2) (dp3) */
   { Dialog::marco_callback, 16,  24,  612, 300, 254, 50,  0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_menu_proc,            0,   0,   640, 15,  7,   15,  0,    D_SELECTED | D_GOTFOCUS | D_GOTMOUSE, 0,   0,   Dialog::menu_editor,                   NULL, NULL },
   { d_box_proc,             0,   428, 640, 150, 255, 0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_text_proc,            534, 342, 80,  16,  14,  219, 0,    0,                                    0,   0,   const_cast<char*>("  Modo Edicion  "), NULL, NULL },
   { d_text_proc,            8,   360, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Estado:"),         NULL, NULL },
   { d_list_proc,            385, 342, 144, 60,  50,  219, 0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_bitmap_proc,          552, 412, 83,  64,  0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_text_proc,            100, 360, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("andando"),         NULL, NULL },
   { d_text_proc,            8,   372, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Anterior:"),       NULL, NULL },
   { d_text_proc,            100, 372, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("disparando"),      NULL, NULL },
   { d_text_proc,            8,   384, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Siguiente:"),      NULL, NULL },
   { d_text_proc,            100, 384, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("saltando"),        NULL, NULL },
   { d_text_proc,            8,   400, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Posicion:"),       NULL, NULL },
   { d_text_proc,            100, 400, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("00X, 00Y"),        NULL, NULL },
   { d_text_proc,            8,   344, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Nombre:"),         NULL, NULL },
   { d_text_proc,            100, 344, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Sin nombre"),      NULL, NULL },
   { d_box_proc,             92,  336, 68,  76,  0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { NULL,                   0,   0,   0,   0,   0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL }
};
DIALOG Dialog::dialog[] =
{
   /* (proc)                 (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags)                               (d1) (d2) (dp)                                   (dp2) (dp3) */
   { Dialog::marco_callback, 16,  24,  612, 300, 254, 50,  0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_menu_proc,            0,   0,   640, 15,  7,   15,  0,    D_SELECTED | D_GOTFOCUS | D_GOTMOUSE, 0,   0,   Dialog::menu_editor,                   NULL, NULL },
   { d_box_proc,             0,   330, 640, 150, 255, 0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_text_proc,            534, 342, 80,  16,  14,  219, 0,    0,                                    0,   0,   const_cast<char*>("  Modo Edicion  "), NULL, NULL },
   { d_text_proc,            8,   360, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Estado:"),         NULL, NULL },
   { d_list_proc,            385, 342, 144, 60,  50,  219, 0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_bitmap_proc,          552, 412, 83,  64,  0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_text_proc,            100, 360, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("andando"),         NULL, NULL },
   { d_text_proc,            8,   372, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Anterior:"),       NULL, NULL },
   { d_text_proc,            100, 372, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("disparando"),      NULL, NULL },
   { d_text_proc,            8,   384, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Siguiente:"),      NULL, NULL },
   { d_text_proc,            100, 384, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("saltando"),        NULL, NULL },
   { d_text_proc,            8,   400, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Posicion:"),       NULL, NULL },
   { d_text_proc,            100, 400, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("00X, 00Y"),        NULL, NULL },
   { d_text_proc,            8,   344, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Nombre:"),         NULL, NULL },
   { d_text_proc,            100, 344, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Sin nombre"),      NULL, NULL },
   { NULL,                   0,   0,   0,   0,   0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL }
};

DIALOG Dialog::dialog[] =
{
   /* (proc)                 (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags)                               (d1) (d2) (dp)                                   (dp2) (dp3) */
   { Dialog::marco_callback, 16,  24,  612, 300, 254, 50,  0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_menu_proc,            0,   0,   640, 15,  7,   15,  0,    D_SELECTED | D_GOTFOCUS | D_GOTMOUSE, 0,   0,   Dialog::menu_editor,                   NULL, NULL },
   { d_box_proc,             0,   330, 640, 150, 50,  129, 0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_text_proc,            534, 342, 80,  16,  14,  219, 0,    0,                                    0,   0,   const_cast<char*>("  Modo Edicion  "), NULL, NULL },
   { d_text_proc,            8,   360, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Estado:"),         NULL, NULL },
   { d_list_proc,            385, 342, 144, 60,  50,  219, 0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_bitmap_proc,          552, 412, 83,  64,  0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_text_proc,            100, 360, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("andando"),         NULL, NULL },
   { d_text_proc,            8,   372, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Anterior:"),       NULL, NULL },
   { d_text_proc,            100, 372, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("disparando"),      NULL, NULL },
   { d_text_proc,            8,   384, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Siguiente:"),      NULL, NULL },
   { d_text_proc,            100, 384, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("saltando"),        NULL, NULL },
   { d_text_proc,            8,   400, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Posicion:"),       NULL, NULL },
   { d_text_proc,            100, 400, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("00X, 00Y"),        NULL, NULL },
   { d_text_proc,            8,   344, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Nombre:"),         NULL, NULL },
   { d_text_proc,            100, 344, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Sin nombre"),      NULL, NULL },
   { NULL,                   0,   0,   0,   0,   0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL }
};

DIALOG Dialog::dialog[] =
{
   /* (proc)                 (x)  (y)  (w)  (h)  (fg)     (bg)      (key) (flags)                               (d1) (d2) (dp)                                   (dp2) (dp3) */
   { Dialog::marco_callback, 16,  24,  612, 300, 254,     50,       0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_menu_proc,            0,   0,   640, 15,  7,       15,       0,    D_SELECTED | D_GOTFOCUS | D_GOTMOUSE, 0,   0,   Dialog::menu_editor,                   NULL, NULL },
   { d_box_proc,             0,   330, 640, 150, 1310975, 16751104, 0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_text_proc,            534, 342, 80,  16,  14,      219,      0,    0,                                    0,   0,   const_cast<char*>("  Modo Edicion  "), NULL, NULL },
   { d_text_proc,            8,   344, 32,  8,   50,      219,      0,    0,                                    0,   0,   const_cast<char *>("Estado:"),         NULL, NULL },
   { d_list_proc,            385, 342, 144, 60,  50,      219,      0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_bitmap_proc,          552, 412, 83,  64,  0,       0,        0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_text_proc,            100, 344, 82,  8,   50,      219,      0,    0,                                    0,   0,   const_cast<char *>("andando"),         NULL, NULL },
   { d_text_proc,            8,   356, 40,  8,   50,      219,      0,    0,                                    0,   0,   const_cast<char *>("Anterior:"),       NULL, NULL },
   { d_text_proc,            100, 356, 82,  8,   50,      219,      0,    0,                                    0,   0,   const_cast<char *>("disparando"),      NULL, NULL },
   { d_text_proc,            8,   368, 40,  8,   50,      219,      0,    0,                                    0,   0,   const_cast<char *>("Siguiente:"),      NULL, NULL },
   { d_text_proc,            100, 368, 82,  8,   50,      219,      0,    0,                                    0,   0,   const_cast<char *>("saltando"),        NULL, NULL },
   { d_text_proc,            8,   400, 40,  8,   50,      219,      0,    0,                                    0,   0,   const_cast<char *>("Posicion:"),       NULL, NULL },
   { d_text_proc,            100, 400, 82,  8,   50,      219,      0,    0,                                    0,   0,   const_cast<char *>("00X, 00Y"),        NULL, NULL },
   { NULL,                   0,   0,   0,   0,   0,       0,        0,    0,                                    0,   0,   NULL,                                  NULL, NULL }
};
DIALOG Dialog::dialog[] =
{
   /* (proc)                 (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags)                               (d1) (d2) (dp)                                   (dp2) (dp3) */
   { Dialog::marco_callback, 16,  24,  612, 300, 254, 50,  0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_menu_proc,            0,   0,   640, 15,  7,   15,  0,    D_SELECTED | D_GOTFOCUS | D_GOTMOUSE, 0,   0,   Dialog::menu_editor,                   NULL, NULL },
   { d_shadow_box_proc,      0,   330, 640, 150, 0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_text_proc,            534, 342, 80,  16,  14,  219, 0,    0,                                    0,   0,   const_cast<char*>("  Modo Edicion  "), NULL, NULL },
   { d_text_proc,            8,   344, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Estado:"),         NULL, NULL },
   { d_list_proc,            385, 342, 144, 60,  50,  219, 0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_bitmap_proc,          552, 412, 83,  64,  0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_text_proc,            100, 344, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("andando"),         NULL, NULL },
   { d_text_proc,            8,   356, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Anterior:"),       NULL, NULL },
   { d_text_proc,            100, 356, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("disparando"),      NULL, NULL },
   { d_text_proc,            8,   368, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Siguiente:"),      NULL, NULL },
   { d_text_proc,            100, 368, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("saltando"),        NULL, NULL },
   { d_text_proc,            8,   400, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Posicion:"),       NULL, NULL },
   { d_text_proc,            100, 400, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("00X, 00Y"),        NULL, NULL },
   { NULL,                   0,   0,   0,   0,   0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL }
};
DIALOG Dialog::dialog[] =
{
   /* (proc)                 (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags)                               (d1) (d2) (dp)                                   (dp2) (dp3) */
   { Dialog::marco_callback, 16,  24,  612, 300, 254, 50,  0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_menu_proc,            0,   0,   640, 15,  7,   15,  0,    D_SELECTED | D_GOTFOCUS | D_GOTMOUSE, 0,   0,   Dialog::menu_editor,                   NULL, NULL },
   { d_shadow_box_proc,      0,   330, 640, 150, 0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_text_proc,            534, 342, 80,  16,  14,  219, 0,    0,                                    0,   0,   const_cast<char*>("  Modo Edicion  "), NULL, NULL },
   { d_text_proc,            8,   344, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Estado:"),         NULL, NULL },
   { d_list_proc,            385, 342, 144, 60,  50,  219, 0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_bitmap_proc,          552, 412, 83,  64,  0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_text_proc,            100, 344, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("andando"),         NULL, NULL },
   { d_text_proc,            8,   356, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Anterior:"),       NULL, NULL },
   { d_text_proc,            100, 356, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("disparando"),      NULL, NULL },
   { d_text_proc,            8,   368, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Siguiente:"),      NULL, NULL },
   { d_text_proc,            100, 368, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("saltando"),        NULL, NULL },
   { NULL,                   0,   0,   0,   0,   0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL }
};
