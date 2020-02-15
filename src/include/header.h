#ifndef HEADER
#define HEADER

#define APP_ID "inst-commenty"
#define APP_NAME "Inst Commenty"
#define AUTHOR "Anıl Adem Yener"
#define GIT_PAGE "https://github.com/anilademyener/inst-commenty/"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __linux__
#define OS "linux"
#include <unistd.h>
#elif _WIN32
#define OS "windows"
#include <conio.h>
#else
#define OS "unknown"
#endif

#endif // header
