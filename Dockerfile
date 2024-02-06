FROM gcc

RUN mkdir /app
WORKDIR /app

COPY ./ /app/
RUN gcc src/main.c -o db

CMD ["/app/db"]