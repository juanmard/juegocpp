DIALOG Dialog::dialog[] =
{
   /* (proc)                 (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags)                               (d1) (d2) (dp)                                     (dp2) (dp3) */
   { Dialog::marco_callback, 16,  24,  612, 300, 254, 50,  0,    0,                                    0,   0,   NULL,                                    NULL, NULL },
   { d_menu_proc,            0,   0,   640, 15,  7,   15,  0,    D_SELECTED | D_GOTFOCUS | D_GOTMOUSE, 0,   0,   Dialog::menu_editor,                     NULL, NULL },
   { d_text_proc,            344, 328, 100, 8,   14,  219, 0,    0,                                    0,   0,   const_cast<char*>("Lista de actores: "), NULL, NULL },
   { d_text_proc,            8,   360, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Estado:"),           NULL, NULL },
   { d_list_proc,            344, 340, 144, 92,  50,  219, 0,    0,                                    0,   0,   NULL,                                    NULL, NULL },
   { d_bitmap_proc,          500, 336, 104, 96,  0,   0,   0,    0,                                    0,   0,   NULL,                                    NULL, NULL },
   { d_box_proc,             92,  336, 128, 80,  16,  164, 0,    0,                                    0,   0,   NULL,                                    NULL, NULL },
   { d_text_proc,            100, 360, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("andando"),           NULL, NULL },
   { d_text_proc,            8,   372, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Anterior:"),         NULL, NULL },
   { d_text_proc,            100, 372, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("disparando"),        NULL, NULL },
   { d_text_proc,            8,   384, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Siguiente:"),        NULL, NULL },
   { d_text_proc,            100, 384, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("saltando"),          NULL, NULL },
   { d_text_proc,            8,   400, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Posicion:"),         NULL, NULL },
   { d_text_proc,            100, 400, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("00X, 00Y"),          NULL, NULL },
   { d_text_proc,            8,   344, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Nombre:"),           NULL, NULL },
   { d_text_proc,            100, 344, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Sin nombre"),        NULL, NULL },
   { NULL,                   0,   0,   0,   0,   0,   0,   0,    0,                                    0,   0,   NULL,                                    NULL, NULL }
};
DIALOG Dialog::dialog[] =
{
   /* (proc)                 (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags)                               (d1) (d2) (dp)                                   (dp2) (dp3) */
   { Dialog::marco_callback, 16,  24,  612, 300, 254, 50,  0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_menu_proc,            0,   0,   640, 15,  7,   15,  0,    D_SELECTED | D_GOTFOCUS | D_GOTMOUSE, 0,   0,   Dialog::menu_editor,                   NULL, NULL },
   { d_text_proc,            344, 328, 80,  16,  14,  219, 0,    0,                                    0,   0,   const_cast<char*>("  Modo Edicion  "), NULL, NULL },
   { d_text_proc,            8,   360, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Estado:"),         NULL, NULL },
   { d_list_proc,            344, 344, 144, 60,  50,  219, 0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_bitmap_proc,          500, 336, 128, 132, 0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_box_proc,             92,  336, 128, 80,  16,  164, 0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
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