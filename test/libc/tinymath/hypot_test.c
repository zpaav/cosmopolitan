/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=2 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2021 Justine Alexandra Roberts Tunney                              │
│                                                                              │
│ Permission to use, copy, modify, and/or distribute this software for         │
│ any purpose with or without fee is hereby granted, provided that the         │
│ above copyright notice and this permission notice appear in all copies.      │
│                                                                              │
│ THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL                │
│ WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED                │
│ WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE             │
│ AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL         │
│ DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR        │
│ PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER               │
│ TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR             │
│ PERFORMANCE OF THIS SOFTWARE.                                                │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "libc/math.h"
#include "libc/testlib/ezbench.h"
#include "libc/testlib/testlib.h"
#include "libc/x/x.h"

TEST(hypot, test) {
  EXPECT_STREQ("0", gc(xdtoa(hypot(0, 0))));
  EXPECT_STREQ("5", gc(xdtoa(hypot(3, 4))));
  EXPECT_STREQ("5", gc(xdtoa(hypot(-3, -4))));
  EXPECT_STREQ("1.414213562373095e+154", gc(xdtoa(hypot(1e154, 1e154))));
  EXPECT_STREQ("NAN", gc(xdtoa(hypot(0, NAN))));
  EXPECT_STREQ("NAN", gc(xdtoa(hypot(NAN, 0))));
  EXPECT_STREQ("NAN", gc(xdtoa(hypot(NAN, NAN))));
  EXPECT_STREQ("INFINITY", gc(xdtoa(hypot(INFINITY, 0))));
  EXPECT_STREQ("INFINITY", gc(xdtoa(hypot(0, INFINITY))));
  EXPECT_STREQ("INFINITY", gc(xdtoa(hypot(INFINITY, NAN))));
  EXPECT_STREQ("INFINITY", gc(xdtoa(hypot(NAN, INFINITY))));
  EXPECT_STREQ("INFINITY", gc(xdtoa(hypot(INFINITY, INFINITY))));
}

TEST(hypotf, test) {
  EXPECT_STREQ("0", gc(xdtoa(hypotf(0, 0))));
  EXPECT_STREQ("5", gc(xdtoa(hypotf(3, 4))));
  EXPECT_STREQ("5", gc(xdtoa(hypotf(-3, -4))));
  EXPECT_STREQ("1.414214e+38", gc(xdtoaf(hypotf(1e38, 1e38))));
  EXPECT_STREQ("NAN", gc(xdtoa(hypotf(0, NAN))));
  EXPECT_STREQ("NAN", gc(xdtoa(hypotf(NAN, 0))));
  EXPECT_STREQ("NAN", gc(xdtoa(hypotf(NAN, NAN))));
  EXPECT_STREQ("INFINITY", gc(xdtoa(hypotf(INFINITY, 0))));
  EXPECT_STREQ("INFINITY", gc(xdtoa(hypotf(0, INFINITY))));
  EXPECT_STREQ("INFINITY", gc(xdtoa(hypotf(INFINITY, NAN))));
  EXPECT_STREQ("INFINITY", gc(xdtoa(hypotf(NAN, INFINITY))));
  EXPECT_STREQ("INFINITY", gc(xdtoa(hypotf(INFINITY, INFINITY))));
}

TEST(hypotl, test) {
  EXPECT_STREQ("0", gc(xdtoa(hypotl(0, 0))));
  EXPECT_STREQ("5", gc(xdtoa(hypotl(3, 4))));
  EXPECT_STREQ("5", gc(xdtoa(hypotl(-3, -4))));
  EXPECT_STREQ("1.414213562373095e+4931", gc(xdtoa(hypotl(1e4931L, 1e4931L))));
  EXPECT_STREQ("NAN", gc(xdtoa(hypotl(0, NAN))));
  EXPECT_STREQ("NAN", gc(xdtoa(hypotl(NAN, 0))));
  EXPECT_STREQ("NAN", gc(xdtoa(hypotl(NAN, NAN))));
  EXPECT_STREQ("INFINITY", gc(xdtoa(hypotl(INFINITY, 0))));
  EXPECT_STREQ("INFINITY", gc(xdtoa(hypotl(0, INFINITY))));
  EXPECT_STREQ("INFINITY", gc(xdtoa(hypotl(INFINITY, NAN))));
  EXPECT_STREQ("INFINITY", gc(xdtoa(hypotl(NAN, INFINITY))));
  EXPECT_STREQ("INFINITY", gc(xdtoa(hypotl(INFINITY, INFINITY))));
}

BENCH(hypot, bench) {
  volatile double a = 2;
  volatile double b = 3;
  EZBENCH2("hypotf", donothing, EXPROPRIATE(hypotf(a, b)));
  EZBENCH2("hypot", donothing, EXPROPRIATE(hypot(a, b)));
  EZBENCH2("hypotl", donothing, EXPROPRIATE(hypotl(a, b)));
}
