SRCFILES := $(shell find src/library -type f -iname "*.c")
OBJFILES := $(patsubst %.c,%.o,$(SRCFILES))

PREFIX := /usr
BINDIR := /bin
LIBDIR := /lib

%.o: %.c
	mkdir -p build
	$(CC) -c -o build/$(shell basename $@)  $< -Isrc/include -fPIC

build: $(OBJFILES)
	cp src/systemd-compat.pc build
	sed -i "s|@prefix@|$(PREFIX)|g" build/systemd-compat.pc
	$(CC) build/*.o -o build/libsystemd-compat.so -shared -fPIE
	$(CC) src/main.c -o build/systemd-compat -lsystemd-compat -Lbuild -Isrc/include -fPIC
	$(CC) src/init.c -o build/init -lsystemd-compat -Lbuild -Isrc/include -fPIC

clean:
	rm -vfr build/

install:
	install -Dm755 build/systemd-compat $(DESTDIR)/$(PREFIX)/$(BINDIR)/systemd-compat
	install -Dm755 build/init $(DESTDIR)/$(PREFIX)/$(BINDIR)/systemd-compat-init
	install -Dm755 build/libsystemd-compat.so $(DESTDIR)/$(PREFIX)/$(LIBDIR)/libsystemd-compat.so
	mkdir -p $(DESTDIR)/etc/init.d/
	ln -s ../../$(PREFIX)/$(BINDIR)/systemd-compat $(DESTDIR)/etc/init.d/systemd || true
	mkdir -p $(PREFIX)/include/systemd-compat
	install -Dm755 src/include/* $(DESTDIR)/$(PREFIX)/include/systemd-compat/
	install -Dm755 build/systemd-compat.pc $(DESTDIR)/$(PREFIX)/$(LIBDIR)/pkgconfig/
	install -Dm755 script/systemctl $(DESTDIR)/$(PREFIX)/$(BINDIR)/systemctl
