FROM gcc:15

WORKDIR /app

COPY . .

CMD ["make"]
