APP_NAME = Inst Commenty
APP_ID = inst-commenty
CC = /usr/bin/gcc
MINGW = /usr/bin/x86_64-w64-mingw32-gcc
PY = /usr/bin/python3
DEPS = $(PY) $(CC) src/
CLEAN_FILES =  *.log $(APP_ID).o $(APP_ID).exe src/py/__pycache__ src/py/app.py

CORE_GLOBAL_C = src/c/core.c src/c/global/g_lib.c
WINDOWS_C = src/c/windows/w_lib.c
LINUX_C = src/c/linux/l_lib.c
ALL_C = $(CORE_GLOBAL_C) $(WINDOWS_C) $(LINUX_C)

GIT_PAGE = "https://github.com/anilademyener/inst-commenty"
