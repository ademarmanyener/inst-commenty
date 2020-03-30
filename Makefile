include config.mk

.PHONY: build
.PHONY:	clean 

build: $(DEPS)
	@$(CC) $(CORE_GLOBAL_C) $(LINUX_C) -o $(APP_ID).out 2>/dev/null
	@python3 -m py_compile src/py/app.py.src
	@mv src/py/__pycache__/app.py.cpython-37.pyc src/py/app.py
	@echo "Compiled..!"
	@echo "Check Git Page:" $(GIT_PAGE)

debug: $(DEPS)
	@$(CC) $(CORE_GLOBAL_C) $(LINUX_C) -o $(APP_ID).out
	@echo "Compiled..! (Debug)"
	@echo "Check Git Page:" $(GIT_PAGE)

#
# BETA
#
gtk:
	@$(CC) src/c/core-gtk.c -Wall `pkg-config --libs --cflags gtk+-3.0` -export-dynamic -o $(APP_ID).out

clean:
	@rm -rf $(CLEAN_FILES)
	@echo "Cleaned..!"

windows: $(DEPS)
	@$(MINGW) $(CORE_GLOBAL_C) $(WINDOWS_C) -o $(APP_ID).exe 2>/dev/null
	@echo "Compiled..! (for Windows)"

EDITOR=vim
APP_SRC=src/py/app.py.src
editapp:
	@$(EDITOR) $(APP_SRC) 

runapp:
	@python3 $(APP_SRC)  
