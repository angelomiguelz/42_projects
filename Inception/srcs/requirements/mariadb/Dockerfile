FROM debian:bullseye

RUN apt-get update && apt-get install -y mariadb-server && rm -rf /var/lib/apt/lists/*

# mysql socket
RUN mkdir -p /var/run/mysqld \
	&& chown -R mysql:mysql /var/run/mysqld \
	&& chmod 777 /var/run/mysqld

RUN sed -i 's/bind-address\s*=\s*127\.0\.0\.1/bind-address = 0.0.0.0/' /etc/mysql/mariadb.conf.d/50-server.cnf

COPY conf/create_db.sh /create_db.sh

RUN chmod +x /create_db.sh

# mariadb default port
EXPOSE 3306

CMD ["/create_db.sh"]
