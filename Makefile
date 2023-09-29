G++         = g++
SRC         = src/main.cpp
TARGET      = tpy
TEST        = test/test.py
TEST_TARGET = _test 

$(TARGET): $(SRC)
	$(G++) $(SRC) -o $(TARGET)

run: 
	./$(TARGET) $(TEST) -o $(TEST_TARGET)
