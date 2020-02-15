include config.mk

build: $(DEPS)
	@$(CC) $(CORE_GLOBAL_C) $(LINUX_C) -o $(APP_ID) 2>/dev/null
	@echo "Compiled..!"
	@echo "Check Git Page:" $(GIT_PAGE)

debug: $(DEPS)
	@$(CC) $(CORE_GLOBAL_C) $(LINUX_C) -o $(APP_ID)
	@echo "Compiled..! (Debug)"
	@echo "Check Git Page:" $(GIT_PAGE)

clean:
	@rm -rf *.log $(APP_ID) $(APP_ID).exe
	@echo "Cleaned..!"

windows: $(DEPS)
	@$(MINGW) $(CORE_GLOBAL_C) $(WINDOWS_C) -o $(APP_ID).exe 2>/dev/null
	@echo "Compiled..! (for Windows)"

editapp:
	@emacs src/py/app.py

runapp:
	@python3 src/py/app.py
