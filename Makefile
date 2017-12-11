# compiler flags:
#  -Std defines compiler version
CXXFLAGS  = -std=c++11

PROGS=MinHeap MaxHeap Heapsort RBTree

# the build target executable:
all: $(PROGS)

clean:
	$(RM) $(PROGS)

.PHONY: all clean
