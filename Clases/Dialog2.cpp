DIALOG Dialog::dialog[] =
{
   /* (proc)                 (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags)                               (d1) (d2) (dp)                                   (dp2) (dp3) */
   { Dialog::marco_callback, 0,   20,  640, 200, 254, 50,  0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_menu_proc,            0,   0,   640, 15,  7,   15,  0,    D_SELECTED | D_GOTFOCUS | D_GOTMOUSE, 0,   0,   Dialog::menu_editor,                   NULL, NULL },
   { d_shadow_box_proc,      0,   330, 640, 150, 0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_text_proc,            534, 342, 80,  16,  14,  219, 0,    0,                                    0,   0,   const_cast<char*>("  Modo Edicion  "), NULL, NULL },
   { d_text_proc,            8,   344, 32,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Estado:"),         NULL, NULL },
   { d_list_proc,            385, 342, 144, 60,  50,  219, 0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_bitmap_proc,          552, 412, 83,  64,  0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL },
   { d_text_proc,            80,  344, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("andando"),         NULL, NULL },
   { d_text_proc,            8,   356, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Anterior:"),       NULL, NULL },
   { d_text_proc,            80,  356, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("disparando"),      NULL, NULL },
   { d_text_proc,            8,   368, 40,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("Siguiente:"),      NULL, NULL },
   { d_text_proc,            80,  368, 82,  8,   50,  219, 0,    0,                                    0,   0,   const_cast<char *>("saltando"),        NULL, NULL },
   { NULL,                   0,   0,   0,   0,   0,   0,   0,    0,                                    0,   0,   NULL,                                  NULL, NULL }
};