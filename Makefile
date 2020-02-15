include config.mk

build: $(DEPS)
	@$(CC) $(ALL_C) -o $(APP_ID) 2>/dev/null
	@echo "Compiled..!"
	@echo "Check Git Page:" $(GIT_PAGE)

debug: $(DEPS)
	@$(CC) $(ALL_C) -o $(APP_ID)
	@echo "Compiled..! (Debug)"
	@echo "Check Git Page:" $(GIT_PAGE)

clean:
	@rm -rf *.log inst-commenty
	@echo "Cleaned..!"

editapp:
	@emacs src/py/app.py

runapp:
	@python3 src/py/app.py
