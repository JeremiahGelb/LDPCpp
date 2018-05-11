CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		RunMe.o Ldpcer.o Bitnode.o Checknode.o

LIBS =

TARGET =	RunMe.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
