// Auto-generated file. Do not edit!
//   Template: src/qs8-igemm/MRx4c8-sse.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <smmintrin.h>

#include <xnnpack/igemm.h>
#include <xnnpack/math.h>


void xnn_qs8_igemm_minmax_gemmlowp_ukernel_2x4c8__avx_ld128(
    size_t mr,
    size_t nc,
    size_t kc,
    size_t ks,
    const int8_t** restrict a,
    const void* restrict w,
    int8_t* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    size_t a_offset,
    const int8_t* zero,
    const union xnn_qs8_conv_minmax_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_DISABLE_TSAN XNN_DISABLE_MSAN
{
  assert(mr != 0);
  assert(mr <= 2);
  assert(nc != 0);
  assert(kc != 0);
  assert(ks != 0);
  assert(ks % (2 * sizeof(void*)) == 0);
  assert(a_offset % sizeof(int8_t) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

  kc = round_up_po2(kc, 8);
  int8_t* c0 = c;
  int8_t* c1 = (int8_t*) ((uintptr_t) c0 + cm_stride);
  if XNN_UNPREDICTABLE(mr != 2) {
    c1 = c0;
  }

  do {
    __m128i vacc0x0 = _mm_cvtsi32_si128((int) ((const int32_t*) w)[0]);
    __m128i vacc0x1 = _mm_cvtsi32_si128((int) ((const int32_t*) w)[1]);
    __m128i vacc0x2 = _mm_cvtsi32_si128((int) ((const int32_t*) w)[2]);
    __m128i vacc0x3 = _mm_cvtsi32_si128((int) ((const int32_t*) w)[3]);
    __m128i vacc1x0 = vacc0x0;
    __m128i vacc1x1 = vacc0x1;
    __m128i vacc1x2 = vacc0x2;
    __m128i vacc1x3 = vacc0x3;
    w = (const void*) ((const int32_t*) w + 4);

    size_t p = ks;
    do {
      const int8_t* restrict a0 = a[0];
      if XNN_UNPREDICTABLE(a0 != zero) {
        a0 = (const int8_t*) ((uintptr_t) a0 + a_offset);
      }
      const int8_t* restrict a1 = a[1];
      if XNN_UNPREDICTABLE(a1 != zero) {
        a1 = (const int8_t*) ((uintptr_t) a1 + a_offset);
      }
      a += 2;

      size_t k = 0;
      while (k < kc) {
        const __m128i va0 = _mm_loadl_epi64((const __m128i*) a0);
        const __m128i vxa0 = _mm_cvtepi8_epi16(va0);
        a0 += 8;
        const __m128i va1 = _mm_loadl_epi64((const __m128i*) a1);
        const __m128i vxa1 = _mm_cvtepi8_epi16(va1);
        a1 += 8;

        const __m128i vb01 = _mm_load_si128((const __m128i*) w);
        const __m128i vsb01 = _mm_cmpgt_epi8(_mm_setzero_si128(), vb01);
        const __m128i vxb0 = _mm_unpacklo_epi8(vb01, vsb01);
        const __m128i vxb1 = _mm_unpackhi_epi8(vb01, vsb01);

        vacc0x0 = _mm_add_epi32(vacc0x0, _mm_madd_epi16(vxa0, vxb0));
        vacc0x1 = _mm_add_epi32(vacc0x1, _mm_madd_epi16(vxa0, vxb1));
        vacc1x0 = _mm_add_epi32(vacc1x0, _mm_madd_epi16(vxa1, vxb0));
        vacc1x1 = _mm_add_epi32(vacc1x1, _mm_madd_epi16(vxa1, vxb1));
        const __m128i vb23 = _mm_load_si128((const __m128i*) ((const int8_t*) w + 16));
        const __m128i vsb23 = _mm_cmpgt_epi8(_mm_setzero_si128(), vb23);
        const __m128i vxb2 = _mm_unpacklo_epi8(vb23, vsb23);
        const __m128i vxb3 = _mm_unpackhi_epi8(vb23, vsb23);

        vacc0x2 = _mm_add_epi32(vacc0x2, _mm_madd_epi16(vxa0, vxb2));
        vacc0x3 = _mm_add_epi32(vacc0x3, _mm_madd_epi16(vxa0, vxb3));
        vacc1x2 = _mm_add_epi32(vacc1x2, _mm_madd_epi16(vxa1, vxb2));
        vacc1x3 = _mm_add_epi32(vacc1x3, _mm_madd_epi16(vxa1, vxb3));

        w = (const void*) ((const int8_t*) w + 32);
        k += 8 * sizeof(int8_t);
      }
      p -= 2 * sizeof(void*);
    } while (p != 0);

    const __m128i vacc0x01 = _mm_hadd_epi32(vacc0x0, vacc0x1);
    const __m128i vacc0x23 = _mm_hadd_epi32(vacc0x2, vacc0x3);
    const __m128i vacc1x01 = _mm_hadd_epi32(vacc1x0, vacc1x1);
    const __m128i vacc1x23 = _mm_hadd_epi32(vacc1x2, vacc1x3);

    __m128i vacc0x0123 = _mm_hadd_epi32(vacc0x01, vacc0x23);
    __m128i vacc1x0123 = _mm_hadd_epi32(vacc1x01, vacc1x23);

    const __m128i vmultiplier = _mm_load_si128((const __m128i*) params->gemmlowp_sse4.multiplier);
    const __m128i vrounding = _mm_load_si128((const __m128i*) params->gemmlowp_sse4.rounding);

    const __m128i vacc0x1133 = _mm_shuffle_epi32(vacc0x0123, _MM_SHUFFLE(3, 3, 1, 1));
    const __m128i vacc1x1133 = _mm_shuffle_epi32(vacc1x0123, _MM_SHUFFLE(3, 3, 1, 1));

    const __m128i vprod0x02 = _mm_add_epi64(_mm_mul_epi32(vacc0x0123, vmultiplier), vrounding);
    const __m128i vprod1x02 = _mm_add_epi64(_mm_mul_epi32(vacc1x0123, vmultiplier), vrounding);

    const __m128i vprod0x13 = _mm_add_epi64(_mm_mul_epi32(vacc0x1133, vmultiplier), vrounding);
    const __m128i vprod1x13 = _mm_add_epi64(_mm_mul_epi32(vacc1x1133, vmultiplier), vrounding);

    const __m128i vq31prod0x02 = _mm_srli_epi64(vprod0x02, 31);
    const __m128i vq31prod0x13 = _mm_add_epi64(vprod0x13, vprod0x13);
    const __m128i vq31prod1x02 = _mm_srli_epi64(vprod1x02, 31);
    const __m128i vq31prod1x13 = _mm_add_epi64(vprod1x13, vprod1x13);

    const __m128i vq31prod0x0123 = _mm_blend_epi16(vq31prod0x02, vq31prod0x13, 0xCC);
    const __m128i vq31prod1x0123 = _mm_blend_epi16(vq31prod1x02, vq31prod1x13, 0xCC);

    const __m128i vremainder_mask = _mm_load_si128((const __m128i*) params->gemmlowp_sse4.remainder_mask);
    const __m128i vrem0x0123 =
      _mm_add_epi32(_mm_and_si128(vq31prod0x0123, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prod0x0123));
    const __m128i vrem1x0123 =
      _mm_add_epi32(_mm_and_si128(vq31prod1x0123, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prod1x0123));

    const __m128i vremainder_threshold = _mm_load_si128((const __m128i*) params->gemmlowp_sse4.remainder_threshold);
    const __m128i vshift = _mm_load_si128((const __m128i*) params->gemmlowp_sse4.shift);
    vacc0x0123 =
      _mm_sub_epi32(_mm_sra_epi32(vq31prod0x0123, vshift), _mm_cmpgt_epi32(vrem0x0123, vremainder_threshold));
    vacc1x0123 =
      _mm_sub_epi32(_mm_sra_epi32(vq31prod1x0123, vshift), _mm_cmpgt_epi32(vrem1x0123, vremainder_threshold));

    const __m128i voutput_zero_point = _mm_load_si128((const __m128i*) params->gemmlowp_sse4.output_zero_point);
    __m128i vacc01x0123 = _mm_adds_epi16(_mm_packs_epi32(vacc0x0123, vacc1x0123), voutput_zero_point);


    __m128i vout = _mm_packs_epi16(vacc01x0123, vacc01x0123);

    vout = _mm_max_epi8(vout, _mm_load_si128((const __m128i*) params->gemmlowp_sse4.output_min));
    vout = _mm_min_epi8(vout, _mm_load_si128((const __m128i*) params->gemmlowp_sse4.output_max));

    if (nc >= 4) {
      *((uint32_t*) c1) = (uint32_t) _mm_extract_epi32(vout, 1);
      c1 = (int8_t*) ((uintptr_t) c1 + cn_stride);
      *((uint32_t*) c0) = (uint32_t) _mm_cvtsi128_si32(vout);
      c0 = (int8_t*) ((uintptr_t) c0 + cn_stride);

      a = (const int8_t**restrict) ((uintptr_t) a - ks);

      nc -= 4;
    } else {
      if (nc & 2) {
        *((uint16_t*) c1) = (uint16_t) _mm_extract_epi16(vout, 2);
        c1 += 2;
        *((uint16_t*) c0) = (uint16_t) _mm_extract_epi16(vout, 0);
        c0 += 2;
        vout = _mm_srli_epi32(vout, 16);
      }
      if (nc & 1) {
        *((int8_t*) c1) = (int8_t) _mm_extract_epi8(vout, 4);
        *((int8_t*) c0) = (int8_t) _mm_extract_epi8(vout, 0);
      }

      nc = 0;
    }
  } while (nc != 0);
}
