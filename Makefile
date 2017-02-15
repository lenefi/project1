CXX=g++
CXXFLAGS=-g
LDFLAGS=
LIBS= -lm

TARGET=foo

#SRCS=$(wildcard *.cpp)
SRCS= main.cpp
OBJS=$(patsubst %.cpp, %.o, $(SRCS))

%.o: %.cpp
	@echo "CXX  $@"
	@$(CXX) -c $(CXXFLAGS) $<

$(TARGET): $(OBJS)
	@echo "LINK $@"
	$(CXX) -o $@ $(LDFLAGS) $(OBJS) $(LIBS)

all: $(TARGET)

clean:
	$(RM) $(TARGET) $(OBJS)
