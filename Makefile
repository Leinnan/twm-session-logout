#!bin/bash

ifndef PREFIX
  PREFIX=/usr
endif
CXX := g++
CXXFLAGS := -c -std=c++11 -O2 -march=native -Wall -Wextra -pedantic
LD := g++
LDFLAGS := -std=gnu++11 `pkg-config gtkmm-3.0 --libs`

NAME := twm-session-logout
SRCDIR := src
OBJDIR := obj

OBJ := $(OBJDIR)/MainWindow.o $(OBJDIR)/main.o
EXE := $(NAME)

.PHONY: all clean

all: $(EXE)

clean:
	rm -rf $(OBJDIR)
	rm -f $(EXE) main.o

install:
	install -m 755 -D $(EXE) $(DESTDIR)$(PREFIX)/bin/$(EXE)


$(EXE): $(OBJDIR) $(OBJ)
	$(LD) $(OBJ) $(LDFLAGS) -o $@

$(OBJDIR):
	mkdir $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/%.h
	$(CXX) $(CXXFLAGS) $< -o $@ `pkg-config gtkmm-3.0 --cflags --libs`

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ `pkg-config gtkmm-3.0 --cflags --libs`

