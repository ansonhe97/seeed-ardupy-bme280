/**
 * The MIT License (MIT)
 *
 * Author: Anson He (anson.he@seeed.cc)
 *
 * Copyright (C) 2020  Seeed Technology Co.,Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "py/obj.h"
#include "shared-bindings/util.h"

void common_hal_bme280_construct(abstract_module_t *self);
void common_hal_bme280_deinit(abstract_module_t *self);
float common_hal_bme280_get_temperature(abstract_module_t *self);
uint32_t common_hal_bme280_get_pressure(abstract_module_t *self);
uint32_t common_hal_bme280_get_humidity(abstract_module_t *self);
extern const mp_obj_type_t grove_bme280_type;

m_generic_make(bme280) {
    abstract_module_t * self = new_abstruct_module(type);
    mp_arg_check_num(n_args, n_kw, 0, 0, false);
    common_hal_bme280_construct(self);
    return self;
}

void bme280_obj_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest){
    abstract_module_t *self = (abstract_module_t *)self_in;
    uint32_t value;
    float number;
    if (dest[0] == MP_OBJ_NULL) {
        if (attr == MP_QSTR_temperature) {
            number = common_hal_bme280_get_temperature(self);
            dest[0] = mp_obj_new_float(number);
            return;
        }
        else if (attr == MP_QSTR_pressure) {
            value = common_hal_bme280_get_pressure(self);
            dest[0] = mp_obj_new_int(value);
            return;
        }
        else if (attr == MP_QSTR_humidity) {
            value = common_hal_bme280_get_humidity(self);
            dest[0] = mp_obj_new_int(value);
            return;
        }
    }
    generic_method_lookup(self_in, attr, dest);
}

const mp_rom_map_elem_t bme280_locals_dict_table[] = {
    // instance methods
    { MP_ROM_QSTR(MP_QSTR_deinit),    MP_ROM_PTR(&bme280_deinit_obj) },
    { MP_ROM_QSTR(MP_QSTR___enter__), MP_ROM_PTR(&default___enter___obj) },
    { MP_ROM_QSTR(MP_QSTR___exit__),  MP_ROM_PTR(&bme280_obj___exit___obj) },
};

MP_DEFINE_CONST_DICT(bme280_locals_dict, bme280_locals_dict_table);

const mp_obj_type_t grove_bme280_type = {
    {&mp_type_type},
    .name = MP_QSTR_grove_bme280,
    .make_new = bme280_make_new,
    .locals_dict = (mp_obj_t)&bme280_locals_dict,
    .attr = bme280_obj_attr,
};
