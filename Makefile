CC = g++ -g -std=c++11
MAKE = make -w

MAIN = main
CURRENT_DIR_SOURCEs = ${wildcard *.cpp}
CURRENT_DIR_OBJs = ${patsubst %.cpp, %.o, $(CURRENT_DIR_SOURCEs)}

.PHONY : all
all : $(MAIN)
	@echo "make all succeed."

$(MAIN): $(CURRENT_DIR_OBJs)
	$(CC) -o $@ $^

%.o : %.cpp
	$(CC) -c $^ -o $@

.PHONY : clean
clean :
	@rm main
	@rm *.o























