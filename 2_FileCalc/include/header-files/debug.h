#ifdef DEBUG
#    define DEBUG_PRINT(fmt, ...)             \
        fprintf(stderr,                       \
                "[ DEBUG ] %s:%d:%s(): " fmt, \
                __FILE__,                     \
                __LINE__,                     \
                __func__,                     \
                __VA_ARGS__)
#else
#    define DEBUG_PRINT(fmt, ...)
#endif
