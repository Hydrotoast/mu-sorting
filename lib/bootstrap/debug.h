#ifndef DEBUG_H
#define DEBUG_H

#include <cstdio>

#ifdef NDEBUG
#define DEBUG(msg)
#else
#define DEBUG(msg) fprintf(stderr, "[DEBUG] %s:%d: %s\n", __FILE__, __LINE__, msg);
#endif

#define LOG_INFO(msg) fprintf(stderr, "[INFO] %s:%d: %s\n", __FILE__, __LINE__, msg);

#define LOG_WARN(msg) fprintf(stderr, "[WARN] %s:%d: %s\n", __FILE__, __LINE__, msg);

#define LOG_ERRO(msg) fprintf(stderr, "[ERRO] %s:%d: %s\n", __FILE__, __LINE__, msg);

#endif
