#include "shared-bindings/board/__init__.h"

STATIC const mp_rom_map_elem_t board_module_globals_table[] = {
    CIRCUITPYTHON_BOARD_DICT_STANDARD_ITEMS

    { MP_ROM_QSTR(MP_QSTR_LED), MP_ROM_PTR(&pin_P1_15) },

    { MP_ROM_QSTR(MP_QSTR_ARGB_0), MP_ROM_PTR(&pin_P1_09) },
    { MP_ROM_QSTR(MP_QSTR_ARGB_1), MP_ROM_PTR(&pin_P0_08) },
    { MP_ROM_QSTR(MP_QSTR_ARGB_2), MP_ROM_PTR(&pin_P0_06) },
    { MP_ROM_QSTR(MP_QSTR_ARGB_3), MP_ROM_PTR(&pin_P0_05) },
    { MP_ROM_QSTR(MP_QSTR_ARGB_4), MP_ROM_PTR(&pin_P0_27) },
    { MP_ROM_QSTR(MP_QSTR_ARGB_5), MP_ROM_PTR(&pin_P0_00) },
    { MP_ROM_QSTR(MP_QSTR_ARGB_6), MP_ROM_PTR(&pin_P0_01) },
    { MP_ROM_QSTR(MP_QSTR_ARGB_7), MP_ROM_PTR(&pin_P0_04) },

    { MP_ROM_QSTR(MP_QSTR_SCL), MP_ROM_PTR(&pin_P1_08) },
    { MP_ROM_QSTR(MP_QSTR_SDA), MP_ROM_PTR(&pin_P0_07) },

    { MP_ROM_QSTR(MP_QSTR_I2C), MP_ROM_PTR(&board_i2c_obj) },
    { MP_ROM_QSTR(MP_QSTR_STEMMA_I2C), MP_ROM_PTR(&board_i2c_obj) },
};

MP_DEFINE_CONST_DICT(board_module_globals, board_module_globals_table);
