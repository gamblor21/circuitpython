// This file is part of the CircuitPython project: https://circuitpython.org
//
// SPDX-FileCopyrightText: Copyright (c) 2024 Mark Komus
//
// SPDX-License-Identifier: MIT
#pragma once

#include "py/obj.h"

#include "shared-module/audiocore/__init__.h"
#include "shared-module/synthio/block.h"

extern const mp_obj_type_t audiodelays_echo_type;

typedef struct {
    mp_obj_base_t base;
    uint32_t max_delay_ms;
    synthio_block_slot_t delay_ms;
    uint32_t current_delay_ms;
    synthio_block_slot_t decay;
    synthio_block_slot_t mix;

    uint8_t bits_per_sample;
    bool samples_signed;
    uint8_t channel_count;
    uint32_t sample_rate;

    int8_t *buffer[2];
    uint8_t last_buf_idx;
    uint32_t buffer_len; // max buffer in bytes

    uint8_t *sample_remaining_buffer;
    uint32_t sample_buffer_length;

    bool loop;
    bool more_data;

    int8_t *echo_buffer;
    uint32_t echo_buffer_len; // bytes
    uint32_t echo_buffer_rate; // words << 8
    uint32_t echo_buffer_pos; // words << 8

    mp_obj_t sample;
} audiodelays_echo_obj_t;

void recalculate_delay(audiodelays_echo_obj_t *self, mp_float_t f_delay_ms);

void audiodelays_echo_reset_buffer(audiodelays_echo_obj_t *self,
    bool single_channel_output,
    uint8_t channel);

audioio_get_buffer_result_t audiodelays_echo_get_buffer(audiodelays_echo_obj_t *self,
    bool single_channel_output,
    uint8_t channel,
    uint8_t **buffer,
    uint32_t *buffer_length);  // length in bytes

void audiodelays_echo_get_buffer_structure(audiodelays_echo_obj_t *self, bool single_channel_output,
    bool *single_buffer, bool *samples_signed,
    uint32_t *max_buffer_length, uint8_t *spacing);
