#include "test_ft_printf.h"

/* fake write(): output goes to g_buf; the g_fail_on-th call returns g_fail_ret */
static char		g_buf[65536];
static size_t	g_len;
static int		g_calls;
static int		g_fail_on;
static ssize_t	g_fail_ret;

ssize_t	write(int fd, const void *p, size_t n)
{
	(void)fd;
	if (++g_calls == g_fail_on)
		return (g_fail_ret);
	if (g_len + n > sizeof(g_buf))
		return (-1);
	memcpy(g_buf + g_len, p, n);
	g_len += n;
	return (n);
}

static void	reset(int fail_on, ssize_t fail_ret)
{
	g_len = 0;
	g_calls = 0;
	g_fail_on = fail_on;
	g_fail_ret = fail_ret;
}

static int	result(const char *name, int ok)
{
	fprintf(stderr, "%s: %s\n", ok ? "OK" : "KO", name);
	return (!ok);
}

/* fail each write in turn (with -1, then 0): must return -1 and stop */
#define TEST_FAIL_EACH(name, ...) \
	do { \
		int	total_; \
		int	k_; \
		int	r_; \
		int	ok_; \
		reset(0, 0); \
		ft_printf(__VA_ARGS__); \
		total_ = g_calls; \
		ok_ = (total_ > 0); \
		r_ = -1; \
		while (r_ <= 0) \
		{ \
			k_ = 1; \
			while (k_ <= total_) \
			{ \
				reset(k_, r_); \
				if (ft_printf(__VA_ARGS__) != -1 || g_calls != k_) \
					ok_ = 0; \
				k_++; \
			} \
			r_++; \
		} \
		fail += result(name, ok_); \
	} while (0)

/* compare output and return value with snprintf in the same process */
#define TEST_SAME(name, ...) \
	do { \
		static char	exp_[65536]; \
		int			er_; \
		int			r_; \
		er_ = snprintf(exp_, sizeof(exp_), __VA_ARGS__); \
		reset(0, 0); \
		r_ = ft_printf(__VA_ARGS__); \
		fail += result(name, r_ == er_ && g_len == (size_t)er_ \
			&& memcmp(g_buf, exp_, er_) == 0); \
	} while (0)

/* undefined behavior: compare with the behavior this ft_printf decided on */
#define TEST_EXPECT(name, exp, exp_ret, ...) \
	do { \
		int	r_; \
		reset(0, 0); \
		r_ = ft_printf(__VA_ARGS__); \
		fail += result(name, r_ == (exp_ret) && g_len == strlen(exp) \
			&& memcmp(g_buf, exp, g_len) == 0); \
	} while (0)

static int	test_write_fail(void)
{
	int	fail;
	int	local;

	fail = 0;
	TEST_FAIL_EACH("fail plain", "abc");
	TEST_FAIL_EACH("fail c", "%c", 'a');
	TEST_FAIL_EACH("fail c NUL", "[%c]", '\0');
	TEST_FAIL_EACH("fail s", "x%sy", "hello");
	TEST_FAIL_EACH("fail s NULL", "%s", (char *)NULL);
	TEST_FAIL_EACH("fail p", "%p", (void *)&local);
	TEST_FAIL_EACH("fail p NULL", "%p", NULL);
	TEST_FAIL_EACH("fail d", "%d", INT_MAX);
	TEST_FAIL_EACH("fail d INT_MIN", "%d", INT_MIN);
	TEST_FAIL_EACH("fail u", "%u", UINT_MAX);
	TEST_FAIL_EACH("fail x", "%x", 0xdeadbeefU);
	TEST_FAIL_EACH("fail %%", "a%%b");
	TEST_FAIL_EACH("fail mixed", "%s=%d%c", "n", 12, '\n');
	TEST_FAIL_EACH("fail unknown", "a%yb");
	return (fail);
}

/* cases that cannot be compared between two processes */
static int	test_same_process(void)
{
	static int	global;
	static char	big[20001];
	int			fail;
	int			local;
	void		*heap;

	fail = 0;
	heap = malloc(1);
	memset(big, 'x', 20000);
	TEST_SAME("p local", "%p", (void *)&local);
	TEST_SAME("p static", "%p", (void *)&global);
	TEST_SAME("p heap", "%p", heap);
	TEST_SAME("s 20000 in []", "[%s]", big);
	free(heap);
	return (fail);
}

static int	test_undefined(void)
{
	int	fail;

	fail = 0;
	TEST_EXPECT("trailing %", "abc", -1, "abc%");
	TEST_EXPECT("unknown spec", "a%yb", 4, "a%yb");
	TEST_EXPECT("NULL fmt", "", -1, (char *)NULL);
	return (fail);
}

int	main(void)
{
	int	fail;

	fail = 0;
	fail += test_write_fail();
	fail += test_same_process();
	fail += test_undefined();
	fprintf(stderr, "%s (%d KO)\n", fail ? "KO" : "ALL OK", fail);
	return (fail != 0);
}
