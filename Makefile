# ey.gellis@gmail.com
.PHONY: Main tests valgrind clean

CXX = g++
CXXFLAGS = -Wall -Wextra -g

PROG = Matrix
PROG_SRC = main.cpp
PROG_OBJ = $(PROG_SRC:.cpp=.o)

TEST = TestMat
TEST_SRC = squaremat_test.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

LIB = libmat.a
LIB_SRC = squaremat.cpp
LIB_OBJ = $(LIB_SRC:.cpp=.o)

Main: $(PROG)
	./$(PROG)

$(LIB): $(LIB_OBJ)
	ar -rcs $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(PROG): $(LIB) $(PROG_OBJ)
	$(CXX) $(CXXFLAGS) $(PROG_OBJ) -L. -lmat -o $@

$(TEST): $(LIB) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $(TEST_OBJ) -L. -lmat -o $@

tests: $(TEST)
	./$(TEST)

valgrind: $(PROG)
	valgrind --leak-check=full --error-exitcode=1 ./$(PROG)

clean:
	rm -f $(PROG) $(TEST) $(LIB) $(PROG_OBJ) $(TEST_OBJ) $(LIB_OBJ)
