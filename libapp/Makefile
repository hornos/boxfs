# Variables
VER=0.2.0
OBJS=app.o list.o
HEADERS=app.h list.h base.h
CFLAGS=-g -fPIC -I..
CFLAGS_T=-g -fPIC -I../..
SONAME=libapp.so
ANAME=libapp
PREFIX=/usr/local
INCDIR=$(PREFIX)/include/libapp
LIBDIR=$(PREFIX)/lib
TESTS=apptest listtest

# Main target
$(ANAME): $(ANAME).a

$(SONAME): $(SONAME).$(VER)

# Dependencies
app.o: base.h app.h app.c
apptest.o: base.h apptest.c app.h list.h
list.o: base.h list.h list.c

$(ANAME).a:	$(OBJS)
	ar rcs $(ANAME).a $(OBJS)

$(SONAME).$(VER):	$(OBJS)
	gcc $(CFLAGS) -Wl,-soname=$(SONAME) -shared  -o $@ $(OBJS)

.c.o:
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SONAME).* *.o test/*.o $(TESTS) *.a

install: $(SONAME)
	install -s $(SONAME).$(VER) $(LIBDIR)
	install -d $(INCDIR)
	install -m 644 -t $(INCDIR) $(HEADERS)
	
	@echo "*** Note: you should probably run 'ldconfig'"

install_debug: $(SONAME)
	install $(SONAME).$(VER) $(PREFIX)/lib

test: $(SONAME) $(TESTS)

apptest: test/apptest.o
	gcc $(CFLAGS) -o $@ $< -lapp

listtest: test/listtest.o
	gcc $(CFLAGS) -o $@ $< -lapp
