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


#include "Seeed_Arduino_BME280/Seeed_BME280.h"
extern "C"{
#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "shared-bindings/util.h"
}

#define bme280 (*(BME280*)self->module)
void * operator new(size_t, void *);

extern "C" {
    void common_hal_bme280_construct(abstract_module_t *self){
        self->module = new (m_new_obj(BME280)) BME280();
        bme280.init();
    }
    void common_hal_bme280_deinit(abstract_module_t *self){
        bme280.~BME280();
    }
    float common_hal_bme280_get_temperature(abstract_module_t *self){
        return bme280.getTemperature();
    }
    uint32_t common_hal_bme280_get_pressure(abstract_module_t *self){
        return bme280.getPressure();
    }
    uint32_t common_hal_bme280_get_humidity(abstract_module_t *self){
        return bme280.getHumidity();
    }
    float common_hal_bme280_calc_altitude(abstract_module_t *self, float pressure){
        return bme280.calcAltitude(pressure);
    }
}