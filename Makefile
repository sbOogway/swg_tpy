G++         = g++
SRC         = src/main.cpp
HEADERS     = src/utils.cpp src/parsing.cpp
FLAGS       = -std=c++17
TARGET      = build/tpy
TEST        = test/test0.py
TEST_SRC    = test/test.cpp
TEST_TARGET = test/test 

$(TARGET): $(SRC)
	$(G++) $(SRC) $(HEADERS) -o $(TARGET) $(FLAGS)

run: 
	./$(TARGET) $(TEST) $(TEST_TARGET)
	swg_tmr ./$(TEST_TARGET)
