FROM gcc

RUN mkdir /app
WORKDIR /app

COPY ./ /app/
RUN gcc -I /app/ -o db ./src/main.c ./src/inputBuffer.c ./src/row.c ./src/pager.c ./src/table.c

CMD ["/app/db", "users"]