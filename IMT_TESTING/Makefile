CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		IMT_TESTING.o

LIBS =

TARGET =	IMT_TESTING.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
