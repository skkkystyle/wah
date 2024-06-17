# tag
nothing:
	@echo skkk

# построить программу
all: main.o functions.o
	@gcc -no-pie -m32 main.o functions.o src/afunc.c src/integral.c src/root.c -o integral
	@echo built successfully

# удалить .o файлы
clean:
	@rm functions.o main.o
	@echo object files has been deleted

# получить ответ
run: all
	@echo answer!:
	@./integral

# запустить тесты
test: test.o functions.o
	@gcc -no-pie -m32 test.o functions.o src/test_funcs.c -lm src/integral.c src/root.c -o testskkk
	@echo testing...
	@./testskkk
	@rm test.o functions.o testskkk

# удалить все
delete: clean
	@rm integral
	@echo skkk has been deleted

# открыть окно помощи
help: integral
	@./integral -h

##############not_for_user#############

main.o: main.c
	@gcc -m32 -c main.c -o main.o

functions.o: src/functions.asm
	@nasm -f elf32 src/functions.asm -o functions.o

test.o: test.c
	@gcc -m32 -c test.c -o test.o
