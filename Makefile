include config.mk

build: $(DEPS)
	@$(CC) src/c/core.c -o $(APP_ID)
	@echo "Compiled..!"
	@echo "Check Git Page:" $(GIT_PAGE)
