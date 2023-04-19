CC = g++
CFLAGS = -c -Wall -std=c++20
LDFLAGS = -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system
INCLUDES = -I/opt/homebrew/Cellar/sfml/2.5.1_2/include

SOURCES = main.cpp game.cpp deck.cpp pokerOfflineUi.cpp poker.cpp player.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = mygame

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
