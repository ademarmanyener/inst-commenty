include config.mk

build: $(DEPS)
	@$(CC) $(CORE_GLOBAL_C) $(LINUX_C) -o $(APP_ID).o 2>/dev/null
	@python3 -m py_compile src/py/app.py.src
	@mv src/py/__pycache__/app.py.cpython-37.pyc src/py/app.py
	@echo "Compiled..!"
	@echo "Check Git Page:" $(GIT_PAGE)

debug: $(DEPS)
	@$(CC) $(CORE_GLOBAL_C) $(LINUX_C) -o $(APP_ID).o
	@echo "Compiled..! (Debug)"
	@echo "Check Git Page:" $(GIT_PAGE)

clean:
	@rm -rf $(CLEAN_FILES)
	@echo "Cleaned..!"

windows: $(DEPS)
	@$(MINGW) $(CORE_GLOBAL_C) $(WINDOWS_C) -o $(APP_ID).exe 2>/dev/null
	@echo "Compiled..! (for Windows)"

editapp:
	@emacs src/py/app.py

runapp:
	@python3 src/py/app.py
