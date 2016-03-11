DIALOG Actor::dlg[] =
{
   /* (proc)            (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags) (d1) (d2) (dp)                            (dp2) (dp3) */
   { d_box_proc,        8,   336, 616, 240, 67,  243, 0,    0,      0,   0,   NULL,                           NULL, NULL },
   { Actor::callbak,    8,   320, 80,  16,  67,  243, 0,    0,      0,   0,   (void*)"Pesta 01",              NULL, NULL },
   { d_text_proc,       16,  344, 168, 8,   67,  243, 0,    0,      0,   0,   (void*)"Propiedades de actor:", NULL, NULL },
   { d_shadow_box_proc, 24,  360, 320, 192, 67,  243, 0,    0,      0,   0,   NULL,                           NULL, NULL },
   { d_text_proc,       32,  384, 80,  8,   67,  243, 0,    0,      0,   0,   (void*)"Posicion:",             NULL, NULL },
   { d_text_proc,       32,  400, 136, 8,   67,  243, 0,    0,      0,   0,   (void*)"Grafico asociado:",     NULL, NULL },
   { d_text_proc,       32,  368, 56,  8,   67,  243, 0,    0,      0,   0,   (void*)"Nombre:",               NULL, NULL }
};

DIALOG Almacen::dlg[] =
{
   /* (proc)            (x)  (y)  (w)  (h)  (fg) (bg) (key) (flags) (d1) (d2) (dp)                 (dp2) (dp3) */
   { d_box_proc,        584, 176, 208, 248, 0,   0,   0,    0,      0,   0,   NULL,                NULL, NULL },
   { d_list_proc,       592, 200, 192, 56,  0,   0,   0,    0,      0,   0,   dummy_getter,        NULL, NULL },
   { d_text_proc,       592, 184, 128, 8,   0,   0,   0,    0,      0,   0,   (void*)"Almacén : ", NULL, NULL },
   { d_bitmap_proc,     592, 264, 192, 152, 0,   0,   0,    0,      0,   0,   dummy_bmp,           NULL, NULL },
   { NULL,              0,   0,   0,   0,   0,   0,   0,    0,      0,   0,   NULL,                NULL, NULL }
};

DIALOG Dialog::dialog[] =
{
   /* (proc)               (x) (y) (w)  (h)  (fg) (bg) (key) (flags) (d1) (d2) (dp)                 (dp2) (dp3) */
   { Dialog::callback_scr, 16, 24, 612, 300, 254, 50,  0,    0,      0,   0,   NULL,                NULL, NULL },
   { d_menu_proc,          0,  0,  640, 15,  7,   15,  0,    0,      0,   0,   Dialog::menu_editor, NULL, NULL },
   { NULL,                 0,  0,  0,   0,   0,   0,   0,    0,      0,   0,   NULL,                NULL, NULL }
};