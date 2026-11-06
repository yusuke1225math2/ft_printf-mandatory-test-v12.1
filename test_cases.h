#define CASE_SP_00 "%s %c %p", NULL, 0, NULL
#define CASE_SP_01 ""
#define CASE_SP_02 "hello"
#define CASE_SP_03 "%d%d%d", 1, 2, 3
#define CASE_SP_04 "%%%d", 5
#define CASE_SP_05 "%s%s", "ab", "cd"
#define CASE_SP_06 "%c|%s|%p|%d|%i|%u|%x|%X|%%", 'A', "str", (void *)0x42, -42, 42, 42u, 255u, 255u
#define CASE_SP_07 "%d %d %d %d %d %d %d %d %d %d %d %d", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
#define CASE_SP_08 "%s %s %s %s %s %s %s %s", "a", "b", "c", "d", "e", "f", "g", "h"
#define CASE_SP_09 "abc", 42
#define CASE_c_00 "%c", 'a'
#define CASE_c_01 "%c", '\0'
#define CASE_c_02 "[%c]", '\0'
#define CASE_c_03 "%c", 200
#define CASE_c_04 "%c", 'a' + 256
#define CASE_c_05 "%c%c%c", 'x', 'y', 'z'
#define CASE_s_00 "%s", ""
#define CASE_s_01 "%s", "hello"
#define CASE_s_02 "%s", "%d"
#define CASE_s_03 "[%s|%s]", "a", "b"
#define CASE_s_04 "%s", "日本語"
#define CASE_s_05 "%s", NULL
#define CASE_p_00 "%p", (void *)1
#define CASE_p_01 "%p", (void *)0x10
#define CASE_p_02 "%p", (void *)UINTPTR_MAX
#define CASE_p_03 "%p", (void *)INTPTR_MIN
#define CASE_p_04 "%p", (void *)0x123456789abcdef0
#define CASE_p_05 "%p", NULL
#define CASE_d_00 "%d", 0
#define CASE_d_01 "%d", 1
#define CASE_d_02 "%d", -1
#define CASE_d_03 "%d", 9
#define CASE_d_04 "%d", 10
#define CASE_d_05 "%d", -9
#define CASE_d_06 "%d", -10
#define CASE_d_07 "%d", 99
#define CASE_d_08 "%d", 100
#define CASE_d_09 "%d", 42
#define CASE_d_10 "%d", -42
#define CASE_d_11 "%d", INT_MAX
#define CASE_d_12 "%d", INT_MIN
#define CASE_d_13 "%d", INT_MIN + 1
#define CASE_d_14 "%d", 1000000000
#define CASE_d_15 "%d", -1000000000
#define CASE_i_00 "%i", 0
#define CASE_i_01 "%i", -1
#define CASE_i_02 "%i", INT_MIN
#define CASE_u_00 "%u", 0u
#define CASE_u_01 "%u", 1u
#define CASE_u_02 "%u", 9u
#define CASE_u_03 "%u", 10u
#define CASE_u_04 "%u", INT_MAX + 1u
#define CASE_u_05 "%u", UINT_MAX
#define CASE_u_06 "%u", UINT_MAX - 1
#define CASE_u_07 "%u", -1
#define CASE_x_00 "%x", 0u
#define CASE_x_01 "%x", 10u
#define CASE_x_02 "%x", 15u
#define CASE_x_03 "%x", 16u
#define CASE_x_04 "%x", 255u
#define CASE_x_05 "%x", 256u
#define CASE_x_06 "%x", 0x7fffffffu
#define CASE_x_07 "%x", 0x80000000u
#define CASE_x_08 "%x", UINT_MAX
#define CASE_x_09 "%x", 0xdeadbeefu
#define CASE_x_10 "%x", -1
#define CASE_x_11 "%x", 0x10000000u
#define CASE_x_12 "%x", 0x12345678u
#define CASE_x_13 "%x", 0x9abcdef0u
#define CASE_X_00 "%X", 10u
#define CASE_X_01 "%X", 15u
#define CASE_X_02 "%X", 255u
#define CASE_X_03 "%X", 0x7fffffffu
#define CASE_X_04 "%X", UINT_MAX
#define CASE_X_05 "%X", 0xdeadbeefu
#define CASE_X_06 "%X", INT_MIN
#define CASE_X_07 "%X", 0x12345678u
#define CASE_X_08 "%X", 0x9abcdef0u
#define CASE_PER_00 "%%"
#define CASE_PER_01 "%%%%"
#define CASE_PER_02 "100%%"
#define CASE_PER_03 "%%d"
#define CASE_PER_04 "%%%c", 'x'
#define CASE_PER_05 "%d%%", 50
