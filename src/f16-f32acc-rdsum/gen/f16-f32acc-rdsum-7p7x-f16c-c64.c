// Auto-generated file. Do not edit!
//   Template: src/f16-f32acc-rdsum/avx.c.in
//   Generator: tools/xngen
//
// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <immintrin.h>

#include <xnnpack/common.h>
#include <xnnpack/reduce.h>
#include <xnnpack/math.h>


void xnn_f16_f32acc_rdsum_ukernel_7p7x__f16c_c64(
    size_t rows,
    size_t channels,
    const void* input,
    size_t input_stride,
    const void* zero,
    void* output,
    const union xnn_f16_f32acc_scale_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(rows != 0);
  assert(channels != 0);
  assert(input != NULL);
  assert(output != NULL);

  const __m256 vscale = _mm256_set1_ps(params->avx.scale);

  size_t input_increment = 7 * input_stride;
  for (; channels >= 64; channels -= 64) {
    const uint16_t* i0 = input;
    const uint16_t* i1 = (const uint16_t*) ((uintptr_t) input + 1 * input_stride);
    const uint16_t* i2 = (const uint16_t*) ((uintptr_t) input + 2 * input_stride);
    const uint16_t* i3 = (const uint16_t*) ((uintptr_t) input + 3 * input_stride);
    const uint16_t* i4 = (const uint16_t*) ((uintptr_t) input + 4 * input_stride);
    const uint16_t* i5 = (const uint16_t*) ((uintptr_t) input + 5 * input_stride);
    const uint16_t* i6 = (const uint16_t*) ((uintptr_t) input + 6 * input_stride);

    __m256 vacc0 = _mm256_setzero_ps();
    __m256 vacc1 = _mm256_setzero_ps();
    __m256 vacc2 = _mm256_setzero_ps();
    __m256 vacc3 = _mm256_setzero_ps();
    __m256 vacc4 = _mm256_setzero_ps();
    __m256 vacc5 = _mm256_setzero_ps();
    __m256 vacc6 = _mm256_setzero_ps();
    __m256 vacc7 = _mm256_setzero_ps();

    for (int r = rows; r > 0; r -= 7) {
      if XNN_UNPREDICTABLE(r < 2) {
        i1 = zero;
      }
      if XNN_UNPREDICTABLE(r <= 2) {
        i2 = zero;
      }
      if XNN_UNPREDICTABLE(r < 4) {
        i3 = zero;
      }
      if XNN_UNPREDICTABLE(r <= 4) {
        i4 = zero;
      }
      if XNN_UNPREDICTABLE(r < 6) {
        i5 = zero;
      }
      if XNN_UNPREDICTABLE(r <= 6) {
        i6 = zero;
      }
      __m256 vin0;
      __m256 vin1;
      __m256 vin2;
      __m256 vin3;
      __m256 vin4;
      __m256 vin5;
      __m256 vin6;
      __m256 vin7;
      vin0 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i0[0])));
      vin1 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i0[8])));
      vin2 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i0[16])));
      vin3 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i0[24])));
      vin4 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i0[32])));
      vin5 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i0[40])));
      vin6 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i0[48])));
      vin7 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i0[56])));
      vacc0 = _mm256_add_ps(vin0, vacc0);
      vacc1 = _mm256_add_ps(vin1, vacc1);
      vacc2 = _mm256_add_ps(vin2, vacc2);
      vacc3 = _mm256_add_ps(vin3, vacc3);
      vacc4 = _mm256_add_ps(vin4, vacc4);
      vacc5 = _mm256_add_ps(vin5, vacc5);
      vacc6 = _mm256_add_ps(vin6, vacc6);
      vacc7 = _mm256_add_ps(vin7, vacc7);
      vin0 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i1[0])));
      vin1 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i1[8])));
      vin2 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i1[16])));
      vin3 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i1[24])));
      vin4 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i1[32])));
      vin5 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i1[40])));
      vin6 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i1[48])));
      vin7 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i1[56])));
      vacc0 = _mm256_add_ps(vin0, vacc0);
      vacc1 = _mm256_add_ps(vin1, vacc1);
      vacc2 = _mm256_add_ps(vin2, vacc2);
      vacc3 = _mm256_add_ps(vin3, vacc3);
      vacc4 = _mm256_add_ps(vin4, vacc4);
      vacc5 = _mm256_add_ps(vin5, vacc5);
      vacc6 = _mm256_add_ps(vin6, vacc6);
      vacc7 = _mm256_add_ps(vin7, vacc7);
      vin0 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i2[0])));
      vin1 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i2[8])));
      vin2 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i2[16])));
      vin3 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i2[24])));
      vin4 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i2[32])));
      vin5 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i2[40])));
      vin6 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i2[48])));
      vin7 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i2[56])));
      vacc0 = _mm256_add_ps(vin0, vacc0);
      vacc1 = _mm256_add_ps(vin1, vacc1);
      vacc2 = _mm256_add_ps(vin2, vacc2);
      vacc3 = _mm256_add_ps(vin3, vacc3);
      vacc4 = _mm256_add_ps(vin4, vacc4);
      vacc5 = _mm256_add_ps(vin5, vacc5);
      vacc6 = _mm256_add_ps(vin6, vacc6);
      vacc7 = _mm256_add_ps(vin7, vacc7);
      vin0 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i3[0])));
      vin1 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i3[8])));
      vin2 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i3[16])));
      vin3 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i3[24])));
      vin4 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i3[32])));
      vin5 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i3[40])));
      vin6 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i3[48])));
      vin7 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i3[56])));
      vacc0 = _mm256_add_ps(vin0, vacc0);
      vacc1 = _mm256_add_ps(vin1, vacc1);
      vacc2 = _mm256_add_ps(vin2, vacc2);
      vacc3 = _mm256_add_ps(vin3, vacc3);
      vacc4 = _mm256_add_ps(vin4, vacc4);
      vacc5 = _mm256_add_ps(vin5, vacc5);
      vacc6 = _mm256_add_ps(vin6, vacc6);
      vacc7 = _mm256_add_ps(vin7, vacc7);
      vin0 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i4[0])));
      vin1 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i4[8])));
      vin2 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i4[16])));
      vin3 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i4[24])));
      vin4 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i4[32])));
      vin5 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i4[40])));
      vin6 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i4[48])));
      vin7 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i4[56])));
      vacc0 = _mm256_add_ps(vin0, vacc0);
      vacc1 = _mm256_add_ps(vin1, vacc1);
      vacc2 = _mm256_add_ps(vin2, vacc2);
      vacc3 = _mm256_add_ps(vin3, vacc3);
      vacc4 = _mm256_add_ps(vin4, vacc4);
      vacc5 = _mm256_add_ps(vin5, vacc5);
      vacc6 = _mm256_add_ps(vin6, vacc6);
      vacc7 = _mm256_add_ps(vin7, vacc7);
      vin0 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i5[0])));
      vin1 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i5[8])));
      vin2 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i5[16])));
      vin3 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i5[24])));
      vin4 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i5[32])));
      vin5 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i5[40])));
      vin6 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i5[48])));
      vin7 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i5[56])));
      vacc0 = _mm256_add_ps(vin0, vacc0);
      vacc1 = _mm256_add_ps(vin1, vacc1);
      vacc2 = _mm256_add_ps(vin2, vacc2);
      vacc3 = _mm256_add_ps(vin3, vacc3);
      vacc4 = _mm256_add_ps(vin4, vacc4);
      vacc5 = _mm256_add_ps(vin5, vacc5);
      vacc6 = _mm256_add_ps(vin6, vacc6);
      vacc7 = _mm256_add_ps(vin7, vacc7);
      vin0 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i6[0])));
      vin1 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i6[8])));
      vin2 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i6[16])));
      vin3 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i6[24])));
      vin4 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i6[32])));
      vin5 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i6[40])));
      vin6 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i6[48])));
      vin7 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) (&i6[56])));
      vacc0 = _mm256_add_ps(vin0, vacc0);
      vacc1 = _mm256_add_ps(vin1, vacc1);
      vacc2 = _mm256_add_ps(vin2, vacc2);
      vacc3 = _mm256_add_ps(vin3, vacc3);
      vacc4 = _mm256_add_ps(vin4, vacc4);
      vacc5 = _mm256_add_ps(vin5, vacc5);
      vacc6 = _mm256_add_ps(vin6, vacc6);
      vacc7 = _mm256_add_ps(vin7, vacc7);
      i0 = (const uint16_t*) ((uintptr_t) i0 + input_increment);
      i1 = (const uint16_t*) ((uintptr_t) i1 + input_increment);
      i2 = (const uint16_t*) ((uintptr_t) i2 + input_increment);
      i3 = (const uint16_t*) ((uintptr_t) i3 + input_increment);
      i4 = (const uint16_t*) ((uintptr_t) i4 + input_increment);
      i5 = (const uint16_t*) ((uintptr_t) i5 + input_increment);
      i6 = (const uint16_t*) ((uintptr_t) i6 + input_increment);
    }
    vacc0 = _mm256_mul_ps(vacc0, vscale);
    vacc1 = _mm256_mul_ps(vacc1, vscale);
    vacc2 = _mm256_mul_ps(vacc2, vscale);
    vacc3 = _mm256_mul_ps(vacc3, vscale);
    vacc4 = _mm256_mul_ps(vacc4, vscale);
    vacc5 = _mm256_mul_ps(vacc5, vscale);
    vacc6 = _mm256_mul_ps(vacc6, vscale);
    vacc7 = _mm256_mul_ps(vacc7, vscale);

    const uint16_t* o = output;
    __m256 vo0 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) o)); o = (const void*) ((uintptr_t) o + 8 * sizeof(uint16_t));
    __m256 vo1 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) o)); o = (const void*) ((uintptr_t) o + 8 * sizeof(uint16_t));
    __m256 vo2 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) o)); o = (const void*) ((uintptr_t) o + 8 * sizeof(uint16_t));
    __m256 vo3 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) o)); o = (const void*) ((uintptr_t) o + 8 * sizeof(uint16_t));
    __m256 vo4 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) o)); o = (const void*) ((uintptr_t) o + 8 * sizeof(uint16_t));
    __m256 vo5 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) o)); o = (const void*) ((uintptr_t) o + 8 * sizeof(uint16_t));
    __m256 vo6 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) o)); o = (const void*) ((uintptr_t) o + 8 * sizeof(uint16_t));
    __m256 vo7 = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) o)); o = (const void*) ((uintptr_t) o + 8 * sizeof(uint16_t));
    vacc0 = _mm256_add_ps(vo0, vacc0);
    vacc1 = _mm256_add_ps(vo1, vacc1);
    vacc2 = _mm256_add_ps(vo2, vacc2);
    vacc3 = _mm256_add_ps(vo3, vacc3);
    vacc4 = _mm256_add_ps(vo4, vacc4);
    vacc5 = _mm256_add_ps(vo5, vacc5);
    vacc6 = _mm256_add_ps(vo6, vacc6);
    vacc7 = _mm256_add_ps(vo7, vacc7);
    _mm_storeu_si128((__m128i*) output, _mm256_cvtps_ph(vacc0, _MM_FROUND_TO_NEAREST_INT)); output = (void*) ((uintptr_t) output + 8 * sizeof(uint16_t));
    _mm_storeu_si128((__m128i*) output, _mm256_cvtps_ph(vacc1, _MM_FROUND_TO_NEAREST_INT)); output = (void*) ((uintptr_t) output + 8 * sizeof(uint16_t));
    _mm_storeu_si128((__m128i*) output, _mm256_cvtps_ph(vacc2, _MM_FROUND_TO_NEAREST_INT)); output = (void*) ((uintptr_t) output + 8 * sizeof(uint16_t));
    _mm_storeu_si128((__m128i*) output, _mm256_cvtps_ph(vacc3, _MM_FROUND_TO_NEAREST_INT)); output = (void*) ((uintptr_t) output + 8 * sizeof(uint16_t));
    _mm_storeu_si128((__m128i*) output, _mm256_cvtps_ph(vacc4, _MM_FROUND_TO_NEAREST_INT)); output = (void*) ((uintptr_t) output + 8 * sizeof(uint16_t));
    _mm_storeu_si128((__m128i*) output, _mm256_cvtps_ph(vacc5, _MM_FROUND_TO_NEAREST_INT)); output = (void*) ((uintptr_t) output + 8 * sizeof(uint16_t));
    _mm_storeu_si128((__m128i*) output, _mm256_cvtps_ph(vacc6, _MM_FROUND_TO_NEAREST_INT)); output = (void*) ((uintptr_t) output + 8 * sizeof(uint16_t));
    _mm_storeu_si128((__m128i*) output, _mm256_cvtps_ph(vacc7, _MM_FROUND_TO_NEAREST_INT)); output = (void*) ((uintptr_t) output + 8 * sizeof(uint16_t));

    input = (const uint16_t*) ((uintptr_t) input + 64 * sizeof(uint16_t));
  }
  if (channels != 0) {
    input_increment = 7 * input_stride;
    const uint16_t* i0 = input;
    const uint16_t* i1 = (const uint16_t*) ((uintptr_t) input + 1 * input_stride);
    const uint16_t* i2 = (const uint16_t*) ((uintptr_t) input + 2 * input_stride);
    const uint16_t* i3 = (const uint16_t*) ((uintptr_t) input + 3 * input_stride);
    const uint16_t* i4 = (const uint16_t*) ((uintptr_t) input + 4 * input_stride);
    const uint16_t* i5 = (const uint16_t*) ((uintptr_t) input + 5 * input_stride);
    const uint16_t* i6 = (const uint16_t*) ((uintptr_t) input + 6 * input_stride);
    __m256 vacc[8];
    vacc[0] = _mm256_setzero_ps();
    vacc[1] = _mm256_setzero_ps();
    vacc[2] = _mm256_setzero_ps();
    vacc[3] = _mm256_setzero_ps();
    vacc[4] = _mm256_setzero_ps();
    vacc[5] = _mm256_setzero_ps();
    vacc[6] = _mm256_setzero_ps();
    vacc[7] = _mm256_setzero_ps();

    const size_t num_full_chunks = channels >> 3;
    const size_t num_chunks = round_up_po2(channels, 8) >> 3;
    const size_t remainder = channels & 0x7;
    for (int r = rows; r > 0; r -= 7) {
      if XNN_UNPREDICTABLE(r < 2) {
        i1 = zero;
      }
      if XNN_UNPREDICTABLE(r <= 2) {
        i2 = zero;
      }
      if XNN_UNPREDICTABLE(r < 4) {
        i3 = zero;
      }
      if XNN_UNPREDICTABLE(r <= 4) {
        i4 = zero;
      }
      if XNN_UNPREDICTABLE(r < 6) {
        i5 = zero;
      }
      if XNN_UNPREDICTABLE(r <= 6) {
        i6 = zero;
      }
      for (int i = 0; i < num_full_chunks; ++i) {
        vacc[i] = _mm256_add_ps(_mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) &i0[i*8])), vacc[i]);
        vacc[i] = _mm256_add_ps(_mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) &i1[i*8])), vacc[i]);
        vacc[i] = _mm256_add_ps(_mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) &i2[i*8])), vacc[i]);
        vacc[i] = _mm256_add_ps(_mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) &i3[i*8])), vacc[i]);
        vacc[i] = _mm256_add_ps(_mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) &i4[i*8])), vacc[i]);
        vacc[i] = _mm256_add_ps(_mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) &i5[i*8])), vacc[i]);
        vacc[i] = _mm256_add_ps(_mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) &i6[i*8])), vacc[i]);
      }

      if (remainder) {
        vacc[num_full_chunks] = _mm256_add_ps(vacc[num_full_chunks],  _mm256_cvtph_ps(_mm_loadu_si128((const  __m128i*) &i0[num_full_chunks*8])));
        vacc[num_full_chunks] = _mm256_add_ps(vacc[num_full_chunks],  _mm256_cvtph_ps(_mm_loadu_si128((const  __m128i*) &i1[num_full_chunks*8])));
        vacc[num_full_chunks] = _mm256_add_ps(vacc[num_full_chunks],  _mm256_cvtph_ps(_mm_loadu_si128((const  __m128i*) &i2[num_full_chunks*8])));
        vacc[num_full_chunks] = _mm256_add_ps(vacc[num_full_chunks],  _mm256_cvtph_ps(_mm_loadu_si128((const  __m128i*) &i3[num_full_chunks*8])));
        vacc[num_full_chunks] = _mm256_add_ps(vacc[num_full_chunks],  _mm256_cvtph_ps(_mm_loadu_si128((const  __m128i*) &i4[num_full_chunks*8])));
        vacc[num_full_chunks] = _mm256_add_ps(vacc[num_full_chunks],  _mm256_cvtph_ps(_mm_loadu_si128((const  __m128i*) &i5[num_full_chunks*8])));
        vacc[num_full_chunks] = _mm256_add_ps(vacc[num_full_chunks],  _mm256_cvtph_ps(_mm_loadu_si128((const  __m128i*) &i6[num_full_chunks*8])));
      }
      i0 = (const uint16_t*) ((uintptr_t) i0 + input_increment);
      i1 = (const uint16_t*) ((uintptr_t) i1 + input_increment);
      i2 = (const uint16_t*) ((uintptr_t) i2 + input_increment);
      i3 = (const uint16_t*) ((uintptr_t) i3 + input_increment);
      i4 = (const uint16_t*) ((uintptr_t) i4 + input_increment);
      i5 = (const uint16_t*) ((uintptr_t) i5 + input_increment);
      i6 = (const uint16_t*) ((uintptr_t) i6 + input_increment);
    }
    for (size_t i = 0; i < num_chunks; ++i) {
      vacc[i] = _mm256_mul_ps(vacc[i], vscale);
    }

    __m256 vo[8];
    const uint16_t* o = output;
    for (int i = 0; i < num_full_chunks; ++i) {
      vo[i] = _mm256_cvtph_ps(_mm_loadu_si128((const __m128i*) o)); o = (const void*) ((uintptr_t) o + 8 * sizeof(uint16_t));
    }
    for (int i = 0; i < num_full_chunks; ++i) {
      vacc[i] = _mm256_add_ps(vo[i], vacc[i]);
    }
    for (int i = 0; i < num_full_chunks; ++i) {
      _mm_storeu_si128((__m128i*) output, _mm256_cvtps_ph(vacc[i], _MM_FROUND_TO_NEAREST_INT)); output = (void*) ((uintptr_t) output + 8 * sizeof(uint16_t));
    }
    if (remainder) {
      __m256 vout = vacc[num_full_chunks];
      __m128 vout_low = _mm256_castps256_ps128(vout);
      if (channels & 4) {
        __m128 vo =  _mm_cvtph_ps(_mm_loadl_epi64((__m128i*) output));
        vo = _mm_add_ps(vout_low, vo);
        _mm_storel_epi64((__m128i*) output, _mm_cvtps_ph(vo, _MM_FROUND_TO_NEAREST_INT));
        vout_low  = _mm256_castps256_ps128(_mm256_permute2f128_ps(vout, vout, 1));
        output = (void*) ((uintptr_t) output + 4 * sizeof(uint16_t));
      }
      if (channels & 2) {
        __m128 vo = _mm_cvtph_ps(_mm_cvtsi32_si128(*(int32_t*) output));
        vo = _mm_add_ps(vout_low, vo);
        _mm_storeu_si32(output, _mm_cvtps_ph(vo, _MM_FROUND_TO_NEAREST_INT));
        vout_low = _mm_movehl_ps(vout_low, vout_low);
        output = (void*) ((uintptr_t) output + 2 * sizeof(uint16_t));
      }
      if (channels & 1) {
        __m128 vo = _mm_cvtph_ps(_mm_set1_epi16(*(uint16_t*) output));
        vo = _mm_add_ps(vout_low, vo);
        _mm_storeu_si16(output, _mm_cvtps_ph(vo, _MM_FROUND_TO_NEAREST_INT));
      }
    }
  }
}
