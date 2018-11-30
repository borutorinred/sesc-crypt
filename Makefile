PROGRAM=sesc-crypt

run: ${PROGRAM}
	./${PROGRAM}

${PROGRAM}: ${PROGRAM}.c
	gcc -Wall -std=c11 ${PROGRAM}.c -o ${PROGRAM} -lcrypt

build: ${PROGRAM}
