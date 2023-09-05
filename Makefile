SRCFILES := $(shell find src/ -type f -iname "*.c")
OBJFILES := $(patsubst %.c,%.o,$(SRCFILES))

%.o: %.c
	mkdir -p build
	$(CC) -c -o build/$(shell basename $@)  $< -Isrc

build: $(OBJFILES)
	$(CC) build/*.o -o build/service

clean:
	rm -vfr build/

install:
	install -Dm755 service $(DESTDIR)/etc/init.d/systemd
