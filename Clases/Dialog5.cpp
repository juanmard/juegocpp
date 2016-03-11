DIALOG Dialog::dialog[] =
{
   /* (proc)                 (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags) (d1) (d2) (dp)                                     (dp2) (dp3) */
   { Dialog::marco_callback, 16,  24,  612, 300, 254, 50,  0,    0,      0,   0,   NULL,                                    NULL, NULL },
   { d_menu_proc,            0,   0,   640, 15,  7,   15,  0,    0,      0,   0,   Dialog::menu_editor,                     NULL, NULL },
   { d_text_proc,            344, 328, 100, 8,   14,  219, 0,    0,      0,   0,   const_cast<char*>("Lista de actores: "), NULL, NULL },
   { d_text_proc,            8,   380, 32,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Estado:"),           NULL, NULL },
   { Dialog::lista_callback, 344, 340, 144, 92,  50,  219, 0,    0,      0,   0,   NULL,                                    NULL, NULL },
   { d_bitmap_proc,          500, 336, 104, 96,  0,   0,   0,    0,      0,   0,   NULL,                                    NULL, NULL },
   { d_box_proc,             100, 336, 156, 112, 16,  164, 0,    0,      0,   0,   NULL,                                    NULL, NULL },
   { d_text_proc,            108, 380, 82,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("andando"),           NULL, NULL },
   { d_text_proc,            12,  420, 40,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Anterior:"),         NULL, NULL },
   { d_text_proc,            108, 420, 82,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("disparando"),        NULL, NULL },
   { d_text_proc,            12,  432, 40,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Siguiente:"),        NULL, NULL },
   { d_text_proc,            108, 432, 82,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("saltando"),          NULL, NULL },
   { d_text_proc,            8,   368, 40,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Posicion:"),         NULL, NULL },
   { d_text_proc,            108, 368, 82,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("00X, 00Y"),          NULL, NULL },
   { d_text_proc,            8,   344, 32,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Nombre:"),           NULL, NULL },
   { d_text_proc,            108, 344, 82,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Sin nombre"),        NULL, NULL },
   { d_check_proc,           348, 436, 112, 12,  50,  219, 0,    0,      1,   0,   const_cast<char *>("Centrar en pantalla"), NULL, NULL },
   { d_text_proc,            8,   356, 40,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("Dimensiones:"),      NULL, NULL },
   { d_text_proc,            108, 356, 82,  8,   50,  219, 0,    0,      0,   0,   const_cast<char *>("00X, 00Y"),          NULL, NULL },
   { NULL,                   0,   0,   0,   0,   0,   0,   0,    0,      0,   0,   NULL,                                    NULL, NULL }
};