#include <math.h>
#include <boost/preprocessor/repetition/repeat.hpp>

#define TIMES(ignore, n, junk) \
	int times_ ## n(int x) {   \
		return x*n;            \
	}

#define POW(ignore, n, junk) \
	int pow_ ## n(int x) {   \
		return pow(x,n);     \
	}

#define SDIV(ignore, n, junk) \
	int sdiv_ ## n(int x) {    \
		return x/n;            \
	}

#define UDIV(ignore, n, junk)         \
	unsigned udiv_ ## n(unsigned x) { \
		return x/n;                   \
	}

BOOST_PP_REPEAT(17, TIMES, NULL)
BOOST_PP_REPEAT( 4, POW,   NULL)
BOOST_PP_REPEAT(17, SDIV,  NULL)
BOOST_PP_REPEAT(17, UDIV,  NULL)
