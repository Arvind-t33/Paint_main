paint.out: delete.o resize.o add.o check_add.o write.o check_write.o print_statements.o quit.o get_command.o input_val.o setup_canvas.o main.o
	gcc delete.o resize.o add.o check_add.o write.o check_write.o print_statements.o quit.o get_command.o input_val.o setup_canvas.o  main.o -o paint.out

main.o: main.c input_val.h setup_canvas.h get_command.h
	gcc -Wall -Werror -Wextra -c main.c

setup_canvas.o: setup_canvas.c setup_canvas.h
	gcc -Wall -Werror -Wextra -c setup_canvas.c

input_val.o: input_val.h input_val.c
	gcc -Wall -Werror -Wextra -c input_val.c

get_command.o: get_command.c delete.h resize.h add.h write.h check_add.h check_write.h get_command.h quit.h main.h
	gcc -Wall -Werror -Wextra -c get_command.c

quit.o: quit.c quit.h main.h
	gcc -Wall -Werror -Wextra -c quit.c

print_statements.o: print_statements.c print_statements.h
	gcc -Wall -Werror -Wextra -c print_statements.c

check_write.o: check_write.c check_write.h
	gcc -Wall -Werror -Wextra -c check_write.c

write.o: write.c write.h main.h
	gcc -Wall -Werror -Wextra -c write.c

check_add.o: check_add.c check_add.h
	gcc -Wall -Werror -Wextra -c check_add.c

add.o: add.c add.h
	gcc -Wall -Werror -Wextra -c add.c

resize.o: resize.c resize.h main.h
	gcc -Wall -Werror -Wextra -c resize.c

delete.o: delete.c delete.h main.h
	gcc -Wall -Werror -Wextra -c delete.c